import Component from './component';
import GenerateReasonName from './../helpers/generate-reason-name';
import * as Console from './../helpers/console';
import GetPropertyParser from './property-parser';

class Property {
  // Component Reference
  private _component: Component;

  // Raw Prop Values
  readonly _signature: PropSignature;
  readonly _name: string;
  readonly _description: string;

  constructor(
    name: string,
    propSignature: PropSignature,
    componentReference: Component,
    autoParse: boolean = true,
  ) {
    this._component = componentReference;
    this._signature = propSignature;
    this._name = name;
    this._description = propSignature.description;
    if (autoParse) {
      this.parse();
    }
  }

  // Getters
  public get name() {
    return this._name;
  }

  public get safeName() {
    return GenerateReasonName(this.name, false);
  }

  public get component() {
    return this._component;
  }

  public get signature() {
    return this._signature;
  }

  public get description() {
    return this._description;
  }

  public set component(componentReference: Component) {
    this._component = componentReference;
  }

  public parse() {
    if (this._signature.type != null) {
      const Parser = GetPropertyParser(
        this._signature.type,
        this._signature.flowType,
      );
      if (Parser) {
        const parser = new Parser(this);
        parser.parse();
      } else {
        Console.error(
          `Property.parse: Could not find parser for Property ${Console.colors.green}${this.component.name}/${this._name}/${this._signature.type.name}${Console.colors.reset}`,
        );
      }
    } else {
      Console.error(
        `Property.parse: Missing type definition for Property ${Console.colors.green}${this.component.name}/${this._name}${Console.colors.reset}`,
      );
    }
  }
}

export default Property;
