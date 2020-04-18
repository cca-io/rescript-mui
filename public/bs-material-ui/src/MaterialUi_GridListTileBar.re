module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    titlePositionBottom: string,
    [@bs.optional]
    titlePositionTop: string,
    [@bs.optional]
    rootSubtitle: string,
    [@bs.optional]
    titleWrap: string,
    [@bs.optional]
    titleWrapActionPosLeft: string,
    [@bs.optional]
    titleWrapActionPosRight: string,
    [@bs.optional]
    title: string,
    [@bs.optional]
    subtitle: string,
    [@bs.optional]
    actionIcon: string,
    [@bs.optional]
    actionIconActionPosLeft: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~actionIcon: option(React.element)=?,
    ~actionPosition: option(
                       [@bs.string] [
                         | [@bs.as "left"] `Left
                         | [@bs.as "right"] `Right
                       ],
                     )
                       =?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~subtitle: option(React.element)=?,
    ~title: option(React.element)=?,
    ~titlePosition: option(
                      [@bs.string] [
                        | [@bs.as "bottom"] `Bottom
                        | [@bs.as "top"] `Top
                      ],
                    )
                      =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "GridListTileBar";
