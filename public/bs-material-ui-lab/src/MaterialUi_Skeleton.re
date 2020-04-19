module Animation: {
  type t;
  let pulse: t;
  let wave: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let pulse = Any("pulse");
  let wave = Any("wave");
  let _false = Any(false);
};

module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    text: string,
    [@bs.optional]
    rect: string,
    [@bs.optional]
    circle: string,
    [@bs.optional]
    pulse: string,
    [@bs.optional]
    wave: string,
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

module Height: {
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

module Width: {
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

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~animation: option(Animation.t)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~height: option(Height.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "text"] `Text
                  | [@bs.as "rect"] `Rect
                  | [@bs.as "circle"] `Circle
                ],
              )
                =?,
    ~width: option(Width.t)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Skeleton";
