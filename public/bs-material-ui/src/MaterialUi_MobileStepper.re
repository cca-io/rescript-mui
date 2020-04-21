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

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "positionBottom": option(option(string)),
    "positionTop": option(option(string)),
    "positionStatic": option(option(string)),
    "dots": option(option(string)),
    "dot": option(option(string)),
    "dotActive": option(option(string)),
    "progress": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~positionBottom: string=?,
      ~positionTop: string=?,
      ~positionStatic: string=?,
      ~dots: string=?,
      ~dot: string=?,
      ~dotActive: string=?,
      ~progress: string=?,
      unit
    ) =>
    t;
};

type position = [ | `Bottom | `Static | `Top];

type variant = [ | `Dots | `Progress | `Text];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~component: option(Component.t)=?,
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~square: option(bool)=?,
    ~activeStep: option(MaterialUi_Types.Number.t)=?,
    ~backButton: option(React.element)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~_LinearProgressProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~nextButton: option(React.element)=?,
    ~position: option(
                 [@bs.string] [
                   | [@bs.as "bottom"] `Bottom
                   | [@bs.as "static"] `Static
                   | [@bs.as "top"] `Top
                 ],
               )
                 =?,
    ~steps: MaterialUi_Types.Number.t,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "dots"] `Dots
                  | [@bs.as "progress"] `Progress
                  | [@bs.as "text"] `Text
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "MobileStepper";
