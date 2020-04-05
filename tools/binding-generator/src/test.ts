import * as Fs from 'fs';
import * as Path from 'path';
import RenderTheme from './render-theme';
import outputDirectory from './output';

Fs.writeFileSync(
  Path.join(outputDirectory, 'reason', 'MaterialUi_Theme.re'),
  RenderTheme.theme,
);
Fs.writeFileSync(
  Path.join(outputDirectory, 'reason', 'MaterialUi_ThemeOptions.re'),
  RenderTheme.themeOptions,
);
