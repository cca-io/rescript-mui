
            

      module AnchorEl: {
        type t;
        let obj: (Js.Dict.t<MaterialUi_Types.any>) => t;
let anchorEl_func: (MaterialUi_Types.any) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let obj = (v: Js.Dict.t<MaterialUi_Types.any>) => Any(v);
let anchorEl_func = (v: MaterialUi_Types.any) => Any(v);
      };
      

      module Children: {
        type t;
        let element: (React.element) => t;
let children_func: (MaterialUi_Types.any) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let element = (v: React.element) => Any(v);
let children_func = (v: MaterialUi_Types.any) => Any(v);
      };
      

      module Container: {
        type t;
        let container_func: (MaterialUi_Types.any) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let container_func = (v: MaterialUi_Types.any) => Any(v);
      };
      

            type placement = [ | #\"bottom-end" | #\"bottom-start" | #bottom | #\"left-end" | #\"left-start" | #left | #\"right-end" | #\"right-start" | #right | #\"top-end" | #\"top-start" | #top];
          

            @react.component @bs.module("@material-ui/core") external make : (~anchorEl: option<AnchorEl.t>=?,
~children: option<'children>=?,
~container: option<Container.t>=?,
~disablePortal: option<bool>=?,
~keepMounted: option<bool>=?,
~modifiers: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~\"open": bool,
~placement: option<placement>=?,
~popperOptions: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~style: option<ReactDOMRe.Style.t>=?,
~transition: option<bool>=?,
~id: option<string>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Popper";
        