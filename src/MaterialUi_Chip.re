module Classes = {
  type classesType =
    | Root(string)
    | Clickable(string)
    | Deletable(string)
    | Avatar(string)
    | AvatarChildren(string)
    | Label(string)
    | DeleteIcon(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Clickable(_) => "clickable"
    | Deletable(_) => "deletable"
    | Avatar(_) => "avatar"
    | AvatarChildren(_) => "avatarChildren"
    | Label(_) => "label"
    | DeleteIcon(_) => "deleteIcon";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Clickable(className)
           | Deletable(className)
           | Avatar(className)
           | AvatarChildren(className)
           | Label(className)
           | DeleteIcon(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~avatar: ReasonReact.reactElement=?,
    ~className: string=?,
    ~component: 'union_rxva=?,
    ~deleteIcon: ReasonReact.reactElement=?,
    ~label: ReasonReact.reactElement=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
    ~onDelete: ReactEventRe.Synthetic.t => unit=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~tabIndex: 'union_r789=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/Chip/Chip"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~avatar: option(ReasonReact.reactElement)=?,
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~deleteIcon: option(ReasonReact.reactElement)=?,
      ~label: option(ReasonReact.reactElement)=?,
      ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
      ~onDelete: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~avatar?,
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~deleteIcon?,
        ~label?,
        ~onClick?,
        ~onDelete?,
        ~onKeyDown?,
        ~tabIndex=?
          tabIndex |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
