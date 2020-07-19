module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "marginNormal": option(option(string)),
    "marginDense": option(option(string)),
    "fullWidth": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~marginNormal: string=?,
      ~marginDense: string=?,
      ~fullWidth: string=?,
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

type margin = [ | `Dense | `None | `Normal];

type size = [ | `Medium | `Small];

type variant = [ | `Filled | `Outlined | `Standard];

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
    ~focused: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~hiddenLabel: option(bool)=?,
    ~margin: option(
               [@bs.string] [
                 | [@bs.as "dense"] `Dense
                 | [@bs.as "none"] `None
                 | [@bs.as "normal"] `Normal
               ],
             )
               =?,
    ~required: option(bool)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "filled"] `Filled
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "standard"] `Standard
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "FormControl";
