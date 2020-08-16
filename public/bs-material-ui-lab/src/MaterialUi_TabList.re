[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: 'children=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "TabList";
