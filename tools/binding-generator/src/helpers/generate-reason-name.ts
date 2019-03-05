export const capitalize = (str: string) => str.replace(/\b\w/g, l => l.toUpperCase());
export const uncapitalize = (str: string) => str.replace(/\b\w/g, l => l.toLowerCase());

export const isNumeric = (obj: any) => {
    const realStringObj = obj && obj.toString();
    return typeof obj !== 'object' && (realStringObj - parseFloat(realStringObj) + 1) >= 0;
};

export const reservedNames = ['type', 'open', 'in', 'ref', 'to', 'for'];

const GenerateReasonName = (str: string, toUpper: boolean = true) => {
    if (toUpper) {
        str = capitalize(str);
    }
    else {
        const firstLetter = str.substr(0, 1);
        if (firstLetter === firstLetter.toUpperCase()) {
            str = `_${str}`;
        }
    }

    while (str.indexOf('-') > -1) {
        str = str.replace('-', '_');
    }
    if (reservedNames.indexOf(str) > -1) {
        str = `${str}_`;
    }

    if (isNumeric(str)) {
        str = `V${str}`;
    }

    return str;
};

export default GenerateReasonName;