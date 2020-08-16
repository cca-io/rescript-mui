
            

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
                "positionFixed":option<option<string>>
                ,
                "positionAbsolute":option<option<string>>
                ,
                "positionSticky":option<option<string>>
                ,
                "positionStatic":option<option<string>>
                ,
                "positionRelative":option<option<string>>
                ,
                "colorDefault":option<option<string>>
                ,
                "colorPrimary":option<option<string>>
                ,
                "colorSecondary":option<option<string>>
                ,
                "colorInherit":option<option<string>>
                ,
                "colorTransparent":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~positionFixed:
                  string=?
                  ,
                  ~positionAbsolute:
                  string=?
                  ,
                  ~positionSticky:
                  string=?
                  ,
                  ~positionStatic:
                  string=?
                  ,
                  ~positionRelative:
                  string=?
                  ,
                  ~colorDefault:
                  string=?
                  ,
                  ~colorPrimary:
                  string=?
                  ,
                  ~colorSecondary:
                  string=?
                  ,
                  ~colorInherit:
                  string=?
                  ,
                  ~colorTransparent:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #default | #\"inherit" | #primary | #secondary | #transparent];
          

            type position = [ | #absolute | #fixed | #relative | #static | #sticky];
          

            @react.component @bs.module("@material-ui/core") external make : (~component: option<Component.t>=?,
~elevation: option<MaterialUi_Types.Number.t>=?,
~square: option<bool>=?,
~variant: option<variant>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~position: option<position>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "AppBar";
        