
            

      module Container: {
        type t;
        let container_func: (MaterialUi_Types.any) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let container_func = (v: MaterialUi_Types.any) => Any(v);
      };
      

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~container: option<Container.t>=?,
~disablePortal: option<bool>=?,
~onRendered: option<ReactEvent.Synthetic.t => unit>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Portal";
        