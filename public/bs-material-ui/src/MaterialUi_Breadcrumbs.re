module Classes = {
  type classesType =
    | Root(string)
    | Ol(string)
    | Li(string)
    | Separator(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Ol(_) => "ol"
    | Li(_) => "li"
    | Separator(_) => "separator";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Ol(className)
                         | Li(className)
                         | Separator(className) =>
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
    ~itemsAfterCollapse: 'number_y=?,
    ~itemsBeforeCollapse: 'number_7=?,
    ~maxItems: 'number_z=?,
    ~separator: React.element=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Breadcrumbs";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~itemsAfterCollapse: option([ | `Int(int) | `Float(float)])=?,
      ~itemsBeforeCollapse: option([ | `Int(int) | `Float(float)])=?,
      ~maxItems: option([ | `Int(int) | `Float(float)])=?,
      ~separator: option(React.element)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~itemsAfterCollapse=?
        itemsAfterCollapse->(
                              Belt.Option.map(v =>
                                MaterialUi_Helpers.unwrapValue(v)
                              )
                            ),
      ~itemsBeforeCollapse=?
        itemsBeforeCollapse->(
                               Belt.Option.map(v =>
                                 MaterialUi_Helpers.unwrapValue(v)
                               )
                             ),
      ~maxItems=?
        maxItems->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~separator?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
