module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    sizeSmall: string,
    [@bs.optional]
    sizeLarge: string,
    [@bs.optional]
    readOnly: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    focusVisible: string,
    [@bs.optional]
    visuallyhidden: string,
    [@bs.optional]
    pristine: string,
    [@bs.optional]
    label: string,
    [@bs.optional]
    icon: string,
    [@bs.optional]
    iconEmpty: string,
    [@bs.optional]
    iconFilled: string,
    [@bs.optional]
    iconHover: string,
    [@bs.optional]
    iconFocus: string,
    [@bs.optional]
    iconActive: string,
    [@bs.optional]
    decimal: string,
  };
  let make = t;
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

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~defaultValue: option(MaterialUi_Types.Number.t)=?,
    ~disabled: option(bool)=?,
    ~emptyIcon: option(React.element)=?,
    ~emptyLabelText: option(React.element)=?,
    ~getLabelText: option(int => string)=?,
    ~icon: option(React.element)=?,
    ~_IconContainerComponent: option(IconContainerComponent.t)=?,
    ~max: option(MaterialUi_Types.Number.t)=?,
    ~name: option(string)=?,
    ~onChange: option((ReactEvent.Form.t, int) => unit)=?,
    ~onChangeActive: option((Js.Dict.t(MaterialUi_Types.any), int) => unit)=?,
    ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
    ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
    ~precision: option(MaterialUi_Types.Number.t)=?,
    ~readOnly: option(bool)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "large"] `Large
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~value: option(MaterialUi_Types.Number.t)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Rating";
