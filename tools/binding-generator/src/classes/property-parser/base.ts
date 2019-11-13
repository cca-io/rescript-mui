import Property from './../property';
import * as Plugins from './plugins';
import PluginBase from './plugins/base';
import { reservedNames } from '../../helpers/generate-reason-name';

class PropertyParserBase {
	protected _property: Property;
	protected _plugins: PluginBase[] = [];

	protected _reasonType: string = '';
	protected _jsType: string = '';
	protected _wrapJs: (safeName: string) => string = (safeName: string) => safeName;
	protected _module: string = '';
	protected _valid: boolean = true;

	protected _emitToComponent: boolean | 'moduleOnly';

	constructor(property: Property, emitToComponent: boolean | 'moduleOnly' = true) {
		this._property = property;
		this._emitToComponent = emitToComponent;

		this._plugins = Object.keys(Plugins).map((pluginKey) => new Plugins[pluginKey](this));
	}

	// Getters
	public get property() {
		return this._property;
	}

	public get component() {
		return this._property.component;
	}

	public get required() {
		return this._property.signature.required;
	}

	public get reasonType() {
		return this._reasonType;
	}

	public get valid() {
		return this._valid;
	}

	public get jsType() {
		return this._jsType;
	}

	public get wrapJs() {
		return this._wrapJs;
	}

	public set wrapJs(newValue) {
		this._wrapJs = newValue;
	}

	public set jsType(newValue) {
		this._jsType = newValue;
	}

	public set reasonType(newValue) {
		this._reasonType = newValue;
	}

	public set required(newValue) {
		this._property.signature.required = newValue;
	}

	// Parse functions
	public parse() {
		this.runPlugins('beforeParse');
		this.executeParse();
		this.runPlugins('beforeWrite');
		this.writeToComponent();
	}

	public executeParse() {}

	private runPlugins(when: 'beforeParse' | 'beforeWrite') {
		if (when === 'beforeParse') {
			this._plugins.forEach((plugin) => plugin.beforeParse());
		} else {
			this._plugins.forEach((plugin) => plugin.beforeWrite());
		}
	}

	protected writeToComponent() {
		if (this._emitToComponent !== false) {
			if (this._valid && this._reasonType) {
				let makeName = this.property.safeName;
				let index;
				if ((index = reservedNames.indexOf(makeName.replace('_', ''))) > -1) {
					makeName = `_${reservedNames[index]}`;
				}
				let Make = `~${this.property.safeName}: ${this._reasonType},`;
				let MakeProps = `~${makeName}: ${this._jsType ? this._jsType : this._reasonType},`;
				let WrapJs = `~${makeName}=${this._wrapJs(this.property.safeName)},`;

				// Optional
				if (!this.property.signature.required) {
					Make = `~${this.property.safeName}: option(${this._reasonType})=?,`;
					MakeProps = `${MakeProps.replace(',', '=?')},`;
					WrapJs = `${WrapJs.replace('=', '=?')}`;
				}

				if (this._emitToComponent !== 'moduleOnly') {
					this.component.addToSection('Make', Make);
					if (this.property.signature.reasonOnly !== true) {
						this.component.addToSection('MakeProps', MakeProps);
						this.component.addToSection('WrapJs', WrapJs);
					}
				}
				this.component.addToSection('Module', this._module);
			}
		}
	}
}

export default PropertyParserBase;
