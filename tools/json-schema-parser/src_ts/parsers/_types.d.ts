declare interface modulePropertyDefinition {
    name: string;
    optional: boolean;
    reasonType: string;
}

declare interface moduleDefinition {
    name: string;
    isSubmoduleTo?: string;
    properties: modulePropertyDefinition[];
}