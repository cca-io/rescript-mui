
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "docked":option<option<string>>
                ,
                "paper":option<option<string>>
                ,
                "paperAnchorLeft":option<option<string>>
                ,
                "paperAnchorRight":option<option<string>>
                ,
                "paperAnchorTop":option<option<string>>
                ,
                "paperAnchorBottom":option<option<string>>
                ,
                "paperAnchorDockedLeft":option<option<string>>
                ,
                "paperAnchorDockedTop":option<option<string>>
                ,
                "paperAnchorDockedRight":option<option<string>>
                ,
                "paperAnchorDockedBottom":option<option<string>>
                ,
                "modal":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~docked:
                  string=?
                  ,
                  ~paper:
                  string=?
                  ,
                  ~paperAnchorLeft:
                  string=?
                  ,
                  ~paperAnchorRight:
                  string=?
                  ,
                  ~paperAnchorTop:
                  string=?
                  ,
                  ~paperAnchorBottom:
                  string=?
                  ,
                  ~paperAnchorDockedLeft:
                  string=?
                  ,
                  ~paperAnchorDockedTop:
                  string=?
                  ,
                  ~paperAnchorDockedRight:
                  string=?
                  ,
                  ~paperAnchorDockedBottom:
                  string=?
                  ,
                  ~modal:
                  string=?
                  
            , unit) => t = "";
          };
      

            type anchor = [ | #left | #top | #right | #bottom];
          

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
      

          module BackdropProps = {
            type t = {
              .
              
                "component":option<option<Component.t>>
                
            };
            @bs.obj external make: (
              
                  ~component:
                  Component.t=?
                  
            , unit) => t = "";
          };
      

          module ModalProps = {
            type t = {
              .
              
                "BackdropProps":option<option<BackdropProps.t>>
                
            };
            @bs.obj external make: (
              
                  ~\"BackdropProps":
                  BackdropProps.t=?
                  
            , unit) => t = "";
          };
      

          module PaperProps = {
            type t = {
              .
              
                "component":option<option<Component.t>>
                ,
                "style":option<option<Js.Dict.t<MaterialUi_Types.any>>>
                
            };
            @bs.obj external make: (
              
                  ~component:
                  Component.t=?
                  ,
                  ~style:
                  Js.Dict.t<MaterialUi_Types.any>=?
                  
            , unit) => t = "";
          };
      

          module TransitionDuration_shape = {
            type t = {
              .
              
                "enter":option<option<MaterialUi_Types.Number.t>>
                ,
                "exit":option<option<MaterialUi_Types.Number.t>>
                
            };
            @bs.obj external make: (
              
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
      

            type variant = [ | #permanent | #persistent | #temporary];
          

            @react.component @bs.module("@material-ui/core") external make : (~\"BackdropProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~elevation: option<MaterialUi_Types.Number.t>=?,
~\"SlideProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~anchor: option<anchor>=?,
~children: option<'children>=?,
~disableBackdropTransition: option<bool>=?,
~disableDiscovery: option<bool>=?,
~disableSwipeToOpen: option<bool>=?,
~hideBackdrop: option<bool>=?,
~hysteresis: option<MaterialUi_Types.Number.t>=?,
~minFlingVelocity: option<MaterialUi_Types.Number.t>=?,
~\"ModalProps": option<ModalProps.t>=?,
~onClose: (ReactEvent.Synthetic.t) => unit,
~onOpen: (ReactEvent.Synthetic.t) => unit,
~\"open": bool,
~\"PaperProps": option<PaperProps.t>=?,
~\"SwipeAreaProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~swipeAreaWidth: option<MaterialUi_Types.Number.t>=?,
~transitionDuration: option<TransitionDuration.t>=?,
~variant: option<variant>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "SwipeableDrawer";
        