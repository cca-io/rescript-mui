module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    absolute: string,
    [@bs.optional]
    inset: string,
    [@bs.optional]
    light: string,
    [@bs.optional]
    middle: string,
    [@bs.optional]
    vertical: string,
    [@bs.optional]
    flexItem: string,
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
    ~absolute: option(bool)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~flexItem: option(bool)=?,
    ~light: option(bool)=?,
    ~orientation: option(
                    [@bs.string] [
                      | [@bs.as "horizontal"] `Horizontal
                      | [@bs.as "vertical"] `Vertical
                    ],
                  )
                    =?,
    ~role: option(string)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "fullWidth"] `FullWidth
                  | [@bs.as "inset"] `Inset
                  | [@bs.as "middle"] `Middle
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Divider";
