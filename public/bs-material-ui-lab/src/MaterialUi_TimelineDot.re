module Classes = {
  type t = {
    .
    "root": option(string),
    "defaultGrey": option(string),
    "outlinedGrey": option(string),
    "defaultPrimary": option(string),
    "outlinedPrimary": option(string),
    "defaultSecondary": option(string),
    "outlinedSecondary": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~defaultGrey: string=?,
      ~outlinedGrey: string=?,
      ~defaultPrimary: string=?,
      ~outlinedPrimary: string=?,
      ~defaultSecondary: string=?,
      ~outlinedSecondary: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Grey | `Inherit | `Primary | `Secondary];

type variant = [ | `Default | `Outlined];

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "grey"] `Grey
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~variant: [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "outlined"] `Outlined
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "TimelineDot";
