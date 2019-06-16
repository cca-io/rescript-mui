[@bs.deriving jsConverter]
type alignItems = [
  | [@bs.as "flex-start"] `Flex_Start
  | [@bs.as "center"] `Center
];

module Classes = {
  type classesType =
    | Root(string)
    | Gutters(string)
    | Selected(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Gutters(_) => "gutters"
    | Selected(_) => "selected";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Gutters(className)
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
    ~children: 'children=?,
    ~className: string=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~role: string=?,
    ~selected: bool=?,
    ~tabIndex: 'number_p=?,
    ~value: 'union_r2ty=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~alignItems: string=?,
    ~autoFocus: bool=?,
    ~button: bool=?,
    ~_ContainerProps: Js.t({..})=?,
    ~dense: bool=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "MenuItem";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disabled: option(bool)=?,
      ~disableGutters: option(bool)=?,
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
      ~alignItems: option(alignItems)=?,
      ~autoFocus: option(bool)=?,
      ~button: option(bool)=?,
      ~_ContainerProps: option(Js.t({..}))=?,
      ~dense: option(bool)=?,
      ~divider: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~disabled?,
      ~disableGutters?,
      ~role?,
      ~selected?,
      ~tabIndex=?
        tabIndex->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~value=?
        value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~onFocus?,
      ~onClick?,
      ~alignItems=?alignItems->(Belt.Option.map(v => alignItemsToJs(v))),
      ~autoFocus?,
      ~button?,
      ~_ContainerProps?,
      ~dense?,
      ~divider?,
      ~focusVisibleClassName?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
