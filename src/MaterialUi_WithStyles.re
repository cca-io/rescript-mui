[@bs.module] external objectHash : 'a => string = "object-hash";

module type WithStylesSafeTemplate = {
  type classRecord;
  type classRecordJs;
  type classRecordStrings;
  type classRecordStringsJs;
  let classRecordToJs: classRecord => classRecordJs;
  let classRecordStringsFromJs: classRecordStringsJs => classRecordStrings;
  let classes: classRecord;
};

module WithStylesSafe = (S: WithStylesSafeTemplate) => {
  /* Component */
  let innerComponent = ReasonReact.statelessComponent("WithStyles");
  let makeStateLessComponent = (~render: ReasonReact.reactElement, _children) => {
    ...innerComponent,
    render: _self => render,
  };
  /* Helper Component for turning the wrapped Component into a Reason Component */
  module Helper = {
    let make = (~render, ~reactClass: ReasonReact.reactClass, children) =>
      ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props={"render": render},
        children,
      );
  };
  /* Imported from MUI */
  type withStylesComponent('a) = (. 'a) => ReasonReact.reactClass;
  [@bs.module "@material-ui/core/styles"]
  external withStylesExt : 'styles => withStylesComponent('component) =
    "withStyles";
  let createStylesWrapper = styles => withStylesExt(styles);
  /* Generating the Wrapper */
  let generateWrapper = () => {
    let wrapper = createStylesWrapper(S.classRecordToJs(S.classes));
    wrapper(.
      ReasonReact.wrapReasonForJs(~component=innerComponent, jsProps =>
        makeStateLessComponent(
          ~render=
            jsProps##render(S.classRecordStringsFromJs(jsProps##classes)),
          [||],
        )
      ),
    );
  };
  /* Reducer Component to cache the wrapper component */
  type state = {
    hash: string,
    wrapper: ReasonReact.reactClass,
  };
  type actions =
    | SetWrapper(ReasonReact.reactClass);
  let component = ReasonReact.reducerComponent("WithStylesSafeCached");
  let make =
      (~render: S.classRecordStrings => ReasonReact.reactElement, children) => {
    ...component,
    initialState: () => {
      hash: objectHash(S.classes),
      wrapper: generateWrapper(),
    },
    reducer: (action, state) =>
      switch (action) {
      | SetWrapper(wrapper) => ReasonReact.Update({...state, wrapper})
      },
    willReceiveProps: ({state}) => {
      let newHash = objectHash(S.classes);
      if (newHash === state.hash) {
        state;
      } else {
        {hash: newHash, wrapper: generateWrapper()};
      };
    },
    render: ({state}) =>
      <Helper render reactClass=state.wrapper> children </Helper>,
  };
};

type style = {
  name: string,
  styles: ReactDOMRe.Style.t,
};

let innerComponent = ReasonReact.statelessComponent("WithStyles");

let innerMake = (~render, ~classes: Js.t({..}), _children) => {
  ...innerComponent,
  render: _self => render(classes),
};

type withStylesComponent('a) = (. 'a) => ReasonReact.reactClass;

[@bs.module "@material-ui/core/styles"]
external withStylesExt : 'styles => withStylesComponent('component) =
  "withStyles";

let createStylesWrapper = styles => withStylesExt(styles);

/* Helper Component for turning the wrapped Component into a Reason Component */
module Helper = {
  let make = (~render, ~reactClass: ReasonReact.reactClass, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"render": render},
      children,
    );
};

/* Generating the Wrapper */
let generateWrapper =
    (
      classes: option(list(style)),
      classesWithTheme: option(MaterialUi_Theme.t => list(style)),
    ) => {
  let generateDict = (lst: list(style)) => {
    let classDict: Js.Dict.t(ReactDOMRe.Style.t) = Js.Dict.empty();
    StdLabels.List.iter(
      ~f=style => Js.Dict.set(classDict, style.name, style.styles),
      lst,
    );
    classDict;
  };
  let wrapper =
    switch (classes) {
    | Some(classes) => createStylesWrapper(generateDict(classes))
    | None =>
      switch (classesWithTheme) {
      | Some(classesWithTheme) =>
        createStylesWrapper(
          MaterialUi_Helpers.toJsUnsafe(theme =>
            generateDict(classesWithTheme(MaterialUi_Theme.tFromJs(theme)))
          ),
        )
      | None => createStylesWrapper(generateDict([]))
      }
    };
  wrapper(.
    ReasonReact.wrapReasonForJs(~component=innerComponent, jsProps =>
      innerMake(~render=jsProps##render, ~classes=jsProps##classes, [||])
    ),
  );
};

/* Reducer Component to cache the wrapper component */
type state = {
  hash: string,
  wrapper: ReasonReact.reactClass,
};

type actions =
  | SetWrapper(ReasonReact.reactClass);

let component = ReasonReact.reducerComponent("WithStylesCached");

let make =
    (
      ~classes: option(list(style))=?,
      ~classesWithTheme: option(MaterialUi_Theme.t => list(style))=?,
      ~render,
      children,
    ) => {
  ...component,
  initialState: () => {
    hash: objectHash(classes) ++ objectHash(classesWithTheme),
    wrapper: generateWrapper(classes, classesWithTheme),
  },
  reducer: (action, state) =>
    switch (action) {
    | SetWrapper(wrapper) => ReasonReact.Update({...state, wrapper})
    },
  willReceiveProps: ({state}) => {
    let newHash = objectHash(classes) ++ objectHash(classesWithTheme);
    if (newHash === state.hash) {
      state;
    } else {
      {hash: newHash, wrapper: generateWrapper(classes, classesWithTheme)};
    };
  },
  render: ({state}) =>
    <Helper render reactClass=state.wrapper> children </Helper>,
};
