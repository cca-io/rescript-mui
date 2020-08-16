
            
            type align = [ | #center | #\"inherit" | #justify | #left | #right];
          


          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "head":option<option<string>>
                ,
                "body":option<option<string>>
                ,
                "footer":option<option<string>>
                ,
                "sizeSmall":option<option<string>>
                ,
                "paddingCheckbox":option<option<string>>
                ,
                "paddingNone":option<option<string>>
                ,
                "alignLeft":option<option<string>>
                ,
                "alignCenter":option<option<string>>
                ,
                "alignRight":option<option<string>>
                ,
                "alignJustify":option<option<string>>
                ,
                "stickyHeader":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~head:
                  string=?
                  ,
                  ~body:
                  string=?
                  ,
                  ~footer:
                  string=?
                  ,
                  ~sizeSmall:
                  string=?
                  ,
                  ~paddingCheckbox:
                  string=?
                  ,
                  ~paddingNone:
                  string=?
                  ,
                  ~alignLeft:
                  string=?
                  ,
                  ~alignCenter:
                  string=?
                  ,
                  ~alignRight:
                  string=?
                  ,
                  ~alignJustify:
                  string=?
                  ,
                  ~stickyHeader:
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
      

            type padding = [ | #checkbox | #default | #none];
          

            type size = [ | #medium | #small];
          

                module SortDirection: {
                    type t;
                    let asc: t;
let desc: t;
let \"false": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let asc = Any("asc");
let desc = Any("desc");
let \"false" = Any(false);
                };
                

            type variant = [ | #body | #footer | #head];
          

            @react.component @bs.module("@material-ui/core") external make : (~align: option<align>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~component: option<Component.t>=?,
~padding: option<padding>=?,
~scope: option<string>=?,
~size: option<size>=?,
~sortDirection: option<SortDirection.t>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~colSpan: option<int>=?,
~rowSpan: option<int>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "TableCell";
        