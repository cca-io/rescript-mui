[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "filled"] `Filled
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "standard"] `Standard
];

module Classes = {
  type classesType =
    | Root(string)
    | Focused(string)
    | Disabled(string)
    | Error(string)
    | Required(string)
    | Asterisk(string)
    | FormControl(string)
    | MarginDense(string)
    | Shrink(string)
    | Animated(string)
    | Filled(string)
    | Outlined(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | Error(_) => "error"
    | Required(_) => "required"
    | Asterisk(_) => "asterisk"
    | FormControl(_) => "formControl"
    | MarginDense(_) => "marginDense"
    | Shrink(_) => "shrink"
    | Animated(_) => "animated"
    | Filled(_) => "filled"
    | Outlined(_) => "outlined";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Focused(className)
                         | Disabled(className)
                         | Error(className)
                         | Required(className)
                         | Asterisk(className)
                         | FormControl(className)
                         | MarginDense(className)
                         | Shrink(className)
                         | Animated(className)
                         | Filled(className)
                         | Outlined(className) =>
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
    ~component: 'union_r38j=?,
    ~filled: bool=?,
    ~id: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~disableAnimation: bool=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~focused: bool=?,
    ~margin: string=?,
    ~required: bool=?,
    ~shrink: bool=?,
    ~variant: string=?,
    ~htmlFor: string,
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
      ~filled: option(bool)=?,
      ~id: option(string)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~disableAnimation: option(bool)=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~focused: option(bool)=?,
      ~margin: option(margin)=?,
      ~required: option(bool)=?,
      ~shrink: option(bool)=?,
      ~variant: option(variant)=?,
      ~htmlFor: string,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~filled?,
    ~id?,
    ~children?,
    ~className?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~disableAnimation?,
    ~disabled?,
    ~error?,
    ~focused?,
    ~margin=?margin->Belt.Option.map(v => marginToJs(v)),
    ~required?,
    ~shrink?,
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~htmlFor,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "InputLabel";
