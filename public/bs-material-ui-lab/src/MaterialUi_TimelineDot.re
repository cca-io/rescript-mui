module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "defaultGrey": option(option(string)),
    "outlinedGrey": option(option(string)),
    "defaultPrimary": option(option(string)),
    "outlinedPrimary": option(option(string)),
    "defaultSecondary": option(option(string)),
    "outlinedSecondary": option(option(string)),
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
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "grey"] `Grey
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "default"] `Default
                  | [@bs.as "outlined"] `Outlined
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TimelineDot";
