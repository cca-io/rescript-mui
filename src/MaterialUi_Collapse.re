[@bs.deriving abstract]
type timeout_shape = {
  enter: [ | `Int(int) | `Float(float)],
  exit: [ | `Int(int) | `Float(float)],
};

[@bs.deriving jsConverter]
type timeout_enum = [ | [@bs.as "auto"] `Auto];

module Classes = {
  type classesType =
    | Container(string)
    | Entered(string)
    | Wrapper(string)
    | WrapperInner(string);
  type t = list(classesType);
  let to_string =
    fun
    | Container(_) => "container"
    | Entered(_) => "entered"
    | Wrapper(_) => "wrapper"
    | WrapperInner(_) => "wrapperInner";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Container(className)
             | Entered(className)
             | Wrapper(className)
             | WrapperInner(className) =>
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
    ~collapsedHeight: string=?,
    ~component: 'union_r7oj=?,
    ~in_: bool=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~theme: Js.t({..})=?,
    ~timeout: 'union_rxjd=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Collapse/Collapse"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~collapsedHeight: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~in_: option(bool)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEventRe.Synthetic.t => unit)=?,
      ~theme: option(Js.t({..}))=?,
      ~timeout:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(timeout_shape)
             | `Enum(timeout_enum)
           ],
         )=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~collapsedHeight?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~in_?,
        ~onEnter?,
        ~onEntered?,
        ~onEntering?,
        ~onExit?,
        ~onExiting?,
        ~theme?,
        ~timeout=?
          Js.Option.map(
            (. v) =>
              switch (v) {
              | `Enum(v) =>
                MaterialUi_Helpers.unwrapValue(`String(timeout_enumToJs(v)))
              | v => MaterialUi_Helpers.unwrapValue(v)
              },
            timeout,
          ),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
