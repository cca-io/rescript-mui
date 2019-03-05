import BaseParser from './_base';

class FloatParser extends BaseParser {
    public parse(): void {

    }
    public getReasonType(): string {
        return 'float';
    }

    public render() {
        return '';
    }
}

export default FloatParser;