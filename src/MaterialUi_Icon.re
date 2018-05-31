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
    |> StdLabels.List.fold_left(
         ~f=
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
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~color: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Icon/Icon"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~color=?Js.Option.map((. v) => colorToJs(v), color),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
