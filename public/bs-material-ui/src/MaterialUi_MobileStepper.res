
            

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
      

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "positionBottom":option<option<string>>
                ,
                "positionTop":option<option<string>>
                ,
                "positionStatic":option<option<string>>
                ,
                "dots":option<option<string>>
                ,
                "dot":option<option<string>>
                ,
                "dotActive":option<option<string>>
                ,
                "progress":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~positionBottom:
                  string=?
                  ,
                  ~positionTop:
                  string=?
                  ,
                  ~positionStatic:
                  string=?
                  ,
                  ~dots:
                  string=?
                  ,
                  ~dot:
                  string=?
                  ,
                  ~dotActive:
                  string=?
                  ,
                  ~progress:
                  string=?
                  
            , unit) => t = "";
          };
      

            type position = [ | #bottom | #static | #top];
          

            type variant = [ | #dots | #progress | #text];
          

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~component: option<Component.t>=?,
~elevation: option<MaterialUi_Types.Number.t>=?,
~square: option<bool>=?,
~activeStep: option<MaterialUi_Types.Number.t>=?,
~backButton: option<React.element>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~\"LinearProgressProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~nextButton: option<React.element>=?,
~position: option<position>=?,
~steps: MaterialUi_Types.Number.t,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "MobileStepper";
        