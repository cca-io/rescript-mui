module AnchorEl: {
  type t;
  let obj: Js.t({..}) => t;
  let anchorEl_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let obj = (v: Js.t({..})) => Any(v);
  let anchorEl_func = (v: MaterialUi_Types.any) => Any(v);
};

module Children: {
  type t;
  let element: React.element => t;
  let children_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let element = (v: React.element) => Any(v);
  let children_func = (v: MaterialUi_Types.any) => Any(v);
};

module Container: {
  type t;
  let custom: Dom.element => t;
  let element: React.element => t;
  let container_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let custom = (v: Dom.element) => Any(v);
  let element = (v: React.element) => Any(v);
  let container_func = (v: MaterialUi_Types.any) => Any(v);
};

type placement = [
  | `Bottom_End
  | `Bottom_Start
  | `Bottom
  | `Left_End
  | `Left_Start
  | `Left
  | `Right_End
  | `Right_Start
  | `Right
  | `Top_End
  | `Top_Start
  | `Top
];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~anchorEl: AnchorEl.t=?,
    ~children: 'children=?,
    ~container: Container.t=?,
    ~disablePortal: bool=?,
    ~keepMounted: bool=?,
    ~modifiers: Js.t({..})=?,
    ~_open: bool,
    ~placement: [@bs.string] [
                  | [@bs.as "bottom-end"] `Bottom_End
                  | [@bs.as "bottom-start"] `Bottom_Start
                  | [@bs.as "bottom"] `Bottom
                  | [@bs.as "left-end"] `Left_End
                  | [@bs.as "left-start"] `Left_Start
                  | [@bs.as "left"] `Left
                  | [@bs.as "right-end"] `Right_End
                  | [@bs.as "right-start"] `Right_Start
                  | [@bs.as "right"] `Right
                  | [@bs.as "top-end"] `Top_End
                  | [@bs.as "top-start"] `Top_Start
                  | [@bs.as "top"] `Top
                ]
                  =?,
    ~popperOptions: Js.t({..})=?,
    ~style: ReactDOM.Style.t=?,
    ~transition: bool=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Popper";
