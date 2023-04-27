import Base from './base';
import ResolveArgument from './resolve-argument';
import GenerateRescriptName from '../../helpers/generate-rescript-name';
import { inShape } from './helpers';

const factory = (propertyType: PropType$Shape) => {
  return class ShapeParser extends Base {
    private _propertyType: PropType$Shape = propertyType;

    public executeParse() {
      inShape.enter();
      const shapeArgs = this.resolveShape();
      if (shapeArgs.length) {
        this._module = `
          module ${this._moduleName} = {
            type t = {
              .
              ${shapeArgs
                .map((arg) => {
                  return `
                "${arg.key}":option<${arg.type}>
                `;
                })
                .join(',')}
            }
            @obj external make: (
              ${shapeArgs
                .map((arg) => {
                  return `
                  ~${arg.keySafe}:
                  ${arg.type}=?
                  `;
                })
                .join(',')}
            , unit) => t = ""
          };
      `;

        this._reasonType = `${this._moduleName}.t`;
      } else {
        this._valid = false;
      }
      inShape.exit();
    }

    private resolveShape() {
      const shapes: {
        key: string;
        keySafe: string;
        type: string;
        required: boolean;
      }[] = [];

      Object.keys(this._propertyType.value).forEach((key) => {
        const type = this._propertyType.value[key];
        const argumentParser = ResolveArgument(
          key,
          type.required,
          type,
          this._property,
        );
        if (argumentParser && argumentParser.valid) {
          shapes.push({
            key,
            keySafe: GenerateRescriptName(key, false),
            type: argumentParser.reasonType,
            required: type.required,
          });
        }
      });

      return shapes;
    }
  };
};

export default factory;
