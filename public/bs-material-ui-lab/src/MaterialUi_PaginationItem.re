module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "page": option(option(string)),
    "sizeSmall": option(option(string)),
    "sizeLarge": option(option(string)),
    "textPrimary": option(option(string)),
    "textSecondary": option(option(string)),
    "outlined": option(option(string)),
    "outlinedPrimary": option(option(string)),
    "outlinedSecondary": option(option(string)),
    "rounded": option(option(string)),
    "ellipsis": option(option(string)),
    "focusVisible": option(option(string)),
    "disabled": option(option(string)),
    "selected": option(option(string)),
    "icon": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~page: string=?,
      ~sizeSmall: string=?,
      ~sizeLarge: string=?,
      ~textPrimary: string=?,
      ~textSecondary: string=?,
      ~outlined: string=?,
      ~outlinedPrimary: string=?,
      ~outlinedSecondary: string=?,
      ~rounded: string=?,
      ~ellipsis: string=?,
      ~focusVisible: string=?,
      ~disabled: string=?,
      ~selected: string=?,
      ~icon: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Standard | `Primary | `Secondary];

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

type shape = [ | `Round | `Rounded];

type size = [ | `Small | `Medium | `Large];

type _type = [
  | `Page
  | `First
  | `Last
  | `Next
  | `Previous
  | `Start_Ellipsis
  | `End_Ellipsis
];

type variant = [ | `Text | `Outlined];

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
