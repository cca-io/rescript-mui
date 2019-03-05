import PropertyParserBase from './../base';

abstract class PluginBase {
    protected _parser: PropertyParserBase;

    protected constructor(parser: PropertyParserBase) {
        this._parser = parser;
    }

    public abstract beforeParse(): void;
    public abstract beforeWrite(): void;
}

export default PluginBase;