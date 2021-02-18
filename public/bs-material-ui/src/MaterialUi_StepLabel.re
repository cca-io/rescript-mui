module Classes = {
  type t = {
    .
    "root": option(string),
    "horizontal": option(string),
    "vertical": option(string),
    "label": option(string),
    "active": option(string),
    "completed": option(string),
    "error": option(string),
    "disabled": option(string),
    "iconContainer": option(string),
    "alternativeLabel": option(string),
    "labelContainer": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~horizontal: string=?,
      ~vertical: string=?,
      ~label: string=?,
      ~active: string=?,
      ~completed: string=?,
      ~error: string=?,
      ~disabled: string=?,
      ~iconContainer: string=?,
      ~alternativeLabel: string=?,
      ~labelContainer: string=?,
      unit
    ) =>
    t;
};

module StepIconComponent: {
  type t;
  let string: string => t;
  let stepIconComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let stepIconComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~icon: React.element=?,
    ~optional: React.element=?,
    ~_StepIconComponent: StepIconComponent.t=?,
    ~_StepIconProps: Js.t({..})=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "StepLabel";
