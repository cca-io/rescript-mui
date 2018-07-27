[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "error"] `Error
];

module Classes = {
  type classesType =
    | Root(string)
    | Badge(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | ColorError(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Badge(_) => "badge"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | ColorError(_) => "colorError";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Badge(className)
           | ColorPrimary(className)
           | ColorSecondary(className)
           | ColorError(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~badgeContent: ReasonReact.reactElement,
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_r9f6=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Badge/Badge"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~badgeContent: ReasonReact.reactElement,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
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
        ~badgeContent,
        ~className?,
        ~color=?color |. Belt.Option.map(v => colorToJs(v)),
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
