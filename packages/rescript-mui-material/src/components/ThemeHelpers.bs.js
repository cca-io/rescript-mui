// Generated by ReScript, PLEASE EDIT WITH CARE

import * as ReactDOMStyle from "@rescript/react/src/ReactDOMStyle.bs.js";

function addBreakpoint(sourceStyle, theme, breakpoint, style) {
  var breakpoint$1 = typeof breakpoint === "object" ? breakpoint.VAL : (
      breakpoint === "MD" ? "md" : (
          breakpoint === "SM" ? "sm" : (
              breakpoint === "XL" ? "xl" : (
                  breakpoint === "XS" ? "xs" : "lg"
                )
            )
        )
    );
  var breakpointFunc = theme.breakpoints.up;
  var breakpointSource = breakpointFunc(breakpoint$1);
  return ReactDOMStyle.unsafeAddProp(sourceStyle, breakpointSource, style);
}

export {
  addBreakpoint ,
}
/* No side effect */
