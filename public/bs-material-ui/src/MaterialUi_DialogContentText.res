
            
            type align = [ | #\"inherit" | #left | #center | #right | #justify];
          


            type color = [ | #initial | #\"inherit" | #primary | #secondary | #textPrimary | #textSecondary | #error];
          

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
      

            type display = [ | #initial | #block | #inline];
          

            type variant = [ | #h1 | #h2 | #h3 | #h4 | #h5 | #h6 | #subtitle1 | #subtitle2 | #body1 | #body2 | #caption | #button | #overline | #srOnly | #\"inherit"];
          

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  
            , unit) => t = "";
          };
      

            @react.component @bs.module("@material-ui/core") external make : (~align: option<align>=?,
~className: option<string>=?,
~color: option<color>=?,
~component: option<Component.t>=?,
~display: option<display>=?,
~gutterBottom: option<bool>=?,
~noWrap: option<bool>=?,
~paragraph: option<bool>=?,
~variant: option<variant>=?,
~variantMapping: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "DialogContentText";
        