module Classes = {
  type t = {
    .
    "root": option(string),
    "page": option(string),
    "sizeSmall": option(string),
    "sizeLarge": option(string),
    "textPrimary": option(string),
    "textSecondary": option(string),
    "outlined": option(string),
    "outlinedPrimary": option(string),
    "outlinedSecondary": option(string),
    "rounded": option(string),
    "ellipsis": option(string),
    "focusVisible": option(string),
    "disabled": option(string),
    "selected": option(string),
    "icon": option(string),
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
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "standard"] `Standard
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~component: Component.t=?,
    ~disabled: bool=?,
    ~page: MaterialUi_Types.Number.t=?,
    ~selected: bool=?,
    ~shape: [@bs.string] [
              | [@bs.as "round"] `Round
              | [@bs.as "rounded"] `Rounded
            ]
              =?,
    ~size: [@bs.string] [
             | [@bs.as "small"] `Small
             | [@bs.as "medium"] `Medium
             | [@bs.as "large"] `Large
           ]
             =?,
    ~_type: [@bs.string] [
              | [@bs.as "page"] `Page
              | [@bs.as "first"] `First
              | [@bs.as "last"] `Last
              | [@bs.as "next"] `Next
              | [@bs.as "previous"] `Previous
              | [@bs.as "start-ellipsis"] `Start_Ellipsis
              | [@bs.as "end-ellipsis"] `End_Ellipsis
            ]
              =?,
    ~variant: [@bs.string] [
                | [@bs.as "text"] `Text
                | [@bs.as "outlined"] `Outlined
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "PaginationItem";
