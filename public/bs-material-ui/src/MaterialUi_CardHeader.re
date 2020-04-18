module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    avatar: string,
    [@bs.optional]
    action: string,
    [@bs.optional]
    content: string,
    [@bs.optional]
    title: string,
    [@bs.optional]
    subheader: string,
  };
  let make = t;
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
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~disableTypography: option(bool)=?,
    ~subheader: option(React.element)=?,
    ~subheaderTypographyProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~title: option(React.element)=?,
    ~titleTypographyProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "CardHeader";
