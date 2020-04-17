module SortDirection: {
  type t;

  let false_: t;
  let asc: t;
  let desc: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let false_ = Any(false);
  [@bs.inline]
  let asc = Any("asc");
  [@bs.inline]
  let desc = Any("desc");
};

module Color: {
  type t;

  [@bs.inline "primary"]
  let primary: t;
  [@bs.inline "secondary"]
  let secondary: t;
} = {
  type t = string;

  [@bs.inline]
  let primary = "primary";
  [@bs.inline]
  let secondary = "secondary";
};

module Margin: {
  type t;

  [@bs.inline "none"]
  let none: t;
  [@bs.inline "dense"]
  let dense: t;
  [@bs.inline "normal"]
  let normal: t;
} = {
  type t = string;

  [@bs.inline]
  let none = "none";
  [@bs.inline]
  let dense = "dense";
  [@bs.inline]
  let normal = "normal";
};

module Size: {
  type t;

  [@bs.inline "small"]
  let small: t;
  [@bs.inline "medium"]
  let medium: t;
} = {
  type t = string;

  [@bs.inline]
  let small = "small";
  [@bs.inline]
  let medium = "medium";
};

module Variant: {
  type t;

  [@bs.inline "standard"]
  let standard: t;
  [@bs.inline "outlined"]
  let outlined: t;
  [@bs.inline "filled"]
  let filled: t;
} = {
  type t = string;

  [@bs.inline]
  let standard = "standard";
  [@bs.inline]
  let outlined = "outlined";
  [@bs.inline]
  let filled = "filled";
};

type x = Js.Dict.t(string);

module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
  };
  let make = t;
};

module Value: {
  type t;
  let float: float => t;
  let int: int => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let float = (v: float) => Any(v);
  let int = (v: int) => Any(v);
  let string = (v: string) => Any(v);
};

module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: option(Component.t)=?,
    ~focused: option(bool)=?,
    ~autoComplete: option(string)=?,
    ~autoFocus: option(bool)=?,
    ~className: option(string)=?,
    ~color: option(Color.t)=?,
    ~defaultValue: option(Value.t)=?,
    ~disabled: option(bool)=?,
    ~error: option(bool)=?,
    ~_FormHelperTextProps: option(Js.t({..}))=?,
    ~fullWidth: option(bool)=?,
    ~helperText: option(React.element)=?,
    ~hiddenLabel: option(bool)=?,
    ~id: option(string)=?,
    ~_InputLabelProps: option(Js.t({..}))=?,
    ~_InputProps: option(Js.t({..}))=?,
    ~inputProps: option(Js.t({..}))=?,
    ~label: option(React.element)=?,
    ~margin: option(Margin.t)=?,
    ~multiline: option(bool)=?,
    ~name: option(string)=?,
    ~onBlur: option(ReactEvent.Focus.t => unit)=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
    ~placeholder: option(string)=?,
    ~required: option(bool)=?,
    ~rows: option(Value.t)=?,
    ~rowsMax: option(Value.t)=?,
    ~select: option(bool)=?,
    ~_SelectProps: option(Js.t({..}))=?,
    ~size: option(Size.t)=?,
    ~type_: option(string)=?,
    ~value: option(Value.t)=?,
    ~variant: option(Variant.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?,
    ~classes: option(Classes.t)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~children: option(React.element)=?
  ) =>
  React.element =
  "TextField";