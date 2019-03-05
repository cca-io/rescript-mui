import PluginBase from './base';

class PluginThemeOptional extends PluginBase {
    public beforeWrite() {
        if (this._parser.property.name === 'theme' && this._parser.property.component.name !== 'MuiThemeProvider') {
            this._parser.property.signature.required = false;
        }
    }

    public beforeParse() {}
}

export default PluginThemeOptional;