export const capitalize = (str: string) =>
  str.replace(/\b\w/g, (l) => l.toUpperCase());
export const uncapitalize = (str: string) =>
  str.replace(/\b\w/g, (l) => l.toLowerCase());

export const isNumeric = (obj: any) => {
  const realStringObj = obj && obj.toString();
  return (
    typeof obj !== 'object' &&
    realStringObj - parseFloat(realStringObj) + 1 >= 0
  );
};

export const reservedNames = [
  'and',
  'as',
  'asr',
  'assert',
  'begin',
  'class',
  'constraint',
  'do',
  'done',
  'downto',
  'else',
  'end',
  'esfun',
  'exception',
  'external',
  'false',
  'for',
  'fun',
  'function',
  'functor',
  'if',
  'in',
  'include',
  'inherit',
  'initializer',
  'land',
  'lazy',
  'let',
  'lor',
  'lsl',
  'lsr',
  'lxor',
  'match',
  'method',
  'mod',
  'module',
  'mutable',
  'new',
  'nonrec',
  'object',
  'of',
  'open',
  'open!',
  'or',
  'pri',
  'private',
  'pub',
  'public',
  'rec',
  'sig',
  'struct',
  'switch',
  'then',
  'to',
  'true',
  'try',
  'type',
  'val',
  'virtual',
  'when',
  'while',
  'with',
];

const GenerateReasonName = (str: string, toUpper: boolean = true) => {
  // Already parsed
  if (str.substr(0, 2) === `\\"`) {
    return str;
  }
  if (toUpper) {
    str = capitalize(str);
  } else {
    const firstLetter = str.substr(0, 1);
    if (firstLetter === firstLetter.toUpperCase()) {
      return `\\"${str}"`;
    }
  }

  if (
    !toUpper &&
    (str.indexOf('-') > -1 ||
      str.indexOf('@') > -1 ||
      reservedNames.indexOf(str) > -1 ||
      isNumeric(str))
  ) {
    return `\\"${str}"`;
  }

  while (str.indexOf('-') > -1) {
    str = str.replace('-', '_');
  }
  while (str.indexOf('@') > -1) {
    str = str.replace('@', '');
  }
  if (reservedNames.indexOf(str) > -1) {
    str = `_${str}`;
  }

  if (isNumeric(str)) {
    str = `V${str}`;
  }

  return str;
};

export default GenerateReasonName;
