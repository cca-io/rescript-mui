[@bs.deriving jsConverter]
type position = [ | [@bs.as "start"] `Start | [@bs.as "end"] `End];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "standard"] `Standard
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "filled"] `Filled
];

module Classes = {
  type classesType =
    | Root(string)
    | Filled(string)
    | PositionStart(string)
    | PositionEnd(string)
    | DisablePointerEvents(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Filled(_) => "filled"
    | PositionStart(_) => "positionStart"
    | PositionEnd(_) => "positionEnd"
    | DisablePointerEvents(_) => "disablePointerEvents";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Filled(className)
                         | PositionStart(className)
                         | PositionEnd(className)
                         | DisablePointerEvents(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~disablePointerEvents: bool=?,
    ~disableTypography: bool=?,
    ~muiFormControl: Js.t({..})=?,
    ~position: string=?,
    ~variant: string=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disablePointerEvents: option(bool)=?,
      ~disableTypography: option(bool)=?,
      ~muiFormControl: option(Js.t({..}))=?,
      ~position: option(position)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~disablePointerEvents?,
    ~disableTypography?,
    ~muiFormControl?,
    ~position=?position->(Belt.Option.map(v => positionToJs(v))),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "InputAdornment";
