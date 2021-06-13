import * as Console from './../../helpers/console';
import { lowerFirst } from 'lodash';
import { convertUnionToEnum } from './helpers';
import generateReasonName from '../../helpers/generate-rescript-name';
import Base from './base';
import * as Identify from './../../helpers/identify-prop-type';
import ResolveArgument from './resolve-argument';

const factory = (propertyType: PropType$Union) => {
  return class UnionParser extends Base {
    private _propertyType: PropType$Union = propertyType;

    public executeParse() {
      const unionProps = this.resolveUnionProps();

      let defs: { [key: string]: string } = {};
      defs = unionProps.reduce((prev, unionProp) => {
        const type = unionProp.property.signature.type as PropType;

        if (type == null) {
          return prev;
        }
        if (Identify.isPrimitive(type) || Identify.isInstanceOf(type)) {
          const pType = unionProp.reasonType;
          switch (pType) {
            case 'string':
            case 'bool':
            case 'int':
              return { ...prev, [pType]: unionProp.reasonType };
            case 'MaterialUi_Types.any':
              return { ...prev, any: 'MaterialUi_Types.any' };
            case 'array<MaterialUi_Types.any>':
              return { ...prev, array: 'array<MaterialUi_Types.any>' };
            case 'MaterialUi_Types.Number.t':
              return { ...prev, int: 'int', float: 'float' };
            case 'Js.Dict.t<MaterialUi_Types.any>':
            case '{..}':
              return { ...prev, obj: unionProp.reasonType };
            case 'React.element':
            case 'React.element':
            case 'Element<any>':
            case 'element':
            case 'Node':
            case 'node':
            case 'Element':
            case 'ComponentType<object>':
              return { ...prev, element: 'React.element' };
            default:
              Console.error(
                `_union: Unhandled primitive type ${
                  Console.colors.red
                }${JSON.stringify(unionProp.property.signature)}${
                  Console.colors.yellow
                } in Union ${Console.colors.red}${this.property.name}`,
              );
          }
        } else if (
          Identify.isEnum(type) ||
          Identify.isShape(type) ||
          Identify.isArrayOf(type)
        ) {
          let key = generateReasonName(type.name, false);
          key =
            typeof prev[key] === 'undefined'
              ? key
              : lowerFirst(unionProp.moduleName);
          return {
            ...prev,
            [key]: unionProp.reasonType,
          };
        } else if (Identify.isFunc(type)) {
          if (this._property.name === 'component') {
            return { ...prev, callback: 'unit => React.element' };
          } else {
            return {
              ...prev,
              [lowerFirst(unionProp.moduleName)]: unionProp.reasonType,
            };
          }
        } else if (
          type.name == 'custom' &&
          type.raw != null &&
          type.raw == 'HTMLElementType'
        ) {
          let key = generateReasonName(type.name, false);
          return {
            ...prev,
            [key]: 'Dom.element',
          };
        } else {
          console.log(unionProp);
          Console.error(
            `_union: Unhandled complex type ${Console.colors.red}${Console.colors.yellow} in Union ${Console.colors.red}${this.property.name}`,
          );
        }

        return prev;
      }, defs);

      this._module = `
      module ${this.moduleName} = {
        type t;
        ${Object.entries(defs)
          .map(
            ([key, value]) => `external ${key}: (${value}) => t = "%identity"`,
          )
          .join('\n')}
      }
      `;

      this._reasonType = `${this.moduleName}.t`;
    }

    private extractEnum() {
      const extracted = convertUnionToEnum(this._propertyType);
      if (extracted.value.length) {
        return this.resolveType(extracted);
      }

      return false;
    }

    private resolveUnionProps(): Base[] {
      const unionProps =
        this._propertyType.value != null
          ? this._propertyType.value.reduce((arr, pType) => {
              // Do not include literals as they will be extracted into an enum
              if (pType.name === 'literal') {
                return arr;
              }
              const resolved = this.resolveType(pType);
              if (resolved) {
                return [...arr, resolved];
              }
              return arr;
            }, [])
          : [];
      const extractedEnum = this.extractEnum();
      if (extractedEnum) {
        unionProps.push(extractedEnum);
      }

      return unionProps;
    }

    private resolveType(type: PropType) {
      const argName = `${this.property.name}_${type.name}`;
      const argumentParser = ResolveArgument(
        argName,
        true,
        type,
        this._property,
      );
      if (argumentParser) {
        return argumentParser;
      }

      return false;
    }
  };
};

export default factory;
