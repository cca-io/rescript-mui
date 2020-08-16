[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: 'children=?,
    ~value: string,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "TabContext";
