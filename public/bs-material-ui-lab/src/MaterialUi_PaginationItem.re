[@bs.deriving jsConverter]
type color = [
  | [@bs.as "standard"] `Standard
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type shape = [ | [@bs.as "round"] `Round | [@bs.as "rounded"] `Rounded];

[@bs.deriving jsConverter]
type size = [
  | [@bs.as "small"] `Small
  | [@bs.as "medium"] `Medium
  | [@bs.as "large"] `Large
];

[@bs.deriving jsConverter]
type type_ = [
  | [@bs.as "page"] `Page
  | [@bs.as "first"] `First
  | [@bs.as "last"] `Last
  | [@bs.as "next"] `Next
  | [@bs.as "previous"] `Previous
  | [@bs.as "start-ellipsis"] `Start_Ellipsis
  | [@bs.as "end-ellipsis"] `End_Ellipsis
];

[@bs.deriving jsConverter]
type variant = [ | [@bs.as "text"] `Text | [@bs.as "outlined"] `Outlined];

module Classes = {
  type classesType =
    | Root(string)
    | Page(string)
    | SizeSmall(string)
    | SizeLarge(string)
    | TextPrimary(string)
    | TextSecondary(string)
    | Outlined(string)
    | OutlinedPrimary(string)
    | OutlinedSecondary(string)
    | Rounded(string)
    | Ellipsis(string)
    | FocusVisible(string)
    | Disabled(string)
    | Selected(string)
    | Icon(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Page(_) => "page"
    | SizeSmall(_) => "sizeSmall"
    | SizeLarge(_) => "sizeLarge"
    | TextPrimary(_) => "textPrimary"
    | TextSecondary(_) => "textSecondary"
    | Outlined(_) => "outlined"
    | OutlinedPrimary(_) => "outlinedPrimary"
    | OutlinedSecondary(_) => "outlinedSecondary"
    | Rounded(_) => "rounded"
    | Ellipsis(_) => "ellipsis"
    | FocusVisible(_) => "focusVisible"
    | Disabled(_) => "disabled"
    | Selected(_) => "selected"
    | Icon(_) => "icon";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Page(className)
                         | SizeSmall(className)
                         | SizeLarge(className)
                         | TextPrimary(className)
                         | TextSecondary(className)
                         | Outlined(className)
                         | OutlinedPrimary(className)
                         | OutlinedSecondary(className)
                         | Rounded(className)
                         | Ellipsis(className)
                         | FocusVisible(className)
                         | Disabled(className)
                         | Selected(className)
                         | Icon(className) =>
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
    ~component: 'union_r42d=?,
    ~disabled: bool=?,
    ~page: 'number_x=?,
    ~selected: bool=?,
    ~shape: string=?,
    ~size: string=?,
    ~_type: string=?,
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
      ~page: option([ | `Int(int) | `Float(float)])=?,
      ~selected: option(bool)=?,
      ~shape: option(shape)=?,
      ~size: option(size)=?,
      ~type_: option(type_)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disabled?,
    ~page=?page->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~selected?,
    ~shape=?shape->Belt.Option.map(v => shapeToJs(v)),
    ~size=?size->Belt.Option.map(v => sizeToJs(v)),
    ~_type=?type_->Belt.Option.map(v => type_ToJs(v)),
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "PaginationItem";
