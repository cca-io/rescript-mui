[@bs.deriving jsConverter]
type horizontal = [ | [@bs.as "left"] `Left | [@bs.as "right"] `Right];

[@bs.deriving jsConverter]
type vertical = [ | [@bs.as "bottom"] `Bottom | [@bs.as "top"] `Top];

module AnchorOrigin = {
  [@bs.deriving abstract]
  type t = {
    horizontal,
    vertical,
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      unwrappedMap->(
                      Js.Dict.set(
                        "horizontal",
                        horizontalToJs(obj->horizontalGet)
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      unwrappedMap->(
                      Js.Dict.set(
                        "vertical",
                        verticalToJs(obj->verticalGet)
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      Some(unwrappedMap);
    | None => None
    };
  };
};

[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "error"] `Error
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type overlap = [
  | [@bs.as "circle"] `Circle
  | [@bs.as "rectangle"] `Rectangle
];

[@bs.deriving jsConverter]
type variant = [ | [@bs.as "dot"] `Dot | [@bs.as "standard"] `Standard];

module Classes = {
  type classesType =
    | Root(string)
    | Badge(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | ColorError(string)
    | Dot(string)
    | AnchorOriginTopRightRectangle(string)
    | AnchorOriginBottomRightRectangle(string)
    | AnchorOriginTopLeftRectangle(string)
    | AnchorOriginBottomLeftRectangle(string)
    | AnchorOriginTopRightCircle(string)
    | AnchorOriginBottomRightCircle(string)
    | AnchorOriginTopLeftCircle(string)
    | AnchorOriginBottomLeftCircle(string)
    | Invisible(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Badge(_) => "badge"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | ColorError(_) => "colorError"
    | Dot(_) => "dot"
    | AnchorOriginTopRightRectangle(_) => "anchorOriginTopRightRectangle"
    | AnchorOriginBottomRightRectangle(_) => "anchorOriginBottomRightRectangle"
    | AnchorOriginTopLeftRectangle(_) => "anchorOriginTopLeftRectangle"
    | AnchorOriginBottomLeftRectangle(_) => "anchorOriginBottomLeftRectangle"
    | AnchorOriginTopRightCircle(_) => "anchorOriginTopRightCircle"
    | AnchorOriginBottomRightCircle(_) => "anchorOriginBottomRightCircle"
    | AnchorOriginTopLeftCircle(_) => "anchorOriginTopLeftCircle"
    | AnchorOriginBottomLeftCircle(_) => "anchorOriginBottomLeftCircle"
    | Invisible(_) => "invisible";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Badge(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | ColorError(className)
                         | Dot(className)
                         | AnchorOriginTopRightRectangle(className)
                         | AnchorOriginBottomRightRectangle(className)
                         | AnchorOriginTopLeftRectangle(className)
                         | AnchorOriginBottomLeftRectangle(className)
                         | AnchorOriginTopRightCircle(className)
                         | AnchorOriginBottomRightCircle(className)
                         | AnchorOriginTopLeftCircle(className)
                         | AnchorOriginBottomLeftCircle(className)
                         | Invisible(className) =>
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
    ~anchorOrigin: 'any_rybk=?,
    ~badgeContent: React.element=?,
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_ry4c=?,
    ~invisible: bool=?,
    ~max: 'number_8=?,
    ~overlap: string=?,
    ~showZero: bool=?,
    ~variant: string=?,
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
      ~anchorOrigin: option(AnchorOrigin.t)=?,
      ~badgeContent: option(React.element)=?,
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
      ~invisible: option(bool)=?,
      ~max: option([ | `Int(int) | `Float(float)])=?,
      ~overlap: option(overlap)=?,
      ~showZero: option(bool)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~anchorOrigin=?AnchorOrigin.unwrap(anchorOrigin),
    ~badgeContent?,
    ~children?,
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~invisible?,
    ~max=?max->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~overlap=?overlap->(Belt.Option.map(v => overlapToJs(v))),
    ~showZero?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Badge";
