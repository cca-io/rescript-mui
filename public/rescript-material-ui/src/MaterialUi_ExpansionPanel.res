module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type variant = [#elevation | #outlined]

module Classes = {
  type t = {
    "root": option<string>,
    "rounded": option<string>,
    "expanded": option<string>,
    "disabled": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~rounded: string=?,
    ~expanded: string=?,
    ~disabled: string=?,
    unit,
  ) => t = ""
}

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~elevation: MaterialUi_Types.Number.t=?,
  ~variant: variant=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~defaultExpanded: bool=?,
  ~disabled: bool=?,
  ~expanded: bool=?,
  ~onChange: (ReactEvent.Form.t, bool) => unit=?,
  ~square: bool=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ExpansionPanel"
