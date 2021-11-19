@unboxed
type rec any = Any('a): any

let anyUnpack = x =>
  switch x {
  | Any(v) => v->Obj.magic
  }

module Number = {
  type t

  external float: float => t = "%identity"
  external int: int => t = "%identity"
}
