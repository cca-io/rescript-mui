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
external makePropsMui:
  (
    ~children: 'children=?,
    ~className: string=?,
    ~defaultExpanded: bool=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~onChange: 'any_r94f=?,
    ~square: bool=?,
    ~_TransitionComponent: 'union_rlti=?,
    ~_TransitionProps: Js.t({..})=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~component: 'union_rmc6=?,
    ~elevation: 'number_o=?,
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
      ~defaultExpanded: option(bool)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~square: option(bool)=?,
      ~_TransitionComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~defaultExpanded?,
    ~disabled?,
    ~expanded?,
    ~onChange?,
    ~square?,
    ~_TransitionComponent=?
      _TransitionComponent->(
                              Belt.Option.map(v =>
                                MaterialUi_Helpers.unwrapValue(v)
                              )
                            ),
    ~_TransitionProps?,
    ~key?,
    ~_ref=?ref_,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ExpansionPanel";
