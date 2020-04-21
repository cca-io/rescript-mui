import * as Hash from 'object-hash';
import GetCustomProps from './../helpers/get-custom-props';

import Property from './property';

class Component {
  // ComponentSignature
  readonly _component: ComponentSignature;

  // Sections of the reason Component (properties can add to them as needed)
  private _sectionModule: { [hash: string]: string } = {};
  private _sectionMake: string[] = [];

  // Property List
  private _properties: Property[] = [];

  constructor(componentSignature: ComponentSignature) {
    this._component = componentSignature;
    // Add id prop
    if (typeof this._component.props['id'] === 'undefined') {
      this._component.props['id'] = {
        type: {
          name: 'string',
        },
        required: false,
        description: '@ignore',
        defaultValue: { computed: false, value: '' },
      };
    }
    // Add style prop
    this._component.props['style'] = {
      type: {
        name: 'custom',
        reasonType: 'ReactDOMRe.Style.t',
      },
      required: false,
      description: '@ignore',
      defaultValue: { computed: false, value: '' },
    };
    // Modify classes prop
    if (typeof this._component.props['classes'] !== 'undefined') {
      this._component.props['classes'] = {
        ...this._component.props['classes'],
        required: false,
      };
    }
    this.parse();
  }

  // Getters
  public get name() {
    return this._component.name || this._component.displayName;
  }

  public get properties() {
    return this._properties;
  }

  public get inheritsFrom() {
    return this._component.inheritsFrom;
  }

  private getSectionByKey(section: string) {
    switch (section) {
      case 'Make':
        return this._sectionMake;
      default:
        return false;
    }
  }

  public addToSection(section: 'Module' | 'Make', content: string) {
    if (section === 'Module') {
      this._sectionModule[Hash(content)] = content;
    } else {
      const addTo = this.getSectionByKey(section);
      if (addTo) {
        addTo.push(content);
      }
    }
  }

  private renderSection(section: 'Module' | 'Make') {
    if (section === 'Module') {
      return Object.keys(this._sectionModule)
        .map((key) => this._sectionModule[key])
        .join('\n');
    } else {
      const renderFrom = this.getSectionByKey(section);
      if (renderFrom && renderFrom.length) {
        return renderFrom.join('\n');
      }
    }
    return '';
  }

  private parse() {
    if (this._component.props != null) {
      const props = {
        ...this._component.props,
        ...GetCustomProps(this._component.name),
      };

      const propKeys = Object.keys(props);
      this._properties = propKeys.reduce(
        (arr, propKey) =>
          props != null
            ? [...arr, new Property(propKey, props[propKey], this)]
            : arr,
        [],
      );
    }
  }

  public render() {
    return `
            ${this.renderSection('Module')}

            [@react.component] [@bs.module "${
              this._component.importPath
            }"] external make : (${this.renderSection(
      'Make',
    )}) => React.element = "${this._component.importName || 'default'}";
        `;
  }
}

export default Component;
