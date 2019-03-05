import BaseParser from './_base';

class StringParser extends BaseParser {
    public parse(): void {

    }
    public getReasonType(): string {
        return 'string';
    }

    public render() {
        return '';
    }
}

export default StringParser;