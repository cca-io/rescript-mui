open Theme

type breakpoint
external stringToBreakpoint: string => breakpoint = "%identity"
external intToBreakpoint: int => breakpoint = "%identity"

type breakpointFunc = breakpoint => string
external jsonToBreakpointFunc: Js.Json.t => breakpointFunc = "%identity"
external styleToString: ReactDOM.Style.t => string = "%identity"

/* see material-ui.com/layout/breakpoints/#breakpoints for details */
let addBreakpoint = (sourceStyle, ~theme, ~breakpoint, ~style) => {
  let breakpoint = switch breakpoint {
  | #XS => "xs"->stringToBreakpoint
  | #SM => "sm"->stringToBreakpoint
  | #MD => "md"->stringToBreakpoint
  | #LG => "lg"->stringToBreakpoint
  | #XL => "xl"->stringToBreakpoint
  | #Int(x) => x->intToBreakpoint
  }

  let breakpointSource = theme.breakpoints.up->Any.unsafeGetValue->jsonToBreakpointFunc(breakpoint)

  ReactDOM.Style.unsafeAddProp(sourceStyle, breakpointSource, styleToString(style))
}

@deriving(abstract)
type transitionCreateArgs = {
  easing: string,
  duration: float,
}

@send
external transitionCreateRAW: (t_transitions, array<string>, transitionCreateArgs) => string =
  "create"

let checkAffect = (affect, value) => affect ? [value] : []

let transitionCreate = (
  ~theme,
  ~affectWidth=false,
  ~affectMargin=false,
  ~easing: string,
  ~duration: float,
  (),
) => {
  let transitions = theme.transitions

  let affects = Array.concat(list{
    checkAffect(affectWidth, "width"),
    checkAffect(affectMargin, "margin"),
  })

  let args = transitionCreateArgs(~easing, ~duration)

  transitionCreateRAW(transitions, affects, args)
}
