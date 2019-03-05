import { JSONSchema7Definition } from 'json-schema';
import SchemaParser from './schema';

export interface Parser {
    readonly schema: SchemaParser;
    readonly def: JSONSchema7Definition;
    readonly key: string;

    parse(): void;
    getReasonType(): string;
    getGetterFunc(optional: boolean): string;
    render(): string;
}

export interface ParserConstructable {
    new(schema: SchemaParser, key: string, def: JSONSchema7Definition): Parser;
}

abstract class BaseParser implements Parser {
    public readonly schema: SchemaParser;
    public readonly def: JSONSchema7Definition;
    public readonly key: string;

    public constructor(schema: SchemaParser, key: string, def: JSONSchema7Definition) {
        this.key = key;
        this.schema = schema;
        this.def = def;
    }

    public abstract parse(): void;

    public abstract getReasonType(): string;

    public getGetterFunc(optional: boolean) { return '' };

    public abstract render(): string;
}

export default BaseParser;