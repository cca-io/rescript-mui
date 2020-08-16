
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "horizontal":option<option<string>>
                ,
                "vertical":option<option<string>>
                ,
                "label":option<option<string>>
                ,
                "active":option<option<string>>
                ,
                "completed":option<option<string>>
                ,
                "error":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "iconContainer":option<option<string>>
                ,
                "alternativeLabel":option<option<string>>
                ,
                "labelContainer":option<option<string>>
                
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
                  ~label:
                  string=?
                  ,
                  ~active:
                  string=?
                  ,
                  ~completed:
                  string=?
                  ,
                  ~error:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~iconContainer:
                  string=?
                  ,
                  ~alternativeLabel:
                  string=?
                  ,
                  ~labelContainer:
                  string=?
                  
            , unit) => t = "";
          };
      

      module StepIconComponent: {
        type t;
        let string: (string) => t;
let stepIconComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let stepIconComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~disabled: option<bool>=?,
~error: option<bool>=?,
~icon: option<React.element>=?,
~optional: option<React.element>=?,
~\"StepIconComponent": option<StepIconComponent.t>=?,
~\"StepIconProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "StepLabel";
        