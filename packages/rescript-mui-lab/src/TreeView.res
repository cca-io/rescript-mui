module DefaultSelected = {
  type t
  external arrayOf: array<string> => t = "%identity"
  external string: string => t = "%identity"
}

module Selected = {
  type t
  external arrayOf: array<string> => t = "%identity"
  external string: string => t = "%identity"
}

module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Mui.Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Mui.Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

@react.component @module("@mui/lab")
external make: (
  ~children: React.element=?,
  ~className: string=?,
  ~defaultCollapseIcon: React.element=?,
  ~defaultEndIcon: React.element=?,
  ~defaultExpanded: array<string>=?,
  ~defaultExpandIcon: React.element=?,
  ~defaultParentIcon: React.element=?,
  ~defaultSelected: DefaultSelected.t=?,
  ~disabledItemsFocusable: bool=?,
  ~disableSelection: bool=?,
  ~expanded: array<string>=?,
  ~id: string=?,
  ~multiSelect: bool=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onNodeFocus: ({..}, string) => unit=?,
  ~onNodeSelect: ({..}, array<string>) => unit=?,
  ~onNodeToggle: ({..}, array<string>) => unit=?,
  ~selected: Selected.t=?,
  ~sx: Sx.t=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TreeView"
