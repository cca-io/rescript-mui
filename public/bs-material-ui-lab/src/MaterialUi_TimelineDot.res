
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "defaultGrey":option<option<string>>
                ,
                "outlinedGrey":option<option<string>>
                ,
                "defaultPrimary":option<option<string>>
                ,
                "outlinedPrimary":option<option<string>>
                ,
                "defaultSecondary":option<option<string>>
                ,
                "outlinedSecondary":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~defaultGrey:
                  string=?
                  ,
                  ~outlinedGrey:
                  string=?
                  ,
                  ~defaultPrimary:
                  string=?
                  ,
                  ~outlinedPrimary:
                  string=?
                  ,
                  ~defaultSecondary:
                  string=?
                  ,
                  ~outlinedSecondary:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #grey | #\"inherit" | #primary | #secondary];
          

            type variant = [ | #default | #outlined];
          

            @react.component @bs.module("@material-ui/lab") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "TimelineDot";
        