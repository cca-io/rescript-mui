[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "standard"] `Standard
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "filled"] `Filled
];

[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

module Classes = {
  type classesType =
    | Root(string)
    | Select(string)
    | Filled(string)
    | Outlined(string)
    | SelectMenu(string)
    | Disabled(string)
    | Icon(string)
    | IconFilled(string)
    | IconOutlined(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Select(_) => "select"
    | Filled(_) => "filled"
    | Outlined(_) => "outlined"
    | SelectMenu(_) => "selectMenu"
    | Disabled(_) => "disabled"
    | Icon(_) => "icon"
    | IconFilled(_) => "iconFilled"
    | IconOutlined(_) => "iconOutlined";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Select(className)
                         | Filled(className)
                         | Outlined(className)
                         | SelectMenu(className)
                         | Disabled(className)
                         | Icon(className)
                         | IconFilled(className)
                         | IconOutlined(className) =>
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
    ~_IconComponent: 'union_rigx=?,
    ~input: React.element=?,
    ~inputProps: Js.t({..})=?,
    ~onChange: 'any_rfpk=?,
    ~value: 'any_r5vy=?,
    ~variant: string=?,
    ~key: string=?,
    ~_ref: ReactDOMRe.domRef=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~defaultValue: 'any_r86p=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: 'any_rh1p=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: 'union_r6ap=?,
    ~rowsMax: 'union_ruhr=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~aria_describedby: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~renderSuffix: 'genericCallback=?,
    ~select: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~_IconComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~input: option(React.element)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~value: option('any_r5vy)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~defaultValue: option('any_r86p)=?,
      ~disabled: option(bool)=?,
      ~disableUnderline: option(bool)=?,
      ~endAdornment: option(React.element)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputComponent: option('any_rh1p)=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~placeholder: option(string)=?,
      ~readOnly: option(bool)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~startAdornment: option(React.element)=?,
      ~type_: option(string)=?,
      ~aria_describedby: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~renderSuffix: option('genericCallback)=?,
      ~select: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~_IconComponent=?
      _IconComponent->(
                        Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                      ),
    ~input?,
    ~inputProps?,
    ~onChange?,
    ~value?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~_ref=?ref_,
    ~autoComplete?,
    ~autoFocus?,
    ~className?,
    ~defaultValue?,
    ~disabled?,
    ~disableUnderline?,
    ~endAdornment?,
    ~error?,
    ~fullWidth?,
    ~id?,
    ~inputComponent?,
    ~margin=?margin->(Belt.Option.map(v => marginToJs(v))),
    ~multiline?,
    ~name?,
    ~placeholder?,
    ~readOnly?,
    ~required?,
    ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~rowsMax=?
      rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~startAdornment?,
    ~_type=?type_,
    ~aria_describedby?,
    ~onBlur?,
    ~onClick?,
    ~onFocus?,
    ~onKeyDown?,
    ~onKeyUp?,
    ~renderSuffix?,
    ~select?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "NativeSelect";
