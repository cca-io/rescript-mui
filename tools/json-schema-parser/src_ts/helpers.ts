export const capitalize = (str: string) =>
  str.replace(/\b\w/g, (l) => l.toUpperCase());
export const uncapitalize = (str: string) =>
  str.replace(/\b\w/g, (l) => l.toLowerCase());
export const reservedNames = [
  'type',
  'open',
  'in',
  'to',
  'for',
  'true',
  'inherits',
  'false',
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
    name = `${name}_`;
  }

  if (isNumeric(name)) {
    name = `V${name}`;
  }

  return name;
};
