import Base from './base';
import ResolveArgument from './resolve-argument';
import GenerateReasonName from '../../helpers/generate-reason-name';

const factory = (propertyType: PropType$Shape) => {
  return class ShapeParser extends Base {
    private _propertyType: PropType$Shape = propertyType;

    public executeParse() {
      const shapeArgs = this.resolveShape();
      if (shapeArgs.length) {
        this._module = `
                    module ${this._moduleName} {
                        [@bs.deriving abstract]
                        type t = {
                            ${shapeArgs
                              .map(
                                (arg) => `
                                ${!arg.required ? '[@bs.optional]' : ''}
                                ${
                                  arg.key !== arg.keySafe
                                    ? `[@bs.as "${arg.key}"]`
                                    : ''
                                }
                                ${arg.keySafe}: ${arg.type}
                            `,
                              )
                              .join(',')}
                        };
                        let make = t;
                    };
                `;

        this._reasonType = `${this._moduleName}.t`;
      } else {
        this._valid = false;
      }
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
            keySafe: GenerateReasonName(key, false),
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
