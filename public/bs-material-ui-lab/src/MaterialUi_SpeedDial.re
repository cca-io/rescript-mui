[@bs.deriving jsConverter]
type direction = [
  | [@bs.as "down"] `Down
  | [@bs.as "left"] `Left
  | [@bs.as "right"] `Right
  | [@bs.as "up"] `Up
];

module TransitionDuration_shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    appear: [ | `Int(int) | `Float(float)],
    [@bs.optional]
    enter: [ | `Int(int) | `Float(float)],
    [@bs.optional]
    exit: [ | `Int(int) | `Float(float)],
  };
  let make = t;

  let unwrap = (obj: t) => {
    let unwrappedMap = Js.Dict.empty();

    switch (
      obj
      ->appearGet
      ->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)))
    ) {
    | Some(v) =>
      unwrappedMap->(Js.Dict.set("appear", v->MaterialUi_Helpers.toJsUnsafe))
    | None => ()
    };

    switch (
      obj->enterGet->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)))
    ) {
    | Some(v) =>
      unwrappedMap->(Js.Dict.set("enter", v->MaterialUi_Helpers.toJsUnsafe))
    | None => ()
    };

    switch (
      obj->exitGet->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)))
    ) {
    | Some(v) =>
      unwrappedMap->(Js.Dict.set("exit", v->MaterialUi_Helpers.toJsUnsafe))
    | None => ()
    };

    unwrappedMap;
  };
};

module Classes = {
  type classesType =
    | Root(string)
    | Fab(string)
    | DirectionUp(string)
    | DirectionDown(string)
    | DirectionLeft(string)
    | DirectionRight(string)
    | Actions(string)
    | ActionsClosed(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Fab(_) => "fab"
    | DirectionUp(_) => "directionUp"
    | DirectionDown(_) => "directionDown"
    | DirectionLeft(_) => "directionLeft"
    | DirectionRight(_) => "directionRight"
    | Actions(_) => "actions"
    | ActionsClosed(_) => "actionsClosed";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Fab(className)
                         | DirectionUp(className)
                         | DirectionDown(className)
                         | DirectionLeft(className)
                         | DirectionRight(className)
                         | Actions(className)
                         | ActionsClosed(className) =>
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
    ~ariaLabel: string,
    ~children: 'children=?,
    ~className: string=?,
    ~direction: string=?,
    ~_FabProps: Js.t({..})=?,
    ~hidden: bool=?,
    ~icon: React.element=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClose: 'any_rflb=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onOpen: 'any_rcmn=?,
    ~_open: bool,
    ~openIcon: React.element=?,
    ~_TransitionComponent: 'union_rxq1=?,
    ~transitionDuration: 'union_r5sh=?,
    ~_TransitionProps: Js.t({..})=?,
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
      ~ariaLabel: string,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~direction: option(direction)=?,
      ~_FabProps: option(Js.t({..}))=?,
      ~hidden: option(bool)=?,
      ~icon: option(React.element)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
      ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
      ~onOpen: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~open_: bool,
      ~openIcon: option(React.element)=?,
      ~_TransitionComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(TransitionDuration_shape.t)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~ariaLabel,
    ~children?,
    ~className?,
    ~direction=?direction->Belt.Option.map(v => directionToJs(v)),
    ~_FabProps?,
    ~hidden?,
    ~icon?,
    ~onBlur?,
    ~onClose?,
    ~onFocus?,
    ~onKeyDown?,
    ~onMouseEnter?,
    ~onMouseLeave?,
    ~onOpen?,
    ~_open=open_,
    ~openIcon?,
    ~_TransitionComponent=?
      _TransitionComponent->(
                              Belt.Option.map(v =>
                                MaterialUi_Helpers.unwrapValue(v)
                              )
                            ),
    ~transitionDuration=?
      transitionDuration->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
    ~_TransitionProps?,
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "SpeedDial";
