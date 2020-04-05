[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "elevation"] `Elevation
  | [@bs.as "outlined"] `Outlined
];

module Classes = {
  type classesType =
    | Root(string)
    | Rounded(string)
    | Outlined(string)
    | Elevation0(string)
    | Elevation1(string)
    | Elevation2(string)
    | Elevation3(string)
    | Elevation4(string)
    | Elevation5(string)
    | Elevation6(string)
    | Elevation7(string)
    | Elevation8(string)
    | Elevation9(string)
    | Elevation10(string)
    | Elevation11(string)
    | Elevation12(string)
    | Elevation13(string)
    | Elevation14(string)
    | Elevation15(string)
    | Elevation16(string)
    | Elevation17(string)
    | Elevation18(string)
    | Elevation19(string)
    | Elevation20(string)
    | Elevation21(string)
    | Elevation22(string)
    | Elevation23(string)
    | Elevation24(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Rounded(_) => "rounded"
    | Outlined(_) => "outlined"
    | Elevation0(_) => "elevation0"
    | Elevation1(_) => "elevation1"
    | Elevation2(_) => "elevation2"
    | Elevation3(_) => "elevation3"
    | Elevation4(_) => "elevation4"
    | Elevation5(_) => "elevation5"
    | Elevation6(_) => "elevation6"
    | Elevation7(_) => "elevation7"
    | Elevation8(_) => "elevation8"
    | Elevation9(_) => "elevation9"
    | Elevation10(_) => "elevation10"
    | Elevation11(_) => "elevation11"
    | Elevation12(_) => "elevation12"
    | Elevation13(_) => "elevation13"
    | Elevation14(_) => "elevation14"
    | Elevation15(_) => "elevation15"
    | Elevation16(_) => "elevation16"
    | Elevation17(_) => "elevation17"
    | Elevation18(_) => "elevation18"
    | Elevation19(_) => "elevation19"
    | Elevation20(_) => "elevation20"
    | Elevation21(_) => "elevation21"
    | Elevation22(_) => "elevation22"
    | Elevation23(_) => "elevation23"
    | Elevation24(_) => "elevation24";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Rounded(className)
                         | Outlined(className)
                         | Elevation0(className)
                         | Elevation1(className)
                         | Elevation2(className)
                         | Elevation3(className)
                         | Elevation4(className)
                         | Elevation5(className)
                         | Elevation6(className)
                         | Elevation7(className)
                         | Elevation8(className)
                         | Elevation9(className)
                         | Elevation10(className)
                         | Elevation11(className)
                         | Elevation12(className)
                         | Elevation13(className)
                         | Elevation14(className)
                         | Elevation15(className)
                         | Elevation16(className)
                         | Elevation17(className)
                         | Elevation18(className)
                         | Elevation19(className)
                         | Elevation20(className)
                         | Elevation21(className)
                         | Elevation22(className)
                         | Elevation23(className)
                         | Elevation24(className) =>
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
    ~component: 'union_rckg=?,
    ~elevation: 'number_c=?,
    ~square: bool=?,
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
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~square?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Paper";
