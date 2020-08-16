
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "alignLeft":option<option<string>>
                ,
                "alignRight":option<option<string>>
                ,
                "alignAlternate":option<option<string>>
                ,
                "missingOppositeContent":option<option<string>>
                ,
                "content":option<option<string>>
                ,
                "oppositeContent":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~alignLeft:
                  string=?
                  ,
                  ~alignRight:
                  string=?
                  ,
                  ~alignAlternate:
                  string=?
                  ,
                  ~missingOppositeContent:
                  string=?
                  ,
                  ~content:
                  string=?
                  ,
                  ~oppositeContent:
                  string=?
                  
            , unit) => t = "";
          };
      

            @react.component @bs.module("@material-ui/lab") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "TimelineItem";
        