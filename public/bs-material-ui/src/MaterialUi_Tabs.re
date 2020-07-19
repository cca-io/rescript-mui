module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "vertical": option(option(string)),
    "flexContainer": option(option(string)),
    "flexContainerVertical": option(option(string)),
    "centered": option(option(string)),
    "scroller": option(option(string)),
    "fixed": option(option(string)),
    "scrollable": option(option(string)),
    "scrollButtons": option(option(string)),
    "scrollButtonsDesktop": option(option(string)),
    "indicator": option(option(string)),
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
    ~aria_label: option(string)=?,
    ~aria_labelledby: option(string)=?,
    ~centered: option(bool)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~indicatorColor: option(
                       [@bs.string] [
                         | [@bs.as "primary"] `Primary
                         | [@bs.as "secondary"] `Secondary
                       ],
                     )
                       =?,
    ~onChange: option((ReactEvent.Form.t, MaterialUi_Types.any) => unit)=?,
    ~orientation: option(
                    [@bs.string] [
                      | [@bs.as "horizontal"] `Horizontal
                      | [@bs.as "vertical"] `Vertical
                    ],
                  )
                    =?,
    ~_ScrollButtonComponent: option(ScrollButtonComponent.t)=?,
    ~scrollButtons: option(
                      [@bs.string] [
                        | [@bs.as "auto"] `Auto
                        | [@bs.as "desktop"] `Desktop
                        | [@bs.as "off"] `Off
                        | [@bs.as "on"] `On
                      ],
                    )
                      =?,
    ~selectionFollowsFocus: option(bool)=?,
    ~_TabIndicatorProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_TabScrollButtonProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~textColor: option(
                  [@bs.string] [
                    | [@bs.as "inherit"] `Inherit
                    | [@bs.as "primary"] `Primary
                    | [@bs.as "secondary"] `Secondary
                  ],
                )
                  =?,
    ~value: option(MaterialUi_Types.any)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "fullWidth"] `FullWidth
                  | [@bs.as "scrollable"] `Scrollable
                  | [@bs.as "standard"] `Standard
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Tabs";
