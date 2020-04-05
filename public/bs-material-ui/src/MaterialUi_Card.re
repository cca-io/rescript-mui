[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "elevation"] `Elevation
  | [@bs.as "outlined"] `Outlined
];

module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className) =>
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
    ~component: 'union_rijg=?,
    ~elevation: 'number_3=?,
    ~square: bool=?,
    ~variant: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~raised: bool=?,
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
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~variant: option(variant)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~raised: option(bool)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~square?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~children?,
    ~className?,
    ~raised?,
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Card";
