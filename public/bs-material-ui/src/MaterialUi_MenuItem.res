
            
            type alignItems = [ | #\"flex-start" | #center];
          


      module ContainerComponent: {
        type t;
        let string: (string) => t;
let containerComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let containerComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "gutters":option<option<string>>
                ,
                "selected":option<option<string>>
                ,
                "dense":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~gutters:
                  string=?
                  ,
                  ~selected:
                  string=?
                  ,
                  ~dense:
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
      

      module Value: {
        type t;
        let string: (string) => t;
let int: (int) => t;
let float: (float) => t;
let arrayOf: (array<string>) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let arrayOf = (v: array<string>) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/core") external make : (~alignItems: option<alignItems>=?,
~autoFocus: option<bool>=?,
~button: option<bool>=?,
~\"ContainerComponent": option<ContainerComponent.t>=?,
~\"ContainerProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~divider: option<bool>=?,
~focusVisibleClassName: option<string>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~component: option<Component.t>=?,
~dense: option<bool>=?,
~disabled: option<bool>=?,
~disableGutters: option<bool>=?,
~\"ListItemClasses": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~role: option<string>=?,
~selected: option<bool>=?,
~tabIndex: option<MaterialUi_Types.Number.t>=?,
~value: option<Value.t>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~onClick: option<ReactEvent.Mouse.t => unit>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "MenuItem";
        