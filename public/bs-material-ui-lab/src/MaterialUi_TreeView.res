module Classes = {
  type t = {"root": option<string>}
  @obj external make: (~root: string=?, unit) => t = ""
}

module DefaultSelected: {
  type t
  let arrayOf: array<string> => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let arrayOf = (v: array<string>) => Any(v)
  let string = (v: string) => Any(v)
}

module Value: {
  type t
  let array: array<MaterialUi_Types.any> => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let array = (v: array<MaterialUi_Types.any>) => Any(v)
  let string = (v: string) => Any(v)
}

module Selected: {
  type t
  let arrayOf: array<string> => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let arrayOf = (v: array<string>) => Any(v)
  let string = (v: string) => Any(v)
}

@react.component @module("@material-ui/lab")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~defaultCollapseIcon: React.element=?,
  ~defaultEndIcon: React.element=?,
  ~defaultExpanded: array<string>=?,
  ~defaultExpandIcon: React.element=?,
  ~defaultParentIcon: React.element=?,
  ~defaultSelected: DefaultSelected.t=?,
  ~disableSelection: bool=?,
  ~expanded: array<string>=?,
  ~multiSelect: bool=?,
  ~onNodeSelect: ({..}, Value.t) => unit=?,
  ~onNodeToggle: ({..}, array<MaterialUi_Types.any>) => unit=?,
  ~selected: Selected.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TreeView"
