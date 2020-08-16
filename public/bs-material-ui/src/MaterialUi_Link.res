
            
            type align = [ | #\"inherit" | #left | #center | #right | #justify];
          

            type display = [ | #initial | #block | #inline];
          


          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "underlineNone":option<option<string>>
                ,
                "underlineHover":option<option<string>>
                ,
                "underlineAlways":option<option<string>>
                ,
                "button":option<option<string>>
                ,
                "focusVisible":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~underlineNone:
                  string=?
                  ,
                  ~underlineHover:
                  string=?
                  ,
                  ~underlineAlways:
                  string=?
                  ,
                  ~button:
                  string=?
                  ,
                  ~focusVisible:
                  string=?
                  
            , unit) => t = "";
          };
      

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
      

            type underline = [ | #none | #hover | #always];
          

            type rel = [ | #alternate | #author | #bookmark | #\"external" | #help | #license | #next | #nofollow | #noreferrer | #noopener | #prev | #search | #tag];
          

            @react.component @bs.module("@material-ui/core") external make : (~align: option<align>=?,
~display: option<display>=?,
~gutterBottom: option<bool>=?,
~noWrap: option<bool>=?,
~paragraph: option<bool>=?,
~variantMapping: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~component: option<Component.t>=?,
~onBlur: option<ReactEvent.Focus.t => unit>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~\"TypographyClasses": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~underline: option<underline>=?,
~variant: option<string>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~onClick: option<ReactEvent.Mouse.t => unit>=?,
~href: option<string>=?,
~target: option<string>=?,
~rel: option<rel>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Link";
        