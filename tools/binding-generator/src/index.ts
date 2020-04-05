import * as Fs from 'fs';
import * as Path from 'path';
import * as rimraf from 'rimraf';

import outputDirectory from './output';
import * as Console from './helpers/console';
import GetComponents from './helpers/get-components';
import Component from './classes/component';
import RenderColors from './render-colors';
// import RenderIcons from './render-icons';
import RenderTheme from './render-theme';

const parseInit = () => {
  const rawComponents = GetComponents();
  const components = rawComponents.map((jsonString: string) => {
    try {
      const json = JSON.parse(jsonString);
      Console.info(
        `Parsing ${Console.colors.yellow}${json.name || json.displayName}${
          Console.colors.reset
        }`,
      );
      return new Component(jsonString);
    } catch (e) {
      console.log(e);
      Console.error(e);
      Console.error(jsonString);
      process.exit();
      return null;
    }
  });

  // Inheritance
  components.forEach((c) => {
    if (c != null && c.inheritsFrom) {
      const cInherit = components.find(
        (ci) => ci != null && ci.name === c.inheritsFrom,
      );
      if (cInherit != null) {
        c.mergeProperties(cInherit.properties);
      }
    }
  });

  // Write component files
  components.forEach((component) => {
    if (component == null) {
      return;
    }
    Console.info(
      `Rendering ${Console.colors.yellow}${component.name}${Console.colors.reset}`,
    );
    const rendered = component.render();
    Fs.writeFileSync(
      Path.join(outputDirectory, 'reason', `MaterialUi_${component.name}.re`),
      rendered,
    );
  });

  // Copy fixed modules
  const items = Fs.readdirSync(Path.join(__dirname, 'fixed-modules'));
  const itemsFiltered = items.filter(
    (item) =>
      item.lastIndexOf('.re') === item.length - 3 ||
      item.lastIndexOf('.js') === item.length - 3,
  );
  itemsFiltered.forEach((item) => {
    Fs.copyFileSync(
      Path.join(__dirname, 'fixed-modules', item),
      Path.join(outputDirectory, 'reason', item),
    );
  });

  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi_Theme.re'),
    RenderTheme.theme,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi_ThemeOptions.re'),
    RenderTheme.themeOptions,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi_Colors.re'),
    RenderColors.colorModule,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi_ThemeOptions.re'),
    RenderTheme.themeOptions,
  );

  // Write global file
  // ${itemsFiltered.map(item => `module ${item.replace('MaterialUi_', '').replace('.re', '')} = ${item.replace('.re', '')};`).join('\n')}
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi.re'),
    `
        ${components
          .map((component) =>
            component != null
              ? `module ${component.name} = MaterialUi_${component.name};`
              : '',
          )
          .join('\n')}
        
		module Colors = MaterialUi_Colors;
        module type WithStylesSafeTemplate = MaterialUi_WithStyles.WithStylesSafeTemplate;
        module WithStylesSafe = MaterialUi_WithStyles.WithStylesSafe;
        module Theme = MaterialUi_Theme;
        module ThemeOptions = MaterialUi_ThemeOptions;
        module ThemeProvider = MaterialUi_ThemeProvider;
        module ThemeHelpers = MaterialUi_ThemeHelpers;
        module MuiThemeProvider = MaterialUi_ThemeProvider;
        module WithStyles = MaterialUi_WithStyles;
    `,
  );

  // Append create theme function
  const themePath = Path.join(outputDirectory, 'reason', 'MaterialUi_Theme.re');
  const themeContents = Fs.readFileSync(themePath);
  Fs.writeFileSync(
    themePath,
    `
        ${themeContents}

        [@bs.module "@material-ui/core/styles"] external create: MaterialUi_ThemeOptions.t => t = "createMuiTheme";
    `,
  );

  // Todo: Generate .rei files
};

if (Fs.existsSync(Path.join(outputDirectory, 'reason'))) {
  rimraf.sync(Path.join(outputDirectory, 'reason'));
}
const requiredFolders = ['reason'];
requiredFolders.forEach((folder) => {
  const path = Path.join(outputDirectory, folder);
  if (!Fs.existsSync(path)) {
    Fs.mkdirSync(path);
  }
});

parseInit();
