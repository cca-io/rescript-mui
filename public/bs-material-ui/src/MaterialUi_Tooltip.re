module Classes = {
  type t = {
    .
    "popper": option(string),
    "popperInteractive": option(string),
    "popperArrow": option(string),
    "tooltip": option(string),
    "tooltipArrow": option(string),
    "arrow": option(string),
    "touch": option(string),
    "tooltipPlacementLeft": option(string),
    "tooltipPlacementRight": option(string),
    "tooltipPlacementTop": option(string),
    "tooltipPlacementBottom": option(string),
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

module PopperComponent: {
  type t;
  let string: string => t;
  let popperComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let popperComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
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
    ~arrow: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~disableFocusListener: bool=?,
    ~disableHoverListener: bool=?,
    ~disableTouchListener: bool=?,
    ~enterDelay: MaterialUi_Types.Number.t=?,
    ~enterNextDelay: MaterialUi_Types.Number.t=?,
    ~enterTouchDelay: MaterialUi_Types.Number.t=?,
    ~id: string=?,
    ~interactive: bool=?,
    ~leaveDelay: MaterialUi_Types.Number.t=?,
    ~leaveTouchDelay: MaterialUi_Types.Number.t=?,
    ~onClose: ReactEvent.Synthetic.t => unit=?,
    ~onOpen: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool=?,
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
    ~_PopperComponent: PopperComponent.t=?,
    ~_PopperProps: Js.t({..})=?,
    ~title: React.element,
    ~_TransitionComponent: TransitionComponent.t=?,
    ~_TransitionProps: Js.t({..})=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Tooltip";
