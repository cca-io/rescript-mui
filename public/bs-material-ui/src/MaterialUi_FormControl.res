
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "marginNormal":option<option<string>>
                ,
                "marginDense":option<option<string>>
                ,
                "fullWidth":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~marginNormal:
                  string=?
                  ,
                  ~marginDense:
                  string=?
                  ,
                  ~fullWidth:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #primary | #secondary];
          

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
      

            type margin = [ | #dense | #none | #normal];
          

            type size = [ | #medium | #small];
          

            type variant = [ | #filled | #outlined | #standard];
          

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~component: option<Component.t>=?,
~disabled: option<bool>=?,
~error: option<bool>=?,
~focused: option<bool>=?,
~fullWidth: option<bool>=?,
~hiddenLabel: option<bool>=?,
~margin: option<margin>=?,
~required: option<bool>=?,
~size: option<size>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "FormControl";
        