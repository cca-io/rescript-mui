[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "default"] `Default
];

module Classes = {
  type classesType =
    | Root(string)
    | Icon(string)
    | IconChecked(string)
    | SwitchBase(string)
    | Checked(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | Disabled(string)
    | Bar(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Icon(_) => "icon"
    | IconChecked(_) => "iconChecked"
    | SwitchBase(_) => "switchBase"
    | Checked(_) => "checked"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Disabled(_) => "disabled"
    | Bar(_) => "bar";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Icon(className)
                         | IconChecked(className)
                         | SwitchBase(className)
                         | Checked(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | Disabled(className)
                         | Bar(className) =>
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
    ~checked: 'union_rwrn=?,
    ~checkedIcon: ReasonReact.reactElement=?,
    ~className: string=?,
    ~color: string=?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~icon: ReasonReact.reactElement=?,
    ~id: string=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_r6vh=?,
    ~onChange: 'any_rga2=?,
    ~_type: string=?,
    ~value: 'union_ry9d=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Switch";
let make =
    (
      ~checked: option([ | `Bool(bool) | `String(string)])=?,
      ~checkedIcon: option(ReasonReact.reactElement)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~defaultChecked: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~icon: option(ReasonReact.reactElement)=?,
      ~id: option(string)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~type_: option(string)=?,
      ~value:
         option(
           [ | `String(string) | `Int(int) | `Float(float) | `Bool(bool)],
         )=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~checked=?
          checked->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~checkedIcon?,
        ~className?,
        ~color=?color->(Belt.Option.map(v => colorToJs(v))),
        ~defaultChecked?,
        ~disabled?,
        ~disableRipple?,
        ~icon?,
        ~id?,
        ~inputProps?,
        ~inputRef=?
          inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~onChange?,
        ~_type=?type_,
        ~value=?
          value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
