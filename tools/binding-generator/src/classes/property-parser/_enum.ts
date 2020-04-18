import GenerateReasonName, {
  isNumeric,
} from './../../helpers/generate-reason-name';
import Base from './base';
import { generateAny } from './helpers';
import Property from '../property';
import { upperFirst } from 'lodash';

const factory = (propertyType: PropType$Enum) => {
  return class EnumParser extends Base {
    private _propertyType: PropType$Enum = propertyType;
    private _moduleName = upperFirst(
      this.property.safeName.startsWith('_')
        ? this.property.safeName.substr(1)
        : this.property.safeName,
    );

    constructor(
      property: Property,
      emitToComponent: boolean | 'moduleOnly' = true,
    ) {
      super(property, emitToComponent);
      this._gatherEnumValues();
    }

    private _hasString = 0;
    private _hasNumeric = 0;
    private _hasBool = 0;
    private _enumKeys: string[] = [];
    private _enumValues: any[] = [];
    private _renderAs: 'string' | 'numeric' | 'mixed' = 'mixed';

    public get enumType() {
      return this._renderAs;
    }

    public set enumType(value) {
      this._renderAs = value;
    }

    private _gatherEnumValues() {
      this._enumKeys = this._propertyType.value
        .filter((e) => !e.computed)
        .map((e) =>
          e.value.substr(0, 1) === "'" || e.value.substr(0, 1) === '"'
            ? e.value.substr(1, e.value.length - 2)
            : e.value,
        );
      this._enumValues = this._propertyType.value
        .filter((e) => !e.computed)
        .map((e) => {
          if (e.value.substr(0, 1) === "'" || e.value.substr(0, 1) === '"') {
            this._hasString++;
            return e.value.substr(1, e.value.length - 2);
          }
          if (e.value === 'true' || e.value === 'false') {
            this._hasBool++;
            return e.value === 'true';
          }
          if (!isNumeric(e.value)) {
            this._hasString++;
            return e.value;
          }
          if (isNumeric(e.value)) {
            this._hasNumeric++;
            return parseInt(e.value);
          }
          this._hasString++;
          return e.value;
        });
      if (
        (this._hasString && this._hasNumeric) ||
        (this._hasString && this._hasBool) ||
        (this._hasNumeric && this._hasBool)
      ) {
        this._renderAs = 'mixed';
      } else if (this._hasString && !this._hasNumeric && !this._hasBool) {
        this._renderAs = 'string';
      } else if (this._hasNumeric && !this._hasString && !this._hasBool) {
        this._renderAs = 'numeric';
      }
    }

    public executeParse() {
      const enumValuesReason = this._enumKeys.map((e) => GenerateReasonName(e));
      let enumName = this.property.safeName;
      switch (this._renderAs) {
        case 'mixed':
          this._module = `
                module ${this._moduleName} {
                    type t = [
                        ${enumValuesReason
                          .map((name) => `| \`${name}`)
                          .join('\n')}
                    ];
                    let tToJs = fun ${enumValuesReason
                      .map((name, i) => {
                        let value = this._enumValues[i];
                        if (typeof value === 'string') {
                          value = `"${value}"`;
                        } else if (typeof value === 'boolean') {
                          value = value ? 'true' : 'false';
                        }
                        return `| \`${name} => ${value}->Obj.magic`;
                      })
                      .join('\n')}
                };
                `;
          enumName = `${this._moduleName}.t`;
          this._jsType = generateAny();
          break;
        case 'numeric':
          this._module = `
                [@bs.deriving jsConverter]
                type ${enumName} =
                    ${enumValuesReason
                      .map(
                        (name, i) =>
                          `| [@bs.as ${this._enumValues[i]}] ${name}`,
                      )
                      .join('\n')}
                ;`;
          break;
        case 'string':
          this._module = `
                    [@bs.deriving jsConverter]
                    type ${enumName} = [
                        ${enumValuesReason
                          .map(
                            (name, i) =>
                              `| [@bs.as "${this._enumValues[i]}"] \`${name}`,
                          )
                          .join('\n')}
                    ];`;
          break;
      }

      this._reasonType = enumName;
      if (this._renderAs === 'string') {
        this._jsType = 'string';
      } else if (this._renderAs === 'numeric') {
        this._jsType = generateAny('number');
      }
      if (this.property.signature.required) {
        this._wrapJs = (name) => `${enumName}ToJs(${name})`;
      } else {
        this._wrapJs = (name) =>
          `${name}->Belt.Option.map((v => ${enumName}ToJs(v)))`;
      }
    }
  };
};

export default factory;
