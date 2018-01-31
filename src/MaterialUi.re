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

let optionMap = (fn, option) =>
  switch option {
  | Some(value) => Some(fn(value))
  | None => None
  };

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
      type t = {
        easeInOut: string,
        easeOut: string,
        easeIn: string,
        sharp: string
      };
    };
    module Duration = {
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
};

module WithStyles = {
  let component = ReasonReact.statelessComponent("WithStyles");
  let make = (~render, ~classes: Js.t({..}), _children) => {
    ...component,
    render: (_self) => render(classes)
  };
  type withStylesComponent('a) = [@bs] ('a => ReasonReact.reactClass);
  [@bs.module "material-ui/styles"]
  external withStylesExt : 'styles => withStylesComponent('component) =
    "withStyles";
  let creteStylesWrapper = (styles) => withStylesExt(styles);
  let make =
      (
        ~styles: option(Js.t({..}))=?,
        ~stylesWithTheme: option((MuiTheme.t => Js.t({..})))=?,
        ~render,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass={
        let wrapper =
          creteStylesWrapper(
            switch styles {
            | Some(styles) => styles
            | None =>
              switch stylesWithTheme {
              | Some(stylesWithTheme) =>
                toJsUnsafe((theme) => stylesWithTheme(MuiTheme.tFromJs(theme)))
              | None => Js.Obj.empty()
              }
            }
          );
        [@bs]
        wrapper(
          ReasonReact.wrapReasonForJs(
            ~component,
            (jsProps) => make(~render=jsProps##render, ~classes=jsProps##classes, [||])
          )
        )
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
    [@bs.module "material-ui/colors/deepPurple"] external deepPurpleExt : Js.Dict.t(string) =
      "default";
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
    [@bs.module "material-ui/colors/lightBlue"] external lightBlueExt : Js.Dict.t(string) =
      "default";
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
    [@bs.module "material-ui/colors/lightGreen"] external lightGreenExt : Js.Dict.t(string) =
      "default";
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
    [@bs.module "material-ui/colors/deepOrange"] external deepOrangeExt : Js.Dict.t(string) =
      "default";
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
    [@bs.module "material-ui/colors/blueGrey"] external blueGreyExt : Js.Dict.t(string) =
      "default";
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
  type color_y = [
    [@bs.as "inherit"] | `Inherit
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
    [@bs.as "default"] | `Default
  ];
  [@bs.deriving jsConverter]
  type position_b = [
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/AppBar/AppBar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color_y)=?,
        ~position: option(position_b)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_yToJs, color)),
        "position": Js.Nullable.from_opt(optionMap(position_bToJs, position)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Avatar/Avatar"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "alt": Js.Nullable.from_opt(alt),
        "childrenClassName": Js.Nullable.from_opt(childrenClassName),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "imgProps": Js.Nullable.from_opt(imgProps),
        "sizes": Js.Nullable.from_opt(sizes),
        "src": Js.Nullable.from_opt(src),
        "srcSet": Js.Nullable.from_opt(srcSet),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Modal/Backdrop"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~invisible: option(bool)=?,
        ~open_: bool,
        ~transitionDuration:
           option([ | `Int(int) | `Float(float) | `Object(transitionDurationShape)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "invisible": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, invisible)),
        "open": Js.Boolean.to_js_boolean(open_),
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
              | v => unwrapValue(v),
              transitionDuration
            )
          ),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Badge = {
  [@bs.deriving jsConverter]
  type color_i = [
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Badge/Badge"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~badgeContent: ReasonReact.reactElement,
        ~className: option(string)=?,
        ~color: option(color_i)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "badgeContent": badgeContent,
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_iToJs, color)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
      | SelectedLabel(string)
      | HiddenLabel(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Selected(_) => "selected"
      | SelectedIconOnly(_) => "selectedIconOnly"
      | Wrapper(_) => "wrapper"
      | Label(_) => "label"
      | SelectedLabel(_) => "selectedLabel"
      | HiddenLabel(_) => "hiddenLabel";
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
               | HiddenLabel(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/BottomNavigation/BottomNavigationAction"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~selected: option(bool)=?,
        ~showLabel: option(bool)=?,
        ~value: option('any_g)=?,
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
        ~type_: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "icon": Js.Nullable.from_opt(icon),
        "label": Js.Nullable.from_opt(label),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "showLabel": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, showLabel)),
        "value": Js.Nullable.from_opt(value),
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": Js.Nullable.from_opt(type_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/BottomNavigation/BottomNavigation"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~showLabels: option(bool)=?,
        ~value: option('any_x)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onChange": Js.Nullable.from_opt(onChange),
        "showLabels": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, showLabels)),
        "value": Js.Nullable.from_opt(value),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ButtonBase/ButtonBase"] external reactClass : ReasonReact.reactClass =
    "default";
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
        ~type_: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClick": Js.Nullable.from_opt(onClick),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": Js.Nullable.from_opt(type_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Button = {
  [@bs.deriving jsConverter]
  type color_7 = [
    [@bs.as "default"] | `Default
    [@bs.as "inherit"] | `Inherit
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
  ];
  [@bs.deriving jsConverter]
  type size_8 = [ [@bs.as "small"] | `Small [@bs.as "medium"] | `Medium [@bs.as "large"] | `Large];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Button/Button"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color_7)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~disableFocusRipple: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~fab: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~href: option(string)=?,
        ~mini: option(bool)=?,
        ~raised: option(bool)=?,
        ~size: option(size_8)=?,
        ~type_: option(string)=?,
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
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_7ToJs, color)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableFocusRipple":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableFocusRipple)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "fab": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fab)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "href": Js.Nullable.from_opt(href),
        "mini": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, mini)),
        "raised": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, raised)),
        "size": Js.Nullable.from_opt(optionMap(size_8ToJs, size)),
        "type": Js.Nullable.from_opt(type_),
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClick": Js.Nullable.from_opt(onClick),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardActions"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~disableActionSpacing: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableActionSpacing":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableActionSpacing)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardContent"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardHeader"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "action": Js.Nullable.from_opt(action),
        "avatar": Js.Nullable.from_opt(avatar),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "subheader": Js.Nullable.from_opt(subheader),
        "title": Js.Nullable.from_opt(title),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module CardMedia = {
  module Classes = {
    type classesType =
      | Root(string)
      | RootMedia(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | RootMedia(_) => "rootMedia";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | RootMedia(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Card/CardMedia"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "image": Js.Nullable.from_opt(image),
        "src": Js.Nullable.from_opt(src),
        "style": Js.Nullable.from_opt(style),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Card = {
  [@bs.module "material-ui/Card/Card"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~raised: option(bool)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "raised": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, raised)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square))
      },
      children
    );
};

