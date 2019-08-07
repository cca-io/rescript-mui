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
    ~component: 'union_rd7r=?,
    ~itemsAfterCollapse: 'number_l=?,
    ~itemsBeforeCollapse: 'number_t=?,
    ~maxItems: 'number_q=?,
    ~separator: React.element=?,
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
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~itemsAfterCollapse: option([ | `Int(int) | `Float(float)])=?,
      ~itemsBeforeCollapse: option([ | `Int(int) | `Float(float)])=?,
      ~maxItems: option([ | `Int(int) | `Float(float)])=?,
      ~separator: option(React.element)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
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
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Breadcrumbs";
