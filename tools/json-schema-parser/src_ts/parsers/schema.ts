import { JSONSchema7, JSONSchema7Definition } from 'json-schema';
import getParser from './_getParser';
import { Parser } from './_base';

export type options = {
    replaceRefs?: {
        re: RegExp,
        replaceWith: string,
    }[],
};

class SchemaParser {
    private readonly _schema: JSONSchema7;
    private readonly _entry: string;
    private readonly _definitions: { [name: string]: JSONSchema7Definition } | undefined[];
    private readonly _options: options;

    public modules: { [name: string]: moduleDefinition } = {};
    public moduleParsers: { [name: string]: Parser } = {};


    public hasModule = (name: string) => typeof this.modules[name] !== 'undefined';

    public getOptions = () => this._options;

    public getDefinition(defName: string): { moduleName: string, def: JSONSchema7Definition | undefined } {
        const defNameClean = defName.replace('#/definitions/', '');
        const re = /[<,&]([a-zA-Z_]*)[,>]/gm;
        const reResult = re.exec(defNameClean);
        const moduleName = reResult ? reResult[1] : defNameClean;
        return { moduleName, def: this._definitions[defNameClean] };
    }

    public constructor(schema: JSONSchema7, entry: string, options: options = {}) {
        this._entry = entry;
        this._schema = schema;
        this._definitions = (this._schema.definitions != null) ? this._schema.definitions : [];
        this._options = options;
    }

    public getEntryParser() {
        const entry = this._definitions[this._entry];
        const parser = getParser(this, entry);

        if (parser) {
            return new parser(this, this._entry, entry);
        }
        return false;
    }
}

export default SchemaParser;