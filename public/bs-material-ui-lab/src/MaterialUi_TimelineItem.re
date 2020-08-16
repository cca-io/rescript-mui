module Classes = {
  type t = {
    .
    "root": option(string),
    "alignLeft": option(string),
    "alignRight": option(string),
    "alignAlternate": option(string),
    "missingOppositeContent": option(string),
    "content": option(string),
    "oppositeContent": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~alignLeft: string=?,
      ~alignRight: string=?,
      ~alignAlternate: string=?,
      ~missingOppositeContent: string=?,
      ~content: string=?,
      ~oppositeContent: string=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "TimelineItem";
