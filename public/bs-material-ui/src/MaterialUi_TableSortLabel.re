[@bs.deriving jsConverter]
type direction = [ | [@bs.as "asc"] `Asc | [@bs.as "desc"] `Desc];

module Classes = {
  type classesType =
    | Root(string)
    | Active(string)
    | Icon(string)
    | IconDirectionDesc(string)
    | IconDirectionAsc(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Active(_) => "active"
    | Icon(_) => "icon"
    | IconDirectionDesc(_) => "iconDirectionDesc"
    | IconDirectionAsc(_) => "iconDirectionAsc";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Active(className)
                         | Icon(className)
                         | IconDirectionDesc(className)
                         | IconDirectionAsc(className) =>
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
    ~active: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~direction: string=?,
    ~hideSortIcon: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "TableSortLabel";

[@react.component]
let make =
    (
      ~active: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~direction: option(direction)=?,
      ~hideSortIcon: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~active?,
      ~children?,
      ~className?,
      ~direction=?direction->(Belt.Option.map(v => directionToJs(v))),
      ~hideSortIcon?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
