import * as yargs from 'yargs';
import * as rimraf from 'rimraf';
import path from 'path';
import { readFileSync, writeFileSync } from 'fs';
import kebabCase from 'lodash/kebabCase';
import * as reactDocgen from 'react-docgen';
import getStylesCreator from '../styles/getStylesCreator';
import createTheme from '../core/styles/createTheme';
import * as colors from '../core/colors';
import getInheritance from './inheritance';
import parseTest from './parseTest';

import findComponents from './find-components';
import ensureExists from './ensure-folder-exists';

const args = yargs
  .option('src', {
    describe: 'mui source',
    choices: ['material', 'lab'],
  })
  .demandOption(['src'], 'Please provide src argument')
  .help().argv;
const muiSrc = args.src;

const MuiPath = path.resolve(__dirname, '../', muiSrc);

const components = findComponents(`./${muiSrc}`);
const theme = createTheme();
const rootDirectory = MuiPath;
const outputDirectory = path.join(
  __dirname,
  '../../../',
  'output',
  'json',
  muiSrc,
);

rimraf.sync(path.join(outputDirectory, '*.json'));

components.forEach(async (componentPath) => {
  const src = readFileSync(componentPath, 'utf8');

  if (
    src.match(/@ignore - internal component\./) ||
    src.match(/@ignore - do not document\./)
  ) {
    return;
  }

  const component = require(componentPath);
  const styles = {
    classes: [],
    name: null,
  };

  if (component.styles && component.default.options) {
    // Collect the customization points of the `classes` property.
    styles.classes = Object.keys(
      getStylesCreator(component.styles).create(theme),
    ).filter((className) => !className.match(/^(@media|@keyframes)/));
    styles.name = component.default.options.name;
  }

  let reactAPI;
  try {
    reactAPI = reactDocgen.parse(src);
  } catch (err) {
    console.log('Error parsing src for', componentPath);
    throw err;
  }

  reactAPI.name = path.parse(componentPath).name;
  reactAPI.importName = path.parse(componentPath).name;
  reactAPI.styles = styles;
  reactAPI.filename = componentPath.replace(rootDirectory, '');
  reactAPI.importPath = `@material-ui/${muiSrc}`;

  // Inheritance
  const testInfo = await parseTest(reactAPI.filename, muiSrc);
  const inheritance = getInheritance(testInfo, src);
  reactAPI.inheritsFrom = inheritance ? inheritance.component : '';

  if (typeof reactAPI.props.classes !== 'undefined') {
    reactAPI.props.classes.flowType = {
      name: 'classes',
      elements: reactAPI.styles.classes,
    };
  }

  ensureExists(outputDirectory, 0o744, (err) => {
    if (err) {
      console.log('Error creating directory', outputDirectory);
      console.log(err);
      return;
    }

    writeFileSync(
      path.resolve(outputDirectory, `${kebabCase(reactAPI.name)}.json`),
      JSON.stringify(reactAPI),
    );
    console.log('Extracted JSON for', componentPath);
  });
});

ensureExists(outputDirectory, 0o744, (err) => {
  if (err) {
    console.log('Error creating directory', outputDirectory);
    console.log(err);
    return;
  }
  if (muiSrc === 'core') {
    writeFileSync(
      path.resolve(outputDirectory, `colors.json`),
      JSON.stringify(colors),
    );
    console.log('Extracted JSON for Colors');
  }
});
