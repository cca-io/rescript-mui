import BaseParser, { Parser } from './_base';

import ObjectParser from './parser.object';
import { getReplacement } from './parser.ref';

class AnyOfParser extends BaseParser {
  private objParser: Parser;

  public parse(): void {
    if (typeof this.def === 'boolean') {
      return;
    }
    if (!this.def.anyOf) {
      return;
    }

    if (
      this.def.anyOf[0]['$ref'] &&
      this.def.anyOf[0]['$ref'].includes('CSSProperties')
    ) {
      this.objParser = new (class extends ObjectParser {
        public getReasonType() {
          return 'ReactDOM.Style.t';
        }
      })(this.schema, this.key, {});
      return;
    }

    const anyOfObject = [...this.def.anyOf]
      .map((def) => {
        if (typeof def === 'boolean') {
          return def;
        } else if (def.$ref) {
          if (getReplacement(this.schema, def) != null) {
            return def;
          }
          return this.resolveRef(def.$ref).def;
        } else {
          return def;
        }
      })
      .filter((def) => {
        if (typeof def === 'boolean' || typeof def === 'undefined') {
          return false;
        }
        if (!def.type) {
          return false;
        }
        if (def.type !== 'object') {
          return false;
        }
        return true;
      })
      .reduce(
        (prev, def) => {
          if (
            typeof def === 'boolean' ||
            typeof def === 'undefined' ||
            !def.type ||
            def.type !== 'object' ||
            !def.properties
          ) {
            return prev;
          }
          return prev && typeof prev !== 'boolean'
            ? {
                properties: { ...prev.properties, ...def.properties },
                required: [
                  ...(prev.required ?? []),
                  ...(def.required ? def.required : []),
                ],
              }
            : {
                properties: { ...def.properties },
                required: [...(def.required ? def.required : [])],
              };
        },
        { properties: {}, required: [] },
      );

    if (!anyOfObject) {
      return;
    }

    this.objParser = new ObjectParser(this.schema, this.key, anyOfObject);
    this.objParser.parse();
  }
  public getReasonType(): string {
    if (!this.objParser) {
      return '__ERROR__';
    }

    return this.objParser.getReasonType();
  }

  private resolveRef = (ref: string) => {
    return this.schema.getDefinition(ref);
  };

  public render() {
    return '';
  }
}

export default AnyOfParser;
