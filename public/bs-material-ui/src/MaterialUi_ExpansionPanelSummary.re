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
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~action: 'union_rmq1=?,
    ~buttonRef: 'union_rlnc=?,
    ~centerRipple: bool=?,
    ~component: 'union_rp2k=?,
    ~disableRipple: bool=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~onDragLeave: ReactEvent.Mouse.t => unit=?,
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
    ~tabIndex: 'union_r5ht=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~_type: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
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
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~action:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~buttonRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~centerRipple: option(bool)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~disableRipple: option(bool)=?,
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
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
      (),
    ) =>
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
    ~key?,
    ~_ref=?ref_,
    ~action=?
      action->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~buttonRef=?
      buttonRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~centerRipple?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disableRipple?,
    ~disableTouchRipple?,
    ~focusRipple?,
    ~focusVisibleClassName?,
    ~onDragLeave?,
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
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ExpansionPanelSummary";
