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
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
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
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~cols: 'number_1=?,
    ~component: 'union_rgui=?,
    ~rows: 'number_u=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/GridList/GridListTile"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~cols: option([ | `Int(int) | `Float(float)])=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~rows: option([ | `Int(int) | `Float(float)])=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~cols=?
          Js.Option.map((. v) => MaterialUi_Helpers.unwrapValue(v), cols),
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~rows=?
          Js.Option.map((. v) => MaterialUi_Helpers.unwrapValue(v), rows),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
