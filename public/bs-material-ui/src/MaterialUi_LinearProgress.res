
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "colorPrimary":option<option<string>>
                ,
                "colorSecondary":option<option<string>>
                ,
                "determinate":option<option<string>>
                ,
                "indeterminate":option<option<string>>
                ,
                "buffer":option<option<string>>
                ,
                "query":option<option<string>>
                ,
                "dashed":option<option<string>>
                ,
                "dashedColorPrimary":option<option<string>>
                ,
                "dashedColorSecondary":option<option<string>>
                ,
                "bar":option<option<string>>
                ,
                "barColorPrimary":option<option<string>>
                ,
                "barColorSecondary":option<option<string>>
                ,
                "bar1Indeterminate":option<option<string>>
                ,
                "bar1Determinate":option<option<string>>
                ,
                "bar1Buffer":option<option<string>>
                ,
                "bar2Indeterminate":option<option<string>>
                ,
                "bar2Buffer":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~colorPrimary:
                  string=?
                  ,
                  ~colorSecondary:
                  string=?
                  ,
                  ~determinate:
                  string=?
                  ,
                  ~indeterminate:
                  string=?
                  ,
                  ~buffer:
                  string=?
                  ,
                  ~query:
                  string=?
                  ,
                  ~dashed:
                  string=?
                  ,
                  ~dashedColorPrimary:
                  string=?
                  ,
                  ~dashedColorSecondary:
                  string=?
                  ,
                  ~bar:
                  string=?
                  ,
                  ~barColorPrimary:
                  string=?
                  ,
                  ~barColorSecondary:
                  string=?
                  ,
                  ~bar1Indeterminate:
                  string=?
                  ,
                  ~bar1Determinate:
                  string=?
                  ,
                  ~bar1Buffer:
                  string=?
                  ,
                  ~bar2Indeterminate:
                  string=?
                  ,
                  ~bar2Buffer:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #primary | #secondary];
          

            type variant = [ | #buffer | #determinate | #indeterminate | #query];
          

            @react.component @bs.module("@material-ui/core") external make : (~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~value: option<MaterialUi_Types.Number.t>=?,
~valueBuffer: option<MaterialUi_Types.Number.t>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "LinearProgress";
        