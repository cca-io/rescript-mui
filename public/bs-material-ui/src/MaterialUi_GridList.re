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
    ~cellHeight: 'union_rkv3=?,
    ~children: 'children=?,
    ~className: string=?,
    ~cols: 'number_h=?,
    ~component: 'union_rh3y=?,
    ~spacing: 'number_w=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

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
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~spacing: option([ | `Int(int) | `Float(float)])=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
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
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "GridList";
