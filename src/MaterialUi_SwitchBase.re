[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

module Classes = {
  type classesType =
    | Root(string)
    | Checked(string)
    | Disabled(string)
    | Input(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Checked(_) => "checked"
    | Disabled(_) => "disabled"
    | Input(_) => "input";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Checked(className)
           | Disabled(className)
           | Input(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~checked: 'union_ryud=?,
    ~checkedIcon: ReasonReact.reactElement,
    ~className: string=?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~icon: ReasonReact.reactElement,
    ~id: string=?,
    ~indeterminate: bool=?,
    ~indeterminateIcon: ReasonReact.reactElement=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_rsbc=?,
    ~name: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onChange: 'any_rsbh=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~tabIndex: 'union_rnzj=?,
    ~_type: string=?,
    ~value: string=?,
    ~color: string=?,
    ~action: 'any_r8aa=?,
    ~buttonRef: 'union_rghf=?,
    ~centerRipple: bool=?,
    ~component: 'union_rs8i=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
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
    ~_TouchRippleProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/internal/SwitchBase"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~checked: option([ | `Bool(bool) | `String(string)])=?,
      ~checkedIcon: ReasonReact.reactElement,
      ~className: option(string)=?,
      ~defaultChecked: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~icon: ReasonReact.reactElement,
      ~id: option(string)=?,
      ~indeterminate: option(bool)=?,
      ~indeterminateIcon: option(ReasonReact.reactElement)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onChange: option((ReactEventRe.Form.t, bool) => unit)=?,
      ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
      ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~type_: option(string)=?,
      ~value: option(string)=?,
      ~color: option(color)=?,
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
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
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
      ~_TouchRippleProps: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~checked=?
          checked |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~checkedIcon,
        ~className?,
        ~defaultChecked?,
        ~disabled?,
        ~disableRipple?,
        ~icon,
        ~id?,
        ~indeterminate?,
        ~indeterminateIcon?,
        ~inputProps?,
        ~inputRef=?
          inputRef |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~name?,
        ~onBlur?,
        ~onChange?,
        ~onFocus?,
        ~tabIndex=?
          tabIndex |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_type=?type_,
        ~value?,
        ~color=?color |. Belt.Option.map(v => colorToJs(v)),
        ~action?,
        ~buttonRef=?
          buttonRef |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~centerRipple?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~disableTouchRipple?,
        ~focusRipple?,
        ~focusVisibleClassName?,
        ~onClick?,
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
        ~_TouchRippleProps?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
