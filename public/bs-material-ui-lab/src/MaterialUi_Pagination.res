
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "ul":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~ul:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #primary | #secondary | #standard];
          

            type shape = [ | #round | #rounded];
          

            type size = [ | #large | #medium | #small];
          

            type variant = [ | #outlined | #text];
          

            @react.component @bs.module("@material-ui/lab") external make : (~boundaryCount: option<MaterialUi_Types.Number.t>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~count: option<MaterialUi_Types.Number.t>=?,
~defaultPage: option<MaterialUi_Types.Number.t>=?,
~disabled: option<bool>=?,
~getItemAriaLabel: option<(string, int, bool) => string>=?,
~hideNextButton: option<bool>=?,
~hidePrevButton: option<bool>=?,
~onChange: option<(ReactEvent.Form.t, int) => unit>=?,
~page: option<MaterialUi_Types.Number.t>=?,
~renderItem: option<unit => MaterialUi_Types.any>=?,
~shape: option<shape>=?,
~showFirstButton: option<bool>=?,
~showLastButton: option<bool>=?,
~siblingCount: option<MaterialUi_Types.Number.t>=?,
~size: option<size>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Pagination";
        