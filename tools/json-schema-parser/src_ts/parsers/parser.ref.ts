import BaseParser from './_base';
import getParser from './_getParser';

import { JSONSchema7Definition } from 'json-schema';
import SchemaParser from './schema';
import { Parser } from './_base';

export const getReplacement = (schema: SchemaParser, def: JSONSchema7Definition) => {
	if (typeof def === 'boolean' || typeof def.$ref === 'undefined') {
		return null;
	}
	const refDef = schema.getDefinition(def.$ref);
	if (!refDef.def) {
		return null;
	}
	const replaceRefs = schema.getOptions().replaceRefs;
	if (typeof replaceRefs !== 'undefined') {
		const refKey = def.$ref;
		for (let i = 0; i < replaceRefs.length; i++) {
			const replaceRef = { ...replaceRefs[i] };
			if (replaceRef.re.test(refKey)) {
				return replaceRef.replaceWith;
			}
		}
	}

	return null;
};

class RefParser extends BaseParser {
	private parser: Parser | false = false;
	private replacement: string | null = null;

	public constructor(schema: SchemaParser, key: string, def: JSONSchema7Definition) {
		super(schema, key, def);
		if (typeof def === 'boolean' || typeof def.$ref === 'undefined') {
			return;
		}
		const refDef = schema.getDefinition(def.$ref, key);
		if (!refDef.def) {
			return;
		}
		this.replacement = getReplacement(schema, def);
		if (this.replacement) {
			return;
		}

		const parserClass = getParser(schema, refDef.def, key);
		if (!parserClass) {
			return;
		}

		this.parser = new parserClass(schema, refDef.moduleName, refDef.def);
	}

	public parse(): void {
		if (!this.parser) {
			return;
		}
		this.parser.parse();
	}
	public getReasonType(): string {
		if (this.replacement) {
			return this.replacement;
		}
		if (!this.parser) {
			return '__ERROR__';
		}

		return this.parser.getReasonType();
	}

	public render() {
		return '';
	}
}

export default RefParser;
