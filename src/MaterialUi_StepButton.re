[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

module Classes = {
  type classesType =
    | Root(string)
    | Vertical(string)
    | TouchRipple(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Vertical(_) => "vertical"
    | TouchRipple(_) => "touchRipple";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Vertical(className)
             | TouchRipple(className) =>
               Js.Dict.set(obj, to_string(classType), className)
             };
             obj;
           },
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~active: bool=?,
    ~alternativeLabel: bool=?,
    ~className: string=?,
    ~completed: bool=?,
    ~disabled: bool=?,
    ~icon: ReasonReact.reactElement=?,
    ~last: bool=?,
    ~optional: ReasonReact.reactElement=?,
    ~orientation: string=?,
    ~action: 'any_r3wu=?,
    ~buttonRef: 'union_romm=?,
    ~centerRipple: bool=?,
    ~component: 'union_rbfo=?,
    ~disableRipple: bool=?,
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
    ~tabIndex: 'union_rdtu=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~type_: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/StepButton/StepButton"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~active: option(bool)=?,
      ~alternativeLabel: option(bool)=?,
      ~className: option(string)=?,
      ~completed: option(bool)=?,
      ~disabled: option(bool)=?,
      ~icon: option(ReasonReact.reactElement)=?,
      ~last: option(bool)=?,
      ~optional: option(ReasonReact.reactElement)=?,
      ~orientation: option(orientation)=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~buttonRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~centerRipple: option(bool)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~disableRipple: option(bool)=?,
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
        ~active?,
        ~alternativeLabel?,
        ~className?,
        ~completed?,
        ~disabled?,
        ~icon?,
        ~last?,
        ~optional?,
        ~orientation=?
          Js.Option.map((. v) => orientationToJs(v), orientation),
        ~action?,
        ~buttonRef=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            buttonRef,
          ),
        ~centerRipple?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~disableRipple?,
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
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            tabIndex,
          ),
        ~_TouchRippleProps?,
        ~type_?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
