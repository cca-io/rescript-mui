module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "filled": option(option(string)),
    "positionStart": option(option(string)),
    "positionEnd": option(option(string)),
    "disablePointerEvents": option(option(string)),
    "hiddenLabel": option(option(string)),
    "marginDense": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~filled: string=?,
      ~positionStart: string=?,
      ~positionEnd: string=?,
      ~disablePointerEvents: string=?,
      ~hiddenLabel: string=?,
      ~marginDense: string=?,
      unit
    ) =>
    t;
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

type position = [ | `Start | `End];

type variant = [ | `Standard | `Outlined | `Filled];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~disablePointerEvents: option(bool)=?,
    ~disableTypography: option(bool)=?,
    ~muiFormControl: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~position: option(
                 [@bs.string] [
                   | [@bs.as "start"] `Start
                   | [@bs.as "end"] `End
                 ],
               )
                 =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "standard"] `Standard
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "filled"] `Filled
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "InputAdornment";
