
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "page":option<option<string>>
                ,
                "sizeSmall":option<option<string>>
                ,
                "sizeLarge":option<option<string>>
                ,
                "textPrimary":option<option<string>>
                ,
                "textSecondary":option<option<string>>
                ,
                "outlined":option<option<string>>
                ,
                "outlinedPrimary":option<option<string>>
                ,
                "outlinedSecondary":option<option<string>>
                ,
                "rounded":option<option<string>>
                ,
                "ellipsis":option<option<string>>
                ,
                "focusVisible":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "selected":option<option<string>>
                ,
                "icon":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~page:
                  string=?
                  ,
                  ~sizeSmall:
                  string=?
                  ,
                  ~sizeLarge:
                  string=?
                  ,
                  ~textPrimary:
                  string=?
                  ,
                  ~textSecondary:
                  string=?
                  ,
                  ~outlined:
                  string=?
                  ,
                  ~outlinedPrimary:
                  string=?
                  ,
                  ~outlinedSecondary:
                  string=?
                  ,
                  ~rounded:
                  string=?
                  ,
                  ~ellipsis:
                  string=?
                  ,
                  ~focusVisible:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~selected:
                  string=?
                  ,
                  ~icon:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #standard | #primary | #secondary];
          

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
      

            type shape = [ | #round | #rounded];
          

            type size = [ | #small | #medium | #large];
          

            type \"type" = [ | #page | #first | #last | #next | #previous | #\"start-ellipsis" | #\"end-ellipsis"];
          

            type variant = [ | #text | #outlined];
          

            @react.component @bs.module("@material-ui/lab") external make : (~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~component: option<Component.t>=?,
~disabled: option<bool>=?,
~page: option<MaterialUi_Types.Number.t>=?,
~selected: option<bool>=?,
~shape: option<shape>=?,
~size: option<size>=?,
~\"type": option<\"type">=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "PaginationItem";
        