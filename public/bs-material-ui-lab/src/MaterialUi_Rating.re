module Classes = {
  type t = {
    .
    "root": option(string),
    "sizeSmall": option(string),
    "sizeLarge": option(string),
    "readOnly": option(string),
    "disabled": option(string),
    "focusVisible": option(string),
    "visuallyhidden": option(string),
    "pristine": option(string),
    "label": option(string),
    "icon": option(string),
    "iconEmpty": option(string),
    "iconFilled": option(string),
    "iconHover": option(string),
    "iconFocus": option(string),
    "iconActive": option(string),
    "decimal": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~sizeSmall: string=?,
      ~sizeLarge: string=?,
      ~readOnly: string=?,
      ~disabled: string=?,
      ~focusVisible: string=?,
      ~visuallyhidden: string=?,
      ~pristine: string=?,
      ~label: string=?,
      ~icon: string=?,
      ~iconEmpty: string=?,
      ~iconFilled: string=?,
      ~iconHover: string=?,
      ~iconFocus: string=?,
      ~iconActive: string=?,
      ~decimal: string=?,
      unit
    ) =>
    t;
};

module IconContainerComponent: {
  type t;
  let string: string => t;
  let iconContainerComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let iconContainerComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

type size = [ | `Large | `Medium | `Small];

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~classes: Classes.t=?,
    ~className: string=?,
    ~defaultValue: MaterialUi_Types.Number.t=?,
    ~disabled: bool=?,
    ~emptyIcon: React.element=?,
    ~emptyLabelText: React.element=?,
    ~getLabelText: int => string=?,
    ~icon: React.element=?,
    ~_IconContainerComponent: IconContainerComponent.t=?,
    ~max: MaterialUi_Types.Number.t=?,
    ~name: string=?,
    ~onChange: (ReactEvent.Form.t, int) => unit=?,
    ~onChangeActive: (Js.t({..}), int) => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseMove: ReactEvent.Mouse.t => unit=?,
    ~precision: MaterialUi_Types.Number.t=?,
    ~readOnly: bool=?,
    ~size: [@bs.string] [
             | [@bs.as "large"] `Large
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
    ~value: MaterialUi_Types.Number.t=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Rating";
