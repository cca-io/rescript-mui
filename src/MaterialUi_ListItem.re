module Classes = {
  type classesType =
    | Root(string)
    | Container(string)
    | FocusVisible(string)
    | Default(string)
    | Dense(string)
    | Disabled(string)
    | Divider(string)
    | Gutters(string)
    | Button(string)
    | SecondaryAction(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Container(_) => "container"
    | FocusVisible(_) => "focusVisible"
    | Default(_) => "default"
    | Dense(_) => "dense"
    | Disabled(_) => "disabled"
    | Divider(_) => "divider"
    | Gutters(_) => "gutters"
    | Button(_) => "button"
    | SecondaryAction(_) => "secondaryAction";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Container(className)
           | FocusVisible(className)
           | Default(className)
           | Dense(className)
           | Disabled(className)
           | Divider(className)
           | Gutters(className)
           | Button(className)
           | SecondaryAction(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~button: bool=?,
    ~className: string=?,
    ~component: 'union_rl42=?,
    ~_ContainerComponent: 'union_r85x=?,
    ~_ContainerProps: Js.t({..})=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~value: 'union_rbqe=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/ListItem/ListItem"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~button: option(bool)=?,
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~_ContainerComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~_ContainerProps: option(Js.t({..}))=?,
      ~dense: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableGutters: option(bool)=?,
      ~divider: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
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
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~button?,
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_ContainerComponent=?
          _ContainerComponent
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_ContainerProps?,
        ~dense?,
        ~disabled?,
        ~disableGutters?,
        ~divider?,
        ~focusVisibleClassName?,
        ~value=?
          value |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~onFocus?,
        ~onClick?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
