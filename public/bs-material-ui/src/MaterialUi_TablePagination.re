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
    "root": option(string),
    "toolbar": option(string),
    "spacer": option(string),
    "caption": option(string),
    "selectRoot": option(string),
    "select": option(string),
    "selectIcon": option(string),
    "input": option(string),
    "menuItem": option(string),
    "actions": option(string),
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
    ~align: [@bs.string] [
              | [@bs.as "center"] `Center
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "justify"] `Justify
              | [@bs.as "left"] `Left
              | [@bs.as "right"] `Right
            ]
              =?,
    ~children: 'children=?,
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
    ~_ActionsComponent: ActionsComponent.t=?,
    ~backIconButtonProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~backIconButtonText: string=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~colSpan: MaterialUi_Types.Number.t=?,
    ~component: Component.t=?,
    ~count: MaterialUi_Types.Number.t,
    ~labelDisplayedRows: {
                           .
                           "from": int,
                           "to": int,
                           "count": int,
                         } =>
                         string
                           =?,
    ~labelRowsPerPage: {
                         .
                         "from": int,
                         "to": int,
                         "count": int,
                         "page": int,
                       } =>
                       React.element
                         =?,
    ~nextIconButtonProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~nextIconButtonText: string=?,
    ~onChangePage: (ReactEvent.Mouse.t, int) => unit,
    ~onChangeRowsPerPage: ReactEvent.Form.t => unit=?,
    ~page: int=?,
    ~rowsPerPage: MaterialUi_Types.Number.t,
    ~rowsPerPageOptions: array(int)=?,
    ~_SelectProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "TablePagination";
