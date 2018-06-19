[@bs.deriving jsConverter]
type textColor = [
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "primary"] `Primary
  | [@bs.as "inherit"] `Inherit
];

module Classes = {
  type classesType =
    | Root(string)
    | LabelIcon(string)
    | TextColorInherit(string)
    | TextColorPrimary(string)
    | TextColorSecondary(string)
    | Selected(string)
    | Disabled(string)
    | FullWidth(string)
    | Wrapper(string)
    | LabelContainer(string)
    | Label(string)
    | LabelWrapped(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | LabelIcon(_) => "labelIcon"
    | TextColorInherit(_) => "textColorInherit"
    | TextColorPrimary(_) => "textColorPrimary"
    | TextColorSecondary(_) => "textColorSecondary"
    | Selected(_) => "selected"
    | Disabled(_) => "disabled"
    | FullWidth(_) => "fullWidth"
    | Wrapper(_) => "wrapper"
    | LabelContainer(_) => "labelContainer"
    | Label(_) => "label"
    | LabelWrapped(_) => "labelWrapped";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | LabelIcon(className)
           | TextColorInherit(className)
           | TextColorPrimary(className)
           | TextColorSecondary(className)
           | Selected(className)
           | Disabled(className)
           | FullWidth(className)
           | Wrapper(className)
           | LabelContainer(className)
           | Label(className)
           | LabelWrapped(className) =>
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
    ~disabled: bool=?,
    ~fullWidth: bool=?,
    ~icon: ReasonReact.reactElement=?,
    ~indicator: ReasonReact.reactElement=?,
    ~label: ReasonReact.reactElement=?,
    ~onChange: ReactEventRe.Form.t => unit=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
    ~selected: bool=?,
    ~textColor: string=?,
    ~value: 'any_r0w7=?,
    ~action: 'any_r0d6=?,
    ~buttonRef: 'union_r8nr=?,
    ~centerRipple: bool=?,
    ~component: 'union_r4g5=?,
    ~disableRipple: bool=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~onFocusVisible: 'genericCallback=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~onKeyUp: ReactEventRe.Keyboard.t => unit=?,
    ~onMouseDown: ReactEventRe.Mouse.t => unit=?,
    ~onMouseLeave: ReactEventRe.Mouse.t => unit=?,
    ~onMouseUp: ReactEventRe.Mouse.t => unit=?,
    ~onTouchEnd: ReactEventRe.Touch.t => unit=?,
    ~onTouchMove: ReactEventRe.Touch.t => unit=?,
    ~onTouchStart: ReactEventRe.Touch.t => unit=?,
    ~role: string=?,
    ~tabIndex: 'union_rcv2=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~_type: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Tab/Tab"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~disabled: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~icon: option(ReasonReact.reactElement)=?,
      ~indicator: option(ReasonReact.reactElement)=?,
      ~label: option(ReasonReact.reactElement)=?,
      ~onChange: option(ReactEventRe.Form.t => unit)=?,
      ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
      ~selected: option(bool)=?,
      ~textColor: option(textColor)=?,
      ~value: option('any_r0w7)=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~buttonRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~centerRipple: option(bool)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~disableRipple: option(bool)=?,
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
      ~onFocusVisible: option('genericCallback)=?,
      ~onKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onMouseDown: option(ReactEventRe.Mouse.t => unit)=?,
      ~onMouseLeave: option(ReactEventRe.Mouse.t => unit)=?,
      ~onMouseUp: option(ReactEventRe.Mouse.t => unit)=?,
      ~onTouchEnd: option(ReactEventRe.Touch.t => unit)=?,
      ~onTouchMove: option(ReactEventRe.Touch.t => unit)=?,
      ~onTouchStart: option(ReactEventRe.Touch.t => unit)=?,
      ~role: option(string)=?,
      ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~_TouchRippleProps: option(Js.t({..}))=?,
      ~type_: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~disabled?,
        ~fullWidth?,
        ~icon?,
        ~indicator?,
        ~label?,
        ~onChange?,
        ~onClick?,
        ~selected?,
        ~textColor=?textColor |. Belt.Option.map(v => textColorToJs(v)),
        ~value?,
        ~action?,
        ~buttonRef=?
          buttonRef |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~centerRipple?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~disableRipple?,
        ~disableTouchRipple?,
        ~focusRipple?,
        ~focusVisibleClassName?,
        ~onBlur?,
        ~onFocus?,
        ~onFocusVisible?,
        ~onKeyDown?,
        ~onKeyUp?,
        ~onMouseDown?,
        ~onMouseLeave?,
        ~onMouseUp?,
        ~onTouchEnd?,
        ~onTouchMove?,
        ~onTouchStart?,
        ~role?,
        ~tabIndex=?
          tabIndex |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_TouchRippleProps?,
        ~_type=?type_,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
