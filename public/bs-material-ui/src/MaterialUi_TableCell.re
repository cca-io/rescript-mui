type align = [ | `Center | `Inherit | `Justify | `Left | `Right];

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "head": option(option(string)),
    "body": option(option(string)),
    "footer": option(option(string)),
    "sizeSmall": option(option(string)),
    "paddingCheckbox": option(option(string)),
    "paddingNone": option(option(string)),
    "alignLeft": option(option(string)),
    "alignCenter": option(option(string)),
    "alignRight": option(option(string)),
    "alignJustify": option(option(string)),
    "stickyHeader": option(option(string)),
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
    ~align: option(
              [@bs.string] [
                | [@bs.as "center"] `Center
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "justify"] `Justify
                | [@bs.as "left"] `Left
                | [@bs.as "right"] `Right
              ],
            )
              =?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~padding: option(
                [@bs.string] [
                  | [@bs.as "checkbox"] `Checkbox
                  | [@bs.as "default"] `Default
                  | [@bs.as "none"] `None
                ],
              )
                =?,
    ~scope: option(string)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~sortDirection: option(SortDirection.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "body"] `Body
                  | [@bs.as "footer"] `Footer
                  | [@bs.as "head"] `Head
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~colSpan: option(int)=?,
    ~rowSpan: option(int)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TableCell";
