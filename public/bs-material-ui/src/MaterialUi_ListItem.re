module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    container: string,
    [@bs.optional]
    focusVisible: string,
    [@bs.optional]
    dense: string,
    [@bs.optional]
    alignItemsFlexStart: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    divider: string,
    [@bs.optional]
    gutters: string,
    [@bs.optional]
    button: string,
    [@bs.optional]
    secondaryAction: string,
    [@bs.optional]
    selected: string,
  };
  let make = t;
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
    ~alignItems: option(
                   [@bs.string] [
                     | [@bs.as "flex-start"] `Flex_Start
                     | [@bs.as "center"] `Center
                   ],
                 )
                   =?,
    ~autoFocus: option(bool)=?,
    ~button: option(bool)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~_ContainerComponent: option(ContainerComponent.t)=?,
    ~_ContainerProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~dense: option(bool)=?,
    ~disabled: option(bool)=?,
    ~disableGutters: option(bool)=?,
    ~divider: option(bool)=?,
    ~focusVisibleClassName: option(string)=?,
    ~selected: option(bool)=?,
    ~id: option(string)=?,
    ~value: option(Value.t)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ListItem";
