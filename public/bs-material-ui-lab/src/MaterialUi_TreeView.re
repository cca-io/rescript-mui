module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className) =>
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
    ~defaultCollapseIcon: React.element=?,
    ~defaultEndIcon: React.element=?,
    ~defaultExpanded: array(string)=?,
    ~defaultExpandIcon: React.element=?,
    ~defaultParentIcon: React.element=?,
    ~defaultSelected: 'union_rh7t=?,
    ~disableSelection: bool=?,
    ~expanded: array(string)=?,
    ~multiSelect: bool=?,
    ~onNodeSelect: 'any_rajx=?,
    ~onNodeToggle: 'any_rv5h=?,
    ~selected: 'union_r3e2=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~defaultCollapseIcon: option(React.element)=?,
      ~defaultEndIcon: option(React.element)=?,
      ~defaultExpanded: option(array(string))=?,
      ~defaultExpandIcon: option(React.element)=?,
      ~defaultParentIcon: option(React.element)=?,
      ~defaultSelected:
         option([ | `Array(array(string)) | `String(string)])=?,
      ~disableSelection: option(bool)=?,
      ~expanded: option(array(string))=?,
      ~multiSelect: option(bool)=?,
      ~onNodeSelect:
         option(
           (Js.t({..}), [ | `Array('any_rlpo) | `String(string)]) => unit,
         )=?,
      ~onNodeToggle: option((Js.t({..}), array('any_rw8b)) => unit)=?,
      ~selected: option([ | `Array(array(string)) | `String(string)])=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~defaultCollapseIcon?,
    ~defaultEndIcon?,
    ~defaultExpanded?,
    ~defaultExpandIcon?,
    ~defaultParentIcon?,
    ~defaultSelected=?
      defaultSelected->(
                         Belt.Option.map(v =>
                           MaterialUi_Helpers.unwrapValue(v)
                         )
                       ),
    ~disableSelection?,
    ~expanded?,
    ~multiSelect?,
    ~onNodeSelect?,
    ~onNodeToggle?,
    ~selected=?
      selected->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "TreeView";
