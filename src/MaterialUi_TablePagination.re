[@bs.deriving jsConverter]
type padding = [
  | [@bs.as "default"] `Default
  | [@bs.as "checkbox"] `Checkbox
  | [@bs.as "dense"] `Dense
  | [@bs.as "none"] `None
];

[@bs.deriving jsConverter]
type sortDirection = [
  | [@bs.as "asc"] `Asc
  | [@bs.as "desc"] `Desc
  | [@bs.as "false"] `False
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "head"] `Head
  | [@bs.as "body"] `Body
  | [@bs.as "footer"] `Footer
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
external makeProps:
  (
    ~_ActionsComponent: 'union_r2i9=?,
    ~backIconButtonProps: Js.t({..})=?,
    ~colSpan: 'number_d=?,
    ~component: 'union_ru3q=?,
    ~count: 'number_a,
    ~labelDisplayedRows: 'labelDisplayedRows=?,
    ~labelRowsPerPage: 'labelRowsPerPage=?,
    ~nextIconButtonProps: Js.t({..})=?,
    ~onChangePage: 'any_rb8t,
    ~onChangeRowsPerPage: 'any_rdyh=?,
    ~page: 'number_0,
    ~rowsPerPage: 'number_4,
    ~rowsPerPageOptions: array(int)=?,
    ~_SelectProps: Js.t({..})=?,
    ~className: string=?,
    ~numeric: bool=?,
    ~padding: string=?,
    ~scope: string=?,
    ~sortDirection: string=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "TablePagination";
let make =
    (
      ~_ActionsComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~backIconButtonProps: option(Js.t({..}))=?,
      ~colSpan: option([ | `Int(int) | `Float(float)])=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
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
           ReasonReact.reactElement,
         )=?,
      ~nextIconButtonProps: option(Js.t({..}))=?,
      ~onChangePage: (ReactEvent.Mouse.t, int) => unit,
      ~onChangeRowsPerPage: option(ReactEvent.Form.t => unit)=?,
      ~page: [ | `Int(int) | `Float(float)],
      ~rowsPerPage: [ | `Int(int) | `Float(float)],
      ~rowsPerPageOptions: option(array(int))=?,
      ~_SelectProps: option(Js.t({..}))=?,
      ~className: option(string)=?,
      ~numeric: option(bool)=?,
      ~padding: option(padding)=?,
      ~scope: option(string)=?,
      ~sortDirection: option(sortDirection)=?,
      ~variant: option(variant)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_ActionsComponent=?
          _ActionsComponent->(
                               Belt.Option.map(v =>
                                 MaterialUi_Helpers.unwrapValue(v)
                               )
                             ),
        ~backIconButtonProps?,
        ~colSpan=?
          colSpan->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~component=?
          component->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~count=MaterialUi_Helpers.unwrapValue(count),
        ~labelDisplayedRows?,
        ~labelRowsPerPage?,
        ~nextIconButtonProps?,
        ~onChangePage,
        ~onChangeRowsPerPage?,
        ~page=MaterialUi_Helpers.unwrapValue(page),
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
        ~className?,
        ~numeric?,
        ~padding=?padding->(Belt.Option.map(v => paddingToJs(v))),
        ~scope?,
        ~sortDirection=?
          sortDirection->(Belt.Option.map(v => sortDirectionToJs(v))),
        ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
