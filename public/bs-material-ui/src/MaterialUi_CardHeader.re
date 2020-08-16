module Classes = {
  type t = {
    .
    "root": option(string),
    "avatar": option(string),
    "action": option(string),
    "content": option(string),
    "title": option(string),
    "subheader": option(string),
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
    ~action: React.element=?,
    ~avatar: React.element=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~disableTypography: bool=?,
    ~subheader: React.element=?,
    ~subheaderTypographyProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~title: React.element=?,
    ~titleTypographyProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "CardHeader";
