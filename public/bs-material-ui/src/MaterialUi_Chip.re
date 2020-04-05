[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type size = [ | [@bs.as "small"] `Small | [@bs.as "medium"] `Medium];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "default"] `Default
  | [@bs.as "outlined"] `Outlined
];

module Classes = {
  type classesType =
    | Root(string)
    | SizeSmall(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | Disabled(string)
    | Clickable(string)
    | ClickableColorPrimary(string)
    | ClickableColorSecondary(string)
    | Deletable(string)
    | DeletableColorPrimary(string)
    | DeletableColorSecondary(string)
    | Outlined(string)
    | OutlinedPrimary(string)
    | OutlinedSecondary(string)
    | Avatar(string)
    | AvatarSmall(string)
    | AvatarColorPrimary(string)
    | AvatarColorSecondary(string)
    | Icon(string)
    | IconSmall(string)
    | IconColorPrimary(string)
    | IconColorSecondary(string)
    | Label(string)
    | LabelSmall(string)
    | DeleteIcon(string)
    | DeleteIconSmall(string)
    | DeleteIconColorPrimary(string)
    | DeleteIconColorSecondary(string)
    | DeleteIconOutlinedColorPrimary(string)
    | DeleteIconOutlinedColorSecondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | SizeSmall(_) => "sizeSmall"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Disabled(_) => "disabled"
    | Clickable(_) => "clickable"
    | ClickableColorPrimary(_) => "clickableColorPrimary"
    | ClickableColorSecondary(_) => "clickableColorSecondary"
    | Deletable(_) => "deletable"
    | DeletableColorPrimary(_) => "deletableColorPrimary"
    | DeletableColorSecondary(_) => "deletableColorSecondary"
    | Outlined(_) => "outlined"
    | OutlinedPrimary(_) => "outlinedPrimary"
    | OutlinedSecondary(_) => "outlinedSecondary"
    | Avatar(_) => "avatar"
    | AvatarSmall(_) => "avatarSmall"
    | AvatarColorPrimary(_) => "avatarColorPrimary"
    | AvatarColorSecondary(_) => "avatarColorSecondary"
    | Icon(_) => "icon"
    | IconSmall(_) => "iconSmall"
    | IconColorPrimary(_) => "iconColorPrimary"
    | IconColorSecondary(_) => "iconColorSecondary"
    | Label(_) => "label"
    | LabelSmall(_) => "labelSmall"
    | DeleteIcon(_) => "deleteIcon"
    | DeleteIconSmall(_) => "deleteIconSmall"
    | DeleteIconColorPrimary(_) => "deleteIconColorPrimary"
    | DeleteIconColorSecondary(_) => "deleteIconColorSecondary"
    | DeleteIconOutlinedColorPrimary(_) => "deleteIconOutlinedColorPrimary"
    | DeleteIconOutlinedColorSecondary(_) => "deleteIconOutlinedColorSecondary";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | SizeSmall(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | Disabled(className)
                         | Clickable(className)
                         | ClickableColorPrimary(className)
                         | ClickableColorSecondary(className)
                         | Deletable(className)
                         | DeletableColorPrimary(className)
                         | DeletableColorSecondary(className)
                         | Outlined(className)
                         | OutlinedPrimary(className)
                         | OutlinedSecondary(className)
                         | Avatar(className)
                         | AvatarSmall(className)
                         | AvatarColorPrimary(className)
                         | AvatarColorSecondary(className)
                         | Icon(className)
                         | IconSmall(className)
                         | IconColorPrimary(className)
                         | IconColorSecondary(className)
                         | Label(className)
                         | LabelSmall(className)
                         | DeleteIcon(className)
                         | DeleteIconSmall(className)
                         | DeleteIconColorPrimary(className)
                         | DeleteIconColorSecondary(className)
                         | DeleteIconOutlinedColorPrimary(className)
                         | DeleteIconOutlinedColorSecondary(className) =>
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
    ~avatar: React.element=?,
    ~children: 'children=?,
    ~className: string=?,
    ~clickable: bool=?,
    ~color: string=?,
    ~component: 'union_ri4b=?,
    ~deleteIcon: React.element=?,
    ~disabled: bool=?,
    ~icon: React.element=?,
    ~label: React.element=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onDelete: ReactEvent.Synthetic.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~size: string=?,
    ~variant: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~avatar: option(React.element)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~clickable: option(bool)=?,
      ~color: option(color)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~deleteIcon: option(React.element)=?,
      ~disabled: option(bool)=?,
      ~icon: option(React.element)=?,
      ~label: option(React.element)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onDelete: option(ReactEvent.Synthetic.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~size: option(size)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~avatar?,
    ~children?,
    ~className?,
    ~clickable?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~deleteIcon?,
    ~disabled?,
    ~icon?,
    ~label?,
    ~onClick?,
    ~onDelete?,
    ~onKeyDown?,
    ~onKeyUp?,
    ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Chip";
