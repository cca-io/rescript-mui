
            
            type alignItems = [ | #\"flex-start" | #center];
          


          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "container":option<option<string>>
                ,
                "focusVisible":option<option<string>>
                ,
                "dense":option<option<string>>
                ,
                "alignItemsFlexStart":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "divider":option<option<string>>
                ,
                "gutters":option<option<string>>
                ,
                "button":option<option<string>>
                ,
                "secondaryAction":option<option<string>>
                ,
                "selected":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~container:
                  string=?
                  ,
                  ~focusVisible:
                  string=?
                  ,
                  ~dense:
                  string=?
                  ,
                  ~alignItemsFlexStart:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~divider:
                  string=?
                  ,
                  ~gutters:
                  string=?
                  ,
                  ~button:
                  string=?
                  ,
                  ~secondaryAction:
                  string=?
                  ,
                  ~selected:
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
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~component: option<Component.t>=?,
~\"ContainerComponent": option<ContainerComponent.t>=?,
~\"ContainerProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~dense: option<bool>=?,
~disabled: option<bool>=?,
~disableGutters: option<bool>=?,
~divider: option<bool>=?,
~focusVisibleClassName: option<string>=?,
~selected: option<bool>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~value: option<Value.t>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~onClick: option<ReactEvent.Mouse.t => unit>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "ListItem";
        