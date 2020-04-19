module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    disableGutters: string,
    [@bs.optional]
    fixed: string,
    [@bs.optional]
    maxWidthXs: string,
    [@bs.optional]
    maxWidthSm: string,
    [@bs.optional]
    maxWidthMd: string,
    [@bs.optional]
    maxWidthLg: string,
    [@bs.optional]
    maxWidthXl: string,
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

module MaxWidth: {
  type t;
  let xs: t;
  let sm: t;
  let md: t;
  let lg: t;
  let xl: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let xs = Any("xs");
  let sm = Any("sm");
  let md = Any("md");
  let lg = Any("lg");
  let xl = Any("xl");
  let _false = Any(false);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~disableGutters: option(bool)=?,
    ~fixed: option(bool)=?,
    ~maxWidth: option(MaxWidth.t)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Container";
