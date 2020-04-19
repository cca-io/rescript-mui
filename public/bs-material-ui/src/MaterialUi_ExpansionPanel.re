[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "elevation"] `Elevation
  | [@bs.as "outlined"] `Outlined
];

module Classes = {
  type classesType =
    | Root(string)
    | Rounded(string)
    | Expanded(string)
    | Disabled(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Rounded(_) => "rounded"
    | Expanded(_) => "expanded"
    | Disabled(_) => "disabled";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Rounded(className)
                         | Expanded(className)
                         | Disabled(className) =>
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
    ~component: 'union_r8du=?,
    ~elevation: 'number_y=?,
    ~variant: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~defaultExpanded: bool=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~onChange: 'any_rbf9=?,
    ~square: bool=?,
    ~_TransitionComponent: 'union_r5d2=?,
    ~_TransitionProps: Js.t({..})=?,
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
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~variant: option(variant)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~defaultExpanded: option(bool)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~square: option(bool)=?,
      ~_TransitionComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~children?,
    ~className?,
    ~defaultExpanded?,
    ~disabled?,
    ~expanded?,
    ~onChange?,
    ~square?,
    ~_TransitionComponent=?
      _TransitionComponent->(
                              Belt.Option.map(v =>
                                MaterialUi_Helpers.unwrapValue(v)
                              )
                            ),
    ~_TransitionProps?,
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ExpansionPanel";
