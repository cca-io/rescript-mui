type implementation = [#css | #js]

type initialWidth = [#xs | #sm | #md | #lg | #xl]

type only_enum = [#xs | #sm | #md | #lg | #xl]

type only_arrayOf = [#xs | #sm | #md | #lg | #xl]

module Only = {
  type t
  external enum: only_enum => t = "%identity"
  external arrayOf: array<only_arrayOf> => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~children: React.element=?,
  ~implementation: implementation=?,
  ~initialWidth: initialWidth=?,
  ~lgDown: bool=?,
  ~lgUp: bool=?,
  ~mdDown: bool=?,
  ~mdUp: bool=?,
  ~only: Only.t=?,
  ~smDown: bool=?,
  ~smUp: bool=?,
  ~xlDown: bool=?,
  ~xlUp: bool=?,
  ~xsDown: bool=?,
  ~xsUp: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Hidden"
