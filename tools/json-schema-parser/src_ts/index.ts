// @ts-ignore
import { parseRE, printRE } from 'reason';
import { JSONSchema7 } from 'json-schema';
import SchemaParser, { options } from './parsers/schema';
import ObjectParser from './parsers/parser.object';

export default function (jsonString: string, extractType: string, options: options) {
    const testData: JSONSchema7 = JSON.parse(jsonString);

    const parser = new SchemaParser(testData, extractType, options);
    const e = parser.getEntryParser();
    if (e) {
        e.parse();

        let reason = Object.keys(parser.modules).map(name => {
            return parser.moduleParsers[name].render();
        }).join('\n');

        const entry = <ObjectParser>e;
        const genericObjects = entry.getGenericObjectProperties();
        reason += genericObjects ? `
            type t('p) = ${extractType}.t(${genericObjects}) constraint 'p = (${genericObjects}); let make = ${extractType}.make;
        ` : `type t = ${extractType}.t; let make = ${extractType}.make;`;

        let refmt = '';
        try {
            refmt = printRE(parseRE(reason));
        }
        catch (e) {
            console.log(e);
        }

        return {
            modules: parser.moduleParsers,
            string: reason,
            refmt,
        };
    }

    return false;
};