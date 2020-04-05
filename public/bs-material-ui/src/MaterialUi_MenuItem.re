[@bs.deriving jsConverter]
type alignItems = [
  | [@bs.as "flex-start"] `Flex_Start
  | [@bs.as "center"] `Center
];

module Classes = {
  type classesType =
    | Root(string)
    | Gutters(string)
    | Selected(string)
    | Dense(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Gutters(_) => "gutters"
    | Selected(_) => "selected"
    | Dense(_) => "dense";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Gutters(className)
                         | Selected(className)
                         | Dense(className) =>
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
    ~alignItems: string=?,
    ~autoFocus: bool=?,
    ~button: bool=?,
    ~_ContainerComponent: 'union_rwfv=?,
    ~_ContainerProps: Js.t({..})=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~id: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~component: 'union_rx1v=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~_ListItemClasses: Js.t({..})=?,
    ~role: string=?,
    ~selected: bool=?,
    ~tabIndex: 'number_5=?,
    ~value: 'union_rbkq=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~alignItems: option(alignItems)=?,
      ~autoFocus: option(bool)=?,
      ~button: option(bool)=?,
      ~_ContainerComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~_ContainerProps: option(Js.t({..}))=?,
      ~divider: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~id: option(string)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~dense: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableGutters: option(bool)=?,
      ~_ListItemClasses: option(Js.t({..}))=?,
      ~role: option(string)=?,
      ~selected: option(bool)=?,
      ~tabIndex: option([ | `Int(int) | `Float(float)])=?,
      ~value:
         option(
           [
             | `String(string)
             | `Int(int)
             | `Float(float)
             | `Array(array(string))
           ],
         )=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~alignItems=?alignItems->(Belt.Option.map(v => alignItemsToJs(v))),
    ~autoFocus?,
    ~button?,
    ~_ContainerComponent=?
      _ContainerComponent->(
                             Belt.Option.map(v =>
                               MaterialUi_Helpers.unwrapValue(v)
                             )
                           ),
    ~_ContainerProps?,
    ~divider?,
    ~focusVisibleClassName?,
    ~id?,
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~dense?,
    ~disabled?,
    ~disableGutters?,
    ~_ListItemClasses?,
    ~role?,
    ~selected?,
    ~tabIndex=?
      tabIndex->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~onFocus?,
    ~onClick?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "MenuItem";
