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
    | Middle(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Absolute(_) => "absolute"
    | Inset(_) => "inset"
    | Light(_) => "light"
    | Middle(_) => "middle";
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
                         | Middle(className) =>
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
    ~component: 'union_rwdm=?,
    ~light: bool=?,
    ~role: string=?,
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
      ~absolute: option(bool)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~light: option(bool)=?,
      ~role: option(string)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~absolute?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~light?,
    ~role?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Divider";
