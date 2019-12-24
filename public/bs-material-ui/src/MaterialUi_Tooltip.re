[@bs.deriving jsConverter]
type placement = [
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
    | Popper(string)
    | PopperInteractive(string)
    | PopperArrow(string)
    | Tooltip(string)
    | TooltipArrow(string)
    | Arrow(string)
    | Touch(string)
    | TooltipPlacementLeft(string)
    | TooltipPlacementRight(string)
    | TooltipPlacementTop(string)
    | TooltipPlacementBottom(string);
  type t = list(classesType);
  let to_string =
    fun
    | Popper(_) => "popper"
    | PopperInteractive(_) => "popperInteractive"
    | PopperArrow(_) => "popperArrow"
    | Tooltip(_) => "tooltip"
    | TooltipArrow(_) => "tooltipArrow"
    | Arrow(_) => "arrow"
    | Touch(_) => "touch"
    | TooltipPlacementLeft(_) => "tooltipPlacementLeft"
    | TooltipPlacementRight(_) => "tooltipPlacementRight"
    | TooltipPlacementTop(_) => "tooltipPlacementTop"
    | TooltipPlacementBottom(_) => "tooltipPlacementBottom";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Popper(className)
                         | PopperInteractive(className)
                         | PopperArrow(className)
                         | Tooltip(className)
                         | TooltipArrow(className)
                         | Arrow(className)
                         | Touch(className)
                         | TooltipPlacementLeft(className)
                         | TooltipPlacementRight(className)
                         | TooltipPlacementTop(className)
                         | TooltipPlacementBottom(className) =>
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
    ~arrow: bool=?,
    ~children: 'children=?,
    ~disableFocusListener: bool=?,
    ~disableHoverListener: bool=?,
    ~disableTouchListener: bool=?,
    ~enterDelay: 'number_s=?,
    ~enterTouchDelay: 'number_f=?,
    ~id: string=?,
    ~interactive: bool=?,
    ~leaveDelay: 'number_i=?,
    ~leaveTouchDelay: 'number_i=?,
    ~onClose: 'any_rqrn=?,
    ~onOpen: 'any_r5it=?,
    ~_open: bool=?,
    ~placement: string=?,
    ~_PopperProps: Js.t({..})=?,
    ~title: React.element,
    ~_TransitionComponent: 'union_revx=?,
    ~_TransitionProps: Js.t({..})=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~arrow: option(bool)=?,
      ~children: option('children)=?,
      ~disableFocusListener: option(bool)=?,
      ~disableHoverListener: option(bool)=?,
      ~disableTouchListener: option(bool)=?,
      ~enterDelay: option([ | `Int(int) | `Float(float)])=?,
      ~enterTouchDelay: option([ | `Int(int) | `Float(float)])=?,
      ~id: option(string)=?,
      ~interactive: option(bool)=?,
      ~leaveDelay: option([ | `Int(int) | `Float(float)])=?,
      ~leaveTouchDelay: option([ | `Int(int) | `Float(float)])=?,
      ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
      ~onOpen: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: option(bool)=?,
      ~placement: option(placement)=?,
      ~_PopperProps: option(Js.t({..}))=?,
      ~title: React.element,
      ~_TransitionComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~arrow?,
    ~children?,
    ~disableFocusListener?,
    ~disableHoverListener?,
    ~disableTouchListener?,
    ~enterDelay=?
      enterDelay->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~enterTouchDelay=?
      enterTouchDelay->(
                         Belt.Option.map(v =>
                           MaterialUi_Helpers.unwrapValue(v)
                         )
                       ),
    ~id?,
    ~interactive?,
    ~leaveDelay=?
      leaveDelay->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~leaveTouchDelay=?
      leaveTouchDelay->(
                         Belt.Option.map(v =>
                           MaterialUi_Helpers.unwrapValue(v)
                         )
                       ),
    ~onClose?,
    ~onOpen?,
    ~_open=?open_,
    ~placement=?placement->(Belt.Option.map(v => placementToJs(v))),
    ~_PopperProps?,
    ~title,
    ~_TransitionComponent=?
      _TransitionComponent->(
                              Belt.Option.map(v =>
                                MaterialUi_Helpers.unwrapValue(v)
                              )
                            ),
    ~_TransitionProps?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Tooltip";
