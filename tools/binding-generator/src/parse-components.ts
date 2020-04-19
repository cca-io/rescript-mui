import GetComponents from './helpers/get-components';
import ComponentFromJson from './helpers/component-from-json';
import Component from './classes/component';
import * as Console from './helpers/console';

type componentSignatures = {
  [name: string]: ComponentSignature;
};
const resolveInheritance = (
  componentSignatures: componentSignatures,
  signature: ComponentSignature,
) => {
  if (
    signature.inheritsFrom &&
    typeof componentSignatures[signature.inheritsFrom] !== 'undefined'
  ) {
    let mergeSignature = componentSignatures[signature.inheritsFrom];
    mergeSignature = resolveInheritance(componentSignatures, mergeSignature);
    const mergeProps = { ...mergeSignature.props };
    const props = { ...signature.props };
    let newProps = {};
    const propKeys = Object.keys(props);
    const filteredMergePropKeys = Object.keys(mergeProps).filter(
      (mergePropKey) => propKeys.indexOf(mergePropKey) === -1,
    );
    filteredMergePropKeys.forEach((mergePropKey) => {
      newProps[mergePropKey] = mergeProps[mergePropKey];
    });
    propKeys.forEach((propKey) => {
      newProps[propKey] = props[propKey];
    });
    return {
      ...signature,
      props: newProps,
    };
  }
  return signature;
};

export default (muiSrc: muiSrc) => {
  const rawComponents = GetComponents(muiSrc);
  const componentSignatures: componentSignatures = rawComponents.reduce(
    (prev, jsonString) => {
      const componentSignature = ComponentFromJson(jsonString);
      return {
        ...prev,
        [componentSignature.name]: componentSignature,
      };
    },
    {},
  );

  const components = Object.keys(componentSignatures).map((key) => {
    let componentSignature = componentSignatures[key];
    Console.info(
      `Parsing ${Console.colors.yellow}${
        componentSignature.name || componentSignature.displayName
      }${Console.colors.reset}`,
    );
    try {
      componentSignature = resolveInheritance(
        componentSignatures,
        componentSignature,
      );
      return new Component(componentSignature);
    } catch (e) {
      console.log(e);
      Console.error(e);
      process.exit();
    }
  });

  return components.reduce((prev, component) => {
    if (component == null) {
      return prev;
    }
    Console.info(
      `Rendering ${Console.colors.yellow}${component.name}${Console.colors.reset}`,
    );
    return [
      ...prev,
      {
        name: component.name,
        src: component.render(),
      },
    ];
  }, []);
};
