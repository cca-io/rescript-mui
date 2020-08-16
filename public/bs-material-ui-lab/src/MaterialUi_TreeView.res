
            

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
      

      module DefaultSelected: {
        type t;
        let arrayOf: (array<string>) => t;
let string: (string) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let arrayOf = (v: array<string>) => Any(v);
let string = (v: string) => Any(v);
      };
      

      module Value: {
        type t;
        let array: (array<MaterialUi_Types.any>) => t;
let string: (string) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let array = (v: array<MaterialUi_Types.any>) => Any(v);
let string = (v: string) => Any(v);
      };
      

      module Selected: {
        type t;
        let arrayOf: (array<string>) => t;
let string: (string) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let arrayOf = (v: array<string>) => Any(v);
let string = (v: string) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/lab") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~defaultCollapseIcon: option<React.element>=?,
~defaultEndIcon: option<React.element>=?,
~defaultExpanded: option<array<string>>=?,
~defaultExpandIcon: option<React.element>=?,
~defaultParentIcon: option<React.element>=?,
~defaultSelected: option<DefaultSelected.t>=?,
~disableSelection: option<bool>=?,
~expanded: option<array<string>>=?,
~multiSelect: option<bool>=?,
~onNodeSelect: option<(Js.Dict.t<MaterialUi_Types.any>, Value.t) => unit>=?,
~onNodeToggle: option<(Js.Dict.t<MaterialUi_Types.any>, array<MaterialUi_Types.any>) => unit>=?,
~selected: option<Selected.t>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "TreeView";
        