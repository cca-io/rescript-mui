module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "padding": option(option(string)),
    "dense": option(option(string)),
    "subheader": option(option(string)),
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
    ~classes: option(Classes.t)=?,
    ~component: option(Component.t)=?,
    ~dense: option(bool)=?,
    ~disablePadding: option(bool)=?,
    ~subheader: option(React.element)=?,
    ~id: option(string)=?,
    ~autoFocus: option(bool)=?,
    ~autoFocusItem: option(bool)=?,
    ~children: option('children)=?,
    ~className: option(string)=?,
    ~disabledItemsFocusable: option(bool)=?,
    ~disableListWrap: option(bool)=?,
    ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "menu"] `Menu
                  | [@bs.as "selectedMenu"] `SelectedMenu
                ],
              )
                =?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "MenuList";
