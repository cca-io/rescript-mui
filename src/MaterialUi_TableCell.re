[@bs.deriving jsConverter]
type padding = [
  | [@bs.as "default"] `Default
  | [@bs.as "checkbox"] `Checkbox
  | [@bs.as "dense"] `Dense
  | [@bs.as "none"] `None
];

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
    | Numeric(string)
    | PaddingDense(string)
    | PaddingCheckbox(string)
    | PaddingNone(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Head(_) => "head"
    | Body(_) => "body"
    | Footer(_) => "footer"
    | Numeric(_) => "numeric"
    | PaddingDense(_) => "paddingDense"
    | PaddingCheckbox(_) => "paddingCheckbox"
    | PaddingNone(_) => "paddingNone";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Head(className)
           | Body(className)
           | Footer(className)
           | Numeric(className)
           | PaddingDense(className)
           | PaddingCheckbox(className)
           | PaddingNone(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~component: 'union_rdrl=?,
    ~numeric: bool=?,
    ~padding: string=?,
    ~scope: string=?,
    ~sortDirection: string=?,
    ~variant: string=?,
    ~colSpan: int=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/TableCell/TableCell"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~numeric: option(bool)=?,
      ~padding: option(padding)=?,
      ~scope: option(string)=?,
      ~sortDirection: option(sortDirection)=?,
      ~variant: option(variant)=?,
      ~colSpan: option(int)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~numeric?,
        ~padding=?padding |. Belt.Option.map(v => paddingToJs(v)),
        ~scope?,
        ~sortDirection=?
          sortDirection |. Belt.Option.map(v => sortDirectionToJs(v)),
        ~variant=?variant |. Belt.Option.map(v => variantToJs(v)),
        ~colSpan?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
