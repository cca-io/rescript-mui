module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "avatar": option(option(string)),
  };
  [@bs.obj] external make: (~root: string=?, ~avatar: string=?, unit) => t;
};

module Spacing_enum: {
  type t;
  let medium: t;
  let small: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let medium = Any("medium");
  let small = Any("small");
};

module Spacing: {
  type t;
  let enum: Spacing_enum.t => t;
  let int: int => t;
  let float: float => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: Spacing_enum.t) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
};

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~max: option(MaterialUi_Types.Number.t)=?,
    ~spacing: option(Spacing.t)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "AvatarGroup";
