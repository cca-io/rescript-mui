import * as Fs from 'fs';
import * as Path from 'path';
import * as rimraf from 'rimraf';

import outputDirectory from './output';
import * as Console from './helpers/console';
import GetComponents from './helpers/get-components';
import Component from './classes/component';
import RenderColors from './render-colors';
import RenderTheme from './render-theme';
import ComponentFromJson from './helpers/component-from-json';

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
    // const filteredPropKeys = propKeys.filter((propKey) => {
    //   const prop = props[propKey];
    //   if (prop.description !== '@ignore') {
    //     return true;
    //   }
    //   const mergeProp =
    //     typeof mergeProps[propKey] !== 'undefined' ? mergeProps[propKey] : null;
    //   if (!mergeProp) {
    //     return true;
    //   }
    //   if (mergeProp.description !== '@ignore') {
    //     return false;
    //   }
    //   return true;
    // });
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

const parseInit = () => {
  const rawComponents = GetComponents();
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

  // Write component files
  components.forEach((component) => {
    if (component == null) {
      return;
    }
    Console.info(
      `Rendering ${Console.colors.yellow}${component.name}${Console.colors.reset}`,
    );
    const rendered = component.render();
    Fs.writeFileSync(
      Path.join(outputDirectory, 'reason', `MaterialUi_${component.name}.re`),
      rendered,
    );
  });

  // Copy fixed modules
  const items = Fs.readdirSync(Path.join(__dirname, 'fixed-modules'));
  const itemsFiltered = items.filter(
    (item) =>
      item.lastIndexOf('.re') === item.length - 3 ||
      item.lastIndexOf('.js') === item.length - 3,
  );
  itemsFiltered.forEach((item) => {
    Fs.copyFileSync(
      Path.join(__dirname, 'fixed-modules', item),
      Path.join(outputDirectory, 'reason', item),
    );
  });

  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi_Theme.re'),
    RenderTheme.theme,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi_ThemeOptions.re'),
    RenderTheme.themeOptions,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi_Colors.re'),
    RenderColors.colorModule,
  );
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi_ThemeOptions.re'),
    RenderTheme.themeOptions,
  );

  // Write global file
  // ${itemsFiltered.map(item => `module ${item.replace('MaterialUi_', '').replace('.re', '')} = ${item.replace('.re', '')};`).join('\n')}
  Fs.writeFileSync(
    Path.join(outputDirectory, 'reason', 'MaterialUi.re'),
    `
        include MaterialUi_Types;

        ${components
          .map((component) =>
            component != null
              ? `module ${component.name} = MaterialUi_${component.name};`
              : '',
          )
          .join('\n')}
        
		    module Colors = MaterialUi_Colors;
        module type WithStylesSafeTemplate = MaterialUi_WithStyles.WithStylesSafeTemplate;
        module WithStylesSafe = MaterialUi_WithStyles.WithStylesSafe;
        module Core = MaterialUi_Core;
        module Theme = MaterialUi_Theme;
        module ThemeOptions = MaterialUi_ThemeOptions;
        module ThemeProvider = MaterialUi_ThemeProvider;
        module ThemeHelpers = MaterialUi_ThemeHelpers;
        module MuiThemeProvider = MaterialUi_ThemeProvider;
        module WithStyles = MaterialUi_WithStyles;
    `,
  );

  // Append create theme function
  const themePath = Path.join(outputDirectory, 'reason', 'MaterialUi_Theme.re');
  const themeContents = Fs.readFileSync(themePath);
  Fs.writeFileSync(
    themePath,
    `
        ${themeContents}

        [@bs.module "@material-ui/core/styles"] external create: MaterialUi_ThemeOptions.t => t = "createMuiTheme";
    `,
  );

  // Todo: Generate .rei files
};

if (Fs.existsSync(Path.join(outputDirectory, 'reason'))) {
  rimraf.sync(Path.join(outputDirectory, 'reason'));
}
const requiredFolders = ['reason'];
requiredFolders.forEach((folder) => {
  const path = Path.join(outputDirectory, folder);
  if (!Fs.existsSync(path)) {
    Fs.mkdirSync(path);
  }
});

parseInit();
