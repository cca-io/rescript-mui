module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    expanded: string,
    [@bs.optional]
    selected: string,
    [@bs.optional]
    group: string,
    [@bs.optional]
    content: string,
    [@bs.optional]
    iconContainer: string,
    [@bs.optional]
    label: string,
  };
  let make = t;
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
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
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
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TreeItem";
