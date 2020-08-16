import * as Identify from './../../helpers/identify-prop-type';

let isInShape = false;
export const inShape = {
  is() {
    return isInShape;
  },
  enter() {
    isInShape = true;
  },
  exit() {
    isInShape = false;
  },
  set(is: boolean) {
    isInShape = is;
  },
};

export function generateRandom() {
  return `r${Math.random().toString(36).substr(2, 3)}`;
}

export function generateAny(ident: string = 'any') {
  return `'${ident}_${generateRandom()}`;
}

export function convertUnionToEnum(union: PropType$Union): PropType$Enum {
  const value: PropType$Enum['value'] = [];

  if (union.value != null) {
    union.value.forEach((unionProp) => {
      if (Identify.isLiteral(unionProp)) {
        value.push({
          computed: false,
          value: unionProp.value,
        });
      }
    });
  }

  return {
    name: 'enum',
    value,
  };
}
