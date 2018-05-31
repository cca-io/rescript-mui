[@bs.deriving jsConverter]
type margin = [
  | [@bs.as "none"] `None
  | [@bs.as "dense"] `Dense
  | [@bs.as "normal"] `Normal
];

module Classes = {
  type classesType =
    | Root(string)
    | MarginNormal(string)
    | MarginDense(string)
    | FullWidth(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | MarginNormal(_) => "marginNormal"
    | MarginDense(_) => "marginDense"
    | FullWidth(_) => "fullWidth";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | MarginNormal(className)
             | MarginDense(className)
             | FullWidth(className) =>
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
    ~component: 'union_roqc=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~margin: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~required: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/FormControl/FormControl"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~margin: option(margin)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
      ~required: option(bool)=?,
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
        ~fullWidth?,
        ~margin=?Js.Option.map((. v) => marginToJs(v), margin),
        ~onBlur?,
        ~onFocus?,
        ~required?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
