type breakpoints<'a> = {
  lg?: 'a,
  md?: 'a,
  sm?: 'a,
  xl?: 'a,
  xs?: 'a,
}

@unboxed
type value = Int(int)

@unboxed
type t = Array(array<value>) | Object(breakpoints<value>) | ...value
