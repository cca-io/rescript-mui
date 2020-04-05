import PluginBase from './base';

class PluginChildren extends PluginBase {
  public beforeWrite() {
    if (this._parser.property.name === 'children') {
      this._parser.reasonType = `'children`;
      this._parser.jsType = `'children`;
      this._parser.wrapJs = (c) => c;
      this._parser.required = false;
    }
  }

  public beforeParse() {}
}

export default PluginChildren;
