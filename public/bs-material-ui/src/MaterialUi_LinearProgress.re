[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "determinate"] `Determinate
  | [@bs.as "indeterminate"] `Indeterminate
  | [@bs.as "buffer"] `Buffer
  | [@bs.as "query"] `Query
];

module Classes = {
  type classesType =
    | Root(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | Determinate(string)
    | Indeterminate(string)
    | Buffer(string)
    | Query(string)
    | Dashed(string)
    | DashedColorPrimary(string)
    | DashedColorSecondary(string)
    | Bar(string)
    | BarColorPrimary(string)
    | BarColorSecondary(string)
    | Bar1Indeterminate(string)
    | Bar1Determinate(string)
    | Bar1Buffer(string)
    | Bar2Indeterminate(string)
    | Bar2Buffer(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Determinate(_) => "determinate"
    | Indeterminate(_) => "indeterminate"
    | Buffer(_) => "buffer"
    | Query(_) => "query"
    | Dashed(_) => "dashed"
    | DashedColorPrimary(_) => "dashedColorPrimary"
    | DashedColorSecondary(_) => "dashedColorSecondary"
    | Bar(_) => "bar"
    | BarColorPrimary(_) => "barColorPrimary"
    | BarColorSecondary(_) => "barColorSecondary"
    | Bar1Indeterminate(_) => "bar1Indeterminate"
    | Bar1Determinate(_) => "bar1Determinate"
    | Bar1Buffer(_) => "bar1Buffer"
    | Bar2Indeterminate(_) => "bar2Indeterminate"
    | Bar2Buffer(_) => "bar2Buffer";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | Determinate(className)
                         | Indeterminate(className)
                         | Buffer(className)
                         | Query(className)
                         | Dashed(className)
                         | DashedColorPrimary(className)
                         | DashedColorSecondary(className)
                         | Bar(className)
                         | BarColorPrimary(className)
                         | BarColorSecondary(className)
                         | Bar1Indeterminate(className)
                         | Bar1Determinate(className)
                         | Bar1Buffer(className)
                         | Bar2Indeterminate(className)
                         | Bar2Buffer(className) =>
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
    ~value: 'number_b=?,
    ~valueBuffer: 'number_x=?,
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
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~value: option([ | `Int(int) | `Float(float)])=?,
      ~valueBuffer: option([ | `Int(int) | `Float(float)])=?,
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
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~valueBuffer=?
      valueBuffer->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "LinearProgress";
