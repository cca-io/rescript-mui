
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "expanded":option<option<string>>
                ,
                "selected":option<option<string>>
                ,
                "group":option<option<string>>
                ,
                "content":option<option<string>>
                ,
                "iconContainer":option<option<string>>
                ,
                "label":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~expanded:
                  string=?
                  ,
                  ~selected:
                  string=?
                  ,
                  ~group:
                  string=?
                  ,
                  ~content:
                  string=?
                  ,
                  ~iconContainer:
                  string=?
                  ,
                  ~label:
                  string=?
                  
            , unit) => t = "";
          };
      

      module TransitionComponent: {
        type t;
        let string: (string) => t;
let transitionComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let transitionComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/lab") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~collapseIcon: option<React.element>=?,
~endIcon: option<React.element>=?,
~expandIcon: option<React.element>=?,
~icon: option<React.element>=?,
~label: option<React.element>=?,
~nodeId: string,
~onClick: option<ReactEvent.Mouse.t => unit>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~onIconClick: option<MaterialUi_Types.any>=?,
~onKeyDown: option<ReactEvent.Keyboard.t => unit>=?,
~onLabelClick: option<MaterialUi_Types.any>=?,
~onMouseDown: option<ReactEvent.Mouse.t => unit>=?,
~\"TransitionComponent": option<TransitionComponent.t>=?,
~\"TransitionProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "TreeItem";
        