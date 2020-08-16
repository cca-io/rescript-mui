
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "colorPrimary":option<option<string>>
                ,
                "colorSecondary":option<option<string>>
                ,
                "colorAction":option<option<string>>
                ,
                "colorError":option<option<string>>
                ,
                "colorDisabled":option<option<string>>
                ,
                "fontSizeInherit":option<option<string>>
                ,
                "fontSizeSmall":option<option<string>>
                ,
                "fontSizeLarge":option<option<string>>
                
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
                  ~colorAction:
                  string=?
                  ,
                  ~colorError:
                  string=?
                  ,
                  ~colorDisabled:
                  string=?
                  ,
                  ~fontSizeInherit:
                  string=?
                  ,
                  ~fontSizeSmall:
                  string=?
                  ,
                  ~fontSizeLarge:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #action | #disabled | #error | #\"inherit" | #primary | #secondary];
          

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
      

            type fontSize = [ | #default | #\"inherit" | #large | #small];
          

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~component: option<Component.t>=?,
~fontSize: option<fontSize>=?,
~htmlColor: option<string>=?,
~shapeRendering: option<string>=?,
~titleAccess: option<string>=?,
~viewBox: option<string>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "SvgIcon";
        