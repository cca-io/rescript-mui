@unboxed
type rec any = Any('a): any

let anyUnpack = x =>
  switch x {
  | Any(v) => v->Obj.magic
  }
