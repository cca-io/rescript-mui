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
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
  };
  let make = t;
};

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

module Rows: {
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

module RowsMax: {
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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: option(Component.t)=?,
    ~focused: option(bool)=?,
    ~autoComplete: option(string)=?,
    ~autoFocus: option(bool)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~defaultValue: option(DefaultValue.t)=?,
    ~disabled: option(bool)=?,
    ~error: option(bool)=?,
    ~_FormHelperTextProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~fullWidth: option(bool)=?,
    ~helperText: option(React.element)=?,
    ~hiddenLabel: option(bool)=?,
    ~id: option(string)=?,
    ~_InputLabelProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_InputProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~inputProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~label: option(React.element)=?,
    ~margin: option(
               [@bs.string] [
                 | [@bs.as "none"] `None
                 | [@bs.as "dense"] `Dense
                 | [@bs.as "normal"] `Normal
               ],
             )
               =?,
    ~multiline: option(bool)=?,
    ~name: option(string)=?,
    ~onBlur: option(ReactEvent.Focus.t => unit)=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
    ~placeholder: option(string)=?,
    ~required: option(bool)=?,
    ~rows: option(Rows.t)=?,
    ~rowsMax: option(RowsMax.t)=?,
    ~select: option(bool)=?,
    ~_SelectProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "small"] `Small
               | [@bs.as "medium"] `Medium
             ],
           )
             =?,
    ~_type: option(string)=?,
    ~value: option(Value.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "standard"] `Standard
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "filled"] `Filled
                ],
              )
                =?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TextField";
