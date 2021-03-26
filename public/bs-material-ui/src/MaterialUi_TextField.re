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

module Classes = {
  type t = {. "root": option(string)};
  [@bs.obj] external make: (~root: string=?, unit) => t;
};

type color = [ | `Primary | `Secondary];

module DefaultValue: {
  type t;
  let string: string => t;
  let int: int => t;
  let float: float => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
};

type margin = [ | `Dense | `None | `Normal];

module Rows: {
  type t;
  let int: int => t;
  let float: float => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let string = (v: string) => Any(v);
};

module RowsMax: {
  type t;
  let int: int => t;
  let float: float => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let string = (v: string) => Any(v);
};

type size = [ | `Medium | `Small];

module Value: {
  type t;
  let string: string => t;
  let int: int => t;
  let float: float => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
};

type variant = [ | `Filled | `Outlined | `Standard];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: Component.t=?,
    ~focused: bool=?,
    ~style: ReactDOM.Style.t=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~defaultValue: DefaultValue.t=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~_FormHelperTextProps: Js.t({..})=?,
    ~fullWidth: bool=?,
    ~helperText: React.element=?,
    ~hiddenLabel: bool=?,
    ~id: string=?,
    ~_InputLabelProps: Js.t({..})=?,
    ~inputProps: Js.t({..})=?,
    ~_InputProps: Js.t({..})=?,
    ~label: React.element=?,
    ~margin: [@bs.string] [
               | [@bs.as "dense"] `Dense
               | [@bs.as "none"] `None
               | [@bs.as "normal"] `Normal
             ]
               =?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~placeholder: string=?,
    ~required: bool=?,
    ~rows: Rows.t=?,
    ~rowsMax: RowsMax.t=?,
    ~select: bool=?,
    ~_SelectProps: Js.t({..})=?,
    ~size: [@bs.string] [
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
    ~_type: string=?,
    ~value: Value.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "filled"] `Filled
                | [@bs.as "outlined"] `Outlined
                | [@bs.as "standard"] `Standard
              ]
                =?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "TextField";
