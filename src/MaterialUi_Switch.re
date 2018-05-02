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
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
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
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~checked: 'union_r3f4=?,
    ~checkedIcon: ReasonReact.reactElement=?,
    ~className: string=?,
    ~color: string=?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~icon: ReasonReact.reactElement=?,
    ~id: string=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'genericCallback=?,
    ~onChange: 'any_rofm=?,
    ~_type: string=?,
    ~value: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Switch/Switch"]
external reactClass : ReasonReact.reactClass = "default";

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
      ~inputRef: option('genericCallback)=?,
      ~onChange: option((ReactEventRe.Form.t, bool) => unit)=?,
      ~_type: option(string)=?,
      ~value: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~checked=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            checked,
          ),
        ~checkedIcon?,
        ~className?,
        ~color=?Js.Option.map((. v) => colorToJs(v), color),
        ~defaultChecked?,
        ~disabled?,
        ~disableRipple?,
        ~icon?,
        ~id?,
        ~inputProps?,
        ~inputRef?,
        ~onChange?,
        ~_type?,
        ~value?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
