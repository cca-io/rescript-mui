[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "standard"] `Standard
];

[@bs.deriving jsConverter]
type shape = [ | [@bs.as "round"] `Round | [@bs.as "rounded"] `Rounded];

[@bs.deriving jsConverter]
type size = [
  | [@bs.as "large"] `Large
  | [@bs.as "medium"] `Medium
  | [@bs.as "small"] `Small
];

[@bs.deriving jsConverter]
type variant = [ | [@bs.as "outlined"] `Outlined | [@bs.as "text"] `Text];

module Classes = {
  type classesType =
    | Root(string)
    | Ul(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Ul(_) => "ul";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Ul(className) =>
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
    ~boundaryCount: 'number_r=?,
    ~className: string=?,
    ~color: string=?,
    ~count: 'number_w=?,
    ~defaultPage: 'number_b=?,
    ~disabled: bool=?,
    ~getItemAriaLabel: 'any_r0ug=?,
    ~hideNextButton: bool=?,
    ~hidePrevButton: bool=?,
    ~onChange: 'any_rnmu=?,
    ~page: 'number_2=?,
    ~renderItem: 'any_r2iz=?,
    ~shape: string=?,
    ~showFirstButton: bool=?,
    ~showLastButton: bool=?,
    ~siblingCount: 'number_s=?,
    ~size: string=?,
    ~variant: string=?,
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
      ~boundaryCount: option([ | `Int(int) | `Float(float)])=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~count: option([ | `Int(int) | `Float(float)])=?,
      ~defaultPage: option([ | `Int(int) | `Float(float)])=?,
      ~disabled: option(bool)=?,
      ~getItemAriaLabel: option((string, int, bool) => string)=?,
      ~hideNextButton: option(bool)=?,
      ~hidePrevButton: option(bool)=?,
      ~onChange: option((ReactEvent.Form.t, int) => unit)=?,
      ~page: option([ | `Int(int) | `Float(float)])=?,
      ~renderItem: option(unit => 'any_rofk)=?,
      ~shape: option(shape)=?,
      ~showFirstButton: option(bool)=?,
      ~showLastButton: option(bool)=?,
      ~siblingCount: option([ | `Int(int) | `Float(float)])=?,
      ~size: option(size)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~boundaryCount=?
      boundaryCount->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
    ~className?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~count=?count->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~defaultPage=?
      defaultPage->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disabled?,
    ~getItemAriaLabel?,
    ~hideNextButton?,
    ~hidePrevButton?,
    ~onChange?,
    ~page=?page->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~renderItem?,
    ~shape=?shape->Belt.Option.map(v => shapeToJs(v)),
    ~showFirstButton?,
    ~showLastButton?,
    ~siblingCount=?
      siblingCount->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~size=?size->Belt.Option.map(v => sizeToJs(v)),
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "Pagination";
