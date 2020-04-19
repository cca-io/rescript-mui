[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type size = [
  | [@bs.as "small"] `Small
  | [@bs.as "medium"] `Medium
  | [@bs.as "large"] `Large
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "text"] `Text
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "contained"] `Contained
];

module Classes = {
  type classesType =
    | Root(string)
    | Label(string)
    | Text(string)
    | TextPrimary(string)
    | TextSecondary(string)
    | Outlined(string)
    | OutlinedPrimary(string)
    | OutlinedSecondary(string)
    | Contained(string)
    | ContainedPrimary(string)
    | ContainedSecondary(string)
    | DisableElevation(string)
    | FocusVisible(string)
    | Disabled(string)
    | ColorInherit(string)
    | TextSizeSmall(string)
    | TextSizeLarge(string)
    | OutlinedSizeSmall(string)
    | OutlinedSizeLarge(string)
    | ContainedSizeSmall(string)
    | ContainedSizeLarge(string)
    | SizeSmall(string)
    | SizeLarge(string)
    | FullWidth(string)
    | StartIcon(string)
    | EndIcon(string)
    | IconSizeSmall(string)
    | IconSizeMedium(string)
    | IconSizeLarge(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Label(_) => "label"
    | Text(_) => "text"
    | TextPrimary(_) => "textPrimary"
    | TextSecondary(_) => "textSecondary"
    | Outlined(_) => "outlined"
    | OutlinedPrimary(_) => "outlinedPrimary"
    | OutlinedSecondary(_) => "outlinedSecondary"
    | Contained(_) => "contained"
    | ContainedPrimary(_) => "containedPrimary"
    | ContainedSecondary(_) => "containedSecondary"
    | DisableElevation(_) => "disableElevation"
    | FocusVisible(_) => "focusVisible"
    | Disabled(_) => "disabled"
    | ColorInherit(_) => "colorInherit"
    | TextSizeSmall(_) => "textSizeSmall"
    | TextSizeLarge(_) => "textSizeLarge"
    | OutlinedSizeSmall(_) => "outlinedSizeSmall"
    | OutlinedSizeLarge(_) => "outlinedSizeLarge"
    | ContainedSizeSmall(_) => "containedSizeSmall"
    | ContainedSizeLarge(_) => "containedSizeLarge"
    | SizeSmall(_) => "sizeSmall"
    | SizeLarge(_) => "sizeLarge"
    | FullWidth(_) => "fullWidth"
    | StartIcon(_) => "startIcon"
    | EndIcon(_) => "endIcon"
    | IconSizeSmall(_) => "iconSizeSmall"
    | IconSizeMedium(_) => "iconSizeMedium"
    | IconSizeLarge(_) => "iconSizeLarge";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Label(className)
                         | Text(className)
                         | TextPrimary(className)
                         | TextSecondary(className)
                         | Outlined(className)
                         | OutlinedPrimary(className)
                         | OutlinedSecondary(className)
                         | Contained(className)
                         | ContainedPrimary(className)
                         | ContainedSecondary(className)
                         | DisableElevation(className)
                         | FocusVisible(className)
                         | Disabled(className)
                         | ColorInherit(className)
                         | TextSizeSmall(className)
                         | TextSizeLarge(className)
                         | OutlinedSizeSmall(className)
                         | OutlinedSizeLarge(className)
                         | ContainedSizeSmall(className)
                         | ContainedSizeLarge(className)
                         | SizeSmall(className)
                         | SizeLarge(className)
                         | FullWidth(className)
                         | StartIcon(className)
                         | EndIcon(className)
                         | IconSizeSmall(className)
                         | IconSizeMedium(className)
                         | IconSizeLarge(className) =>
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
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
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
    ~tabIndex: 'union_rzgh=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~id: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_rti0=?,
    ~disabled: bool=?,
    ~disableElevation: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~endIcon: React.element=?,
    ~focusVisibleClassName: string=?,
    ~fullWidth: bool=?,
    ~href: string=?,
    ~size: string=?,
    ~startIcon: React.element=?,
    ~_type: string=?,
    ~variant: string=?,
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
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
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
      ~id: option(string)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~disabled: option(bool)=?,
      ~disableElevation: option(bool)=?,
      ~disableFocusRipple: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~endIcon: option(React.element)=?,
      ~focusVisibleClassName: option(string)=?,
      ~fullWidth: option(bool)=?,
      ~href: option(string)=?,
      ~size: option(size)=?,
      ~startIcon: option(React.element)=?,
      ~type_: option(string)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~centerRipple?,
    ~disableTouchRipple?,
    ~focusRipple?,
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
    ~id?,
    ~children?,
    ~className?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disabled?,
    ~disableElevation?,
    ~disableFocusRipple?,
    ~disableRipple?,
    ~endIcon?,
    ~focusVisibleClassName?,
    ~fullWidth?,
    ~href?,
    ~size=?size->Belt.Option.map(v => sizeToJs(v)),
    ~startIcon?,
    ~_type=?type_,
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Button";
