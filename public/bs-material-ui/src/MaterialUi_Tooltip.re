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
    | Tooltip(string)
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
    | Tooltip(_) => "tooltip"
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
                         | Tooltip(className)
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
    ~children: 'children=?,
    ~disableFocusListener: bool=?,
    ~disableHoverListener: bool=?,
    ~disableTouchListener: bool=?,
    ~enterDelay: 'number_l=?,
    ~enterTouchDelay: 'number_x=?,
    ~id: string=?,
    ~interactive: bool=?,
    ~leaveDelay: 'number_c=?,
    ~leaveTouchDelay: 'number_5=?,
    ~onClose: 'any_rs7w=?,
    ~onOpen: 'any_rww4=?,
    ~_open: bool=?,
    ~placement: string=?,
    ~_PopperProps: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~title: React.element,
    ~_TransitionProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Tooltip";

[@react.component]
let make =
    (
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
      ~theme: option(Js.t({..}))=?,
      ~title: React.element,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
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
      ~theme?,
      ~title,
      ~_TransitionProps?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
