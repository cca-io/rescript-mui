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
    ~className: string=?,
    ~raised: bool=?,
    ~children: 'children=?,
    ~elevation: 'number_0=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Card";

[@react.component]
let make =
    (
      ~className: option(string)=?,
      ~raised: option(bool)=?,
      ~children: option('children)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~className?,
      ~raised?,
      ~children?,
      ~elevation=?
        elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~square?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
