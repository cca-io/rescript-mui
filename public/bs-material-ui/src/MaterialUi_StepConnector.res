
            

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
                "active":option<option<string>>
                ,
                "completed":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "line":option<option<string>>
                ,
                "lineHorizontal":option<option<string>>
                ,
                "lineVertical":option<option<string>>
                
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
                  ~active:
                  string=?
                  ,
                  ~completed:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~line:
                  string=?
                  ,
                  ~lineHorizontal:
                  string=?
                  ,
                  ~lineVertical:
                  string=?
                  
            , unit) => t = "";
          };
      

            @react.component @bs.module("@material-ui/core") external make : (~classes: option<Classes.t>=?,
~className: option<string>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "StepConnector";
        