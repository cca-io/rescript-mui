[@bs.deriving jsConverter]
type tooltipPlacement = [
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
];

module Classes = {
  type classesType =
    | Fab(string)
    | FabClosed(string)
    | StaticTooltip(string)
    | StaticTooltipClosed(string)
    | StaticTooltipLabel(string)
    | TooltipPlacementLeft(string)
    | TooltipPlacementRight(string);
  type t = list(classesType);
  let to_string =
    fun
    | Fab(_) => "fab"
    | FabClosed(_) => "fabClosed"
    | StaticTooltip(_) => "staticTooltip"
    | StaticTooltipClosed(_) => "staticTooltipClosed"
    | StaticTooltipLabel(_) => "staticTooltipLabel"
    | TooltipPlacementLeft(_) => "tooltipPlacementLeft"
    | TooltipPlacementRight(_) => "tooltipPlacementRight";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Fab(className)
                         | FabClosed(className)
                         | StaticTooltip(className)
                         | StaticTooltipClosed(className)
                         | StaticTooltipLabel(className)
                         | TooltipPlacementLeft(className)
                         | TooltipPlacementRight(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~className: string=?,
    ~delay: 'number_d=?,
    ~_FabProps: Js.t({..})=?,
    ~icon: React.element=?,
    ~id: string=?,
    ~_open: bool=?,
    ~_TooltipClasses: Js.t({..})=?,
    ~tooltipOpen: bool=?,
    ~tooltipPlacement: string=?,
    ~tooltipTitle: React.element=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~className: option(string)=?,
      ~delay: option([ | `Int(int) | `Float(float)])=?,
      ~_FabProps: option(Js.t({..}))=?,
      ~icon: option(React.element)=?,
      ~id: option(string)=?,
      ~open_: option(bool)=?,
      ~_TooltipClasses: option(Js.t({..}))=?,
      ~tooltipOpen: option(bool)=?,
      ~tooltipPlacement: option(tooltipPlacement)=?,
      ~tooltipTitle: option(React.element)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~delay=?delay->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~_FabProps?,
    ~icon?,
    ~id?,
    ~_open=?open_,
    ~_TooltipClasses?,
    ~tooltipOpen?,
    ~tooltipPlacement=?
      tooltipPlacement->Belt.Option.map(v => tooltipPlacementToJs(v)),
    ~tooltipTitle?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "SpeedDialAction";
