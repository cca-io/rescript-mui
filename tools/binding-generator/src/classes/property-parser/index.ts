import * as Identify from './../../helpers/identify-prop-type';

import { convertUnionToEnum } from './helpers';

import BaseParser from './base';
import PrimitiveFactory from './_primitive';
import FunctionFactory from './_function';
import ShapeFactory from './_shape';
import ShapeArgumentFactory from './_shapeArgument';
import ArrayOfFactory from './_arrayOf';
import UnionFactory from './_union';
import EnumFactory from './_enum';
import FuncFactory from './_func';
import CustomFactory from './_custom';

export default function (
  propType: PropType,
  flowType: PropSignature['flowType'] = undefined,
): false | typeof BaseParser {
  if (Identify.isPrimitive(propType)) {
    if (propType.name === 'object' && typeof flowType !== 'undefined') {
      return ShapeFactory({
        name: 'shape',
        value: flowType.elements.reduce(
          (prev, key) => ({
            ...prev,
            [key]: {
              name: 'string',
              required: false,
            },
          }),
          {},
        ),
      });
    }
    return PrimitiveFactory(propType);
  } else if (Identify.isInstanceOf(propType)) {
    return PrimitiveFactory({
      name: 'Node',
    });
  } else if (Identify.isFunctionSignature(propType)) {
    return FunctionFactory(propType);
  } else if (Identify.isShape(propType)) {
    return ShapeFactory(propType);
  } else if (Identify.isShapeArgument(propType)) {
    return ShapeArgumentFactory(propType);
  } else if (Identify.isArrayOf(propType)) {
    return ArrayOfFactory(propType);
  } else if (Identify.isUnion(propType) && Identify.isUnionEnum(propType)) {
    return EnumFactory(convertUnionToEnum(propType));
  } else if (Identify.isUnion(propType)) {
    return UnionFactory(propType);
  } else if (Identify.isEnum(propType)) {
    return EnumFactory(propType);
  } else if (Identify.isFunc(propType)) {
    return FuncFactory(propType);
  } else if (Identify.isCustom(propType)) {
    return CustomFactory(propType);
  } else {
    return false;
  }
}
