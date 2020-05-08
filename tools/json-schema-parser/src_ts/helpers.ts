export const capitalize = (str: string) =>
  str.replace(/\b\w/g, (l) => l.toUpperCase());
export const uncapitalize = (str: string) =>
  str.replace(/\b\w/g, (l) => l.toLowerCase());
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
export const isNumeric = (obj: any) => {
  const realStringObj = obj && obj.toString();
  return (
    typeof obj !== 'object' &&
    realStringObj - parseFloat(realStringObj) + 1 >= 0
  );
};

export const generateModuleName = (name: string) => {
  name = name.replace(/@/g, '');
  if (isNumeric(name)) {
    name = `V${name}`;
  }
  return capitalize(name).replace(/-/gm, '');
};

export const generateAttributeName = (name: string) => {
  name = name.replace(/@/g, '');
  name = uncapitalize(name);

  name = name.replace(/-(.{1})/g, (g) => g[1].toUpperCase());

  const firstLetter = name.substr(0, 1);
  if (firstLetter === firstLetter.toUpperCase()) {
    name = `_${name}`;
  }

  if (reservedNames.indexOf(name) > -1) {
    name = `_${name}`;
  }

  if (isNumeric(name)) {
    name = `_${name}`;
  }

  return name;
};
