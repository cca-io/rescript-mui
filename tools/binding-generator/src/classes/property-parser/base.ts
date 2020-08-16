import Property from './../property';
import * as Plugins from './plugins';
import PluginBase from './plugins/base';
import generateReasonName, {
  reservedNames,
} from '../../helpers/generate-reason-name';

class PropertyParserBase {
  protected _property: Property;
  protected _plugins: PluginBase[] = [];

  protected _reasonType: string = '';
  protected _module: string = '';
  protected _moduleName: string = '';
  protected _valid: boolean = true;

  protected _emitToComponent: boolean | 'moduleOnly';

  constructor(
    property: Property,
    emitToComponent: boolean | 'moduleOnly' = true,
  ) {
    this._property = property;
    this._emitToComponent = emitToComponent;
    this._moduleName = generateReasonName(property.name, true);

    this._plugins = Object.keys(Plugins).map(
      (pluginKey) => new Plugins[pluginKey](this),
    );
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

  public get module() {
    return this._module;
  }

  public get moduleName() {
    return this._moduleName;
  }

  public get valid() {
    return this._valid;
  }

  public set reasonType(newValue) {
    this._reasonType = newValue;
  }

  public set required(newValue) {
    this._property.signature.required = newValue;
  }

  // Parse functions
  public parse() {
    this._module = '';
    this._reasonType = '';
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
          makeName = `\"${reservedNames[index]}"`;
        }
        let Make = `~${this.property.safeName}: ${this._reasonType},`;

        // Optional
        if (!this.property.signature.required) {
          Make = `~${this.property.safeName}: option<${this._reasonType}>=?,`;
        }

        if (this._emitToComponent !== 'moduleOnly') {
          this.component.addToSection('Make', Make);
        }
        this.component.addToSection('Module', this._module);
      }
    }
  }
}

export default PropertyParserBase;
