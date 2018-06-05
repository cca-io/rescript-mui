module Classes = {
  type classesType =
    | Root(string)
    | Selected(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Selected(_) => "selected";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Selected(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~component: 'union_rh6j=?,
    ~role: string=?,
    ~selected: bool=?,
    ~value: 'union_rovl=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
    ~button: bool=?,
    ~_ContainerComponent: 'union_r93w=?,
    ~_ContainerProps: Js.t({..})=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/MenuItem/MenuItem"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~role: option(string)=?,
      ~selected: option(bool)=?,
      ~value:
         option(
           [
             | `String(string)
             | `Int(int)
             | `Float(float)
             | `Array(array(string))
           ],
         )=?,
      ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
      ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
      ~button: option(bool)=?,
      ~_ContainerComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~_ContainerProps: option(Js.t({..}))=?,
      ~dense: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableGutters: option(bool)=?,
      ~divider: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~role?,
        ~selected?,
        ~value=?
          value |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~onFocus?,
        ~onClick?,
        ~button?,
        ~_ContainerComponent=?
          _ContainerComponent
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_ContainerProps?,
        ~dense?,
        ~disabled?,
        ~disableGutters?,
        ~divider?,
        ~focusVisibleClassName?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
