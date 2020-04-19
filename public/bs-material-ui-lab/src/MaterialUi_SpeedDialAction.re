module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    fab: string,
    [@bs.optional]
    fabClosed: string,
    [@bs.optional]
    staticTooltip: string,
    [@bs.optional]
    staticTooltipClosed: string,
    [@bs.optional]
    staticTooltipLabel: string,
    [@bs.optional]
    tooltipPlacementLeft: string,
    [@bs.optional]
    tooltipPlacementRight: string,
  };
  let make = t;
};

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
