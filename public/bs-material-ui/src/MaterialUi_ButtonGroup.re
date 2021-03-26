module Classes = {
  type t = {
    .
    "root": option(string),
    "contained": option(string),
    "disableElevation": option(string),
    "disabled": option(string),
    "fullWidth": option(string),
    "vertical": option(string),
    "grouped": option(string),
    "groupedHorizontal": option(string),
    "groupedVertical": option(string),
    "groupedText": option(string),
    "groupedTextHorizontal": option(string),
    "groupedTextVertical": option(string),
    "groupedTextPrimary": option(string),
    "groupedTextSecondary": option(string),
    "groupedOutlined": option(string),
    "groupedOutlinedHorizontal": option(string),
    "groupedOutlinedVertical": option(string),
    "groupedOutlinedPrimary": option(string),
    "groupedOutlinedSecondary": option(string),
    "groupedContained": option(string),
    "groupedContainedHorizontal": option(string),
    "groupedContainedVertical": option(string),
    "groupedContainedPrimary": option(string),
    "groupedContainedSecondary": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~contained: string=?,
      ~disableElevation: string=?,
      ~disabled: string=?,
      ~fullWidth: string=?,
      ~vertical: string=?,
      ~grouped: string=?,
      ~groupedHorizontal: string=?,
      ~groupedVertical: string=?,
      ~groupedText: string=?,
      ~groupedTextHorizontal: string=?,
      ~groupedTextVertical: string=?,
      ~groupedTextPrimary: string=?,
      ~groupedTextSecondary: string=?,
      ~groupedOutlined: string=?,
      ~groupedOutlinedHorizontal: string=?,
      ~groupedOutlinedVertical: string=?,
      ~groupedOutlinedPrimary: string=?,
      ~groupedOutlinedSecondary: string=?,
      ~groupedContained: string=?,
      ~groupedContainedHorizontal: string=?,
      ~groupedContainedVertical: string=?,
      ~groupedContainedPrimary: string=?,
      ~groupedContainedSecondary: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Inherit | `Primary | `Secondary];

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

type orientation = [ | `Horizontal | `Vertical];

type size = [ | `Large | `Medium | `Small];

type variant = [ | `Contained | `Outlined | `Text];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "default"] `Default
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~component: Component.t=?,
    ~disabled: bool=?,
    ~disableElevation: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~fullWidth: bool=?,
    ~orientation: [@bs.string] [
                    | [@bs.as "horizontal"] `Horizontal
                    | [@bs.as "vertical"] `Vertical
                  ]
                    =?,
    ~size: [@bs.string] [
             | [@bs.as "large"] `Large
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
    ~variant: [@bs.string] [
                | [@bs.as "contained"] `Contained
                | [@bs.as "outlined"] `Outlined
                | [@bs.as "text"] `Text
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "ButtonGroup";
