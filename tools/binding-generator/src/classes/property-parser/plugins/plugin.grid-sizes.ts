import PluginBase from './base';
import { isEnum } from '../../../helpers/identify-prop-type';

class PluginGridSizes extends PluginBase {
    private isGridSizeProp() {
        if (this._parser.property.component.name !== 'Grid') {
            return false;
        }
        if (['lg', 'md', 'sm', 'xl', 'xs'].indexOf(this._parser.property.name) == -1) {
            return false;
        }

        return true;
    }

    public beforeParse() {
        if (!this.isGridSizeProp()) {
            return;
        }

        if (this._parser.property.signature.type != null && isEnum(this._parser.property.signature.type)) {
            this._parser.property.signature.type.value = this._parser.property.signature.type.value.filter(item => item.value !== 'false' && item.value !== 'true' && item.value !== '\'auto\'');
        }
    }

    public beforeWrite() {
        if (!this.isGridSizeProp()) {
            return;
        }

        const wrapResult = this._parser.wrapJs(this._parser.property.safeName);
        this._parser.wrapJs = safeName => `${safeName}Auto
        ->(Belt.Option.map(v => v->MaterialUi_Helpers.toJsUnsafe))
        ->Belt.Option.getWithDefault(${wrapResult})`;
    }
}

export default PluginGridSizes;