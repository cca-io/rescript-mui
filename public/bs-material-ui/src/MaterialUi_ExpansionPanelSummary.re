[@bs.deriving jsConverter]
type type_ = [
  | [@bs.as "submit"] `Submit
  | [@bs.as "reset"] `Reset
  | [@bs.as "button"] `Button
];

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
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
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
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~className: string=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~expandIcon: React.element=?,
    ~_IconButtonProps: Js.t({..})=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocusVisible: 'genericCallback=?,
    ~action: 'any_rlms=?,
    ~buttonRef: 'union_rvry=?,
    ~centerRipple: bool=?,
    ~component: React.element=?,
    ~disableRipple: bool=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~onDragEnd: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseUp: ReactEvent.Mouse.t => unit=?,
    ~onTouchEnd: ReactEvent.Touch.t => unit=?,
    ~onTouchMove: ReactEvent.Touch.t => unit=?,
    ~onTouchStart: ReactEvent.Touch.t => unit=?,
    ~role: string=?,
    ~tabIndex: 'union_rspp=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~_type: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "ExpansionPanelSummary";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~expandIcon: option(React.element)=?,
      ~_IconButtonProps: option(Js.t({..}))=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocusVisible: option('genericCallback)=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~buttonRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~centerRipple: option(bool)=?,
      ~component: option(React.element)=?,
      ~disableRipple: option(bool)=?,
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
      ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
      ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
      ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
      ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
      ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
      ~role: option(string)=?,
      ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~_TouchRippleProps: option(Js.t({..}))=?,
      ~type_: option(type_)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~disabled?,
      ~expanded?,
      ~expandIcon?,
      ~_IconButtonProps?,
      ~onBlur?,
      ~onChange?,
      ~onClick?,
      ~onFocusVisible?,
      ~action?,
      ~buttonRef=?
        buttonRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~centerRipple?,
      ~component?,
      ~disableRipple?,
      ~disableTouchRipple?,
      ~focusRipple?,
      ~focusVisibleClassName?,
      ~onDragEnd?,
      ~onFocus?,
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
        tabIndex->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~_TouchRippleProps?,
      ~_type=?type_->(Belt.Option.map(v => type_ToJs(v))),
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
