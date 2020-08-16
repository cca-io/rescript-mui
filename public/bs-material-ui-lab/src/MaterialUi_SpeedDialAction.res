
            

          module Classes = {
            type t = {
              .
              
                "fab":option<option<string>>
                ,
                "fabClosed":option<option<string>>
                ,
                "staticTooltip":option<option<string>>
                ,
                "staticTooltipClosed":option<option<string>>
                ,
                "staticTooltipLabel":option<option<string>>
                ,
                "tooltipPlacementLeft":option<option<string>>
                ,
                "tooltipPlacementRight":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~fab:
                  string=?
                  ,
                  ~fabClosed:
                  string=?
                  ,
                  ~staticTooltip:
                  string=?
                  ,
                  ~staticTooltipClosed:
                  string=?
                  ,
                  ~staticTooltipLabel:
                  string=?
                  ,
                  ~tooltipPlacementLeft:
                  string=?
                  ,
                  ~tooltipPlacementRight:
                  string=?
                  
            , unit) => t = "";
          };
      

            type tooltipPlacement = [ | #\"bottom-end" | #\"bottom-start" | #bottom | #\"left-end" | #\"left-start" | #left | #\"right-end" | #\"right-start" | #right | #\"top-end" | #\"top-start" | #top];
          

            @react.component @bs.module("@material-ui/lab") external make : (~classes: option<Classes.t>=?,
~className: option<string>=?,
~delay: option<MaterialUi_Types.Number.t>=?,
~\"FabProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~icon: option<React.element>=?,
~id: option<string>=?,
~\"open": option<bool>=?,
~\"TooltipClasses": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~tooltipOpen: option<bool>=?,
~tooltipPlacement: option<tooltipPlacement>=?,
~tooltipTitle: option<React.element>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "SpeedDialAction";
        