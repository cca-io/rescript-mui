
            
            type anchor = [ | #bottom | #left | #right | #top];
          


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
      

            type variant = [ | #permanent | #persistent | #temporary];
          

            @react.component @bs.module("@material-ui/core") external make : (~anchor: option<anchor>=?,
~\"BackdropProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~elevation: option<MaterialUi_Types.Number.t>=?,
~\"ModalProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~onClose: option<(ReactEvent.Synthetic.t) => unit>=?,
~\"open": option<bool>=?,
~\"PaperProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~\"SlideProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~transitionDuration: option<TransitionDuration.t>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Drawer";
        