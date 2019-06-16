module Classes = {
  type classesType =
    | Root(string)
    | Tile(string)
    | ImgFullHeight(string)
    | ImgFullWidth(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Tile(_) => "tile"
    | ImgFullHeight(_) => "imgFullHeight"
    | ImgFullWidth(_) => "imgFullWidth";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Tile(className)
                         | ImgFullHeight(className)
                         | ImgFullWidth(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~cols: 'number_s=?,
    ~rows: 'number_9=?,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~cols: option([ | `Int(int) | `Float(float)])=?,
      ~rows: option([ | `Int(int) | `Float(float)])=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~cols=?cols->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "GridListTile";
