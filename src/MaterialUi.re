external toJsUnsafe : 'a => 'b = "%identity";

let unwrapValue =
  fun
  | `String(s) => toJsUnsafe(s)
  | `Bool(b) => toJsUnsafe(Js.Boolean.to_js_boolean(b))
  | `Float(f) => toJsUnsafe(f)
  | `Int(i) => toJsUnsafe(i)
  | `Date(d) => toJsUnsafe(d)
  | `Callback(c) => toJsUnsafe(c)
  | `Element(e) => toJsUnsafe(e)
  | `StringArray(sa) => toJsUnsafe(sa)
  | `IntArray(ia) => toJsUnsafe(ia)
  | `FloatArray(fa) => toJsUnsafe(fa)
  | `ObjectGeneric(og) => toJsUnsafe(og)
  | `ArrayGeneric(ag) => toJsUnsafe(ag)
  | `Object(_) => assert false
  | `Enum(_) => assert false
  | `EnumArray(_) => assert false;

module MuiTheme = {
  module Direction = {
    type t =
      | Ltr
      | Rtl;
    let toString = (direction: t) =>
      switch direction {
      | Ltr => "ltr"
      | Rtl => "rtl"
      };
    let fromString = (direction: string) =>
      switch direction {
      | "ltr" => Ltr
      | "rtl" => Rtl
      | other => raise(Failure("Unknown direction: " ++ other))
      };
  };
  module Spacing = {
    type t = {unit: int};
  };
  module Transitions = {
    module Easing = {
      [@bs.deriving jsConverter]
      type t = {
        easeInOut: string,
        easeOut: string,
        easeIn: string,
        sharp: string
      };
    };
    module Duration = {
      [@bs.deriving jsConverter]
      type t = {
        shortest: int,
        shorter: int,
        short: int,
        standard: int,
        complex: int,
        enteringScreen: int,
        leavingScreen: int
      };
    };
    [@bs.deriving jsConverter]
    type t = {
      easing: Easing.t,
      duration: Duration.t,
      getAutoHeightDuration: int => int,
      create: (string, {. "duration": int}) => string /* create: (string, {. "duration": int, "easing": string, "delay": int}) => string */
    };
  };
  [@bs.deriving jsConverter]
  type t = {
    direction: Direction.t,
    palette: unit,
    typography: unit,
    mixins: unit,
    breakpoints: unit,
    shadows: list(string),
    transitions: Transitions.t,
    spacing: Spacing.t,
    zIndex: int
  };
  let tFromJs = (theme) => {
    direction: Direction.fromString(theme##direction),
    palette: (),
    typography: (),
    mixins: (),
    breakpoints: (),
    shadows: Js.Array.reduce((lst, entry) => [entry, ...lst], [], theme##shadows),
    transitions: Transitions.tFromJs(theme##transitions),
    spacing: {
      unit: theme##spacing##unit
    },
    zIndex: theme##zIndex
  };
};

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
  let component = ReasonReact.statelessComponent("WithStyles");
  let makeStateLessComponent = (~render: ReasonReact.reactElement, _children) => {
    ...component,
    render: (_self) => render
  };
  /* Imported from MUI */
  type withStylesComponent('a) = [@bs] ('a => ReasonReact.reactClass);
  [@bs.module "material-ui/styles"]
  external withStylesExt : 'styles => withStylesComponent('component) = "withStyles";
  let createStylesWrapper = (styles) => withStylesExt(styles);
  let make = (~render: S.classRecordStrings => ReasonReact.reactElement, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass={
        let wrapper = createStylesWrapper(S.classRecordToJs(S.classes));
        [@bs]
        wrapper(
          ReasonReact.wrapReasonForJs(
            ~component,
            (jsProps) =>
              makeStateLessComponent(
                ~render=jsProps##render(S.classRecordStringsFromJs(jsProps##classes)),
                [||]
              )
          )
        );
      },
      ~props={"render": render},
      children
    );
};

module WithStyles = {
  type style = {
    name: string,
    styles: ReactDOMRe.Style.t
  };
  let component = ReasonReact.statelessComponent("WithStyles");
  let make = (~render, ~classes: Js.t({..}), _children) => {
    ...component,
    render: (_self) => render(classes)
  };
  type withStylesComponent('a) = [@bs] ('a => ReasonReact.reactClass);
  [@bs.module "material-ui/styles"]
  external withStylesExt : 'styles => withStylesComponent('component) = "withStyles";
  let createStylesWrapper = (styles) => withStylesExt(styles);
  let make =
      (
        ~classes: option(list(style))=?,
        ~classesWithTheme: option(MuiTheme.t => list(style))=?,
        ~render,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass={
        let generateDict = (lst: list(style)) => {
          let classDict: Js.Dict.t(ReactDOMRe.Style.t) = Js.Dict.empty();
          StdLabels.List.iter(~f=(style) => Js.Dict.set(classDict, style.name, style.styles), lst);
          classDict;
        };
        let wrapper =
          switch classes {
          | Some(classes) => createStylesWrapper(generateDict(classes))
          | None =>
            switch classesWithTheme {
            | Some(classesWithTheme) =>
              createStylesWrapper(
                toJsUnsafe((theme) => generateDict(classesWithTheme(MuiTheme.tFromJs(theme))))
              )
            | None => createStylesWrapper(generateDict([]))
            }
          };
        [@bs]
        wrapper(
          ReasonReact.wrapReasonForJs(
            ~component,
            (jsProps) => make(~render=jsProps##render, ~classes=jsProps##classes, [||])
          )
        );
      },
      ~props={"render": render},
      children
    );
};

module Colors = {
  module Common = {
    [@bs.module "material-ui/colors/common"] external commonExt : Js.Dict.t(string) = "default";
    let black: string = Js.Dict.unsafeGet(commonExt, "black");
    let white: string = Js.Dict.unsafeGet(commonExt, "white");
  };
  module Red = {
    [@bs.module "material-ui/colors/red"] external redExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(redExt, "50");
    let c100: string = Js.Dict.unsafeGet(redExt, "100");
    let c200: string = Js.Dict.unsafeGet(redExt, "200");
    let c300: string = Js.Dict.unsafeGet(redExt, "300");
    let c400: string = Js.Dict.unsafeGet(redExt, "400");
    let c500: string = Js.Dict.unsafeGet(redExt, "500");
    let c600: string = Js.Dict.unsafeGet(redExt, "600");
    let c700: string = Js.Dict.unsafeGet(redExt, "700");
    let c800: string = Js.Dict.unsafeGet(redExt, "800");
    let c900: string = Js.Dict.unsafeGet(redExt, "900");
    let a100: string = Js.Dict.unsafeGet(redExt, "A100");
    let a200: string = Js.Dict.unsafeGet(redExt, "A200");
    let a400: string = Js.Dict.unsafeGet(redExt, "A400");
    let a700: string = Js.Dict.unsafeGet(redExt, "A700");
  };
  module Pink = {
    [@bs.module "material-ui/colors/pink"] external pinkExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(pinkExt, "50");
    let c100: string = Js.Dict.unsafeGet(pinkExt, "100");
    let c200: string = Js.Dict.unsafeGet(pinkExt, "200");
    let c300: string = Js.Dict.unsafeGet(pinkExt, "300");
    let c400: string = Js.Dict.unsafeGet(pinkExt, "400");
    let c500: string = Js.Dict.unsafeGet(pinkExt, "500");
    let c600: string = Js.Dict.unsafeGet(pinkExt, "600");
    let c700: string = Js.Dict.unsafeGet(pinkExt, "700");
    let c800: string = Js.Dict.unsafeGet(pinkExt, "800");
    let c900: string = Js.Dict.unsafeGet(pinkExt, "900");
    let a100: string = Js.Dict.unsafeGet(pinkExt, "A100");
    let a200: string = Js.Dict.unsafeGet(pinkExt, "A200");
    let a400: string = Js.Dict.unsafeGet(pinkExt, "A400");
    let a700: string = Js.Dict.unsafeGet(pinkExt, "A700");
  };
  module Purple = {
    [@bs.module "material-ui/colors/purple"] external purpleExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(purpleExt, "50");
    let c100: string = Js.Dict.unsafeGet(purpleExt, "100");
    let c200: string = Js.Dict.unsafeGet(purpleExt, "200");
    let c300: string = Js.Dict.unsafeGet(purpleExt, "300");
    let c400: string = Js.Dict.unsafeGet(purpleExt, "400");
    let c500: string = Js.Dict.unsafeGet(purpleExt, "500");
    let c600: string = Js.Dict.unsafeGet(purpleExt, "600");
    let c700: string = Js.Dict.unsafeGet(purpleExt, "700");
    let c800: string = Js.Dict.unsafeGet(purpleExt, "800");
    let c900: string = Js.Dict.unsafeGet(purpleExt, "900");
    let a100: string = Js.Dict.unsafeGet(purpleExt, "A100");
    let a200: string = Js.Dict.unsafeGet(purpleExt, "A200");
    let a400: string = Js.Dict.unsafeGet(purpleExt, "A400");
    let a700: string = Js.Dict.unsafeGet(purpleExt, "A700");
  };
  module DeepPurple = {
    [@bs.module "material-ui/colors/deepPurple"]
    external deepPurpleExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(deepPurpleExt, "50");
    let c100: string = Js.Dict.unsafeGet(deepPurpleExt, "100");
    let c200: string = Js.Dict.unsafeGet(deepPurpleExt, "200");
    let c300: string = Js.Dict.unsafeGet(deepPurpleExt, "300");
    let c400: string = Js.Dict.unsafeGet(deepPurpleExt, "400");
    let c500: string = Js.Dict.unsafeGet(deepPurpleExt, "500");
    let c600: string = Js.Dict.unsafeGet(deepPurpleExt, "600");
    let c700: string = Js.Dict.unsafeGet(deepPurpleExt, "700");
    let c800: string = Js.Dict.unsafeGet(deepPurpleExt, "800");
    let c900: string = Js.Dict.unsafeGet(deepPurpleExt, "900");
    let a100: string = Js.Dict.unsafeGet(deepPurpleExt, "A100");
    let a200: string = Js.Dict.unsafeGet(deepPurpleExt, "A200");
    let a400: string = Js.Dict.unsafeGet(deepPurpleExt, "A400");
    let a700: string = Js.Dict.unsafeGet(deepPurpleExt, "A700");
  };
  module Indigo = {
    [@bs.module "material-ui/colors/indigo"] external indigoExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(indigoExt, "50");
    let c100: string = Js.Dict.unsafeGet(indigoExt, "100");
    let c200: string = Js.Dict.unsafeGet(indigoExt, "200");
    let c300: string = Js.Dict.unsafeGet(indigoExt, "300");
    let c400: string = Js.Dict.unsafeGet(indigoExt, "400");
    let c500: string = Js.Dict.unsafeGet(indigoExt, "500");
    let c600: string = Js.Dict.unsafeGet(indigoExt, "600");
    let c700: string = Js.Dict.unsafeGet(indigoExt, "700");
    let c800: string = Js.Dict.unsafeGet(indigoExt, "800");
    let c900: string = Js.Dict.unsafeGet(indigoExt, "900");
    let a100: string = Js.Dict.unsafeGet(indigoExt, "A100");
    let a200: string = Js.Dict.unsafeGet(indigoExt, "A200");
    let a400: string = Js.Dict.unsafeGet(indigoExt, "A400");
    let a700: string = Js.Dict.unsafeGet(indigoExt, "A700");
  };
  module Blue = {
    [@bs.module "material-ui/colors/blue"] external blueExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(blueExt, "50");
    let c100: string = Js.Dict.unsafeGet(blueExt, "100");
    let c200: string = Js.Dict.unsafeGet(blueExt, "200");
    let c300: string = Js.Dict.unsafeGet(blueExt, "300");
    let c400: string = Js.Dict.unsafeGet(blueExt, "400");
    let c500: string = Js.Dict.unsafeGet(blueExt, "500");
    let c600: string = Js.Dict.unsafeGet(blueExt, "600");
    let c700: string = Js.Dict.unsafeGet(blueExt, "700");
    let c800: string = Js.Dict.unsafeGet(blueExt, "800");
    let c900: string = Js.Dict.unsafeGet(blueExt, "900");
    let a100: string = Js.Dict.unsafeGet(blueExt, "A100");
    let a200: string = Js.Dict.unsafeGet(blueExt, "A200");
    let a400: string = Js.Dict.unsafeGet(blueExt, "A400");
    let a700: string = Js.Dict.unsafeGet(blueExt, "A700");
  };
  module LightBlue = {
    [@bs.module "material-ui/colors/lightBlue"]
    external lightBlueExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(lightBlueExt, "50");
    let c100: string = Js.Dict.unsafeGet(lightBlueExt, "100");
    let c200: string = Js.Dict.unsafeGet(lightBlueExt, "200");
    let c300: string = Js.Dict.unsafeGet(lightBlueExt, "300");
    let c400: string = Js.Dict.unsafeGet(lightBlueExt, "400");
    let c500: string = Js.Dict.unsafeGet(lightBlueExt, "500");
    let c600: string = Js.Dict.unsafeGet(lightBlueExt, "600");
    let c700: string = Js.Dict.unsafeGet(lightBlueExt, "700");
    let c800: string = Js.Dict.unsafeGet(lightBlueExt, "800");
    let c900: string = Js.Dict.unsafeGet(lightBlueExt, "900");
    let a100: string = Js.Dict.unsafeGet(lightBlueExt, "A100");
    let a200: string = Js.Dict.unsafeGet(lightBlueExt, "A200");
    let a400: string = Js.Dict.unsafeGet(lightBlueExt, "A400");
    let a700: string = Js.Dict.unsafeGet(lightBlueExt, "A700");
  };
  module Cyan = {
    [@bs.module "material-ui/colors/cyan"] external cyanExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(cyanExt, "50");
    let c100: string = Js.Dict.unsafeGet(cyanExt, "100");
    let c200: string = Js.Dict.unsafeGet(cyanExt, "200");
    let c300: string = Js.Dict.unsafeGet(cyanExt, "300");
    let c400: string = Js.Dict.unsafeGet(cyanExt, "400");
    let c500: string = Js.Dict.unsafeGet(cyanExt, "500");
    let c600: string = Js.Dict.unsafeGet(cyanExt, "600");
    let c700: string = Js.Dict.unsafeGet(cyanExt, "700");
    let c800: string = Js.Dict.unsafeGet(cyanExt, "800");
    let c900: string = Js.Dict.unsafeGet(cyanExt, "900");
    let a100: string = Js.Dict.unsafeGet(cyanExt, "A100");
    let a200: string = Js.Dict.unsafeGet(cyanExt, "A200");
    let a400: string = Js.Dict.unsafeGet(cyanExt, "A400");
    let a700: string = Js.Dict.unsafeGet(cyanExt, "A700");
  };
  module Teal = {
    [@bs.module "material-ui/colors/teal"] external tealExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(tealExt, "50");
    let c100: string = Js.Dict.unsafeGet(tealExt, "100");
    let c200: string = Js.Dict.unsafeGet(tealExt, "200");
    let c300: string = Js.Dict.unsafeGet(tealExt, "300");
    let c400: string = Js.Dict.unsafeGet(tealExt, "400");
    let c500: string = Js.Dict.unsafeGet(tealExt, "500");
    let c600: string = Js.Dict.unsafeGet(tealExt, "600");
    let c700: string = Js.Dict.unsafeGet(tealExt, "700");
    let c800: string = Js.Dict.unsafeGet(tealExt, "800");
    let c900: string = Js.Dict.unsafeGet(tealExt, "900");
    let a100: string = Js.Dict.unsafeGet(tealExt, "A100");
    let a200: string = Js.Dict.unsafeGet(tealExt, "A200");
    let a400: string = Js.Dict.unsafeGet(tealExt, "A400");
    let a700: string = Js.Dict.unsafeGet(tealExt, "A700");
  };
  module Green = {
    [@bs.module "material-ui/colors/green"] external greenExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(greenExt, "50");
    let c100: string = Js.Dict.unsafeGet(greenExt, "100");
    let c200: string = Js.Dict.unsafeGet(greenExt, "200");
    let c300: string = Js.Dict.unsafeGet(greenExt, "300");
    let c400: string = Js.Dict.unsafeGet(greenExt, "400");
    let c500: string = Js.Dict.unsafeGet(greenExt, "500");
    let c600: string = Js.Dict.unsafeGet(greenExt, "600");
    let c700: string = Js.Dict.unsafeGet(greenExt, "700");
    let c800: string = Js.Dict.unsafeGet(greenExt, "800");
    let c900: string = Js.Dict.unsafeGet(greenExt, "900");
    let a100: string = Js.Dict.unsafeGet(greenExt, "A100");
    let a200: string = Js.Dict.unsafeGet(greenExt, "A200");
    let a400: string = Js.Dict.unsafeGet(greenExt, "A400");
    let a700: string = Js.Dict.unsafeGet(greenExt, "A700");
  };
  module LightGreen = {
    [@bs.module "material-ui/colors/lightGreen"]
    external lightGreenExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(lightGreenExt, "50");
    let c100: string = Js.Dict.unsafeGet(lightGreenExt, "100");
    let c200: string = Js.Dict.unsafeGet(lightGreenExt, "200");
    let c300: string = Js.Dict.unsafeGet(lightGreenExt, "300");
    let c400: string = Js.Dict.unsafeGet(lightGreenExt, "400");
    let c500: string = Js.Dict.unsafeGet(lightGreenExt, "500");
    let c600: string = Js.Dict.unsafeGet(lightGreenExt, "600");
    let c700: string = Js.Dict.unsafeGet(lightGreenExt, "700");
    let c800: string = Js.Dict.unsafeGet(lightGreenExt, "800");
    let c900: string = Js.Dict.unsafeGet(lightGreenExt, "900");
    let a100: string = Js.Dict.unsafeGet(lightGreenExt, "A100");
    let a200: string = Js.Dict.unsafeGet(lightGreenExt, "A200");
    let a400: string = Js.Dict.unsafeGet(lightGreenExt, "A400");
    let a700: string = Js.Dict.unsafeGet(lightGreenExt, "A700");
  };
  module Lime = {
    [@bs.module "material-ui/colors/lime"] external limeExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(limeExt, "50");
    let c100: string = Js.Dict.unsafeGet(limeExt, "100");
    let c200: string = Js.Dict.unsafeGet(limeExt, "200");
    let c300: string = Js.Dict.unsafeGet(limeExt, "300");
    let c400: string = Js.Dict.unsafeGet(limeExt, "400");
    let c500: string = Js.Dict.unsafeGet(limeExt, "500");
    let c600: string = Js.Dict.unsafeGet(limeExt, "600");
    let c700: string = Js.Dict.unsafeGet(limeExt, "700");
    let c800: string = Js.Dict.unsafeGet(limeExt, "800");
    let c900: string = Js.Dict.unsafeGet(limeExt, "900");
    let a100: string = Js.Dict.unsafeGet(limeExt, "A100");
    let a200: string = Js.Dict.unsafeGet(limeExt, "A200");
    let a400: string = Js.Dict.unsafeGet(limeExt, "A400");
    let a700: string = Js.Dict.unsafeGet(limeExt, "A700");
  };
  module Yellow = {
    [@bs.module "material-ui/colors/yellow"] external yellowExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(yellowExt, "50");
    let c100: string = Js.Dict.unsafeGet(yellowExt, "100");
    let c200: string = Js.Dict.unsafeGet(yellowExt, "200");
    let c300: string = Js.Dict.unsafeGet(yellowExt, "300");
    let c400: string = Js.Dict.unsafeGet(yellowExt, "400");
    let c500: string = Js.Dict.unsafeGet(yellowExt, "500");
    let c600: string = Js.Dict.unsafeGet(yellowExt, "600");
    let c700: string = Js.Dict.unsafeGet(yellowExt, "700");
    let c800: string = Js.Dict.unsafeGet(yellowExt, "800");
    let c900: string = Js.Dict.unsafeGet(yellowExt, "900");
    let a100: string = Js.Dict.unsafeGet(yellowExt, "A100");
    let a200: string = Js.Dict.unsafeGet(yellowExt, "A200");
    let a400: string = Js.Dict.unsafeGet(yellowExt, "A400");
    let a700: string = Js.Dict.unsafeGet(yellowExt, "A700");
  };
  module Amber = {
    [@bs.module "material-ui/colors/amber"] external amberExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(amberExt, "50");
    let c100: string = Js.Dict.unsafeGet(amberExt, "100");
    let c200: string = Js.Dict.unsafeGet(amberExt, "200");
    let c300: string = Js.Dict.unsafeGet(amberExt, "300");
    let c400: string = Js.Dict.unsafeGet(amberExt, "400");
    let c500: string = Js.Dict.unsafeGet(amberExt, "500");
    let c600: string = Js.Dict.unsafeGet(amberExt, "600");
    let c700: string = Js.Dict.unsafeGet(amberExt, "700");
    let c800: string = Js.Dict.unsafeGet(amberExt, "800");
    let c900: string = Js.Dict.unsafeGet(amberExt, "900");
    let a100: string = Js.Dict.unsafeGet(amberExt, "A100");
    let a200: string = Js.Dict.unsafeGet(amberExt, "A200");
    let a400: string = Js.Dict.unsafeGet(amberExt, "A400");
    let a700: string = Js.Dict.unsafeGet(amberExt, "A700");
  };
  module Orange = {
    [@bs.module "material-ui/colors/orange"] external orangeExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(orangeExt, "50");
    let c100: string = Js.Dict.unsafeGet(orangeExt, "100");
    let c200: string = Js.Dict.unsafeGet(orangeExt, "200");
    let c300: string = Js.Dict.unsafeGet(orangeExt, "300");
    let c400: string = Js.Dict.unsafeGet(orangeExt, "400");
    let c500: string = Js.Dict.unsafeGet(orangeExt, "500");
    let c600: string = Js.Dict.unsafeGet(orangeExt, "600");
    let c700: string = Js.Dict.unsafeGet(orangeExt, "700");
    let c800: string = Js.Dict.unsafeGet(orangeExt, "800");
    let c900: string = Js.Dict.unsafeGet(orangeExt, "900");
    let a100: string = Js.Dict.unsafeGet(orangeExt, "A100");
    let a200: string = Js.Dict.unsafeGet(orangeExt, "A200");
    let a400: string = Js.Dict.unsafeGet(orangeExt, "A400");
    let a700: string = Js.Dict.unsafeGet(orangeExt, "A700");
  };
  module DeepOrange = {
    [@bs.module "material-ui/colors/deepOrange"]
    external deepOrangeExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(deepOrangeExt, "50");
    let c100: string = Js.Dict.unsafeGet(deepOrangeExt, "100");
    let c200: string = Js.Dict.unsafeGet(deepOrangeExt, "200");
    let c300: string = Js.Dict.unsafeGet(deepOrangeExt, "300");
    let c400: string = Js.Dict.unsafeGet(deepOrangeExt, "400");
    let c500: string = Js.Dict.unsafeGet(deepOrangeExt, "500");
    let c600: string = Js.Dict.unsafeGet(deepOrangeExt, "600");
    let c700: string = Js.Dict.unsafeGet(deepOrangeExt, "700");
    let c800: string = Js.Dict.unsafeGet(deepOrangeExt, "800");
    let c900: string = Js.Dict.unsafeGet(deepOrangeExt, "900");
    let a100: string = Js.Dict.unsafeGet(deepOrangeExt, "A100");
    let a200: string = Js.Dict.unsafeGet(deepOrangeExt, "A200");
    let a400: string = Js.Dict.unsafeGet(deepOrangeExt, "A400");
    let a700: string = Js.Dict.unsafeGet(deepOrangeExt, "A700");
  };
  module Brown = {
    [@bs.module "material-ui/colors/brown"] external brownExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(brownExt, "50");
    let c100: string = Js.Dict.unsafeGet(brownExt, "100");
    let c200: string = Js.Dict.unsafeGet(brownExt, "200");
    let c300: string = Js.Dict.unsafeGet(brownExt, "300");
    let c400: string = Js.Dict.unsafeGet(brownExt, "400");
    let c500: string = Js.Dict.unsafeGet(brownExt, "500");
    let c600: string = Js.Dict.unsafeGet(brownExt, "600");
    let c700: string = Js.Dict.unsafeGet(brownExt, "700");
    let c800: string = Js.Dict.unsafeGet(brownExt, "800");
    let c900: string = Js.Dict.unsafeGet(brownExt, "900");
    let a100: string = Js.Dict.unsafeGet(brownExt, "A100");
    let a200: string = Js.Dict.unsafeGet(brownExt, "A200");
    let a400: string = Js.Dict.unsafeGet(brownExt, "A400");
    let a700: string = Js.Dict.unsafeGet(brownExt, "A700");
  };
  module Grey = {
    [@bs.module "material-ui/colors/grey"] external greyExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(greyExt, "50");
    let c100: string = Js.Dict.unsafeGet(greyExt, "100");
    let c200: string = Js.Dict.unsafeGet(greyExt, "200");
    let c300: string = Js.Dict.unsafeGet(greyExt, "300");
    let c400: string = Js.Dict.unsafeGet(greyExt, "400");
    let c500: string = Js.Dict.unsafeGet(greyExt, "500");
    let c600: string = Js.Dict.unsafeGet(greyExt, "600");
    let c700: string = Js.Dict.unsafeGet(greyExt, "700");
    let c800: string = Js.Dict.unsafeGet(greyExt, "800");
    let c900: string = Js.Dict.unsafeGet(greyExt, "900");
    let a100: string = Js.Dict.unsafeGet(greyExt, "A100");
    let a200: string = Js.Dict.unsafeGet(greyExt, "A200");
    let a400: string = Js.Dict.unsafeGet(greyExt, "A400");
    let a700: string = Js.Dict.unsafeGet(greyExt, "A700");
  };
  module BlueGrey = {
    [@bs.module "material-ui/colors/blueGrey"]
    external blueGreyExt : Js.Dict.t(string) = "default";
    let c50: string = Js.Dict.unsafeGet(blueGreyExt, "50");
    let c100: string = Js.Dict.unsafeGet(blueGreyExt, "100");
    let c200: string = Js.Dict.unsafeGet(blueGreyExt, "200");
    let c300: string = Js.Dict.unsafeGet(blueGreyExt, "300");
    let c400: string = Js.Dict.unsafeGet(blueGreyExt, "400");
    let c500: string = Js.Dict.unsafeGet(blueGreyExt, "500");
    let c600: string = Js.Dict.unsafeGet(blueGreyExt, "600");
    let c700: string = Js.Dict.unsafeGet(blueGreyExt, "700");
    let c800: string = Js.Dict.unsafeGet(blueGreyExt, "800");
    let c900: string = Js.Dict.unsafeGet(blueGreyExt, "900");
    let a100: string = Js.Dict.unsafeGet(blueGreyExt, "A100");
    let a200: string = Js.Dict.unsafeGet(blueGreyExt, "A200");
    let a400: string = Js.Dict.unsafeGet(blueGreyExt, "A400");
    let a700: string = Js.Dict.unsafeGet(blueGreyExt, "A700");
  };
};

module AppBar = {
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "inherit"] | `Inherit
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
    [@bs.as "default"] | `Default
  ];
  [@bs.deriving jsConverter]
  type position = [
    [@bs.as "fixed"] | `Fixed
    [@bs.as "absolute"] | `Absolute
    [@bs.as "sticky"] | `Sticky
    [@bs.as "static"] | `Static
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | PositionFixed(string)
      | PositionAbsolute(string)
      | PositionSticky(string)
      | PositionStatic(string)
      | ColorDefault(string)
      | ColorPrimary(string)
      | ColorSecondary(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PositionFixed(_) => "positionFixed"
      | PositionAbsolute(_) => "positionAbsolute"
      | PositionSticky(_) => "positionSticky"
      | PositionStatic(_) => "positionStatic"
      | ColorDefault(_) => "colorDefault"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PositionFixed(className)
               | PositionAbsolute(className)
               | PositionSticky(className)
               | PositionStatic(className)
               | ColorDefault(className)
               | ColorPrimary(className)
               | ColorSecondary(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/AppBar/AppBar"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~color: string=?,
      ~position: string=?,
      ~component: 'union_7=?,
      ~elevation: 'number_e=?,
      ~square: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~position: option(position)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~position=?Js.Option.map([@bs] ((v) => positionToJs(v)), position),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~square=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), square),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Avatar = {
  module Classes = {
    type classesType =
      | Root(string)
      | ColorDefault(string)
      | Img(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorDefault(_) => "colorDefault"
      | Img(_) => "img";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorDefault(className)
               | Img(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Avatar/Avatar"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~alt: string=?,
      ~childrenClassName: string=?,
      ~className: string=?,
      ~component: 'union_d=?,
      ~imgProps: Js.t({..})=?,
      ~sizes: string=?,
      ~src: string=?,
      ~srcSet: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~alt: option(string)=?,
        ~childrenClassName: option(string)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~imgProps: option(Js.t({..}))=?,
        ~sizes: option(string)=?,
        ~src: option(string)=?,
        ~srcSet: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~alt?,
          ~childrenClassName?,
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~imgProps?,
          ~sizes?,
          ~src?,
          ~srcSet?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Backdrop = {
  [@bs.deriving jsConverter]
  type transitionDurationShape = {
    enter: int,
    exit: int
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Invisible(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Invisible(_) => "invisible";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Invisible(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Modal/Backdrop"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~invisible: Js.boolean=?,
      ~_open: Js.boolean,
      ~transitionDuration: 'union_f=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~invisible: option(bool)=?,
        ~_open: bool,
        ~transitionDuration:
           option([ | `Int(int) | `Float(float) | `Object(transitionDurationShape)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~invisible=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), invisible),
          ~_open=Js.Boolean.to_js_boolean(_open),
          ~transitionDuration=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              transitionDuration
            ),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Badge = {
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "default"] | `Default
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
    [@bs.as "error"] | `Error
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | Badge(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | ColorError(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Badge(_) => "badge"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | ColorError(_) => "colorError";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Badge(className)
               | ColorPrimary(className)
               | ColorSecondary(className)
               | ColorError(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Badge/Badge"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~badgeContent: ReasonReact.reactElement,
      ~className: string=?,
      ~color: string=?,
      ~component: 'union_z=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~badgeContent: ReasonReact.reactElement,
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~badgeContent,
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module BottomNavigationAction = {
  module Classes = {
    type classesType =
      | Root(string)
      | Selected(string)
      | SelectedIconOnly(string)
      | Wrapper(string)
      | Label(string)
      | LabelSelected(string)
      | LabelHidden(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Selected(_) => "selected"
      | SelectedIconOnly(_) => "selectedIconOnly"
      | Wrapper(_) => "wrapper"
      | Label(_) => "label"
      | LabelSelected(_) => "labelSelected"
      | LabelHidden(_) => "labelHidden";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Selected(className)
               | SelectedIconOnly(className)
               | Wrapper(className)
               | Label(className)
               | LabelSelected(className)
               | LabelHidden(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/BottomNavigation/BottomNavigationAction"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~icon: ReasonReact.reactElement=?,
      ~label: ReasonReact.reactElement=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~selected: Js.boolean=?,
      ~showLabel: Js.boolean=?,
      ~value: 'any_3=?,
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~component: 'union_y=?,
      ~disabled: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~selected: option(bool)=?,
        ~showLabel: option(bool)=?,
        ~value: option('any_3)=?,
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~icon?,
          ~label?,
          ~onChange?,
          ~onClick?,
          ~selected=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), selected),
          ~showLabel=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), showLabel),
          ~value?,
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module BottomNavigationButton = {
  module Classes = {
    type classesType =
      | Root(string)
      | Selected(string)
      | SelectedIconOnly(string)
      | Wrapper(string)
      | Label(string)
      | SelectedLabel(string)
      | HiddenLabel(string)
      | Icon(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Selected(_) => "selected"
      | SelectedIconOnly(_) => "selectedIconOnly"
      | Wrapper(_) => "wrapper"
      | Label(_) => "label"
      | SelectedLabel(_) => "selectedLabel"
      | HiddenLabel(_) => "hiddenLabel"
      | Icon(_) => "icon";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Selected(className)
               | SelectedIconOnly(className)
               | Wrapper(className)
               | Label(className)
               | SelectedLabel(className)
               | HiddenLabel(className)
               | Icon(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/BottomNavigation/BottomNavigationButton"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~theme: Js.t({..})=?,
      ~className: string=?,
      ~icon: 'union_5=?,
      ~label: ReasonReact.reactElement=?,
      ~onChange: 'any_e=?,
      ~onClick: 'any_i=?,
      ~selected: Js.boolean=?,
      ~showLabel: Js.boolean=?,
      ~value: 'any_p=?,
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~component: 'union_y=?,
      ~disabled: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~theme: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~icon: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~onChange: option('any_e)=?,
        ~onClick: option('any_i)=?,
        ~selected: option(bool)=?,
        ~showLabel: option(bool)=?,
        ~value: option('any_p)=?,
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~theme?,
          ~className?,
          ~icon=?Js.Option.map([@bs] ((v) => unwrapValue(v)), icon),
          ~label?,
          ~onChange?,
          ~onClick?,
          ~selected=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), selected),
          ~showLabel=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), showLabel),
          ~value?,
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module BottomNavigation = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/BottomNavigation/BottomNavigation"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~showLabels: Js.boolean=?,
      ~value: 'any_v=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~showLabels: option(bool)=?,
        ~value: option('any_v)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~onChange?,
          ~showLabels=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), showLabels),
          ~value?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ButtonBase = {
  module Classes = {
    type classesType =
      | Root(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ButtonBase/ButtonBase"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~className: string=?,
      ~component: 'union_y=?,
      ~disabled: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onClick?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Button = {
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "default"] | `Default
    [@bs.as "inherit"] | `Inherit
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
  ];
  [@bs.deriving jsConverter]
  type size = [ [@bs.as "small"] | `Small [@bs.as "medium"] | `Medium [@bs.as "large"] | `Large];
  [@bs.deriving jsConverter]
  type variant = [ [@bs.as "flat"] | `Flat [@bs.as "raised"] | `Raised [@bs.as "fab"] | `Fab];
  module Classes = {
    type classesType =
      | Root(string)
      | Label(string)
      | FlatPrimary(string)
      | FlatSecondary(string)
      | ColorInherit(string)
      | Raised(string)
      | KeyboardFocused(string)
      | RaisedPrimary(string)
      | RaisedSecondary(string)
      | Disabled(string)
      | Fab(string)
      | Mini(string)
      | SizeSmall(string)
      | SizeLarge(string)
      | FullWidth(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Label(_) => "label"
      | FlatPrimary(_) => "flatPrimary"
      | FlatSecondary(_) => "flatSecondary"
      | ColorInherit(_) => "colorInherit"
      | Raised(_) => "raised"
      | KeyboardFocused(_) => "keyboardFocused"
      | RaisedPrimary(_) => "raisedPrimary"
      | RaisedSecondary(_) => "raisedSecondary"
      | Disabled(_) => "disabled"
      | Fab(_) => "fab"
      | Mini(_) => "mini"
      | SizeSmall(_) => "sizeSmall"
      | SizeLarge(_) => "sizeLarge"
      | FullWidth(_) => "fullWidth";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Label(className)
               | FlatPrimary(className)
               | FlatSecondary(className)
               | ColorInherit(className)
               | Raised(className)
               | KeyboardFocused(className)
               | RaisedPrimary(className)
               | RaisedSecondary(className)
               | Disabled(className)
               | Fab(className)
               | Mini(className)
               | SizeSmall(className)
               | SizeLarge(className)
               | FullWidth(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Button/Button"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~color: string=?,
      ~component: 'union_f=?,
      ~disabled: Js.boolean=?,
      ~disableFocusRipple: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~fullWidth: Js.boolean=?,
      ~href: string=?,
      ~mini: Js.boolean=?,
      ~size: string=?,
      ~_type: string=?,
      ~variant: string=?,
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~disableFocusRipple: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~href: option(string)=?,
        ~mini: option(bool)=?,
        ~size: option(size)=?,
        ~_type: option(string)=?,
        ~variant: option(variant)=?,
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableFocusRipple=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableFocusRipple),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~fullWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullWidth),
          ~href?,
          ~mini=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), mini),
          ~size=?Js.Option.map([@bs] ((v) => sizeToJs(v)), size),
          ~_type?,
          ~variant=?Js.Option.map([@bs] ((v) => variantToJs(v)), variant),
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onClick?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module CardActions = {
  module Classes = {
    type classesType =
      | Root(string)
      | Action(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Action(_) => "action";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Action(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardActions"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disableActionSpacing: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disableActionSpacing: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disableActionSpacing=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableActionSpacing),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module CardContent = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardContent"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (~className: string=?, ~component: 'union_w=?, ~classes: Js.Dict.t(string)=?, unit) => _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module CardHeader = {
  module Classes = {
    type classesType =
      | Root(string)
      | Avatar(string)
      | Action(string)
      | Content(string)
      | Title(string)
      | Subheader(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Avatar(_) => "avatar"
      | Action(_) => "action"
      | Content(_) => "content"
      | Title(_) => "title"
      | Subheader(_) => "subheader";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Avatar(className)
               | Action(className)
               | Content(className)
               | Title(className)
               | Subheader(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardHeader"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~action: ReasonReact.reactElement=?,
      ~avatar: ReasonReact.reactElement=?,
      ~className: string=?,
      ~component: 'union_9=?,
      ~subheader: ReasonReact.reactElement=?,
      ~title: ReasonReact.reactElement=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~avatar: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~subheader: option(ReasonReact.reactElement)=?,
        ~title: option(ReasonReact.reactElement)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~action?,
          ~avatar?,
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~subheader?,
          ~title?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module CardMedia = {
  module Classes = {
    type classesType =
      | Root(string)
      | Media(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Media(_) => "media";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Media(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardMedia"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_p=?,
      ~image: string=?,
      ~src: string=?,
      ~style: Js.t({..})=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~image: option(string)=?,
        ~src: option(string)=?,
        ~style: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~image?,
          ~src?,
          ~style?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Card = {
  [@bs.module "material-ui/Card/Card"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~raised: Js.boolean=?,
      ~className: string=?,
      ~component: 'union_7=?,
      ~elevation: 'number_e=?,
      ~square: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~raised: option(bool)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~raised=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), raised),
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~square=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), square),
          ()
        ),
      children
    );
};

module Checkbox = {
  [@bs.deriving jsConverter]
  type color = [ [@bs.as "primary"] | `Primary [@bs.as "secondary"] | `Secondary];
  module Classes = {
    type classesType =
      | Default(string)
      | Checked(string)
      | CheckedPrimary(string)
      | CheckedSecondary(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Default(_) => "default"
      | Checked(_) => "checked"
      | CheckedPrimary(_) => "checkedPrimary"
      | CheckedSecondary(_) => "checkedSecondary"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Default(className)
               | Checked(className)
               | CheckedPrimary(className)
               | CheckedSecondary(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Checkbox/Checkbox"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~checked: 'union_r=?,
      ~checkedIcon: ReasonReact.reactElement=?,
      ~color: string=?,
      ~disabled: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~icon: ReasonReact.reactElement=?,
      ~id: string=?,
      ~indeterminate: Js.boolean=?,
      ~indeterminateIcon: ReasonReact.reactElement=?,
      ~inputProps: Js.t({..})=?,
      ~inputRef: ReasonReact.reactElement=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~_type: string=?,
      ~value: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~color: option(color)=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~id: option(string)=?,
        ~indeterminate: option(bool)=?,
        ~indeterminateIcon: option(ReasonReact.reactElement)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~_type: option(string)=?,
        ~value: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~checked=?Js.Option.map([@bs] ((v) => unwrapValue(v)), checked),
          ~checkedIcon?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~icon?,
          ~id?,
          ~indeterminate=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), indeterminate),
          ~indeterminateIcon?,
          ~inputProps?,
          ~inputRef?,
          ~onChange?,
          ~_type?,
          ~value?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Chip = {
  module Classes = {
    type classesType =
      | Root(string)
      | Clickable(string)
      | Deletable(string)
      | Avatar(string)
      | AvatarChildren(string)
      | Label(string)
      | DeleteIcon(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Clickable(_) => "clickable"
      | Deletable(_) => "deletable"
      | Avatar(_) => "avatar"
      | AvatarChildren(_) => "avatarChildren"
      | Label(_) => "label"
      | DeleteIcon(_) => "deleteIcon";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Clickable(className)
               | Deletable(className)
               | Avatar(className)
               | AvatarChildren(className)
               | Label(className)
               | DeleteIcon(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Chip/Chip"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~avatar: ReasonReact.reactElement=?,
      ~className: string=?,
      ~component: 'union_8=?,
      ~deleteIcon: ReasonReact.reactElement=?,
      ~label: ReasonReact.reactElement=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onDelete: unit => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~tabIndex: 'union_a=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~avatar: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~deleteIcon: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDelete: option(unit => unit)=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~avatar?,
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~deleteIcon?,
          ~label?,
          ~onClick?,
          ~onDelete?,
          ~onKeyDown?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module CircularProgress = {
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
    [@bs.as "inherit"] | `Inherit
  ];
  [@bs.deriving jsConverter]
  type variant = [
    [@bs.as "determinate"] | `Determinate
    [@bs.as "indeterminate"] | `Indeterminate
    [@bs.as "static"] | `Static
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | Svg(string)
      | SvgIndeterminate(string)
      | Circle(string)
      | CircleIndeterminate(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | Svg(_) => "svg"
      | SvgIndeterminate(_) => "svgIndeterminate"
      | Circle(_) => "circle"
      | CircleIndeterminate(_) => "circleIndeterminate";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorPrimary(className)
               | ColorSecondary(className)
               | Svg(className)
               | SvgIndeterminate(className)
               | Circle(className)
               | CircleIndeterminate(className) =>
                 Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Progress/CircularProgress"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~color: string=?,
      ~max: 'number_7=?,
      ~min: 'number_u=?,
      ~size: 'union_4=?,
      ~style: Js.t({..})=?,
      ~thickness: 'number_5=?,
      ~value: 'number_6=?,
      ~variant: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~max: option([ | `Int(int) | `Float(float)])=?,
        ~min: option([ | `Int(int) | `Float(float)])=?,
        ~size: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~style: option(Js.t({..}))=?,
        ~thickness: option([ | `Int(int) | `Float(float)])=?,
        ~value: option([ | `Int(int) | `Float(float)])=?,
        ~variant: option(variant)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~max=?Js.Option.map([@bs] ((v) => unwrapValue(v)), max),
          ~min=?Js.Option.map([@bs] ((v) => unwrapValue(v)), min),
          ~size=?Js.Option.map([@bs] ((v) => unwrapValue(v)), size),
          ~style?,
          ~thickness=?Js.Option.map([@bs] ((v) => unwrapValue(v)), thickness),
          ~value=?Js.Option.map([@bs] ((v) => unwrapValue(v)), value),
          ~variant=?Js.Option.map([@bs] ((v) => variantToJs(v)), variant),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ClickAwayListener = {
  [@bs.module "material-ui/utils/ClickAwayListener"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~onClickAway: ReasonReact.Callback.t(ReactEventRe.Mouse.t), unit) => _ =
    "";
  let make = (~onClickAway: ReasonReact.Callback.t(ReactEventRe.Mouse.t), children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(~onClickAway, ()), children);
};

module Collapse = {
  [@bs.deriving jsConverter]
  type timeoutShape = {
    enter: int,
    exit: int
  };
  [@bs.deriving jsConverter]
  type timeout = [ [@bs.as "auto"] | `Auto];
  module Classes = {
    type classesType =
      | Container(string)
      | Entered(string)
      | Wrapper(string)
      | WrapperInner(string);
    type t = list(classesType);
    let to_string =
      fun
      | Container(_) => "container"
      | Entered(_) => "entered"
      | Wrapper(_) => "wrapper"
      | WrapperInner(_) => "wrapperInner";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Container(className)
               | Entered(className)
               | Wrapper(className)
               | WrapperInner(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/transitions/Collapse"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~collapsedHeight: string=?,
      ~component: 'union_n=?,
      ~_in: Js.boolean=?,
      ~onEnter: unit => unit=?,
      ~onEntered: unit => unit=?,
      ~onEntering: unit => unit=?,
      ~onExit: unit => unit=?,
      ~onExiting: unit => unit=?,
      ~style: Js.t({..})=?,
      ~theme: Js.t({..}),
      ~timeout: 'union_w=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~collapsedHeight: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~_in: option(bool)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntered: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~onExiting: option(unit => unit)=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape) | `Enum(timeout)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~collapsedHeight?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~_in=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _in),
          ~onEnter?,
          ~onEntered?,
          ~onEntering?,
          ~onExit?,
          ~onExiting?,
          ~style?,
          ~theme,
          ~timeout=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(timeoutToJs(v)))
                  | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              timeout
            ),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module DialogActions = {
  module Classes = {
    type classesType =
      | Root(string)
      | Action(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Action(_) => "action";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Action(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogActions"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disableActionSpacing: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disableActionSpacing: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disableActionSpacing=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableActionSpacing),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module DialogContentText = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogContentText"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~className: string=?, ~classes: Js.Dict.t(string)=?, unit) => _ = "";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module DialogContent = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogContent"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~className: string=?, ~classes: Js.Dict.t(string)=?, unit) => _ = "";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module DialogTitle = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogTitle"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disableTypography: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disableTypography: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disableTypography=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableTypography),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Dialog = {
  [@bs.deriving jsConverter]
  type maxWidth = [
    [@bs.as "xs"] | `Xs
    [@bs.as "sm"] | `Sm
    [@bs.as "md"] | `Md
    [@bs.as "0"] | `False
  ];
  [@bs.deriving jsConverter]
  type transitionDurationShape = {
    enter: int,
    exit: int
  };
  module Classes = {
    type classesType =
      | Root(string)
      | Paper(string)
      | PaperWidthXs(string)
      | PaperWidthSm(string)
      | PaperWidthMd(string)
      | PaperFullWidth(string)
      | PaperFullScreen(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Paper(_) => "paper"
      | PaperWidthXs(_) => "paperWidthXs"
      | PaperWidthSm(_) => "paperWidthSm"
      | PaperWidthMd(_) => "paperWidthMd"
      | PaperFullWidth(_) => "paperFullWidth"
      | PaperFullScreen(_) => "paperFullScreen";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Paper(className)
               | PaperWidthXs(className)
               | PaperWidthSm(className)
               | PaperWidthMd(className)
               | PaperFullWidth(className)
               | PaperFullScreen(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/Dialog"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disableBackdropClick: Js.boolean=?,
      ~disableEscapeKeyDown: Js.boolean=?,
      ~fullScreen: Js.boolean=?,
      ~fullWidth: Js.boolean=?,
      ~maxWidth: string=?,
      ~onBackdropClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onClose: unit => unit=?,
      ~onEnter: unit => unit=?,
      ~onEntered: unit => unit=?,
      ~onEntering: unit => unit=?,
      ~onEscapeKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onExit: unit => unit=?,
      ~onExited: unit => unit=?,
      ~onExiting: unit => unit=?,
      ~_open: Js.boolean,
      ~paperProps: Js.t({..})=?,
      ~transition: 'union_e=?,
      ~transitionDuration: 'union_2=?,
      ~backdropComponent: 'union_0=?,
      ~backdropProps: Js.t({..})=?,
      ~container: 'union_q=?,
      ~disableAutoFocus: Js.boolean=?,
      ~disableEnforceFocus: Js.boolean=?,
      ~disableRestoreFocus: Js.boolean=?,
      ~hideBackdrop: Js.boolean=?,
      ~keepMounted: Js.boolean=?,
      ~manager: Js.t({..})=?,
      ~onRendered: unit => unit=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disableBackdropClick: option(bool)=?,
        ~disableEscapeKeyDown: option(bool)=?,
        ~fullScreen: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~maxWidth: option(maxWidth)=?,
        ~onBackdropClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onClose: option(unit => unit)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntered: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onEscapeKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onExit: option(unit => unit)=?,
        ~onExited: option(unit => unit)=?,
        ~onExiting: option(unit => unit)=?,
        ~_open: bool,
        ~paperProps: option(Js.t({..}))=?,
        ~transition: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~transitionDuration:
           option([ | `Int(int) | `Float(float) | `Object(transitionDurationShape)])=?,
        ~backdropComponent: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~backdropProps: option(Js.t({..}))=?,
        ~container: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~disableAutoFocus: option(bool)=?,
        ~disableEnforceFocus: option(bool)=?,
        ~disableRestoreFocus: option(bool)=?,
        ~hideBackdrop: option(bool)=?,
        ~keepMounted: option(bool)=?,
        ~manager: option(Js.t({..}))=?,
        ~onRendered: option(unit => unit)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disableBackdropClick=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableBackdropClick),
          ~disableEscapeKeyDown=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableEscapeKeyDown),
          ~fullScreen=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullScreen),
          ~fullWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullWidth),
          ~maxWidth=?Js.Option.map([@bs] ((v) => maxWidthToJs(v)), maxWidth),
          ~onBackdropClick?,
          ~onClose?,
          ~onEnter?,
          ~onEntered?,
          ~onEntering?,
          ~onEscapeKeyDown?,
          ~onExit?,
          ~onExited?,
          ~onExiting?,
          ~_open=Js.Boolean.to_js_boolean(_open),
          ~paperProps?,
          ~transition=?Js.Option.map([@bs] ((v) => unwrapValue(v)), transition),
          ~transitionDuration=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              transitionDuration
            ),
          ~backdropComponent=?Js.Option.map([@bs] ((v) => unwrapValue(v)), backdropComponent),
          ~backdropProps?,
          ~container=?Js.Option.map([@bs] ((v) => unwrapValue(v)), container),
          ~disableAutoFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableAutoFocus),
          ~disableEnforceFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableEnforceFocus),
          ~disableRestoreFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRestoreFocus),
          ~hideBackdrop=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), hideBackdrop),
          ~keepMounted=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), keepMounted),
          ~manager?,
          ~onRendered?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Divider = {
  module Classes = {
    type classesType =
      | Root(string)
      | Absolute(string)
      | Inset(string)
      | Light(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Absolute(_) => "absolute"
      | Inset(_) => "inset"
      | Light(_) => "light";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Absolute(className)
               | Inset(className)
               | Light(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Divider/Divider"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~absolute: Js.boolean=?,
      ~className: string=?,
      ~component: 'union_z=?,
      ~inset: Js.boolean=?,
      ~light: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~absolute: option(bool)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~inset: option(bool)=?,
        ~light: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~absolute=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), absolute),
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~inset=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), inset),
          ~light=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), light),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Drawer = {
  [@bs.deriving jsConverter]
  type anchor = [
    [@bs.as "left"] | `Left
    [@bs.as "top"] | `Top
    [@bs.as "right"] | `Right
    [@bs.as "bottom"] | `Bottom
  ];
  [@bs.deriving jsConverter]
  type transitionDurationShape = {
    enter: int,
    exit: int
  };
  [@bs.deriving jsConverter]
  type variant = [
    [@bs.as "permanent"] | `Permanent
    [@bs.as "persistent"] | `Persistent
    [@bs.as "temporary"] | `Temporary
  ];
  module Classes = {
    type classesType =
      | Docked(string)
      | Paper(string)
      | PaperAnchorLeft(string)
      | PaperAnchorRight(string)
      | PaperAnchorTop(string)
      | PaperAnchorBottom(string)
      | PaperAnchorDockedLeft(string)
      | PaperAnchorDockedTop(string)
      | PaperAnchorDockedRight(string)
      | PaperAnchorDockedBottom(string)
      | Modal(string);
    type t = list(classesType);
    let to_string =
      fun
      | Docked(_) => "docked"
      | Paper(_) => "paper"
      | PaperAnchorLeft(_) => "paperAnchorLeft"
      | PaperAnchorRight(_) => "paperAnchorRight"
      | PaperAnchorTop(_) => "paperAnchorTop"
      | PaperAnchorBottom(_) => "paperAnchorBottom"
      | PaperAnchorDockedLeft(_) => "paperAnchorDockedLeft"
      | PaperAnchorDockedTop(_) => "paperAnchorDockedTop"
      | PaperAnchorDockedRight(_) => "paperAnchorDockedRight"
      | PaperAnchorDockedBottom(_) => "paperAnchorDockedBottom"
      | Modal(_) => "modal";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Docked(className)
               | Paper(className)
               | PaperAnchorLeft(className)
               | PaperAnchorRight(className)
               | PaperAnchorTop(className)
               | PaperAnchorBottom(className)
               | PaperAnchorDockedLeft(className)
               | PaperAnchorDockedTop(className)
               | PaperAnchorDockedRight(className)
               | PaperAnchorDockedBottom(className)
               | Modal(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Drawer/Drawer"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~anchor: string=?,
      ~className: string=?,
      ~elevation: 'number_p=?,
      ~modalProps: Js.t({..})=?,
      ~onClose: unit => unit=?,
      ~_open: Js.boolean=?,
      ~paperProps: Js.t({..})=?,
      ~slideProps: Js.t({..})=?,
      ~theme: Js.t({..}),
      ~transitionDuration: 'union_9=?,
      ~variant: string=?,
      ~backdropComponent: 'union_0=?,
      ~backdropProps: Js.t({..})=?,
      ~container: 'union_q=?,
      ~disableAutoFocus: Js.boolean=?,
      ~disableBackdropClick: Js.boolean=?,
      ~disableEnforceFocus: Js.boolean=?,
      ~disableEscapeKeyDown: Js.boolean=?,
      ~disableRestoreFocus: Js.boolean=?,
      ~hideBackdrop: Js.boolean=?,
      ~keepMounted: Js.boolean=?,
      ~manager: Js.t({..})=?,
      ~onBackdropClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onEscapeKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onRendered: unit => unit=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~anchor: option(anchor)=?,
        ~className: option(string)=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~modalProps: option(Js.t({..}))=?,
        ~onClose: option(unit => unit)=?,
        ~_open: option(bool)=?,
        ~paperProps: option(Js.t({..}))=?,
        ~slideProps: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~transitionDuration:
           option([ | `Int(int) | `Float(float) | `Object(transitionDurationShape)])=?,
        ~variant: option(variant)=?,
        ~backdropComponent: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~backdropProps: option(Js.t({..}))=?,
        ~container: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~disableAutoFocus: option(bool)=?,
        ~disableBackdropClick: option(bool)=?,
        ~disableEnforceFocus: option(bool)=?,
        ~disableEscapeKeyDown: option(bool)=?,
        ~disableRestoreFocus: option(bool)=?,
        ~hideBackdrop: option(bool)=?,
        ~keepMounted: option(bool)=?,
        ~manager: option(Js.t({..}))=?,
        ~onBackdropClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onEscapeKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onRendered: option(unit => unit)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~anchor=?Js.Option.map([@bs] ((v) => anchorToJs(v)), anchor),
          ~className?,
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~modalProps?,
          ~onClose?,
          ~_open=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _open),
          ~paperProps?,
          ~slideProps?,
          ~theme,
          ~transitionDuration=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              transitionDuration
            ),
          ~variant=?Js.Option.map([@bs] ((v) => variantToJs(v)), variant),
          ~backdropComponent=?Js.Option.map([@bs] ((v) => unwrapValue(v)), backdropComponent),
          ~backdropProps?,
          ~container=?Js.Option.map([@bs] ((v) => unwrapValue(v)), container),
          ~disableAutoFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableAutoFocus),
          ~disableBackdropClick=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableBackdropClick),
          ~disableEnforceFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableEnforceFocus),
          ~disableEscapeKeyDown=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableEscapeKeyDown),
          ~disableRestoreFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRestoreFocus),
          ~hideBackdrop=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), hideBackdrop),
          ~keepMounted=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), keepMounted),
          ~manager?,
          ~onBackdropClick?,
          ~onEscapeKeyDown?,
          ~onRendered?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ExpansionPanelActions = {
  module Classes = {
    type classesType =
      | Root(string)
      | Action(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Action(_) => "action";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Action(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ExpansionPanel/ExpansionPanelActions"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~className: string=?, ~classes: Js.Dict.t(string)=?, unit) => _ = "";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ExpansionPanelDetails = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ExpansionPanel/ExpansionPanelDetails"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~className: string=?, ~classes: Js.Dict.t(string)=?, unit) => _ = "";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ExpansionPanelSummary = {
  module Classes = {
    type classesType =
      | Root(string)
      | Expanded(string)
      | Focused(string)
      | Disabled(string)
      | Content(string)
      | ContentExpanded(string)
      | ExpandIcon(string)
      | ExpandIconExpanded(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Expanded(_) => "expanded"
      | Focused(_) => "focused"
      | Disabled(_) => "disabled"
      | Content(_) => "content"
      | ContentExpanded(_) => "contentExpanded"
      | ExpandIcon(_) => "expandIcon"
      | ExpandIconExpanded(_) => "expandIconExpanded";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Expanded(className)
               | Focused(className)
               | Disabled(className)
               | Content(className)
               | ContentExpanded(className)
               | ExpandIcon(className)
               | ExpandIconExpanded(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ExpansionPanel/ExpansionPanelSummary"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disabled: Js.boolean=?,
      ~expanded: Js.boolean=?,
      ~expandIcon: ReasonReact.reactElement=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~component: 'union_y=?,
      ~disableRipple: Js.boolean=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~expanded: option(bool)=?,
        ~expandIcon: option(ReasonReact.reactElement)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~expanded=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), expanded),
          ~expandIcon?,
          ~onChange?,
          ~onClick?,
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ExpansionPanel = {
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
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Expanded(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ExpansionPanel/ExpansionPanel"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~collapseProps: Js.t({..})=?,
      ~defaultExpanded: Js.boolean=?,
      ~disabled: Js.boolean=?,
      ~expanded: Js.boolean=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~component: 'union_7=?,
      ~elevation: 'number_e=?,
      ~square: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~collapseProps: option(Js.t({..}))=?,
        ~defaultExpanded: option(bool)=?,
        ~disabled: option(bool)=?,
        ~expanded: option(bool)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~collapseProps?,
          ~defaultExpanded=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), defaultExpanded),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~expanded=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), expanded),
          ~onChange?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~square=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), square),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Fade = {
  [@bs.deriving jsConverter]
  type timeoutShape = {
    enter: int,
    exit: int
  };
  [@bs.module "material-ui/transitions/Fade"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~_in: Js.boolean=?,
      ~onEnter: unit => unit=?,
      ~onEntering: unit => unit=?,
      ~onExit: unit => unit=?,
      ~style: Js.t({..})=?,
      ~theme: Js.t({..}),
      ~timeout: 'union_p=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~_in: option(bool)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~_in=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _in),
          ~onEnter?,
          ~onEntering?,
          ~onExit?,
          ~style?,
          ~theme,
          ~timeout=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              timeout
            ),
          ()
        ),
      children
    );
};

module FormControlLabel = {
  module Classes = {
    type classesType =
      | Root(string)
      | Disabled(string)
      | Label(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Disabled(_) => "disabled"
      | Label(_) => "label";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Disabled(className)
               | Label(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormControlLabel"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~checked: 'union_u=?,
      ~className: string=?,
      ~control: ReasonReact.reactElement=?,
      ~disabled: Js.boolean=?,
      ~inputRef: ReasonReact.reactElement=?,
      ~label: ReasonReact.reactElement=?,
      ~name: string=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~value: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~className: option(string)=?,
        ~control: option(ReasonReact.reactElement)=?,
        ~disabled: option(bool)=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~name: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~value: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~checked=?Js.Option.map([@bs] ((v) => unwrapValue(v)), checked),
          ~className?,
          ~control?,
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~inputRef?,
          ~label?,
          ~name?,
          ~onChange?,
          ~value?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module FormControl = {
  [@bs.deriving jsConverter]
  type margin = [ [@bs.as "none"] | `None [@bs.as "dense"] | `Dense [@bs.as "normal"] | `Normal];
  module Classes = {
    type classesType =
      | Root(string)
      | MarginNormal(string)
      | MarginDense(string)
      | FullWidth(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | MarginNormal(_) => "marginNormal"
      | MarginDense(_) => "marginDense"
      | FullWidth(_) => "fullWidth";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | MarginNormal(className)
               | MarginDense(className)
               | FullWidth(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormControl"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_d=?,
      ~disabled: Js.boolean=?,
      ~error: Js.boolean=?,
      ~fullWidth: Js.boolean=?,
      ~margin: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~required: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~margin: option(margin)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~required: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~error=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), error),
          ~fullWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullWidth),
          ~margin=?Js.Option.map([@bs] ((v) => marginToJs(v)), margin),
          ~onBlur?,
          ~onFocus?,
          ~required=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), required),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module FormGroup = {
  module Classes = {
    type classesType =
      | Root(string)
      | Row(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Row(_) => "row";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Row(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormGroup"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (~className: string=?, ~row: Js.boolean=?, ~classes: Js.Dict.t(string)=?, unit) => _ =
    "";
  let make =
      (~className: option(string)=?, ~row: option(bool)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~row=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), row),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module FormHelperText = {
  [@bs.deriving jsConverter]
  type margin = [ [@bs.as "dense"] | `Dense];
  module Classes = {
    type classesType =
      | Root(string)
      | Error(string)
      | Disabled(string)
      | MarginDense(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Error(_) => "error"
      | Disabled(_) => "disabled"
      | MarginDense(_) => "marginDense";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Error(className)
               | Disabled(className)
               | MarginDense(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormHelperText"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_m=?,
      ~disabled: Js.boolean=?,
      ~error: Js.boolean=?,
      ~margin: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~margin: option(margin)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~error=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), error),
          ~margin=?Js.Option.map([@bs] ((v) => marginToJs(v)), margin),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module FormLabel = {
  module Classes = {
    type classesType =
      | Root(string)
      | Focused(string)
      | Disabled(string)
      | Error(string)
      | Asterisk(string)
      | AsteriskError(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Focused(_) => "focused"
      | Disabled(_) => "disabled"
      | Error(_) => "error"
      | Asterisk(_) => "asterisk"
      | AsteriskError(_) => "asteriskError";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Focused(className)
               | Disabled(className)
               | Error(className)
               | Asterisk(className)
               | AsteriskError(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormLabel"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_n=?,
      ~disabled: Js.boolean=?,
      ~error: Js.boolean=?,
      ~focused: Js.boolean=?,
      ~required: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~focused: option(bool)=?,
        ~required: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~error=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), error),
          ~focused=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focused),
          ~required=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), required),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module GridListTileBar = {
  [@bs.deriving jsConverter]
  type actionPosition = [ [@bs.as "left"] | `Left [@bs.as "right"] | `Right];
  [@bs.deriving jsConverter]
  type titlePosition = [ [@bs.as "top"] | `Top [@bs.as "bottom"] | `Bottom];
  module Classes = {
    type classesType =
      | Root(string)
      | TitlePositionBottom(string)
      | TitlePositionTop(string)
      | RootSubtitle(string)
      | TitleWrap(string)
      | TitleWrapActionPosLeft(string)
      | TitleWrapActionPosRight(string)
      | Title(string)
      | Subtitle(string)
      | ActionIcon(string)
      | ActionIconActionPosLeft(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | TitlePositionBottom(_) => "titlePositionBottom"
      | TitlePositionTop(_) => "titlePositionTop"
      | RootSubtitle(_) => "rootSubtitle"
      | TitleWrap(_) => "titleWrap"
      | TitleWrapActionPosLeft(_) => "titleWrapActionPosLeft"
      | TitleWrapActionPosRight(_) => "titleWrapActionPosRight"
      | Title(_) => "title"
      | Subtitle(_) => "subtitle"
      | ActionIcon(_) => "actionIcon"
      | ActionIconActionPosLeft(_) => "actionIconActionPosLeft";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | TitlePositionBottom(className)
               | TitlePositionTop(className)
               | RootSubtitle(className)
               | TitleWrap(className)
               | TitleWrapActionPosLeft(className)
               | TitleWrapActionPosRight(className)
               | Title(className)
               | Subtitle(className)
               | ActionIcon(className)
               | ActionIconActionPosLeft(className) =>
                 Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridListTileBar"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~actionIcon: ReasonReact.reactElement=?,
      ~actionPosition: string=?,
      ~className: string=?,
      ~subtitle: ReasonReact.reactElement=?,
      ~title: ReasonReact.reactElement=?,
      ~titlePosition: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~actionIcon: option(ReasonReact.reactElement)=?,
        ~actionPosition: option(actionPosition)=?,
        ~className: option(string)=?,
        ~subtitle: option(ReasonReact.reactElement)=?,
        ~title: option(ReasonReact.reactElement)=?,
        ~titlePosition: option(titlePosition)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~actionIcon?,
          ~actionPosition=?Js.Option.map([@bs] ((v) => actionPositionToJs(v)), actionPosition),
          ~className?,
          ~subtitle?,
          ~title?,
          ~titlePosition=?Js.Option.map([@bs] ((v) => titlePositionToJs(v)), titlePosition),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module GridListTile = {
  module Classes = {
    type classesType =
      | Root(string)
      | Tile(string)
      | ImgFullHeight(string)
      | ImgFullWidth(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Tile(_) => "tile"
      | ImgFullHeight(_) => "imgFullHeight"
      | ImgFullWidth(_) => "imgFullWidth";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Tile(className)
               | ImgFullHeight(className)
               | ImgFullWidth(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridListTile"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~cols: 'number_d=?,
      ~component: 'union_m=?,
      ~rows: 'number_5=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~cols: option([ | `Int(int) | `Float(float)])=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~rows: option([ | `Int(int) | `Float(float)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~cols=?Js.Option.map([@bs] ((v) => unwrapValue(v)), cols),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~rows=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rows),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module GridList = {
  [@bs.deriving jsConverter]
  type cellHeight = [ [@bs.as "auto"] | `Auto];
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridList"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~cellHeight: 'union_2=?,
      ~className: string=?,
      ~cols: 'number_c=?,
      ~component: 'union_v=?,
      ~spacing: 'number_4=?,
      ~style: Js.t({..})=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~cellHeight: option([ | `Int(int) | `Float(float) | `Enum(cellHeight)])=?,
        ~className: option(string)=?,
        ~cols: option([ | `Int(int) | `Float(float)])=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~spacing: option([ | `Int(int) | `Float(float)])=?,
        ~style: option(Js.t({..}))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~cellHeight=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(cellHeightToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              cellHeight
            ),
          ~className?,
          ~cols=?Js.Option.map([@bs] ((v) => unwrapValue(v)), cols),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~spacing=?Js.Option.map([@bs] ((v) => unwrapValue(v)), spacing),
          ~style?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Grid = {
  [@bs.deriving jsConverter]
  type alignContent = [
    [@bs.as "stretch"] | `Stretch
    [@bs.as "center"] | `Center
    [@bs.as "flex-start"] | `Flex_Start
    [@bs.as "flex-end"] | `Flex_End
    [@bs.as "space-between"] | `Space_Between
    [@bs.as "space-around"] | `Space_Around
  ];
  [@bs.deriving jsConverter]
  type alignItems = [
    [@bs.as "flex-start"] | `Flex_Start
    [@bs.as "center"] | `Center
    [@bs.as "flex-end"] | `Flex_End
    [@bs.as "stretch"] | `Stretch
    [@bs.as "baseline"] | `Baseline
  ];
  [@bs.deriving jsConverter]
  type direction = [
    [@bs.as "row"] | `Row
    [@bs.as "row-reverse"] | `Row_Reverse
    [@bs.as "column"] | `Column
    [@bs.as "column-reverse"] | `Column_Reverse
  ];
  [@bs.deriving jsConverter]
  type justify = [
    [@bs.as "flex-start"] | `Flex_Start
    [@bs.as "center"] | `Center
    [@bs.as "flex-end"] | `Flex_End
    [@bs.as "space-between"] | `Space_Between
    [@bs.as "space-around"] | `Space_Around
  ];
  [@bs.deriving jsConverter]
  type lg =
    [@bs.as 1] | True
    [@bs.as 1] | V1
    [@bs.as 2] | V2
    [@bs.as 3] | V3
    [@bs.as 4] | V4
    [@bs.as 5] | V5
    [@bs.as 6] | V6
    [@bs.as 7] | V7
    [@bs.as 8] | V8
    [@bs.as 9] | V9
    [@bs.as 10] | V10
    [@bs.as 11] | V11
    [@bs.as 12] | V12;
  [@bs.deriving jsConverter]
  type md =
    [@bs.as 1] | True
    [@bs.as 1] | V1
    [@bs.as 2] | V2
    [@bs.as 3] | V3
    [@bs.as 4] | V4
    [@bs.as 5] | V5
    [@bs.as 6] | V6
    [@bs.as 7] | V7
    [@bs.as 8] | V8
    [@bs.as 9] | V9
    [@bs.as 10] | V10
    [@bs.as 11] | V11
    [@bs.as 12] | V12;
  [@bs.deriving jsConverter]
  type sm =
    [@bs.as 1] | True
    [@bs.as 1] | V1
    [@bs.as 2] | V2
    [@bs.as 3] | V3
    [@bs.as 4] | V4
    [@bs.as 5] | V5
    [@bs.as 6] | V6
    [@bs.as 7] | V7
    [@bs.as 8] | V8
    [@bs.as 9] | V9
    [@bs.as 10] | V10
    [@bs.as 11] | V11
    [@bs.as 12] | V12;
  [@bs.deriving jsConverter]
  type spacing =
    [@bs.as 0] | V0
    [@bs.as 8] | V8
    [@bs.as 16] | V16
    [@bs.as 24] | V24
    [@bs.as 40] | V40;
  [@bs.deriving jsConverter]
  type wrap = [
    [@bs.as "nowrap"] | `Nowrap
    [@bs.as "wrap"] | `Wrap
    [@bs.as "wrap-reverse"] | `Wrap_Reverse
  ];
  [@bs.deriving jsConverter]
  type xl =
    [@bs.as 1] | True
    [@bs.as 1] | V1
    [@bs.as 2] | V2
    [@bs.as 3] | V3
    [@bs.as 4] | V4
    [@bs.as 5] | V5
    [@bs.as 6] | V6
    [@bs.as 7] | V7
    [@bs.as 8] | V8
    [@bs.as 9] | V9
    [@bs.as 10] | V10
    [@bs.as 11] | V11
    [@bs.as 12] | V12;
  [@bs.deriving jsConverter]
  type xs =
    [@bs.as 1] | True
    [@bs.as 1] | V1
    [@bs.as 2] | V2
    [@bs.as 3] | V3
    [@bs.as 4] | V4
    [@bs.as 5] | V5
    [@bs.as 6] | V6
    [@bs.as 7] | V7
    [@bs.as 8] | V8
    [@bs.as 9] | V9
    [@bs.as 10] | V10
    [@bs.as 11] | V11
    [@bs.as 12] | V12;
  module Classes = {
    type classesType =
      | TypeContainer(string)
      | TypeItem(string)
      | ZeroMinWidth(string)
      | Direction_Xs_Column(string)
      | Direction_Xs_Column_Reverse(string)
      | Direction_Xs_Row_Reverse(string)
      | Wrap_Xs_Nowrap(string)
      | Wrap_Xs_Wrap_Reverse(string)
      | Align_Items_Xs_Center(string)
      | Align_Items_Xs_Flex_Start(string)
      | Align_Items_Xs_Flex_End(string)
      | Align_Items_Xs_Baseline(string)
      | Align_Content_Xs_Center(string)
      | Align_Content_Xs_Flex_Start(string)
      | Align_Content_Xs_Flex_End(string)
      | Align_Content_Xs_Space_Between(string)
      | Align_Content_Xs_Space_Around(string)
      | Justify_Xs_Center(string)
      | Justify_Xs_Flex_End(string)
      | Justify_Xs_Space_Between(string)
      | Justify_Xs_Space_Around(string)
      | Spacing_Xs_8(string)
      | Spacing_Xs_16(string)
      | Spacing_Xs_24(string)
      | Spacing_Xs_40(string)
      | Grid_Xs(string)
      | Grid_Xs_1(string)
      | Grid_Xs_2(string)
      | Grid_Xs_3(string)
      | Grid_Xs_4(string)
      | Grid_Xs_5(string)
      | Grid_Xs_6(string)
      | Grid_Xs_7(string)
      | Grid_Xs_8(string)
      | Grid_Xs_9(string)
      | Grid_Xs_10(string)
      | Grid_Xs_11(string)
      | Grid_Xs_12(string);
    type t = list(classesType);
    let to_string =
      fun
      | TypeContainer(_) => "typeContainer"
      | TypeItem(_) => "typeItem"
      | ZeroMinWidth(_) => "zeroMinWidth"
      | Direction_Xs_Column(_) => "direction-xs-column"
      | Direction_Xs_Column_Reverse(_) => "direction-xs-column-reverse"
      | Direction_Xs_Row_Reverse(_) => "direction-xs-row-reverse"
      | Wrap_Xs_Nowrap(_) => "wrap-xs-nowrap"
      | Wrap_Xs_Wrap_Reverse(_) => "wrap-xs-wrap-reverse"
      | Align_Items_Xs_Center(_) => "align-items-xs-center"
      | Align_Items_Xs_Flex_Start(_) => "align-items-xs-flex-start"
      | Align_Items_Xs_Flex_End(_) => "align-items-xs-flex-end"
      | Align_Items_Xs_Baseline(_) => "align-items-xs-baseline"
      | Align_Content_Xs_Center(_) => "align-content-xs-center"
      | Align_Content_Xs_Flex_Start(_) => "align-content-xs-flex-start"
      | Align_Content_Xs_Flex_End(_) => "align-content-xs-flex-end"
      | Align_Content_Xs_Space_Between(_) => "align-content-xs-space-between"
      | Align_Content_Xs_Space_Around(_) => "align-content-xs-space-around"
      | Justify_Xs_Center(_) => "justify-xs-center"
      | Justify_Xs_Flex_End(_) => "justify-xs-flex-end"
      | Justify_Xs_Space_Between(_) => "justify-xs-space-between"
      | Justify_Xs_Space_Around(_) => "justify-xs-space-around"
      | Spacing_Xs_8(_) => "spacing-xs-8"
      | Spacing_Xs_16(_) => "spacing-xs-16"
      | Spacing_Xs_24(_) => "spacing-xs-24"
      | Spacing_Xs_40(_) => "spacing-xs-40"
      | Grid_Xs(_) => "grid-xs"
      | Grid_Xs_1(_) => "grid-xs-1"
      | Grid_Xs_2(_) => "grid-xs-2"
      | Grid_Xs_3(_) => "grid-xs-3"
      | Grid_Xs_4(_) => "grid-xs-4"
      | Grid_Xs_5(_) => "grid-xs-5"
      | Grid_Xs_6(_) => "grid-xs-6"
      | Grid_Xs_7(_) => "grid-xs-7"
      | Grid_Xs_8(_) => "grid-xs-8"
      | Grid_Xs_9(_) => "grid-xs-9"
      | Grid_Xs_10(_) => "grid-xs-10"
      | Grid_Xs_11(_) => "grid-xs-11"
      | Grid_Xs_12(_) => "grid-xs-12";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | TypeContainer(className)
               | TypeItem(className)
               | ZeroMinWidth(className)
               | Direction_Xs_Column(className)
               | Direction_Xs_Column_Reverse(className)
               | Direction_Xs_Row_Reverse(className)
               | Wrap_Xs_Nowrap(className)
               | Wrap_Xs_Wrap_Reverse(className)
               | Align_Items_Xs_Center(className)
               | Align_Items_Xs_Flex_Start(className)
               | Align_Items_Xs_Flex_End(className)
               | Align_Items_Xs_Baseline(className)
               | Align_Content_Xs_Center(className)
               | Align_Content_Xs_Flex_Start(className)
               | Align_Content_Xs_Flex_End(className)
               | Align_Content_Xs_Space_Between(className)
               | Align_Content_Xs_Space_Around(className)
               | Justify_Xs_Center(className)
               | Justify_Xs_Flex_End(className)
               | Justify_Xs_Space_Between(className)
               | Justify_Xs_Space_Around(className)
               | Spacing_Xs_8(className)
               | Spacing_Xs_16(className)
               | Spacing_Xs_24(className)
               | Spacing_Xs_40(className)
               | Grid_Xs(className)
               | Grid_Xs_1(className)
               | Grid_Xs_2(className)
               | Grid_Xs_3(className)
               | Grid_Xs_4(className)
               | Grid_Xs_5(className)
               | Grid_Xs_6(className)
               | Grid_Xs_7(className)
               | Grid_Xs_8(className)
               | Grid_Xs_9(className)
               | Grid_Xs_10(className)
               | Grid_Xs_11(className)
               | Grid_Xs_12(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Grid/Grid"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~alignContent: string=?,
      ~alignItems: string=?,
      ~className: string=?,
      ~component: 'union_h=?,
      ~container: Js.boolean=?,
      ~direction: string=?,
      ~hidden: Js.t({..})=?,
      ~item: Js.boolean=?,
      ~justify: string=?,
      ~lg: int=?,
      ~md: int=?,
      ~sm: int=?,
      ~spacing: int=?,
      ~wrap: string=?,
      ~xl: int=?,
      ~xs: int=?,
      ~zeroMinWidth: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~alignContent: option(alignContent)=?,
        ~alignItems: option(alignItems)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~container: option(bool)=?,
        ~direction: option(direction)=?,
        ~hidden: option(Js.t({..}))=?,
        ~item: option(bool)=?,
        ~justify: option(justify)=?,
        ~lg: option(lg)=?,
        ~md: option(md)=?,
        ~sm: option(sm)=?,
        ~spacing: option(spacing)=?,
        ~wrap: option(wrap)=?,
        ~xl: option(xl)=?,
        ~xs: option(xs)=?,
        ~zeroMinWidth: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~alignContent=?Js.Option.map([@bs] ((v) => alignContentToJs(v)), alignContent),
          ~alignItems=?Js.Option.map([@bs] ((v) => alignItemsToJs(v)), alignItems),
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~container=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), container),
          ~direction=?Js.Option.map([@bs] ((v) => directionToJs(v)), direction),
          ~hidden?,
          ~item=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), item),
          ~justify=?Js.Option.map([@bs] ((v) => justifyToJs(v)), justify),
          ~lg=?Js.Option.map([@bs] ((v) => lgToJs(v)), lg),
          ~md=?Js.Option.map([@bs] ((v) => mdToJs(v)), md),
          ~sm=?Js.Option.map([@bs] ((v) => smToJs(v)), sm),
          ~spacing=?Js.Option.map([@bs] ((v) => spacingToJs(v)), spacing),
          ~wrap=?Js.Option.map([@bs] ((v) => wrapToJs(v)), wrap),
          ~xl=?Js.Option.map([@bs] ((v) => xlToJs(v)), xl),
          ~xs=?Js.Option.map([@bs] ((v) => xsToJs(v)), xs),
          ~zeroMinWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), zeroMinWidth),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Grow = {
  [@bs.deriving jsConverter]
  type timeoutShape = {
    enter: int,
    exit: int
  };
  [@bs.deriving jsConverter]
  type timeout = [ [@bs.as "auto"] | `Auto];
  [@bs.module "material-ui/transitions/Grow"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~_in: Js.boolean=?,
      ~onEnter: unit => unit=?,
      ~onEntered: unit => unit=?,
      ~onEntering: unit => unit=?,
      ~onExit: unit => unit=?,
      ~style: Js.t({..})=?,
      ~theme: Js.t({..}),
      ~timeout: 'union_a=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~_in: option(bool)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntered: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape) | `Enum(timeout)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~_in=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _in),
          ~onEnter?,
          ~onEntered?,
          ~onEntering?,
          ~onExit?,
          ~style?,
          ~theme,
          ~timeout=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(timeoutToJs(v)))
                  | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              timeout
            ),
          ()
        ),
      children
    );
};

module Hidden = {
  [@bs.deriving jsConverter]
  type implementation = [ [@bs.as "js"] | `Js [@bs.as "css"] | `Css];
  [@bs.deriving jsConverter]
  type initialWidth = [
    [@bs.as "xs"] | `Xs
    [@bs.as "sm"] | `Sm
    [@bs.as "md"] | `Md
    [@bs.as "lg"] | `Lg
    [@bs.as "xl"] | `Xl
  ];
  [@bs.deriving jsConverter]
  type only = [
    [@bs.as "xs"] | `Xs
    [@bs.as "sm"] | `Sm
    [@bs.as "md"] | `Md
    [@bs.as "lg"] | `Lg
    [@bs.as "xl"] | `Xl
  ];
  [@bs.module "material-ui/Hidden/Hidden"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~implementation: string=?,
      ~initialWidth: string=?,
      ~lgDown: Js.boolean=?,
      ~lgUp: Js.boolean=?,
      ~mdDown: Js.boolean=?,
      ~mdUp: Js.boolean=?,
      ~only: 'union_z=?,
      ~smDown: Js.boolean=?,
      ~smUp: Js.boolean=?,
      ~xlDown: Js.boolean=?,
      ~xlUp: Js.boolean=?,
      ~xsDown: Js.boolean=?,
      ~xsUp: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~implementation: option(implementation)=?,
        ~initialWidth: option(initialWidth)=?,
        ~lgDown: option(bool)=?,
        ~lgUp: option(bool)=?,
        ~mdDown: option(bool)=?,
        ~mdUp: option(bool)=?,
        ~only: option([ | `Enum(only) | `EnumArray(array(only))])=?,
        ~smDown: option(bool)=?,
        ~smUp: option(bool)=?,
        ~xlDown: option(bool)=?,
        ~xlUp: option(bool)=?,
        ~xsDown: option(bool)=?,
        ~xsUp: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~implementation=?Js.Option.map([@bs] ((v) => implementationToJs(v)), implementation),
          ~initialWidth=?Js.Option.map([@bs] ((v) => initialWidthToJs(v)), initialWidth),
          ~lgDown=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), lgDown),
          ~lgUp=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), lgUp),
          ~mdDown=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), mdDown),
          ~mdUp=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), mdUp),
          ~only=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(onlyToJs(v)))
                  | `EnumArray(v) => unwrapValue(`Element(Array.map(onlyToJs, v)))
                  }
              ),
              only
            ),
          ~smDown=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), smDown),
          ~smUp=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), smUp),
          ~xlDown=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), xlDown),
          ~xlUp=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), xlUp),
          ~xsDown=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), xsDown),
          ~xsUp=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), xsUp),
          ()
        ),
      children
    );
};

