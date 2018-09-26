[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "standard"] `Standard
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "filled"] `Filled
];

module Classes = {
  type classesType =
    | Root(string)
    | FormControl(string)
    | MarginDense(string)
    | Shrink(string)
    | Animated(string)
    | Filled(string)
    | Outlined(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | FormControl(_) => "formControl"
    | MarginDense(_) => "marginDense"
    | Shrink(_) => "shrink"
    | Animated(_) => "animated"
    | Filled(_) => "filled"
    | Outlined(_) => "outlined";
  let to_obj = listOfClasses =>
    listOfClasses
    ->(
        Belt.List.reduce(
          Js.Dict.empty(),
          (obj, classType) => {
            switch (classType) {
            | Root(className)
            | FormControl(className)
            | MarginDense(className)
            | Shrink(className)
            | Animated(className)
            | Filled(className)
            | Outlined(className) =>
              Js.Dict.set(obj, to_string(classType), className)
            };
            obj;
          },
        )
      );
};

[@bs.obj]
external makeProps:
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
    ~variant: string=?,
    ~component: 'union_r0eo=?,
    ~filled: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "InputLabel";
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
      ~variant: option(variant)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~filled: option(bool)=?,
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
        ~margin=?margin->(Belt.Option.map(v => marginToJs(v))),
        ~required?,
        ~shrink?,
        ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
        ~component=?
          component
          ->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~filled?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
