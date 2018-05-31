[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

[@bs.deriving abstract]
type transitionDuration_shape = {
  enter: [ | `Int(int) | `Float(float)],
  exit: [ | `Int(int) | `Float(float)],
};

[@bs.deriving jsConverter]
type transitionDuration_enum = [ | [@bs.as "auto"] `Auto];

module Classes = {
  type classesType =
    | Root(string)
    | Last(string)
    | Transition(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Last(_) => "last"
    | Transition(_) => "transition";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Last(className)
             | Transition(className) =>
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
    ~active: bool=?,
    ~alternativeLabel: bool=?,
    ~className: string=?,
    ~completed: bool=?,
    ~last: bool=?,
    ~optional: bool=?,
    ~orientation: string=?,
    ~_TransitionComponent: 'genericCallback=?,
    ~transitionDuration: 'union_r6wk=?,
    ~_TransitionProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/StepContent/StepContent"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~active: option(bool)=?,
      ~alternativeLabel: option(bool)=?,
      ~className: option(string)=?,
      ~completed: option(bool)=?,
      ~last: option(bool)=?,
      ~optional: option(bool)=?,
      ~orientation: option(orientation)=?,
      ~_TransitionComponent: option('genericCallback)=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(transitionDuration_shape)
             | `Enum(transitionDuration_enum)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~active?,
        ~alternativeLabel?,
        ~className?,
        ~completed?,
        ~last?,
        ~optional?,
        ~orientation=?
          Js.Option.map((. v) => orientationToJs(v), orientation),
        ~_TransitionComponent?,
        ~transitionDuration=?
          Js.Option.map(
            (. v) =>
              switch (v) {
              | `Enum(v) =>
                MaterialUi_Helpers.unwrapValue(
                  `String(transitionDuration_enumToJs(v)),
                )
              | v => MaterialUi_Helpers.unwrapValue(v)
              },
            transitionDuration,
          ),
        ~_TransitionProps?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
