module Classes = {
  type t = {
    "root": option<string>,
    "entered": option<string>,
    "hidden": option<string>,
    "wrapper": option<string>,
    "wrapperInner": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~entered: string=?,
    ~hidden: string=?,
    ~wrapper: string=?,
    ~wrapperInner: string=?,
    unit,
  ) => t = ""
}

module CollapsedSize = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type timeout_enum = [#auto]

module Timeout_shape = {
  type t = {"appear": option<Number.t>, "enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~appear: Number.t=?, ~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
}

module Timeout = {
  type t
  external enum: timeout_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: Timeout_shape.t => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~collapsedHeight: Number.t=?,
  ~collapsedSize: CollapsedSize.t=?,
  ~component: Component.t=?,
  ~disableStrictModeCompat: bool=?,
  ~\"in": bool=?,
  ~onEnter: ReactEvent.Synthetic.t => unit=?,
  ~onEntered: ReactEvent.Synthetic.t => unit=?,
  ~onEntering: ReactEvent.Synthetic.t => unit=?,
  ~onExit: ReactEvent.Synthetic.t => unit=?,
  ~onExited: ReactEvent.Synthetic.t => unit=?,
  ~onExiting: ReactEvent.Synthetic.t => unit=?,
  ~style: ReactDOM.Style.t=?,
  ~timeout: Timeout.t=?,
  ~id: string=?,
  ~mountOnEnter: bool=?,
  ~unmountOnExit: bool=?,
  ~appear: bool=?,
  ~enter: bool=?,
  ~exit: bool=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Collapse"
