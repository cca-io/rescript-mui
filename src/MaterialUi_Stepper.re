[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

module Classes = {
  type classesType =
    | Root(string)
    | Horizontal(string)
    | Vertical(string)
    | AlternativeLabel(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | AlternativeLabel(_) => "alternativeLabel";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Horizontal(className)
             | Vertical(className)
             | AlternativeLabel(className) =>
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
    ~activeStep: 'number_6=?,
    ~alternativeLabel: bool=?,
    ~className: string=?,
    ~connector: ReasonReact.reactElement=?,
    ~nonLinear: bool=?,
    ~orientation: string=?,
    ~component: 'union_rmxp=?,
    ~elevation: 'number_s=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Stepper/Stepper"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~activeStep: option([ | `Int(int) | `Float(float)])=?,
      ~alternativeLabel: option(bool)=?,
      ~className: option(string)=?,
      ~connector: option(ReasonReact.reactElement)=?,
      ~nonLinear: option(bool)=?,
      ~orientation: option(orientation)=?,
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
        ~alternativeLabel?,
        ~className?,
        ~connector?,
        ~nonLinear?,
        ~orientation=?
          Js.Option.map((. v) => orientationToJs(v), orientation),
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
