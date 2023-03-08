import * as Fs from 'fs';
import * as Path from 'path';
import { capitalize } from './helpers/generate-rescript-name';
import outputDirectory from './output';

interface ColorFile {
  [colorName: string]: {
    [colorCode: string]: string;
  };
}

const GetColors = (): ColorFile =>
  JSON.parse(
    Fs.readFileSync(
      Path.join(outputDirectory, 'json', 'material', 'colors.json'),
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
                      \"${key}": string,
                  `,
                  )
                  .join('\n')}
            };
            @module("@mui/material/colors") external ${colorName}: t${capitalize(
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
