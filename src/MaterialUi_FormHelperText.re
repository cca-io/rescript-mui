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
    |> StdLabels.List.fold_left(
         ~f=
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
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~component: 'union_rbdm=?,
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
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
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
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~disabled?,
        ~error?,
        ~margin=?Js.Option.map((. v) => marginToJs(v), margin),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
