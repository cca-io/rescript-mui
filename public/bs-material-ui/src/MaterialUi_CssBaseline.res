
            

          module Classes = {
            type t = {
              .
              
                "@global":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~\"@global":
                  string=?
                  
            , unit) => t = "";
          };
      

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "CssBaseline";
        