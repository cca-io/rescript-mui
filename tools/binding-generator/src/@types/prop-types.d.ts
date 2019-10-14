interface PropType$Primitive {
	name:
		| 'string'
		| 'number'
		| 'boolean'
		| 'bool'
		| 'int'
		| 'float'
		| 'any'
		| 'void'
		| 'Object'
		| 'String'
		| 'node'
		| 'object'
		| 'element'
		| 'any'
		| 'array'
		| 'Element'
		| 'element'
		| 'Element<any>'
		| 'Function'
		| 'Node'
		| 'ComponentType<object>';
}

interface PropType$Custom {
	name: 'custom';
	raw?: string;
	reasonType: string;
	jsType?: string;
	wrapJs?: (name: string) => string;
}

interface PropType$Literal {
	name: 'literal';
	value: string;
}

interface PropType$Func {
	name: 'func';
}

interface PropType$ObjectSignature {
	name: 'signature';
	type: 'object';
	raw: string;
	signature: {
		properties: {
			[key: string]: PropType;
		};
	};
}

interface PropType$FunctionSignature {
	name: 'signature';
	type: 'function';
	raw: string;
	signature: {
		arguments: {
			name: string;
			type: PropType;
			required?: boolean;
		}[];
		return: PropType;
	};
}

interface PropType$Intersect {
	name: 'intersect';
	raw: string;
	elements: PropType[];
}

interface PropType$Union {
	name: 'union';
	value?: PropType[];
	elements?: PropType[];
}

interface PropType$Enum {
	name: 'enum';
	value: {
		value: string;
		computed: boolean;
	}[];
}

interface PropType$Shape {
	name: 'shape' | 'shapeArgument';
	value: {
		[name: string]: PropType & { required: boolean };
	};
}

interface PropType$ArrayOf {
	name: 'arrayOf';
	value: PropType;
}

interface PropType$Callback {
	name: 'func';
}

declare type PropTypeList =
	| 'Primitive'
	| 'Literal'
	| 'ObjectSignature'
	| 'FunctionSignature'
	| 'Intersect'
	| 'Union'
	| 'Enum'
	| 'Shape'
	| 'ArrayOf'
	| 'Callback';

declare type PropType =
	| PropType$Primitive
	| PropType$Literal
	| PropType$ObjectSignature
	| PropType$Intersect
	| PropType$Union
	| PropType$FunctionSignature
	| PropType$Enum
	| PropType$ArrayOf
	| PropType$Callback
	| PropType$Shape
	| PropType$Custom;
