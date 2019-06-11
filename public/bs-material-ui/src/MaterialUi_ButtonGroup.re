[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type size = [
  | [@bs.as "small"] `Small
  | [@bs.as "medium"] `Medium
  | [@bs.as "large"] `Large
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "contained"] `Contained
];

module Classes = {
  type classesType =
    | Root(string)
    | Contained(string)
    | FullWidth(string)
    | Grouped(string)
    | GroupedOutlined(string)
    | GroupedOutlinedPrimary(string)
    | GroupedOutlinedSecondary(string)
    | GroupedContained(string)
    | GroupedContainedPrimary(string)
    | GroupedContainedSecondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Contained(_) => "contained"
    | FullWidth(_) => "fullWidth"
    | Grouped(_) => "grouped"
    | GroupedOutlined(_) => "groupedOutlined"
    | GroupedOutlinedPrimary(_) => "groupedOutlinedPrimary"
    | GroupedOutlinedSecondary(_) => "groupedOutlinedSecondary"
    | GroupedContained(_) => "groupedContained"
    | GroupedContainedPrimary(_) => "groupedContainedPrimary"
    | GroupedContainedSecondary(_) => "groupedContainedSecondary";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Contained(className)
                         | FullWidth(className)
                         | Grouped(className)
                         | GroupedOutlined(className)
                         | GroupedOutlinedPrimary(className)
                         | GroupedOutlinedSecondary(className)
                         | GroupedContained(className)
                         | GroupedContainedPrimary(className)
                         | GroupedContainedSecondary(className) =>
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
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~fullWidth: bool=?,
    ~size: string=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "ButtonGroup";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~disabled: option(bool)=?,
      ~disableFocusRipple: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~size: option(size)=?,
      ~variant: option(variant)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~color=?color->(Belt.Option.map(v => colorToJs(v))),
      ~disabled?,
      ~disableFocusRipple?,
      ~disableRipple?,
      ~fullWidth?,
      ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
      ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
