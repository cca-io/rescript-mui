module Classes = {
  type classesType =
    | Root(string)
    | Inset(string)
    | Dense(string)
    | Primary(string)
    | Secondary(string)
    | TextDense(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Inset(_) => "inset"
    | Dense(_) => "dense"
    | Primary(_) => "primary"
    | Secondary(_) => "secondary"
    | TextDense(_) => "textDense";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Inset(className)
                         | Dense(className)
                         | Primary(className)
                         | Secondary(className)
                         | TextDense(className) =>
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
    ~disableTypography: bool=?,
    ~inset: bool=?,
    ~primary: React.element=?,
    ~primaryTypographyProps: Js.t({..})=?,
    ~secondary: React.element=?,
    ~secondaryTypographyProps: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "ListItemText";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disableTypography: option(bool)=?,
      ~inset: option(bool)=?,
      ~primary: option(React.element)=?,
      ~primaryTypographyProps: option(Js.t({..}))=?,
      ~secondary: option(React.element)=?,
      ~secondaryTypographyProps: option(Js.t({..}))=?,
      ~theme: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~disableTypography?,
      ~inset?,
      ~primary?,
      ~primaryTypographyProps?,
      ~secondary?,
      ~secondaryTypographyProps?,
      ~theme?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
