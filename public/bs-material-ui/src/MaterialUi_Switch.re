[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "default"] `Default
];

[@bs.deriving jsConverter]
type edge = [
  | [@bs.as "start"] `Start
  | [@bs.as "end"] `End
  | [@bs.as "false"] `False
];

[@bs.deriving jsConverter]
type size = [ | [@bs.as "small"] `Small | [@bs.as "medium"] `Medium];

module Classes = {
  type classesType =
    | Root(string)
    | EdgeStart(string)
    | EdgeEnd(string)
    | SwitchBase(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | SizeSmall(string)
    | Checked(string)
    | Disabled(string)
    | Input(string)
    | Thumb(string)
    | Track(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | EdgeStart(_) => "edgeStart"
    | EdgeEnd(_) => "edgeEnd"
    | SwitchBase(_) => "switchBase"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | SizeSmall(_) => "sizeSmall"
    | Checked(_) => "checked"
    | Disabled(_) => "disabled"
    | Input(_) => "input"
    | Thumb(_) => "thumb"
    | Track(_) => "track";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | EdgeStart(className)
                         | EdgeEnd(className)
                         | SwitchBase(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | SizeSmall(className)
                         | Checked(className)
                         | Disabled(className)
                         | Input(className)
                         | Thumb(className)
                         | Track(className) =>
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
    ~checked: bool=?,
    ~checkedIcon: React.element=?,
    ~className: string=?,
    ~color: string=?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~edge: string=?,
    ~icon: React.element=?,
    ~id: string=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_rata=?,
    ~onChange: 'any_r1xo=?,
    ~required: bool=?,
    ~size: string=?,
    ~_type: string=?,
    ~value: 'any_rtzd=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~children: 'children=?,
    ~disableFocusRipple: bool=?,
    ~action: 'union_rb7w=?,
    ~buttonRef: 'union_rr3g=?,
    ~centerRipple: bool=?,
    ~component: 'union_rhk5=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onDragLeave: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onFocusVisible: 'genericCallback=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseUp: ReactEvent.Mouse.t => unit=?,
    ~onTouchEnd: ReactEvent.Touch.t => unit=?,
    ~onTouchMove: ReactEvent.Touch.t => unit=?,
    ~onTouchStart: ReactEvent.Touch.t => unit=?,
    ~role: string=?,
    ~tabIndex: 'union_rnnm=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~checked: option(bool)=?,
      ~checkedIcon: option(React.element)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~defaultChecked: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~edge: option(edge)=?,
      ~icon: option(React.element)=?,
      ~id: option(string)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~required: option(bool)=?,
      ~size: option(size)=?,
      ~type_: option(string)=?,
      ~value: option('any_rtzd)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~children: option('children)=?,
      ~disableFocusRipple: option(bool)=?,
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
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onFocusVisible: option('genericCallback)=?,
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
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~checked?,
    ~checkedIcon?,
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~defaultChecked?,
    ~disabled?,
    ~disableRipple?,
    ~edge=?edge->(Belt.Option.map(v => edgeToJs(v))),
    ~icon?,
    ~id?,
    ~inputProps?,
    ~inputRef=?
      inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~onChange?,
    ~required?,
    ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
    ~_type=?type_,
    ~value?,
    ~key?,
    ~_ref=?ref_,
    ~children?,
    ~disableFocusRipple?,
    ~action=?
      action->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~buttonRef=?
      buttonRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~centerRipple?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disableTouchRipple?,
    ~focusRipple?,
    ~focusVisibleClassName?,
    ~onBlur?,
    ~onClick?,
    ~onDragLeave?,
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
      tabIndex->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~_TouchRippleProps?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Switch";
