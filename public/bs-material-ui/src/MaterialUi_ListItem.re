type alignItems = [ | `Flex_Start | `Center];

module Classes = {
  type t = {
    .
    "root": option(string),
    "container": option(string),
    "focusVisible": option(string),
    "dense": option(string),
    "alignItemsFlexStart": option(string),
    "disabled": option(string),
    "divider": option(string),
    "gutters": option(string),
    "button": option(string),
    "secondaryAction": option(string),
    "selected": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~container: string=?,
      ~focusVisible: string=?,
      ~dense: string=?,
      ~alignItemsFlexStart: string=?,
      ~disabled: string=?,
      ~divider: string=?,
      ~gutters: string=?,
      ~button: string=?,
      ~secondaryAction: string=?,
      ~selected: string=?,
      unit
    ) =>
    t;
};

module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

module ContainerComponent: {
  type t;
  let string: string => t;
  let containerComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let containerComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module Value: {
  type t;
  let string: string => t;
  let int: int => t;
  let float: float => t;
  let arrayOf: array(string) => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let arrayOf = (v: array(string)) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~alignItems: [@bs.string] [
                   | [@bs.as "flex-start"] `Flex_Start
                   | [@bs.as "center"] `Center
                 ]
                   =?,
    ~autoFocus: bool=?,
    ~button: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~_ContainerComponent: ContainerComponent.t=?,
    ~_ContainerProps: Js.t({..})=?,
    ~dense: bool=?,
    ~disabled: bool=?,
    ~disableGutters: bool=?,
    ~divider: bool=?,
    ~focusVisibleClassName: string=?,
    ~selected: bool=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~value: Value.t=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "ListItem";
