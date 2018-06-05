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
    | Open(string)
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
    | Open(_) => "open"
    | Tooltip(_) => "tooltip"
    | Touch(_) => "touch"
    | TooltipPlacementLeft(_) => "tooltipPlacementLeft"
    | TooltipPlacementRight(_) => "tooltipPlacementRight"
    | TooltipPlacementTop(_) => "tooltipPlacementTop"
    | TooltipPlacementBottom(_) => "tooltipPlacementBottom";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Popper(className)
           | Open(className)
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
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~disableFocusListener: bool=?,
    ~disableHoverListener: bool=?,
    ~disableTouchListener: bool=?,
    ~enterDelay: 'number_z=?,
    ~enterTouchDelay: 'number_3=?,
    ~id: string=?,
    ~leaveDelay: 'number_x=?,
    ~leaveTouchDelay: 'number_f=?,
    ~onClose: 'any_rzgu=?,
    ~onOpen: 'any_riav=?,
    ~_open: bool=?,
    ~placement: string=?,
    ~_PopperProps: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~title: ReasonReact.reactElement,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/Tooltip/Tooltip"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~className: option(string)=?,
      ~disableFocusListener: option(bool)=?,
      ~disableHoverListener: option(bool)=?,
      ~disableTouchListener: option(bool)=?,
      ~enterDelay: option([ | `Int(int) | `Float(float)])=?,
      ~enterTouchDelay: option([ | `Int(int) | `Float(float)])=?,
      ~id: option(string)=?,
      ~leaveDelay: option([ | `Int(int) | `Float(float)])=?,
      ~leaveTouchDelay: option([ | `Int(int) | `Float(float)])=?,
      ~onClose: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onOpen: option(ReactEventRe.Synthetic.t => unit)=?,
      ~open_: option(bool)=?,
      ~placement: option(placement)=?,
      ~_PopperProps: option(Js.t({..}))=?,
      ~theme: option(Js.t({..}))=?,
      ~title: ReasonReact.reactElement,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~disableFocusListener?,
        ~disableHoverListener?,
        ~disableTouchListener?,
        ~enterDelay=?
          enterDelay
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~enterTouchDelay=?
          enterTouchDelay
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~id?,
        ~leaveDelay=?
          leaveDelay
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~leaveTouchDelay=?
          leaveTouchDelay
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~onClose?,
        ~onOpen?,
        ~_open=?open_,
        ~placement=?placement |. Belt.Option.map(v => placementToJs(v)),
        ~_PopperProps?,
        ~theme?,
        ~title,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
