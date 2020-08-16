
            

          module Classes = {
            type t = {
              .
              
                "popper":option<option<string>>
                ,
                "popperInteractive":option<option<string>>
                ,
                "popperArrow":option<option<string>>
                ,
                "tooltip":option<option<string>>
                ,
                "tooltipArrow":option<option<string>>
                ,
                "arrow":option<option<string>>
                ,
                "touch":option<option<string>>
                ,
                "tooltipPlacementLeft":option<option<string>>
                ,
                "tooltipPlacementRight":option<option<string>>
                ,
                "tooltipPlacementTop":option<option<string>>
                ,
                "tooltipPlacementBottom":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~popper:
                  string=?
                  ,
                  ~popperInteractive:
                  string=?
                  ,
                  ~popperArrow:
                  string=?
                  ,
                  ~tooltip:
                  string=?
                  ,
                  ~tooltipArrow:
                  string=?
                  ,
                  ~arrow:
                  string=?
                  ,
                  ~touch:
                  string=?
                  ,
                  ~tooltipPlacementLeft:
                  string=?
                  ,
                  ~tooltipPlacementRight:
                  string=?
                  ,
                  ~tooltipPlacementTop:
                  string=?
                  ,
                  ~tooltipPlacementBottom:
                  string=?
                  
            , unit) => t = "";
          };
      

            type placement = [ | #\"bottom-end" | #\"bottom-start" | #bottom | #\"left-end" | #\"left-start" | #left | #\"right-end" | #\"right-start" | #right | #\"top-end" | #\"top-start" | #top];
          

      module PopperComponent: {
        type t;
        let string: (string) => t;
let popperComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let popperComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
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
      

            @react.component @bs.module("@material-ui/core") external make : (~arrow: option<bool>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~disableFocusListener: option<bool>=?,
~disableHoverListener: option<bool>=?,
~disableTouchListener: option<bool>=?,
~enterDelay: option<MaterialUi_Types.Number.t>=?,
~enterNextDelay: option<MaterialUi_Types.Number.t>=?,
~enterTouchDelay: option<MaterialUi_Types.Number.t>=?,
~id: option<string>=?,
~interactive: option<bool>=?,
~leaveDelay: option<MaterialUi_Types.Number.t>=?,
~leaveTouchDelay: option<MaterialUi_Types.Number.t>=?,
~onClose: option<(ReactEvent.Synthetic.t) => unit>=?,
~onOpen: option<(ReactEvent.Synthetic.t) => unit>=?,
~\"open": option<bool>=?,
~placement: option<placement>=?,
~\"PopperComponent": option<PopperComponent.t>=?,
~\"PopperProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~title: React.element,
~\"TransitionComponent": option<TransitionComponent.t>=?,
~\"TransitionProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Tooltip";
        