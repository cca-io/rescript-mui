module BackdropComponent = {
  type t
  external string: string => t = "%identity"
  external backdropComponent_func: Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

module Container = {
  type t
  external custom: Dom.element => t = "%identity"
  external element: React.element => t = "%identity"
  external container_func: Types.any => t = "%identity"
}

module Classes = {
  type t = {
    "root": option<string>,
    "scrollPaper": option<string>,
    "scrollBody": option<string>,
    "container": option<string>,
    "paper": option<string>,
    "paperScrollPaper": option<string>,
    "paperScrollBody": option<string>,
    "paperWidthFalse": option<string>,
    "paperWidthXs": option<string>,
    "paperWidthSm": option<string>,
    "paperWidthMd": option<string>,
    "paperWidthLg": option<string>,
    "paperWidthXl": option<string>,
    "paperFullWidth": option<string>,
    "paperFullScreen": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~scrollPaper: string=?,
    ~scrollBody: string=?,
    ~container: string=?,
    ~paper: string=?,
    ~paperScrollPaper: string=?,
    ~paperScrollBody: string=?,
    ~paperWidthFalse: string=?,
    ~paperWidthXs: string=?,
    ~paperWidthSm: string=?,
    ~paperWidthMd: string=?,
    ~paperWidthLg: string=?,
    ~paperWidthXl: string=?,
    ~paperFullWidth: string=?,
    ~paperFullScreen: string=?,
    unit,
  ) => t = ""
}

module MaxWidth: {
  type t
  let lg: t
  let md: t
  let sm: t
  let xl: t
  let xs: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let lg = Any("lg")
  let md = Any("md")
  let sm = Any("sm")
  let xl = Any("xl")
  let xs = Any("xs")
  let \"false" = Any(false)
}

module PaperComponent = {
  type t
  external string: string => t = "%identity"
  external paperComponent_func: Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

type scroll = [#body | #paper]

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

module TransitionDuration_shape = {
  type t = {"appear": option<Number.t>, "enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~appear: Number.t=?, ~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
}

module TransitionDuration = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~\"BackdropComponent": BackdropComponent.t=?,
  ~closeAfterTransition: bool=?,
  ~container: Container.t=?,
  ~disableAutoFocus: bool=?,
  ~disableEnforceFocus: bool=?,
  ~disablePortal: bool=?,
  ~disableRestoreFocus: bool=?,
  ~disableScrollLock: bool=?,
  ~hideBackdrop: bool=?,
  ~keepMounted: bool=?,
  ~manager: {..}=?,
  ~onRendered: ReactEvent.Synthetic.t => unit=?,
  ~\"aria-describedby": string=?,
  ~\"aria-labelledby": string=?,
  ~\"BackdropProps": {..}=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~disableBackdropClick: bool=?,
  ~disableEscapeKeyDown: bool=?,
  ~fullScreen: bool=?,
  ~fullWidth: bool=?,
  ~maxWidth: MaxWidth.t=?,
  ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~onEnter: ReactEvent.Synthetic.t => unit=?,
  ~onEntered: ReactEvent.Synthetic.t => unit=?,
  ~onEntering: ReactEvent.Synthetic.t => unit=?,
  ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onExit: ReactEvent.Synthetic.t => unit=?,
  ~onExited: ReactEvent.Synthetic.t => unit=?,
  ~onExiting: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool,
  ~\"PaperComponent": PaperComponent.t=?,
  ~\"PaperProps": {..}=?,
  ~scroll: scroll=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Dialog"
