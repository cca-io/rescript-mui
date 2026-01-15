type breakpoints<'a> = {
  lg?: 'a,
  md?: 'a,
  sm?: 'a,
  xl?: 'a,
  xs?: 'a,
}

@unboxed
type value =
  | @as("auto") Auto
  | Int(int)

type container = breakpoints<value>

@unboxed
type t = Array(array<value>) | Object(container) | ...value
