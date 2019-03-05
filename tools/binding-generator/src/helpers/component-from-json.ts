const ComponentFromJson = (jsonString: string): ComponentSignature => {
    return JSON.parse(jsonString);
};

export default ComponentFromJson;