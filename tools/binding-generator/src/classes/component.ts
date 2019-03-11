import * as Hash from 'object-hash';
import ComponentFromJson from './../helpers/component-from-json';
import GetCustomProps from './../helpers/get-custom-props';
import GenerateClassProp from './../helpers/generate-class-prop';

import Property from './property';

class Component {
    // Statics
    static ignorePropNames = ['key', 'classes', 'style'];

    // ComponentSignature
    readonly _component: ComponentSignature;

    // Sections of the reason Component (properties can add to them as needed)
    private _sectionModule: { [hash: string]: string } = {};
    private _sectionMake: string[] = [];
    private _sectionMakeProps: string[] = [];
    private _sectionWrapJs: string[] = [];

    // Property List
    private _properties: Property[] = [];

    constructor(jsonString: string) {
        this._component = ComponentFromJson(jsonString);
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

    public mergeProperties(toMerge: Property[]) {
        const filtered = toMerge.filter(
            pi => this._properties.find(p => p.name === pi.name) == null,
        );
        filtered.forEach(prop => {
            prop.component = this;
            prop.parse();
        });
        this._properties = [...this._properties, ...filtered];
    }

    private getSectionByKey(section: string) {
        switch (section) {
            case 'Make':
                return this._sectionMake;
            case 'MakeProps':
                return this._sectionMakeProps;
            case 'WrapJs':
                return this._sectionWrapJs;
            default:
                return false;
        }
    }

    public addToSection(
        section: 'Module' | 'Make' | 'MakeProps' | 'WrapJs',
        content: string,
    ) {
        if (section === 'Module') {
            this._sectionModule[Hash(content)] = content;
        } else {
            const addTo = this.getSectionByKey(section);
            if (addTo) {
                addTo.push(content);
            }
        }
    }

    private renderSection(section: 'Module' | 'Make' | 'MakeProps' | 'WrapJs') {
        if (section === 'Module') {
            return Object.keys(this._sectionModule)
                .map(key => this._sectionModule[key])
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
            this._properties = propKeys
                .filter(
                    propKey =>
                        Component.ignorePropNames.indexOf(propKey) === -1,
                )
                .reduce(
                    (arr, propKey) =>
                        props != null
                            ? [
                                  ...arr,
                                  new Property(propKey, props[propKey], this),
                              ]
                            : arr,
                    [],
                );
        }
    }

    private injectClasses() {
        const classProp = GenerateClassProp(this._component);
        this.addToSection('Module', classProp.toModule);
        this.addToSection('Make', classProp.toMake);
        this.addToSection('MakeProps', classProp.toMakeProps);
        this.addToSection('WrapJs', classProp.toWrapJs);
    }

    public render() {
        this.injectClasses();
        const hasProps =
            this._component.props != null ||
            this._component.styles.classes.length > 0;

        return `
            ${this.renderSection('Module')}
            ${
                hasProps
                    ? `[@bs.obj] external makePropsMui : (${this.renderSection(
                          'MakeProps',
                      )} unit) => _ = "";`
                    : ''
            }

            [@bs.module "${
                this._component.importPath
            }"] external reactComponent : React.component('a) = "${this
            ._component.importName || 'default'}";

            [@react.component]
            let make = (
                ${this.renderSection('Make')}
            ) => React.createElement(
                reactComponent,
                ${
                    !hasProps
                        ? 'Js.Obj.empty()'
                        : `makePropsMui(${this.renderSection('WrapJs')} ())`
                }
            );
        `;
    }
}

export default Component;
