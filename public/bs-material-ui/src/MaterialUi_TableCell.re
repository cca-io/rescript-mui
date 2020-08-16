type align = [ | `Center | `Inherit | `Justify | `Left | `Right];

module Classes = {
  type t = {
    .
    "root": option(string),
    "head": option(string),
    "body": option(string),
    "footer": option(string),
    "sizeSmall": option(string),
    "paddingCheckbox": option(string),
    "paddingNone": option(string),
    "alignLeft": option(string),
    "alignCenter": option(string),
    "alignRight": option(string),
    "alignJustify": option(string),
    "stickyHeader": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~head: string=?,
      ~body: string=?,
      ~footer: string=?,
      ~sizeSmall: string=?,
      ~paddingCheckbox: string=?,
      ~paddingNone: string=?,
      ~alignLeft: string=?,
      ~alignCenter: string=?,
      ~alignRight: string=?,
      ~alignJustify: string=?,
      ~stickyHeader: string=?,
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

type padding = [ | `Checkbox | `Default | `None];

type size = [ | `Medium | `Small];

module SortDirection: {
  type t;
  let asc: t;
  let desc: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let asc = Any("asc");
  let desc = Any("desc");
  let _false = Any(false);
};

type variant = [ | `Body | `Footer | `Head];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~align: [@bs.string] [
              | [@bs.as "center"] `Center
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "justify"] `Justify
              | [@bs.as "left"] `Left
              | [@bs.as "right"] `Right
            ]
              =?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~padding: [@bs.string] [
                | [@bs.as "checkbox"] `Checkbox
                | [@bs.as "default"] `Default
                | [@bs.as "none"] `None
              ]
                =?,
    ~scope: string=?,
    ~size: [@bs.string] [
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
    ~sortDirection: SortDirection.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "body"] `Body
                | [@bs.as "footer"] `Footer
                | [@bs.as "head"] `Head
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~colSpan: int=?,
    ~rowSpan: int=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "TableCell";
