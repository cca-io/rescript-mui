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
  | [@bs.as "flat"] `Flat
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "contained"] `Contained
  | [@bs.as "raised"] `Raised
  | [@bs.as "fab"] `Fab
  | [@bs.as "extendedFab"] `ExtendedFab
];

module Classes = {
  type classesType =
    | Root(string)
    | Label(string)
    | Text(string)
    | TextPrimary(string)
    | TextSecondary(string)
    | Flat(string)
    | FlatPrimary(string)
    | FlatSecondary(string)
    | Outlined(string)
    | OutlinedPrimary(string)
    | OutlinedSecondary(string)
    | Contained(string)
    | ContainedPrimary(string)
    | ContainedSecondary(string)
    | Raised(string)
    | RaisedPrimary(string)
    | RaisedSecondary(string)
    | Fab(string)
    | ExtendedFab(string)
    | FocusVisible(string)
    | Disabled(string)
    | ColorInherit(string)
    | Mini(string)
    | SizeSmall(string)
    | SizeLarge(string)
    | FullWidth(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Label(_) => "label"
    | Text(_) => "text"
    | TextPrimary(_) => "textPrimary"
    | TextSecondary(_) => "textSecondary"
    | Flat(_) => "flat"
    | FlatPrimary(_) => "flatPrimary"
    | FlatSecondary(_) => "flatSecondary"
    | Outlined(_) => "outlined"
    | OutlinedPrimary(_) => "outlinedPrimary"
    | OutlinedSecondary(_) => "outlinedSecondary"
    | Contained(_) => "contained"
    | ContainedPrimary(_) => "containedPrimary"
    | ContainedSecondary(_) => "containedSecondary"
    | Raised(_) => "raised"
    | RaisedPrimary(_) => "raisedPrimary"
    | RaisedSecondary(_) => "raisedSecondary"
    | Fab(_) => "fab"
    | ExtendedFab(_) => "extendedFab"
    | FocusVisible(_) => "focusVisible"
    | Disabled(_) => "disabled"
    | ColorInherit(_) => "colorInherit"
    | Mini(_) => "mini"
    | SizeSmall(_) => "sizeSmall"
    | SizeLarge(_) => "sizeLarge"
    | FullWidth(_) => "fullWidth";
  let to_obj = listOfClasses =>
    listOfClasses
    ->(
        Belt.List.reduce(
          Js.Dict.empty(),
          (obj, classType) => {
            switch (classType) {
            | Root(className)
            | Label(className)
            | Text(className)
            | TextPrimary(className)
            | TextSecondary(className)
            | Flat(className)
            | FlatPrimary(className)
            | FlatSecondary(className)
            | Outlined(className)
            | OutlinedPrimary(className)
            | OutlinedSecondary(className)
            | Contained(className)
            | ContainedPrimary(className)
            | ContainedSecondary(className)
            | Raised(className)
            | RaisedPrimary(className)
            | RaisedSecondary(className)
            | Fab(className)
            | ExtendedFab(className)
            | FocusVisible(className)
            | Disabled(className)
            | ColorInherit(className)
            | Mini(className)
            | SizeSmall(className)
            | SizeLarge(className)
            | FullWidth(className) =>
              Js.Dict.set(obj, to_string(classType), className)
            };
            obj;
          },
        )
      );
};

[@bs.obj]
external makeProps:
  (
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_ruif=?,
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~fullWidth: bool=?,
    ~href: string=?,
    ~mini: bool=?,
    ~size: string=?,
    ~_type: string=?,
    ~variant: string=?,
    ~action: 'any_rzar=?,
    ~buttonRef: 'union_rff2=?,
    ~centerRipple: bool=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
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
    ~tabIndex: 'union_rntz=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Button";
let make =
    (
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~disabled: option(bool)=?,
      ~disableFocusRipple: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~fullWidth: option(bool)=?,
      ~href: option(string)=?,
      ~mini: option(bool)=?,
      ~size: option(size)=?,
      ~type_: option(string)=?,
      ~variant: option(variant)=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~buttonRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~centerRipple: option(bool)=?,
      ~disableTouchRipple: option(bool)=?,
      ~focusRipple: option(bool)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
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
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~color=?color->(Belt.Option.map(v => colorToJs(v))),
        ~component=?
          component
          ->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~disabled?,
        ~disableFocusRipple?,
        ~disableRipple?,
        ~focusVisibleClassName?,
        ~fullWidth?,
        ~href?,
        ~mini?,
        ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
        ~_type=?type_,
        ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
        ~action?,
        ~buttonRef=?
          buttonRef
          ->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~centerRipple?,
        ~disableTouchRipple?,
        ~focusRipple?,
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
          tabIndex->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~_TouchRippleProps?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
