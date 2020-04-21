module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "rounded": option(option(string)),
    "outlined": option(option(string)),
    "elevation0": option(option(string)),
    "elevation1": option(option(string)),
    "elevation2": option(option(string)),
    "elevation3": option(option(string)),
    "elevation4": option(option(string)),
    "elevation5": option(option(string)),
    "elevation6": option(option(string)),
    "elevation7": option(option(string)),
    "elevation8": option(option(string)),
    "elevation9": option(option(string)),
    "elevation10": option(option(string)),
    "elevation11": option(option(string)),
    "elevation12": option(option(string)),
    "elevation13": option(option(string)),
    "elevation14": option(option(string)),
    "elevation15": option(option(string)),
    "elevation16": option(option(string)),
    "elevation17": option(option(string)),
    "elevation18": option(option(string)),
    "elevation19": option(option(string)),
    "elevation20": option(option(string)),
    "elevation21": option(option(string)),
    "elevation22": option(option(string)),
    "elevation23": option(option(string)),
    "elevation24": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~rounded: string=?,
      ~outlined: string=?,
      ~elevation0: string=?,
      ~elevation1: string=?,
      ~elevation2: string=?,
      ~elevation3: string=?,
      ~elevation4: string=?,
      ~elevation5: string=?,
      ~elevation6: string=?,
      ~elevation7: string=?,
      ~elevation8: string=?,
      ~elevation9: string=?,
      ~elevation10: string=?,
      ~elevation11: string=?,
      ~elevation12: string=?,
      ~elevation13: string=?,
      ~elevation14: string=?,
      ~elevation15: string=?,
      ~elevation16: string=?,
      ~elevation17: string=?,
      ~elevation18: string=?,
      ~elevation19: string=?,
      ~elevation20: string=?,
      ~elevation21: string=?,
      ~elevation22: string=?,
      ~elevation23: string=?,
      ~elevation24: string=?,
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

type variant = [ | `Elevation | `Outlined];

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
