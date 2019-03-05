declare interface PropType$Primitive {
    name: 'string' | 'number' | 'boolean' | 'bool' | 'int' | 'float' | 'any' | 'void' | 'Object' | 'String' | 'node' | 'object' | 'element' | 'any' | 'array' | 'Element' | 'ReactElement' | 'Element<any>' | 'Function' | 'Node' | 'ComponentType<object>'
}

declare interface PropType$Custom {
    name: 'custom',
    raw?: string,
    reasonType: string,
    jsType?: string,
    wrapJs?: (name: string) => string,
}

declare interface PropType$Literal {
    name: 'literal',
    value: string,
}

declare interface PropType$Func {
    name: 'func',
}

declare interface PropType$ObjectSignature {
    name: 'signature',
    type: 'object',
    raw: string,
    signature: {
        properties: {
            [key: string]: PropType,
        },
    },
}

declare interface PropType$FunctionSignature {
    name: 'signature',
    type: 'function',
    raw: string,
    signature: {
        arguments: {
            name: string,
            type: PropType,
            required?: boolean,
        }[],
        return: PropType
    },
}

declare interface PropType$Intersect {
    name: 'intersect',
    raw: string,
    elements: PropType[],
}

declare interface PropType$Union {
    name: 'union',
    value?: PropType[],
    elements?: PropType[],
}

declare interface PropType$Enum {
    name: 'enum',
    value: {
        value: string,
        computed: boolean,
    }[]
}

declare interface PropType$Shape {
    name: 'shape' | 'shapeArgument',
    value: {
        [name: string]: PropType & { required: boolean },
    }
}

declare interface PropType$ArrayOf {
    name: 'arrayOf',
    value: PropType,
}

declare interface PropType$Callback {
    name: 'func',
}

declare type PropTypeList = 'Primitive' | 'Literal' | 'ObjectSignature' | 'FunctionSignature' | 'Intersect' | 'Union' | 'Enum' | 'Shape' | 'ArrayOf' | 'Callback';

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
