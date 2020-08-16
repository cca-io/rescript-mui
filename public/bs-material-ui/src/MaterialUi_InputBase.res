
            

          module Classes = {
            type t = {
              .
              
                "@global":option<option<string>>
                ,
                "root":option<option<string>>
                ,
                "formControl":option<option<string>>
                ,
                "focused":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "adornedStart":option<option<string>>
                ,
                "adornedEnd":option<option<string>>
                ,
                "error":option<option<string>>
                ,
                "marginDense":option<option<string>>
                ,
                "multiline":option<option<string>>
                ,
                "colorSecondary":option<option<string>>
                ,
                "fullWidth":option<option<string>>
                ,
                "input":option<option<string>>
                ,
                "inputMarginDense":option<option<string>>
                ,
                "inputMultiline":option<option<string>>
                ,
                "inputTypeSearch":option<option<string>>
                ,
                "inputAdornedStart":option<option<string>>
                ,
                "inputAdornedEnd":option<option<string>>
                ,
                "inputHiddenLabel":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~\"@global":
                  string=?
                  ,
                  ~root:
                  string=?
                  ,
                  ~formControl:
                  string=?
                  ,
                  ~focused:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~adornedStart:
                  string=?
                  ,
                  ~adornedEnd:
                  string=?
                  ,
                  ~error:
                  string=?
                  ,
                  ~marginDense:
                  string=?
                  ,
                  ~multiline:
                  string=?
                  ,
                  ~colorSecondary:
                  string=?
                  ,
                  ~fullWidth:
                  string=?
                  ,
                  ~input:
                  string=?
                  ,
                  ~inputMarginDense:
                  string=?
                  ,
                  ~inputMultiline:
                  string=?
                  ,
                  ~inputTypeSearch:
                  string=?
                  ,
                  ~inputAdornedStart:
                  string=?
                  ,
                  ~inputAdornedEnd:
                  string=?
                  ,
                  ~inputHiddenLabel:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #primary | #secondary];
          

      module InputComponent: {
        type t;
        let string: (string) => t;
let inputComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let inputComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            type margin = [ | #dense | #none];
          

      module Rows: {
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
      

      module RowsMax: {
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
      

      module RowsMin: {
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
      

            @react.component @bs.module("@material-ui/core") external make : (~\"aria-describedby": option<string>=?,
~autoComplete: option<string>=?,
~autoFocus: option<bool>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~defaultValue: option<MaterialUi_Types.any>=?,
~disabled: option<bool>=?,
~endAdornment: option<React.element>=?,
~error: option<bool>=?,
~fullWidth: option<bool>=?,
~id: option<string>=?,
~inputComponent: option<InputComponent.t>=?,
~inputProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~margin: option<margin>=?,
~multiline: option<bool>=?,
~name: option<string>=?,
~onBlur: option<ReactEvent.Focus.t => unit>=?,
~onChange: option<(ReactEvent.Form.t) => unit>=?,
~onClick: option<ReactEvent.Mouse.t => unit>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~onKeyDown: option<ReactEvent.Keyboard.t => unit>=?,
~onKeyUp: option<ReactEvent.Keyboard.t => unit>=?,
~placeholder: option<string>=?,
~readOnly: option<bool>=?,
~renderSuffix: option<MaterialUi_Types.any>=?,
~required: option<bool>=?,
~rows: option<Rows.t>=?,
~rowsMax: option<RowsMax.t>=?,
~rowsMin: option<RowsMin.t>=?,
~startAdornment: option<React.element>=?,
~\"type": option<string>=?,
~value: option<MaterialUi_Types.any>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "InputBase";
        