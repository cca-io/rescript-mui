[@bs.deriving jsConverter]
type color = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "action"] `Action
  | [@bs.as "error"] `Error
  | [@bs.as "disabled"] `Disabled
];

module Classes = {
  type classesType =
    | Root(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | ColorAction(string)
    | ColorError(string)
    | ColorDisabled(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | ColorAction(_) => "colorAction"
    | ColorError(_) => "colorError"
    | ColorDisabled(_) => "colorDisabled";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | ColorPrimary(className)
           | ColorSecondary(className)
           | ColorAction(className)
           | ColorError(className)
           | ColorDisabled(className) =>
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
    ~color: string=?,
    ~nativeColor: string=?,
    ~titleAccess: string=?,
    ~viewBox: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/SvgIcon/SvgIcon"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~nativeColor: option(string)=?,
      ~titleAccess: option(string)=?,
      ~viewBox: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~color=?color |. Belt.Option.map(v => colorToJs(v)),
        ~nativeColor?,
        ~titleAccess?,
        ~viewBox?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
