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
    | Default(string)
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
    | Default(_) => "default"
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
                         | Default(className)
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
external makeProps:
  (
    ~alignItems: string=?,
    ~button: bool=?,
    ~className: string=?,
    ~_ContainerProps: Js.t({..})=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~selected: bool=?,
    ~value: 'union_r51k=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "ListItem";
let make =
    (
      ~alignItems: option(alignItems)=?,
      ~button: option(bool)=?,
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
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~alignItems=?alignItems->(Belt.Option.map(v => alignItemsToJs(v))),
        ~button?,
        ~className?,
        ~_ContainerProps?,
        ~dense?,
        ~disabled?,
        ~disableGutters?,
        ~divider?,
        ~focusVisibleClassName?,
        ~selected?,
        ~value=?
          value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~onFocus?,
        ~onClick?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
