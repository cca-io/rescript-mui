
            

      module Component: {
        type t;
        let string: (string) => t;
let callback: (unit => React.element) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let callback = (v: unit => React.element) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            type variant = [ | #elevation | #outlined];
          

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
                  
            , unit) => t = "";
          };
      

            type orientation = [ | #horizontal | #vertical];
          

            @react.component @bs.module("@material-ui/core") external make : (~component: option<Component.t>=?,
~elevation: option<MaterialUi_Types.Number.t>=?,
~square: option<bool>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~activeStep: option<MaterialUi_Types.Number.t>=?,
~alternativeLabel: option<bool>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~connector: option<React.element>=?,
~nonLinear: option<bool>=?,
~orientation: option<orientation>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Stepper";
        