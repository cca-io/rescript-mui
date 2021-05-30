type actionPosition = [#left | #right]

module Classes = {
  type t = {
    "root": option<string>,
    "titlePositionBottom": option<string>,
    "titlePositionTop": option<string>,
    "rootSubtitle": option<string>,
    "titleWrap": option<string>,
    "titleWrapActionPosLeft": option<string>,
    "titleWrapActionPosRight": option<string>,
    "title": option<string>,
    "subtitle": option<string>,
    "actionIcon": option<string>,
    "actionIconActionPosLeft": option<string>,
  }
  @obj
  external make: (
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
    unit,
  ) => t = ""
}

type titlePosition = [#bottom | #top]

@react.component @module("@material-ui/core")
external make: (
  ~actionIcon: React.element=?,
  ~actionPosition: actionPosition=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~subtitle: React.element=?,
  ~title: React.element=?,
  ~titlePosition: titlePosition=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "GridListTileBar"
