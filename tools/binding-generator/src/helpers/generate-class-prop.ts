import GenerateReasonName from './generate-reason-name';

const GenerateClassProp = (component: ComponentSignature) => {
  const classes = component.styles.classes;
  let toModule = '';
  let toMakeProps = '';
  let toMake = '';
  let toWrapJs = '';
  if (classes.length) {
    const classesTypeDefs = classes
      .map((c) => `| ${GenerateReasonName(c)}(string)`)
      .join('\n');
    const toString = classes
      .map((c) => `| ${GenerateReasonName(c)}(_) => "${c}"`)
      .join('\n');
    const toClassname = classes
      .map((c) => `| ${GenerateReasonName(c)}(className)`)
      .join('\n');
    toModule = `
                module Classes = {
                    type classesType = ${classesTypeDefs};
                    type t = list(classesType);
                    let to_string = (v) => ${toString}(v);
                    let to_obj = (listOfClasses) =>
                    listOfClasses->Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                ${toClassname} => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            `;
    toMakeProps = '~classes: Js.Dict.t<string>=?,~style: ReactDOMRe.Style.t=?,';
    toWrapJs =
      '~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?,';
    toMake =
      '~classes: option<Classes.t>=?,~style: option<ReactDOMRe.Style.t>=?,';
  }

  return {
    toModule,
    toMakeProps,
    toWrapJs,
    toMake,
  };
};

export default GenerateClassProp;
