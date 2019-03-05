declare interface PropSignature {
    type?: PropType,
    raw?: string,
    required: boolean,
    reasonOnly?: boolean,
    description: string | '@ignore',
    defaultValue: {
        value: string,
        computed: boolean,
    },
}

declare interface ComponentSignature {
    description: string,
    displayName: string,
    name: string,
    styles: {
        classes: string[],
        name: null | string,
    },
    filename: string,
    importPath: string,
    importName?: string,
    inheritsFrom: string,
    props: {
        [propName: string]: PropSignature
    },
    basename?: string,
}
