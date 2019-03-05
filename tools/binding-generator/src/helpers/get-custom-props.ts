import CustomProps from './../custom-props';

const GetCustomProps = (componentName: string) => (typeof CustomProps[componentName] !== 'undefined') ? CustomProps[componentName] : {};

export default GetCustomProps;