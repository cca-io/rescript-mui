open Theme

type breakpoint
external stringToBreakpoint: string => breakpoint = "%identity"
external intToBreakpoint: int => breakpoint = "%identity"

type breakpointFunc = breakpoint => string
external floatToBreakpointFunc: float => breakpointFunc = "%identity"
external styleToString: ReactDOM.Style.t => string = "%identity"

/* see https://mui.com/material-ui/customization/breakpoints for details */
let addBreakpoint = (sourceStyle, ~theme, ~breakpoint, ~style) => {
  let breakpoint = switch breakpoint {
  | #XS => "xs"->stringToBreakpoint
  | #SM => "sm"->stringToBreakpoint
  | #MD => "md"->stringToBreakpoint
  | #LG => "lg"->stringToBreakpoint
  | #XL => "xl"->stringToBreakpoint
  | #Int(x) => x->intToBreakpoint
  }

  let breakpointFunc = theme.breakpoints.up->floatToBreakpointFunc
  let breakpointSource = breakpointFunc(breakpoint)

  ReactDOM.Style.unsafeAddProp(sourceStyle, breakpointSource, styleToString(style))
}
