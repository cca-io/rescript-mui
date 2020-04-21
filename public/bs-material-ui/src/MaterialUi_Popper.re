module AnchorEl: {
  type t;
  let obj: Js.Dict.t(MaterialUi_Types.any) => t;
  let anchorEl_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let obj = (v: Js.Dict.t(MaterialUi_Types.any)) => Any(v);
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
  let container_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
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
    ~anchorEl: option(AnchorEl.t)=?,
    ~children: option('children)=?,
    ~container: option(Container.t)=?,
    ~disablePortal: option(bool)=?,
    ~keepMounted: option(bool)=?,
    ~modifiers: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_open: bool,
    ~placement: option(
                  [@bs.string] [
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
                  ],
                )
                  =?,
    ~popperOptions: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~transition: option(bool)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Popper";
