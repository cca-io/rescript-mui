
            

          module Classes = {
            type t = {
              .
              
                "container":option<option<string>>
                ,
                "entered":option<option<string>>
                ,
                "hidden":option<option<string>>
                ,
                "wrapper":option<option<string>>
                ,
                "wrapperInner":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~container:
                  string=?
                  ,
                  ~entered:
                  string=?
                  ,
                  ~hidden:
                  string=?
                  ,
                  ~wrapper:
                  string=?
                  ,
                  ~wrapperInner:
                  string=?
                  
            , unit) => t = "";
          };
      

      module CollapsedHeight: {
        type t;
        let int: (int) => t;
let float: (float) => t;
let string: (string) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let string = (v: string) => Any(v);
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
      

                module Timeout_enum: {
                    type t;
                    let auto: t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let auto = Any("auto");
                };
                

          module Timeout_shape = {
            type t = {
              .
              
                "appear":option<option<MaterialUi_Types.Number.t>>
                ,
                "enter":option<option<MaterialUi_Types.Number.t>>
                ,
                "exit":option<option<MaterialUi_Types.Number.t>>
                
            };
            @bs.obj external make: (
              
                  ~appear:
                  MaterialUi_Types.Number.t=?
                  ,
                  ~enter:
                  MaterialUi_Types.Number.t=?
                  ,
                  ~exit:
                  MaterialUi_Types.Number.t=?
                  
            , unit) => t = "";
          };
      

      module Timeout: {
        type t;
        let enum: (Timeout_enum.t) => t;
let int: (int) => t;
let float: (float) => t;
let shape: (Timeout_shape.t) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let enum = (v: Timeout_enum.t) => Any(v);
let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let shape = (v: Timeout_shape.t) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~collapsedHeight: option<CollapsedHeight.t>=?,
~component: option<Component.t>=?,
~disableStrictModeCompat: option<bool>=?,
~\"in": option<bool>=?,
~onEnter: option<ReactEvent.Synthetic.t => unit>=?,
~onEntered: option<ReactEvent.Synthetic.t => unit>=?,
~onEntering: option<ReactEvent.Synthetic.t => unit>=?,
~onExit: option<ReactEvent.Synthetic.t => unit>=?,
~onExited: option<ReactEvent.Synthetic.t => unit>=?,
~onExiting: option<ReactEvent.Synthetic.t => unit>=?,
~style: option<ReactDOMRe.Style.t>=?,
~timeout: option<Timeout.t>=?,
~id: option<string>=?,
~mountOnEnter: option<bool>=?,
~unmountOnExit: option<bool>=?,
~appear: option<bool>=?,
~enter: option<bool>=?,
~exit: option<bool>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Collapse";
        