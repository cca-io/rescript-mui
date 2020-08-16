
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "vertical":option<option<string>>
                ,
                "grouped":option<option<string>>
                ,
                "groupedHorizontal":option<option<string>>
                ,
                "groupedVertical":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
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
                  
            , unit) => t = "";
          };
      

            type orientation = [ | #horizontal | #vertical];
          

            type size = [ | #large | #medium | #small];
          

            @react.component @bs.module("@material-ui/lab") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~exclusive: option<bool>=?,
~onChange: option<(ReactEvent.Form.t, MaterialUi_Types.any) => unit>=?,
~orientation: option<orientation>=?,
~size: option<size>=?,
~value: option<MaterialUi_Types.any>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "ToggleButtonGroup";
        