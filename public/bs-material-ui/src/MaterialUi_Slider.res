
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "colorPrimary":option<option<string>>
                ,
                "colorSecondary":option<option<string>>
                ,
                "marked":option<option<string>>
                ,
                "vertical":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "rail":option<option<string>>
                ,
                "track":option<option<string>>
                ,
                "trackFalse":option<option<string>>
                ,
                "trackInverted":option<option<string>>
                ,
                "thumb":option<option<string>>
                ,
                "thumbColorPrimary":option<option<string>>
                ,
                "thumbColorSecondary":option<option<string>>
                ,
                "active":option<option<string>>
                ,
                "focusVisible":option<option<string>>
                ,
                "valueLabel":option<option<string>>
                ,
                "mark":option<option<string>>
                ,
                "markActive":option<option<string>>
                ,
                "markLabel":option<option<string>>
                ,
                "markLabelActive":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~colorPrimary:
                  string=?
                  ,
                  ~colorSecondary:
                  string=?
                  ,
                  ~marked:
                  string=?
                  ,
                  ~vertical:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~rail:
                  string=?
                  ,
                  ~track:
                  string=?
                  ,
                  ~trackFalse:
                  string=?
                  ,
                  ~trackInverted:
                  string=?
                  ,
                  ~thumb:
                  string=?
                  ,
                  ~thumbColorPrimary:
                  string=?
                  ,
                  ~thumbColorSecondary:
                  string=?
                  ,
                  ~active:
                  string=?
                  ,
                  ~focusVisible:
                  string=?
                  ,
                  ~valueLabel:
                  string=?
                  ,
                  ~mark:
                  string=?
                  ,
                  ~markActive:
                  string=?
                  ,
                  ~markLabel:
                  string=?
                  ,
                  ~markLabelActive:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #primary | #secondary];
          

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
      

      module DefaultValue: {
        type t;
        let int: (int) => t;
let float: (float) => t;
let arrayOf: (array<MaterialUi_Types.Number.t>) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let arrayOf = (v: array<MaterialUi_Types.Number.t>) => Any(v);
      };
      

      module Marks: {
        type t;
        let bool: (bool) => t;
let array: (array<MaterialUi_Types.any>) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let bool = (v: bool) => Any(v);
let array = (v: array<MaterialUi_Types.any>) => Any(v);
      };
      

            type orientation = [ | #horizontal | #vertical];
          

      module ThumbComponent: {
        type t;
        let string: (string) => t;
let thumbComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let thumbComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

                module Track: {
                    type t;
                    let normal: t;
let \"false": t;
let inverted: t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let normal = Any("normal");
let \"false" = Any(false);
let inverted = Any("inverted");
                };
                

      module Value: {
        type t;
        let int: (int) => t;
let float: (float) => t;
let arrayOf: (array<MaterialUi_Types.Number.t>) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let arrayOf = (v: array<MaterialUi_Types.Number.t>) => Any(v);
      };
      

      module ValueLabelComponent: {
        type t;
        let string: (string) => t;
let valueLabelComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let valueLabelComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            type valueLabelDisplay = [ | #on | #auto | #off];
          

      module ValueLabelFormat: {
        type t;
        let string: (string) => t;
let valueLabelFormat_func: (MaterialUi_Types.any) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let valueLabelFormat_func = (v: MaterialUi_Types.any) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/core") external make : (~\"aria-labelledby": option<string>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~component: option<Component.t>=?,
~defaultValue: option<DefaultValue.t>=?,
~disabled: option<bool>=?,
~getAriaLabel: option<(int) => string>=?,
~getAriaValueText: option<(int, int) => string>=?,
~marks: option<Marks.t>=?,
~max: option<MaterialUi_Types.Number.t>=?,
~min: option<MaterialUi_Types.Number.t>=?,
~name: option<string>=?,
~onChange: option<(ReactEvent.Form.t, int) => unit>=?,
~onChangeCommitted: option<(ReactEvent.Form.t, int) => unit>=?,
~onMouseDown: option<ReactEvent.Mouse.t => unit>=?,
~orientation: option<orientation>=?,
~scale: option<MaterialUi_Types.any>=?,
~step: option<MaterialUi_Types.Number.t>=?,
~\"ThumbComponent": option<ThumbComponent.t>=?,
~track: option<Track.t>=?,
~value: option<Value.t>=?,
~\"ValueLabelComponent": option<ValueLabelComponent.t>=?,
~valueLabelDisplay: option<valueLabelDisplay>=?,
~valueLabelFormat: option<ValueLabelFormat.t>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Slider";
        