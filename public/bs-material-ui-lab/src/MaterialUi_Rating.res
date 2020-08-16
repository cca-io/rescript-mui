
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "sizeSmall":option<option<string>>
                ,
                "sizeLarge":option<option<string>>
                ,
                "readOnly":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "focusVisible":option<option<string>>
                ,
                "visuallyhidden":option<option<string>>
                ,
                "pristine":option<option<string>>
                ,
                "label":option<option<string>>
                ,
                "icon":option<option<string>>
                ,
                "iconEmpty":option<option<string>>
                ,
                "iconFilled":option<option<string>>
                ,
                "iconHover":option<option<string>>
                ,
                "iconFocus":option<option<string>>
                ,
                "iconActive":option<option<string>>
                ,
                "decimal":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~sizeSmall:
                  string=?
                  ,
                  ~sizeLarge:
                  string=?
                  ,
                  ~readOnly:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~focusVisible:
                  string=?
                  ,
                  ~visuallyhidden:
                  string=?
                  ,
                  ~pristine:
                  string=?
                  ,
                  ~label:
                  string=?
                  ,
                  ~icon:
                  string=?
                  ,
                  ~iconEmpty:
                  string=?
                  ,
                  ~iconFilled:
                  string=?
                  ,
                  ~iconHover:
                  string=?
                  ,
                  ~iconFocus:
                  string=?
                  ,
                  ~iconActive:
                  string=?
                  ,
                  ~decimal:
                  string=?
                  
            , unit) => t = "";
          };
      

      module IconContainerComponent: {
        type t;
        let string: (string) => t;
let iconContainerComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let iconContainerComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            type size = [ | #large | #medium | #small];
          

            @react.component @bs.module("@material-ui/lab") external make : (~classes: option<Classes.t>=?,
~className: option<string>=?,
~defaultValue: option<MaterialUi_Types.Number.t>=?,
~disabled: option<bool>=?,
~emptyIcon: option<React.element>=?,
~emptyLabelText: option<React.element>=?,
~getLabelText: option<(int) => string>=?,
~icon: option<React.element>=?,
~\"IconContainerComponent": option<IconContainerComponent.t>=?,
~max: option<MaterialUi_Types.Number.t>=?,
~name: option<string>=?,
~onChange: option<(ReactEvent.Form.t, int) => unit>=?,
~onChangeActive: option<(Js.Dict.t<MaterialUi_Types.any>, int) => unit>=?,
~onMouseLeave: option<ReactEvent.Mouse.t => unit>=?,
~onMouseMove: option<ReactEvent.Mouse.t => unit>=?,
~precision: option<MaterialUi_Types.Number.t>=?,
~readOnly: option<bool>=?,
~size: option<size>=?,
~value: option<MaterialUi_Types.Number.t>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Rating";
        