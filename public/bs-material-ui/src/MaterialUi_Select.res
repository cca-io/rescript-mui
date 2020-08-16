
            

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
      

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "select":option<option<string>>
                ,
                "filled":option<option<string>>
                ,
                "outlined":option<option<string>>
                ,
                "selectMenu":option<option<string>>
                ,
                "disabled":option<option<string>>
                ,
                "icon":option<option<string>>
                ,
                "iconOpen":option<option<string>>
                ,
                "iconFilled":option<option<string>>
                ,
                "iconOutlined":option<option<string>>
                ,
                "nativeInput":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~select:
                  string=?
                  ,
                  ~filled:
                  string=?
                  ,
                  ~outlined:
                  string=?
                  ,
                  ~selectMenu:
                  string=?
                  ,
                  ~disabled:
                  string=?
                  ,
                  ~icon:
                  string=?
                  ,
                  ~iconOpen:
                  string=?
                  ,
                  ~iconFilled:
                  string=?
                  ,
                  ~iconOutlined:
                  string=?
                  ,
                  ~nativeInput:
                  string=?
                  
            , unit) => t = "";
          };
      

      module IconComponent: {
        type t;
        let string: (string) => t;
let iconComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let iconComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

      module Value: {
        type t;
        let string: (string) => t;
let int: (int) => t;
let float: (float) => t;
let arrayOf: (array<string>) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let int = (v: int) => Any(v);
let float = (v: float) => Any(v);
let arrayOf = (v: array<string>) => Any(v);
      };
      

            type variant = [ | #filled | #outlined | #standard];
          

            @react.component @bs.module("@material-ui/core") external make : (~\"aria-describedby": option<string>=?,
~className: option<string>=?,
~onBlur: option<ReactEvent.Focus.t => unit>=?,
~onClick: option<ReactEvent.Mouse.t => unit>=?,
~onFocus: option<ReactEvent.Focus.t => unit>=?,
~onKeyDown: option<ReactEvent.Keyboard.t => unit>=?,
~onKeyUp: option<ReactEvent.Keyboard.t => unit>=?,
~renderSuffix: option<MaterialUi_Types.any>=?,
~rowsMin: option<RowsMin.t>=?,
~style: option<ReactDOMRe.Style.t>=?,
~autoComplete: option<string>=?,
~autoFocus: option<bool>=?,
~color: option<color>=?,
~disabled: option<bool>=?,
~disableUnderline: option<bool>=?,
~endAdornment: option<React.element>=?,
~error: option<bool>=?,
~fullWidth: option<bool>=?,
~inputComponent: option<InputComponent.t>=?,
~margin: option<margin>=?,
~multiline: option<bool>=?,
~name: option<string>=?,
~placeholder: option<string>=?,
~readOnly: option<bool>=?,
~required: option<bool>=?,
~rows: option<Rows.t>=?,
~rowsMax: option<RowsMax.t>=?,
~startAdornment: option<React.element>=?,
~\"type": option<string>=?,
~autoWidth: option<bool>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~defaultValue: option<MaterialUi_Types.any>=?,
~displayEmpty: option<bool>=?,
~\"IconComponent": option<IconComponent.t>=?,
~id: option<string>=?,
~input: option<React.element>=?,
~inputProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~label: option<React.element>=?,
~labelId: option<string>=?,
~labelWidth: option<MaterialUi_Types.Number.t>=?,
~\"MenuProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~multiple: option<bool>=?,
~native: option<bool>=?,
~onChange: option<(ReactEvent.Form.t, Js.Dict.t<MaterialUi_Types.any>) => unit>=?,
~onClose: option<(ReactEvent.Synthetic.t) => unit>=?,
~onOpen: option<(ReactEvent.Synthetic.t) => unit>=?,
~\"open": option<bool>=?,
~renderValue: option<(MaterialUi_Types.any) => MaterialUi_Types.any>=?,
~\"SelectDisplayProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~value: option<Value.t>=?,
~variant: option<variant>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Select";
        