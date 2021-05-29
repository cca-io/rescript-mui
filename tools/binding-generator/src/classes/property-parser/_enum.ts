import GenerateReasonName, {
  isNumeric,
} from './../../helpers/generate-reason-name';
import Base from './base';
import Property from '../property';

const factory = (propertyType: PropType$Enum) => {
  return class EnumParser extends Base {
    private _propertyType: PropType$Enum = propertyType;

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
      const enumValuesReason = this._enumKeys.map((e) =>
        GenerateReasonName(e, false),
      );
      switch (this._renderAs) {
        case 'mixed':
          const mixedKeys = this._enumKeys.map((e) =>
            GenerateReasonName(e, false),
          );
          this._module = `
                module ${this._moduleName}: {
                    type t;
                    ${mixedKeys.map((key) => `let ${key}: t;`).join('\n')}
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    ${mixedKeys
                      .map((key, i) => {
                        let value = this._enumValues[i];
                        if (typeof value === 'string') {
                          value = `"${value}"`;
                        } else if (typeof value === 'boolean') {
                          value = value ? 'true' : 'false';
                        }
                        return `let ${key} = Any(${value});`;
                      })
                      .join('\n')}
                };
                `;
          this._reasonType = `${this._moduleName}.t`;
          break;
        case 'string':
          this._module = `
            type ${this._property.safeName} = [${enumValuesReason
            .map((name, i) => {
              return this._enumValues[i] === name
                ? `#${name}`
                : `#\\"${this._enumValues[i]}"`;
            })
            .join(' | ')}];
          `;
          this._reasonType = this._property.safeName;
          break;
        case 'numeric':
          this._module = `
            type ${this._property.safeName} = [${enumValuesReason
            .map((name, i) => `#${name}`)
            .join(' | ')}];
          `;
          this._reasonType = `@int [${enumValuesReason
            .map((name, i) => `@as(${this._enumValues[i]}) #${name}`)
            .join(' | ')}]`;
          break;
      }
    }
  };
};

export default factory;
