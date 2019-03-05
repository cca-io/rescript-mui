declare module '@jsiebern/json-schema-parser' {
    interface expDef {
        modules: any,
        string: string,
        refmt: string,
    }

    type options = {
        replaceRefs?: {
            re: RegExp,
            replaceWith: string,
        }[],
    };

    let exp: (jsonString: string, extractType: string, options: options) => expDef;

    export default exp;
}