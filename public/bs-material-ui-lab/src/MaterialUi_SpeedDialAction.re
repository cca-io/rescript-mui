module Classes = {
  type t = {
    .
    "fab": option(option(string)),
    "fabClosed": option(option(string)),
    "staticTooltip": option(option(string)),
    "staticTooltipClosed": option(option(string)),
    "staticTooltipLabel": option(option(string)),
    "tooltipPlacementLeft": option(option(string)),
    "tooltipPlacementRight": option(option(string)),
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
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~delay: option(MaterialUi_Types.Number.t)=?,
    ~_FabProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~icon: option(React.element)=?,
    ~id: option(string)=?,
    ~_open: option(bool)=?,
    ~_TooltipClasses: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~tooltipOpen: option(bool)=?,
    ~tooltipPlacement: option(
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
    ~tooltipTitle: option(React.element)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "SpeedDialAction";