module IconButton = {
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "default"] | `Default
    [@bs.as "inherit"] | `Inherit
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | ColorInherit(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | Disabled(string)
      | Label(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorInherit(_) => "colorInherit"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | Disabled(_) => "disabled"
      | Label(_) => "label";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorInherit(className)
               | ColorPrimary(className)
               | ColorSecondary(className)
               | Disabled(className)
               | Label(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/IconButton/IconButton"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~color: string=?,
      ~disabled: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~component: 'union_y=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onClick?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Icon = {
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "inherit"] | `Inherit
    [@bs.as "secondary"] | `Secondary
    [@bs.as "action"] | `Action
    [@bs.as "disabled"] | `Disabled
    [@bs.as "error"] | `Error
    [@bs.as "primary"] | `Primary
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | ColorAction(string)
      | ColorDisabled(string)
      | ColorError(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | ColorAction(_) => "colorAction"
      | ColorDisabled(_) => "colorDisabled"
      | ColorError(_) => "colorError";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorPrimary(className)
               | ColorSecondary(className)
               | ColorAction(className)
               | ColorDisabled(className)
               | ColorError(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Icon/Icon"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (~className: string=?, ~color: string=?, ~classes: Js.Dict.t(string)=?, unit) => _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module InputAdornment = {
  [@bs.deriving jsConverter]
  type position = [ [@bs.as "start"] | `Start [@bs.as "end"] | `End];
  module Classes = {
    type classesType =
      | Root(string)
      | PositionStart(string)
      | PositionEnd(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PositionStart(_) => "positionStart"
      | PositionEnd(_) => "positionEnd";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PositionStart(className)
               | PositionEnd(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/InputAdornment"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_3=?,
      ~disableTypography: Js.boolean=?,
      ~position: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disableTypography: option(bool)=?,
        ~position: option(position)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disableTypography=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableTypography),
          ~position=?Js.Option.map([@bs] ((v) => positionToJs(v)), position),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module InputLabel = {
  [@bs.deriving jsConverter]
  type margin = [ [@bs.as "dense"] | `Dense];
  module Classes = {
    type classesType =
      | Root(string)
      | FormControl(string)
      | MarginDense(string)
      | Shrink(string)
      | Animated(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FormControl(_) => "formControl"
      | MarginDense(_) => "marginDense"
      | Shrink(_) => "shrink"
      | Animated(_) => "animated"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | FormControl(className)
               | MarginDense(className)
               | Shrink(className)
               | Animated(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/InputLabel"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disableAnimation: Js.boolean=?,
      ~disabled: Js.boolean=?,
      ~error: Js.boolean=?,
      ~focused: Js.boolean=?,
      ~formControlClasses: Js.t({..})=?,
      ~margin: string=?,
      ~required: Js.boolean=?,
      ~shrink: Js.boolean=?,
      ~component: 'union_n=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disableAnimation: option(bool)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~focused: option(bool)=?,
        ~formControlClasses: option(Js.t({..}))=?,
        ~margin: option(margin)=?,
        ~required: option(bool)=?,
        ~shrink: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disableAnimation=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableAnimation),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~error=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), error),
          ~focused=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focused),
          ~formControlClasses?,
          ~margin=?Js.Option.map([@bs] ((v) => marginToJs(v)), margin),
          ~required=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), required),
          ~shrink=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), shrink),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Input = {
  [@bs.deriving jsConverter]
  type margin = [ [@bs.as "dense"] | `Dense [@bs.as "none"] | `None];
  module Classes = {
    type classesType =
      | Root(string)
      | FormControl(string)
      | Focused(string)
      | Disabled(string)
      | Underline(string)
      | Error(string)
      | Multiline(string)
      | FullWidth(string)
      | Input(string)
      | InputMarginDense(string)
      | InputDisabled(string)
      | InputMultiline(string)
      | InputType(string)
      | InputTypeSearch(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FormControl(_) => "formControl"
      | Focused(_) => "focused"
      | Disabled(_) => "disabled"
      | Underline(_) => "underline"
      | Error(_) => "error"
      | Multiline(_) => "multiline"
      | FullWidth(_) => "fullWidth"
      | Input(_) => "input"
      | InputMarginDense(_) => "inputMarginDense"
      | InputDisabled(_) => "inputDisabled"
      | InputMultiline(_) => "inputMultiline"
      | InputType(_) => "inputType"
      | InputTypeSearch(_) => "inputTypeSearch";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | FormControl(className)
               | Focused(className)
               | Disabled(className)
               | Underline(className)
               | Error(className)
               | Multiline(className)
               | FullWidth(className)
               | Input(className)
               | InputMarginDense(className)
               | InputDisabled(className)
               | InputMultiline(className)
               | InputType(className)
               | InputTypeSearch(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/Input"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~autoComplete: string=?,
      ~autoFocus: Js.boolean=?,
      ~className: string=?,
      ~defaultValue: 'union_8=?,
      ~disabled: Js.boolean=?,
      ~disableUnderline: Js.boolean=?,
      ~endAdornment: ReasonReact.reactElement=?,
      ~error: Js.boolean=?,
      ~fullWidth: Js.boolean=?,
      ~id: string=?,
      ~inputComponent: 'union_0=?,
      ~inputProps: Js.t({..})=?,
      ~inputRef: ReasonReact.reactElement=?,
      ~margin: string=?,
      ~multiline: Js.boolean=?,
      ~name: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~onClean: unit => unit=?,
      ~onDirty: unit => unit=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~placeholder: string=?,
      ~readOnly: Js.boolean=?,
      ~rows: 'union_9=?,
      ~rowsMax: 'union_5=?,
      ~startAdornment: ReasonReact.reactElement=?,
      ~_type: string=?,
      ~value: 'union_k=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~autoComplete: option(string)=?,
        ~autoFocus: option(bool)=?,
        ~className: option(string)=?,
        ~defaultValue: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~disabled: option(bool)=?,
        ~disableUnderline: option(bool)=?,
        ~endAdornment: option(ReasonReact.reactElement)=?,
        ~error: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~id: option(string)=?,
        ~inputComponent: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~margin: option(margin)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClean: option(unit => unit)=?,
        ~onDirty: option(unit => unit)=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~placeholder: option(string)=?,
        ~readOnly: option(bool)=?,
        ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~startAdornment: option(ReasonReact.reactElement)=?,
        ~_type: option(string)=?,
        ~value:
           option(
             [
               | `String(string)
               | `Int(int)
               | `Float(float)
               | `StringArray(array(string))
               | `IntArray(array(int))
               | `FloatArray(array(float))
             ]
           )=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~autoComplete?,
          ~autoFocus=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), autoFocus),
          ~className?,
          ~defaultValue=?Js.Option.map([@bs] ((v) => unwrapValue(v)), defaultValue),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableUnderline=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableUnderline),
          ~endAdornment?,
          ~error=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), error),
          ~fullWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullWidth),
          ~id?,
          ~inputComponent=?Js.Option.map([@bs] ((v) => unwrapValue(v)), inputComponent),
          ~inputProps?,
          ~inputRef?,
          ~margin=?Js.Option.map([@bs] ((v) => marginToJs(v)), margin),
          ~multiline=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), multiline),
          ~name?,
          ~onBlur?,
          ~onChange?,
          ~onClean?,
          ~onDirty?,
          ~onFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~placeholder?,
          ~readOnly=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), readOnly),
          ~rows=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rows),
          ~rowsMax=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowsMax),
          ~startAdornment?,
          ~_type?,
          ~value=?Js.Option.map([@bs] ((v) => unwrapValue(v)), value),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module LinearProgress = {
  [@bs.deriving jsConverter]
  type color = [ [@bs.as "primary"] | `Primary [@bs.as "secondary"] | `Secondary];
  [@bs.deriving jsConverter]
  type variant = [
    [@bs.as "determinate"] | `Determinate
    [@bs.as "indeterminate"] | `Indeterminate
    [@bs.as "buffer"] | `Buffer
    [@bs.as "query"] | `Query
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | Buffer(string)
      | Query(string)
      | Dashed(string)
      | DashedColorPrimary(string)
      | DashedColorSecondary(string)
      | Bar(string)
      | BarColorPrimary(string)
      | BarColorSecondary(string)
      | Bar1Indeterminate(string)
      | Bar2Indeterminate(string)
      | Bar1Determinate(string)
      | Bar1Buffer(string)
      | Bar2Buffer(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | Buffer(_) => "buffer"
      | Query(_) => "query"
      | Dashed(_) => "dashed"
      | DashedColorPrimary(_) => "dashedColorPrimary"
      | DashedColorSecondary(_) => "dashedColorSecondary"
      | Bar(_) => "bar"
      | BarColorPrimary(_) => "barColorPrimary"
      | BarColorSecondary(_) => "barColorSecondary"
      | Bar1Indeterminate(_) => "bar1Indeterminate"
      | Bar2Indeterminate(_) => "bar2Indeterminate"
      | Bar1Determinate(_) => "bar1Determinate"
      | Bar1Buffer(_) => "bar1Buffer"
      | Bar2Buffer(_) => "bar2Buffer";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorPrimary(className)
               | ColorSecondary(className)
               | Buffer(className)
               | Query(className)
               | Dashed(className)
               | DashedColorPrimary(className)
               | DashedColorSecondary(className)
               | Bar(className)
               | BarColorPrimary(className)
               | BarColorSecondary(className)
               | Bar1Indeterminate(className)
               | Bar2Indeterminate(className)
               | Bar1Determinate(className)
               | Bar1Buffer(className)
               | Bar2Buffer(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Progress/LinearProgress"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~color: string=?,
      ~value: 'number_8=?,
      ~valueBuffer: 'number_b=?,
      ~variant: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~value: option([ | `Int(int) | `Float(float)])=?,
        ~valueBuffer: option([ | `Int(int) | `Float(float)])=?,
        ~variant: option(variant)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~value=?Js.Option.map([@bs] ((v) => unwrapValue(v)), value),
          ~valueBuffer=?Js.Option.map([@bs] ((v) => unwrapValue(v)), valueBuffer),
          ~variant=?Js.Option.map([@bs] ((v) => variantToJs(v)), variant),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ListItemAvatar = {
  module Classes = {
    type classesType =
      | Root(string)
      | Icon(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Icon(_) => "icon";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Icon(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemAvatar"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~className: string=?, ~classes: Js.Dict.t(string)=?, unit) => _ = "";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ListItemIcon = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemIcon"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~className: string=?, ~classes: Js.Dict.t(string)=?, unit) => _ = "";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ListItemSecondaryAction = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemSecondaryAction"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~className: string=?, ~classes: Js.Dict.t(string)=?, unit) => _ = "";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ListItemText = {
  module Classes = {
    type classesType =
      | Root(string)
      | Inset(string)
      | Dense(string)
      | Primary(string)
      | Secondary(string)
      | TextDense(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Inset(_) => "inset"
      | Dense(_) => "dense"
      | Primary(_) => "primary"
      | Secondary(_) => "secondary"
      | TextDense(_) => "textDense";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Inset(className)
               | Dense(className)
               | Primary(className)
               | Secondary(className)
               | TextDense(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemText"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disableTypography: Js.boolean=?,
      ~inset: Js.boolean=?,
      ~primary: ReasonReact.reactElement=?,
      ~secondary: ReasonReact.reactElement=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disableTypography: option(bool)=?,
        ~inset: option(bool)=?,
        ~primary: option(ReasonReact.reactElement)=?,
        ~secondary: option(ReasonReact.reactElement)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disableTypography=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableTypography),
          ~inset=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), inset),
          ~primary?,
          ~secondary?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ListItem = {
  module Classes = {
    type classesType =
      | Root(string)
      | Container(string)
      | KeyboardFocused(string)
      | Default(string)
      | Dense(string)
      | Disabled(string)
      | Divider(string)
      | Gutters(string)
      | Button(string)
      | SecondaryAction(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Container(_) => "container"
      | KeyboardFocused(_) => "keyboardFocused"
      | Default(_) => "default"
      | Dense(_) => "dense"
      | Disabled(_) => "disabled"
      | Divider(_) => "divider"
      | Gutters(_) => "gutters"
      | Button(_) => "button"
      | SecondaryAction(_) => "secondaryAction";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Container(className)
               | KeyboardFocused(className)
               | Default(className)
               | Dense(className)
               | Disabled(className)
               | Divider(className)
               | Gutters(className)
               | Button(className)
               | SecondaryAction(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItem"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~button: Js.boolean=?,
      ~className: string=?,
      ~component: 'union_t=?,
      ~containerComponent: 'union_d=?,
      ~containerProps: Js.t({..})=?,
      ~dense: Js.boolean=?,
      ~disabled: Js.boolean=?,
      ~disableGutters: Js.boolean=?,
      ~divider: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~button: option(bool)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~containerComponent: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~containerProps: option(Js.t({..}))=?,
        ~dense: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disableGutters: option(bool)=?,
        ~divider: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~button=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), button),
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~containerComponent=?Js.Option.map([@bs] ((v) => unwrapValue(v)), containerComponent),
          ~containerProps?,
          ~dense=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), dense),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableGutters=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableGutters),
          ~divider=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), divider),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module ListSubheader = {
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "default"] | `Default
    [@bs.as "primary"] | `Primary
    [@bs.as "inherit"] | `Inherit
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | ColorPrimary(string)
      | ColorInherit(string)
      | Inset(string)
      | Sticky(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorInherit(_) => "colorInherit"
      | Inset(_) => "inset"
      | Sticky(_) => "sticky";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorPrimary(className)
               | ColorInherit(className)
               | Inset(className)
               | Sticky(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListSubheader"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~color: string=?,
      ~component: 'union_p=?,
      ~disableSticky: Js.boolean=?,
      ~inset: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disableSticky: option(bool)=?,
        ~inset: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disableSticky=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableSticky),
          ~inset=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), inset),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module List = {
  module Classes = {
    type classesType =
      | Root(string)
      | Padding(string)
      | Dense(string)
      | Subheader(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Padding(_) => "padding"
      | Dense(_) => "dense"
      | Subheader(_) => "subheader";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Padding(className)
               | Dense(className)
               | Subheader(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/List"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_9=?,
      ~dense: Js.boolean=?,
      ~disablePadding: Js.boolean=?,
      ~subheader: ReasonReact.reactElement=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~dense: option(bool)=?,
        ~disablePadding: option(bool)=?,
        ~subheader: option(ReasonReact.reactElement)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~dense=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), dense),
          ~disablePadding=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disablePadding),
          ~subheader?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module MenuItem = {
  module Classes = {
    type classesType =
      | Root(string)
      | Selected(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Selected(_) => "selected";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Selected(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Menu/MenuItem"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_e=?,
      ~role: string=?,
      ~selected: Js.boolean=?,
      ~button: Js.boolean=?,
      ~containerComponent: 'union_d=?,
      ~containerProps: Js.t({..})=?,
      ~dense: Js.boolean=?,
      ~disabled: Js.boolean=?,
      ~disableGutters: Js.boolean=?,
      ~divider: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~role: option(string)=?,
        ~selected: option(bool)=?,
        ~button: option(bool)=?,
        ~containerComponent: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~containerProps: option(Js.t({..}))=?,
        ~dense: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disableGutters: option(bool)=?,
        ~divider: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~role?,
          ~selected=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), selected),
          ~button=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), button),
          ~containerComponent=?Js.Option.map([@bs] ((v) => unwrapValue(v)), containerComponent),
          ~containerProps?,
          ~dense=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), dense),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableGutters=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableGutters),
          ~divider=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), divider),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module MenuList = {
  [@bs.module "material-ui/Menu/MenuList"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~component: 'union_9=?,
      ~dense: Js.boolean=?,
      ~disablePadding: Js.boolean=?,
      ~subheader: ReasonReact.reactElement=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~dense: option(bool)=?,
        ~disablePadding: option(bool)=?,
        ~subheader: option(ReasonReact.reactElement)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~onBlur?,
          ~onKeyDown?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~dense=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), dense),
          ~disablePadding=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disablePadding),
          ~subheader?,
          ()
        ),
      children
    );
};

