
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "disableGutters":option<option<string>>
                ,
                "fixed":option<option<string>>
                ,
                "maxWidthXs":option<option<string>>
                ,
                "maxWidthSm":option<option<string>>
                ,
                "maxWidthMd":option<option<string>>
                ,
                "maxWidthLg":option<option<string>>
                ,
                "maxWidthXl":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~disableGutters:
                  string=?
                  ,
                  ~fixed:
                  string=?
                  ,
                  ~maxWidthXs:
                  string=?
                  ,
                  ~maxWidthSm:
                  string=?
                  ,
                  ~maxWidthMd:
                  string=?
                  ,
                  ~maxWidthLg:
                  string=?
                  ,
                  ~maxWidthXl:
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
      

                module MaxWidth: {
                    type t;
                    let lg: t;
let md: t;
let sm: t;
let xl: t;
let xs: t;
let \"false": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let lg = Any("lg");
let md = Any("md");
let sm = Any("sm");
let xl = Any("xl");
let xs = Any("xs");
let \"false" = Any(false);
                };
                

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~component: option<Component.t>=?,
~disableGutters: option<bool>=?,
~fixed: option<bool>=?,
~maxWidth: option<MaxWidth.t>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Container";
        