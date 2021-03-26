type actionPosition = [ | `Left | `Right];

module Classes = {
  type t = {
    .
    "root": option(string),
    "titlePositionBottom": option(string),
    "titlePositionTop": option(string),
    "rootSubtitle": option(string),
    "titleWrap": option(string),
    "titleWrapActionPosLeft": option(string),
    "titleWrapActionPosRight": option(string),
    "title": option(string),
    "subtitle": option(string),
    "actionIcon": option(string),
    "actionIconActionPosLeft": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~titlePositionBottom: string=?,
      ~titlePositionTop: string=?,
      ~rootSubtitle: string=?,
      ~titleWrap: string=?,
      ~titleWrapActionPosLeft: string=?,
      ~titleWrapActionPosRight: string=?,
      ~title: string=?,
      ~subtitle: string=?,
      ~actionIcon: string=?,
      ~actionIconActionPosLeft: string=?,
      unit
    ) =>
    t;
};

type titlePosition = [ | `Bottom | `Top];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~actionIcon: React.element=?,
    ~actionPosition: [@bs.string] [
                       | [@bs.as "left"] `Left
                       | [@bs.as "right"] `Right
                     ]
                       =?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~subtitle: React.element=?,
    ~title: React.element=?,
    ~titlePosition: [@bs.string] [
                      | [@bs.as "bottom"] `Bottom
                      | [@bs.as "top"] `Top
                    ]
                      =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "GridListTileBar";
