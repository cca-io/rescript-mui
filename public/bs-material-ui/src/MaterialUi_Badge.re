[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "error"] `Error
];

[@bs.deriving jsConverter]
type variant = [ | [@bs.as "standard"] `Standard | [@bs.as "dot"] `Dot];

module Classes = {
  type classesType =
    | Root(string)
    | Badge(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | ColorError(string)
    | Invisible(string)
    | Dot(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Badge(_) => "badge"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | ColorError(_) => "colorError"
    | Invisible(_) => "invisible"
    | Dot(_) => "dot";
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
                         | Invisible(className)
                         | Dot(className) =>
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
    ~badgeContent: React.element=?,
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~invisible: bool=?,
    ~max: 'number_9=?,
    ~showZero: bool=?,
    ~variant: string=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~badgeContent: option(React.element)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~invisible: option(bool)=?,
      ~max: option([ | `Int(int) | `Float(float)])=?,
      ~showZero: option(bool)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~badgeContent?,
    ~children?,
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~invisible?,
    ~max=?max->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~showZero?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Badge";
