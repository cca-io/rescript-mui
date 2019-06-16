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
    ~disableTypography: bool=?,
    ~subheader: React.element=?,
    ~subheaderTypographyProps: Js.t({..})=?,
    ~title: React.element=?,
    ~titleTypographyProps: Js.t({..})=?,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~action: option(React.element)=?,
      ~avatar: option(React.element)=?,
      ~className: option(string)=?,
      ~disableTypography: option(bool)=?,
      ~subheader: option(React.element)=?,
      ~subheaderTypographyProps: option(Js.t({..}))=?,
      ~title: option(React.element)=?,
      ~titleTypographyProps: option(Js.t({..}))=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~action?,
    ~avatar?,
    ~className?,
    ~disableTypography?,
    ~subheader?,
    ~subheaderTypographyProps?,
    ~title?,
    ~titleTypographyProps?,
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "CardHeader";
