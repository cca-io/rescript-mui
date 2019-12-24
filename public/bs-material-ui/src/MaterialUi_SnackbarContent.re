[@bs.deriving jsConverter]
type role = [ | [@bs.as "alert"] `Alert | [@bs.as "alertdialog"] `Alertdialog];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "elevation"] `Elevation
  | [@bs.as "outlined"] `Outlined
];

module Classes = {
  type classesType =
    | Root(string)
    | Message(string)
    | Action(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Message(_) => "message"
    | Action(_) => "action";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Message(className)
                         | Action(className) =>
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
    ~action: React.element=?,
    ~className: string=?,
    ~message: React.element=?,
    ~role: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~children: 'children=?,
    ~component: 'union_r9wk=?,
    ~elevation: 'number_o=?,
    ~square: bool=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~action: option(React.element)=?,
      ~className: option(string)=?,
      ~message: option(React.element)=?,
      ~role: option(role)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~children: option('children)=?,
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
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~action?,
    ~className?,
    ~message?,
    ~role=?role->(Belt.Option.map(v => roleToJs(v))),
    ~key?,
    ~ref?,
    ~children?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~square?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "SnackbarContent";
