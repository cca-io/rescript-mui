module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    colorPrimary: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    colorAction: string,
    [@bs.optional]
    colorError: string,
    [@bs.optional]
    colorDisabled: string,
    [@bs.optional]
    fontSizeInherit: string,
    [@bs.optional]
    fontSizeSmall: string,
    [@bs.optional]
    fontSizeLarge: string,
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
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
                | [@bs.as "action"] `Action
                | [@bs.as "error"] `Error
                | [@bs.as "disabled"] `Disabled
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~fontSize: option(
                 [@bs.string] [
                   | [@bs.as "inherit"] `Inherit
                   | [@bs.as "default"] `Default
                   | [@bs.as "small"] `Small
                   | [@bs.as "large"] `Large
                 ],
               )
                 =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Icon";
