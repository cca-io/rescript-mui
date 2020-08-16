module Classes = {
  type t = {
    .
    "root": option(string),
    "expanded": option(string),
    "selected": option(string),
    "group": option(string),
    "content": option(string),
    "iconContainer": option(string),
    "label": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~expanded: string=?,
      ~selected: string=?,
      ~group: string=?,
      ~content: string=?,
      ~iconContainer: string=?,
      ~label: string=?,
      unit
    ) =>
    t;
};

module TransitionComponent: {
  type t;
  let string: string => t;
  let transitionComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let transitionComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~collapseIcon: React.element=?,
    ~endIcon: React.element=?,
    ~expandIcon: React.element=?,
    ~icon: React.element=?,
    ~label: React.element=?,
    ~nodeId: string,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onIconClick: MaterialUi_Types.any=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onLabelClick: MaterialUi_Types.any=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~_TransitionComponent: TransitionComponent.t=?,
    ~_TransitionProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "TreeItem";
