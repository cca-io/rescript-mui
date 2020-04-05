[@bs.deriving jsConverter]
type textColor = [
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "primary"] `Primary
  | [@bs.as "inherit"] `Inherit
];

[@bs.deriving jsConverter]
type type_ = [
  | [@bs.as "submit"] `Submit
  | [@bs.as "reset"] `Reset
  | [@bs.as "button"] `Button
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
    | Wrapped(string)
    | Wrapper(string);
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
    | Wrapped(_) => "wrapped"
    | Wrapper(_) => "wrapper";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
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
                         | Wrapped(className)
                         | Wrapper(className) =>
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
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~fullWidth: bool=?,
    ~icon: React.element=?,
    ~indicator: React.element=?,
    ~label: React.element=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~selected: bool=?,
    ~textColor: string=?,
    ~value: 'any_rmg4=?,
    ~wrapped: bool=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~centerRipple: bool=?,
    ~component: 'union_rffn=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
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
    ~tabIndex: 'union_rfsw=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~_type: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disabled: option(bool)=?,
      ~disableFocusRipple: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~icon: option(React.element)=?,
      ~indicator: option(React.element)=?,
      ~label: option(React.element)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~selected: option(bool)=?,
      ~textColor: option(textColor)=?,
      ~value: option('any_rmg4)=?,
      ~wrapped: option(bool)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~centerRipple: option(bool)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
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
      ~type_: option(type_)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~disabled?,
    ~disableFocusRipple?,
    ~disableRipple?,
    ~fullWidth?,
    ~icon?,
    ~indicator?,
    ~label?,
    ~onChange?,
    ~onClick?,
    ~selected?,
    ~textColor=?
      textColor->(
                   Belt.Option.map(v =>
                     switch (v->Obj.magic->Js.Json.classify) {
                     | JSONString(str) => str
                     | _ => textColorToJs(v)
                     }
                   )
                 ),
    ~value?,
    ~wrapped?,
    ~key?,
    ~ref?,
    ~centerRipple?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disableTouchRipple?,
    ~focusRipple?,
    ~focusVisibleClassName?,
    ~onBlur?,
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
    ~_type=?type_->(Belt.Option.map(v => type_ToJs(v))),
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Tab";
