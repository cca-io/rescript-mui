[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense];

module Classes = {
  type classesType =
    | Root(string)
    | Error(string)
    | Disabled(string)
    | MarginDense(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Error(_) => "error"
    | Disabled(_) => "disabled"
    | MarginDense(_) => "marginDense";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Error(className)
           | Disabled(className)
           | MarginDense(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~component: 'union_r35w=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~margin: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/FormHelperText/FormHelperText"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~margin: option(margin)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~disabled?,
        ~error?,
        ~margin=?margin |. Belt.Option.map(v => marginToJs(v)),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
