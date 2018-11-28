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
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
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
                     )
                   );
};

[@bs.obj]
external makeProps:
  (
    ~activeStep: 'number_l=?,
    ~backButton: ReasonReact.reactElement=?,
    ~className: string=?,
    ~_LinearProgressProps: Js.t({..})=?,
    ~nextButton: ReasonReact.reactElement=?,
    ~position: string=?,
    ~steps: 'number_7,
    ~variant: string=?,
    ~component: 'union_r4ma=?,
    ~elevation: 'number_8=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "MobileStepper";
let make =
    (
      ~activeStep: option([ | `Int(int) | `Float(float)])=?,
      ~backButton: option(ReasonReact.reactElement)=?,
      ~className: option(string)=?,
      ~_LinearProgressProps: option(Js.t({..}))=?,
      ~nextButton: option(ReasonReact.reactElement)=?,
      ~position: option(position)=?,
      ~steps: [ | `Int(int) | `Float(float)],
      ~variant: option(variant)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
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
          activeStep->(
                        Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                      ),
        ~backButton?,
        ~className?,
        ~_LinearProgressProps?,
        ~nextButton?,
        ~position=?position->(Belt.Option.map(v => positionToJs(v))),
        ~steps=MaterialUi_Helpers.unwrapValue(steps),
        ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
        ~component=?
          component->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~elevation=?
          elevation->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~square?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
