module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    horizontal: string,
    [@bs.optional]
    vertical: string,
    [@bs.optional]
    label: string,
    [@bs.optional]
    active: string,
    [@bs.optional]
    completed: string,
    [@bs.optional]
    error: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    iconContainer: string,
    [@bs.optional]
    alternativeLabel: string,
    [@bs.optional]
    labelContainer: string,
  };
  let make = t;
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
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~disabled: option(bool)=?,
    ~error: option(bool)=?,
    ~icon: option(React.element)=?,
    ~optional: option(React.element)=?,
    ~_StepIconComponent: option(StepIconComponent.t)=?,
    ~_StepIconProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "StepLabel";
