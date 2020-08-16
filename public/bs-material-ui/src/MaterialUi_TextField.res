
            

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
      

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  
            , unit) => t = "";
          };
      

            type color = [ | #primary | #secondary];
          

      module DefaultValue: {
        type t;
        let string: (string) => t;
let int: (int) => t;
let float: (float) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
      };
      

            type margin = [ | #dense | #none | #normal];
          

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
      

            type size = [ | #medium | #small];
          

      module Value: {
        type t;
        let string: (string) => t;
let int: (int) => t;
let float: (float) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
      };
      

            type variant = [ | #filled | #outlined | #standard];
          

            @react.component @bs.module("@material-ui/core") external make : (~component: option<Component.t>=?,
~focused: option<bool>=?,
~style: option<ReactDOMRe.Style.t>=?,
~autoComplete: option<string>=?,
~autoFocus: option<bool>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~color: option<color>=?,
~defaultValue: option<DefaultValue.t>=?,
~disabled: option<bool>=?,
~error: option<bool>=?,
~\"FormHelperTextProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~fullWidth: option<bool>=?,
~helperText: option<React.element>=?,
~hiddenLabel: option<bool>=?,
~id: option<string>=?,
~\"InputLabelProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~inputProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~\"InputProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~label: option<React.element>=?,
~margin: option<margin>=?,
~multiline: option<bool>=?,
~name: option<string>=?,
~onBlur: option<ReactEvent.Focus.t => unit>=?,
~onChange: option<(ReactEvent.Form.t) => unit>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~placeholder: option<string>=?,
~required: option<bool>=?,
~rows: option<Rows.t>=?,
~rowsMax: option<RowsMax.t>=?,
~select: option<bool>=?,
~\"SelectProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~size: option<size>=?,
~\"type": option<string>=?,
~value: option<Value.t>=?,
~variant: option<variant>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "TextField";
        