module Container: {
  type t;
  let custom: Dom.element => t;
  let container_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let custom = (v: Dom.element) => Any(v);
  let container_func = (v: MaterialUi_Types.any) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~container: Container.t=?,
    ~disablePortal: bool=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Portal";
