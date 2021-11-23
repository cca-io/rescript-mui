import * as Console from './../../helpers/console';
import Base from './base';
import ResolveArgument from './resolve-argument';
import GenerateRescriptName from '../../helpers/generate-rescript-name';

const factory = (propertyType: PropType$FunctionSignature) => {
  return class FunctionParser extends Base {
    private _signature = propertyType.signature;

    public executeParse() {
      // Todo: Proxy Wrapper / Call Function for unpure (labelled function)
      let argString = '';
      if (this._signature.arguments.length) {
        const args = this.parseArguments();
        if (args.length) {
          const shouldLabel = args.reduce(
            (shouldLabel, arg) => (shouldLabel ? shouldLabel : !arg.required),
            false,
          );

          if (shouldLabel) {
            argString = `(${args
              .map(
                (arg) =>
                  `~${arg.name}: ${arg.type}${!arg.required ? '=?' : ''}`,
              )
              .join(', ')}, unit)`;
          } else {
            argString = `(${args.map((arg) => arg.type).join(', ')})`;
          }
        }
      }
      if (!argString) {
        argString = 'unit';
      }

      this._reasonType = `${argString} => ${this.parseReturn()}`;
    }

    private parseArguments() {
      const argumentSignatures = this._signature.arguments;
      const args: { name: string; type: string; required: boolean }[] = [];
      argumentSignatures.forEach((arg) => {
        const name = GenerateRescriptName(arg.name, false);

        if (arg.type.name === 'shape') {
          arg.type.name = 'shapeArgument';
        }
        const argumentParser = ResolveArgument(
          name,
          arg.required || true,
          arg.type,
          this._property,
        );
        if (argumentParser) {
          args.push({
            name,
            type: argumentParser.reasonType,
            required: arg.required || true,
          });
        }
      });
      return args;
    }

    private parseReturn() {
      const returnParser = ResolveArgument(
        `${this._property.name}Return`,
        true,
        this._signature.return,
        this._property,
      );
      if (returnParser) {
        if (returnParser.valid) {
          return returnParser.reasonType;
        } else {
          Console.error(
            `_function: Parser returned false for argument ${Console.colors.green}${this.property.component.name}/${this.property.name}/${this._property.name}Return/${this._signature.return.name}${Console.colors.reset}`,
          );
          return 'Any.t';
        }
      } else {
        return 'Any.t';
      }
    }
  };
};

export default factory;
