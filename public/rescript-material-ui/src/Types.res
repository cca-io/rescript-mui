type any = Any.t

let anyUnpack = x => Any.unsafeGetValue(x)

module Number = {
  type t

  external float: float => t = "%identity"
  external int: int => t = "%identity"
}
