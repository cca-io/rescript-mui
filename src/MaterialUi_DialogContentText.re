[@bs.deriving jsConverter]
type align = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "left"] `Left
  | [@bs.as "center"] `Center
  | [@bs.as "right"] `Right
  | [@bs.as "justify"] `Justify
];

[@bs.deriving jsConverter]
type color = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "textSecondary"] `TextSecondary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "error"] `Error
  | [@bs.as "default"] `Default
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "display4"] `Display4
  | [@bs.as "display3"] `Display3
  | [@bs.as "display2"] `Display2
  | [@bs.as "display1"] `Display1
  | [@bs.as "headline"] `Headline
  | [@bs.as "title"] `Title
  | [@bs.as "subheading"] `Subheading
  | [@bs.as "body2"] `Body2
  | [@bs.as "body1"] `Body1
  | [@bs.as "caption"] `Caption
  | [@bs.as "button"] `Button
];

module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className) =>
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
    ~align: string=?,
    ~color: string=?,
    ~component: 'union_rib1=?,
    ~gutterBottom: bool=?,
    ~headlineMapping: Js.t({..})=?,
    ~noWrap: bool=?,
    ~paragraph: bool=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Dialog/DialogContentText"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~align: option(align)=?,
      ~color: option(color)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~gutterBottom: option(bool)=?,
      ~headlineMapping: option(Js.t({..}))=?,
      ~noWrap: option(bool)=?,
      ~paragraph: option(bool)=?,
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
        ~align=?Js.Option.map((. v) => alignToJs(v), align),
        ~color=?Js.Option.map((. v) => colorToJs(v), color),
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~gutterBottom?,
        ~headlineMapping?,
        ~noWrap?,
        ~paragraph?,
        ~variant=?Js.Option.map((. v) => variantToJs(v), variant),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
