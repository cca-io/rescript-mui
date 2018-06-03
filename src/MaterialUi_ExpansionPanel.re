module Classes = {
  type classesType =
    | Root(string)
    | Expanded(string)
    | Disabled(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Expanded(_) => "expanded"
    | Disabled(_) => "disabled";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Expanded(className)
           | Disabled(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~_CollapseProps: Js.t({..})=?,
    ~defaultExpanded: bool=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~onChange: 'any_rl3k=?,
    ~component: 'union_rrf6=?,
    ~elevation: 'number_1=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/ExpansionPanel/ExpansionPanel"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~className: option(string)=?,
      ~_CollapseProps: option(Js.t({..}))=?,
      ~defaultExpanded: option(bool)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~onChange: option((ReactEventRe.Form.t, bool) => unit)=?,
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
        ~className?,
        ~_CollapseProps?,
        ~defaultExpanded?,
        ~disabled?,
        ~expanded?,
        ~onChange?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~elevation=?
          elevation |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~square?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
