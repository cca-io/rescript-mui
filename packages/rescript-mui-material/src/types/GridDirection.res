type breakpoints<'a> = {
  lg?: 'a,
  md?: 'a,
  sm?: 'a,
  xl?: 'a,
  xs?: 'a,
}

@unboxed
type value =
  | @as("row") Row
  | @as("row-reverse") RowReverse

@unboxed
type t = Array(array<value>) | Object(breakpoints<value>) | ...value
