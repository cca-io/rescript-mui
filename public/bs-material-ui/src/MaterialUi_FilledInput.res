
            

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
      

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "colorSecondary":option<option<string>>
                ,
                "underline":option<option<string>>
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
                "input":option<option<string>>
                ,
                "inputMarginDense":option<option<string>>
                ,
                "inputHiddenLabel":option<option<string>>
                ,
                "inputMultiline":option<option<string>>
                ,
                "inputAdornedStart":option<option<string>>
                ,
                "inputAdornedEnd":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~colorSecondary:
                  string=?
                  ,
                  ~underline:
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
                  ~input:
                  string=?
                  ,
                  ~inputMarginDense:
                  string=?
                  ,
                  ~inputHiddenLabel:
                  string=?
                  ,
                  ~inputMultiline:
                  string=?
                  ,
                  ~inputAdornedStart:
                  string=?
                  ,
                  ~inputAdornedEnd:
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
      

            @react.component @bs.module("@material-ui/core") external make : (~\"aria-describedby": option<string>=?,
~className: option<string>=?,
~onBlur: option<ReactEvent.Focus.t => unit>=?,
~onClick: option<ReactEvent.Mouse.t => unit>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~onKeyDown: option<ReactEvent.Keyboard.t => unit>=?,
~onKeyUp: option<ReactEvent.Keyboard.t => unit>=?,
~renderSuffix: option<MaterialUi_Types.any>=?,
~rowsMin: option<RowsMin.t>=?,
~autoComplete: option<string>=?,
~autoFocus: option<bool>=?,
~classes: option<Classes.t>=?,
~color: option<color>=?,
~defaultValue: option<MaterialUi_Types.any>=?,
~disabled: option<bool>=?,
~disableUnderline: option<bool>=?,
~endAdornment: option<React.element>=?,
~error: option<bool>=?,
~fullWidth: option<bool>=?,
~id: option<string>=?,
~inputComponent: option<InputComponent.t>=?,
~inputProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~margin: option<margin>=?,
~multiline: option<bool>=?,
~name: option<string>=?,
~onChange: option<(ReactEvent.Form.t) => unit>=?,
~placeholder: option<string>=?,
~readOnly: option<bool>=?,
~required: option<bool>=?,
~rows: option<Rows.t>=?,
~rowsMax: option<RowsMax.t>=?,
~startAdornment: option<React.element>=?,
~\"type": option<string>=?,
~value: option<MaterialUi_Types.any>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "FilledInput";
        