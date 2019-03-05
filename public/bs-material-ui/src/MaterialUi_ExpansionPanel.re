module Classes = {
  type classesType =
    | Root(string)
    | Rounded(string)
    | Expanded(string)
    | Disabled(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Rounded(_) => "rounded"
    | Expanded(_) => "expanded"
    | Disabled(_) => "disabled";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Rounded(className)
                         | Expanded(className)
                         | Disabled(className) =>
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
    ~className: string=?,
    ~_CollapseProps: Js.t({..})=?,
    ~defaultExpanded: bool=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~onChange: 'any_rfd6=?,
    ~square: bool=?,
    ~elevation: 'number_6=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "ExpansionPanel";
let make =
    (
      ~className: option(string)=?,
      ~_CollapseProps: option(Js.t({..}))=?,
      ~defaultExpanded: option(bool)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~square: option(bool)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~_CollapseProps?,
        ~defaultExpanded?,
        ~disabled?,
        ~expanded?,
        ~onChange?,
        ~square?,
        ~elevation=?
          elevation->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
