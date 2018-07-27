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
    listOfClasses
    |. Belt.List.reduce(
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
       );
};

[@bs.obj]
external makeProps :
  (
    ~action: ReasonReact.reactElement=?,
    ~className: string=?,
    ~message: ReasonReact.reactElement=?,
    ~component: 'union_r4cf=?,
    ~elevation: 'number_h=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/SnackbarContent/SnackbarContent"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~action: option(ReasonReact.reactElement)=?,
      ~className: option(string)=?,
      ~message: option(ReasonReact.reactElement)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~action?,
        ~className?,
        ~message?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~elevation=?
          elevation |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~square?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
