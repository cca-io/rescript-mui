module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "avatar": option(option(string)),
    "action": option(option(string)),
    "content": option(option(string)),
    "title": option(option(string)),
    "subheader": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~avatar: string=?,
      ~action: string=?,
      ~content: string=?,
      ~title: string=?,
      ~subheader: string=?,
      unit
    ) =>
    t;
};

module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~action: option(React.element)=?,
    ~avatar: option(React.element)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~disableTypography: option(bool)=?,
    ~subheader: option(React.element)=?,
    ~subheaderTypographyProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~title: option(React.element)=?,
    ~titleTypographyProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "CardHeader";
