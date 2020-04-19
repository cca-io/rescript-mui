module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    head: string,
    [@bs.optional]
    body: string,
    [@bs.optional]
    footer: string,
    [@bs.optional]
    sizeSmall: string,
    [@bs.optional]
    paddingCheckbox: string,
    [@bs.optional]
    paddingNone: string,
    [@bs.optional]
    alignLeft: string,
    [@bs.optional]
    alignCenter: string,
    [@bs.optional]
    alignRight: string,
    [@bs.optional]
    alignJustify: string,
    [@bs.optional]
    stickyHeader: string,
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
    ~colSpan: option(int)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TableCell";
