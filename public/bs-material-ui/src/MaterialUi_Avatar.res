
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "colorDefault":option<option<string>>
                ,
                "circle":option<option<string>>
                ,
                "rounded":option<option<string>>
                ,
                "square":option<option<string>>
                ,
                "img":option<option<string>>
                ,
                "fallback":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~colorDefault:
                  string=?
                  ,
                  ~circle:
                  string=?
                  ,
                  ~rounded:
                  string=?
                  ,
                  ~square:
                  string=?
                  ,
                  ~img:
                  string=?
                  ,
                  ~fallback:
                  string=?
                  
            , unit) => t = "";
          };
      

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
      

            type variant = [ | #circle | #rounded | #square];
          

            @react.component @bs.module("@material-ui/core") external make : (~alt: option<string>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~component: option<Component.t>=?,
~imgProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~sizes: option<string>=?,
~src: option<string>=?,
~srcSet: option<string>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Avatar";
        