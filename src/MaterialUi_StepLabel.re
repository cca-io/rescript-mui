[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

module Classes = {
  type classesType =
    | Root(string)
    | Horizontal(string)
    | Vertical(string)
    | Active(string)
    | Completed(string)
    | AlternativeLabel(string)
    | Error(string)
    | Disabled(string)
    | Label(string)
    | IconContainer(string)
    | LabelContainer(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | Active(_) => "active"
    | Completed(_) => "completed"
    | AlternativeLabel(_) => "alternativeLabel"
    | Error(_) => "error"
    | Disabled(_) => "disabled"
    | Label(_) => "label"
    | IconContainer(_) => "iconContainer"
    | LabelContainer(_) => "labelContainer";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Horizontal(className)
             | Vertical(className)
             | Active(className)
             | Completed(className)
             | AlternativeLabel(className)
             | Error(className)
             | Disabled(className)
             | Label(className)
             | IconContainer(className)
             | LabelContainer(className) =>
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
    ~disabled: bool=?,
    ~error: bool=?,
    ~icon: ReasonReact.reactElement=?,
    ~last: bool=?,
    ~optional: ReasonReact.reactElement=?,
    ~orientation: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Stepper/StepLabel"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~active: option(bool)=?,
      ~alternativeLabel: option(bool)=?,
      ~className: option(string)=?,
      ~completed: option(bool)=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~icon: option(ReasonReact.reactElement)=?,
      ~last: option(bool)=?,
      ~optional: option(ReasonReact.reactElement)=?,
      ~orientation: option(orientation)=?,
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
        ~disabled?,
        ~error?,
        ~icon?,
        ~last?,
        ~optional?,
        ~orientation=?
          Js.Option.map((. v) => orientationToJs(v), orientation),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
