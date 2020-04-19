[@bs.deriving jsConverter]
type size = [
  | [@bs.as "large"] `Large
  | [@bs.as "medium"] `Medium
  | [@bs.as "small"] `Small
];

module Classes = {
  type classesType =
    | Root(string)
    | Grouped(string)
    | GroupedSizeSmall(string)
    | GroupedSizeLarge(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Grouped(_) => "grouped"
    | GroupedSizeSmall(_) => "groupedSizeSmall"
    | GroupedSizeLarge(_) => "groupedSizeLarge";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Grouped(className)
                         | GroupedSizeSmall(className)
                         | GroupedSizeLarge(className) =>
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
    ~exclusive: bool=?,
    ~onChange: 'any_r140=?,
    ~size: string=?,
    ~value: 'any_r4wk=?,
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
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~exclusive: option(bool)=?,
      ~onChange: option((ReactEvent.Form.t, 'any_rqnt) => unit)=?,
      ~size: option(size)=?,
      ~value: option('any_r4wk)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~exclusive?,
    ~onChange?,
    ~size=?size->Belt.Option.map(v => sizeToJs(v)),
    ~value?,
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "ToggleButtonGroup";
