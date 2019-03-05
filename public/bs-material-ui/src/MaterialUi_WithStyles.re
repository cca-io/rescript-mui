type classRecordDef('classRecord) =
  | Record('classRecord)
  | ThemeFunc(MaterialUi_Theme.t => 'classRecord);

module type WithStylesSafeTemplate = {
  type classRecord;
  type classRecordJs;
  type classRecordStrings;
  type classRecordStringsJs;
  let classRecordToJs: classRecord => classRecordJs;
  let classRecordStringsFromJs: classRecordStringsJs => classRecordStrings;
  let classes: classRecordDef(classRecord);
};

module WithStylesSafe = (S: WithStylesSafeTemplate) => {
  let withStyles: S.classRecordJs => ReasonReact.reactClass = MaterialUi_WithStyles_Helper.createStyled;

  let withStylesWithTheme:
    (MaterialUi_Theme.t => S.classRecordJs) => ReasonReact.reactClass = MaterialUi_WithStyles_Helper.createStyled;

  module Styled = {
    let styled =
      switch (S.classes) {
      | Record(record) => withStyles(record->S.classRecordToJs)
      | ThemeFunc(func) =>
        withStylesWithTheme(theme => func(theme)->S.classRecordToJs)
      };

    let make =
        (
          children:
            {. "classes": S.classRecordStringsJs} => ReasonReact.reactElement,
        ) =>
      ReasonReact.wrapJsForReason(
        ~reactClass=styled,
        ~props=Js.Obj.empty(),
        children,
      );
  };

  let component = ReasonReact.statelessComponent("WithStylesSafe");
  let make = children => {
    ...component,
    render: _ =>
      <Styled>
        ...{classes => children(classes##classes->S.classRecordStringsFromJs)}
      </Styled>,
  };
};

let createStyled: Js.Dict.t(ReactDOMRe.Style.t) => ReasonReact.reactClass = MaterialUi_WithStyles_Helper.createStyled;
let createStyledWithTheme:
  (MaterialUi_Theme.t => Js.Dict.t(ReactDOMRe.Style.t)) =>
  ReasonReact.reactClass = MaterialUi_WithStyles_Helper.createStyled;
external renderFunctionToChildren: 'b => 'a = "%identity";

type style = {
  name: string,
  styles: ReactDOMRe.Style.t,
};

let make =
    (
      ~classes: option(list(style))=?,
      ~classesWithTheme: option(MaterialUi_Theme.t => list(style))=?,
      ~render: Js.t({..}) => ReasonReact.reactElement,
      _,
    ) => {
  let generateDict = (lst: list(style)) => {
    let classDict: Js.Dict.t(ReactDOMRe.Style.t) = Js.Dict.empty();
    lst->Belt.List.forEach(style =>
      Js.Dict.set(classDict, style.name, style.styles)
    );
    classDict;
  };

  let styled =
    switch (classes, classesWithTheme) {
    | (Some(classList), None) => createStyled(classList->generateDict)
    | (None, Some(func)) =>
      createStyledWithTheme(theme => func(theme)->generateDict)
    | _ => raise(Not_found)
    };

  ReasonReact.wrapJsForReason(
    ~reactClass=styled, ~props=Js.Obj.empty(), styles =>
    render(styles##classes)->renderFunctionToChildren
  );
};
