import * as Console from './../../helpers/console';
import Base from './base';
import { inShape } from './helpers';

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
          this._reasonType = 'MaterialUi_Types.Number.t';
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
        case 'ReactNode':
        case 'element':
        case 'Element':
        case 'element':
        case 'ComponentType<object>':
        case 'Element<any>':
          this._reasonType = 'React.element';
          break;

        // Generic Object
        case 'object':
        case 'Object':
          if (inShape.is()) {
            this._reasonType = 'MaterialUi_Types.any';
          } else {
            this._reasonType = 'Js.t({..})';
          }
          break;

        // Function without Signature / Any
        case 'any':
          this._reasonType = 'MaterialUi_Types.any';
          break;

        // Generic array
        case 'array':
          this._reasonType = `array(MaterialUi_Types.any)`;
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
