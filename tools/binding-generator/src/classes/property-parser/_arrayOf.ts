// import * as Console from './../../helpers/console';
import { generateAny } from './helpers';
import Base from './base';
import * as Identify from './../../helpers/identify-prop-type';
import ResolveArgument from './resolve-argument';

const factory = (propertyType: PropType$ArrayOf) => {
    return class ArrayOfParser extends Base {
        private _propertyType: PropType$ArrayOf = propertyType;

        public executeParse() {
            const type = this._propertyType.value;

            let reasonType: false | string[] | string = false;

            if (Identify.isPrimitive(type) && ['string', 'number'].indexOf(type.name) > -1) {
                if (type.name === 'string') {
                    reasonType = 'array(string)';
                }
                else if (type.name === 'number') {
                    reasonType = ['IntArray(array(int))', 'FloatArray(array(float))'];
                }
            }
            else {
                const resolvedType = this.resolveType(type);
                if (resolvedType) {
                    if (resolvedType.valid) {

                        reasonType = `array(${resolvedType.reasonType})`;
                        if (this.property.signature.required) {
                            this._wrapJs = (name) => `${name} |. Belt.Array.map(item => MaterialUi_Helpers.toJsUnsafe(${resolvedType.wrapJs('item')}))`;
                        }
                        else {
                            this._wrapJs = (name) => `${name} |. Belt.Option.map((v) => v |. Belt.Array.map(item => MaterialUi_Helpers.toJsUnsafe(${resolvedType.wrapJs('item')})))`;
                        }
                    }
                }
            }

            if (Array.isArray(reasonType)) {
                this._reasonType = `[ ${reasonType.map(s => `| \`${s}`).join('')} ]`;
            }
            else if (typeof reasonType === 'string') {
                this._reasonType = reasonType;
            }
            else {
                this._reasonType = generateAny('invalidArrayType');
            }

            if (this._reasonType.indexOf('[') === 0) {
                this._jsType = generateAny('arrayOf');
            }
        }

        private resolveType(type: PropType) {
            const argumentParser = ResolveArgument(this._property.safeName, true, type, this._property);
            if (argumentParser) {
                return argumentParser;
            }

            return false;
        }
    }
};

export default factory;