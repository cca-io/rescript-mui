import { JSONSchema7Type } from 'json-schema';
import BaseParser from './_base';
import { generateAttributeName, generateModuleName } from '../helpers';

class EnumParser extends BaseParser {
  private enumType: 'string' | 'float' | 'int' = 'string';
  private enums: Array<JSONSchema7Type>;

  public parse(): void {
    if (typeof this.def === 'boolean') {
      return;
    }
    if (!this.def.enum) {
      return;
    }
    this.enums = this.def.enum;
    if (!this.def.type) {
      return;
    }

    if (this.def.type === 'integer') {
      this.enumType = 'int';
      return;
    }
    if (this.def.type === 'number') {
      this.enumType = 'float';
      return;
    }
  }

  public getReasonType(): string {
    return this.enumType;
  }

  public getGetterFunc(optional: boolean) {
    const attributeName = generateAttributeName(this.key);
    return `
        @bs.deriving(jsConverter)
        type ${attributeName}Converter = [
            ${this.enums
              .map(
                (v) => `
                | #${generateModuleName(`${v}`)}
            `,
              )
              .join('\n')}
        ];
        let ${attributeName}Get = (value) => ${
      optional
        ? `
            ${attributeName}Get(value)->Belt.Option.map(v => ${attributeName}ConverterFromJs(v));
        `
        : `
        ${attributeName}Get(value)->${attributeName}ConverterFromJs;
        `
    }`;
  }

  public render() {
    return '';
  }
}

export default EnumParser;
