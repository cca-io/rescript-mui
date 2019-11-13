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
  | [@bs.as "text"] `Text
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "contained"] `Contained
];

module Classes = {
  type classesType =
    | Root(string)
    | Contained(string)
    | FullWidth(string)
    | Grouped(string)
    | GroupedText(string)
    | GroupedTextPrimary(string)
    | GroupedTextSecondary(string)
    | GroupedOutlined(string)
    | GroupedOutlinedPrimary(string)
    | GroupedOutlinedSecondary(string)
    | GroupedContained(string)
    | GroupedContainedPrimary(string)
    | GroupedContainedSecondary(string)
    | Disabled(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Contained(_) => "contained"
    | FullWidth(_) => "fullWidth"
    | Grouped(_) => "grouped"
    | GroupedText(_) => "groupedText"
    | GroupedTextPrimary(_) => "groupedTextPrimary"
    | GroupedTextSecondary(_) => "groupedTextSecondary"
    | GroupedOutlined(_) => "groupedOutlined"
    | GroupedOutlinedPrimary(_) => "groupedOutlinedPrimary"
    | GroupedOutlinedSecondary(_) => "groupedOutlinedSecondary"
    | GroupedContained(_) => "groupedContained"
    | GroupedContainedPrimary(_) => "groupedContainedPrimary"
    | GroupedContainedSecondary(_) => "groupedContainedSecondary"
    | Disabled(_) => "disabled";
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
                         | GroupedText(className)
                         | GroupedTextPrimary(className)
                         | GroupedTextSecondary(className)
                         | GroupedOutlined(className)
                         | GroupedOutlinedPrimary(className)
                         | GroupedOutlinedSecondary(className)
                         | GroupedContained(className)
                         | GroupedContainedPrimary(className)
                         | GroupedContainedSecondary(className)
                         | Disabled(className) =>
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
    ~component: 'union_rv0m=?,
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~fullWidth: bool=?,
    ~size: string=?,
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
      ~size: option(size)=?,
      ~variant: option(variant)=?,
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
    ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ButtonGroup";
