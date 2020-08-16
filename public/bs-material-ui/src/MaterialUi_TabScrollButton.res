
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "vertical":option<option<string>>
                ,
                "disabled":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~vertical:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  
            , unit) => t = "";
          };
      

            type direction = [ | #left | #right];
          

            type orientation = [ | #horizontal | #vertical];
          

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~direction: direction,
~disabled: option<bool>=?,
~orientation: orientation,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "TabScrollButton";
        