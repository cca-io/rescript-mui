module Classes = {
  type classesType =
    | Root(string)
    | Expanded(string)
    | Selected(string)
    | Group(string)
    | Content(string)
    | IconContainer(string)
    | Label(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Expanded(_) => "expanded"
    | Selected(_) => "selected"
    | Group(_) => "group"
    | Content(_) => "content"
    | IconContainer(_) => "iconContainer"
    | Label(_) => "label";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Expanded(className)
                         | Selected(className)
                         | Group(className)
                         | Content(className)
                         | IconContainer(className)
                         | Label(className) =>
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
    ~collapseIcon: React.element=?,
    ~endIcon: React.element=?,
    ~expandIcon: React.element=?,
    ~icon: React.element=?,
    ~label: React.element=?,
    ~nodeId: string,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~_TransitionComponent: 'union_r9aw=?,
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
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~collapseIcon: option(React.element)=?,
      ~endIcon: option(React.element)=?,
      ~expandIcon: option(React.element)=?,
      ~icon: option(React.element)=?,
      ~label: option(React.element)=?,
      ~nodeId: string,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
      ~_TransitionComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
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
    ~children?,
    ~className?,
    ~collapseIcon?,
    ~endIcon?,
    ~expandIcon?,
    ~icon?,
    ~label?,
    ~nodeId,
    ~onClick?,
    ~onFocus?,
    ~onKeyDown?,
    ~onMouseDown?,
    ~_TransitionComponent=?
      _TransitionComponent->(
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
external make: React.component('a) = "TreeItem";