module Menu = {
  [@bs.deriving jsConverter]
  type transitionDurationShape = {
    enter: int,
    exit: int
  };
  [@bs.deriving jsConverter]
  type transitionDuration = [ [@bs.as "auto"] | `Auto];
  [@bs.deriving jsConverter]
  type anchorOriginShape = {
    horizontal: int,
    vertical: int
  };
  [@bs.deriving jsConverter]
  type anchorPositionShape = {
    top: int,
    left: int
  };
  [@bs.deriving jsConverter]
  type anchorReference = [
    [@bs.as "anchorEl"] | `AnchorEl
    [@bs.as "anchorPosition"] | `AnchorPosition
  ];
  [@bs.deriving jsConverter]
  type transformOriginShape = {
    horizontal: int,
    vertical: int
  };
  module Classes = {
    type classesType =
      | Paper(string);
    type t = list(classesType);
    let to_string =
      fun
      | Paper(_) => "paper";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Paper(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Menu/Menu"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~anchorEl: Js.t({..})=?,
      ~menuListProps: Js.t({..})=?,
      ~onClose: unit => unit=?,
      ~onEnter: unit => unit=?,
      ~onEntered: unit => unit=?,
      ~onEntering: unit => unit=?,
      ~onExit: unit => unit=?,
      ~onExited: unit => unit=?,
      ~onExiting: unit => unit=?,
      ~_open: Js.boolean,
      ~paperProps: Js.t({..})=?,
      ~popoverClasses: Js.t({..})=?,
      ~theme: Js.t({..}),
      ~transitionDuration: 'union_w=?,
      ~action: ReasonReact.reactElement=?,
      ~anchorOrigin: 'shape_a=?,
      ~anchorPosition: 'shape_l=?,
      ~anchorReference: string=?,
      ~container: 'union_b=?,
      ~elevation: 'number_7=?,
      ~getContentAnchorEl: ReasonReact.reactElement=?,
      ~marginThreshold: 'number_q=?,
      ~role: string=?,
      ~transformOrigin: 'shape_v=?,
      ~transition: 'union_u=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~anchorEl: option(Js.t({..}))=?,
        ~menuListProps: option(Js.t({..}))=?,
        ~onClose: option(unit => unit)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntered: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~onExited: option(unit => unit)=?,
        ~onExiting: option(unit => unit)=?,
        ~_open: bool,
        ~paperProps: option(Js.t({..}))=?,
        ~popoverClasses: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~transitionDuration:
           option(
             [
               | `Int(int)
               | `Float(float)
               | `Object(transitionDurationShape)
               | `Enum(transitionDuration)
             ]
           )=?,
        ~action: option(ReasonReact.reactElement)=?,
        ~anchorOrigin: option(anchorOriginShape)=?,
        ~anchorPosition: option(anchorPositionShape)=?,
        ~anchorReference: option(anchorReference)=?,
        ~container: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~getContentAnchorEl: option(ReasonReact.reactElement)=?,
        ~marginThreshold: option([ | `Int(int) | `Float(float)])=?,
        ~role: option(string)=?,
        ~transformOrigin: option(transformOriginShape)=?,
        ~transition: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~anchorEl?,
          ~menuListProps?,
          ~onClose?,
          ~onEnter?,
          ~onEntered?,
          ~onEntering?,
          ~onExit?,
          ~onExited?,
          ~onExiting?,
          ~_open=Js.Boolean.to_js_boolean(_open),
          ~paperProps?,
          ~popoverClasses?,
          ~theme,
          ~transitionDuration=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(transitionDurationToJs(v)))
                  | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              transitionDuration
            ),
          ~action?,
          ~anchorOrigin=?Js.Option.map([@bs] ((v) => anchorOriginShapeToJs(v)), anchorOrigin),
          ~anchorPosition=?
            Js.Option.map([@bs] ((v) => anchorPositionShapeToJs(v)), anchorPosition),
          ~anchorReference=?Js.Option.map([@bs] ((v) => anchorReferenceToJs(v)), anchorReference),
          ~container=?Js.Option.map([@bs] ((v) => unwrapValue(v)), container),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~getContentAnchorEl?,
          ~marginThreshold=?Js.Option.map([@bs] ((v) => unwrapValue(v)), marginThreshold),
          ~role?,
          ~transformOrigin=?
            Js.Option.map([@bs] ((v) => transformOriginShapeToJs(v)), transformOrigin),
          ~transition=?Js.Option.map([@bs] ((v) => unwrapValue(v)), transition),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module MobileStepper = {
  [@bs.deriving jsConverter]
  type position = [ [@bs.as "bottom"] | `Bottom [@bs.as "top"] | `Top [@bs.as "static"] | `Static];
  [@bs.deriving jsConverter]
  type variant = [
    [@bs.as "text"] | `Text
    [@bs.as "dots"] | `Dots
    [@bs.as "progress"] | `Progress
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | PositionBottom(string)
      | PositionTop(string)
      | PositionStatic(string)
      | Dots(string)
      | Dot(string)
      | DotActive(string)
      | Progress(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PositionBottom(_) => "positionBottom"
      | PositionTop(_) => "positionTop"
      | PositionStatic(_) => "positionStatic"
      | Dots(_) => "dots"
      | Dot(_) => "dot"
      | DotActive(_) => "dotActive"
      | Progress(_) => "progress";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PositionBottom(className)
               | PositionTop(className)
               | PositionStatic(className)
               | Dots(className)
               | Dot(className)
               | DotActive(className)
               | Progress(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/MobileStepper/MobileStepper"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~activeStep: 'number_8=?,
      ~backButton: ReasonReact.reactElement=?,
      ~className: string=?,
      ~nextButton: ReasonReact.reactElement=?,
      ~position: string=?,
      ~steps: 'number_f,
      ~variant: string=?,
      ~component: 'union_7=?,
      ~elevation: 'number_e=?,
      ~square: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~activeStep: option([ | `Int(int) | `Float(float)])=?,
        ~backButton: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~nextButton: option(ReasonReact.reactElement)=?,
        ~position: option(position)=?,
        ~steps: [ | `Int(int) | `Float(float)],
        ~variant: option(variant)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~activeStep=?Js.Option.map([@bs] ((v) => unwrapValue(v)), activeStep),
          ~backButton?,
          ~className?,
          ~nextButton?,
          ~position=?Js.Option.map([@bs] ((v) => positionToJs(v)), position),
          ~steps=unwrapValue(steps),
          ~variant=?Js.Option.map([@bs] ((v) => variantToJs(v)), variant),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~square=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), square),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Modal = {
  module Classes = {
    type classesType =
      | Root(string)
      | Hidden(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Hidden(_) => "hidden";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Hidden(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Modal/Modal"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~backdropComponent: 'union_0=?,
      ~backdropProps: Js.t({..})=?,
      ~className: string=?,
      ~container: 'union_q=?,
      ~disableAutoFocus: Js.boolean=?,
      ~disableBackdropClick: Js.boolean=?,
      ~disableEnforceFocus: Js.boolean=?,
      ~disableEscapeKeyDown: Js.boolean=?,
      ~disableRestoreFocus: Js.boolean=?,
      ~hideBackdrop: Js.boolean=?,
      ~keepMounted: Js.boolean=?,
      ~manager: Js.t({..})=?,
      ~onBackdropClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onClose: unit => unit=?,
      ~onEscapeKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onRendered: unit => unit=?,
      ~_open: Js.boolean,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~backdropComponent: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~backdropProps: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~container: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~disableAutoFocus: option(bool)=?,
        ~disableBackdropClick: option(bool)=?,
        ~disableEnforceFocus: option(bool)=?,
        ~disableEscapeKeyDown: option(bool)=?,
        ~disableRestoreFocus: option(bool)=?,
        ~hideBackdrop: option(bool)=?,
        ~keepMounted: option(bool)=?,
        ~manager: option(Js.t({..}))=?,
        ~onBackdropClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onClose: option(unit => unit)=?,
        ~onEscapeKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onRendered: option(unit => unit)=?,
        ~_open: bool,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~backdropComponent=?Js.Option.map([@bs] ((v) => unwrapValue(v)), backdropComponent),
          ~backdropProps?,
          ~className?,
          ~container=?Js.Option.map([@bs] ((v) => unwrapValue(v)), container),
          ~disableAutoFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableAutoFocus),
          ~disableBackdropClick=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableBackdropClick),
          ~disableEnforceFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableEnforceFocus),
          ~disableEscapeKeyDown=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableEscapeKeyDown),
          ~disableRestoreFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRestoreFocus),
          ~hideBackdrop=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), hideBackdrop),
          ~keepMounted=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), keepMounted),
          ~manager?,
          ~onBackdropClick?,
          ~onClose?,
          ~onEscapeKeyDown?,
          ~onRendered?,
          ~_open=Js.Boolean.to_js_boolean(_open),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module MuiThemeProvider = {
  [@bs.module "material-ui/styles/MuiThemeProvider"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~disableStylesGeneration: Js.boolean=?,
      ~sheetsManager: Js.t({..})=?,
      ~theme: 'union_d,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~disableStylesGeneration: option(bool)=?,
        ~sheetsManager: option(Js.t({..}))=?,
        ~theme: [ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)],
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~disableStylesGeneration=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableStylesGeneration),
          ~sheetsManager?,
          ~theme=unwrapValue(theme),
          ()
        ),
      children
    );
};

module Paper = {
  module Classes = {
    type classesType =
      | Root(string)
      | Rounded(string)
      | Elevation0(string)
      | Elevation1(string)
      | Elevation2(string)
      | Elevation3(string)
      | Elevation4(string)
      | Elevation5(string)
      | Elevation6(string)
      | Elevation7(string)
      | Elevation8(string)
      | Elevation9(string)
      | Elevation10(string)
      | Elevation11(string)
      | Elevation12(string)
      | Elevation13(string)
      | Elevation14(string)
      | Elevation15(string)
      | Elevation16(string)
      | Elevation17(string)
      | Elevation18(string)
      | Elevation19(string)
      | Elevation20(string)
      | Elevation21(string)
      | Elevation22(string)
      | Elevation23(string)
      | Elevation24(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Rounded(_) => "rounded"
      | Elevation0(_) => "elevation0"
      | Elevation1(_) => "elevation1"
      | Elevation2(_) => "elevation2"
      | Elevation3(_) => "elevation3"
      | Elevation4(_) => "elevation4"
      | Elevation5(_) => "elevation5"
      | Elevation6(_) => "elevation6"
      | Elevation7(_) => "elevation7"
      | Elevation8(_) => "elevation8"
      | Elevation9(_) => "elevation9"
      | Elevation10(_) => "elevation10"
      | Elevation11(_) => "elevation11"
      | Elevation12(_) => "elevation12"
      | Elevation13(_) => "elevation13"
      | Elevation14(_) => "elevation14"
      | Elevation15(_) => "elevation15"
      | Elevation16(_) => "elevation16"
      | Elevation17(_) => "elevation17"
      | Elevation18(_) => "elevation18"
      | Elevation19(_) => "elevation19"
      | Elevation20(_) => "elevation20"
      | Elevation21(_) => "elevation21"
      | Elevation22(_) => "elevation22"
      | Elevation23(_) => "elevation23"
      | Elevation24(_) => "elevation24";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Rounded(className)
               | Elevation0(className)
               | Elevation1(className)
               | Elevation2(className)
               | Elevation3(className)
               | Elevation4(className)
               | Elevation5(className)
               | Elevation6(className)
               | Elevation7(className)
               | Elevation8(className)
               | Elevation9(className)
               | Elevation10(className)
               | Elevation11(className)
               | Elevation12(className)
               | Elevation13(className)
               | Elevation14(className)
               | Elevation15(className)
               | Elevation16(className)
               | Elevation17(className)
               | Elevation18(className)
               | Elevation19(className)
               | Elevation20(className)
               | Elevation21(className)
               | Elevation22(className)
               | Elevation23(className)
               | Elevation24(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Paper/Paper"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_7=?,
      ~elevation: 'number_e=?,
      ~square: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~square=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), square),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Popover = {
  [@bs.deriving jsConverter]
  type anchorOriginShape = {
    horizontal: int,
    vertical: int
  };
  [@bs.deriving jsConverter]
  type anchorPositionShape = {
    top: int,
    left: int
  };
  [@bs.deriving jsConverter]
  type anchorReference = [
    [@bs.as "anchorEl"] | `AnchorEl
    [@bs.as "anchorPosition"] | `AnchorPosition
  ];
  [@bs.deriving jsConverter]
  type transformOriginShape = {
    horizontal: int,
    vertical: int
  };
  [@bs.deriving jsConverter]
  type transitionDurationShape = {
    enter: int,
    exit: int
  };
  [@bs.deriving jsConverter]
  type transitionDuration = [ [@bs.as "auto"] | `Auto];
  module Classes = {
    type classesType =
      | Paper(string);
    type t = list(classesType);
    let to_string =
      fun
      | Paper(_) => "paper";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Paper(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Popover/Popover"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~action: ReasonReact.reactElement=?,
      ~anchorEl: 'union_j=?,
      ~anchorOrigin: 'shape_a=?,
      ~anchorPosition: 'shape_l=?,
      ~anchorReference: string=?,
      ~container: 'union_b=?,
      ~elevation: 'number_7=?,
      ~getContentAnchorEl: ReasonReact.reactElement=?,
      ~marginThreshold: 'number_q=?,
      ~onClose: unit => unit=?,
      ~onEnter: unit => unit=?,
      ~onEntered: unit => unit=?,
      ~onEntering: unit => unit=?,
      ~onExit: unit => unit=?,
      ~onExited: unit => unit=?,
      ~onExiting: unit => unit=?,
      ~_open: Js.boolean,
      ~paperProps: Js.t({..})=?,
      ~role: string=?,
      ~transformOrigin: 'shape_v=?,
      ~transition: 'union_u=?,
      ~transitionDuration: 'union_a=?,
      ~backdropComponent: 'union_0=?,
      ~backdropProps: Js.t({..})=?,
      ~className: string=?,
      ~disableAutoFocus: Js.boolean=?,
      ~disableBackdropClick: Js.boolean=?,
      ~disableEnforceFocus: Js.boolean=?,
      ~disableEscapeKeyDown: Js.boolean=?,
      ~disableRestoreFocus: Js.boolean=?,
      ~hideBackdrop: Js.boolean=?,
      ~keepMounted: Js.boolean=?,
      ~manager: Js.t({..})=?,
      ~onBackdropClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onEscapeKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onRendered: unit => unit=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~anchorEl: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~anchorOrigin: option(anchorOriginShape)=?,
        ~anchorPosition: option(anchorPositionShape)=?,
        ~anchorReference: option(anchorReference)=?,
        ~container: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~getContentAnchorEl: option(ReasonReact.reactElement)=?,
        ~marginThreshold: option([ | `Int(int) | `Float(float)])=?,
        ~onClose: option(unit => unit)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntered: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~onExited: option(unit => unit)=?,
        ~onExiting: option(unit => unit)=?,
        ~_open: bool,
        ~paperProps: option(Js.t({..}))=?,
        ~role: option(string)=?,
        ~transformOrigin: option(transformOriginShape)=?,
        ~transition: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~transitionDuration:
           option(
             [
               | `Int(int)
               | `Float(float)
               | `Object(transitionDurationShape)
               | `Enum(transitionDuration)
             ]
           )=?,
        ~backdropComponent: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~backdropProps: option(Js.t({..}))=?,
        ~className: option(string)=?,
        ~disableAutoFocus: option(bool)=?,
        ~disableBackdropClick: option(bool)=?,
        ~disableEnforceFocus: option(bool)=?,
        ~disableEscapeKeyDown: option(bool)=?,
        ~disableRestoreFocus: option(bool)=?,
        ~hideBackdrop: option(bool)=?,
        ~keepMounted: option(bool)=?,
        ~manager: option(Js.t({..}))=?,
        ~onBackdropClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onEscapeKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onRendered: option(unit => unit)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~action?,
          ~anchorEl=?Js.Option.map([@bs] ((v) => unwrapValue(v)), anchorEl),
          ~anchorOrigin=?Js.Option.map([@bs] ((v) => anchorOriginShapeToJs(v)), anchorOrigin),
          ~anchorPosition=?
            Js.Option.map([@bs] ((v) => anchorPositionShapeToJs(v)), anchorPosition),
          ~anchorReference=?Js.Option.map([@bs] ((v) => anchorReferenceToJs(v)), anchorReference),
          ~container=?Js.Option.map([@bs] ((v) => unwrapValue(v)), container),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~getContentAnchorEl?,
          ~marginThreshold=?Js.Option.map([@bs] ((v) => unwrapValue(v)), marginThreshold),
          ~onClose?,
          ~onEnter?,
          ~onEntered?,
          ~onEntering?,
          ~onExit?,
          ~onExited?,
          ~onExiting?,
          ~_open=Js.Boolean.to_js_boolean(_open),
          ~paperProps?,
          ~role?,
          ~transformOrigin=?
            Js.Option.map([@bs] ((v) => transformOriginShapeToJs(v)), transformOrigin),
          ~transition=?Js.Option.map([@bs] ((v) => unwrapValue(v)), transition),
          ~transitionDuration=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(transitionDurationToJs(v)))
                  | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              transitionDuration
            ),
          ~backdropComponent=?Js.Option.map([@bs] ((v) => unwrapValue(v)), backdropComponent),
          ~backdropProps?,
          ~className?,
          ~disableAutoFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableAutoFocus),
          ~disableBackdropClick=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableBackdropClick),
          ~disableEnforceFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableEnforceFocus),
          ~disableEscapeKeyDown=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableEscapeKeyDown),
          ~disableRestoreFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRestoreFocus),
          ~hideBackdrop=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), hideBackdrop),
          ~keepMounted=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), keepMounted),
          ~manager?,
          ~onBackdropClick?,
          ~onEscapeKeyDown?,
          ~onRendered?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Portal = {
  [@bs.module "material-ui/Portal/Portal"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps : (~container: 'union_8=?, ~onRendered: unit => unit=?, unit) => _ = "";
  let make =
      (
        ~container: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~onRendered: option(unit => unit)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~container=?Js.Option.map([@bs] ((v) => unwrapValue(v)), container),
          ~onRendered?,
          ()
        ),
      children
    );
};

module RadioGroup = {
  [@bs.module "material-ui/Radio/RadioGroup"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~name: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~value: string=?,
      ~className: string=?,
      ~row: Js.boolean=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~value: option(string)=?,
        ~className: option(string)=?,
        ~row: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~name?,
          ~onBlur?,
          ~onChange?,
          ~onKeyDown?,
          ~value?,
          ~className?,
          ~row=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), row),
          ()
        ),
      children
    );
};

