import BaseParser from './_base';

import { generateAttributeName } from '../helpers';

class UnionParser extends BaseParser {
    public parse(): void {
    }
    public getReasonType(): string {
        return 'string';
    }

    public render() {
        return '';
    }

    public getGetterFunc(optional: boolean) {
        const attributeName = generateAttributeName(this.key);
        return `let ${attributeName}Get = (value) => {
            let isNumeric: 'a => bool = [%raw {|
                function(obj) {
                    var realStringObj = obj && obj.toString();
                    return typeof obj !== 'object' && (realStringObj - parseFloat(realStringObj) + 1) >= 0;
                }
            |}];
            let isBool: 'a => bool = [%raw {|
                function(obj) {
                    return typeof obj === 'boolean';
                }
            |}];
            ${optional ? `
                ${attributeName}Get(value)->Belt.Option.map(v => isNumeric(v) ? \`Float(Obj.magic(v)) : isBool(v) ? \`Bool(Obj.magic(v)) : \`String(Obj.magic(v)));
            ` : `
            let v = ${attributeName}Get(value);
            isNumeric(v) ? \`Float(Obj.magic(v)) : isBool(v) ? \`Bool(Obj.magic(v)) : \`String(Obj.magic(v));
            `}
        };`;
    }
}

export default UnionParser;