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
    | MenuItem(string)
    | Caption(string)
    | Input(string)
    | SelectRoot(string)
    | Select(string)
    | SelectIcon(string)
    | Actions(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Toolbar(_) => "toolbar"
    | Spacer(_) => "spacer"
    | MenuItem(_) => "menuItem"
    | Caption(_) => "caption"
    | Input(_) => "input"
    | SelectRoot(_) => "selectRoot"
    | Select(_) => "select"
    | SelectIcon(_) => "selectIcon"
    | Actions(_) => "actions";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Toolbar(className)
             | Spacer(className)
             | MenuItem(className)
             | Caption(className)
             | Input(className)
             | SelectRoot(className)
             | Select(className)
             | SelectIcon(className)
             | Actions(className) =>
               Js.Dict.set(obj, to_string(classType), className)
             };
             obj;
           },
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~_ActionsComponent: 'union_ryyo=?,
    ~backIconButtonProps: Js.t({..})=?,
    ~colSpan: 'number_a=?,
    ~component: 'union_rry3=?,
    ~count: 'number_h,
    ~labelDisplayedRows: 'labelDisplayedRows=?,
    ~labelRowsPerPage: 'labelRowsPerPage=?,
    ~nextIconButtonProps: Js.t({..})=?,
    ~onChangePage: 'any_rkko,
    ~onChangeRowsPerPage: 'any_rxo2=?,
    ~page: 'number_6,
    ~rowsPerPage: 'number_w,
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

[@bs.module "@material-ui/core/TablePagination/TablePagination"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~_ActionsComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~backIconButtonProps: option(Js.t({..}))=?,
      ~colSpan: option([ | `Int(int) | `Float(float)])=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
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
      ~onChangePage: (ReactEventRe.Mouse.t, int) => unit,
      ~onChangeRowsPerPage: option(ReactEventRe.Form.t => unit)=?,
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
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            _ActionsComponent,
          ),
        ~backIconButtonProps?,
        ~colSpan=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            colSpan,
          ),
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
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
          Js.Option.map(
            (. v) =>
              Js.Array.map(item => MaterialUi_Helpers.toJsUnsafe(item), v),
            rowsPerPageOptions,
          ),
        ~_SelectProps?,
        ~className?,
        ~numeric?,
        ~padding=?Js.Option.map((. v) => paddingToJs(v), padding),
        ~scope?,
        ~sortDirection=?
          Js.Option.map((. v) => sortDirectionToJs(v), sortDirection),
        ~variant=?Js.Option.map((. v) => variantToJs(v), variant),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
