module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    sizeSmall: string,
    [@bs.optional]
    colorPrimary: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    clickable: string,
    [@bs.optional]
    clickableColorPrimary: string,
    [@bs.optional]
    clickableColorSecondary: string,
    [@bs.optional]
    deletable: string,
    [@bs.optional]
    deletableColorPrimary: string,
    [@bs.optional]
    deletableColorSecondary: string,
    [@bs.optional]
    outlined: string,
    [@bs.optional]
    outlinedPrimary: string,
    [@bs.optional]
    outlinedSecondary: string,
    [@bs.optional]
    avatar: string,
    [@bs.optional]
    avatarSmall: string,
    [@bs.optional]
    avatarColorPrimary: string,
    [@bs.optional]
    avatarColorSecondary: string,
    [@bs.optional]
    icon: string,
    [@bs.optional]
    iconSmall: string,
    [@bs.optional]
    iconColorPrimary: string,
    [@bs.optional]
    iconColorSecondary: string,
    [@bs.optional]
    label: string,
    [@bs.optional]
    labelSmall: string,
    [@bs.optional]
    deleteIcon: string,
    [@bs.optional]
    deleteIconSmall: string,
    [@bs.optional]
    deleteIconColorPrimary: string,
    [@bs.optional]
    deleteIconColorSecondary: string,
    [@bs.optional]
    deleteIconOutlinedColorPrimary: string,
    [@bs.optional]
    deleteIconOutlinedColorSecondary: string,
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
