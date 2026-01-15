type breakpoints<'a> = {
  lg?: 'a,
  md?: 'a,
  sm?: 'a,
  xl?: 'a,
  xs?: 'a,
}

@unboxed
type t = Array(array<int>) | Object(breakpoints<int>) | Int(int)
