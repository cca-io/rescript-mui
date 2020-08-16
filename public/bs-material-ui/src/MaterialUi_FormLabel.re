module Classes = {
  type t = {
    .
    "root": option(string),
    "colorSecondary": option(string),
    "focused": option(string),
    "disabled": option(string),
    "error": option(string),
    "filled": option(string),
    "required": option(string),
    "asterisk": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~colorSecondary: string=?,
      ~focused: string=?,
      ~disabled: string=?,
      ~error: string=?,
      ~filled: string=?,
      ~required: string=?,
      ~asterisk: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Primary | `Secondary];

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
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~component: Component.t=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~filled: bool=?,
    ~focused: bool=?,
    ~required: bool=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "FormLabel";