module Radio = {
  [@bs.deriving jsConverter]
  type color = [ [@bs.as "primary"] | `Primary [@bs.as "secondary"] | `Secondary];
  module Classes = {
    type classesType =
      | Default(string)
      | Checked(string)
      | CheckedPrimary(string)
      | CheckedSecondary(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Default(_) => "default"
      | Checked(_) => "checked"
      | CheckedPrimary(_) => "checkedPrimary"
      | CheckedSecondary(_) => "checkedSecondary"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Default(className)
               | Checked(className)
               | CheckedPrimary(className)
               | CheckedSecondary(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Radio/Radio"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~checked: 'union_p=?,
      ~checkedIcon: ReasonReact.reactElement=?,
      ~color: string=?,
      ~disabled: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~icon: ReasonReact.reactElement=?,
      ~id: string=?,
      ~inputProps: Js.t({..})=?,
      ~inputRef: ReasonReact.reactElement=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~_type: string=?,
      ~value: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~color: option(color)=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~id: option(string)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~_type: option(string)=?,
        ~value: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~checked=?Js.Option.map([@bs] ((v) => unwrapValue(v)), checked),
          ~checkedIcon?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~icon?,
          ~id?,
          ~inputProps?,
          ~inputRef?,
          ~onChange?,
          ~_type?,
          ~value?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Reboot = {
  [@bs.module "material-ui/Reboot/Reboot"]
  external reactClass : ReasonReact.reactClass = "default";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module Select = {
  [@bs.deriving jsConverter]
  type margin = [ [@bs.as "dense"] | `Dense [@bs.as "none"] | `None];
  module Classes = {
    type classesType =
      | Root(string)
      | Select(string)
      | SelectMenu(string)
      | Disabled(string)
      | Icon(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Select(_) => "select"
      | SelectMenu(_) => "selectMenu"
      | Disabled(_) => "disabled"
      | Icon(_) => "icon";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Select(className)
               | SelectMenu(className)
               | Disabled(className)
               | Icon(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Select/Select"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~autoWidth: Js.boolean=?,
      ~displayEmpty: Js.boolean=?,
      ~input: ReasonReact.reactElement=?,
      ~inputProps: Js.t({..})=?,
      ~menuProps: Js.t({..})=?,
      ~multiple: Js.boolean=?,
      ~native: Js.boolean=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~onClose: unit => unit=?,
      ~onOpen: unit => unit=?,
      ~_open: Js.boolean=?,
      ~renderValue: ReasonReact.reactElement=?,
      ~selectDisplayProps: Js.t({..})=?,
      ~value: 'union_l=?,
      ~autoComplete: string=?,
      ~autoFocus: Js.boolean=?,
      ~className: string=?,
      ~defaultValue: 'union_8=?,
      ~disabled: Js.boolean=?,
      ~disableUnderline: Js.boolean=?,
      ~endAdornment: ReasonReact.reactElement=?,
      ~error: Js.boolean=?,
      ~fullWidth: Js.boolean=?,
      ~id: string=?,
      ~inputComponent: 'union_0=?,
      ~inputRef: ReasonReact.reactElement=?,
      ~margin: string=?,
      ~multiline: Js.boolean=?,
      ~name: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClean: unit => unit=?,
      ~onDirty: unit => unit=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~placeholder: string=?,
      ~readOnly: Js.boolean=?,
      ~rows: 'union_9=?,
      ~rowsMax: 'union_5=?,
      ~startAdornment: ReasonReact.reactElement=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~autoWidth: option(bool)=?,
        ~displayEmpty: option(bool)=?,
        ~input: option(ReasonReact.reactElement)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~menuProps: option(Js.t({..}))=?,
        ~multiple: option(bool)=?,
        ~native: option(bool)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClose: option(unit => unit)=?,
        ~onOpen: option(unit => unit)=?,
        ~_open: option(bool)=?,
        ~renderValue: option(ReasonReact.reactElement)=?,
        ~selectDisplayProps: option(Js.t({..}))=?,
        ~value:
           option(
             [
               | `String(string)
               | `Int(int)
               | `Float(float)
               | `StringArray(array(string))
               | `IntArray(array(int))
               | `FloatArray(array(float))
             ]
           )=?,
        ~autoComplete: option(string)=?,
        ~autoFocus: option(bool)=?,
        ~className: option(string)=?,
        ~defaultValue: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~disabled: option(bool)=?,
        ~disableUnderline: option(bool)=?,
        ~endAdornment: option(ReasonReact.reactElement)=?,
        ~error: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~id: option(string)=?,
        ~inputComponent: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~margin: option(margin)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClean: option(unit => unit)=?,
        ~onDirty: option(unit => unit)=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~placeholder: option(string)=?,
        ~readOnly: option(bool)=?,
        ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~startAdornment: option(ReasonReact.reactElement)=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~autoWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), autoWidth),
          ~displayEmpty=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), displayEmpty),
          ~input?,
          ~inputProps?,
          ~menuProps?,
          ~multiple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), multiple),
          ~native=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), native),
          ~onChange?,
          ~onClose?,
          ~onOpen?,
          ~_open=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _open),
          ~renderValue?,
          ~selectDisplayProps?,
          ~value=?Js.Option.map([@bs] ((v) => unwrapValue(v)), value),
          ~autoComplete?,
          ~autoFocus=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), autoFocus),
          ~className?,
          ~defaultValue=?Js.Option.map([@bs] ((v) => unwrapValue(v)), defaultValue),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableUnderline=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableUnderline),
          ~endAdornment?,
          ~error=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), error),
          ~fullWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullWidth),
          ~id?,
          ~inputComponent=?Js.Option.map([@bs] ((v) => unwrapValue(v)), inputComponent),
          ~inputRef?,
          ~margin=?Js.Option.map([@bs] ((v) => marginToJs(v)), margin),
          ~multiline=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), multiline),
          ~name?,
          ~onBlur?,
          ~onClean?,
          ~onDirty?,
          ~onFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~placeholder?,
          ~readOnly=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), readOnly),
          ~rows=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rows),
          ~rowsMax=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowsMax),
          ~startAdornment?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Slide = {
  [@bs.deriving jsConverter]
  type direction = [
    [@bs.as "left"] | `Left
    [@bs.as "right"] | `Right
    [@bs.as "up"] | `Up
    [@bs.as "down"] | `Down
  ];
  [@bs.deriving jsConverter]
  type timeoutShape = {
    enter: int,
    exit: int
  };
  [@bs.module "material-ui/transitions/Slide"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~direction: string=?,
      ~_in: Js.boolean=?,
      ~onEnter: unit => unit=?,
      ~onEntered: unit => unit=?,
      ~onEntering: unit => unit=?,
      ~onExit: unit => unit=?,
      ~onExited: unit => unit=?,
      ~onExiting: unit => unit=?,
      ~style: Js.t({..})=?,
      ~theme: Js.t({..}),
      ~timeout: 'union_u=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~direction: option(direction)=?,
        ~_in: option(bool)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntered: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~onExited: option(unit => unit)=?,
        ~onExiting: option(unit => unit)=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~direction=?Js.Option.map([@bs] ((v) => directionToJs(v)), direction),
          ~_in=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _in),
          ~onEnter?,
          ~onEntered?,
          ~onEntering?,
          ~onExit?,
          ~onExited?,
          ~onExiting?,
          ~style?,
          ~theme,
          ~timeout=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              timeout
            ),
          ()
        ),
      children
    );
};

