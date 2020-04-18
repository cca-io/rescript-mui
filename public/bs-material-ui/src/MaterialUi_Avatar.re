module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    colorDefault: string,
    [@bs.optional]
    circle: string,
    [@bs.optional]
    rounded: string,
    [@bs.optional]
    square: string,
    [@bs.optional]
    img: string,
    [@bs.optional]
    fallback: string,
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
    ~alt: option(string)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~imgProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~sizes: option(string)=?,
    ~src: option(string)=?,
    ~srcSet: option(string)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "circle"] `Circle
                  | [@bs.as "rounded"] `Rounded
                  | [@bs.as "square"] `Square
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Avatar";
