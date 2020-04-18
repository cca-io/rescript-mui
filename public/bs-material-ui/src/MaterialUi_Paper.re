module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    rounded: string,
    [@bs.optional]
    outlined: string,
    [@bs.optional]
    elevation0: string,
    [@bs.optional]
    elevation1: string,
    [@bs.optional]
    elevation2: string,
    [@bs.optional]
    elevation3: string,
    [@bs.optional]
    elevation4: string,
    [@bs.optional]
    elevation5: string,
    [@bs.optional]
    elevation6: string,
    [@bs.optional]
    elevation7: string,
    [@bs.optional]
    elevation8: string,
    [@bs.optional]
    elevation9: string,
    [@bs.optional]
    elevation10: string,
    [@bs.optional]
    elevation11: string,
    [@bs.optional]
    elevation12: string,
    [@bs.optional]
    elevation13: string,
    [@bs.optional]
    elevation14: string,
    [@bs.optional]
    elevation15: string,
    [@bs.optional]
    elevation16: string,
    [@bs.optional]
    elevation17: string,
    [@bs.optional]
    elevation18: string,
    [@bs.optional]
    elevation19: string,
    [@bs.optional]
    elevation20: string,
    [@bs.optional]
    elevation21: string,
    [@bs.optional]
    elevation22: string,
    [@bs.optional]
    elevation23: string,
    [@bs.optional]
    elevation24: string,
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
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~square: option(bool)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "elevation"] `Elevation
                  | [@bs.as "outlined"] `Outlined
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Paper";
