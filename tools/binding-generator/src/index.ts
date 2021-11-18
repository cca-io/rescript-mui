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
      Path.join(outputDirectory, 'rescript', muiSrc, `${name}.res`),
      src,
    );
  });

  // Copy fixed modules
  const items = Fs.readdirSync(Path.join(__dirname, 'fixed-modules'));
  const itemsFiltered = items.filter(
    (item) =>
      item.lastIndexOf('.res') === item.length - 4 ||
      item.lastIndexOf('.js') === item.length - 3,
  );
  itemsFiltered.forEach((item) => {
    Fs.copyFileSync(
      Path.join(__dirname, 'fixed-modules', item),
      Path.join(outputDirectory, 'rescript', muiSrc, item),
    );
  });

  Fs.writeFileSync(
    Path.join(outputDirectory, 'rescript', muiSrc, 'Theme.res'),
    RenderTheme.theme,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'rescript', muiSrc, 'ThemeOptions.res'),
    RenderTheme.themeOptions,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'rescript', muiSrc, 'Colors.res'),
    RenderColors.colorModule,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'rescript', muiSrc, 'ThemeOptions.res'),
    RenderTheme.themeOptions,
  );

  // Append create theme function
  const themePath = Path.join(outputDirectory, 'rescript', muiSrc, 'Theme.res');
  const themeContents = Fs.readFileSync(themePath);
  Fs.writeFileSync(
    themePath,
    `
        ${themeContents}

        @module("@material-ui/core/styles") external create: ThemeOptions.t => t = "createMuiTheme";
    `,
  );
};

PrepareOutput(muiSrc);
parseInit();
