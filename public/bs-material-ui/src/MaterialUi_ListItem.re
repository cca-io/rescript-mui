[@bs.deriving jsConverter]
type alignItems = [
  | [@bs.as "flex-start"] `Flex_Start
  | [@bs.as "center"] `Center
];

module Classes = {
  type classesType =
    | Root(string)
    | Container(string)
    | FocusVisible(string)
    | Dense(string)
    | AlignItemsFlexStart(string)
    | Disabled(string)
    | Divider(string)
    | Gutters(string)
    | Button(string)
    | SecondaryAction(string)
    | Selected(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Container(_) => "container"
    | FocusVisible(_) => "focusVisible"
    | Dense(_) => "dense"
    | AlignItemsFlexStart(_) => "alignItemsFlexStart"
    | Disabled(_) => "disabled"
    | Divider(_) => "divider"
    | Gutters(_) => "gutters"
    | Button(_) => "button"
    | SecondaryAction(_) => "secondaryAction"
    | Selected(_) => "selected";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Container(className)
                         | FocusVisible(className)
                         | Dense(className)
                         | AlignItemsFlexStart(className)
                         | Disabled(className)
                         | Divider(className)
                         | Gutters(className)
                         | Button(className)
                         | SecondaryAction(className)
                         | Selected(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~component: 'union_rvd8=?,
    ~_ContainerComponent: 'union_r77s=?,
    ~_ContainerProps: Js.t({..})=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~selected: bool=?,
    ~id: string=?,
    ~value: 'union_rsl5=?,
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
      ~_ContainerComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~_ContainerProps: option(Js.t({..}))=?,
      ~dense: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableGutters: option(bool)=?,
      ~divider: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~selected: option(bool)=?,
      ~id: option(string)=?,
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
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~_ContainerComponent=?
      _ContainerComponent->(
                             Belt.Option.map(v =>
                               MaterialUi_Helpers.unwrapValue(v)
                             )
                           ),
    ~_ContainerProps?,
    ~dense?,
    ~disabled?,
    ~disableGutters?,
    ~divider?,
    ~focusVisibleClassName?,
    ~selected?,
    ~id?,
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
external make: React.component('a) = "ListItem";
