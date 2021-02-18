module Classes = {
  type t = {
    .
    "fab": option(string),
    "fabClosed": option(string),
    "staticTooltip": option(string),
    "staticTooltipClosed": option(string),
    "staticTooltipLabel": option(string),
    "tooltipPlacementLeft": option(string),
    "tooltipPlacementRight": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~fab: string=?,
      ~fabClosed: string=?,
      ~staticTooltip: string=?,
      ~staticTooltipClosed: string=?,
      ~staticTooltipLabel: string=?,
      ~tooltipPlacementLeft: string=?,
      ~tooltipPlacementRight: string=?,
      unit
    ) =>
    t;
};

type tooltipPlacement = [
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

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~classes: Classes.t=?,
    ~className: string=?,
    ~delay: MaterialUi_Types.Number.t=?,
    ~_FabProps: Js.t({..})=?,
    ~icon: React.element=?,
    ~id: string=?,
    ~_open: bool=?,
    ~_TooltipClasses: Js.t({..})=?,
    ~tooltipOpen: bool=?,
    ~tooltipPlacement: [@bs.string] [
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
    ~tooltipTitle: React.element=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "SpeedDialAction";
