module Classes = {
  type t = {
    .
    "popper": option(option(string)),
    "popperInteractive": option(option(string)),
    "popperArrow": option(option(string)),
    "tooltip": option(option(string)),
    "tooltipArrow": option(option(string)),
    "arrow": option(option(string)),
    "touch": option(option(string)),
    "tooltipPlacementLeft": option(option(string)),
    "tooltipPlacementRight": option(option(string)),
    "tooltipPlacementTop": option(option(string)),
    "tooltipPlacementBottom": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~popper: string=?,
      ~popperInteractive: string=?,
      ~popperArrow: string=?,
      ~tooltip: string=?,
      ~tooltipArrow: string=?,
      ~arrow: string=?,
      ~touch: string=?,
      ~tooltipPlacementLeft: string=?,
      ~tooltipPlacementRight: string=?,
      ~tooltipPlacementTop: string=?,
      ~tooltipPlacementBottom: string=?,
      unit
    ) =>
    t;
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
    ~className: option(string)=?,
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
