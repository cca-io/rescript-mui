
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "vertical":option<option<string>>
                ,
                "flexContainer":option<option<string>>
                ,
                "flexContainerVertical":option<option<string>>
                ,
                "centered":option<option<string>>
                ,
                "scroller":option<option<string>>
                ,
                "fixed":option<option<string>>
                ,
                "scrollable":option<option<string>>
                ,
                "scrollButtons":option<option<string>>
                ,
                "scrollButtonsDesktop":option<option<string>>
                ,
                "indicator":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~vertical:
                  string=?
                  ,
                  ~flexContainer:
                  string=?
                  ,
                  ~flexContainerVertical:
                  string=?
                  ,
                  ~centered:
                  string=?
                  ,
                  ~scroller:
                  string=?
                  ,
                  ~fixed:
                  string=?
                  ,
                  ~scrollable:
                  string=?
                  ,
                  ~scrollButtons:
                  string=?
                  ,
                  ~scrollButtonsDesktop:
                  string=?
                  ,
                  ~indicator:
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
      

            type indicatorColor = [ | #primary | #secondary];
          

            type orientation = [ | #horizontal | #vertical];
          

      module ScrollButtonComponent: {
        type t;
        let string: (string) => t;
let scrollButtonComponent_func: (MaterialUi_Types.any) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let scrollButtonComponent_func = (v: MaterialUi_Types.any) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            type scrollButtons = [ | #auto | #desktop | #off | #on];
          

            type textColor = [ | #\"inherit" | #primary | #secondary];
          

            type variant = [ | #fullWidth | #scrollable | #standard];
          

            @react.component @bs.module("@material-ui/core") external make : (~\"aria-label": option<string>=?,
~\"aria-labelledby": option<string>=?,
~centered: option<bool>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~component: option<Component.t>=?,
~indicatorColor: option<indicatorColor>=?,
~onChange: option<(ReactEvent.Form.t, MaterialUi_Types.any) => unit>=?,
~orientation: option<orientation>=?,
~\"ScrollButtonComponent": option<ScrollButtonComponent.t>=?,
~scrollButtons: option<scrollButtons>=?,
~selectionFollowsFocus: option<bool>=?,
~\"TabIndicatorProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~\"TabScrollButtonProps": option<Js.Dict.t<MaterialUi_Types.any>>=?,
~textColor: option<textColor>=?,
~value: option<MaterialUi_Types.any>=?,
~variant: option<variant>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Tabs";
        