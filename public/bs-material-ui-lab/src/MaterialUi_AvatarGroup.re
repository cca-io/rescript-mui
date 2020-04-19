[@bs.deriving jsConverter]
type spacing_enum = [ | [@bs.as "medium"] `Medium | [@bs.as "small"] `Small];

module Classes = {
  type classesType =
    | Root(string)
    | Avatar(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Avatar(_) => "avatar";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Avatar(className) =>
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
    ~max: 'number_6=?,
    ~spacing: 'union_rg9x=?,
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
      ~max: option([ | `Int(int) | `Float(float)])=?,
      ~spacing:
         option([ | `Enum(spacing_enum) | `Int(int) | `Float(float)])=?,
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
    ~max=?max->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~spacing=?
      spacing->(
                 Belt.Option.map(v =>
                   switch (v) {
                   | `Enum(v) =>
                     MaterialUi_Helpers.unwrapValue(
                       `String(spacing_enumToJs(v)),
                     )

                   | v => MaterialUi_Helpers.unwrapValue(v)
                   }
                 )
               ),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "AvatarGroup";
