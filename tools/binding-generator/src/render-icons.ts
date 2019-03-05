import * as Fs from 'fs';
import * as Path from 'path';
import outputDirectory from './output';

type iconSuffix = 'Default' | 'Outlined' | 'Rounded' | 'TwoTone' | 'Sharp';

const GetIcons = (): string[] => JSON.parse(Fs.readFileSync(Path.join(outputDirectory, 'json', 'icons.json'), 'utf8'));

const RenderIcons = (suffix: iconSuffix) => {
    const icons = GetIcons().filter(icon => {
        switch (suffix) {
            case 'Default':
                return !icon.endsWith('Outlined') && !icon.endsWith('Rounded') && !icon.endsWith('TwoTone') && !icon.endsWith('Sharp');
            default:
                return icon.endsWith(suffix);
        }
    });

    return icons.reduce((prev, iconName) => ({
        ...prev, [iconName]: `
            module ${iconName} = MaterialUi_Make_Icon.Make({
                [@bs.module "@material-ui/icons/AcUnit"]
                external reactClass: ReasonReact.reactClass = "default";
            });
            include ${iconName};
        `}), {});
};

export default {
    'Default': RenderIcons('Default'),
    'Outlined': RenderIcons('Outlined'),
    'Rounded': RenderIcons('Rounded'),
    'TwoTone': RenderIcons('TwoTone'),
    'Sharp': RenderIcons('Sharp'),
};