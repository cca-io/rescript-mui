import PluginBase from './base';

class PluginGridSizes extends PluginBase {
	private isOrientationProp() {
		if (!this._parser.property.component.name.includes('Step')) {
			return false;
		}
		if ([ 'orientation' ].indexOf(this._parser.property.name) == -1) {
			return false;
		}

		return true;
	}

	public beforeParse() {
		if (!this.isOrientationProp()) {
			return;
		}
	}

	public beforeWrite() {
		if (!this.isOrientationProp()) {
			return;
		}

		this._parser.wrapJs = (name) => `${name}->(
            Belt.Option.map(v =>
              switch (v->Obj.magic->Js.Json.classify) {
              | JSONString(str) => str
              | _ => ${name}ToJs(v)
              }
            )
          )`;
	}
}

export default PluginGridSizes;
