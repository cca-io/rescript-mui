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
  let withStyles: S.classRecordJs => React.component('a) = MaterialUi_WithStyles_Helper.createStyled;

  let withStylesWithTheme:
    (MaterialUi_Theme.t => S.classRecordJs) => React.component('a) = MaterialUi_WithStyles_Helper.createStyled;

  type x = unit => S.classRecordStringsJs;
  [@bs.module "@material-ui/styles"]
  external makeStyles: S.classRecordJs => x = "makeStyles";
  [@bs.module "@material-ui/styles"]
  external makeStylesWithTheme: ('a => 'b) => x = "makeStyles";
  let useStyles = () => {
    let stylesHook =
      React.useMemo0(() =>
        switch (S.classes) {
        | Record(record) => makeStyles(record->S.classRecordToJs)
        | ThemeFunc(func) =>
          makeStylesWithTheme(theme => func(theme)->S.classRecordToJs)
        }
      );
    stylesHook()->S.classRecordStringsFromJs;
  };

  module Styled = {
    let styled =
      switch (S.classes) {
      | Record(record) => withStyles(record->S.classRecordToJs)
      | ThemeFunc(func) =>
        withStylesWithTheme(theme => func(theme)->S.classRecordToJs)
      };

    [@react.component]
    let make =
        (~children: {. "classes": S.classRecordStringsJs} => React.element) =>
      React.createElement(styled, {"children": children});
  };

  [@react.component]
  let make = (~children: S.classRecordStrings => React.element) =>
    <Styled>
      ...{classes => children(classes##classes->S.classRecordStringsFromJs)}
    </Styled>;
};

let createStyled: Js.Dict.t(ReactDOMRe.Style.t) => React.component('a) = MaterialUi_WithStyles_Helper.createStyled;
let createStyledWithTheme:
  (MaterialUi_Theme.t => Js.Dict.t(ReactDOMRe.Style.t)) =>
  React.component('a) = MaterialUi_WithStyles_Helper.createStyled;
external renderFunctionToChildren: 'b => 'a = "%identity";

type style = {
  name: string,
  styles: ReactDOMRe.Style.t,
};

[@react.component]
let make =
    (
      ~classes: option(list(style))=?,
      ~classesWithTheme: option(MaterialUi_Theme.t => list(style))=?,
      ~render: Js.t({..}) => React.element,
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

  React.createElement(
    styled,
    {
      "children": styles => render(styles##classes)->renderFunctionToChildren,
    },
  );
};
