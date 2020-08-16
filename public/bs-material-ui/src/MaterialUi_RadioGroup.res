
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "row":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~row:
                  string=?
                  
            , unit) => t = "";
          };
      

      module DefaultValue: {
        type t;
        let arrayOf: (array<string>) => t;
let int: (int) => t;
let float: (float) => t;
let string: (string) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let arrayOf = (v: array<string>) => Any(v);
let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let string = (v: string) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/core") external make : (~classes: option<Classes.t>=?,
~className: option<string>=?,
~row: option<bool>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~children: option<'children>=?,
~defaultValue: option<DefaultValue.t>=?,
~name: option<string>=?,
~onChange: option<(ReactEvent.Form.t) => unit>=?,
~value: option<MaterialUi_Types.any>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "RadioGroup";
        