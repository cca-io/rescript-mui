import { JSONSchema7Definition } from 'json-schema';

import { ParserConstructable } from './_base';
import Schema from './schema';
import ObjectParser from './parser.object';
import RefParser from './parser.ref';
import StringParser from './parser.string';
import FloatParser from './parser.float';
import IntParser from './parser.int';
import BoolParser from './parser.bool';
import ArrayParser from './parser.array';
import AllOfParser from './parser.allOf';
import UnionParser from './parser.union';
import EnumParser from './parser.enum';
import AnyOfParser from './parser.anyOf';

const getParser = (schema: Schema, def: JSONSchema7Definition): false | ParserConstructable => {
    if (typeof def !== 'boolean' && typeof def !== 'undefined') {
        if (def.type != null) {
            if (def.type === 'object') {
                return ObjectParser;
            }
            else if (def.type === 'boolean') {
                return BoolParser;
            }
            else if (def.type === 'integer') {
                return IntParser;
            }
            else if (def.type === 'number') {
                return FloatParser;
            }
            else if (def.type === 'string') {
                return StringParser;
            }
            else if (def.type === 'array') {
                return ArrayParser;
            }
            else if (Array.isArray(def.type)) {
                return UnionParser;
            }
        }
        else if (def.$ref != null) {
            return RefParser;
        }
        else if (def.allOf != null) {
            return AllOfParser;
        }
        else if (def.anyOf != null) {
            return AnyOfParser;
        }
        else if (def.enum != null) {
            return EnumParser;
        }
    }
    console.warn('NO_PARSER', def);
    return false;
};

export default getParser;