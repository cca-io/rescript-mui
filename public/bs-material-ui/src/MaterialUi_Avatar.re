[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "circle"] `Circle
  | [@bs.as "rounded"] `Rounded
  | [@bs.as "square"] `Square
];

module Classes = {
  type classesType =
    | Root(string)
    | ColorDefault(string)
    | Circle(string)
    | Rounded(string)
    | Square(string)
    | Img(string)
    | Fallback(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorDefault(_) => "colorDefault"
    | Circle(_) => "circle"
    | Rounded(_) => "rounded"
    | Square(_) => "square"
    | Img(_) => "img"
    | Fallback(_) => "fallback";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | ColorDefault(className)
                         | Circle(className)
                         | Rounded(className)
                         | Square(className)
                         | Img(className)
                         | Fallback(className) =>
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
    ~alt: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~component: 'union_rrtf=?,
    ~imgProps: Js.t({..})=?,
    ~sizes: string=?,
    ~src: string=?,
    ~srcSet: string=?,
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
      ~alt: option(string)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~imgProps: option(Js.t({..}))=?,
      ~sizes: option(string)=?,
      ~src: option(string)=?,
      ~srcSet: option(string)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~alt?,
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~imgProps?,
    ~sizes?,
    ~src?,
    ~srcSet?,
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Avatar";
