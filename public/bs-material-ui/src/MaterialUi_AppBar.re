[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "elevation"] `Elevation
  | [@bs.as "outlined"] `Outlined
];

[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "transparent"] `Transparent
];

[@bs.deriving jsConverter]
type position = [
  | [@bs.as "absolute"] `Absolute
  | [@bs.as "fixed"] `Fixed
  | [@bs.as "relative"] `Relative
  | [@bs.as "static"] `Static
  | [@bs.as "sticky"] `Sticky
];

module Classes = {
  type classesType =
    | Root(string)
    | PositionFixed(string)
    | PositionAbsolute(string)
    | PositionSticky(string)
    | PositionStatic(string)
    | PositionRelative(string)
    | ColorDefault(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | ColorInherit(string)
    | ColorTransparent(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | PositionFixed(_) => "positionFixed"
    | PositionAbsolute(_) => "positionAbsolute"
    | PositionSticky(_) => "positionSticky"
    | PositionStatic(_) => "positionStatic"
    | PositionRelative(_) => "positionRelative"
    | ColorDefault(_) => "colorDefault"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | ColorInherit(_) => "colorInherit"
    | ColorTransparent(_) => "colorTransparent";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | PositionFixed(className)
                         | PositionAbsolute(className)
                         | PositionSticky(className)
                         | PositionStatic(className)
                         | PositionRelative(className)
                         | ColorDefault(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | ColorInherit(className)
                         | ColorTransparent(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~component: 'union_r68p=?,
    ~elevation: 'number_s=?,
    ~square: bool=?,
    ~variant: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~position: string=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~variant: option(variant)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~position: option(position)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~square?,
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~children?,
    ~className?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~position=?position->Belt.Option.map(v => positionToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "AppBar";
