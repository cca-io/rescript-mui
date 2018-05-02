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
    | ColorPrimary(string)
    | ColorSecondary(string)
    | Svg(string)
    | SvgIndeterminate(string)
    | Circle(string)
    | CircleIndeterminate(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Svg(_) => "svg"
    | SvgIndeterminate(_) => "svgIndeterminate"
    | Circle(_) => "circle"
    | CircleIndeterminate(_) => "circleIndeterminate";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | ColorPrimary(className)
             | ColorSecondary(className)
             | Svg(className)
             | SvgIndeterminate(className)
             | Circle(className)
             | CircleIndeterminate(className) =>
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
    ~max: 'number_7=?,
    ~min: 'number_y=?,
    ~size: 'union_rl2z=?,
    ~thickness: 'number_j=?,
    ~value: 'number_k=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Progress/CircularProgress"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~max: option([ | `Int(int) | `Float(float)])=?,
      ~min: option([ | `Int(int) | `Float(float)])=?,
      ~size: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~thickness: option([ | `Int(int) | `Float(float)])=?,
      ~value: option([ | `Int(int) | `Float(float)])=?,
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
        ~color=?Js.Option.map((. v) => colorToJs(v), color),
        ~max=?
          Js.Option.map((. v) => MaterialUi_Helpers.unwrapValue(v), max),
        ~min=?
          Js.Option.map((. v) => MaterialUi_Helpers.unwrapValue(v), min),
        ~size=?
          Js.Option.map((. v) => MaterialUi_Helpers.unwrapValue(v), size),
        ~thickness=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            thickness,
          ),
        ~value=?
          Js.Option.map((. v) => MaterialUi_Helpers.unwrapValue(v), value),
        ~variant=?Js.Option.map((. v) => variantToJs(v), variant),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
