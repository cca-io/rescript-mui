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
    ~children: 'children=?,
    ~elevation: 'number_t=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "SnackbarContent";

[@react.component]
let make =
    (
      ~action: option(React.element)=?,
      ~className: option(string)=?,
      ~message: option(React.element)=?,
      ~children: option('children)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~action?,
      ~className?,
      ~message?,
      ~children?,
      ~elevation=?
        elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~square?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
