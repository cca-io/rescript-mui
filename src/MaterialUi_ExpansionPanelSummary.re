module Classes = {
  type classesType =
    | Root(string)
    | Expanded(string)
    | Focused(string)
    | Disabled(string)
    | Content(string)
    | ExpandIcon(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Expanded(_) => "expanded"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | Content(_) => "content"
    | ExpandIcon(_) => "expandIcon";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Expanded(className)
             | Focused(className)
             | Disabled(className)
             | Content(className)
             | ExpandIcon(className) =>
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
    ~className: string=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~expandIcon: ReasonReact.reactElement=?,
    ~onChange: ReactEventRe.Form.t => unit=?,
    ~onClick: ReactEventRe.Mouse.t => unit=?,
    ~action: 'any_rynt=?,
    ~buttonRef: 'union_rmv5=?,
    ~centerRipple: bool=?,
    ~component: 'union_rwd2=?,
    ~disableRipple: bool=?,
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
    ~tabIndex: 'union_r7p8=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~type_: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/ExpansionPanelSummary/ExpansionPanelSummary"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~expandIcon: option(ReasonReact.reactElement)=?,
      ~onChange: option(ReactEventRe.Form.t => unit)=?,
      ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
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
        ~expanded?,
        ~expandIcon?,
        ~onChange?,
        ~onClick?,
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