module Checkbox = {
  module Classes = {
    type classesType =
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Default(_) => "default"
      | Checked(_) => "checked"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Default(className)
               | Checked(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Checkbox/Checkbox"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~defaultChecked: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~indeterminate: option(bool)=?,
        ~indeterminateIcon: option(ReasonReact.reactElement)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~inputType: option(string)=?,
        ~name: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~value: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.from_opt(optionMap(unwrapValue, checked)),
        "checkedIcon": Js.Nullable.from_opt(checkedIcon),
        "className": Js.Nullable.from_opt(className),
        "defaultChecked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, defaultChecked)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "icon": Js.Nullable.from_opt(icon),
        "indeterminate": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, indeterminate)),
        "indeterminateIcon": Js.Nullable.from_opt(indeterminateIcon),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "inputType": Js.Nullable.from_opt(inputType),
        "name": Js.Nullable.from_opt(name),
        "onChange": Js.Nullable.from_opt(onChange),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "value": Js.Nullable.from_opt(value),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Chip/Chip"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~avatar: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~deleteIcon: option(ReasonReact.reactElement)=?,
        ~label: option(ReasonReact.reactElement)=?,
        ~onClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onDelete: option((unit => unit))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "avatar": Js.Nullable.from_opt(avatar),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "deleteIcon": Js.Nullable.from_opt(deleteIcon),
        "label": Js.Nullable.from_opt(label),
        "onClick": Js.Nullable.from_opt(onClick),
        "onDelete": Js.Nullable.from_opt(onDelete),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module CircularProgress = {
  [@bs.deriving jsConverter]
  type color_h = [
    [@bs.as "primary"] | `Primary
    [@bs.as "secondary"] | `Secondary
    [@bs.as "inherit"] | `Inherit
  ];
  [@bs.deriving jsConverter]
  type mode_5 = [ [@bs.as "determinate"] | `Determinate [@bs.as "indeterminate"] | `Indeterminate];
  module Classes = {
    type classesType =
      | Root(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | SvgIndeterminate(string)
      | SvgDeterminate(string)
      | Circle(string)
      | CircleIndeterminate(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | SvgIndeterminate(_) => "svgIndeterminate"
      | SvgDeterminate(_) => "svgDeterminate"
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
               | SvgIndeterminate(className)
               | SvgDeterminate(className)
               | Circle(className)
               | CircleIndeterminate(className) =>
                 Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Progress/CircularProgress"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color_h)=?,
        ~max: option([ | `Int(int) | `Float(float)])=?,
        ~min: option([ | `Int(int) | `Float(float)])=?,
        ~mode: option(mode_5)=?,
        ~size: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~style: option(Js.t({..}))=?,
        ~thickness: option([ | `Int(int) | `Float(float)])=?,
        ~value: option([ | `Int(int) | `Float(float)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_hToJs, color)),
        "max": Js.Nullable.from_opt(optionMap(unwrapValue, max)),
        "min": Js.Nullable.from_opt(optionMap(unwrapValue, min)),
        "mode": Js.Nullable.from_opt(optionMap(mode_5ToJs, mode)),
        "size": Js.Nullable.from_opt(optionMap(unwrapValue, size)),
        "style": Js.Nullable.from_opt(style),
        "thickness": Js.Nullable.from_opt(optionMap(unwrapValue, thickness)),
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module ClickAwayListener = {
  [@bs.module "material-ui/utils/ClickAwayListener"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~onClickAway: ReasonReact.Callback.t(ReactEventRe.Mouse.t), children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props={"onClickAway": onClickAway}, children);
};

module Collapse = {
  [@bs.deriving jsConverter]
  type timeoutShape = {
    enter: int,
    exit: int
  };
  [@bs.deriving jsConverter]
  type timeout_4 = [ [@bs.as "auto"] | `Auto];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/transitions/Collapse"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~appear: option(bool)=?,
        ~className: option(string)=?,
        ~collapsedHeight: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~in_: option(bool)=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntered: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onExit: option((unit => unit))=?,
        ~onExiting: option((unit => unit))=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape) | `Enum(timeout_4)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "appear": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, appear)),
        "className": Js.Nullable.from_opt(className),
        "collapsedHeight": Js.Nullable.from_opt(collapsedHeight),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "in": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, in_)),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onExit": Js.Nullable.from_opt(onExit),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "style": Js.Nullable.from_opt(style),
        "theme": theme,
        "timeout":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(timeout_4ToJs(v)))
              | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
              | v => unwrapValue(v),
              timeout
            )
          ),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module DialogActions = {
  module Classes = {
    type classesType =
      | Root(string)
      | Action(string)
      | Button(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Action(_) => "action"
      | Button(_) => "button";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Action(className)
               | Button(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogActions"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogContentText"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogContent"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/DialogTitle"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~disableTypography: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableTypography":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTypography)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Dialog = {
  [@bs.deriving jsConverter]
  type maxWidth_q = [
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
      | FullWidth(string)
      | FullScreen(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Paper(_) => "paper"
      | PaperWidthXs(_) => "paperWidthXs"
      | PaperWidthSm(_) => "paperWidthSm"
      | PaperWidthMd(_) => "paperWidthMd"
      | FullWidth(_) => "fullWidth"
      | FullScreen(_) => "fullScreen";
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
               | FullWidth(className)
               | FullScreen(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Dialog/Dialog"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~disableBackdropClick: option(bool)=?,
        ~disableEscapeKeyDown: option(bool)=?,
        ~fullScreen: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~maxWidth: option(maxWidth_q)=?,
        ~onBackdropClick: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onClose: option((unit => unit))=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntered: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onEscapeKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onExit: option((unit => unit))=?,
        ~onExited: option((unit => unit))=?,
        ~onExiting: option((unit => unit))=?,
        ~open_: bool,
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
        ~onRendered: option((unit => unit))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableBackdropClick":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableBackdropClick)),
        "disableEscapeKeyDown":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableEscapeKeyDown)),
        "fullScreen": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullScreen)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "maxWidth": Js.Nullable.from_opt(optionMap(maxWidth_qToJs, maxWidth)),
        "onBackdropClick": Js.Nullable.from_opt(onBackdropClick),
        "onClose": Js.Nullable.from_opt(onClose),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onEscapeKeyDown": Js.Nullable.from_opt(onEscapeKeyDown),
        "onExit": Js.Nullable.from_opt(onExit),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "open": Js.Boolean.to_js_boolean(open_),
        "PaperProps": Js.Nullable.from_opt(paperProps),
        "transition": Js.Nullable.from_opt(optionMap(unwrapValue, transition)),
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
              | v => unwrapValue(v),
              transitionDuration
            )
          ),
        "BackdropComponent": Js.Nullable.from_opt(optionMap(unwrapValue, backdropComponent)),
        "BackdropProps": Js.Nullable.from_opt(backdropProps),
        "container": Js.Nullable.from_opt(optionMap(unwrapValue, container)),
        "disableAutoFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableAutoFocus)),
        "disableEnforceFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableEnforceFocus)),
        "disableRestoreFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRestoreFocus)),
        "hideBackdrop": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, hideBackdrop)),
        "keepMounted": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, keepMounted)),
        "manager": Js.Nullable.from_opt(manager),
        "onRendered": Js.Nullable.from_opt(onRendered),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Divider = {
  module Classes = {
    type classesType =
      | Root(string)
      | Inset(string)
      | Default(string)
      | Light(string)
      | Absolute(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Inset(_) => "inset"
      | Default(_) => "default"
      | Light(_) => "light"
      | Absolute(_) => "absolute";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Inset(className)
               | Default(className)
               | Light(className)
               | Absolute(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Divider/Divider"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "absolute": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, absolute)),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "inset": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inset)),
        "light": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, light)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Drawer = {
  [@bs.deriving jsConverter]
  type anchor_o = [
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
  type type__p = [
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Drawer/Drawer"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~anchor: option(anchor_o)=?,
        ~className: option(string)=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~modalProps: option(Js.t({..}))=?,
        ~onClose: option((unit => unit))=?,
        ~open_: option(bool)=?,
        ~slideProps: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~transitionDuration:
           option([ | `Int(int) | `Float(float) | `Object(transitionDurationShape)])=?,
        ~type_: option(type__p)=?,
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
        ~onRendered: option((unit => unit))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "anchor": Js.Nullable.from_opt(optionMap(anchor_oToJs, anchor)),
        "className": Js.Nullable.from_opt(className),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "ModalProps": Js.Nullable.from_opt(modalProps),
        "onClose": Js.Nullable.from_opt(onClose),
        "open": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, open_)),
        "SlideProps": Js.Nullable.from_opt(slideProps),
        "theme": theme,
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
              | v => unwrapValue(v),
              transitionDuration
            )
          ),
        "type": Js.Nullable.from_opt(optionMap(type__pToJs, type_)),
        "BackdropComponent": Js.Nullable.from_opt(optionMap(unwrapValue, backdropComponent)),
        "BackdropProps": Js.Nullable.from_opt(backdropProps),
        "container": Js.Nullable.from_opt(optionMap(unwrapValue, container)),
        "disableAutoFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableAutoFocus)),
        "disableBackdropClick":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableBackdropClick)),
        "disableEnforceFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableEnforceFocus)),
        "disableEscapeKeyDown":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableEscapeKeyDown)),
        "disableRestoreFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRestoreFocus)),
        "hideBackdrop": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, hideBackdrop)),
        "keepMounted": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, keepMounted)),
        "manager": Js.Nullable.from_opt(manager),
        "onBackdropClick": Js.Nullable.from_opt(onBackdropClick),
        "onEscapeKeyDown": Js.Nullable.from_opt(onEscapeKeyDown),
        "onRendered": Js.Nullable.from_opt(onRendered),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ExpansionPanel/ExpansionPanelActions"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ExpansionPanel/ExpansionPanelDetails"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ExpansionPanel/ExpansionPanelSummary"]
  external reactClass : ReasonReact.reactClass =
    "default";
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
        ~type_: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "expanded": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, expanded)),
        "expandIcon": Js.Nullable.from_opt(expandIcon),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": Js.Nullable.from_opt(type_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/ExpansionPanel/ExpansionPanel"]
  external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "CollapseProps": Js.Nullable.from_opt(collapseProps),
        "defaultExpanded":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, defaultExpanded)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "expanded": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, expanded)),
        "onChange": Js.Nullable.from_opt(onChange),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Fade = {
  [@bs.deriving jsConverter]
  type timeoutShape = {
    enter: int,
    exit: int
  };
  [@bs.module "material-ui/transitions/Fade"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~appear: option(bool)=?,
        ~in_: option(bool)=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onExit: option((unit => unit))=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "appear": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, appear)),
        "in": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, in_)),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onExit": Js.Nullable.from_opt(onExit),
        "style": Js.Nullable.from_opt(style),
        "theme": theme,
        "timeout":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
              | v => unwrapValue(v),
              timeout
            )
          )
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormControlLabel"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "checked": Js.Nullable.from_opt(optionMap(unwrapValue, checked)),
        "className": Js.Nullable.from_opt(className),
        "control": Js.Nullable.from_opt(control),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "label": Js.Nullable.from_opt(label),
        "name": Js.Nullable.from_opt(name),
        "onChange": Js.Nullable.from_opt(onChange),
        "value": Js.Nullable.from_opt(value),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module FormControl = {
  [@bs.deriving jsConverter]
  type margin_r = [ [@bs.as "none"] | `None [@bs.as "dense"] | `Dense [@bs.as "normal"] | `Normal];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormControl"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~fullWidth: option(bool)=?,
        ~margin: option(margin_r)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~required: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "margin": Js.Nullable.from_opt(optionMap(margin_rToJs, margin)),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormGroup"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (~className: option(string)=?, ~row: option(bool)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "row": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, row)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module FormHelperText = {
  [@bs.deriving jsConverter]
  type margin_b = [ [@bs.as "dense"] | `Dense];
  module Classes = {
    type classesType =
      | Root(string)
      | Dense(string)
      | Error(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Dense(_) => "dense"
      | Error(_) => "error"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Dense(className)
               | Error(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormHelperText"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~margin: option(margin_b)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "margin": Js.Nullable.from_opt(optionMap(margin_bToJs, margin)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module FormLabel = {
  module Classes = {
    type classesType =
      | Root(string)
      | Focused(string)
      | Error(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Focused(_) => "focused"
      | Error(_) => "error"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Focused(className)
               | Error(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Form/FormLabel"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "focused": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focused)),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module GridListTileBar = {
  [@bs.deriving jsConverter]
  type actionPosition_0 = [ [@bs.as "left"] | `Left [@bs.as "right"] | `Right];
  [@bs.deriving jsConverter]
  type titlePosition_x = [ [@bs.as "top"] | `Top [@bs.as "bottom"] | `Bottom];
  module Classes = {
    type classesType =
      | Root(string)
      | RootBottom(string)
      | RootTop(string)
      | RootWithSubtitle(string)
      | TitleWrap(string)
      | TitleWrapActionLeft(string)
      | TitleWrapActionRight(string)
      | Title(string)
      | Subtitle(string)
      | ActionIconPositionLeft(string)
      | ChildImg(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | RootBottom(_) => "rootBottom"
      | RootTop(_) => "rootTop"
      | RootWithSubtitle(_) => "rootWithSubtitle"
      | TitleWrap(_) => "titleWrap"
      | TitleWrapActionLeft(_) => "titleWrapActionLeft"
      | TitleWrapActionRight(_) => "titleWrapActionRight"
      | Title(_) => "title"
      | Subtitle(_) => "subtitle"
      | ActionIconPositionLeft(_) => "actionIconPositionLeft"
      | ChildImg(_) => "childImg";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | RootBottom(className)
               | RootTop(className)
               | RootWithSubtitle(className)
               | TitleWrap(className)
               | TitleWrapActionLeft(className)
               | TitleWrapActionRight(className)
               | Title(className)
               | Subtitle(className)
               | ActionIconPositionLeft(className)
               | ChildImg(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridListTileBar"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~actionIcon: option(ReasonReact.reactElement)=?,
        ~actionPosition: option(actionPosition_0)=?,
        ~className: option(string)=?,
        ~subtitle: option(ReasonReact.reactElement)=?,
        ~title: option(ReasonReact.reactElement)=?,
        ~titlePosition: option(titlePosition_x)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "actionIcon": Js.Nullable.from_opt(actionIcon),
        "actionPosition": Js.Nullable.from_opt(optionMap(actionPosition_0ToJs, actionPosition)),
        "className": Js.Nullable.from_opt(className),
        "subtitle": Js.Nullable.from_opt(subtitle),
        "title": Js.Nullable.from_opt(title),
        "titlePosition": Js.Nullable.from_opt(optionMap(titlePosition_xToJs, titlePosition)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridListTile"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "cols": Js.Nullable.from_opt(optionMap(unwrapValue, cols)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "rows": Js.Nullable.from_opt(optionMap(unwrapValue, rows)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module GridList = {
  [@bs.deriving jsConverter]
  type cellHeight_z = [ [@bs.as "auto"] | `Auto];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/GridList/GridList"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~cellHeight: option([ | `Int(int) | `Float(float) | `Enum(cellHeight_z)])=?,
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
      ~props={
        "cellHeight":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(cellHeight_zToJs(v)))
              | v => unwrapValue(v),
              cellHeight
            )
          ),
        "className": Js.Nullable.from_opt(className),
        "cols": Js.Nullable.from_opt(optionMap(unwrapValue, cols)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "spacing": Js.Nullable.from_opt(optionMap(unwrapValue, spacing)),
        "style": Js.Nullable.from_opt(style),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Grid = {
  [@bs.deriving jsConverter]
  type alignContent_p = [
    [@bs.as "stretch"] | `Stretch
    [@bs.as "center"] | `Center
    [@bs.as "flex-start"] | `Flex_Start
    [@bs.as "flex-end"] | `Flex_End
    [@bs.as "space-between"] | `Space_Between
    [@bs.as "space-around"] | `Space_Around
  ];
  [@bs.deriving jsConverter]
  type alignItems_2 = [
    [@bs.as "flex-start"] | `Flex_Start
    [@bs.as "center"] | `Center
    [@bs.as "flex-end"] | `Flex_End
    [@bs.as "stretch"] | `Stretch
    [@bs.as "baseline"] | `Baseline
  ];
  [@bs.deriving jsConverter]
  type direction_v = [
    [@bs.as "row"] | `Row
    [@bs.as "row-reverse"] | `Row_Reverse
    [@bs.as "column"] | `Column
    [@bs.as "column-reverse"] | `Column_Reverse
  ];
  [@bs.deriving jsConverter]
  type justify_g = [
    [@bs.as "flex-start"] | `Flex_Start
    [@bs.as "center"] | `Center
    [@bs.as "flex-end"] | `Flex_End
    [@bs.as "space-between"] | `Space_Between
    [@bs.as "space-around"] | `Space_Around
  ];
  [@bs.deriving jsConverter]
  type lg_d =
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
  type md_c =
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
  type sm_m =
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
  type spacing_i =
    [@bs.as 0] | V0
    [@bs.as 8] | V8
    [@bs.as 16] | V16
    [@bs.as 24] | V24
    [@bs.as 40] | V40;
  [@bs.deriving jsConverter]
  type wrap_1 = [
    [@bs.as "nowrap"] | `Nowrap
    [@bs.as "wrap"] | `Wrap
    [@bs.as "wrap-reverse"] | `Wrap_Reverse
  ];
  [@bs.deriving jsConverter]
  type xl_d =
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
  type xs_n =
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Grid/Grid"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~alignContent: option(alignContent_p)=?,
        ~alignItems: option(alignItems_2)=?,
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~container: option(bool)=?,
        ~direction: option(direction_v)=?,
        ~hidden: option(Js.t({..}))=?,
        ~item: option(bool)=?,
        ~justify: option(justify_g)=?,
        ~lg: option(lg_d)=?,
        ~md: option(md_c)=?,
        ~sm: option(sm_m)=?,
        ~spacing: option(spacing_i)=?,
        ~wrap: option(wrap_1)=?,
        ~xl: option(xl_d)=?,
        ~xs: option(xs_n)=?,
        ~zeroMinWidth: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "alignContent": Js.Nullable.from_opt(optionMap(alignContent_pToJs, alignContent)),
        "alignItems": Js.Nullable.from_opt(optionMap(alignItems_2ToJs, alignItems)),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "container": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, container)),
        "direction": Js.Nullable.from_opt(optionMap(direction_vToJs, direction)),
        "hidden": Js.Nullable.from_opt(hidden),
        "item": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, item)),
        "justify": Js.Nullable.from_opt(optionMap(justify_gToJs, justify)),
        "lg": Js.Nullable.from_opt(optionMap(lg_dToJs, lg)),
        "md": Js.Nullable.from_opt(optionMap(md_cToJs, md)),
        "sm": Js.Nullable.from_opt(optionMap(sm_mToJs, sm)),
        "spacing": Js.Nullable.from_opt(optionMap(spacing_iToJs, spacing)),
        "wrap": Js.Nullable.from_opt(optionMap(wrap_1ToJs, wrap)),
        "xl": Js.Nullable.from_opt(optionMap(xl_dToJs, xl)),
        "xs": Js.Nullable.from_opt(optionMap(xs_nToJs, xs)),
        "zeroMinWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, zeroMinWidth)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
  type timeout_3 = [ [@bs.as "auto"] | `Auto];
  [@bs.deriving jsConverter]
  type transitionClassesShape = {
    appear: string,
    appearActive: string,
    enter: string,
    enterActive: string,
    exit: string,
    exitActive: string
  };
  [@bs.module "material-ui/transitions/Grow"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~appear: option(bool)=?,
        ~in_: option(bool)=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntered: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onExit: option((unit => unit))=?,
        ~onExited: option((unit => unit))=?,
        ~onExiting: option((unit => unit))=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape) | `Enum(timeout_3)])=?,
        ~transitionClasses: option(transitionClassesShape)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "appear": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, appear)),
        "in": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, in_)),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onExit": Js.Nullable.from_opt(onExit),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "style": Js.Nullable.from_opt(style),
        "theme": theme,
        "timeout":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(timeout_3ToJs(v)))
              | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
              | v => unwrapValue(v),
              timeout
            )
          ),
        "transitionClasses":
          Js.Nullable.from_opt(optionMap(transitionClassesShapeToJs, transitionClasses))
      },
      children
    );
};

module Hidden = {
  [@bs.deriving jsConverter]
  type implementation_b = [ [@bs.as "js"] | `Js [@bs.as "css"] | `Css];
  [@bs.deriving jsConverter]
  type initialWidth_x = [
    [@bs.as "xs"] | `Xs
    [@bs.as "sm"] | `Sm
    [@bs.as "md"] | `Md
    [@bs.as "lg"] | `Lg
    [@bs.as "xl"] | `Xl
  ];
  [@bs.deriving jsConverter]
  type only_f = [
    [@bs.as "xs"] | `Xs
    [@bs.as "sm"] | `Sm
    [@bs.as "md"] | `Md
    [@bs.as "lg"] | `Lg
    [@bs.as "xl"] | `Xl
  ];
  [@bs.deriving jsConverter]
  type only_2 = [
    [@bs.as "xs"] | `Xs
    [@bs.as "sm"] | `Sm
    [@bs.as "md"] | `Md
    [@bs.as "lg"] | `Lg
    [@bs.as "xl"] | `Xl
  ];
  [@bs.module "material-ui/Hidden/Hidden"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~implementation: option(implementation_b)=?,
        ~initialWidth: option(initialWidth_x)=?,
        ~lgDown: option(bool)=?,
        ~lgUp: option(bool)=?,
        ~mdDown: option(bool)=?,
        ~mdUp: option(bool)=?,
        ~only: option([ | `Enum(only_f) | `EnumArray(array(only_2))])=?,
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "implementation": Js.Nullable.from_opt(optionMap(implementation_bToJs, implementation)),
        "initialWidth": Js.Nullable.from_opt(optionMap(initialWidth_xToJs, initialWidth)),
        "lgDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, lgDown)),
        "lgUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, lgUp)),
        "mdDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, mdDown)),
        "mdUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, mdUp)),
        "only":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(only_fToJs(v)))
              | `EnumArray(v) => unwrapValue(`Element(Array.map(only_2ToJs, v))),
              only
            )
          ),
        "smDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, smDown)),
        "smUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, smUp)),
        "xlDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, xlDown)),
        "xlUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, xlUp)),
        "xsDown": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, xsDown)),
        "xsUp": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, xsUp))
      },
      children
    );
};

