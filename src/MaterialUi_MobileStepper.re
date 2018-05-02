[@bs.deriving jsConverter]
type position = [
  | [@bs.as "bottom"] `Bottom
  | [@bs.as "top"] `Top
  | [@bs.as "static"] `Static
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "text"] `Text
  | [@bs.as "dots"] `Dots
  | [@bs.as "progress"] `Progress
];

module Classes = {
  type classesType =
    | Root(string)
    | PositionBottom(string)
    | PositionTop(string)
    | PositionStatic(string)
    | Dots(string)
    | Dot(string)
    | DotActive(string)
    | Progress(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | PositionBottom(_) => "positionBottom"
    | PositionTop(_) => "positionTop"
    | PositionStatic(_) => "positionStatic"
    | Dots(_) => "dots"
    | Dot(_) => "dot"
    | DotActive(_) => "dotActive"
    | Progress(_) => "progress";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | PositionBottom(className)
             | PositionTop(className)
             | PositionStatic(className)
             | Dots(className)
             | Dot(className)
             | DotActive(className)
             | Progress(className) =>
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
    ~activeStep: 'number_l=?,
    ~backButton: ReasonReact.reactElement=?,
    ~className: string=?,
    ~nextButton: ReasonReact.reactElement=?,
    ~position: string=?,
    ~steps: 'number_m,
    ~variant: string=?,
    ~component: 'union_rtie=?,
    ~elevation: 'number_2=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/MobileStepper/MobileStepper"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~activeStep: option([ | `Int(int) | `Float(float)])=?,
      ~backButton: option(ReasonReact.reactElement)=?,
      ~className: option(string)=?,
      ~nextButton: option(ReasonReact.reactElement)=?,
      ~position: option(position)=?,
      ~steps: [ | `Int(int) | `Float(float)],
      ~variant: option(variant)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~activeStep=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            activeStep,
          ),
        ~backButton?,
        ~className?,
        ~nextButton?,
        ~position=?Js.Option.map((. v) => positionToJs(v), position),
        ~steps=MaterialUi_Helpers.unwrapValue(steps),
        ~variant=?Js.Option.map((. v) => variantToJs(v), variant),
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~elevation=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            elevation,
          ),
        ~square?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
