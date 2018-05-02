[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "error"] `Error
];

module Classes = {
  type classesType =
    | Root(string)
    | Badge(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | ColorError(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Badge(_) => "badge"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | ColorError(_) => "colorError";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Badge(className)
             | ColorPrimary(className)
             | ColorSecondary(className)
             | ColorError(className) =>
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
    ~badgeContent: ReasonReact.reactElement,
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_r9e8=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Badge/Badge"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~badgeContent: ReasonReact.reactElement,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~badgeContent,
        ~className?,
        ~color=?Js.Option.map((. v) => colorToJs(v), color),
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
