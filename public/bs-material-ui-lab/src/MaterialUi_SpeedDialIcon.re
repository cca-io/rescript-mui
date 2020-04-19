module Classes = {
  type classesType =
    | Root(string)
    | Icon(string)
    | IconOpen(string)
    | IconWithOpenIconOpen(string)
    | OpenIcon(string)
    | OpenIconOpen(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Icon(_) => "icon"
    | IconOpen(_) => "iconOpen"
    | IconWithOpenIconOpen(_) => "iconWithOpenIconOpen"
    | OpenIcon(_) => "openIcon"
    | OpenIconOpen(_) => "openIconOpen";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Icon(className)
                         | IconOpen(className)
                         | IconWithOpenIconOpen(className)
                         | OpenIcon(className)
                         | OpenIconOpen(className) =>
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
    ~className: string=?,
    ~icon: React.element=?,
    ~_open: bool=?,
    ~openIcon: React.element=?,
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
      ~className: option(string)=?,
      ~icon: option(React.element)=?,
      ~open_: option(bool)=?,
      ~openIcon: option(React.element)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~icon?,
    ~_open=?open_,
    ~openIcon?,
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "SpeedDialIcon";
