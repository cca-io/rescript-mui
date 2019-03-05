import * as rimraf from 'rimraf';

import path from 'path';
import { mkdir, readFileSync, writeFileSync } from 'fs';
import kebabCase from 'lodash/kebabCase';
import * as reactDocgen from 'react-docgen';
import getStylesCreator from './../core/styles/getStylesCreator';
import createMuiTheme from './../core/styles/createMuiTheme';
import * as colors from './../core/colors';

import findComponents from './find-components';
import ensureExists from './ensure-folder-exists';

const MuiPath = path.resolve(__dirname, '../', 'core');

const components = findComponents();
const theme = createMuiTheme();
const rootDirectory = MuiPath;
const outputDirectory = path.join(__dirname, '../../../', 'output', 'json');

rimraf.sync(path.join(outputDirectory, '*.json'));

components.forEach(componentPath => {
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
        name: null
    };

    if (component.styles && component.default.options) {
        // Collect the customization points of the `classes` property.
        styles.classes = Object.keys(
            getStylesCreator(component.styles).create(theme)
        ).filter(className => !className.match(/^(@media|@keyframes)/));
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
    reactAPI.importPath = '@material-ui/core'; // `@material-ui/core/${componentPath.replace(`${rootDirectory}/`, '').replace('.js', '')}`;

    // Inheritance
    const inheritedComponentRegexp = /\/\/ @inheritedComponent (.*)/;
    const inheritedComponent = src.match(inheritedComponentRegexp);
    const inheritsFrom = !inheritedComponent ? '' : inheritedComponent[1];
    reactAPI.inheritsFrom = inheritsFrom;

    if (typeof reactAPI.props.classes !== 'undefined') {
        reactAPI.props.classes.flowType = {
            name: 'classes',
            elements: reactAPI.styles.classes
        };
    }

    ensureExists(outputDirectory, 0o744, err => {
        if (err) {
            console.log('Error creating directory', outputDirectory);
            console.log(err);
            return;
        }

        writeFileSync(
            path.resolve(outputDirectory, `${kebabCase(reactAPI.name)}.json`),
            JSON.stringify(reactAPI)
        );

        console.log('Extracted JSON for', componentPath);
    });
});

ensureExists(outputDirectory, 0o744, err => {
    if (err) {
        console.log('Error creating directory', outputDirectory);
        console.log(err);
        return;
    }

    // Icons
    // const regex = /export { default as ([a-zA-Z]*) } from '[a-zA-Z./]*';/gm;
    // let iconArray = [];
    // const str = readFileSync(path.join(__dirname, '../core', 'icons.js'), 'utf-8');
    // let m;
    // while ((m = regex.exec(str)) !== null) {
    //     // This is necessary to avoid infinite loops with zero-width matches
    //     if (m.index === regex.lastIndex) {
    //         regex.lastIndex++;
    //     }

    //     iconArray.push(m[1]);
    // }

    // writeFileSync(path.resolve(outputDirectory, `icons.json`), JSON.stringify(iconArray));
    // console.log('Extracted JSON for Icons');

    writeFileSync(
        path.resolve(outputDirectory, `colors.json`),
        JSON.stringify(colors)
    );
    console.log('Extracted JSON for Colors');
});
