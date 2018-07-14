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
    | AlternativeLabel(string)
    | Line(string)
    | LineHorizontal(string)
    | LineVertical(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | AlternativeLabel(_) => "alternativeLabel"
    | Line(_) => "line"
    | LineHorizontal(_) => "lineHorizontal"
    | LineVertical(_) => "lineVertical";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Horizontal(className)
           | Vertical(className)
           | AlternativeLabel(className)
           | Line(className)
           | LineHorizontal(className)
           | LineVertical(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~alternativeLabel: bool=?,
    ~className: string=?,
    ~orientation: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/StepConnector/StepConnector"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~alternativeLabel: option(bool)=?,
      ~className: option(string)=?,
      ~orientation: option(orientation)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~alternativeLabel?,
        ~className?,
        ~orientation=?orientation |. Belt.Option.map(v => orientationToJs(v)),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
