// import * as Console from './../../helpers/console';
import Base from './base';
import * as Identify from './../../helpers/identify-prop-type';
import ResolveArgument from './resolve-argument';

const factory = (propertyType: PropType$ArrayOf) => {
  return class ArrayOfParser extends Base {
    private _propertyType: PropType$ArrayOf = propertyType;

    public executeParse() {
      const type = this._propertyType.value;

      let reasonType: false | string[] | string = false;

      if (
        Identify.isPrimitive(type) &&
        ['string', 'number', 'int', 'float'].indexOf(type.name) > -1
      ) {
        if (type.name === 'string') {
          reasonType = 'array(string)';
        } else if (type.name === 'int') {
          reasonType = 'array(int)';
        } else if (type.name === 'float') {
          reasonType = 'array(float)';
        } else if (type.name === 'number') {
          reasonType = 'array(MaterialUi_Types.Number.t)';
        }
      } else {
        const resolvedType = this.resolveType(type);
        if (resolvedType) {
          if (resolvedType.valid) {
            reasonType = `array(${resolvedType.reasonType})`;
          }
        }
      }

      if (typeof reasonType === 'string') {
        this._reasonType = reasonType;
      } else {
        this._reasonType = 'array(MaterialUi_Types.any)';
      }
    }

    private resolveType(type: PropType) {
      const argumentParser = ResolveArgument(
        this._property.safeName,
        true,
        type,
        this._property,
      );
      if (argumentParser) {
        // Ensure mixed enum in union
        if (argumentParser.constructor.name === 'EnumParser') {
          // @ts-ignore
          argumentParser.enumType = 'mixed';
        }
        return argumentParser;
      }

      return false;
    }
  };
};

export default factory;
