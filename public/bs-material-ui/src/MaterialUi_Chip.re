module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "sizeSmall": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(string)),
    "clickable": option(option(string)),
    "clickableColorPrimary": option(option(string)),
    "clickableColorSecondary": option(option(string)),
    "deletable": option(option(string)),
    "deletableColorPrimary": option(option(string)),
    "deletableColorSecondary": option(option(string)),
    "outlined": option(option(string)),
    "outlinedPrimary": option(option(string)),
    "outlinedSecondary": option(option(string)),
    "avatar": option(option(string)),
    "avatarSmall": option(option(string)),
    "avatarColorPrimary": option(option(string)),
    "avatarColorSecondary": option(option(string)),
    "icon": option(option(string)),
    "iconSmall": option(option(string)),
    "iconColorPrimary": option(option(string)),
    "iconColorSecondary": option(option(string)),
    "label": option(option(string)),
    "labelSmall": option(option(string)),
    "deleteIcon": option(option(string)),
    "deleteIconSmall": option(option(string)),
    "deleteIconColorPrimary": option(option(string)),
    "deleteIconColorSecondary": option(option(string)),
    "deleteIconOutlinedColorPrimary": option(option(string)),
    "deleteIconOutlinedColorSecondary": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~sizeSmall: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~disabled: string=?,
      ~clickable: string=?,
      ~clickableColorPrimary: string=?,
      ~clickableColorSecondary: string=?,
      ~deletable: string=?,
      ~deletableColorPrimary: string=?,
      ~deletableColorSecondary: string=?,
      ~outlined: string=?,
      ~outlinedPrimary: string=?,
      ~outlinedSecondary: string=?,
      ~avatar: string=?,
      ~avatarSmall: string=?,
      ~avatarColorPrimary: string=?,
      ~avatarColorSecondary: string=?,
      ~icon: string=?,
      ~iconSmall: string=?,
      ~iconColorPrimary: string=?,
      ~iconColorSecondary: string=?,
      ~label: string=?,
      ~labelSmall: string=?,
      ~deleteIcon: string=?,
      ~deleteIconSmall: string=?,
      ~deleteIconColorPrimary: string=?,
      ~deleteIconColorSecondary: string=?,
      ~deleteIconOutlinedColorPrimary: string=?,
      ~deleteIconOutlinedColorSecondary: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Primary | `Secondary];

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

type size = [ | `Small | `Medium];

type variant = [ | `Default | `Outlined];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~avatar: option(React.element)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~clickable: option(bool)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~deleteIcon: option(React.element)=?,
    ~disabled: option(bool)=?,
    ~icon: option(React.element)=?,
    ~label: option(React.element)=?,
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onDelete: option(ReactEvent.Synthetic.t => unit)=?,
    ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "small"] `Small
               | [@bs.as "medium"] `Medium
             ],
           )
             =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "default"] `Default
                  | [@bs.as "outlined"] `Outlined
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Chip";
