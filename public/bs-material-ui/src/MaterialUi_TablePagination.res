
            
            type align = [ | #center | #\"inherit" | #justify | #left | #right];
          


            type padding = [ | #checkbox | #default | #none];
          

            type size = [ | #medium | #small];
          

                module SortDirection: {
                    type t;
                    let asc: t;
let desc: t;
let \"false": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let asc = Any("asc");
let desc = Any("desc");
let \"false" = Any(false);
                };
                

            type variant = [ | #body | #footer | #head];
          

      module ActionsComponent: {
        type t;
        let string: (string) => t;
let actionsComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let actionsComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "toolbar":option<option<string>>
                ,
                "spacer":option<option<string>>
                ,
                "caption":option<option<string>>
                ,
                "selectRoot":option<option<string>>
                ,
                "select":option<option<string>>
                ,
                "selectIcon":option<option<string>>
                ,
                "input":option<option<string>>
                ,
                "menuItem":option<option<string>>
                ,
                "actions":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~toolbar:
                  string=?
                  ,
                  ~spacer:
                  string=?
                  ,
                  ~caption:
                  string=?
                  ,
                  ~selectRoot:
                  string=?
                  ,
                  ~select:
                  string=?
                  ,
                  ~selectIcon:
                  string=?
                  ,
                  ~input:
                  string=?
                  ,
                  ~menuItem:
                  string=?
                  ,
                  ~actions:
                  string=?
                  
            , unit) => t = "";
          };
      

      module Component: {
        type t;
        let string: (string) => t;
let callback: (unit => React.element) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let callback = (v: unit => React.element) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/core") external make : (~align: option<align>=?,
~children: option<'children>=?,
~padding: option<padding>=?,
~scope: option<string>=?,
~size: option<size>=?,
~sortDirection: option<SortDirection.t>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~\"ActionsComponent": option<ActionsComponent.t>=?,
~backIconButtonProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~backIconButtonText: option<string>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~colSpan: option<MaterialUi_Types.Number.t>=?,
~component: option<Component.t>=?,
~count: MaterialUi_Types.Number.t,
~labelDisplayedRows: option<({. "from": int, "to": int, "count": int}) => string>=?,
~labelRowsPerPage: option<({. "from": int, "to": int, "count": int, "page": int}) => React.element>=?,
~nextIconButtonProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~nextIconButtonText: option<string>=?,
~onChangePage: (ReactEvent.Mouse.t, int) => unit,
~onChangeRowsPerPage: option<(ReactEvent.Form.t) => unit>=?,
~page: option<int>=?,
~rowsPerPage: MaterialUi_Types.Number.t,
~rowsPerPageOptions: option<array<int>>=?,
~\"SelectProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "TablePagination";
        