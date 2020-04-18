module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    filled: string,
    [@bs.optional]
    positionStart: string,
    [@bs.optional]
    positionEnd: string,
    [@bs.optional]
    disablePointerEvents: string,
    [@bs.optional]
    hiddenLabel: string,
    [@bs.optional]
    marginDense: string,
  };
  let make = t;
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
