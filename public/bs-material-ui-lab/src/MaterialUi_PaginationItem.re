module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    page: string,
    [@bs.optional]
    sizeSmall: string,
    [@bs.optional]
    sizeLarge: string,
    [@bs.optional]
    textPrimary: string,
    [@bs.optional]
    textSecondary: string,
    [@bs.optional]
    outlined: string,
    [@bs.optional]
    outlinedPrimary: string,
    [@bs.optional]
    outlinedSecondary: string,
    [@bs.optional]
    rounded: string,
    [@bs.optional]
    ellipsis: string,
    [@bs.optional]
    focusVisible: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    selected: string,
    [@bs.optional]
    icon: string,
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

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "standard"] `Standard
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~disabled: option(bool)=?,
    ~page: option(MaterialUi_Types.Number.t)=?,
    ~selected: option(bool)=?,
    ~shape: option(
              [@bs.string] [
                | [@bs.as "round"] `Round
                | [@bs.as "rounded"] `Rounded
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
    ~_type: option(
              [@bs.string] [
                | [@bs.as "page"] `Page
                | [@bs.as "first"] `First
                | [@bs.as "last"] `Last
                | [@bs.as "next"] `Next
                | [@bs.as "previous"] `Previous
                | [@bs.as "start-ellipsis"] `Start_Ellipsis
                | [@bs.as "end-ellipsis"] `End_Ellipsis
              ],
            )
              =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "text"] `Text
                  | [@bs.as "outlined"] `Outlined
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "PaginationItem";
