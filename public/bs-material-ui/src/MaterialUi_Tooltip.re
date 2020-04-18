module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    popper: string,
    [@bs.optional]
    popperInteractive: string,
    [@bs.optional]
    popperArrow: string,
    [@bs.optional]
    tooltip: string,
    [@bs.optional]
    tooltipArrow: string,
    [@bs.optional]
    arrow: string,
    [@bs.optional]
    touch: string,
    [@bs.optional]
    tooltipPlacementLeft: string,
    [@bs.optional]
    tooltipPlacementRight: string,
    [@bs.optional]
    tooltipPlacementTop: string,
    [@bs.optional]
    tooltipPlacementBottom: string,
  };
  let make = t;
};

module TransitionComponent: {
  type t;
  let string: string => t;
  let transitionComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let transitionComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~arrow: option(bool)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~disableFocusListener: option(bool)=?,
    ~disableHoverListener: option(bool)=?,
    ~disableTouchListener: option(bool)=?,
    ~enterDelay: option(MaterialUi_Types.Number.t)=?,
    ~enterNextDelay: option(MaterialUi_Types.Number.t)=?,
    ~enterTouchDelay: option(MaterialUi_Types.Number.t)=?,
    ~id: option(string)=?,
    ~interactive: option(bool)=?,
    ~leaveDelay: option(MaterialUi_Types.Number.t)=?,
    ~leaveTouchDelay: option(MaterialUi_Types.Number.t)=?,
    ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
    ~onOpen: option(ReactEvent.Synthetic.t => unit)=?,
    ~_open: option(bool)=?,
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
    ~_PopperProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~title: React.element,
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Tooltip";
