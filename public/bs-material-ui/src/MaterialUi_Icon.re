module Classes = {
  type t = {
    .
    "root": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "colorAction": option(string),
    "colorError": option(string),
    "colorDisabled": option(string),
    "fontSizeInherit": option(string),
    "fontSizeSmall": option(string),
    "fontSizeLarge": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~colorAction: string=?,
      ~colorError: string=?,
      ~colorDisabled: string=?,
      ~fontSizeInherit: string=?,
      ~fontSizeSmall: string=?,
      ~fontSizeLarge: string=?,
      unit
    ) =>
    t;
};

type color = [
  | `Inherit
  | `Primary
  | `Secondary
  | `Action
  | `Error
  | `Disabled
];

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

type fontSize = [ | `Inherit | `Default | `Small | `Large];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
              | [@bs.as "action"] `Action
              | [@bs.as "error"] `Error
              | [@bs.as "disabled"] `Disabled
            ]
              =?,
    ~component: Component.t=?,
    ~fontSize: [@bs.string] [
                 | [@bs.as "inherit"] `Inherit
                 | [@bs.as "default"] `Default
                 | [@bs.as "small"] `Small
                 | [@bs.as "large"] `Large
               ]
                 =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Icon";
