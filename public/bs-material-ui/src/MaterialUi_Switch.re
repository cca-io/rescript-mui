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
    | EdgeStart(string)
    | EdgeEnd(string)
    | SwitchBase(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | Checked(string)
    | Disabled(string)
    | Input(string)
    | Thumb(string)
    | Track(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | EdgeStart(_) => "edgeStart"
    | EdgeEnd(_) => "edgeEnd"
    | SwitchBase(_) => "switchBase"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Checked(_) => "checked"
    | Disabled(_) => "disabled"
    | Input(_) => "input"
    | Thumb(_) => "thumb"
    | Track(_) => "track";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | EdgeStart(className)
                         | EdgeEnd(className)
                         | SwitchBase(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | Checked(className)
                         | Disabled(className)
                         | Input(className)
                         | Thumb(className)
                         | Track(className) =>
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
    ~className: string=?,
    ~color: string=?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~edge: string=?,
    ~icon: React.element=?,
    ~id: string=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_rmvx=?,
    ~onChange: 'any_rcxf=?,
    ~_type: string=?,
    ~value: 'any_rj85=?,
    ~children: 'children=?,
    ~disableFocusRipple: bool=?,
    ~size: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Switch";

[@react.component]
let make =
    (
      ~checked: option(bool)=?,
      ~checkedIcon: option(React.element)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~defaultChecked: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~edge: option(edge)=?,
      ~icon: option(React.element)=?,
      ~id: option(string)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~type_: option(string)=?,
      ~value: option('any_rj85)=?,
      ~children: option('children)=?,
      ~disableFocusRipple: option(bool)=?,
      ~size: option(size)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~checked?,
      ~checkedIcon?,
      ~className?,
      ~color=?color->(Belt.Option.map(v => colorToJs(v))),
      ~defaultChecked?,
      ~disabled?,
      ~disableRipple?,
      ~edge=?edge->(Belt.Option.map(v => edgeToJs(v))),
      ~icon?,
      ~id?,
      ~inputProps?,
      ~inputRef=?
        inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~onChange?,
      ~_type=?type_,
      ~value?,
      ~children?,
      ~disableFocusRipple?,
      ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
