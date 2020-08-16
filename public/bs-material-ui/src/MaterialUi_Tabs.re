module Classes = {
  type t = {
    .
    "root": option(string),
    "vertical": option(string),
    "flexContainer": option(string),
    "flexContainerVertical": option(string),
    "centered": option(string),
    "scroller": option(string),
    "fixed": option(string),
    "scrollable": option(string),
    "scrollButtons": option(string),
    "scrollButtonsDesktop": option(string),
    "indicator": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~vertical: string=?,
      ~flexContainer: string=?,
      ~flexContainerVertical: string=?,
      ~centered: string=?,
      ~scroller: string=?,
      ~fixed: string=?,
      ~scrollable: string=?,
      ~scrollButtons: string=?,
      ~scrollButtonsDesktop: string=?,
      ~indicator: string=?,
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

type indicatorColor = [ | `Primary | `Secondary];

type orientation = [ | `Horizontal | `Vertical];

module ScrollButtonComponent: {
  type t;
  let string: string => t;
  let scrollButtonComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let scrollButtonComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

type scrollButtons = [ | `Auto | `Desktop | `Off | `On];

type textColor = [ | `Inherit | `Primary | `Secondary];

type variant = [ | `FullWidth | `Scrollable | `Standard];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~aria_label: string=?,
    ~aria_labelledby: string=?,
    ~centered: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~indicatorColor: [@bs.string] [
                       | [@bs.as "primary"] `Primary
                       | [@bs.as "secondary"] `Secondary
                     ]
                       =?,
    ~onChange: (ReactEvent.Form.t, MaterialUi_Types.any) => unit=?,
    ~orientation: [@bs.string] [
                    | [@bs.as "horizontal"] `Horizontal
                    | [@bs.as "vertical"] `Vertical
                  ]
                    =?,
    ~_ScrollButtonComponent: ScrollButtonComponent.t=?,
    ~scrollButtons: [@bs.string] [
                      | [@bs.as "auto"] `Auto
                      | [@bs.as "desktop"] `Desktop
                      | [@bs.as "off"] `Off
                      | [@bs.as "on"] `On
                    ]
                      =?,
    ~selectionFollowsFocus: bool=?,
    ~_TabIndicatorProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~_TabScrollButtonProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~textColor: [@bs.string] [
                  | [@bs.as "inherit"] `Inherit
                  | [@bs.as "primary"] `Primary
                  | [@bs.as "secondary"] `Secondary
                ]
                  =?,
    ~value: MaterialUi_Types.any=?,
    ~variant: [@bs.string] [
                | [@bs.as "fullWidth"] `FullWidth
                | [@bs.as "scrollable"] `Scrollable
                | [@bs.as "standard"] `Standard
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Tabs";
