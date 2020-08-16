module Classes = {
  type t = {
    .
    "root": option(string),
    "colorDefault": option(string),
    "circle": option(string),
    "rounded": option(string),
    "square": option(string),
    "img": option(string),
    "fallback": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~colorDefault: string=?,
      ~circle: string=?,
      ~rounded: string=?,
      ~square: string=?,
      ~img: string=?,
      ~fallback: string=?,
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

type variant = [ | `Circle | `Rounded | `Square];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~alt: string=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~imgProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~sizes: string=?,
    ~src: string=?,
    ~srcSet: string=?,
    ~variant: [@bs.string] [
                | [@bs.as "circle"] `Circle
                | [@bs.as "rounded"] `Rounded
                | [@bs.as "square"] `Square
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Avatar";
