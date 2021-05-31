type implementation = [#js | #css]

type initialWidth = [#xs | #sm | #md | #lg | #xl]

module Only_enum: {
  type t
  let xs: t
  let sm: t
  let md: t
  let lg: t
  let xl: t
} = {
  @unboxed
  type rec t = Any('a): t

  let xs = Any("xs")
  let sm = Any("sm")
  let md = Any("md")
  let lg = Any("lg")
  let xl = Any("xl")
}

module Only_arrayOf: {
  type t
  let xs: t
  let sm: t
  let md: t
  let lg: t
  let xl: t
} = {
  @unboxed
  type rec t = Any('a): t

  let xs = Any("xs")
  let sm = Any("sm")
  let md = Any("md")
  let lg = Any("lg")
  let xl = Any("xl")
}

module Only: {
  type t
  let enum: Only_enum.t => t
  let arrayOf: array<Only_arrayOf.t> => t
} = {
  @unboxed
  type rec t = Any('a): t
  let enum = (v: Only_enum.t) => Any(v)
  let arrayOf = (v: array<Only_arrayOf.t>) => Any(v)
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~className: string=?,
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
