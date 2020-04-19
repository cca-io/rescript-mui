[@bs.deriving jsConverter]
type type_ = [
  | [@bs.as "submit"] `Submit
  | [@bs.as "reset"] `Reset
  | [@bs.as "button"] `Button
];

[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

module Classes = {
  type classesType =
    | Root(string)
    | Horizontal(string)
    | Vertical(string)
    | TouchRipple(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | TouchRipple(_) => "touchRipple";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Horizontal(className)
                         | Vertical(className)
                         | TouchRipple(className) =>
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
    ~centerRipple: bool=?,
    ~component: 'union_reo3=?,
    ~disableRipple: bool=?,
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
    ~tabIndex: 'union_r415=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~_type: string=?,
    ~id: string=?,
    ~active: bool=?,
    ~alternativeLabel: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~completed: bool=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~icon: React.element=?,
    ~last: bool=?,
    ~optional: React.element=?,
    ~orientation: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~centerRipple: option(bool)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~disableRipple: option(bool)=?,
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
      ~type_: option(type_)=?,
      ~id: option(string)=?,
      ~active: option(bool)=?,
      ~alternativeLabel: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~completed: option(bool)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~icon: option(React.element)=?,
      ~last: option(bool)=?,
      ~optional: option(React.element)=?,
      ~orientation: option(orientation)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~centerRipple?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disableRipple?,
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
    ~_type=?type_->Belt.Option.map(v => type_ToJs(v)),
    ~id?,
    ~active?,
    ~alternativeLabel?,
    ~children?,
    ~className?,
    ~completed?,
    ~disabled?,
    ~expanded?,
    ~icon?,
    ~last?,
    ~optional?,
    ~orientation=?
      orientation->(
                     Belt.Option.map(v =>
                       switch (v->Obj.magic->Js.Json.classify) {
                       | JSONString(str) => str
                       | _ => orientationToJs(v)
                       }
                     )
                   ),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "StepButton";
