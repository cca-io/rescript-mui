[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "default"] `Default
];

[@bs.deriving jsConverter]
type edge = [
  | [@bs.as "start"] `Start
  | [@bs.as "end"] `End
  | [@bs.as "false"] `False
];

[@bs.deriving jsConverter]
type size = [ | [@bs.as "small"] `Small | [@bs.as "medium"] `Medium];

module Classes = {
  type classesType =
    | Root(string)
    | Checked(string)
    | Disabled(string)
    | Indeterminate(string)
    | ColorPrimary(string)
    | ColorSecondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Checked(_) => "checked"
    | Disabled(_) => "disabled"
    | Indeterminate(_) => "indeterminate"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Checked(className)
                         | Disabled(className)
                         | Indeterminate(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className) =>
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
    ~checked: bool=?,
    ~checkedIcon: React.element=?,
    ~color: string=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~icon: React.element=?,
    ~id: string=?,
    ~indeterminate: bool=?,
    ~indeterminateIcon: React.element=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_rc47=?,
    ~onChange: 'any_rdn7=?,
    ~_type: string=?,
    ~value: 'any_rrk7=?,
    ~children: 'children=?,
    ~className: string=?,
    ~disableFocusRipple: bool=?,
    ~edge: string=?,
    ~size: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Checkbox";

[@react.component]
let make =
    (
      ~checked: option(bool)=?,
      ~checkedIcon: option(React.element)=?,
      ~color: option(color)=?,
      ~disabled: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~icon: option(React.element)=?,
      ~id: option(string)=?,
      ~indeterminate: option(bool)=?,
      ~indeterminateIcon: option(React.element)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~type_: option(string)=?,
      ~value: option('any_rrk7)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disableFocusRipple: option(bool)=?,
      ~edge: option(edge)=?,
      ~size: option(size)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~checked?,
      ~checkedIcon?,
      ~color=?color->(Belt.Option.map(v => colorToJs(v))),
      ~disabled?,
      ~disableRipple?,
      ~icon?,
      ~id?,
      ~indeterminate?,
      ~indeterminateIcon?,
      ~inputProps?,
      ~inputRef=?
        inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~onChange?,
      ~_type=?type_,
      ~value?,
      ~children?,
      ~className?,
      ~disableFocusRipple?,
      ~edge=?edge->(Belt.Option.map(v => edgeToJs(v))),
      ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
