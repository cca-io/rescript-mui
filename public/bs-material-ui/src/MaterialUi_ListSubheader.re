[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "primary"] `Primary
  | [@bs.as "inherit"] `Inherit
];

module Classes = {
  type classesType =
    | Root(string)
    | ColorPrimary(string)
    | ColorInherit(string)
    | Gutters(string)
    | Inset(string)
    | Sticky(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorPrimary(_) => "colorPrimary"
    | ColorInherit(_) => "colorInherit"
    | Gutters(_) => "gutters"
    | Inset(_) => "inset"
    | Sticky(_) => "sticky";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | ColorPrimary(className)
                         | ColorInherit(className)
                         | Gutters(className)
                         | Inset(className)
                         | Sticky(className) =>
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
    ~component: 'union_rq1i=?,
    ~disableGutters: bool=?,
    ~disableSticky: bool=?,
    ~inset: bool=?,
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
      ~disableGutters: option(bool)=?,
      ~disableSticky: option(bool)=?,
      ~inset: option(bool)=?,
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
    ~disableGutters?,
    ~disableSticky?,
    ~inset?,
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ListSubheader";
