
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "contained":option<option<string>>
                ,
                "disableElevation":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "fullWidth":option<option<string>>
                ,
                "vertical":option<option<string>>
                ,
                "grouped":option<option<string>>
                ,
                "groupedHorizontal":option<option<string>>
                ,
                "groupedVertical":option<option<string>>
                ,
                "groupedText":option<option<string>>
                ,
                "groupedTextHorizontal":option<option<string>>
                ,
                "groupedTextVertical":option<option<string>>
                ,
                "groupedTextPrimary":option<option<string>>
                ,
                "groupedTextSecondary":option<option<string>>
                ,
                "groupedOutlined":option<option<string>>
                ,
                "groupedOutlinedHorizontal":option<option<string>>
                ,
                "groupedOutlinedVertical":option<option<string>>
                ,
                "groupedOutlinedPrimary":option<option<string>>
                ,
                "groupedOutlinedSecondary":option<option<string>>
                ,
                "groupedContained":option<option<string>>
                ,
                "groupedContainedHorizontal":option<option<string>>
                ,
                "groupedContainedVertical":option<option<string>>
                ,
                "groupedContainedPrimary":option<option<string>>
                ,
                "groupedContainedSecondary":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~contained:
                  string=?
                  ,
                  ~disableElevation:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~fullWidth:
                  string=?
                  ,
                  ~vertical:
                  string=?
                  ,
                  ~grouped:
                  string=?
                  ,
                  ~groupedHorizontal:
                  string=?
                  ,
                  ~groupedVertical:
                  string=?
                  ,
                  ~groupedText:
                  string=?
                  ,
                  ~groupedTextHorizontal:
                  string=?
                  ,
                  ~groupedTextVertical:
                  string=?
                  ,
                  ~groupedTextPrimary:
                  string=?
                  ,
                  ~groupedTextSecondary:
                  string=?
                  ,
                  ~groupedOutlined:
                  string=?
                  ,
                  ~groupedOutlinedHorizontal:
                  string=?
                  ,
                  ~groupedOutlinedVertical:
                  string=?
                  ,
                  ~groupedOutlinedPrimary:
                  string=?
                  ,
                  ~groupedOutlinedSecondary:
                  string=?
                  ,
                  ~groupedContained:
                  string=?
                  ,
                  ~groupedContainedHorizontal:
                  string=?
                  ,
                  ~groupedContainedVertical:
                  string=?
                  ,
                  ~groupedContainedPrimary:
                  string=?
                  ,
                  ~groupedContainedSecondary:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #default | #\"inherit" | #primary | #secondary];
          

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
      

            type orientation = [ | #horizontal | #vertical];
          

            type size = [ | #large | #medium | #small];
          

            type variant = [ | #contained | #outlined | #text];
          

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~component: option<Component.t>=?,
~disabled: option<bool>=?,
~disableElevation: option<bool>=?,
~disableFocusRipple: option<bool>=?,
~disableRipple: option<bool>=?,
~fullWidth: option<bool>=?,
~orientation: option<orientation>=?,
~size: option<size>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "ButtonGroup";
        