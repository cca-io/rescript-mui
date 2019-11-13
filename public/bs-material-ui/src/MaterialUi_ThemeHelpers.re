module Theme = MaterialUi_Theme.Theme;
module Mixins = MaterialUi_Theme.Mixins;
module ZIndex = MaterialUi_Theme.ZIndex;
module Breakpoints = MaterialUi_Theme.Breakpoints;
module PaletteColor = MaterialUi_Theme.PaletteColor;
module Palette = MaterialUi_Theme.Palette;
module Transitions = MaterialUi_Theme.Transitions;

type breakpoint;
external stringToBreakpoint: string => breakpoint = "%identity";
external intToBreakpoint: int => breakpoint = "%identity";

type breakpointFunc = breakpoint => string;
external jsonToBreakpointFunc: Js.Json.t => breakpointFunc = "%identity";
external styleToString: ReactDOMRe.Style.t => string = "%identity";

/* see material-ui.com/layout/breakpoints/#breakpoints for details */
let addBreakpoint = (sourceStyle, ~theme, ~breakpoint, ~style) => {
  let breakpoint =
    switch (breakpoint) {
    | `XS => "xs"->stringToBreakpoint
    | `SM => "sm"->stringToBreakpoint
    | `MD => "md"->stringToBreakpoint
    | `LG => "lg"->stringToBreakpoint
    | `XL => "xl"->stringToBreakpoint
    | `Int(x) => x->intToBreakpoint
    };

  let breakpointSource =
    theme
    ->Theme.breakpointsGet
    ->Breakpoints.upGet
    ->jsonToBreakpointFunc(breakpoint);

  ReactDOMRe.Style.unsafeAddProp(
    sourceStyle,
    breakpointSource,
    styleToString(style),
  );
};

[@bs.deriving abstract]
type transitionCreateArgs = {
  easing: string,
  duration: float,
};

[@bs.send]
external transitionCreateRAW:
  (Transitions.t, array(string), transitionCreateArgs) => string =
  "create";

let checkAffect = (affect, value) => affect ? [|value|] : [||];

let transitionCreate =
    (
      ~theme,
      ~affectWidth=false,
      ~affectMargin=false,
      ~easing: string,
      ~duration: float,
      (),
    ) => {
  let transitions = Theme.transitionsGet(theme);

  let affects =
    Array.concat([
      checkAffect(affectWidth, "width"),
      checkAffect(affectMargin, "margin"),
    ]);

  let args = transitionCreateArgs(~easing, ~duration);

  transitionCreateRAW(transitions, affects, args);
};
