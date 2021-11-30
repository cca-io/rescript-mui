import PluginBase from './base';

class PluginChildren extends PluginBase {
  public beforeWrite() {
    if (this._parser.property.name === 'children') {
      this._parser.reasonType = `React.element`;
      this._parser.required = false;
    }
  }

  public beforeParse() {}
}

export default PluginChildren;
