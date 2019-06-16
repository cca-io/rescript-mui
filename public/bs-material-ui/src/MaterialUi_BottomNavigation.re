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
    ~children: 'children=?,
    ~className: string=?,
    ~onChange: 'any_r881=?,
    ~showLabels: bool=?,
    ~value: 'any_rvl3=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "BottomNavigation";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~onChange: option((ReactEvent.Form.t, 'any_rjy9) => unit)=?,
      ~showLabels: option(bool)=?,
      ~value: option('any_rvl3)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~onChange?,
      ~showLabels?,
      ~value?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
