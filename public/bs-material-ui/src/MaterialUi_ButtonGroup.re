[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "vertical"] `Vertical
  | [@bs.as "horizontal"] `Horizontal
];

[@bs.deriving jsConverter]
type size = [
  | [@bs.as "small"] `Small
  | [@bs.as "medium"] `Medium
  | [@bs.as "large"] `Large
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "text"] `Text
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "contained"] `Contained
];

module Classes = {
  type classesType =
    | Root(string)
    | Contained(string)
    | Disabled(string)
    | FullWidth(string)
    | Vertical(string)
    | Grouped(string)
    | GroupedHorizontal(string)
    | GroupedVertical(string)
    | GroupedText(string)
    | GroupedTextHorizontal(string)
    | GroupedTextVertical(string)
    | GroupedTextPrimary(string)
    | GroupedTextSecondary(string)
    | GroupedOutlined(string)
    | GroupedOutlinedHorizontal(string)
    | GroupedOutlinedVertical(string)
    | GroupedOutlinedPrimary(string)
    | GroupedOutlinedSecondary(string)
    | GroupedContained(string)
    | GroupedContainedHorizontal(string)
    | GroupedContainedVertical(string)
    | GroupedContainedPrimary(string)
    | GroupedContainedSecondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Contained(_) => "contained"
    | Disabled(_) => "disabled"
    | FullWidth(_) => "fullWidth"
    | Vertical(_) => "vertical"
    | Grouped(_) => "grouped"
    | GroupedHorizontal(_) => "groupedHorizontal"
    | GroupedVertical(_) => "groupedVertical"
    | GroupedText(_) => "groupedText"
    | GroupedTextHorizontal(_) => "groupedTextHorizontal"
    | GroupedTextVertical(_) => "groupedTextVertical"
    | GroupedTextPrimary(_) => "groupedTextPrimary"
    | GroupedTextSecondary(_) => "groupedTextSecondary"
    | GroupedOutlined(_) => "groupedOutlined"
    | GroupedOutlinedHorizontal(_) => "groupedOutlinedHorizontal"
    | GroupedOutlinedVertical(_) => "groupedOutlinedVertical"
    | GroupedOutlinedPrimary(_) => "groupedOutlinedPrimary"
    | GroupedOutlinedSecondary(_) => "groupedOutlinedSecondary"
    | GroupedContained(_) => "groupedContained"
    | GroupedContainedHorizontal(_) => "groupedContainedHorizontal"
    | GroupedContainedVertical(_) => "groupedContainedVertical"
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
                         | Disabled(className)
                         | FullWidth(className)
                         | Vertical(className)
                         | Grouped(className)
                         | GroupedHorizontal(className)
                         | GroupedVertical(className)
                         | GroupedText(className)
                         | GroupedTextHorizontal(className)
                         | GroupedTextVertical(className)
                         | GroupedTextPrimary(className)
                         | GroupedTextSecondary(className)
                         | GroupedOutlined(className)
                         | GroupedOutlinedHorizontal(className)
                         | GroupedOutlinedVertical(className)
                         | GroupedOutlinedPrimary(className)
                         | GroupedOutlinedSecondary(className)
                         | GroupedContained(className)
                         | GroupedContainedHorizontal(className)
                         | GroupedContainedVertical(className)
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
    ~component: 'union_rrt9=?,
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~fullWidth: bool=?,
    ~orientation: string=?,
    ~size: string=?,
    ~variant: string=?,
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
      ~disabled: option(bool)=?,
      ~disableFocusRipple: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~orientation: option(orientation)=?,
      ~size: option(size)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
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
    ~disabled?,
    ~disableFocusRipple?,
    ~disableRipple?,
    ~fullWidth?,
    ~orientation=?orientation->(Belt.Option.map(v => orientationToJs(v))),
    ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ButtonGroup";
