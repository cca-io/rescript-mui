import GenerateReasonName, { isNumeric } from './../../helpers/generate-reason-name';
import Base from './base';
import { generateAny } from './helpers';

const factory = (propertyType: PropType$Enum) => {
    return class EnumParser extends Base {
        private _propertyType: PropType$Enum = propertyType;

        private _isNumeric: null | boolean = null;

        public executeParse() {
            const enumKeys = this._propertyType.value.filter(e => !e.computed).map(e => e.value.substr(0, 1) === '\'' || e.value.substr(0, 1) === '"' ? e.value.substr(1, e.value.length - 2) : e.value);
            const enumValues = this._propertyType.value.filter(e => !e.computed).map(e => {
                if (e.value.substr(0, 1) === '\'' || e.value.substr(0, 1) === '"') {
                    this._isNumeric = false;
                    return e.value.substr(1, e.value.length - 2);
                }
                else if (!isNumeric(e.value)) {
                    this._isNumeric = false;
                    return e.value;
                }
                else {
                    if (this._isNumeric === null) {
                        this._isNumeric = true;
                    }
                    if (isNumeric(e.value)) {
                        return parseInt(e.value);
                    }
                    else if (e.value === 'true') {
                        return 1;
                    }
                    else {
                        return 0;
                    }
                }
            });

            const enumValuesReason = enumKeys.map(e => GenerateReasonName(e));
            const enumName = this.property.safeName;

            if (this._isNumeric) {
                this._module = `
                [@bs.deriving jsConverter]
                type ${enumName} =
                    ${enumValuesReason.map((name, i) => `| [@bs.as ${enumValues[i]}] ${name}`).join('\n')}
                ;`;
            }
            else {
                this._module = `
                [@bs.deriving jsConverter]
                type ${enumName} = [
                    ${enumValuesReason.map((name, i) => `| [@bs.as "${enumValues[i]}"] \`${name}`).join('\n')}
                ];`;
            }

            this._reasonType = enumName;
            this._jsType = this._isNumeric ? generateAny('number') : 'string';
            if (this.property.signature.required) {
                this._wrapJs = (name) => `${enumName}ToJs(${name})`;
            }
            else {
                this._wrapJs = (name) => `${name} |. Belt.Option.map((v => ${enumName}ToJs(v)))`;
            }
        }
    }
};

export default factory;