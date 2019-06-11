module Classes = {
  type classesType =
    | Root(string)
    | Expanded(string)
    | Focused(string)
    | Disabled(string)
    | Content(string)
    | ExpandIcon(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Expanded(_) => "expanded"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | Content(_) => "content"
    | ExpandIcon(_) => "expandIcon";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Expanded(className)
                         | Focused(className)
                         | Disabled(className)
                         | Content(className)
                         | ExpandIcon(className) =>
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
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~expandIcon: React.element=?,
    ~_IconButtonProps: Js.t({..})=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocusVisible: 'genericCallback=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "ExpansionPanelSummary";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disabled: option(bool)=?,
      ~expanded: option(bool)=?,
      ~expandIcon: option(React.element)=?,
      ~_IconButtonProps: option(Js.t({..}))=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocusVisible: option('genericCallback)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~disabled?,
      ~expanded?,
      ~expandIcon?,
      ~_IconButtonProps?,
      ~onBlur?,
      ~onChange?,
      ~onClick?,
      ~onFocusVisible?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
