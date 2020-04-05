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
    ~component: 'union_r4tr=?,
    ~disableTypography: bool=?,
    ~subheader: React.element=?,
    ~subheaderTypographyProps: Js.t({..})=?,
    ~title: React.element=?,
    ~titleTypographyProps: Js.t({..})=?,
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
      ~action: option(React.element)=?,
      ~avatar: option(React.element)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~disableTypography: option(bool)=?,
      ~subheader: option(React.element)=?,
      ~subheaderTypographyProps: option(Js.t({..}))=?,
      ~title: option(React.element)=?,
      ~titleTypographyProps: option(Js.t({..}))=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
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
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "CardHeader";
