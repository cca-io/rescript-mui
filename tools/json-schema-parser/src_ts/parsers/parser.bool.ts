import BaseParser from './_base';

class BoolParser extends BaseParser {
    public parse(): void {

    }
    public getReasonType(): string {
        return 'bool';
    }

    public render() {
        return '';
    }
}

export default BoolParser;