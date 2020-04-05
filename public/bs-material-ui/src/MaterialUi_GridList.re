[@bs.deriving jsConverter]
type cellHeight_enum = [ | [@bs.as "auto"] `Auto];

module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className) =>
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
    ~cellHeight: 'union_ra25=?,
    ~children: 'children=?,
    ~className: string=?,
    ~cols: 'number_b=?,
    ~component: 'union_rls6=?,
    ~spacing: 'number_n=?,
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
      ~cellHeight:
         option([ | `Int(int) | `Float(float) | `Enum(cellHeight_enum)])=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~cols: option([ | `Int(int) | `Float(float)])=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~spacing: option([ | `Int(int) | `Float(float)])=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~cellHeight=?
      cellHeight->(
                    Belt.Option.map(v =>
                      switch (v) {
                      | `Enum(v) =>
                        MaterialUi_Helpers.unwrapValue(
                          `String(cellHeight_enumToJs(v)),
                        )

                      | v => MaterialUi_Helpers.unwrapValue(v)
                      }
                    )
                  ),
    ~children?,
    ~className?,
    ~cols=?cols->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~spacing=?
      spacing->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "GridList";
