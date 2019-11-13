[@bs.deriving jsConverter]
type color = [
  | [@bs.as "action"] `Action
  | [@bs.as "disabled"] `Disabled
  | [@bs.as "error"] `Error
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type fontSize = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "large"] `Large
  | [@bs.as "small"] `Small
];

module Classes = {
  type classesType =
    | Root(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | ColorAction(string)
    | ColorError(string)
    | ColorDisabled(string)
    | FontSizeInherit(string)
    | FontSizeSmall(string)
    | FontSizeLarge(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | ColorAction(_) => "colorAction"
    | ColorError(_) => "colorError"
    | ColorDisabled(_) => "colorDisabled"
    | FontSizeInherit(_) => "fontSizeInherit"
    | FontSizeSmall(_) => "fontSizeSmall"
    | FontSizeLarge(_) => "fontSizeLarge";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | ColorAction(className)
                         | ColorError(className)
                         | ColorDisabled(className)
                         | FontSizeInherit(className)
                         | FontSizeSmall(className)
                         | FontSizeLarge(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_rzu8=?,
    ~fontSize: string=?,
    ~htmlColor: string=?,
    ~shapeRendering: string=?,
    ~titleAccess: string=?,
    ~viewBox: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~fontSize: option(fontSize)=?,
      ~htmlColor: option(string)=?,
      ~shapeRendering: option(string)=?,
      ~titleAccess: option(string)=?,
      ~viewBox: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~fontSize=?fontSize->(Belt.Option.map(v => fontSizeToJs(v))),
    ~htmlColor?,
    ~shapeRendering?,
    ~titleAccess?,
    ~viewBox?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "SvgIcon";
