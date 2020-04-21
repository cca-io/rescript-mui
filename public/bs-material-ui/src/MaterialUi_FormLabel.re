module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "colorSecondary": option(option(string)),
    "focused": option(option(string)),
    "disabled": option(option(string)),
    "error": option(option(string)),
    "filled": option(option(string)),
    "required": option(option(string)),
    "asterisk": option(option(string)),
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
    ~component: option(Component.t)=?,
    ~disabled: option(bool)=?,
    ~error: option(bool)=?,
    ~filled: option(bool)=?,
    ~focused: option(bool)=?,
    ~required: option(bool)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "FormLabel";
