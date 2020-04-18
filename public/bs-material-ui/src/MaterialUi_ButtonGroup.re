module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    contained: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    fullWidth: string,
    [@bs.optional]
    vertical: string,
    [@bs.optional]
    grouped: string,
    [@bs.optional]
    groupedHorizontal: string,
    [@bs.optional]
    groupedVertical: string,
    [@bs.optional]
    groupedText: string,
    [@bs.optional]
    groupedTextHorizontal: string,
    [@bs.optional]
    groupedTextVertical: string,
    [@bs.optional]
    groupedTextPrimary: string,
    [@bs.optional]
    groupedTextSecondary: string,
    [@bs.optional]
    groupedOutlined: string,
    [@bs.optional]
    groupedOutlinedHorizontal: string,
    [@bs.optional]
    groupedOutlinedVertical: string,
    [@bs.optional]
    groupedOutlinedPrimary: string,
    [@bs.optional]
    groupedOutlinedSecondary: string,
    [@bs.optional]
    groupedContained: string,
    [@bs.optional]
    groupedContainedHorizontal: string,
    [@bs.optional]
    groupedContainedVertical: string,
    [@bs.optional]
    groupedContainedPrimary: string,
    [@bs.optional]
    groupedContainedSecondary: string,
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
    ~color: option(
              [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~disabled: option(bool)=?,
    ~disableFocusRipple: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~orientation: option(
                    [@bs.string] [
                      | [@bs.as "vertical"] `Vertical
                      | [@bs.as "horizontal"] `Horizontal
                    ],
                  )
                    =?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "small"] `Small
               | [@bs.as "medium"] `Medium
               | [@bs.as "large"] `Large
             ],
           )
             =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "text"] `Text
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "contained"] `Contained
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ButtonGroup";
