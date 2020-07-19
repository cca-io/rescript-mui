type align = [ | `Alternate | `Left | `Right];

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "alignLeft": option(option(string)),
    "alignRight": option(option(string)),
    "alignAlternate": option(option(string)),
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
    ~align: option(
              [@bs.string] [
                | [@bs.as "alternate"] `Alternate
                | [@bs.as "left"] `Left
                | [@bs.as "right"] `Right
              ],
            )
              =?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Timeline";
