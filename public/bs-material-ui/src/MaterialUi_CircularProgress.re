[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "inherit"] `Inherit
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "determinate"] `Determinate
  | [@bs.as "indeterminate"] `Indeterminate
  | [@bs.as "static"] `Static
];

module Classes = {
  type classesType =
    | Root(string)
    | Static(string)
    | Indeterminate(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | Svg(string)
    | Circle(string)
    | CircleStatic(string)
    | CircleIndeterminate(string)
    | CircleDisableShrink(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Static(_) => "static"
    | Indeterminate(_) => "indeterminate"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Svg(_) => "svg"
    | Circle(_) => "circle"
    | CircleStatic(_) => "circleStatic"
    | CircleIndeterminate(_) => "circleIndeterminate"
    | CircleDisableShrink(_) => "circleDisableShrink";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Static(className)
                         | Indeterminate(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | Svg(className)
                         | Circle(className)
                         | CircleStatic(className)
                         | CircleIndeterminate(className)
                         | CircleDisableShrink(className) =>
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
    ~className: string=?,
    ~color: string=?,
    ~size: 'union_r7kt=?,
    ~thickness: 'number_s=?,
    ~value: 'number_e=?,
    ~variant: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~size: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~thickness: option([ | `Int(int) | `Float(float)])=?,
      ~value: option([ | `Int(int) | `Float(float)])=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~size=?size->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~thickness=?
      thickness->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "CircularProgress";
