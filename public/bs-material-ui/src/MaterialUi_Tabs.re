module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    vertical: string,
    [@bs.optional]
    flexContainer: string,
    [@bs.optional]
    flexContainerVertical: string,
    [@bs.optional]
    centered: string,
    [@bs.optional]
    scroller: string,
    [@bs.optional]
    fixed: string,
    [@bs.optional]
    scrollable: string,
    [@bs.optional]
    scrollButtons: string,
    [@bs.optional]
    scrollButtonsDesktop: string,
    [@bs.optional]
    indicator: string,
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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~centered: option(bool)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~indicatorColor: option(
                       [@bs.string] [
                         | [@bs.as "secondary"] `Secondary
                         | [@bs.as "primary"] `Primary
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
                        | [@bs.as "on"] `On
                        | [@bs.as "off"] `Off
                      ],
                    )
                      =?,
    ~_TabIndicatorProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~textColor: option(
                  [@bs.string] [
                    | [@bs.as "secondary"] `Secondary
                    | [@bs.as "primary"] `Primary
                    | [@bs.as "inherit"] `Inherit
                  ],
                )
                  =?,
    ~value: option(MaterialUi_Types.any)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "standard"] `Standard
                  | [@bs.as "scrollable"] `Scrollable
                  | [@bs.as "fullWidth"] `FullWidth
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Tabs";
