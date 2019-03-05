import Base from './base';
import ResolveArgument from './resolve-argument';
import GenerateReasonName from '../../helpers/generate-reason-name';

const factory = (propertyType: PropType$Shape) => {
    return class ShapeArgumentParser extends Base {
        private _propertyType: PropType$Shape = propertyType;

        public executeParse() {
            const shapeArgs = this.resolveShape();
            if (shapeArgs.length) {
                this._reasonType = `{.
                    ${shapeArgs.map(arg => `"${arg.key}": ${arg.type}`).join(',')}
                }`;
            }
            else {
                this._reasonType = 'Js.t({..})';
            }
        }

        private resolveShape() {
            const shapes: { key: string, keySafe: string, type: string, required: boolean }[] = [];

            Object.keys(this._propertyType.value).forEach(key => {
                const type = this._propertyType.value[key];
                if (type.name === 'shape') {
                    type.name = 'shapeArgument';
                }
                const argumentParser = ResolveArgument(key, type.required, type, this._property);
                if (argumentParser) {
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