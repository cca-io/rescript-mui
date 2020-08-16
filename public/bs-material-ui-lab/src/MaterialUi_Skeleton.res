
            
                module Animation: {
                    type t;
                    let pulse: t;
let wave: t;
let \"false": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let pulse = Any("pulse");
let wave = Any("wave");
let \"false" = Any(false);
                };
                


          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "text":option<option<string>>
                ,
                "rect":option<option<string>>
                ,
                "circle":option<option<string>>
                ,
                "pulse":option<option<string>>
                ,
                "wave":option<option<string>>
                ,
                "withChildren":option<option<string>>
                ,
                "fitContent":option<option<string>>
                ,
                "heightAuto":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~text:
                  string=?
                  ,
                  ~rect:
                  string=?
                  ,
                  ~circle:
                  string=?
                  ,
                  ~pulse:
                  string=?
                  ,
                  ~wave:
                  string=?
                  ,
                  ~withChildren:
                  string=?
                  ,
                  ~fitContent:
                  string=?
                  ,
                  ~heightAuto:
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
      

      module Height: {
        type t;
        let int: (int) => t;
let float: (float) => t;
let string: (string) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let string = (v: string) => Any(v);
      };
      

            type variant = [ | #text | #rect | #circle];
          

      module Width: {
        type t;
        let int: (int) => t;
let float: (float) => t;
let string: (string) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let string = (v: string) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/lab") external make : (~animation: option<Animation.t>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~component: option<Component.t>=?,
~height: option<Height.t>=?,
~variant: option<variant>=?,
~width: option<Width.t>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Skeleton";
        