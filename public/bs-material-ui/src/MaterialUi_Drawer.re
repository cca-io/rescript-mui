module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    docked: string,
    [@bs.optional]
    paper: string,
    [@bs.optional]
    paperAnchorLeft: string,
    [@bs.optional]
    paperAnchorRight: string,
    [@bs.optional]
    paperAnchorTop: string,
    [@bs.optional]
    paperAnchorBottom: string,
    [@bs.optional]
    paperAnchorDockedLeft: string,
    [@bs.optional]
    paperAnchorDockedTop: string,
    [@bs.optional]
    paperAnchorDockedRight: string,
    [@bs.optional]
    paperAnchorDockedBottom: string,
    [@bs.optional]
    modal: string,
  };
  let make = t;
};

module TransitionDuration_shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    appear: MaterialUi_Types.Number.t,
    [@bs.optional]
    enter: MaterialUi_Types.Number.t,
    [@bs.optional]
    exit: MaterialUi_Types.Number.t,
  };
  let make = t;
};

module TransitionDuration: {
  type t;
  let int: int => t;
  let float: float => t;
  let shape: TransitionDuration_shape.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let shape = (v: TransitionDuration_shape.t) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~anchor: option(
               [@bs.string] [
                 | [@bs.as "bottom"] `Bottom
                 | [@bs.as "left"] `Left
                 | [@bs.as "right"] `Right
                 | [@bs.as "top"] `Top
               ],
             )
               =?,
    ~_BackdropProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~_ModalProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
    ~_open: option(bool)=?,
    ~_PaperProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_SlideProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "permanent"] `Permanent
                  | [@bs.as "persistent"] `Persistent
                  | [@bs.as "temporary"] `Temporary
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Drawer";
