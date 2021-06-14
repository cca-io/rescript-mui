import GetPropertyParser from './index';
import Property from './../property';
import * as Console from '../../helpers/console';

export default function (
  name: string,
  required: boolean,
  type: PropType,
  originalProperty: Property,
) {
  const argumentProperty = new Property(
    name,
    {
      required,
      type,
      description: '',
      defaultValue: { computed: false, value: '' },
    },
    originalProperty.component,
    false,
  );

  const Parser = GetPropertyParser(type);
  if (Parser) {
    const parser = new Parser(argumentProperty, 'moduleOnly');
    parser.parse();

    return parser;
  } else {
    console.log(type);
    Console.error(
      `resolveArgument: Could not find parser for argument ${Console.colors.green}${originalProperty.component.name}/${originalProperty.name}/${name}/${type.name}${Console.colors.reset}`,
    );

    return false;
  }
}
