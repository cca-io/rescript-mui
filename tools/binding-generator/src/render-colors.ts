import * as Fs from 'fs';
import * as Path from 'path';
import {
  capitalize,
  isNumeric,
  uncapitalize,
} from './helpers/generate-reason-name';
import outputDirectory from './output';

interface ColorFile {
  [colorName: string]: {
    [colorCode: string]: string;
  };
}

const GetColors = (): ColorFile =>
  JSON.parse(
    Fs.readFileSync(
      Path.join(outputDirectory, 'json', 'core', 'colors.json'),
      'utf8',
    ),
  );

const RenderColors = () => {
  const colors = GetColors();
  const colorDefinitions = Object.keys(colors).reduce((prev, colorName) => {
    return [
      `
        type t${capitalize(colorName)} = {
                ${Object.keys(colors[colorName])
                  .map(
                    (key) => `
                      [@bs.as "${key}"] ${
                      isNumeric(key) ? 'c' : ''
                    }${uncapitalize(key)}: string,
                  `,
                  )
                  .join('\n')}
            };
            [@bs.module "@material-ui/core/colors"] external ${colorName}: t${capitalize(
        colorName,
      )} = "${colorName}";
        `,
      ...prev,
    ];
  }, []);

  return {
    colorModule: colorDefinitions.join('\n'),
  };
};

export default RenderColors();
