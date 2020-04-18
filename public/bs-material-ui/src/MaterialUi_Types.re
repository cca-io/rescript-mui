[@unboxed]
type any =
  | Any('a): any;
let anyUnpack =
  fun
  | Any(v) => v->Obj.magic;
module Number: {
  type t;
  let float: float => t;
  let int: int => t;
} = {
  [@unboxed]
  type t =
    | Number('a): t;
  let float = (v: float) => Number(v);
  let int = (v: int) => Number(v);
};