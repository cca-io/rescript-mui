[@bs.deriving jsConverter]
type size = [
  | [@bs.as "large"] `Large
  | [@bs.as "medium"] `Medium
  | [@bs.as "small"] `Small
];

module Classes = {
  type classesType =
    | Root(string)
    | SizeSmall(string)
    | SizeLarge(string)
    | ReadOnly(string)
    | Disabled(string)
    | FocusVisible(string)
    | Visuallyhidden(string)
    | Pristine(string)
    | Label(string)
    | Icon(string)
    | IconEmpty(string)
    | IconFilled(string)
    | IconHover(string)
    | IconFocus(string)
    | IconActive(string)
    | Decimal(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | SizeSmall(_) => "sizeSmall"
    | SizeLarge(_) => "sizeLarge"
    | ReadOnly(_) => "readOnly"
    | Disabled(_) => "disabled"
    | FocusVisible(_) => "focusVisible"
    | Visuallyhidden(_) => "visuallyhidden"
    | Pristine(_) => "pristine"
    | Label(_) => "label"
    | Icon(_) => "icon"
    | IconEmpty(_) => "iconEmpty"
    | IconFilled(_) => "iconFilled"
    | IconHover(_) => "iconHover"
    | IconFocus(_) => "iconFocus"
    | IconActive(_) => "iconActive"
    | Decimal(_) => "decimal";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | SizeSmall(className)
                         | SizeLarge(className)
                         | ReadOnly(className)
                         | Disabled(className)
                         | FocusVisible(className)
                         | Visuallyhidden(className)
                         | Pristine(className)
                         | Label(className)
                         | Icon(className)
                         | IconEmpty(className)
                         | IconFilled(className)
                         | IconHover(className)
                         | IconFocus(className)
                         | IconActive(className)
                         | Decimal(className) =>
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
    ~className: string=?,
    ~defaultValue: 'number_n=?,
    ~disabled: bool=?,
    ~emptyIcon: React.element=?,
    ~emptyLabelText: React.element=?,
    ~getLabelText: 'any_rhmc=?,
    ~icon: React.element=?,
    ~_IconContainerComponent: 'union_r75d=?,
    ~max: 'number_r=?,
    ~name: string=?,
    ~onChange: 'any_rm53=?,
    ~onChangeActive: 'any_revh=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseMove: ReactEvent.Mouse.t => unit=?,
    ~precision: 'number_6=?,
    ~readOnly: bool=?,
    ~size: string=?,
    ~value: 'number_7=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~className: option(string)=?,
      ~defaultValue: option([ | `Int(int) | `Float(float)])=?,
      ~disabled: option(bool)=?,
      ~emptyIcon: option(React.element)=?,
      ~emptyLabelText: option(React.element)=?,
      ~getLabelText: option(int => string)=?,
      ~icon: option(React.element)=?,
      ~_IconContainerComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~max: option([ | `Int(int) | `Float(float)])=?,
      ~name: option(string)=?,
      ~onChange: option((ReactEvent.Form.t, int) => unit)=?,
      ~onChangeActive: option((Js.t({..}), int) => unit)=?,
      ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
      ~onMouseMove: option(ReactEvent.Mouse.t => unit)=?,
      ~precision: option([ | `Int(int) | `Float(float)])=?,
      ~readOnly: option(bool)=?,
      ~size: option(size)=?,
      ~value: option([ | `Int(int) | `Float(float)])=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~defaultValue=?
      defaultValue->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disabled?,
    ~emptyIcon?,
    ~emptyLabelText?,
    ~getLabelText?,
    ~icon?,
    ~_IconContainerComponent=?
      _IconContainerComponent->(
                                 Belt.Option.map(v =>
                                   MaterialUi_Helpers.unwrapValue(v)
                                 )
                               ),
    ~max=?max->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~name?,
    ~onChange?,
    ~onChangeActive?,
    ~onMouseLeave?,
    ~onMouseMove?,
    ~precision=?
      precision->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~readOnly?,
    ~size=?size->Belt.Option.map(v => sizeToJs(v)),
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"] external make: React.component('a) = "Rating";
