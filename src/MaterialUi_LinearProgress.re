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
    | Buffer(string)
    | Query(string)
    | Dashed(string)
    | DashedColorPrimary(string)
    | DashedColorSecondary(string)
    | Bar(string)
    | BarColorPrimary(string)
    | BarColorSecondary(string)
    | Bar1Indeterminate(string)
    | Bar2Indeterminate(string)
    | Bar1Determinate(string)
    | Bar1Buffer(string)
    | Bar2Buffer(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Buffer(_) => "buffer"
    | Query(_) => "query"
    | Dashed(_) => "dashed"
    | DashedColorPrimary(_) => "dashedColorPrimary"
    | DashedColorSecondary(_) => "dashedColorSecondary"
    | Bar(_) => "bar"
    | BarColorPrimary(_) => "barColorPrimary"
    | BarColorSecondary(_) => "barColorSecondary"
    | Bar1Indeterminate(_) => "bar1Indeterminate"
    | Bar2Indeterminate(_) => "bar2Indeterminate"
    | Bar1Determinate(_) => "bar1Determinate"
    | Bar1Buffer(_) => "bar1Buffer"
    | Bar2Buffer(_) => "bar2Buffer";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | ColorPrimary(className)
           | ColorSecondary(className)
           | Buffer(className)
           | Query(className)
           | Dashed(className)
           | DashedColorPrimary(className)
           | DashedColorSecondary(className)
           | Bar(className)
           | BarColorPrimary(className)
           | BarColorSecondary(className)
           | Bar1Indeterminate(className)
           | Bar2Indeterminate(className)
           | Bar1Determinate(className)
           | Bar1Buffer(className)
           | Bar2Buffer(className) =>
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
    ~value: 'number_6=?,
    ~valueBuffer: 'number_h=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/LinearProgress/LinearProgress"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~value: option([ | `Int(int) | `Float(float)])=?,
      ~valueBuffer: option([ | `Int(int) | `Float(float)])=?,
      ~variant: option(variant)=?,
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
        ~value=?
          value |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~valueBuffer=?
          valueBuffer
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~variant=?variant |. Belt.Option.map(v => variantToJs(v)),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
