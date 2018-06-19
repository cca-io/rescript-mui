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
    listOfClasses
    |. Belt.List.reduce(
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
       );
};

[@bs.obj]
external makeProps :
  (
    ~action: ReasonReact.reactElement=?,
    ~avatar: ReasonReact.reactElement=?,
    ~className: string=?,
    ~component: 'union_rv7z=?,
    ~subheader: ReasonReact.reactElement=?,
    ~title: ReasonReact.reactElement=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/CardHeader/CardHeader"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~action: option(ReasonReact.reactElement)=?,
      ~avatar: option(ReasonReact.reactElement)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~subheader: option(ReasonReact.reactElement)=?,
      ~title: option(ReasonReact.reactElement)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~action?,
        ~avatar?,
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~subheader?,
        ~title?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
