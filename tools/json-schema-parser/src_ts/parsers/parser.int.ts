import BaseParser from './_base';

class IntParser extends BaseParser {
    public parse(): void {

    }
    public getReasonType(): string {
        return 'int';
    }

    public render() {
        return '';
    }
}

export default IntParser;