module Breakpoint = {
  type theme = Theme.t
  type breakpoint
  type t
  type breakpointDefinition = [#xs | #sm | #md | #lg | #xl | #int(int)]
  type breakpointDirection = [
    | #up(breakpointDefinition)
    | #down(breakpointDefinition)
  ]

  module UNSAFE_INTERNAL = {
    type breakpointFunc = breakpoint => string
    external jsonToBreakpointFunc: Js.Json.t => breakpointFunc = "%identity"
    external stringToBreakpoint: string => breakpoint = "%identity"
    external intToBreakpoint: int => breakpoint = "%identity"
    external stringToBreakpointResult: string => t = "%identity"
  }

  let getAsString = (theme: theme, breakpoint: breakpointDirection) => {
    let bpGet = switch breakpoint {
    | #up(_) => v => v.Theme.up
    | #down(_) => v => v.Theme.down
    }
    let bpValue = switch breakpoint {
    | #up(#xs)
    | #down(#xs) =>
      "xs"->UNSAFE_INTERNAL.stringToBreakpoint
    | #up(#sm)
    | #down(#sm) =>
      "sm"->UNSAFE_INTERNAL.stringToBreakpoint
    | #up(#md)
    | #down(#md) =>
      "md"->UNSAFE_INTERNAL.stringToBreakpoint
    | #up(#lg)
    | #down(#lg) =>
      "lg"->UNSAFE_INTERNAL.stringToBreakpoint
    | #up(#xl)
    | #down(#xl) =>
      "xl"->UNSAFE_INTERNAL.stringToBreakpoint
    | #up(#int(x))
    | #down(#int(x)) =>
      x->UNSAFE_INTERNAL.intToBreakpoint
    }
    theme.breakpoints->bpGet->Types.anyUnpack->UNSAFE_INTERNAL.jsonToBreakpointFunc(bpValue)
  }

  let get = (theme: theme, breakpoint: breakpointDirection) =>
    theme->getAsString(breakpoint)->UNSAFE_INTERNAL.stringToBreakpointResult
}

@module("@material-ui/core/styles")
external useTheme: unit => Theme.t = "useTheme"

@module("@material-ui/core")
external useMediaQueryString: string => bool = "useMediaQuery"

@module("@material-ui/core")
external useMediaQuery: Breakpoint.t => bool = "useMediaQuery"

module ServerStyleSheets = {
  type t
  @module("@material-ui/core/styles") @new
  external make: unit => t = "ServerStyleSheets"
  @module("@material-ui/core/styles") @new
  external makeWithOptions: {..} => t = "ServerStyleSheets"

  @send external collect: (t, React.element) => React.element = "collect"
  @send external toString: t => string = "toString"
  @send external getStyleElement: t => React.element = "getStyleElement"
}
