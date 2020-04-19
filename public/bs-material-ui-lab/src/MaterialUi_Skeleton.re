module Animation = {
  type t = [ | `Pulse | `Wave | `False];
  let tToJs =
    fun
    | `Pulse => "pulse"->Obj.magic
    | `Wave => "wave"->Obj.magic
    | `False => false->Obj.magic;
};

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "text"] `Text
  | [@bs.as "rect"] `Rect
  | [@bs.as "circle"] `Circle
];

module Classes = {
  type classesType =
    | Root(string)
    | Text(string)
    | Rect(string)
    | Circle(string)
    | Pulse(string)
    | Wave(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Text(_) => "text"
    | Rect(_) => "rect"
    | Circle(_) => "circle"
    | Pulse(_) => "pulse"
    | Wave(_) => "wave";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Text(className)
                         | Rect(className)
                         | Circle(className)
                         | Pulse(className)
                         | Wave(className) =>
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
    ~animation: 'any_rzfx=?,
    ~className: string=?,
    ~component: 'union_rn5c=?,
    ~height: 'union_rmue=?,
    ~variant: string=?,
    ~width: 'union_rcj4=?,
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
      ~animation: option(Animation.t)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~height: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~variant: option(variant)=?,
      ~width: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~animation=?animation->Belt.Option.map(v => Animation.tToJs(v)),
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~height=?
      height->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~width=?width->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "Skeleton";
