type align = [ | `Alternate | `Left | `Right];

module Classes = {
  type t = {
    .
    "root": option(string),
    "alignLeft": option(string),
    "alignRight": option(string),
    "alignAlternate": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~alignLeft: string=?,
      ~alignRight: string=?,
      ~alignAlternate: string=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~align: [@bs.string] [
              | [@bs.as "alternate"] `Alternate
              | [@bs.as "left"] `Left
              | [@bs.as "right"] `Right
            ]
              =?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Timeline";
