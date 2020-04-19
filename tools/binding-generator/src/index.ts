import * as Fs from 'fs';
import * as Path from 'path';

import outputDirectory from './output';
import RenderColors from './render-colors';
import RenderTheme from './render-theme';
import ParseComponents from './parse-components';
import PrepareOutput from './prepare-output';

const muiSrc: muiSrc = 'core';

const parseInit = () => {
  const components = ParseComponents(muiSrc);

  // Write component files
  components.forEach(({ name, src }) => {
    Fs.writeFileSync(
      Path.join(outputDirectory, 'reason', muiSrc, `MaterialUi_${name}.re`),
      src,
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
      Path.join(outputDirectory, 'reason', muiSrc, item),
    );
  });

  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', muiSrc, 'MaterialUi_Theme.re'),
    RenderTheme.theme,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', muiSrc, 'MaterialUi_ThemeOptions.re'),
    RenderTheme.themeOptions,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', muiSrc, 'MaterialUi_Colors.re'),
    RenderColors.colorModule,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', muiSrc, 'MaterialUi_ThemeOptions.re'),
    RenderTheme.themeOptions,
  );

  // Write global file
  // ${itemsFiltered.map(item => `module ${item.replace('MaterialUi_', '').replace('.re', '')} = ${item.replace('.re', '')};`).join('\n')}
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', muiSrc, 'MaterialUi.re'),
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
        module Core = MaterialUi_Core;
        module Theme = MaterialUi_Theme;
        module ThemeOptions = MaterialUi_ThemeOptions;
        module ThemeProvider = MaterialUi_ThemeProvider;
        module ThemeHelpers = MaterialUi_ThemeHelpers;
        module MuiThemeProvider = MaterialUi_ThemeProvider;
        module WithStyles = MaterialUi_WithStyles;
    `,
  );

  // Append create theme function
  const themePath = Path.join(
    outputDirectory,
    'reason',
    muiSrc,
    'MaterialUi_Theme.re',
  );
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

PrepareOutput(muiSrc);
parseInit();
