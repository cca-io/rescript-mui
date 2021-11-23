@unboxed
type any = Any.t

@deprecated("Use Any.unsafeGetValue or a more type-specific helper from the Any module instead.")
let anyUnpack: any => 'a

module Number: {
  type t

  let float: float => t
  let int: int => t
}
