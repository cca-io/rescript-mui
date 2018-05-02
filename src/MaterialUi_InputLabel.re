[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense];

module Classes = {
  type classesType =
    | Root(string)
    | FormControl(string)
    | MarginDense(string)
    | Shrink(string)
    | Animated(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | FormControl(_) => "formControl"
    | MarginDense(_) => "marginDense"
    | Shrink(_) => "shrink"
    | Animated(_) => "animated";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | FormControl(className)
             | MarginDense(className)
             | Shrink(className)
             | Animated(className) =>
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
    ~disableAnimation: bool=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~focused: bool=?,
    ~_FormLabelClasses: Js.t({..})=?,
    ~margin: string=?,
    ~required: bool=?,
    ~shrink: bool=?,
    ~component: 'union_rxsl=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Input/InputLabel"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~disableAnimation: option(bool)=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~focused: option(bool)=?,
      ~_FormLabelClasses: option(Js.t({..}))=?,
      ~margin: option(margin)=?,
      ~required: option(bool)=?,
      ~shrink: option(bool)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~disableAnimation?,
        ~disabled?,
        ~error?,
        ~focused?,
        ~_FormLabelClasses?,
        ~margin=?Js.Option.map((. v) => marginToJs(v), margin),
        ~required?,
        ~shrink?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