module SnackbarContent = {
  module Classes = {
    type classesType =
      | Root(string)
      | Message(string)
      | Action(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Message(_) => "message"
      | Action(_) => "action";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Message(className)
               | Action(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Snackbar/SnackbarContent"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~action: ReasonReact.reactElement=?,
      ~className: string=?,
      ~message: ReasonReact.reactElement=?,
      ~component: 'union_7=?,
      ~elevation: 'number_e=?,
      ~square: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~message: option(ReasonReact.reactElement)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~action?,
          ~className?,
          ~message?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~square=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), square),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Snackbar = {
  [@bs.deriving jsConverter]
  type anchorOriginShape = {
    horizontal: int,
    vertical: int
  };
  [@bs.deriving jsConverter]
  type transitionDurationShape = {
    enter: int,
    exit: int
  };
  module Classes = {
    type classesType =
      | Root(string)
      | AnchorOriginTopCenter(string)
      | AnchorOriginBottomCenter(string)
      | AnchorOriginTopRight(string)
      | AnchorOriginBottomRight(string)
      | AnchorOriginTopLeft(string)
      | AnchorOriginBottomLeft(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | AnchorOriginTopCenter(_) => "anchorOriginTopCenter"
      | AnchorOriginBottomCenter(_) => "anchorOriginBottomCenter"
      | AnchorOriginTopRight(_) => "anchorOriginTopRight"
      | AnchorOriginBottomRight(_) => "anchorOriginBottomRight"
      | AnchorOriginTopLeft(_) => "anchorOriginTopLeft"
      | AnchorOriginBottomLeft(_) => "anchorOriginBottomLeft";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | AnchorOriginTopCenter(className)
               | AnchorOriginBottomCenter(className)
               | AnchorOriginTopRight(className)
               | AnchorOriginBottomRight(className)
               | AnchorOriginTopLeft(className)
               | AnchorOriginBottomLeft(className) =>
                 Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Snackbar/Snackbar"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~action: ReasonReact.reactElement=?,
      ~anchorOrigin: 'shape_v=?,
      ~autoHideDuration: 'number_v=?,
      ~className: string=?,
      ~disableWindowBlurListener: Js.boolean=?,
      ~key: 'any_o=?,
      ~message: ReasonReact.reactElement=?,
      ~onClose: unit => unit=?,
      ~onEnter: unit => unit=?,
      ~onEntered: unit => unit=?,
      ~onEntering: unit => unit=?,
      ~onExit: unit => unit=?,
      ~onExited: unit => unit=?,
      ~onExiting: unit => unit=?,
      ~onMouseEnter: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~_open: Js.boolean=?,
      ~resumeHideDuration: 'number_2=?,
      ~snackbarContentProps: Js.t({..})=?,
      ~transition: 'union_g=?,
      ~transitionDuration: 'union_h=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~anchorOrigin: option(anchorOriginShape)=?,
        ~autoHideDuration: option([ | `Int(int) | `Float(float)])=?,
        ~className: option(string)=?,
        ~disableWindowBlurListener: option(bool)=?,
        ~key: option('any_o)=?,
        ~message: option(ReasonReact.reactElement)=?,
        ~onClose: option(unit => unit)=?,
        ~onEnter: option(unit => unit)=?,
        ~onEntered: option(unit => unit)=?,
        ~onEntering: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~onExited: option(unit => unit)=?,
        ~onExiting: option(unit => unit)=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~_open: option(bool)=?,
        ~resumeHideDuration: option([ | `Int(int) | `Float(float)])=?,
        ~snackbarContentProps: option(Js.t({..}))=?,
        ~transition: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~transitionDuration:
           option([ | `Int(int) | `Float(float) | `Object(transitionDurationShape)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~action?,
          ~anchorOrigin=?Js.Option.map([@bs] ((v) => anchorOriginShapeToJs(v)), anchorOrigin),
          ~autoHideDuration=?Js.Option.map([@bs] ((v) => unwrapValue(v)), autoHideDuration),
          ~className?,
          ~disableWindowBlurListener=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableWindowBlurListener),
          ~key?,
          ~message?,
          ~onClose?,
          ~onEnter?,
          ~onEntered?,
          ~onEntering?,
          ~onExit?,
          ~onExited?,
          ~onExiting?,
          ~onMouseEnter?,
          ~onMouseLeave?,
          ~_open=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _open),
          ~resumeHideDuration=?Js.Option.map([@bs] ((v) => unwrapValue(v)), resumeHideDuration),
          ~snackbarContentProps?,
          ~transition=?Js.Option.map([@bs] ((v) => unwrapValue(v)), transition),
          ~transitionDuration=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              transitionDuration
            ),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module StepButton = {
  [@bs.deriving jsConverter]
  type orientation = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/StepButton"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~alternativeLabel: Js.boolean=?,
      ~className: string=?,
      ~completed: Js.boolean=?,
      ~disabled: Js.boolean=?,
      ~icon: ReasonReact.reactElement=?,
      ~last: Js.boolean=?,
      ~optional: ReasonReact.reactElement=?,
      ~orientation: string=?,
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~component: 'union_y=?,
      ~disableRipple: Js.boolean=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active: option(bool)=?,
        ~alternativeLabel: option(bool)=?,
        ~className: option(string)=?,
        ~completed: option(bool)=?,
        ~disabled: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~last: option(bool)=?,
        ~optional: option(ReasonReact.reactElement)=?,
        ~orientation: option(orientation)=?,
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~active=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), active),
          ~alternativeLabel=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), alternativeLabel),
          ~className?,
          ~completed=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), completed),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~icon?,
          ~last=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), last),
          ~optional?,
          ~orientation=?Js.Option.map([@bs] ((v) => orientationToJs(v)), orientation),
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onClick?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module StepContent = {
  [@bs.deriving jsConverter]
  type orientation = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  [@bs.deriving jsConverter]
  type transitionDurationShape = {
    enter: int,
    exit: int
  };
  [@bs.deriving jsConverter]
  type transitionDuration = [ [@bs.as "auto"] | `Auto];
  module Classes = {
    type classesType =
      | Root(string)
      | Last(string)
      | Transition(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Last(_) => "last"
      | Transition(_) => "transition";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Last(className)
               | Transition(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/StepContent"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~alternativeLabel: Js.boolean=?,
      ~className: string=?,
      ~completed: Js.boolean=?,
      ~last: Js.boolean=?,
      ~optional: Js.boolean=?,
      ~orientation: string=?,
      ~transition: ReasonReact.reactElement=?,
      ~transitionDuration: 'union_w=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active: option(bool)=?,
        ~alternativeLabel: option(bool)=?,
        ~className: option(string)=?,
        ~completed: option(bool)=?,
        ~last: option(bool)=?,
        ~optional: option(bool)=?,
        ~orientation: option(orientation)=?,
        ~transition: option(ReasonReact.reactElement)=?,
        ~transitionDuration:
           option(
             [
               | `Int(int)
               | `Float(float)
               | `Object(transitionDurationShape)
               | `Enum(transitionDuration)
             ]
           )=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~active=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), active),
          ~alternativeLabel=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), alternativeLabel),
          ~className?,
          ~completed=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), completed),
          ~last=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), last),
          ~optional=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), optional),
          ~orientation=?Js.Option.map([@bs] ((v) => orientationToJs(v)), orientation),
          ~transition?,
          ~transitionDuration=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(transitionDurationToJs(v)))
                  | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              transitionDuration
            ),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module StepIcon = {
  module Classes = {
    type classesType =
      | Root(string)
      | Completed(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Completed(_) => "completed";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Completed(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/StepIcon"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~completed: Js.boolean=?,
      ~icon: ReasonReact.reactElement,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active: option(bool)=?,
        ~completed: option(bool)=?,
        ~icon: ReasonReact.reactElement,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~active=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), active),
          ~completed=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), completed),
          ~icon,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module StepLabel = {
  [@bs.deriving jsConverter]
  type orientation = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  module Classes = {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | Vertical(string)
      | AlternativeLabel(string)
      | Disabled(string)
      | Label(string)
      | LabelActive(string)
      | LabelCompleted(string)
      | LabelAlternativeLabel(string)
      | IconContainer(string)
      | IconContainerAlternativeLabel(string)
      | LabelContainer(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Horizontal(_) => "horizontal"
      | Vertical(_) => "vertical"
      | AlternativeLabel(_) => "alternativeLabel"
      | Disabled(_) => "disabled"
      | Label(_) => "label"
      | LabelActive(_) => "labelActive"
      | LabelCompleted(_) => "labelCompleted"
      | LabelAlternativeLabel(_) => "labelAlternativeLabel"
      | IconContainer(_) => "iconContainer"
      | IconContainerAlternativeLabel(_) => "iconContainerAlternativeLabel"
      | LabelContainer(_) => "labelContainer";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Horizontal(className)
               | Vertical(className)
               | AlternativeLabel(className)
               | Disabled(className)
               | Label(className)
               | LabelActive(className)
               | LabelCompleted(className)
               | LabelAlternativeLabel(className)
               | IconContainer(className)
               | IconContainerAlternativeLabel(className)
               | LabelContainer(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/StepLabel"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~alternativeLabel: Js.boolean=?,
      ~className: string=?,
      ~completed: Js.boolean=?,
      ~disabled: Js.boolean=?,
      ~icon: ReasonReact.reactElement=?,
      ~last: Js.boolean=?,
      ~optional: ReasonReact.reactElement=?,
      ~orientation: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active: option(bool)=?,
        ~alternativeLabel: option(bool)=?,
        ~className: option(string)=?,
        ~completed: option(bool)=?,
        ~disabled: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~last: option(bool)=?,
        ~optional: option(ReasonReact.reactElement)=?,
        ~orientation: option(orientation)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~active=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), active),
          ~alternativeLabel=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), alternativeLabel),
          ~className?,
          ~completed=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), completed),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~icon?,
          ~last=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), last),
          ~optional?,
          ~orientation=?Js.Option.map([@bs] ((v) => orientationToJs(v)), orientation),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Step = {
  [@bs.deriving jsConverter]
  type orientation = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  module Classes = {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | Vertical(string)
      | AlternativeLabel(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Horizontal(_) => "horizontal"
      | Vertical(_) => "vertical"
      | AlternativeLabel(_) => "alternativeLabel";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Horizontal(className)
               | Vertical(className)
               | AlternativeLabel(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/Step"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~alternativeLabel: Js.boolean=?,
      ~className: string=?,
      ~completed: Js.boolean=?,
      ~connector: ReasonReact.reactElement=?,
      ~disabled: Js.boolean=?,
      ~index: 'number_o=?,
      ~last: Js.boolean=?,
      ~orientation: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active: option(bool)=?,
        ~alternativeLabel: option(bool)=?,
        ~className: option(string)=?,
        ~completed: option(bool)=?,
        ~connector: option(ReasonReact.reactElement)=?,
        ~disabled: option(bool)=?,
        ~index: option([ | `Int(int) | `Float(float)])=?,
        ~last: option(bool)=?,
        ~orientation: option(orientation)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~active=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), active),
          ~alternativeLabel=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), alternativeLabel),
          ~className?,
          ~completed=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), completed),
          ~connector?,
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~index=?Js.Option.map([@bs] ((v) => unwrapValue(v)), index),
          ~last=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), last),
          ~orientation=?Js.Option.map([@bs] ((v) => orientationToJs(v)), orientation),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Stepper = {
  [@bs.deriving jsConverter]
  type orientation = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  module Classes = {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | Vertical(string)
      | AlternativeLabel(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Horizontal(_) => "horizontal"
      | Vertical(_) => "vertical"
      | AlternativeLabel(_) => "alternativeLabel";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Horizontal(className)
               | Vertical(className)
               | AlternativeLabel(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/Stepper"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~activeStep: 'number_7=?,
      ~alternativeLabel: Js.boolean=?,
      ~className: string=?,
      ~connector: ReasonReact.reactElement=?,
      ~nonLinear: Js.boolean=?,
      ~orientation: string=?,
      ~component: 'union_7=?,
      ~elevation: 'number_e=?,
      ~square: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~activeStep: option([ | `Int(int) | `Float(float)])=?,
        ~alternativeLabel: option(bool)=?,
        ~className: option(string)=?,
        ~connector: option(ReasonReact.reactElement)=?,
        ~nonLinear: option(bool)=?,
        ~orientation: option(orientation)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~activeStep=?Js.Option.map([@bs] ((v) => unwrapValue(v)), activeStep),
          ~alternativeLabel=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), alternativeLabel),
          ~className?,
          ~connector?,
          ~nonLinear=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), nonLinear),
          ~orientation=?Js.Option.map([@bs] ((v) => orientationToJs(v)), orientation),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~elevation=?Js.Option.map([@bs] ((v) => unwrapValue(v)), elevation),
          ~square=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), square),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module SvgIcon = {
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "action"] | `Action
    [@bs.as "disabled"] | `Disabled
    [@bs.as "error"] | `Error
    [@bs.as "inherit"] | `Inherit
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | ColorAction(string)
      | ColorDisabled(string)
      | ColorError(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | ColorAction(_) => "colorAction"
      | ColorDisabled(_) => "colorDisabled"
      | ColorError(_) => "colorError";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | ColorPrimary(className)
               | ColorSecondary(className)
               | ColorAction(className)
               | ColorDisabled(className)
               | ColorError(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/SvgIcon/SvgIcon"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~color: string=?,
      ~nativeColor: string=?,
      ~titleAccess: string=?,
      ~viewBox: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~nativeColor: option(string)=?,
        ~titleAccess: option(string)=?,
        ~viewBox: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~nativeColor?,
          ~titleAccess?,
          ~viewBox?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Switch = {
  [@bs.deriving jsConverter]
  type color = [ [@bs.as "primary"] | `Primary [@bs.as "secondary"] | `Secondary];
  module Classes = {
    type classesType =
      | Root(string)
      | Bar(string)
      | Icon(string)
      | IconChecked(string)
      | Default(string)
      | Checked(string)
      | CheckedPrimary(string)
      | CheckedSecondary(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Bar(_) => "bar"
      | Icon(_) => "icon"
      | IconChecked(_) => "iconChecked"
      | Default(_) => "default"
      | Checked(_) => "checked"
      | CheckedPrimary(_) => "checkedPrimary"
      | CheckedSecondary(_) => "checkedSecondary"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Bar(className)
               | Icon(className)
               | IconChecked(className)
               | Default(className)
               | Checked(className)
               | CheckedPrimary(className)
               | CheckedSecondary(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Switch/Switch"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~checked: 'union_6=?,
      ~checkedIcon: ReasonReact.reactElement=?,
      ~className: string=?,
      ~color: string=?,
      ~defaultChecked: Js.boolean=?,
      ~disabled: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~icon: ReasonReact.reactElement=?,
      ~id: string=?,
      ~inputProps: Js.t({..})=?,
      ~inputRef: ReasonReact.reactElement=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~_type: string=?,
      ~value: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~defaultChecked: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~id: option(string)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~_type: option(string)=?,
        ~value: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~checked=?Js.Option.map([@bs] ((v) => unwrapValue(v)), checked),
          ~checkedIcon?,
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~defaultChecked=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), defaultChecked),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~icon?,
          ~id?,
          ~inputProps?,
          ~inputRef?,
          ~onChange?,
          ~_type?,
          ~value?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Tab = {
  [@bs.deriving jsConverter]
  type textColor = [
    [@bs.as "secondary"] | `Secondary
    [@bs.as "primary"] | `Primary
    [@bs.as "inherit"] | `Inherit
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | LabelIcon(string)
      | TextColorInherit(string)
      | TextColorPrimary(string)
      | TextColorPrimarySelected(string)
      | TextColorPrimaryDisabled(string)
      | TextColorSecondary(string)
      | TextColorSecondarySelected(string)
      | TextColorSecondaryDisabled(string)
      | TextColorInheritSelected(string)
      | TextColorInheritDisabled(string)
      | FullWidth(string)
      | Wrapper(string)
      | LabelContainer(string)
      | Label(string)
      | LabelWrapped(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | LabelIcon(_) => "labelIcon"
      | TextColorInherit(_) => "textColorInherit"
      | TextColorPrimary(_) => "textColorPrimary"
      | TextColorPrimarySelected(_) => "textColorPrimarySelected"
      | TextColorPrimaryDisabled(_) => "textColorPrimaryDisabled"
      | TextColorSecondary(_) => "textColorSecondary"
      | TextColorSecondarySelected(_) => "textColorSecondarySelected"
      | TextColorSecondaryDisabled(_) => "textColorSecondaryDisabled"
      | TextColorInheritSelected(_) => "textColorInheritSelected"
      | TextColorInheritDisabled(_) => "textColorInheritDisabled"
      | FullWidth(_) => "fullWidth"
      | Wrapper(_) => "wrapper"
      | LabelContainer(_) => "labelContainer"
      | Label(_) => "label"
      | LabelWrapped(_) => "labelWrapped";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | LabelIcon(className)
               | TextColorInherit(className)
               | TextColorPrimary(className)
               | TextColorPrimarySelected(className)
               | TextColorPrimaryDisabled(className)
               | TextColorSecondary(className)
               | TextColorSecondarySelected(className)
               | TextColorSecondaryDisabled(className)
               | TextColorInheritSelected(className)
               | TextColorInheritDisabled(className)
               | FullWidth(className)
               | Wrapper(className)
               | LabelContainer(className)
               | Label(className)
               | LabelWrapped(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tabs/Tab"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disabled: Js.boolean=?,
      ~fullWidth: Js.boolean=?,
      ~icon: ReasonReact.reactElement=?,
      ~indicator: ReasonReact.reactElement=?,
      ~label: ReasonReact.reactElement=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~selected: Js.boolean=?,
      ~style: Js.t({..})=?,
      ~textColor: 'union_i=?,
      ~value: 'any_5=?,
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~component: 'union_y=?,
      ~disableRipple: Js.boolean=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disabled: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~indicator: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~selected: option(bool)=?,
        ~style: option(Js.t({..}))=?,
        ~textColor: option([ | `String(string) | `Enum(textColor)])=?,
        ~value: option('any_5)=?,
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~fullWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullWidth),
          ~icon?,
          ~indicator?,
          ~label?,
          ~onChange?,
          ~onClick?,
          ~selected=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), selected),
          ~style?,
          ~textColor=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(textColorToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              textColor
            ),
          ~value?,
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module TableBody = {
  [@bs.module "material-ui/Table/TableBody"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj] external makeProps : (~className: string=?, ~component: 'union_c=?, unit) => _ = "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ()
        ),
      children
    );
};

module TableCell = {
  [@bs.deriving jsConverter]
  type padding = [
    [@bs.as "default"] | `Default
    [@bs.as "checkbox"] | `Checkbox
    [@bs.as "dense"] | `Dense
    [@bs.as "none"] | `None
  ];
  [@bs.deriving jsConverter]
  type sortDirection = [ [@bs.as "asc"] | `Asc [@bs.as "desc"] | `Desc [@bs.as "0"] | `False];
  [@bs.deriving jsConverter]
  type variant = [ [@bs.as "head"] | `Head [@bs.as "body"] | `Body [@bs.as "footer"] | `Footer];
  module Classes = {
    type classesType =
      | Root(string)
      | Head(string)
      | Body(string)
      | Footer(string)
      | Numeric(string)
      | PaddingDense(string)
      | PaddingCheckbox(string)
      | PaddingNone(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Head(_) => "head"
      | Body(_) => "body"
      | Footer(_) => "footer"
      | Numeric(_) => "numeric"
      | PaddingDense(_) => "paddingDense"
      | PaddingCheckbox(_) => "paddingCheckbox"
      | PaddingNone(_) => "paddingNone";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Head(className)
               | Body(className)
               | Footer(className)
               | Numeric(className)
               | PaddingDense(className)
               | PaddingCheckbox(className)
               | PaddingNone(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableCell"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_x=?,
      ~numeric: Js.boolean=?,
      ~padding: string=?,
      ~scope: string=?,
      ~sortDirection: string=?,
      ~variant: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~numeric: option(bool)=?,
        ~padding: option(padding)=?,
        ~scope: option(string)=?,
        ~sortDirection: option(sortDirection)=?,
        ~variant: option(variant)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~numeric=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), numeric),
          ~padding=?Js.Option.map([@bs] ((v) => paddingToJs(v)), padding),
          ~scope?,
          ~sortDirection=?Js.Option.map([@bs] ((v) => sortDirectionToJs(v)), sortDirection),
          ~variant=?Js.Option.map([@bs] ((v) => variantToJs(v)), variant),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module TableFooter = {
  [@bs.module "material-ui/Table/TableFooter"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj] external makeProps : (~component: 'union_h=?, unit) => _ = "";
  let make =
      (~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=makeProps(~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component), ()),
      children
    );
};

module TableHead = {
  [@bs.module "material-ui/Table/TableHead"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj] external makeProps : (~className: string=?, ~component: 'union_m=?, unit) => _ = "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ()
        ),
      children
    );
};

module TablePagination = {
  [@bs.deriving jsConverter]
  type padding = [
    [@bs.as "default"] | `Default
    [@bs.as "checkbox"] | `Checkbox
    [@bs.as "dense"] | `Dense
    [@bs.as "none"] | `None
  ];
  [@bs.deriving jsConverter]
  type sortDirection = [ [@bs.as "asc"] | `Asc [@bs.as "desc"] | `Desc [@bs.as "0"] | `False];
  [@bs.deriving jsConverter]
  type variant = [ [@bs.as "head"] | `Head [@bs.as "body"] | `Body [@bs.as "footer"] | `Footer];
  module Classes = {
    type classesType =
      | Root(string)
      | Toolbar(string)
      | Spacer(string)
      | Caption(string)
      | Input(string)
      | SelectRoot(string)
      | Select(string)
      | SelectIcon(string)
      | Actions(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Toolbar(_) => "toolbar"
      | Spacer(_) => "spacer"
      | Caption(_) => "caption"
      | Input(_) => "input"
      | SelectRoot(_) => "selectRoot"
      | Select(_) => "select"
      | SelectIcon(_) => "selectIcon"
      | Actions(_) => "actions";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Toolbar(className)
               | Spacer(className)
               | Caption(className)
               | Input(className)
               | SelectRoot(className)
               | Select(className)
               | SelectIcon(className)
               | Actions(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TablePagination"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~actions: 'union_v=?,
      ~backIconButtonProps: Js.t({..})=?,
      ~colSpan: 'number_p=?,
      ~component: 'union_k=?,
      ~count: 'number_9,
      ~labelDisplayedRows: ReasonReact.reactElement=?,
      ~labelRowsPerPage: ReasonReact.reactElement=?,
      ~nextIconButtonProps: Js.t({..})=?,
      ~onChangePage: unit => unit,
      ~onChangeRowsPerPage: unit => unit=?,
      ~page: 'number_m,
      ~rowsPerPage: 'number_i,
      ~rowsPerPageOptions: 'arrayGeneric_h=?,
      ~className: string=?,
      ~numeric: Js.boolean=?,
      ~padding: string=?,
      ~scope: string=?,
      ~sortDirection: string=?,
      ~variant: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~actions: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~backIconButtonProps: option(Js.t({..}))=?,
        ~colSpan: option([ | `Int(int) | `Float(float)])=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~count: [ | `Int(int) | `Float(float)],
        ~labelDisplayedRows: option(ReasonReact.reactElement)=?,
        ~labelRowsPerPage: option(ReasonReact.reactElement)=?,
        ~nextIconButtonProps: option(Js.t({..}))=?,
        ~onChangePage: unit => unit,
        ~onChangeRowsPerPage: option(unit => unit)=?,
        ~page: [ | `Int(int) | `Float(float)],
        ~rowsPerPage: [ | `Int(int) | `Float(float)],
        ~rowsPerPageOptions: option([ | `ArrayGeneric(array('any_8))])=?,
        ~className: option(string)=?,
        ~numeric: option(bool)=?,
        ~padding: option(padding)=?,
        ~scope: option(string)=?,
        ~sortDirection: option(sortDirection)=?,
        ~variant: option(variant)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~actions=?Js.Option.map([@bs] ((v) => unwrapValue(v)), actions),
          ~backIconButtonProps?,
          ~colSpan=?Js.Option.map([@bs] ((v) => unwrapValue(v)), colSpan),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~count=unwrapValue(count),
          ~labelDisplayedRows?,
          ~labelRowsPerPage?,
          ~nextIconButtonProps?,
          ~onChangePage,
          ~onChangeRowsPerPage?,
          ~page=unwrapValue(page),
          ~rowsPerPage=unwrapValue(rowsPerPage),
          ~rowsPerPageOptions?,
          ~className?,
          ~numeric=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), numeric),
          ~padding=?Js.Option.map([@bs] ((v) => paddingToJs(v)), padding),
          ~scope?,
          ~sortDirection=?Js.Option.map([@bs] ((v) => sortDirectionToJs(v)), sortDirection),
          ~variant=?Js.Option.map([@bs] ((v) => variantToJs(v)), variant),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module TableRow = {
  module Classes = {
    type classesType =
      | Root(string)
      | Head(string)
      | Footer(string)
      | Selected(string)
      | Hover(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Head(_) => "head"
      | Footer(_) => "footer"
      | Selected(_) => "selected"
      | Hover(_) => "hover";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Head(className)
               | Footer(className)
               | Selected(className)
               | Hover(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableRow"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~component: 'union_2=?,
      ~hover: Js.boolean=?,
      ~selected: Js.boolean=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~hover: option(bool)=?,
        ~selected: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~hover=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), hover),
          ~selected=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), selected),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module TableSortLabel = {
  [@bs.deriving jsConverter]
  type direction = [ [@bs.as "asc"] | `Asc [@bs.as "desc"] | `Desc];
  module Classes = {
    type classesType =
      | Root(string)
      | Active(string)
      | Icon(string)
      | IconDirectionDesc(string)
      | IconDirectionAsc(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Active(_) => "active"
      | Icon(_) => "icon"
      | IconDirectionDesc(_) => "iconDirectionDesc"
      | IconDirectionAsc(_) => "iconDirectionAsc";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Active(className)
               | Icon(className)
               | IconDirectionDesc(className)
               | IconDirectionAsc(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableSortLabel"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~active: Js.boolean=?,
      ~className: string=?,
      ~direction: string=?,
      ~buttonRef: ReasonReact.reactElement=?,
      ~centerRipple: Js.boolean=?,
      ~component: 'union_y=?,
      ~disabled: Js.boolean=?,
      ~disableRipple: Js.boolean=?,
      ~focusRipple: Js.boolean=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: 'union_y=?,
      ~touchRippleProps: Js.t({..})=?,
      ~_type: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~direction: option(direction)=?,
        ~buttonRef: option(ReasonReact.reactElement)=?,
        ~centerRipple: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~focusRipple: option(bool)=?,
        ~keyboardFocusedClassName: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyboardFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onMouseDown: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseUp: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onTouchEnd: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchMove: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~onTouchStart: option(ReasonReact.Callback.t(ReactEventRe.Touch.t))=?,
        ~role: option(string)=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~touchRippleProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~active=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), active),
          ~className?,
          ~direction=?Js.Option.map([@bs] ((v) => directionToJs(v)), direction),
          ~buttonRef?,
          ~centerRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centerRipple),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~disableRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableRipple),
          ~focusRipple=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), focusRipple),
          ~keyboardFocusedClassName?,
          ~onBlur?,
          ~onClick?,
          ~onFocus?,
          ~onKeyboardFocus?,
          ~onKeyDown?,
          ~onKeyUp?,
          ~onMouseDown?,
          ~onMouseLeave?,
          ~onMouseUp?,
          ~onTouchEnd?,
          ~onTouchMove?,
          ~onTouchStart?,
          ~role?,
          ~tabIndex=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabIndex),
          ~touchRippleProps?,
          ~_type?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Table = {
  module Classes = {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/Table"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (~className: string=?, ~component: 'union_0=?, ~classes: Js.Dict.t(string)=?, unit) => _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Tabs = {
  [@bs.deriving jsConverter]
  type indicatorColor = [ [@bs.as "secondary"] | `Secondary [@bs.as "primary"] | `Primary];
  [@bs.deriving jsConverter]
  type scrollButtons = [ [@bs.as "auto"] | `Auto [@bs.as "on"] | `On [@bs.as "off"] | `Off];
  [@bs.deriving jsConverter]
  type textColor = [
    [@bs.as "secondary"] | `Secondary
    [@bs.as "primary"] | `Primary
    [@bs.as "inherit"] | `Inherit
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | FlexContainer(string)
      | Scroller(string)
      | Fixed(string)
      | Scrollable(string)
      | Centered(string)
      | ScrollButtonsAuto(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FlexContainer(_) => "flexContainer"
      | Scroller(_) => "scroller"
      | Fixed(_) => "fixed"
      | Scrollable(_) => "scrollable"
      | Centered(_) => "centered"
      | ScrollButtonsAuto(_) => "scrollButtonsAuto";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | FlexContainer(className)
               | Scroller(className)
               | Fixed(className)
               | Scrollable(className)
               | Centered(className)
               | ScrollButtonsAuto(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tabs/Tabs"] external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~action: ReasonReact.reactElement=?,
      ~buttonClassName: string=?,
      ~centered: Js.boolean=?,
      ~className: string=?,
      ~fullWidth: Js.boolean=?,
      ~indicatorClassName: string=?,
      ~indicatorColor: 'union_i=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~scrollable: Js.boolean=?,
      ~scrollButtons: string=?,
      ~tabScrollButton: 'union_c=?,
      ~textColor: string=?,
      ~theme: Js.t({..}),
      ~value: 'any_f=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~buttonClassName: option(string)=?,
        ~centered: option(bool)=?,
        ~className: option(string)=?,
        ~fullWidth: option(bool)=?,
        ~indicatorClassName: option(string)=?,
        ~indicatorColor: option([ | `String(string) | `Enum(indicatorColor)])=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~scrollable: option(bool)=?,
        ~scrollButtons: option(scrollButtons)=?,
        ~tabScrollButton: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~textColor: option(textColor)=?,
        ~theme: Js.t({..}),
        ~value: option('any_f)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~action?,
          ~buttonClassName?,
          ~centered=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), centered),
          ~className?,
          ~fullWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullWidth),
          ~indicatorClassName?,
          ~indicatorColor=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Enum(v) => unwrapValue(`String(indicatorColorToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              indicatorColor
            ),
          ~onChange?,
          ~scrollable=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), scrollable),
          ~scrollButtons=?Js.Option.map([@bs] ((v) => scrollButtonsToJs(v)), scrollButtons),
          ~tabScrollButton=?Js.Option.map([@bs] ((v) => unwrapValue(v)), tabScrollButton),
          ~textColor=?Js.Option.map([@bs] ((v) => textColorToJs(v)), textColor),
          ~theme,
          ~value?,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module TextField = {
  [@bs.deriving jsConverter]
  type margin = [ [@bs.as "none"] | `None [@bs.as "dense"] | `Dense [@bs.as "normal"] | `Normal];
  [@bs.module "material-ui/TextField/TextField"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~autoComplete: string=?,
      ~autoFocus: Js.boolean=?,
      ~className: string=?,
      ~defaultValue: string=?,
      ~disabled: Js.boolean=?,
      ~error: Js.boolean=?,
      ~formHelperTextProps: Js.t({..})=?,
      ~fullWidth: Js.boolean=?,
      ~helperText: ReasonReact.reactElement=?,
      ~helperTextClassName: string=?,
      ~id: string=?,
      ~inputLabelProps: Js.t({..})=?,
      ~inputProps2: Js.t({..})=?,
      ~inputProps: Js.t({..})=?,
      ~inputRef: ReasonReact.reactElement=?,
      ~label: ReasonReact.reactElement=?,
      ~labelClassName: string=?,
      ~margin: string=?,
      ~multiline: Js.boolean=?,
      ~name: string=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~placeholder: string=?,
      ~required: Js.boolean=?,
      ~rows: 'union_f=?,
      ~rowsMax: 'union_6=?,
      ~select: Js.boolean=?,
      ~selectProps: Js.t({..})=?,
      ~_type: string=?,
      ~value: 'union_l=?,
      ~component: 'union_d=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~autoComplete: option(string)=?,
        ~autoFocus: option(bool)=?,
        ~className: option(string)=?,
        ~defaultValue: option(string)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~formHelperTextProps: option(Js.t({..}))=?,
        ~fullWidth: option(bool)=?,
        ~helperText: option(ReasonReact.reactElement)=?,
        ~helperTextClassName: option(string)=?,
        ~id: option(string)=?,
        ~inputLabelProps: option(Js.t({..}))=?,
        ~inputProps2: option(Js.t({..}))=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~labelClassName: option(string)=?,
        ~margin: option(margin)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~placeholder: option(string)=?,
        ~required: option(bool)=?,
        ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~select: option(bool)=?,
        ~selectProps: option(Js.t({..}))=?,
        ~_type: option(string)=?,
        ~value:
           option(
             [
               | `String(string)
               | `Int(int)
               | `Float(float)
               | `StringArray(array(string))
               | `IntArray(array(int))
               | `FloatArray(array(float))
             ]
           )=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~autoComplete?,
          ~autoFocus=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), autoFocus),
          ~className?,
          ~defaultValue?,
          ~disabled=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disabled),
          ~error=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), error),
          ~formHelperTextProps?,
          ~fullWidth=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), fullWidth),
          ~helperText?,
          ~helperTextClassName?,
          ~id?,
          ~inputLabelProps?,
          ~inputProps2?,
          ~inputProps?,
          ~inputRef?,
          ~label?,
          ~labelClassName?,
          ~margin=?Js.Option.map([@bs] ((v) => marginToJs(v)), margin),
          ~multiline=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), multiline),
          ~name?,
          ~onChange?,
          ~placeholder?,
          ~required=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), required),
          ~rows=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rows),
          ~rowsMax=?Js.Option.map([@bs] ((v) => unwrapValue(v)), rowsMax),
          ~select=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), select),
          ~selectProps?,
          ~_type?,
          ~value=?Js.Option.map([@bs] ((v) => unwrapValue(v)), value),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~onBlur?,
          ~onFocus?,
          ()
        ),
      children
    );
};

