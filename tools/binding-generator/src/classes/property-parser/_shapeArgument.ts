import Base from './base';
import ResolveArgument from './resolve-argument';
import GenerateRescriptName from '../../helpers/generate-rescript-name';
import { inShape } from './helpers';

const factory = (propertyType: PropType$Shape) => {
  return class ShapeArgumentParser extends Base {
    private _propertyType: PropType$Shape = propertyType;
    private inShapeBefore: boolean;

    public executeParse() {
      this.inShapeBefore = inShape.is();
      inShape.enter();
      const shapeArgs = this.resolveShape();
      if (shapeArgs.length) {
        this._reasonType = `{.
                    ${shapeArgs
                      .map((arg) => `"${arg.key}": ${arg.type}`)
                      .join(',')}
                }`;
      } else {
        this._reasonType = 'Helpers.any';
      }
      inShape.exit();
      inShape.set(this.inShapeBefore);
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
        if (type.name === 'shape') {
          type.name = 'shapeArgument';
        }
        const argumentParser = ResolveArgument(
          key,
          type.required,
          type,
          this._property,
        );
        if (argumentParser) {
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
