[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "fullWidth"] `FullWidth
  | [@bs.as "inset"] `Inset
  | [@bs.as "middle"] `Middle
];

module Classes = {
  type classesType =
    | Root(string)
    | Absolute(string)
    | Inset(string)
    | Light(string)
    | Middle(string)
    | Vertical(string)
    | FlexItem(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Absolute(_) => "absolute"
    | Inset(_) => "inset"
    | Light(_) => "light"
    | Middle(_) => "middle"
    | Vertical(_) => "vertical"
    | FlexItem(_) => "flexItem";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Absolute(className)
                         | Inset(className)
                         | Light(className)
                         | Middle(className)
                         | Vertical(className)
                         | FlexItem(className) =>
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
    ~absolute: bool=?,
    ~className: string=?,
    ~component: 'union_rkn6=?,
    ~flexItem: bool=?,
    ~light: bool=?,
    ~orientation: string=?,
    ~role: string=?,
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
      ~absolute: option(bool)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~flexItem: option(bool)=?,
      ~light: option(bool)=?,
      ~orientation: option(orientation)=?,
      ~role: option(string)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~absolute?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~flexItem?,
    ~light?,
    ~orientation=?orientation->Belt.Option.map(v => orientationToJs(v)),
    ~role?,
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Divider";
