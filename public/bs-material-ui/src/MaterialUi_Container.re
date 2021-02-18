module Classes = {
  type t = {
    .
    "root": option(string),
    "disableGutters": option(string),
    "fixed": option(string),
    "maxWidthXs": option(string),
    "maxWidthSm": option(string),
    "maxWidthMd": option(string),
    "maxWidthLg": option(string),
    "maxWidthXl": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~disableGutters: string=?,
      ~fixed: string=?,
      ~maxWidthXs: string=?,
      ~maxWidthSm: string=?,
      ~maxWidthMd: string=?,
      ~maxWidthLg: string=?,
      ~maxWidthXl: string=?,
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

module MaxWidth: {
  type t;
  let lg: t;
  let md: t;
  let sm: t;
  let xl: t;
  let xs: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let lg = Any("lg");
  let md = Any("md");
  let sm = Any("sm");
  let xl = Any("xl");
  let xs = Any("xs");
  let _false = Any(false);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~disableGutters: bool=?,
    ~fixed: bool=?,
    ~maxWidth: MaxWidth.t=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Container";
