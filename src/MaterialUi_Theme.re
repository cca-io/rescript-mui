module Direction = {
  type t =
    | Ltr
    | Rtl;
  let toString = (direction: t) =>
    switch (direction) {
    | Ltr => "ltr"
    | Rtl => "rtl"
    };
  let fromString = (direction: string) =>
    switch (direction) {
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
      sharp: string,
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
      leavingScreen: int,
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
  zIndex: int,
};

let tFromJs = theme => {
  direction: Direction.fromString(theme##direction),
  palette: (),
  typography: (),
  mixins: (),
  breakpoints: (),
  shadows:
    Js.Array.reduce((lst, entry) => [entry, ...lst], [], theme##shadows),
  transitions: Transitions.tFromJs(theme##transitions),
  spacing: {
    unit: theme##spacing##unit,
  },
  zIndex: theme##zIndex,
};
