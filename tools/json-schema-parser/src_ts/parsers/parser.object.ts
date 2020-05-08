import BaseParser from './_base';
import getParser from './_getParser';

import { generateModuleName, generateAttributeName } from '../helpers';

let i = 0;

class ObjectParser extends BaseParser {
  private properties: BaseParser[] = [];
  private moduleName: string;
  private module: moduleDefinition;
  private typeName: string;

  public parse() {
    this.moduleName = generateModuleName(this.key);
    this.typeName = `t_${generateAttributeName(this.key)}`;

    if (typeof this.def === 'boolean') {
      return;
    }
    if (!this.def.properties) {
      return;
    }
    // if (this.schema.hasModule(this.key)) {
    //     return;
    // }

    const properties = this.def.properties;
    Object.keys(properties).forEach((key) => {
      const parser = getParser(this.schema, properties[key], key);
      if (!parser) {
        return;
      }
      i = i + 1;
      if (i > 10000) {
        throw 'FUCK';
      }
      this.properties.push(new parser(this.schema, key, properties[key]));
    });
    this.properties.forEach((p) => p.parse());

    if (!this.properties.length) {
      return;
    }
    const required = this.def.required ? this.def.required : [];

    this.module = this.schema.modules[this.moduleName] = {
      name: this.moduleName,
      properties: this.properties.map((property) => ({
        name: property.key,
        optional: !required.includes(property.key),
        reasonType: property.getReasonType(),
      })),
    };
    this.schema.moduleParsers[this.moduleName] = this;
  }

  public getReasonType() {
    if (this.properties.length) {
      if (this.schema.records) {
        return `${this.typeName}`;
      }

      return `${this.moduleName}.t`;
    } else {
      return 'MaterialUi_Types.any';
    }
  }

  public render() {
    if (this.schema.records) {
      return `
        type ${this.typeName} = {
            ${this.module.properties
              .map((property) => {
                const attributeName = generateAttributeName(property.name);
                return `
                    ${
                      attributeName !== property.name
                        ? `[@bs.as "${property.name}"]`
                        : ''
                    }
                    ${attributeName}: ${property.reasonType},
                `;
              })
              .join('\n')}
        };
    `;
    }

    const content = `
type t = {
    .
    ${this.module.properties
      .map((property) => {
        return `
            "${property.name}": option(option(${property.reasonType}))
          `;
      })
      .join(',')}
};
[@bs.obj] external make: (
    ${this.module.properties
      .map((property) => {
        const attributeName = generateAttributeName(property.name);
        return `
                ~${attributeName}:
                ${property.reasonType}=?
            `;
      })
      .join(',')}
, unit) => t = "";`;
    return this.schema.entry === this.key
      ? content
      : `
        module ${this.moduleName} {
            ${content}
        };
    `;
  }
}

export default ObjectParser;
