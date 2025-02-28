open Theme

external styleToString: ReactDOM.Style.t => string = "%identity"

/* see https://mui.com/material-ui/customization/breakpoints for details */
let addBreakpoint = (sourceStyle, ~theme, ~breakpoint, ~style) => {
  let mediaQuery = theme.breakpoints.up(breakpoint)

  ReactDOM.Style.unsafeAddProp(sourceStyle, mediaQuery, styleToString(style))
}

let addBreakpointDown = (sourceStyle, ~theme, ~breakpoint, ~style) => {
  let mediaQuery = theme.breakpoints.down(breakpoint)

  ReactDOM.Style.unsafeAddProp(sourceStyle, mediaQuery, styleToString(style))
}
