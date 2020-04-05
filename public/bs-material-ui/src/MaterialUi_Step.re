module Classes = {
  type classesType =
    | Root(string)
    | Horizontal(string)
    | Vertical(string)
    | AlternativeLabel(string)
    | Completed(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | AlternativeLabel(_) => "alternativeLabel"
    | Completed(_) => "completed";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Horizontal(className)
                         | Vertical(className)
                         | AlternativeLabel(className)
                         | Completed(className) =>
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
    ~active: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~completed: bool=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~active: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~completed: option(bool)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~active?,
    ~children?,
    ~className?,
    ~completed?,
    ~disabled?,
    ~expanded?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Step";
