type align = [ | `Center | `Inherit | `Justify | `Left | `Right];

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

module ActionsComponent: {
  type t;
  let string: string => t;
  let actionsComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let actionsComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "toolbar": option(option(string)),
    "spacer": option(option(string)),
    "caption": option(option(string)),
    "selectRoot": option(option(string)),
    "select": option(option(string)),
    "selectIcon": option(option(string)),
    "input": option(option(string)),
    "menuItem": option(option(string)),
    "actions": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~toolbar: string=?,
      ~spacer: string=?,
      ~caption: string=?,
      ~selectRoot: string=?,
      ~select: string=?,
      ~selectIcon: string=?,
      ~input: string=?,
      ~menuItem: string=?,
      ~actions: string=?,
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
    ~_ActionsComponent: option(ActionsComponent.t)=?,
    ~backIconButtonProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~backIconButtonText: option(string)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~colSpan: option(MaterialUi_Types.Number.t)=?,
    ~component: option(Component.t)=?,
    ~count: MaterialUi_Types.Number.t,
    ~labelDisplayedRows: option(
                           {
                             .
                             "from": int,
                             "to": int,
                             "count": int,
                           } =>
                           string,
                         )
                           =?,
    ~labelRowsPerPage: option(
                         {
                           .
                           "from": int,
                           "to": int,
                           "count": int,
                           "page": int,
                         } =>
                         React.element,
                       )
                         =?,
    ~nextIconButtonProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~nextIconButtonText: option(string)=?,
    ~onChangePage: (ReactEvent.Mouse.t, int) => unit,
    ~onChangeRowsPerPage: option(ReactEvent.Form.t => unit)=?,
    ~page: option(int)=?,
    ~rowsPerPage: MaterialUi_Types.Number.t,
    ~rowsPerPageOptions: option(array(int))=?,
    ~_SelectProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TablePagination";
