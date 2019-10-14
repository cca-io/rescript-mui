[@bs.deriving jsConverter]
type align = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "left"] `Left
  | [@bs.as "center"] `Center
  | [@bs.as "right"] `Right
  | [@bs.as "justify"] `Justify
];

[@bs.deriving jsConverter]
type padding = [
  | [@bs.as "default"] `Default
  | [@bs.as "checkbox"] `Checkbox
  | [@bs.as "none"] `None
];

[@bs.deriving jsConverter]
type size = [ | [@bs.as "small"] `Small | [@bs.as "medium"] `Medium];

[@bs.deriving jsConverter]
type sortDirection = [
  | [@bs.as "asc"] `Asc
  | [@bs.as "desc"] `Desc
  | [@bs.as "false"] `False
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "head"] `Head
  | [@bs.as "body"] `Body
  | [@bs.as "footer"] `Footer
];

module Classes = {
  type classesType =
    | Root(string)
    | Head(string)
    | Body(string)
    | Footer(string)
    | SizeSmall(string)
    | PaddingCheckbox(string)
    | PaddingNone(string)
    | AlignLeft(string)
    | AlignCenter(string)
    | AlignRight(string)
    | AlignJustify(string)
    | StickyHeader(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Head(_) => "head"
    | Body(_) => "body"
    | Footer(_) => "footer"
    | SizeSmall(_) => "sizeSmall"
    | PaddingCheckbox(_) => "paddingCheckbox"
    | PaddingNone(_) => "paddingNone"
    | AlignLeft(_) => "alignLeft"
    | AlignCenter(_) => "alignCenter"
    | AlignRight(_) => "alignRight"
    | AlignJustify(_) => "alignJustify"
    | StickyHeader(_) => "stickyHeader";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Head(className)
                         | Body(className)
                         | Footer(className)
                         | SizeSmall(className)
                         | PaddingCheckbox(className)
                         | PaddingNone(className)
                         | AlignLeft(className)
                         | AlignCenter(className)
                         | AlignRight(className)
                         | AlignJustify(className)
                         | StickyHeader(className) =>
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
    ~align: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~component: 'union_r7z2=?,
    ~padding: string=?,
    ~scope: string=?,
    ~size: string=?,
    ~sortDirection: string=?,
    ~variant: string=?,
    ~colSpan: int=?,
    ~key: string=?,
    ~_ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~align: option(align)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~padding: option(padding)=?,
      ~scope: option(string)=?,
      ~size: option(size)=?,
      ~sortDirection: option(sortDirection)=?,
      ~variant: option(variant)=?,
      ~colSpan: option(int)=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~align=?align->(Belt.Option.map(v => alignToJs(v))),
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~padding=?padding->(Belt.Option.map(v => paddingToJs(v))),
    ~scope?,
    ~size=?size->(Belt.Option.map(v => sizeToJs(v))),
    ~sortDirection=?
      sortDirection->(Belt.Option.map(v => sortDirectionToJs(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~colSpan?,
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "TableCell";
