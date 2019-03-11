import * as Console from './../../helpers/console';
import { generateAny } from './helpers';
import Base from './base';

const factory = (propertyType: PropType$Primitive) => {
    return class PrimitiveParser extends Base {
        private _propertyType: PropType$Primitive = propertyType;

        public executeParse() {
            switch (this._propertyType.name) {
                // -- String
                case 'string':
                case 'String':
                    this._reasonType = 'string';
                    break;

                // -- Boolean
                case 'bool':
                case 'boolean':
                    this._reasonType = 'bool';
                    break;

                // -- Number
                case 'number':
                    this._reasonType = '[ | `Int(int) | `Float(float) ]';
                    this._jsType = `'number_${Math.random()
                        .toString(36)
                        .substr(2, 1)}`;

                    if (this.required) {
                        this._wrapJs = name =>
                            `MaterialUi_Helpers.unwrapValue(${name})`;
                    } else {
                        this._wrapJs = name =>
                            `${name} |. Belt.Option.map((v) => MaterialUi_Helpers.unwrapValue(v))`;
                    }
                    break;
                case 'int':
                    this._reasonType = 'int';
                    break;
                case 'float':
                    this._reasonType = 'float';
                    break;

                // React Element
                case 'node':
                case 'Node':
                case 'element':
                case 'Element':
                case 'ReactElement':
                case 'ComponentType<object>':
                case 'Element<any>':
                    this._reasonType = 'React.element';
                    break;

                // Generic Object
                case 'object':
                case 'Object':
                    this._reasonType = 'Js.t({..})';
                    break;

                // Function without Signature / Any
                case 'any':
                    this._reasonType = generateAny();
                    break;

                // Generic array
                case 'array':
                    this._reasonType = `array(${generateAny()})`;
                    break;

                // Void return types
                case 'void':
                    this._reasonType = 'unit';
                    break;

                // Unhandled
                default:
                    this._valid = false;
                    Console.warn(
                        `PrimitiveParser: Primitive type ${
                            Console.colors.red
                        }${JSON.stringify(this._propertyType.name)}${
                            Console.colors.yellow
                        } does not map to anything`,
                    );
            }
        }
    };
};

export default factory;
