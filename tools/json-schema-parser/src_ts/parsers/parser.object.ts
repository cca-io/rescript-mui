import BaseParser from './_base';
import getParser from './_getParser';

import { generateModuleName, generateAttributeName } from '../helpers';

let i = 0;

class ObjectParser extends BaseParser {
    private properties: BaseParser[] = [];
    private moduleName: string;
    private module: moduleDefinition;

    public parse() {
        this.moduleName = generateModuleName(this.key);

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
        Object.keys(properties).forEach(key => {
            const parser = getParser(this.schema, properties[key]);
            if (!parser) {
                return;
            }
            i = i + 1;
            if (i > 10000) {
                throw 'FUCK';
            }
            this.properties.push(new parser(this.schema, key, properties[key]));
        });
        this.properties.forEach(p => p.parse());

        if (!this.properties.length) {
            return;
        }
        const required = this.def.required ? this.def.required : [];

        this.module = this.schema.modules[this.moduleName] = {
            name: this.moduleName,
            properties: this.properties.map(property => ({
                name: property.key,
                optional: !required.includes(property.key),
                reasonType: property.getReasonType(),
            }))
        };
        this.schema.moduleParsers[this.moduleName] = this;
    }

    public getReasonType() {
        if (this.properties.length) {
            const genericObjects = this.module.properties.filter(p => p.reasonType === 'Js.t({..})').map(p => `'${generateAttributeName(p.name)}`).join(',');
            return `${this.moduleName}.t${genericObjects ? `(${genericObjects})` : ''}`;
        }
        else {
            return 'Js.Json.t';
        }
    }

    public getGenericObjectProperties() {
        const genericObjectProperties = [
            ...this.module.properties.filter(p => p.reasonType === 'Js.t({..})').map(p => `'${generateAttributeName(p.name)}`),
            ...this.module.properties.filter(p => p.reasonType.includes('.t(') && !p.reasonType.includes('{..}')).reduce((prev, p) => {
                const re = /.*\.t\((.*)\)/m;
                const match = re.exec(p.reasonType);
                if (match) {
                    const parts = match[1].split(',');
                    return [...prev, ...parts];
                }
                return prev;
            }, [])
        ];
        return genericObjectProperties.join(',');
    }

    public render() {
        const genericObjects = this.getGenericObjectProperties();

        return `
            module ${this.moduleName} {
                [@bs.deriving abstract]
                type t${genericObjects ? `(${genericObjects})` : ''} = {
                    ${this.module.properties.map(property => {
                const attributeName = generateAttributeName(property.name);
                return `
                            ${property.optional ? '[@bs.optional]' : ''}
                            [@bs.as "${property.name}"]
                            ${attributeName}: ${property.reasonType.replace('Js.t({..})', `Js.t('${attributeName})`)},
                        `;
            }).join('\n')}
                };
                ${this.properties.map(property => property.getGetterFunc(this.module.properties.filter(p => p.name === property.key)[0].optional)).join('\n')}
                let make = t;
            }
        `;
    }
}

export default ObjectParser;