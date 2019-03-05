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
external makeProps:
  (
    ~className: string=?,
    ~disableGutters: bool=?,
    ~role: string=?,
    ~selected: bool=?,
    ~value: 'union_rm23=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~alignItems: string=?,
    ~button: bool=?,
    ~_ContainerProps: Js.t({..})=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "MenuItem";
let make =
    (
      ~className: option(string)=?,
      ~disableGutters: option(bool)=?,
      ~role: option(string)=?,
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
      ~alignItems: option(alignItems)=?,
      ~button: option(bool)=?,
      ~_ContainerProps: option(Js.t({..}))=?,
      ~dense: option(bool)=?,
      ~disabled: option(bool)=?,
      ~divider: option(bool)=?,
      ~focusVisibleClassName: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~disableGutters?,
        ~role?,
        ~selected?,
        ~value=?
          value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~onFocus?,
        ~onClick?,
        ~alignItems=?alignItems->(Belt.Option.map(v => alignItemsToJs(v))),
        ~button?,
        ~_ContainerProps?,
        ~dense?,
        ~disabled?,
        ~divider?,
        ~focusVisibleClassName?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
