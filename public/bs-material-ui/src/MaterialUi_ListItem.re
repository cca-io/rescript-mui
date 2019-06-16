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
    ~_ContainerProps: Js.t({..})=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~selected: bool=?,
    ~value: 'union_r9zk=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
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
      ~alignItems: option(alignItems)=?,
      ~autoFocus: option(bool)=?,
      ~button: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~_ContainerProps: option(Js.t({..}))=?,
      ~dense: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableGutters: option(bool)=?,
      ~divider: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~selected: option(bool)=?,
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
      ~ref_: option(React.Ref.t(Dom.element))=?,
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
    ~_ContainerProps?,
    ~dense?,
    ~disabled?,
    ~disableGutters?,
    ~divider?,
    ~focusVisibleClassName?,
    ~selected?,
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~onFocus?,
    ~onClick?,
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ListItem";
