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
    |> StdLabels.List.fold_left(
         ~f=
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
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~component: 'union_rsq8=?,
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

[@bs.module "material-ui/Table/TableCell"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
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
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~numeric?,
        ~padding=?Js.Option.map((. v) => paddingToJs(v), padding),
        ~scope?,
        ~sortDirection=?
          Js.Option.map((. v) => sortDirectionToJs(v), sortDirection),
        ~variant=?Js.Option.map((. v) => variantToJs(v), variant),
        ~colSpan?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
