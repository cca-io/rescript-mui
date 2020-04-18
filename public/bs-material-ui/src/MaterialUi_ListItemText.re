module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    multiline: string,
    [@bs.optional]
    dense: string,
    [@bs.optional]
    inset: string,
    [@bs.optional]
    primary: string,
    [@bs.optional]
    secondary: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~disableTypography: option(bool)=?,
    ~inset: option(bool)=?,
    ~primary: option(React.element)=?,
    ~primaryTypographyProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~secondary: option(React.element)=?,
    ~secondaryTypographyProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ListItemText";
