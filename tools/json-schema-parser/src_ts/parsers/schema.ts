import { JSONSchema7, JSONSchema7Definition } from 'json-schema';
import getParser from './_getParser';
import { Parser } from './_base';

export type options = {
  replaceRefs?: {
    re: RegExp;
    replaceWith: string;
  }[];
  replaceKeys?: {
    re: RegExp;
    replaceWith: any;
  }[];
  mode?: 'records' | 'objects';
};

class SchemaParser {
  private readonly _schema: JSONSchema7;
  private readonly _entry: string;
  private readonly _definitions:
    | { [name: string]: JSONSchema7Definition }
    | undefined[];
  private readonly _options: options;

  public modules: { [name: string]: moduleDefinition } = {};
  public moduleParsers: { [name: string]: Parser } = {};

  public hasModule = (name: string) =>
    typeof this.modules[name] !== 'undefined';

  public getOptions = () => this._options;
  public get records() {
    return (
      typeof this._options.mode !== 'undefined' &&
      this._options.mode === 'records'
    );
  }

  public getDefinition(
    defName: string,
    key?: string,
  ): { moduleName: string; def: JSONSchema7Definition | undefined } {
    const defNameClean = defName.replace('#/definitions/', '');
    const re = /[<,&]([a-zA-Z_]*)[,>]/gm;
    const reResult = re.exec(defNameClean);
    const alternativeName = defNameClean.includes('Partial')
      ? key || defNameClean
      : defNameClean;
    const moduleName = reResult ? reResult[1] : alternativeName;
    return { moduleName, def: this._definitions[defNameClean] };
  }

  public constructor(
    schema: JSONSchema7,
    entry: string,
    options: options = {},
  ) {
    this._entry = entry;
    this._schema = schema;
    this._definitions =
      this._schema.definitions != null ? this._schema.definitions : [];
    this._options = options;
  }

  public getEntryParser() {
    const entry = this._definitions[this._entry];
    const parser = getParser(this, entry, this._entry);

    if (parser) {
      return new parser(this, this._entry, entry);
    }
    return false;
  }
}

export default SchemaParser;
