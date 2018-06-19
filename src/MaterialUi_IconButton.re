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
    | ColorInherit(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | Disabled(string)
    | Label(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorInherit(_) => "colorInherit"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Disabled(_) => "disabled"
    | Label(_) => "label";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | ColorInherit(className)
           | ColorPrimary(className)
           | ColorSecondary(className)
           | Disabled(className)
           | Label(className) =>
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
    ~color: string=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~action: 'any_rd5p=?,
    ~buttonRef: 'union_r3wc=?,
    ~centerRipple: bool=?,
    ~component: 'union_rosr=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
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
    ~tabIndex: 'union_rbf9=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~_type: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/IconButton/IconButton"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~disabled: option(bool)=?,
      ~disableRipple: option(bool)=?,
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
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
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
        ~color=?color |. Belt.Option.map(v => colorToJs(v)),
        ~disabled?,
        ~disableRipple?,
        ~action?,
        ~buttonRef=?
          buttonRef |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~centerRipple?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~disableTouchRipple?,
        ~focusRipple?,
        ~focusVisibleClassName?,
        ~onBlur?,
        ~onClick?,
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
