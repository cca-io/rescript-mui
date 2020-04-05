[@bs.deriving jsConverter]
type align = [
  | [@bs.as "center"] `Center
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "justify"] `Justify
  | [@bs.as "left"] `Left
  | [@bs.as "right"] `Right
];

[@bs.deriving jsConverter]
type padding = [
  | [@bs.as "checkbox"] `Checkbox
  | [@bs.as "default"] `Default
  | [@bs.as "none"] `None
];

[@bs.deriving jsConverter]
type size = [ | [@bs.as "medium"] `Medium | [@bs.as "small"] `Small];

[@bs.deriving jsConverter]
type sortDirection = [
  | [@bs.as "asc"] `Asc
  | [@bs.as "desc"] `Desc
  | [@bs.as "false"] `False
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "body"] `Body
  | [@bs.as "footer"] `Footer
  | [@bs.as "head"] `Head
];

module Classes = {
  type classesType =
    | Root(string)
    | Toolbar(string)
    | Spacer(string)
    | Caption(string)
    | SelectRoot(string)
    | Select(string)
    | SelectIcon(string)
    | Input(string)
    | MenuItem(string)
    | Actions(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Toolbar(_) => "toolbar"
    | Spacer(_) => "spacer"
    | Caption(_) => "caption"
    | SelectRoot(_) => "selectRoot"
    | Select(_) => "select"
    | SelectIcon(_) => "selectIcon"
    | Input(_) => "input"
    | MenuItem(_) => "menuItem"
    | Actions(_) => "actions";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Toolbar(className)
                         | Spacer(className)
                         | Caption(className)
                         | SelectRoot(className)
                         | Select(className)
                         | SelectIcon(className)
                         | Input(className)
                         | MenuItem(className)
                         | Actions(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~align: string=?,
    ~children: 'children=?,
    ~padding: string=?,
    ~scope: string=?,
    ~size: string=?,
    ~sortDirection: string=?,
    ~variant: string=?,
    ~id: string=?,
    ~_ActionsComponent: 'union_rbc6=?,
    ~backIconButtonProps: Js.t({..})=?,
    ~backIconButtonText: string=?,
    ~className: string=?,
    ~colSpan: 'number_y=?,
    ~component: 'union_rp6f=?,
    ~count: 'number_r,
    ~labelDisplayedRows: 'labelDisplayedRows=?,
    ~labelRowsPerPage: 'labelRowsPerPage=?,
    ~nextIconButtonProps: Js.t({..})=?,
    ~nextIconButtonText: string=?,
    ~onChangePage: 'any_rvix,
    ~onChangeRowsPerPage: 'any_rqzz=?,
    ~page: int=?,
    ~rowsPerPage: 'number_g,
    ~rowsPerPageOptions: array(int)=?,
    ~_SelectProps: Js.t({..})=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~align: option(align)=?,
      ~children: option('children)=?,
      ~padding: option(padding)=?,
      ~scope: option(string)=?,
      ~size: option(size)=?,
      ~sortDirection: option(sortDirection)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
      ~_ActionsComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~backIconButtonProps: option(Js.t({..}))=?,
      ~backIconButtonText: option(string)=?,
      ~className: option(string)=?,
      ~colSpan: option([ | `Int(int) | `Float(float)])=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~count: [ | `Int(int) | `Float(float)],
      ~labelDisplayedRows:
         option(
           {
             .
             "from": int,
             "to": int,
             "count": int,
           } =>
           string,
         )=?,
      ~labelRowsPerPage:
         option(
           {
             .
             "from": int,
             "to": int,
             "count": int,
             "page": int,
           } =>
           React.element,
         )=?,
      ~nextIconButtonProps: option(Js.t({..}))=?,
      ~nextIconButtonText: option(string)=?,
      ~onChangePage: (ReactEvent.Mouse.t, int) => unit,
      ~onChangeRowsPerPage: option(ReactEvent.Form.t => unit)=?,
      ~page: option(int)=?,
      ~rowsPerPage: [ | `Int(int) | `Float(float)],
      ~rowsPerPageOptions: option(array(int))=?,
      ~_SelectProps: option(Js.t({..}))=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~align=?align->(Belt.Option.map(v => alignToJs(v))),
    ~children?,
    ~padding=?padding->(Belt.Option.map(v => paddingToJs(v))),
    ~scope?,
    ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
    ~sortDirection=?
      sortDirection->(Belt.Option.map(v => sortDirectionToJs(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~id?,
    ~_ActionsComponent=?
      _ActionsComponent->(
                           Belt.Option.map(v =>
                             MaterialUi_Helpers.unwrapValue(v)
                           )
                         ),
    ~backIconButtonProps?,
    ~backIconButtonText?,
    ~className?,
    ~colSpan=?
      colSpan->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~count=MaterialUi_Helpers.unwrapValue(count),
    ~labelDisplayedRows?,
    ~labelRowsPerPage?,
    ~nextIconButtonProps?,
    ~nextIconButtonText?,
    ~onChangePage,
    ~onChangeRowsPerPage?,
    ~page?,
    ~rowsPerPage=MaterialUi_Helpers.unwrapValue(rowsPerPage),
    ~rowsPerPageOptions=?
      rowsPerPageOptions->(
                            Belt.Option.map(v =>
                              v->(
                                   Belt.Array.map(item =>
                                     MaterialUi_Helpers.toJsUnsafe(item)
                                   )
                                 )
                            )
                          ),
    ~_SelectProps?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "TablePagination";
