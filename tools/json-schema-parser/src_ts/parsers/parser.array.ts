import BaseParser from './_base';

import { Parser } from './_base';
import getParser from './_getParser';
import StringParser from './parser.string';

class ArrayParser extends BaseParser {
  private itemsParser: Parser;

  public parse(): void {
    if (typeof this.def === 'boolean') {
      return;
    }
    if (!this.def.items || typeof this.def.items === 'boolean') {
      return;
    }
    if (Array.isArray(this.def.items)) {
      // TODO: Can be many things
      this.itemsParser = new StringParser(this.schema, '', {
        type: 'string',
      });
      return;
    }

    const parser = getParser(this.schema, this.def.items, this.key);
    if (!parser) {
      return;
    }
    this.itemsParser = new parser(this.schema, this.key, this.def.items);
    if (!this.itemsParser) {
      return;
    }
    this.itemsParser.parse();
  }

  public getReasonType(): string {
    if (!this.itemsParser) {
      return '__ERROR__';
    }
    return `array<${this.itemsParser.getReasonType()}>`;
  }

  public render() {
    return '';
  }
}

export default ArrayParser;
