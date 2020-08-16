
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "horizontal":option<option<string>>
                ,
                "vertical":option<option<string>>
                ,
                "alternativeLabel":option<option<string>>
                ,
                "completed":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~horizontal:
                  string=?
                  ,
                  ~vertical:
                  string=?
                  ,
                  ~alternativeLabel:
                  string=?
                  ,
                  ~completed:
                  string=?
                  
            , unit) => t = "";
          };
      

            @react.component @bs.module("@material-ui/core") external make : (~active: option<bool>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~completed: option<bool>=?,
~disabled: option<bool>=?,
~expanded: option<bool>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Step";
        