module IconButton = {
  [@bs.deriving jsConverter]
  type color_j = [
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/IconButton/IconButton"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color_j)=?,
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
        ~type_: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_jToJs, color)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClick": Js.Nullable.from_opt(onClick),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": Js.Nullable.from_opt(type_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Icon = {
  [@bs.deriving jsConverter]
  type color_o = [
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
      | ColorError(string)
      | FontSize(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | ColorAction(_) => "colorAction"
      | ColorDisabled(_) => "colorDisabled"
      | ColorError(_) => "colorError"
      | FontSize(_) => "fontSize";
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
               | ColorError(className)
               | FontSize(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Icon/Icon"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color_o)=?,
        ~fontSize: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_oToJs, color)),
        "fontSize": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fontSize)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module InputAdornment = {
  [@bs.deriving jsConverter]
  type position_e = [ [@bs.as "start"] | `Start [@bs.as "end"] | `End];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/InputAdornment"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disableTypography: option(bool)=?,
        ~position: option(position_e)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disableTypography":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTypography)),
        "position": Js.Nullable.from_opt(optionMap(position_eToJs, position)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module InputLabel = {
  [@bs.deriving jsConverter]
  type margin_t = [ [@bs.as "dense"] | `Dense];
  module Classes = {
    type classesType =
      | Root(string)
      | FormControl(string)
      | LabelDense(string)
      | Shrink(string)
      | Animated(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FormControl(_) => "formControl"
      | LabelDense(_) => "labelDense"
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
               | LabelDense(className)
               | Shrink(className)
               | Animated(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/InputLabel"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~disableAnimation: option(bool)=?,
        ~disabled: option(bool)=?,
        ~error: option(bool)=?,
        ~focused: option(bool)=?,
        ~formControlClasses: option(Js.t({..}))=?,
        ~margin: option(margin_t)=?,
        ~required: option(bool)=?,
        ~shrink: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableAnimation":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableAnimation)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "focused": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focused)),
        "FormControlClasses": Js.Nullable.from_opt(formControlClasses),
        "margin": Js.Nullable.from_opt(optionMap(margin_tToJs, margin)),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "shrink": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, shrink)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Input = {
  [@bs.deriving jsConverter]
  type margin_e = [ [@bs.as "dense"] | `Dense [@bs.as "none"] | `None];
  module Classes = {
    type classesType =
      | Root(string)
      | FormControl(string)
      | Inkbar(string)
      | Error(string)
      | Focused(string)
      | Disabled(string)
      | Underline(string)
      | Multiline(string)
      | FullWidth(string)
      | Input(string)
      | InputDense(string)
      | InputDisabled(string)
      | InputType(string)
      | InputMultiline(string)
      | InputSearch(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FormControl(_) => "formControl"
      | Inkbar(_) => "inkbar"
      | Error(_) => "error"
      | Focused(_) => "focused"
      | Disabled(_) => "disabled"
      | Underline(_) => "underline"
      | Multiline(_) => "multiline"
      | FullWidth(_) => "fullWidth"
      | Input(_) => "input"
      | InputDense(_) => "inputDense"
      | InputDisabled(_) => "inputDisabled"
      | InputType(_) => "inputType"
      | InputMultiline(_) => "inputMultiline"
      | InputSearch(_) => "inputSearch";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | FormControl(className)
               | Inkbar(className)
               | Error(className)
               | Focused(className)
               | Disabled(className)
               | Underline(className)
               | Multiline(className)
               | FullWidth(className)
               | Input(className)
               | InputDense(className)
               | InputDisabled(className)
               | InputType(className)
               | InputMultiline(className)
               | InputSearch(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Input/Input"] external reactClass : ReasonReact.reactClass = "default";
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
        ~margin: option(margin_e)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~onClean: option((unit => unit))=?,
        ~onDirty: option((unit => unit))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~placeholder: option(string)=?,
        ~readOnly: option(bool)=?,
        ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~startAdornment: option(ReasonReact.reactElement)=?,
        ~type_: option(string)=?,
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
      ~props={
        "autoComplete": Js.Nullable.from_opt(autoComplete),
        "autoFocus": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoFocus)),
        "className": Js.Nullable.from_opt(className),
        "defaultValue": Js.Nullable.from_opt(optionMap(unwrapValue, defaultValue)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableUnderline":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableUnderline)),
        "endAdornment": Js.Nullable.from_opt(endAdornment),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "id": Js.Nullable.from_opt(id),
        "inputComponent": Js.Nullable.from_opt(optionMap(unwrapValue, inputComponent)),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "margin": Js.Nullable.from_opt(optionMap(margin_eToJs, margin)),
        "multiline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiline)),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClean": Js.Nullable.from_opt(onClean),
        "onDirty": Js.Nullable.from_opt(onDirty),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "placeholder": Js.Nullable.from_opt(placeholder),
        "readOnly": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, readOnly)),
        "rows": Js.Nullable.from_opt(optionMap(unwrapValue, rows)),
        "rowsMax": Js.Nullable.from_opt(optionMap(unwrapValue, rowsMax)),
        "startAdornment": Js.Nullable.from_opt(startAdornment),
        "type": Js.Nullable.from_opt(type_),
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module LinearProgress = {
  [@bs.deriving jsConverter]
  type color_f = [ [@bs.as "primary"] | `Primary [@bs.as "secondary"] | `Secondary];
  [@bs.deriving jsConverter]
  type mode_9 = [
    [@bs.as "determinate"] | `Determinate
    [@bs.as "indeterminate"] | `Indeterminate
    [@bs.as "buffer"] | `Buffer
    [@bs.as "query"] | `Query
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | PrimaryColor(string)
      | PrimaryColorBar(string)
      | PrimaryDashed(string)
      | SecondaryColor(string)
      | SecondaryColorBar(string)
      | SecondaryDashed(string)
      | Bar(string)
      | Dashed(string)
      | BufferBar2(string)
      | RootBuffer(string)
      | RootQuery(string)
      | IndeterminateBar1(string)
      | IndeterminateBar2(string)
      | DeterminateBar1(string)
      | BufferBar1(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | PrimaryColor(_) => "primaryColor"
      | PrimaryColorBar(_) => "primaryColorBar"
      | PrimaryDashed(_) => "primaryDashed"
      | SecondaryColor(_) => "secondaryColor"
      | SecondaryColorBar(_) => "secondaryColorBar"
      | SecondaryDashed(_) => "secondaryDashed"
      | Bar(_) => "bar"
      | Dashed(_) => "dashed"
      | BufferBar2(_) => "bufferBar2"
      | RootBuffer(_) => "rootBuffer"
      | RootQuery(_) => "rootQuery"
      | IndeterminateBar1(_) => "indeterminateBar1"
      | IndeterminateBar2(_) => "indeterminateBar2"
      | DeterminateBar1(_) => "determinateBar1"
      | BufferBar1(_) => "bufferBar1";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | PrimaryColor(className)
               | PrimaryColorBar(className)
               | PrimaryDashed(className)
               | SecondaryColor(className)
               | SecondaryColorBar(className)
               | SecondaryDashed(className)
               | Bar(className)
               | Dashed(className)
               | BufferBar2(className)
               | RootBuffer(className)
               | RootQuery(className)
               | IndeterminateBar1(className)
               | IndeterminateBar2(className)
               | DeterminateBar1(className)
               | BufferBar1(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Progress/LinearProgress"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color_f)=?,
        ~mode: option(mode_9)=?,
        ~value: option([ | `Int(int) | `Float(float)])=?,
        ~valueBuffer: option([ | `Int(int) | `Float(float)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_fToJs, color)),
        "mode": Js.Nullable.from_opt(optionMap(mode_9ToJs, mode)),
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value)),
        "valueBuffer": Js.Nullable.from_opt(optionMap(unwrapValue, valueBuffer)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemAvatar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemIcon"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemSecondaryAction"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make = (~className: option(string)=?, ~classes: option(Classes.t)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItemText"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableTypography":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTypography)),
        "inset": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inset)),
        "primary": Js.Nullable.from_opt(primary),
        "secondary": Js.Nullable.from_opt(secondary),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListItem"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "button": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, button)),
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "ContainerComponent": Js.Nullable.from_opt(optionMap(unwrapValue, containerComponent)),
        "ContainerProps": Js.Nullable.from_opt(containerProps),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableGutters": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableGutters)),
        "divider": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, divider)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module ListSubheader = {
  [@bs.deriving jsConverter]
  type color_7 = [
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/ListSubheader"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color_7)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~disableSticky: option(bool)=?,
        ~inset: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_7ToJs, color)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disableSticky": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableSticky)),
        "inset": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, inset)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/List/List"] external reactClass : ReasonReact.reactClass = "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "disablePadding": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disablePadding)),
        "subheader": Js.Nullable.from_opt(subheader),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Menu/MenuItem"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "role": Js.Nullable.from_opt(role),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "button": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, button)),
        "ContainerComponent": Js.Nullable.from_opt(optionMap(unwrapValue, containerComponent)),
        "ContainerProps": Js.Nullable.from_opt(containerProps),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableGutters": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableGutters)),
        "divider": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, divider)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module MenuList = {
  [@bs.module "material-ui/Menu/MenuList"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "dense": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, dense)),
        "disablePadding": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disablePadding)),
        "subheader": Js.Nullable.from_opt(subheader)
      },
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
  type transitionDuration_u = [ [@bs.as "auto"] | `Auto];
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
  type anchorReference_g = [
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Menu/Menu"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~anchorEl: option(Js.t({..}))=?,
        ~menuListProps: option(Js.t({..}))=?,
        ~onClose: option((unit => unit))=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntered: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onExit: option((unit => unit))=?,
        ~onExited: option((unit => unit))=?,
        ~onExiting: option((unit => unit))=?,
        ~open_: bool,
        ~paperProps: option(Js.t({..}))=?,
        ~popoverClasses: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~transitionDuration:
           option(
             [
               | `Int(int)
               | `Float(float)
               | `Object(transitionDurationShape)
               | `Enum(transitionDuration_u)
             ]
           )=?,
        ~action: option(ReasonReact.reactElement)=?,
        ~anchorOrigin: option(anchorOriginShape)=?,
        ~anchorPosition: option(anchorPositionShape)=?,
        ~anchorReference: option(anchorReference_g)=?,
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
      ~props={
        "anchorEl": Js.Nullable.from_opt(anchorEl),
        "MenuListProps": Js.Nullable.from_opt(menuListProps),
        "onClose": Js.Nullable.from_opt(onClose),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onExit": Js.Nullable.from_opt(onExit),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "open": Js.Boolean.to_js_boolean(open_),
        "PaperProps": Js.Nullable.from_opt(paperProps),
        "PopoverClasses": Js.Nullable.from_opt(popoverClasses),
        "theme": theme,
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(transitionDuration_uToJs(v)))
              | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
              | v => unwrapValue(v),
              transitionDuration
            )
          ),
        "action": Js.Nullable.from_opt(action),
        "anchorOrigin": Js.Nullable.from_opt(optionMap(anchorOriginShapeToJs, anchorOrigin)),
        "anchorPosition": Js.Nullable.from_opt(optionMap(anchorPositionShapeToJs, anchorPosition)),
        "anchorReference": Js.Nullable.from_opt(optionMap(anchorReference_gToJs, anchorReference)),
        "container": Js.Nullable.from_opt(optionMap(unwrapValue, container)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "getContentAnchorEl": Js.Nullable.from_opt(getContentAnchorEl),
        "marginThreshold": Js.Nullable.from_opt(optionMap(unwrapValue, marginThreshold)),
        "role": Js.Nullable.from_opt(role),
        "transformOrigin":
          Js.Nullable.from_opt(optionMap(transformOriginShapeToJs, transformOrigin)),
        "transition": Js.Nullable.from_opt(optionMap(unwrapValue, transition)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module MobileStepper = {
  [@bs.deriving jsConverter]
  type position_w = [
    [@bs.as "bottom"] | `Bottom
    [@bs.as "top"] | `Top
    [@bs.as "static"] | `Static
  ];
  [@bs.deriving jsConverter]
  type type__0 = [
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/MobileStepper/MobileStepper"]
  external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~activeStep: option([ | `Int(int) | `Float(float)])=?,
        ~backButton: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~nextButton: option(ReasonReact.reactElement)=?,
        ~position: option(position_w)=?,
        ~steps: [ | `Int(int) | `Float(float)],
        ~type_: option(type__0)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "activeStep": Js.Nullable.from_opt(optionMap(unwrapValue, activeStep)),
        "backButton": Js.Nullable.from_opt(backButton),
        "className": Js.Nullable.from_opt(className),
        "nextButton": Js.Nullable.from_opt(nextButton),
        "position": Js.Nullable.from_opt(optionMap(position_wToJs, position)),
        "steps": unwrapValue(steps),
        "type": Js.Nullable.from_opt(optionMap(type__0ToJs, type_)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Modal/Modal"] external reactClass : ReasonReact.reactClass = "default";
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
        ~onClose: option((unit => unit))=?,
        ~onEscapeKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onRendered: option((unit => unit))=?,
        ~open_: bool,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "BackdropComponent": Js.Nullable.from_opt(optionMap(unwrapValue, backdropComponent)),
        "BackdropProps": Js.Nullable.from_opt(backdropProps),
        "className": Js.Nullable.from_opt(className),
        "container": Js.Nullable.from_opt(optionMap(unwrapValue, container)),
        "disableAutoFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableAutoFocus)),
        "disableBackdropClick":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableBackdropClick)),
        "disableEnforceFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableEnforceFocus)),
        "disableEscapeKeyDown":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableEscapeKeyDown)),
        "disableRestoreFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRestoreFocus)),
        "hideBackdrop": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, hideBackdrop)),
        "keepMounted": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, keepMounted)),
        "manager": Js.Nullable.from_opt(manager),
        "onBackdropClick": Js.Nullable.from_opt(onBackdropClick),
        "onClose": Js.Nullable.from_opt(onClose),
        "onEscapeKeyDown": Js.Nullable.from_opt(onEscapeKeyDown),
        "onRendered": Js.Nullable.from_opt(onRendered),
        "open": Js.Boolean.to_js_boolean(open_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module MuiThemeProvider = {
  [@bs.module "material-ui/styles/MuiThemeProvider"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~disableStylesGeneration: option(bool)=?,
        ~sheetsManager: option(Js.t({..}))=?,
        ~theme: [ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)],
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "disableStylesGeneration":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableStylesGeneration)),
        "sheetsManager": Js.Nullable.from_opt(sheetsManager),
        "theme": unwrapValue(theme)
      },
      children
    );
};

module Paper = {
  module Classes = {
    type classesType =
      | Root(string)
      | Rounded(string)
      | Shadow0(string)
      | Shadow1(string)
      | Shadow2(string)
      | Shadow3(string)
      | Shadow4(string)
      | Shadow5(string)
      | Shadow6(string)
      | Shadow7(string)
      | Shadow8(string)
      | Shadow9(string)
      | Shadow10(string)
      | Shadow11(string)
      | Shadow12(string)
      | Shadow13(string)
      | Shadow14(string)
      | Shadow15(string)
      | Shadow16(string)
      | Shadow17(string)
      | Shadow18(string)
      | Shadow19(string)
      | Shadow20(string)
      | Shadow21(string)
      | Shadow22(string)
      | Shadow23(string)
      | Shadow24(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Rounded(_) => "rounded"
      | Shadow0(_) => "shadow0"
      | Shadow1(_) => "shadow1"
      | Shadow2(_) => "shadow2"
      | Shadow3(_) => "shadow3"
      | Shadow4(_) => "shadow4"
      | Shadow5(_) => "shadow5"
      | Shadow6(_) => "shadow6"
      | Shadow7(_) => "shadow7"
      | Shadow8(_) => "shadow8"
      | Shadow9(_) => "shadow9"
      | Shadow10(_) => "shadow10"
      | Shadow11(_) => "shadow11"
      | Shadow12(_) => "shadow12"
      | Shadow13(_) => "shadow13"
      | Shadow14(_) => "shadow14"
      | Shadow15(_) => "shadow15"
      | Shadow16(_) => "shadow16"
      | Shadow17(_) => "shadow17"
      | Shadow18(_) => "shadow18"
      | Shadow19(_) => "shadow19"
      | Shadow20(_) => "shadow20"
      | Shadow21(_) => "shadow21"
      | Shadow22(_) => "shadow22"
      | Shadow23(_) => "shadow23"
      | Shadow24(_) => "shadow24";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Rounded(className)
               | Shadow0(className)
               | Shadow1(className)
               | Shadow2(className)
               | Shadow3(className)
               | Shadow4(className)
               | Shadow5(className)
               | Shadow6(className)
               | Shadow7(className)
               | Shadow8(className)
               | Shadow9(className)
               | Shadow10(className)
               | Shadow11(className)
               | Shadow12(className)
               | Shadow13(className)
               | Shadow14(className)
               | Shadow15(className)
               | Shadow16(className)
               | Shadow17(className)
               | Shadow18(className)
               | Shadow19(className)
               | Shadow20(className)
               | Shadow21(className)
               | Shadow22(className)
               | Shadow23(className)
               | Shadow24(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Paper/Paper"] external reactClass : ReasonReact.reactClass = "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
  type anchorReference_g = [
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
  type transitionDuration_g = [ [@bs.as "auto"] | `Auto];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Popover/Popover"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~anchorEl: option(Js.t({..}))=?,
        ~anchorOrigin: option(anchorOriginShape)=?,
        ~anchorPosition: option(anchorPositionShape)=?,
        ~anchorReference: option(anchorReference_g)=?,
        ~container: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~getContentAnchorEl: option(ReasonReact.reactElement)=?,
        ~marginThreshold: option([ | `Int(int) | `Float(float)])=?,
        ~onClose: option((unit => unit))=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntered: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onExit: option((unit => unit))=?,
        ~onExited: option((unit => unit))=?,
        ~onExiting: option((unit => unit))=?,
        ~open_: bool,
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
               | `Enum(transitionDuration_g)
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
        ~onRendered: option((unit => unit))=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "action": Js.Nullable.from_opt(action),
        "anchorEl": Js.Nullable.from_opt(anchorEl),
        "anchorOrigin": Js.Nullable.from_opt(optionMap(anchorOriginShapeToJs, anchorOrigin)),
        "anchorPosition": Js.Nullable.from_opt(optionMap(anchorPositionShapeToJs, anchorPosition)),
        "anchorReference": Js.Nullable.from_opt(optionMap(anchorReference_gToJs, anchorReference)),
        "container": Js.Nullable.from_opt(optionMap(unwrapValue, container)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "getContentAnchorEl": Js.Nullable.from_opt(getContentAnchorEl),
        "marginThreshold": Js.Nullable.from_opt(optionMap(unwrapValue, marginThreshold)),
        "onClose": Js.Nullable.from_opt(onClose),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onExit": Js.Nullable.from_opt(onExit),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "open": Js.Boolean.to_js_boolean(open_),
        "PaperProps": Js.Nullable.from_opt(paperProps),
        "role": Js.Nullable.from_opt(role),
        "transformOrigin":
          Js.Nullable.from_opt(optionMap(transformOriginShapeToJs, transformOrigin)),
        "transition": Js.Nullable.from_opt(optionMap(unwrapValue, transition)),
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(transitionDuration_gToJs(v)))
              | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
              | v => unwrapValue(v),
              transitionDuration
            )
          ),
        "BackdropComponent": Js.Nullable.from_opt(optionMap(unwrapValue, backdropComponent)),
        "BackdropProps": Js.Nullable.from_opt(backdropProps),
        "className": Js.Nullable.from_opt(className),
        "disableAutoFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableAutoFocus)),
        "disableBackdropClick":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableBackdropClick)),
        "disableEnforceFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableEnforceFocus)),
        "disableEscapeKeyDown":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableEscapeKeyDown)),
        "disableRestoreFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRestoreFocus)),
        "hideBackdrop": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, hideBackdrop)),
        "keepMounted": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, keepMounted)),
        "manager": Js.Nullable.from_opt(manager),
        "onBackdropClick": Js.Nullable.from_opt(onBackdropClick),
        "onEscapeKeyDown": Js.Nullable.from_opt(onEscapeKeyDown),
        "onRendered": Js.Nullable.from_opt(onRendered),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Portal = {
  [@bs.module "material-ui/Portal/Portal"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~container: option([ | `ObjectGeneric(Js.t({..})) | `Element(ReasonReact.reactElement)])=?,
        ~onRendered: option((unit => unit))=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "container": Js.Nullable.from_opt(optionMap(unwrapValue, container)),
        "onRendered": Js.Nullable.from_opt(onRendered)
      },
      children
    );
};

module RadioGroup = {
  [@bs.module "material-ui/Radio/RadioGroup"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onChange": Js.Nullable.from_opt(onChange),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "value": Js.Nullable.from_opt(value),
        "className": Js.Nullable.from_opt(className),
        "row": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, row))
      },
      children
    );
};

module Radio = {
  module Classes = {
    type classesType =
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Default(_) => "default"
      | Checked(_) => "checked"
      | Disabled(_) => "disabled";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Default(className)
               | Checked(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Radio/Radio"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~defaultChecked: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~inputType: option(string)=?,
        ~name: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~value: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.from_opt(optionMap(unwrapValue, checked)),
        "checkedIcon": Js.Nullable.from_opt(checkedIcon),
        "className": Js.Nullable.from_opt(className),
        "defaultChecked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, defaultChecked)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "icon": Js.Nullable.from_opt(icon),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "inputType": Js.Nullable.from_opt(inputType),
        "name": Js.Nullable.from_opt(name),
        "onChange": Js.Nullable.from_opt(onChange),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "value": Js.Nullable.from_opt(value),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Reboot = {
  [@bs.module "material-ui/Reboot/Reboot"] external reactClass : ReasonReact.reactClass =
    "default";
  let make = (children) =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module Select = {
  [@bs.deriving jsConverter]
  type margin_e = [ [@bs.as "dense"] | `Dense [@bs.as "none"] | `None];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Select/Select"] external reactClass : ReasonReact.reactClass =
    "default";
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
        ~onClose: option((unit => unit))=?,
        ~onOpen: option((unit => unit))=?,
        ~open_: option(bool)=?,
        ~renderValue: option(ReasonReact.reactElement)=?,
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
        ~margin: option(margin_e)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onBlur: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onClean: option((unit => unit))=?,
        ~onDirty: option((unit => unit))=?,
        ~onFocus: option(ReasonReact.Callback.t(ReactEventRe.Focus.t))=?,
        ~onKeyDown: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~onKeyUp: option(ReasonReact.Callback.t(ReactEventRe.Keyboard.t))=?,
        ~placeholder: option(string)=?,
        ~readOnly: option(bool)=?,
        ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~startAdornment: option(ReasonReact.reactElement)=?,
        ~type_: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "autoWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoWidth)),
        "displayEmpty": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, displayEmpty)),
        "input": Js.Nullable.from_opt(input),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "MenuProps": Js.Nullable.from_opt(menuProps),
        "multiple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiple)),
        "native": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, native)),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClose": Js.Nullable.from_opt(onClose),
        "onOpen": Js.Nullable.from_opt(onOpen),
        "open": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, open_)),
        "renderValue": Js.Nullable.from_opt(renderValue),
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value)),
        "autoComplete": Js.Nullable.from_opt(autoComplete),
        "autoFocus": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoFocus)),
        "className": Js.Nullable.from_opt(className),
        "defaultValue": Js.Nullable.from_opt(optionMap(unwrapValue, defaultValue)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableUnderline":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableUnderline)),
        "endAdornment": Js.Nullable.from_opt(endAdornment),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "id": Js.Nullable.from_opt(id),
        "inputComponent": Js.Nullable.from_opt(optionMap(unwrapValue, inputComponent)),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "margin": Js.Nullable.from_opt(optionMap(margin_eToJs, margin)),
        "multiline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiline)),
        "name": Js.Nullable.from_opt(name),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClean": Js.Nullable.from_opt(onClean),
        "onDirty": Js.Nullable.from_opt(onDirty),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "placeholder": Js.Nullable.from_opt(placeholder),
        "readOnly": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, readOnly)),
        "rows": Js.Nullable.from_opt(optionMap(unwrapValue, rows)),
        "rowsMax": Js.Nullable.from_opt(optionMap(unwrapValue, rowsMax)),
        "startAdornment": Js.Nullable.from_opt(startAdornment),
        "type": Js.Nullable.from_opt(type_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Slide = {
  [@bs.deriving jsConverter]
  type direction_9 = [
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
  [@bs.module "material-ui/transitions/Slide"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~direction: option(direction_9)=?,
        ~in_: option(bool)=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntered: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onExit: option((unit => unit))=?,
        ~onExited: option((unit => unit))=?,
        ~onExiting: option((unit => unit))=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "direction": Js.Nullable.from_opt(optionMap(direction_9ToJs, direction)),
        "in": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, in_)),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onExit": Js.Nullable.from_opt(onExit),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "style": Js.Nullable.from_opt(style),
        "theme": theme,
        "timeout":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
              | v => unwrapValue(v),
              timeout
            )
          )
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Snackbar/SnackbarContent"]
  external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "action": Js.Nullable.from_opt(action),
        "className": Js.Nullable.from_opt(className),
        "message": Js.Nullable.from_opt(message),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
      | AnchorTopCenter(string)
      | AnchorBottomCenter(string)
      | AnchorTopRight(string)
      | AnchorBottomRight(string)
      | AnchorTopLeft(string)
      | AnchorBottomLeft(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | AnchorTopCenter(_) => "anchorTopCenter"
      | AnchorBottomCenter(_) => "anchorBottomCenter"
      | AnchorTopRight(_) => "anchorTopRight"
      | AnchorBottomRight(_) => "anchorBottomRight"
      | AnchorTopLeft(_) => "anchorTopLeft"
      | AnchorBottomLeft(_) => "anchorBottomLeft";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | AnchorTopCenter(className)
               | AnchorBottomCenter(className)
               | AnchorTopRight(className)
               | AnchorBottomRight(className)
               | AnchorTopLeft(className)
               | AnchorBottomLeft(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Snackbar/Snackbar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~anchorOrigin: option(anchorOriginShape)=?,
        ~autoHideDuration: option([ | `Int(int) | `Float(float)])=?,
        ~className: option(string)=?,
        ~key: option('any_y)=?,
        ~message: option(ReasonReact.reactElement)=?,
        ~onClose: option((unit => unit))=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntered: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onExit: option((unit => unit))=?,
        ~onExited: option((unit => unit))=?,
        ~onExiting: option((unit => unit))=?,
        ~onMouseEnter: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~onMouseLeave: option(ReasonReact.Callback.t(ReactEventRe.Mouse.t))=?,
        ~open_: option(bool)=?,
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
      ~props={
        "action": Js.Nullable.from_opt(action),
        "anchorOrigin": Js.Nullable.from_opt(optionMap(anchorOriginShapeToJs, anchorOrigin)),
        "autoHideDuration": Js.Nullable.from_opt(optionMap(unwrapValue, autoHideDuration)),
        "className": Js.Nullable.from_opt(className),
        "key": Js.Nullable.from_opt(key),
        "message": Js.Nullable.from_opt(message),
        "onClose": Js.Nullable.from_opt(onClose),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntered": Js.Nullable.from_opt(onEntered),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onExit": Js.Nullable.from_opt(onExit),
        "onExited": Js.Nullable.from_opt(onExited),
        "onExiting": Js.Nullable.from_opt(onExiting),
        "onMouseEnter": Js.Nullable.from_opt(onMouseEnter),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "open": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, open_)),
        "resumeHideDuration": Js.Nullable.from_opt(optionMap(unwrapValue, resumeHideDuration)),
        "SnackbarContentProps": Js.Nullable.from_opt(snackbarContentProps),
        "transition": Js.Nullable.from_opt(optionMap(unwrapValue, transition)),
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
              | v => unwrapValue(v),
              transitionDuration
            )
          ),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module StepButton = {
  [@bs.deriving jsConverter]
  type orientation_c = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  module Classes = {
    type classesType =
      | Root(string)
      | AlternativeLabel(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | AlternativeLabel(_) => "alternativeLabel";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | AlternativeLabel(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/StepButton"] external reactClass : ReasonReact.reactClass =
    "default";
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
        ~orientation: option(orientation_c)=?,
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
        ~type_: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "alternativeLabel":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, alternativeLabel)),
        "className": Js.Nullable.from_opt(className),
        "completed": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, completed)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "icon": Js.Nullable.from_opt(icon),
        "last": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, last)),
        "optional": Js.Nullable.from_opt(optional),
        "orientation": Js.Nullable.from_opt(optionMap(orientation_cToJs, orientation)),
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClick": Js.Nullable.from_opt(onClick),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": Js.Nullable.from_opt(type_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module StepContent = {
  [@bs.deriving jsConverter]
  type orientation_a = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  [@bs.deriving jsConverter]
  type transitionDurationShape = {
    enter: int,
    exit: int
  };
  [@bs.deriving jsConverter]
  type transitionDuration_k = [ [@bs.as "auto"] | `Auto];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/StepContent"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~active: option(bool)=?,
        ~alternativeLabel: option(bool)=?,
        ~className: option(string)=?,
        ~completed: option(bool)=?,
        ~last: option(bool)=?,
        ~optional: option(bool)=?,
        ~orientation: option(orientation_a)=?,
        ~transition: option(ReasonReact.reactElement)=?,
        ~transitionDuration:
           option(
             [
               | `Int(int)
               | `Float(float)
               | `Object(transitionDurationShape)
               | `Enum(transitionDuration_k)
             ]
           )=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "alternativeLabel":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, alternativeLabel)),
        "className": Js.Nullable.from_opt(className),
        "completed": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, completed)),
        "last": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, last)),
        "optional": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, optional)),
        "orientation": Js.Nullable.from_opt(optionMap(orientation_aToJs, orientation)),
        "transition": Js.Nullable.from_opt(transition),
        "transitionDuration":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(transitionDuration_kToJs(v)))
              | `Object(v) => unwrapValue(`Element(transitionDurationShapeToJs(v)))
              | v => unwrapValue(v),
              transitionDuration
            )
          ),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module StepLabel = {
  [@bs.deriving jsConverter]
  type orientation_9 = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  module Classes = {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | Vertical(string)
      | Active(string)
      | Completed(string)
      | Disabled(string)
      | IconContainer(string)
      | IconContainerNoAlternative(string)
      | AlternativeLabelRoot(string)
      | AlternativeLabel(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Horizontal(_) => "horizontal"
      | Vertical(_) => "vertical"
      | Active(_) => "active"
      | Completed(_) => "completed"
      | Disabled(_) => "disabled"
      | IconContainer(_) => "iconContainer"
      | IconContainerNoAlternative(_) => "iconContainerNoAlternative"
      | AlternativeLabelRoot(_) => "alternativeLabelRoot"
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
               | Active(className)
               | Completed(className)
               | Disabled(className)
               | IconContainer(className)
               | IconContainerNoAlternative(className)
               | AlternativeLabelRoot(className)
               | AlternativeLabel(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/StepLabel"] external reactClass : ReasonReact.reactClass =
    "default";
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
        ~orientation: option(orientation_9)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "alternativeLabel":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, alternativeLabel)),
        "className": Js.Nullable.from_opt(className),
        "completed": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, completed)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "icon": Js.Nullable.from_opt(icon),
        "last": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, last)),
        "optional": Js.Nullable.from_opt(optional),
        "orientation": Js.Nullable.from_opt(optionMap(orientation_9ToJs, orientation)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Step = {
  [@bs.deriving jsConverter]
  type orientation_y = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  module Classes = {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | AlternativeLabel(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Horizontal(_) => "horizontal"
      | AlternativeLabel(_) => "alternativeLabel";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Horizontal(className)
               | AlternativeLabel(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/Step"] external reactClass : ReasonReact.reactClass = "default";
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
        ~orientation: option(orientation_y)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "alternativeLabel":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, alternativeLabel)),
        "className": Js.Nullable.from_opt(className),
        "completed": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, completed)),
        "connector": Js.Nullable.from_opt(connector),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "index": Js.Nullable.from_opt(optionMap(unwrapValue, index)),
        "last": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, last)),
        "orientation": Js.Nullable.from_opt(optionMap(orientation_yToJs, orientation)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Stepper = {
  [@bs.deriving jsConverter]
  type orientation_y = [ [@bs.as "horizontal"] | `Horizontal [@bs.as "vertical"] | `Vertical];
  module Classes = {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | Vertical(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Horizontal(_) => "horizontal"
      | Vertical(_) => "vertical";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Horizontal(className)
               | Vertical(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Stepper/Stepper"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~activeStep: option([ | `Int(int) | `Float(float)])=?,
        ~alternativeLabel: option(bool)=?,
        ~className: option(string)=?,
        ~connector: option(ReasonReact.reactElement)=?,
        ~nonLinear: option(bool)=?,
        ~orientation: option(orientation_y)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~elevation: option([ | `Int(int) | `Float(float)])=?,
        ~square: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "activeStep": Js.Nullable.from_opt(optionMap(unwrapValue, activeStep)),
        "alternativeLabel":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, alternativeLabel)),
        "className": Js.Nullable.from_opt(className),
        "connector": Js.Nullable.from_opt(connector),
        "nonLinear": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, nonLinear)),
        "orientation": Js.Nullable.from_opt(optionMap(orientation_yToJs, orientation)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "elevation": Js.Nullable.from_opt(optionMap(unwrapValue, elevation)),
        "square": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, square)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module SvgIcon = {
  [@bs.deriving jsConverter]
  type color_r = [
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
      | ColorError(string)
      | FontSize(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | ColorPrimary(_) => "colorPrimary"
      | ColorSecondary(_) => "colorSecondary"
      | ColorAction(_) => "colorAction"
      | ColorDisabled(_) => "colorDisabled"
      | ColorError(_) => "colorError"
      | FontSize(_) => "fontSize";
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
               | ColorError(className)
               | FontSize(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/SvgIcon/SvgIcon"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~color: option(color_r)=?,
        ~fontSize: option(bool)=?,
        ~nativeColor: option(string)=?,
        ~titleAccess: option(string)=?,
        ~viewBox: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_rToJs, color)),
        "fontSize": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fontSize)),
        "nativeColor": Js.Nullable.from_opt(nativeColor),
        "titleAccess": Js.Nullable.from_opt(titleAccess),
        "viewBox": Js.Nullable.from_opt(viewBox),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Switch = {
  module Classes = {
    type classesType =
      | Root(string)
      | Bar(string)
      | Icon(string)
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Bar(_) => "bar"
      | Icon(_) => "icon"
      | Default(_) => "default"
      | Checked(_) => "checked"
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
               | Default(className)
               | Checked(className)
               | Disabled(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Switch/Switch"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~checked: option([ | `Bool(bool) | `String(string)])=?,
        ~checkedIcon: option(ReasonReact.reactElement)=?,
        ~className: option(string)=?,
        ~defaultChecked: option(bool)=?,
        ~disabled: option(bool)=?,
        ~disableRipple: option(bool)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~inputProps: option(Js.t({..}))=?,
        ~inputRef: option(ReasonReact.reactElement)=?,
        ~inputType: option(string)=?,
        ~name: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)])=?,
        ~value: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "checked": Js.Nullable.from_opt(optionMap(unwrapValue, checked)),
        "checkedIcon": Js.Nullable.from_opt(checkedIcon),
        "className": Js.Nullable.from_opt(className),
        "defaultChecked": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, defaultChecked)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "icon": Js.Nullable.from_opt(icon),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "inputType": Js.Nullable.from_opt(inputType),
        "name": Js.Nullable.from_opt(name),
        "onChange": Js.Nullable.from_opt(onChange),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "value": Js.Nullable.from_opt(value),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Tab = {
  [@bs.deriving jsConverter]
  type textColor_i = [
    [@bs.as "secondary"] | `Secondary
    [@bs.as "primary"] | `Primary
    [@bs.as "inherit"] | `Inherit
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | RootLabelIcon(string)
      | RootInherit(string)
      | RootPrimary(string)
      | RootPrimarySelected(string)
      | RootPrimaryDisabled(string)
      | RootSecondary(string)
      | RootSecondarySelected(string)
      | RootSecondaryDisabled(string)
      | RootInheritSelected(string)
      | RootInheritDisabled(string)
      | FullWidth(string)
      | Wrapper(string)
      | LabelContainer(string)
      | Label(string)
      | LabelWrapped(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | RootLabelIcon(_) => "rootLabelIcon"
      | RootInherit(_) => "rootInherit"
      | RootPrimary(_) => "rootPrimary"
      | RootPrimarySelected(_) => "rootPrimarySelected"
      | RootPrimaryDisabled(_) => "rootPrimaryDisabled"
      | RootSecondary(_) => "rootSecondary"
      | RootSecondarySelected(_) => "rootSecondarySelected"
      | RootSecondaryDisabled(_) => "rootSecondaryDisabled"
      | RootInheritSelected(_) => "rootInheritSelected"
      | RootInheritDisabled(_) => "rootInheritDisabled"
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
               | RootLabelIcon(className)
               | RootInherit(className)
               | RootPrimary(className)
               | RootPrimarySelected(className)
               | RootPrimaryDisabled(className)
               | RootSecondary(className)
               | RootSecondarySelected(className)
               | RootSecondaryDisabled(className)
               | RootInheritSelected(className)
               | RootInheritDisabled(className)
               | FullWidth(className)
               | Wrapper(className)
               | LabelContainer(className)
               | Label(className)
               | LabelWrapped(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tabs/Tab"] external reactClass : ReasonReact.reactClass = "default";
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
        ~textColor: option([ | `String(string) | `Enum(textColor_i)])=?,
        ~value: option('any_v)=?,
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
        ~type_: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "icon": Js.Nullable.from_opt(icon),
        "indicator": Js.Nullable.from_opt(indicator),
        "label": Js.Nullable.from_opt(label),
        "onChange": Js.Nullable.from_opt(onChange),
        "onClick": Js.Nullable.from_opt(onClick),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "style": Js.Nullable.from_opt(style),
        "textColor":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(textColor_iToJs(v)))
              | v => unwrapValue(v),
              textColor
            )
          ),
        "value": Js.Nullable.from_opt(value),
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": Js.Nullable.from_opt(type_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TableBody = {
  [@bs.module "material-ui/Table/TableBody"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"component": Js.Nullable.from_opt(optionMap(unwrapValue, component))},
      children
    );
};

module TableCell = {
  [@bs.deriving jsConverter]
  type padding_5 = [
    [@bs.as "default"] | `Default
    [@bs.as "checkbox"] | `Checkbox
    [@bs.as "dense"] | `Dense
    [@bs.as "none"] | `None
  ];
  [@bs.deriving jsConverter]
  type sortDirection_x = [ [@bs.as "asc"] | `Asc [@bs.as "desc"] | `Desc [@bs.as "0"] | `False];
  [@bs.deriving jsConverter]
  type type__t = [ [@bs.as "head"] | `Head [@bs.as "body"] | `Body [@bs.as "footer"] | `Footer];
  module Classes = {
    type classesType =
      | Root(string)
      | Numeric(string)
      | TypeHead(string)
      | TypeBody(string)
      | TypeFooter(string)
      | PaddingDefault(string)
      | PaddingDense(string)
      | PaddingCheckbox(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Numeric(_) => "numeric"
      | TypeHead(_) => "typeHead"
      | TypeBody(_) => "typeBody"
      | TypeFooter(_) => "typeFooter"
      | PaddingDefault(_) => "paddingDefault"
      | PaddingDense(_) => "paddingDense"
      | PaddingCheckbox(_) => "paddingCheckbox";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Numeric(className)
               | TypeHead(className)
               | TypeBody(className)
               | TypeFooter(className)
               | PaddingDefault(className)
               | PaddingDense(className)
               | PaddingCheckbox(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableCell"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~numeric: option(bool)=?,
        ~padding: option(padding_5)=?,
        ~sortDirection: option(sortDirection_x)=?,
        ~type_: option(type__t)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "numeric": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, numeric)),
        "padding": Js.Nullable.from_opt(optionMap(padding_5ToJs, padding)),
        "sortDirection": Js.Nullable.from_opt(optionMap(sortDirection_xToJs, sortDirection)),
        "type": Js.Nullable.from_opt(optionMap(type__tToJs, type_)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TableFooter = {
  [@bs.module "material-ui/Table/TableFooter"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"component": Js.Nullable.from_opt(optionMap(unwrapValue, component))},
      children
    );
};

module TableHead = {
  [@bs.module "material-ui/Table/TableHead"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={"component": Js.Nullable.from_opt(optionMap(unwrapValue, component))},
      children
    );
};

module TablePagination = {
  [@bs.deriving jsConverter]
  type padding_5 = [
    [@bs.as "default"] | `Default
    [@bs.as "checkbox"] | `Checkbox
    [@bs.as "dense"] | `Dense
    [@bs.as "none"] | `None
  ];
  [@bs.deriving jsConverter]
  type sortDirection_x = [ [@bs.as "asc"] | `Asc [@bs.as "desc"] | `Desc [@bs.as "0"] | `False];
  [@bs.deriving jsConverter]
  type type__t = [ [@bs.as "head"] | `Head [@bs.as "body"] | `Body [@bs.as "footer"] | `Footer];
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TablePagination"] external reactClass : ReasonReact.reactClass =
    "default";
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
        ~onChangeRowsPerPage: option((unit => unit))=?,
        ~page: [ | `Int(int) | `Float(float)],
        ~rowsPerPage: [ | `Int(int) | `Float(float)],
        ~rowsPerPageOptions: option([ | `ArrayGeneric(array('any_w))])=?,
        ~className: option(string)=?,
        ~numeric: option(bool)=?,
        ~padding: option(padding_5)=?,
        ~sortDirection: option(sortDirection_x)=?,
        ~type_: option(type__t)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "Actions": Js.Nullable.from_opt(optionMap(unwrapValue, actions)),
        "backIconButtonProps": Js.Nullable.from_opt(backIconButtonProps),
        "colSpan": Js.Nullable.from_opt(optionMap(unwrapValue, colSpan)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "count": unwrapValue(count),
        "labelDisplayedRows": Js.Nullable.from_opt(labelDisplayedRows),
        "labelRowsPerPage": Js.Nullable.from_opt(labelRowsPerPage),
        "nextIconButtonProps": Js.Nullable.from_opt(nextIconButtonProps),
        "onChangePage": onChangePage,
        "onChangeRowsPerPage": Js.Nullable.from_opt(onChangeRowsPerPage),
        "page": unwrapValue(page),
        "rowsPerPage": unwrapValue(rowsPerPage),
        "rowsPerPageOptions": Js.Nullable.from_opt(rowsPerPageOptions),
        "className": Js.Nullable.from_opt(className),
        "numeric": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, numeric)),
        "padding": Js.Nullable.from_opt(optionMap(padding_5ToJs, padding)),
        "sortDirection": Js.Nullable.from_opt(optionMap(sortDirection_xToJs, sortDirection)),
        "type": Js.Nullable.from_opt(optionMap(type__tToJs, type_)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TableRow = {
  module Classes = {
    type classesType =
      | Root(string)
      | TypeHead(string)
      | TypeFooter(string)
      | Selected(string)
      | Hover(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | TypeHead(_) => "typeHead"
      | TypeFooter(_) => "typeFooter"
      | Selected(_) => "selected"
      | Hover(_) => "hover";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | TypeHead(className)
               | TypeFooter(className)
               | Selected(className)
               | Hover(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableRow"] external reactClass : ReasonReact.reactClass =
    "default";
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
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "hover": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, hover)),
        "selected": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, selected)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TableSortLabel = {
  [@bs.deriving jsConverter]
  type direction_k = [ [@bs.as "asc"] | `Asc [@bs.as "desc"] | `Desc];
  module Classes = {
    type classesType =
      | Root(string)
      | Active(string)
      | Icon(string)
      | Desc(string)
      | Asc(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Active(_) => "active"
      | Icon(_) => "icon"
      | Desc(_) => "desc"
      | Asc(_) => "asc";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | Active(className)
               | Icon(className)
               | Desc(className)
               | Asc(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/TableSortLabel"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~active: option(bool)=?,
        ~className: option(string)=?,
        ~direction: option(direction_k)=?,
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
        ~type_: option(string)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "active": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, active)),
        "className": Js.Nullable.from_opt(className),
        "direction": Js.Nullable.from_opt(optionMap(direction_kToJs, direction)),
        "buttonRef": Js.Nullable.from_opt(buttonRef),
        "centerRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centerRipple)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "disableRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableRipple)),
        "focusRipple": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, focusRipple)),
        "keyboardFocusedClassName": Js.Nullable.from_opt(keyboardFocusedClassName),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onClick": Js.Nullable.from_opt(onClick),
        "onFocus": Js.Nullable.from_opt(onFocus),
        "onKeyboardFocus": Js.Nullable.from_opt(onKeyboardFocus),
        "onKeyDown": Js.Nullable.from_opt(onKeyDown),
        "onKeyUp": Js.Nullable.from_opt(onKeyUp),
        "onMouseDown": Js.Nullable.from_opt(onMouseDown),
        "onMouseLeave": Js.Nullable.from_opt(onMouseLeave),
        "onMouseUp": Js.Nullable.from_opt(onMouseUp),
        "onTouchEnd": Js.Nullable.from_opt(onTouchEnd),
        "onTouchMove": Js.Nullable.from_opt(onTouchMove),
        "onTouchStart": Js.Nullable.from_opt(onTouchStart),
        "role": Js.Nullable.from_opt(role),
        "tabIndex": Js.Nullable.from_opt(optionMap(unwrapValue, tabIndex)),
        "type": Js.Nullable.from_opt(type_),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Table/Table"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~className: option(string)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Tabs = {
  [@bs.deriving jsConverter]
  type indicatorColor_m = [ [@bs.as "secondary"] | `Secondary [@bs.as "primary"] | `Primary];
  [@bs.deriving jsConverter]
  type scrollButtons_4 = [ [@bs.as "auto"] | `Auto [@bs.as "on"] | `On [@bs.as "off"] | `Off];
  [@bs.deriving jsConverter]
  type textColor_2 = [
    [@bs.as "secondary"] | `Secondary
    [@bs.as "primary"] | `Primary
    [@bs.as "inherit"] | `Inherit
  ];
  module Classes = {
    type classesType =
      | Root(string)
      | FlexContainer(string)
      | ScrollingContainer(string)
      | Fixed(string)
      | Scrollable(string)
      | Centered(string)
      | ButtonAuto(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | FlexContainer(_) => "flexContainer"
      | ScrollingContainer(_) => "scrollingContainer"
      | Fixed(_) => "fixed"
      | Scrollable(_) => "scrollable"
      | Centered(_) => "centered"
      | ButtonAuto(_) => "buttonAuto";
    let to_obj = (listOfClasses) =>
      listOfClasses
      |> StdLabels.List.fold_left(
           ~f=
             (obj, classType) => {
               switch classType {
               | Root(className)
               | FlexContainer(className)
               | ScrollingContainer(className)
               | Fixed(className)
               | Scrollable(className)
               | Centered(className)
               | ButtonAuto(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tabs/Tabs"] external reactClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~action: option(ReasonReact.reactElement)=?,
        ~buttonClassName: option(string)=?,
        ~centered: option(bool)=?,
        ~className: option(string)=?,
        ~fullWidth: option(bool)=?,
        ~indicatorClassName: option(string)=?,
        ~indicatorColor: option([ | `String(string) | `Enum(indicatorColor_m)])=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~scrollable: option(bool)=?,
        ~scrollButtons: option(scrollButtons_4)=?,
        ~tabScrollButton: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~textColor: option(textColor_2)=?,
        ~theme: Js.t({..}),
        ~value: option('any_b)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "action": Js.Nullable.from_opt(action),
        "buttonClassName": Js.Nullable.from_opt(buttonClassName),
        "centered": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, centered)),
        "className": Js.Nullable.from_opt(className),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "indicatorClassName": Js.Nullable.from_opt(indicatorClassName),
        "indicatorColor":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Enum(v) => unwrapValue(`String(indicatorColor_mToJs(v)))
              | v => unwrapValue(v),
              indicatorColor
            )
          ),
        "onChange": Js.Nullable.from_opt(onChange),
        "scrollable": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, scrollable)),
        "scrollButtons": Js.Nullable.from_opt(optionMap(scrollButtons_4ToJs, scrollButtons)),
        "TabScrollButton": Js.Nullable.from_opt(optionMap(unwrapValue, tabScrollButton)),
        "textColor": Js.Nullable.from_opt(optionMap(textColor_2ToJs, textColor)),
        "theme": theme,
        "value": Js.Nullable.from_opt(value),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module TextField = {
  [@bs.deriving jsConverter]
  type margin_a = [ [@bs.as "none"] | `None [@bs.as "dense"] | `Dense [@bs.as "normal"] | `Normal];
  [@bs.module "material-ui/TextField/TextField"] external reactClass : ReasonReact.reactClass =
    "default";
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
        ~margin: option(margin_a)=?,
        ~multiline: option(bool)=?,
        ~name: option(string)=?,
        ~onChange: option(ReasonReact.Callback.t(ReactEventRe.Form.t))=?,
        ~placeholder: option(string)=?,
        ~required: option(bool)=?,
        ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
        ~select: option(bool)=?,
        ~selectProps: option(Js.t({..}))=?,
        ~type_: option(string)=?,
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
      ~props={
        "autoComplete": Js.Nullable.from_opt(autoComplete),
        "autoFocus": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, autoFocus)),
        "className": Js.Nullable.from_opt(className),
        "defaultValue": Js.Nullable.from_opt(defaultValue),
        "disabled": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disabled)),
        "error": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, error)),
        "FormHelperTextProps": Js.Nullable.from_opt(formHelperTextProps),
        "fullWidth": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, fullWidth)),
        "helperText": Js.Nullable.from_opt(helperText),
        "helperTextClassName": Js.Nullable.from_opt(helperTextClassName),
        "id": Js.Nullable.from_opt(id),
        "InputLabelProps": Js.Nullable.from_opt(inputLabelProps),
        "InputProps2": Js.Nullable.from_opt(inputProps2),
        "inputProps": Js.Nullable.from_opt(inputProps),
        "inputRef": Js.Nullable.from_opt(inputRef),
        "label": Js.Nullable.from_opt(label),
        "labelClassName": Js.Nullable.from_opt(labelClassName),
        "margin": Js.Nullable.from_opt(optionMap(margin_aToJs, margin)),
        "multiline": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, multiline)),
        "name": Js.Nullable.from_opt(name),
        "onChange": Js.Nullable.from_opt(onChange),
        "placeholder": Js.Nullable.from_opt(placeholder),
        "required": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, required)),
        "rows": Js.Nullable.from_opt(optionMap(unwrapValue, rows)),
        "rowsMax": Js.Nullable.from_opt(optionMap(unwrapValue, rowsMax)),
        "select": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, select)),
        "SelectProps": Js.Nullable.from_opt(selectProps),
        "type": Js.Nullable.from_opt(type_),
        "value": Js.Nullable.from_opt(optionMap(unwrapValue, value)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "onBlur": Js.Nullable.from_opt(onBlur),
        "onFocus": Js.Nullable.from_opt(onFocus)
      },
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Toolbar/Toolbar"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~disableGutters: option(bool)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableGutters": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableGutters)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Tooltip = {
  [@bs.deriving jsConverter]
  type placement_k = [
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
      | TooltipLeft(string)
      | TooltipRight(string)
      | TooltipTop(string)
      | TooltipBottom(string)
      | TooltipOpen(string);
    type t = list(classesType);
    let to_string =
      fun
      | Root(_) => "root"
      | Popper(_) => "popper"
      | PopperClose(_) => "popperClose"
      | Tooltip(_) => "tooltip"
      | TooltipLeft(_) => "tooltipLeft"
      | TooltipRight(_) => "tooltipRight"
      | TooltipTop(_) => "tooltipTop"
      | TooltipBottom(_) => "tooltipBottom"
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
               | TooltipLeft(className)
               | TooltipRight(className)
               | TooltipTop(className)
               | TooltipBottom(className)
               | TooltipOpen(className) => Js.Dict.set(obj, to_string(classType), className)
               };
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Tooltip/Tooltip"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~className: option(string)=?,
        ~disableTriggerFocus: option(bool)=?,
        ~disableTriggerHover: option(bool)=?,
        ~disableTriggerTouch: option(bool)=?,
        ~enterDelay: option([ | `Int(int) | `Float(float)])=?,
        ~id: option(string)=?,
        ~leaveDelay: option([ | `Int(int) | `Float(float)])=?,
        ~onClose: option((unit => unit))=?,
        ~onOpen: option((unit => unit))=?,
        ~open_: option(bool)=?,
        ~placement: option(placement_k)=?,
        ~popperProps: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~title: ReasonReact.reactElement,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "className": Js.Nullable.from_opt(className),
        "disableTriggerFocus":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTriggerFocus)),
        "disableTriggerHover":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTriggerHover)),
        "disableTriggerTouch":
          Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, disableTriggerTouch)),
        "enterDelay": Js.Nullable.from_opt(optionMap(unwrapValue, enterDelay)),
        "id": Js.Nullable.from_opt(id),
        "leaveDelay": Js.Nullable.from_opt(optionMap(unwrapValue, leaveDelay)),
        "onClose": Js.Nullable.from_opt(onClose),
        "onOpen": Js.Nullable.from_opt(onOpen),
        "open": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, open_)),
        "placement": Js.Nullable.from_opt(optionMap(placement_kToJs, placement)),
        "PopperProps": Js.Nullable.from_opt(popperProps),
        "theme": theme,
        "title": title,
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Typography = {
  [@bs.deriving jsConverter]
  type align_f = [
    [@bs.as "inherit"] | `Inherit
    [@bs.as "left"] | `Left
    [@bs.as "center"] | `Center
    [@bs.as "right"] | `Right
    [@bs.as "justify"] | `Justify
  ];
  [@bs.deriving jsConverter]
  type color_v = [
    [@bs.as "inherit"] | `Inherit
    [@bs.as "primary"] | `Primary
    [@bs.as "textSecondary"] | `TextSecondary
    [@bs.as "secondary"] | `Secondary
    [@bs.as "error"] | `Error
    [@bs.as "default"] | `Default
  ];
  [@bs.deriving jsConverter]
  type type__9 = [
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
               obj
             },
           ~init=Js.Dict.empty()
         );
  };
  [@bs.module "material-ui/Typography/Typography"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~align: option(align_f)=?,
        ~className: option(string)=?,
        ~color: option(color_v)=?,
        ~component: option([ | `String(string) | `Element(ReasonReact.reactElement)])=?,
        ~gutterBottom: option(bool)=?,
        ~headlineMapping: option(Js.t({..}))=?,
        ~noWrap: option(bool)=?,
        ~paragraph: option(bool)=?,
        ~type_: option(type__9)=?,
        ~classes: option(Classes.t)=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "align": Js.Nullable.from_opt(optionMap(align_fToJs, align)),
        "className": Js.Nullable.from_opt(className),
        "color": Js.Nullable.from_opt(optionMap(color_vToJs, color)),
        "component": Js.Nullable.from_opt(optionMap(unwrapValue, component)),
        "gutterBottom": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, gutterBottom)),
        "headlineMapping": Js.Nullable.from_opt(headlineMapping),
        "noWrap": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, noWrap)),
        "paragraph": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, paragraph)),
        "type": Js.Nullable.from_opt(optionMap(type__9ToJs, type_)),
        "classes": Js.Nullable.from_opt(optionMap(Classes.to_obj, classes))
      },
      children
    );
};

module Zoom = {
  [@bs.deriving jsConverter]
  type timeoutShape = {
    enter: int,
    exit: int
  };
  [@bs.module "material-ui/transitions/Zoom"] external reactClass : ReasonReact.reactClass =
    "default";
  let make =
      (
        ~appear: option(bool)=?,
        ~enterDelay: option([ | `Int(int) | `Float(float)])=?,
        ~in_: option(bool)=?,
        ~onEnter: option((unit => unit))=?,
        ~onEntering: option((unit => unit))=?,
        ~onExit: option((unit => unit))=?,
        ~style: option(Js.t({..}))=?,
        ~theme: Js.t({..}),
        ~timeout: option([ | `Int(int) | `Float(float) | `Object(timeoutShape)])=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props={
        "appear": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, appear)),
        "enterDelay": Js.Nullable.from_opt(optionMap(unwrapValue, enterDelay)),
        "in": Js.Nullable.from_opt(optionMap(Js.Boolean.to_js_boolean, in_)),
        "onEnter": Js.Nullable.from_opt(onEnter),
        "onEntering": Js.Nullable.from_opt(onEntering),
        "onExit": Js.Nullable.from_opt(onExit),
        "style": Js.Nullable.from_opt(style),
        "theme": theme,
        "timeout":
          Js.Nullable.from_opt(
            optionMap(
              fun
              | `Object(v) => unwrapValue(`Element(timeoutShapeToJs(v)))
              | v => unwrapValue(v),
              timeout
            )
          )
      },
      children
    );
};
