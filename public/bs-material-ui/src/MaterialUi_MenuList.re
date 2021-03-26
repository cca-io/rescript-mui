module Classes = {
  type t = {
    .
    "root": option(string),
    "padding": option(string),
    "dense": option(string),
    "subheader": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~padding: string=?,
      ~dense: string=?,
      ~subheader: string=?,
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

type variant = [ | `Menu | `SelectedMenu];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~classes: Classes.t=?,
    ~component: Component.t=?,
    ~dense: bool=?,
    ~disablePadding: bool=?,
    ~subheader: React.element=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~autoFocus: bool=?,
    ~autoFocusItem: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~disabledItemsFocusable: bool=?,
    ~disableListWrap: bool=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~variant: [@bs.string] [
                | [@bs.as "menu"] `Menu
                | [@bs.as "selectedMenu"] `SelectedMenu
              ]
                =?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "MenuList";
