[@bs.deriving jsConverter]
type color = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "default"] `Default
];

[@bs.deriving jsConverter]
type position = [
  | [@bs.as "fixed"] `Fixed
  | [@bs.as "absolute"] `Absolute
  | [@bs.as "sticky"] `Sticky
  | [@bs.as "static"] `Static
];

module Classes = {
  type classesType =
    | Root(string)
    | PositionFixed(string)
    | PositionAbsolute(string)
    | PositionSticky(string)
    | PositionStatic(string)
    | ColorDefault(string)
    | ColorPrimary(string)
    | ColorSecondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | PositionFixed(_) => "positionFixed"
    | PositionAbsolute(_) => "positionAbsolute"
    | PositionSticky(_) => "positionSticky"
    | PositionStatic(_) => "positionStatic"
    | ColorDefault(_) => "colorDefault"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | PositionFixed(className)
           | PositionAbsolute(className)
           | PositionSticky(className)
           | PositionStatic(className)
           | ColorDefault(className)
           | ColorPrimary(className)
           | ColorSecondary(className) =>
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
    ~position: string=?,
    ~component: 'union_r70e=?,
    ~elevation: 'number_i=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/AppBar/AppBar"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~position: option(position)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
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
        ~position=?position |. Belt.Option.map(v => positionToJs(v)),
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~elevation=?
          elevation |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~square?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
