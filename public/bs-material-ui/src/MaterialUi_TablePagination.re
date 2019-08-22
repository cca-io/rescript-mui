[@bs.deriving jsConverter]
type align = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "left"] `Left
  | [@bs.as "center"] `Center
  | [@bs.as "right"] `Right
  | [@bs.as "justify"] `Justify
];

[@bs.deriving jsConverter]
type padding = [
  | [@bs.as "default"] `Default
  | [@bs.as "checkbox"] `Checkbox
  | [@bs.as "none"] `None
];

[@bs.deriving jsConverter]
type size = [ | [@bs.as "small"] `Small | [@bs.as "medium"] `Medium];

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
external makePropsMui:
  (
    ~_ActionsComponent: 'union_ryl2=?,
    ~backIconButtonProps: Js.t({..})=?,
    ~colSpan: 'number_v=?,
    ~component: 'union_rw9t=?,
    ~count: 'number_a,
    ~labelDisplayedRows: 'labelDisplayedRows=?,
    ~labelRowsPerPage: 'labelRowsPerPage=?,
    ~nextIconButtonProps: Js.t({..})=?,
    ~onChangePage: 'any_r0qy,
    ~onChangeRowsPerPage: 'any_r46z=?,
    ~rowsPerPage: 'number_8,
    ~rowsPerPageOptions: array(int)=?,
    ~_SelectProps: Js.t({..})=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~align: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~padding: string=?,
    ~scope: string=?,
    ~size: string=?,
    ~sortDirection: string=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~_ActionsComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~backIconButtonProps: option(Js.t({..}))=?,
      ~colSpan: option([ | `Int(int) | `Float(float)])=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(ReasonReact.reactElement)
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
      ~rowsPerPage: [ | `Int(int) | `Float(float)],
      ~rowsPerPageOptions: option(array(int))=?,
      ~_SelectProps: option(Js.t({..}))=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~align: option(align)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~padding: option(padding)=?,
      ~scope: option(string)=?,
      ~size: option(size)=?,
      ~sortDirection: option(sortDirection)=?,
      ~variant: option(variant)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
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
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~count=MaterialUi_Helpers.unwrapValue(count),
    ~labelDisplayedRows?,
    ~labelRowsPerPage?,
    ~nextIconButtonProps?,
    ~onChangePage,
    ~onChangeRowsPerPage?,
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
    ~_ref=?ref_,
    ~align=?align->(Belt.Option.map(v => alignToJs(v))),
    ~children?,
    ~className?,
    ~padding=?padding->(Belt.Option.map(v => paddingToJs(v))),
    ~scope?,
    ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
    ~sortDirection=?
      sortDirection->(Belt.Option.map(v => sortDirectionToJs(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "TablePagination";
