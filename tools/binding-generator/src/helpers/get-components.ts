import * as Path from 'path';
import * as Fs from 'fs';

import outputDirectory from '../output';

const GetComponents = (): string[] => {
    const dir = Path.join(outputDirectory, 'json');
    const items = Fs.readdirSync(dir);

    return items.filter(item => item.lastIndexOf('.json') === item.length - 5 && item !== 'colors.json' && item !== 'icons.json' && item !== 'theme.json' && item !== 'theme-options.json').map(item => Fs.readFileSync(Path.join(dir, item), 'utf8'));
};

export default GetComponents;