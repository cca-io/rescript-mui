[@bs.deriving jsConverter]
type actionPosition = [ | [@bs.as "left"] `Left | [@bs.as "right"] `Right];

[@bs.deriving jsConverter]
type titlePosition = [ | [@bs.as "bottom"] `Bottom | [@bs.as "top"] `Top];

module Classes = {
  type classesType =
    | Root(string)
    | TitlePositionBottom(string)
    | TitlePositionTop(string)
    | RootSubtitle(string)
    | TitleWrap(string)
    | TitleWrapActionPosLeft(string)
    | TitleWrapActionPosRight(string)
    | Title(string)
    | Subtitle(string)
    | ActionIcon(string)
    | ActionIconActionPosLeft(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | TitlePositionBottom(_) => "titlePositionBottom"
    | TitlePositionTop(_) => "titlePositionTop"
    | RootSubtitle(_) => "rootSubtitle"
    | TitleWrap(_) => "titleWrap"
    | TitleWrapActionPosLeft(_) => "titleWrapActionPosLeft"
    | TitleWrapActionPosRight(_) => "titleWrapActionPosRight"
    | Title(_) => "title"
    | Subtitle(_) => "subtitle"
    | ActionIcon(_) => "actionIcon"
    | ActionIconActionPosLeft(_) => "actionIconActionPosLeft";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | TitlePositionBottom(className)
                         | TitlePositionTop(className)
                         | RootSubtitle(className)
                         | TitleWrap(className)
                         | TitleWrapActionPosLeft(className)
                         | TitleWrapActionPosRight(className)
                         | Title(className)
                         | Subtitle(className)
                         | ActionIcon(className)
                         | ActionIconActionPosLeft(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~actionIcon: React.element=?,
    ~actionPosition: string=?,
    ~className: string=?,
    ~subtitle: React.element=?,
    ~title: React.element=?,
    ~titlePosition: string=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~actionIcon: option(React.element)=?,
      ~actionPosition: option(actionPosition)=?,
      ~className: option(string)=?,
      ~subtitle: option(React.element)=?,
      ~title: option(React.element)=?,
      ~titlePosition: option(titlePosition)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~actionIcon?,
    ~actionPosition=?
      actionPosition->(Belt.Option.map(v => actionPositionToJs(v))),
    ~className?,
    ~subtitle?,
    ~title?,
    ~titlePosition=?
      titlePosition->(Belt.Option.map(v => titlePositionToJs(v))),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "GridListTileBar";
