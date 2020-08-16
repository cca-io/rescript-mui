
            

            type implementation = [ | #js | #css];
          

            type initialWidth = [ | #xs | #sm | #md | #lg | #xl];
          

                module Only_enum: {
                    type t;
                    let xs: t;
let sm: t;
let md: t;
let lg: t;
let xl: t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let xs = Any("xs");
let sm = Any("sm");
let md = Any("md");
let lg = Any("lg");
let xl = Any("xl");
                };
                

                module Only_arrayOf: {
                    type t;
                    let xs: t;
let sm: t;
let md: t;
let lg: t;
let xl: t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let xs = Any("xs");
let sm = Any("sm");
let md = Any("md");
let lg = Any("lg");
let xl = Any("xl");
                };
                

      module Only: {
        type t;
        let enum: (Only_enum.t) => t;
let arrayOf: (array<Only_arrayOf.t>) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let enum = (v: Only_enum.t) => Any(v);
let arrayOf = (v: array<Only_arrayOf.t>) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~className: option<string>=?,
~implementation: option<implementation>=?,
~initialWidth: option<initialWidth>=?,
~lgDown: option<bool>=?,
~lgUp: option<bool>=?,
~mdDown: option<bool>=?,
~mdUp: option<bool>=?,
~only: option<Only.t>=?,
~smDown: option<bool>=?,
~smUp: option<bool>=?,
~xlDown: option<bool>=?,
~xlUp: option<bool>=?,
~xsDown: option<bool>=?,
~xsUp: option<bool>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Hidden";
        