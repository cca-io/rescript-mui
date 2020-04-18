[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type margin = [
  | [@bs.as "dense"] `Dense
  | [@bs.as "none"] `None
  | [@bs.as "normal"] `Normal
];

[@bs.deriving jsConverter]
type size = [ | [@bs.as "medium"] `Medium | [@bs.as "small"] `Small];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "filled"] `Filled
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "standard"] `Standard
];

module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className) =>
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
    ~component: 'union_rnfb=?,
    ~focused: bool=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~defaultValue: 'union_rluo=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~_FormHelperTextProps: Js.t({..})=?,
    ~fullWidth: bool=?,
    ~helperText: React.element=?,
    ~hiddenLabel: bool=?,
    ~id: string=?,
    ~_InputLabelProps: Js.t({..})=?,
    ~inputProps: Js.t({..})=?,
    ~_InputProps: Js.t({..})=?,
    ~label: React.element=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_rpsd=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~placeholder: string=?,
    ~required: bool=?,
    ~rows: 'union_rxsm=?,
    ~rowsMax: 'union_rymj=?,
    ~select: bool=?,
    ~_SelectProps: Js.t({..})=?,
    ~size: string=?,
    ~_type: string=?,
    ~value: 'union_r4ww=?,
    ~variant: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~focused: option(bool)=?,
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~defaultValue:
         option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~_FormHelperTextProps: option(Js.t({..}))=?,
      ~fullWidth: option(bool)=?,
      ~helperText: option(React.element)=?,
      ~hiddenLabel: option(bool)=?,
      ~id: option(string)=?,
      ~_InputLabelProps: option(Js.t({..}))=?,
      ~inputProps: option(Js.t({..}))=?,
      ~_InputProps: option(Js.t({..}))=?,
      ~label: option(React.element)=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~placeholder: option(string)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~rowsMax: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~select: option(bool)=?,
      ~_SelectProps: option(Js.t({..}))=?,
      ~size: option(size)=?,
      ~type_: option(string)=?,
      ~value: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~focused?,
    ~autoComplete?,
    ~autoFocus?,
    ~children?,
    ~className?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~defaultValue=?
      defaultValue->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disabled?,
    ~error?,
    ~_FormHelperTextProps?,
    ~fullWidth?,
    ~helperText?,
    ~hiddenLabel?,
    ~id?,
    ~_InputLabelProps?,
    ~inputProps?,
    ~_InputProps?,
    ~label?,
    ~margin=?margin->Belt.Option.map(v => marginToJs(v)),
    ~multiline?,
    ~name?,
    ~onBlur?,
    ~onChange?,
    ~onFocus?,
    ~placeholder?,
    ~required?,
    ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~rowsMax=?
      rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~select?,
    ~_SelectProps?,
    ~size=?size->Belt.Option.map(v => sizeToJs(v)),
    ~_type=?type_,
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "TextField";