[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "default"] `Default
  | [@bs.as "outlined"] `Outlined
];

module Classes = {
  type classesType =
    | Root(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
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
    | AvatarColorPrimary(string)
    | AvatarColorSecondary(string)
    | AvatarChildren(string)
    | Icon(string)
    | IconColorPrimary(string)
    | IconColorSecondary(string)
    | Label(string)
    | DeleteIcon(string)
    | DeleteIconColorPrimary(string)
    | DeleteIconColorSecondary(string)
    | DeleteIconOutlinedColorPrimary(string)
    | DeleteIconOutlinedColorSecondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
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
    | AvatarColorPrimary(_) => "avatarColorPrimary"
    | AvatarColorSecondary(_) => "avatarColorSecondary"
    | AvatarChildren(_) => "avatarChildren"
    | Icon(_) => "icon"
    | IconColorPrimary(_) => "iconColorPrimary"
    | IconColorSecondary(_) => "iconColorSecondary"
    | Label(_) => "label"
    | DeleteIcon(_) => "deleteIcon"
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
                         | ColorPrimary(className)
                         | ColorSecondary(className)
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
                         | AvatarColorPrimary(className)
                         | AvatarColorSecondary(className)
                         | AvatarChildren(className)
                         | Icon(className)
                         | IconColorPrimary(className)
                         | IconColorSecondary(className)
                         | Label(className)
                         | DeleteIcon(className)
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
    ~component: 'union_ril2=?,
    ~deleteIcon: React.element=?,
    ~icon: React.element=?,
    ~label: React.element=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onDelete: ReactEvent.Synthetic.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~tabIndex: 'union_rnhu=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Chip";

[@react.component]
let make =
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
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~deleteIcon: option(React.element)=?,
      ~icon: option(React.element)=?,
      ~label: option(React.element)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onDelete: option(ReactEvent.Synthetic.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
      ~variant: option(variant)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~avatar?,
      ~children?,
      ~className?,
      ~clickable?,
      ~color=?color->(Belt.Option.map(v => colorToJs(v))),
      ~component=?
        component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~deleteIcon?,
      ~icon?,
      ~label?,
      ~onClick?,
      ~onDelete?,
      ~onKeyDown?,
      ~onKeyUp?,
      ~tabIndex=?
        tabIndex->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
