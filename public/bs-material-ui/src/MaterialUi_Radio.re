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
    | Checked(string)
    | Disabled(string)
    | ColorPrimary(string)
    | ColorSecondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Checked(_) => "checked"
    | Disabled(_) => "disabled"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Checked(className)
                         | Disabled(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className) =>
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
    ~color: string=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~icon: React.element=?,
    ~id: string=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_rxpy=?,
    ~name: string=?,
    ~onChange: 'any_rsrw=?,
    ~_type: string=?,
    ~value: 'any_rzkx=?,
    ~children: 'children=?,
    ~className: string=?,
    ~disableFocusRipple: bool=?,
    ~edge: string=?,
    ~size: string=?,
    ~action: 'any_rhzw=?,
    ~buttonRef: 'union_rksp=?,
    ~centerRipple: bool=?,
    ~component: React.element=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onDragEnd: ReactEvent.Mouse.t => unit=?,
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
    ~tabIndex: 'union_rdmf=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Radio";

[@react.component]
let make =
    (
      ~checked: option(bool)=?,
      ~checkedIcon: option(React.element)=?,
      ~color: option(color)=?,
      ~disabled: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~icon: option(React.element)=?,
      ~id: option(string)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~name: option(string)=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~type_: option(string)=?,
      ~value: option('any_rzkx)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disableFocusRipple: option(bool)=?,
      ~edge: option(edge)=?,
      ~size: option(size)=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~buttonRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~centerRipple: option(bool)=?,
      ~component: option(React.element)=?,
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onDragEnd: option(ReactEvent.Mouse.t => unit)=?,
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
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~checked?,
      ~checkedIcon?,
      ~color=?color->(Belt.Option.map(v => colorToJs(v))),
      ~disabled?,
      ~disableRipple?,
      ~icon?,
      ~id?,
      ~inputProps?,
      ~inputRef=?
        inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~name?,
      ~onChange?,
      ~_type=?type_,
      ~value?,
      ~children?,
      ~className?,
      ~disableFocusRipple?,
      ~edge=?edge->(Belt.Option.map(v => edgeToJs(v))),
      ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
      ~action?,
      ~buttonRef=?
        buttonRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~centerRipple?,
      ~component?,
      ~disableTouchRipple?,
      ~focusRipple?,
      ~focusVisibleClassName?,
      ~onBlur?,
      ~onClick?,
      ~onDragEnd?,
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
    ),
  );
