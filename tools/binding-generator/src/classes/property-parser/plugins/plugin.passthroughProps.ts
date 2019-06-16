import PluginBase from './base';

class PluginGridSizes extends PluginBase {
	private applyTo = {
		Step: [ 'orientation' ],
		Tab: [ 'textColor' ],
	};

	private isPassThroughProp() {
		const keys = Object.keys(this.applyTo);
		for (let key of keys) {
			if (this._parser.property.component.name.includes(key)) {
				if (this.applyTo[key].indexOf(this._parser.property.name) > -1) {
					return true;
				}
			}
		}
		return false;
	}

	public beforeParse() {
		if (!this.isPassThroughProp()) {
			return;
		}
	}

	public beforeWrite() {
		if (!this.isPassThroughProp()) {
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
