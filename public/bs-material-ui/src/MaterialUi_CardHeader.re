module Classes = {
  type classesType =
    | Root(string)
    | Avatar(string)
    | Action(string)
    | Content(string)
    | Title(string)
    | Subheader(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Avatar(_) => "avatar"
    | Action(_) => "action"
    | Content(_) => "content"
    | Title(_) => "title"
    | Subheader(_) => "subheader";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Avatar(className)
                         | Action(className)
                         | Content(className)
                         | Title(className)
                         | Subheader(className) =>
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
    ~avatar: React.element=?,
    ~className: string=?,
    ~component: 'union_rp7g=?,
    ~disableTypography: bool=?,
    ~subheader: React.element=?,
    ~subheaderTypographyProps: Js.t({..})=?,
    ~title: React.element=?,
    ~titleTypographyProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "CardHeader";

[@react.component]
let make =
    (
      ~action: option(React.element)=?,
      ~avatar: option(React.element)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~disableTypography: option(bool)=?,
      ~subheader: option(React.element)=?,
      ~subheaderTypographyProps: option(Js.t({..}))=?,
      ~title: option(React.element)=?,
      ~titleTypographyProps: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~action?,
      ~avatar?,
      ~className?,
      ~component=?
        component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~disableTypography?,
      ~subheader?,
      ~subheaderTypographyProps?,
      ~title?,
      ~titleTypographyProps?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
