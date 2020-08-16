
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "fab":option<option<string>>
                ,
                "directionUp":option<option<string>>
                ,
                "directionDown":option<option<string>>
                ,
                "directionLeft":option<option<string>>
                ,
                "directionRight":option<option<string>>
                ,
                "actions":option<option<string>>
                ,
                "actionsClosed":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~fab:
                  string=?
                  ,
                  ~directionUp:
                  string=?
                  ,
                  ~directionDown:
                  string=?
                  ,
                  ~directionLeft:
                  string=?
                  ,
                  ~directionRight:
                  string=?
                  ,
                  ~actions:
                  string=?
                  ,
                  ~actionsClosed:
                  string=?
                  
            , unit) => t = "";
          };
      

            type direction = [ | #down | #left | #right | #up];
          

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
      

          module TransitionDuration_shape = {
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
      

      module TransitionDuration: {
        type t;
        let int: (int) => t;
let float: (float) => t;
let shape: (TransitionDuration_shape.t) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let shape = (v: TransitionDuration_shape.t) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/lab") external make : (~ariaLabel: string,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~direction: option<direction>=?,
~\"FabProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~hidden: option<bool>=?,
~icon: option<React.element>=?,
~onBlur: option<ReactEvent.Focus.t => unit>=?,
~onClose: option<(ReactEvent.Synthetic.t, string) => unit>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~onKeyDown: option<ReactEvent.Keyboard.t => unit>=?,
~onMouseEnter: option<ReactEvent.Mouse.t => unit>=?,
~onMouseLeave: option<ReactEvent.Mouse.t => unit>=?,
~onOpen: option<(ReactEvent.Synthetic.t, string) => unit>=?,
~\"open": bool,
~openIcon: option<React.element>=?,
~\"TransitionComponent": option<TransitionComponent.t>=?,
~transitionDuration: option<TransitionDuration.t>=?,
~\"TransitionProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "SpeedDial";
        