module Toolbar = {
  module Classes = {
    type classesType =
      | Root(string)
      | Gutters(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Gutters(_) => "gutters";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Gutters(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Toolbar/Toolbar"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (~className: string=?, ~disableGutters: Js.boolean=?, ~classes: Js.Dict.t(string)=?, unit) => _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disableGutters: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disableGutters=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableGutters),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Tooltip = {
  [@bs.deriving jsConverter]
  type placement = [
    [@bs.as "bottom-end"] | `Bottom_End
    [@bs.as "bottom-start"] | `Bottom_Start
    [@bs.as "bottom"] | `Bottom
    [@bs.as "left-end"] | `Left_End
    [@bs.as "left-start"] | `Left_Start
    [@bs.as "left"] | `Left
    [@bs.as "right-end"] | `Right_End
    [@bs.as "right-start"] | `Right_Start
    [@bs.as "right"] | `Right
    [@bs.as "top-end"] | `Top_End
    [@bs.as "top-start"] | `Top_Start
    [@bs.as "top"] | `Top
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | Popper(string)
      | PopperClose(string)
      | Tooltip(string)
      | TooltipPlacementLeft(string)
      | TooltipPlacementRight(string)
      | TooltipPlacementTop(string)
      | TooltipPlacementBottom(string)
      | TooltipOpen(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Popper(_) => "popper"
      | PopperClose(_) => "popperClose"
      | Tooltip(_) => "tooltip"
      | TooltipPlacementLeft(_) => "tooltipPlacementLeft"
      | TooltipPlacementRight(_) => "tooltipPlacementRight"
      | TooltipPlacementTop(_) => "tooltipPlacementTop"
      | TooltipPlacementBottom(_) => "tooltipPlacementBottom"
      | TooltipOpen(_) => "tooltipOpen";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Popper(className)
               | PopperClose(className)
               | Tooltip(className)
               | TooltipPlacementLeft(className)
               | TooltipPlacementRight(className)
               | TooltipPlacementTop(className)
               | TooltipPlacementBottom(className)
               | TooltipOpen(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tooltip/Tooltip"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~className: string=?,
      ~disableTriggerFocus: Js.boolean=?,
      ~disableTriggerHover: Js.boolean=?,
      ~disableTriggerTouch: Js.boolean=?,
      ~enterDelay: 'number_0=?,
      ~id: string=?,
      ~leaveDelay: 'number_5=?,
      ~onClose: unit => unit=?,
      ~onOpen: unit => unit=?,
      ~_open: Js.boolean=?,
      ~placement: string=?,
      ~popperProps: Js.t({..})=?,
      ~theme: Js.t({..}),
      ~title: ReasonReact.reactElement,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className: option(string)=?,
        ~disableTriggerFocus: option(bool)=?,
        ~disableTriggerHover: option(bool)=?,
        ~disableTriggerTouch: option(bool)=?,
        ~enterDelay: option([ | `Int(int) | `Float(float)])=?,
        ~id: option(string)=?,
        ~leaveDelay: option([ | `Int(int) | `Float(float)])=?,
        ~onClose: option(unit => unit)=?,
        ~onOpen: option(unit => unit)=?,
        ~_open: option(bool)=?,
        ~placement: option(placement)=?,
        ~popperProps: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~title: ReasonReact.reactElement,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~disableTriggerFocus=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableTriggerFocus),
          ~disableTriggerHover=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableTriggerHover),
          ~disableTriggerTouch=?
            Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), disableTriggerTouch),
          ~enterDelay=?Js.Option.map([@bs] ((v) => unwrapValue(v)), enterDelay),
          ~id?,
          ~leaveDelay=?Js.Option.map([@bs] ((v) => unwrapValue(v)), leaveDelay),
          ~onClose?,
          ~onOpen?,
          ~_open=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _open),
          ~placement=?Js.Option.map([@bs] ((v) => placementToJs(v)), placement),
          ~popperProps?,
          ~theme,
          ~title,
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Typography = {
  [@bs.deriving jsConverter]
  type align = [
    [@bs.as "inherit"] | `Inherit
    [@bs.as "left"] | `Left
    [@bs.as "center"] | `Center
    [@bs.as "right"] | `Right
    [@bs.as "justify"] | `Justify
  ];
  [@bs.deriving jsConverter]
  type color = [
    [@bs.as "inherit"] | `Inherit
    [@bs.as "primary"] | `Primary
    [@bs.as "textSecondary"] | `TextSecondary
    [@bs.as "secondary"] | `Secondary
    [@bs.as "error"] | `Error
    [@bs.as "default"] | `Default
  ];
  [@bs.deriving jsConverter]
  type variant = [
    [@bs.as "display4"] | `Display4
    [@bs.as "display3"] | `Display3
    [@bs.as "display2"] | `Display2
    [@bs.as "display1"] | `Display1
    [@bs.as "headline"] | `Headline
    [@bs.as "title"] | `Title
    [@bs.as "subheading"] | `Subheading
    [@bs.as "body2"] | `Body2
    [@bs.as "body1"] | `Body1
    [@bs.as "caption"] | `Caption
    [@bs.as "button"] | `Button
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | Display4(string)
      | Display3(string)
      | Display2(string)
      | Display1(string)
      | Headline(string)
      | Title(string)
      | Subheading(string)
      | Body2(string)
      | Body1(string)
      | Caption(string)
      | Button(string)
      | AlignLeft(string)
      | AlignCenter(string)
      | AlignRight(string)
      | AlignJustify(string)
      | NoWrap(string)
      | GutterBottom(string)
      | Paragraph(string)
      | ColorInherit(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | ColorTextSecondary(string)
      | ColorError(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Display4(_) => "display4"
      | Display3(_) => "display3"
      | Display2(_) => "display2"
      | Display1(_) => "display1"
      | Headline(_) => "headline"
      | Title(_) => "title"
      | Subheading(_) => "subheading"
      | Body2(_) => "body2"
      | Body1(_) => "body1"
      | Caption(_) => "caption"
      | Button(_) => "button"
      | AlignLeft(_) => "alignLeft"
      | AlignCenter(_) => "alignCenter"
      | AlignRight(_) => "alignRight"
      | AlignJustify(_) => "alignJustify"
      | NoWrap(_) => "noWrap"
      | GutterBottom(_) => "gutterBottom"
      | Paragraph(_) => "paragraph"
      | ColorInherit(_) => "colorInherit"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | ColorTextSecondary(_) => "colorTextSecondary"
      | ColorError(_) => "colorError";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Display4(className)
               | Display3(className)
               | Display2(className)
               | Display1(className)
               | Headline(className)
               | Title(className)
               | Subheading(className)
               | Body2(className)
               | Body1(className)
               | Caption(className)
               | Button(className)
               | AlignLeft(className)
               | AlignCenter(className)
               | AlignRight(className)
               | AlignJustify(className)
               | NoWrap(className)
               | GutterBottom(className)
               | Paragraph(className)
               | ColorInherit(className)
               | ColorPrimary(className)
               | ColorSecondary(className)
               | ColorTextSecondary(className)
               | ColorError(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj;
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Typography/Typography"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~align: string=?,
      ~className: string=?,
      ~color: string=?,
      ~component: 'union_u=?,
      ~gutterBottom: Js.boolean=?,
      ~headlineMapping: Js.t({..})=?,
      ~noWrap: Js.boolean=?,
      ~paragraph: Js.boolean=?,
      ~variant: string=?,
      ~classes: Js.Dict.t(string)=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~align: option(align)=?,
        ~className: option(string)=?,
        ~color: option(color)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~gutterBottom: option(bool)=?,
        ~headlineMapping: option(Js.t({..}))=?,
        ~noWrap: option(bool)=?,
        ~paragraph: option(bool)=?,
        ~variant: option(variant)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~align=?Js.Option.map([@bs] ((v) => alignToJs(v)), align),
          ~className?,
          ~color=?Js.Option.map([@bs] ((v) => colorToJs(v)), color),
          ~component=?Js.Option.map([@bs] ((v) => unwrapValue(v)), component),
          ~gutterBottom=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), gutterBottom),
          ~headlineMapping?,
          ~noWrap=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), noWrap),
          ~paragraph=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), paragraph),
          ~variant=?Js.Option.map([@bs] ((v) => variantToJs(v)), variant),
          ~classes=?Js.Option.map([@bs] ((v) => Classes.to_obj(v)), classes),
          ()
        ),
      children
    );
};

module Zoom = {
  [@bs.deriving jsConverter]
  type timeoutShape = {
    enter: int,
    exit: int
  };
  [@bs.module "material-ui/transitions/Zoom"]
  external reactClass : ReasonReact.reactClass = "default";
  [@bs.obj]
  external makeProps :
    (
      ~_in: Js.boolean=?,
      ~onEnter: unit => unit=?,
      ~onExit: unit => unit=?,
      ~style: Js.t({..})=?,
      ~theme: Js.t({..}),
      ~timeout: 'union_r=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~_in: option(bool)=?,
        ~onEnter: option(unit => unit)=?,
        ~onExit: option(unit => unit)=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~_in=?Js.Option.map([@bs] ((v) => Js.Boolean.to_js_boolean(v)), _in),
          ~onEnter?,
          ~onExit?,
          ~style?,
          ~theme,
          ~timeout=?
            Js.Option.map(
              [@bs]
              (
                (v) =>
                  switch v {
                  | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
                  | v => unwrapValue(v)
                  }
              ),
              timeout
            ),
          ()
        ),
      children
    );
};
