module Jss = {
  type t

  external fromObj: {..} => t = "%identity"
  external toObj: t => {..} = "%identity"
}

type props = {
  disableGeneration?: bool,
  generateClassName?: unit => string,
  injectFirst?: bool,
  jss?: Jss.t,
  children: React.element,
}

@module("@mui/styles")
external make: props => React.element = "StylesProvider"
