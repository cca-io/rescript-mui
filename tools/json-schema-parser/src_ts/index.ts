// @ts-ignore
import { JSONSchema7 } from 'json-schema';
import SchemaParser, { options } from './parsers/schema';
import { generateTypeName } from './helpers';

type onError = (e: any, code: string) => void;
export default function (
  jsonString: string,
  extractType: string,
  options: options,
  onError: onError | null = null,
) {
  const testData: JSONSchema7 = JSON.parse(jsonString);

  const parser = new SchemaParser(testData, extractType, options);
  const e = parser.getEntryParser();
  if (e) {
    e.parse();

    let reason = Object.keys(parser.modules)
      .map((name) => {
        return parser.moduleParsers[name].render();
      })
      .join('\n');

    if (parser.records) {
      reason += `type t = ${generateTypeName(extractType)};`;
    }

    let refmt = '';
    try {
      refmt = reason;
    } catch (e) {
      if (onError) {
        onError(e, reason);
      }
    }

    return {
      modules: parser.moduleParsers,
      string: reason,
      refmt,
    };
  }

  return false;
}
