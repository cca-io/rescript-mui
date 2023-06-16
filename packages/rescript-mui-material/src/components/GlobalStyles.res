module Styles_shape = {
  type t = {"__emotion_styles": option<Any.t>}
  @obj external make: (~__emotion_styles: Any.t=?, unit) => t = ""
}

module Styles = {
  type t
  external styles_func: Any.t => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external obj: {..} => t = "%identity"
  external shape: Styles_shape.t => t = "%identity"
  external string: string => t = "%identity"
  external bool: bool => t = "%identity"
}

type props = {
  ...CommonProps.t,
  styles: Styles.t,
}

@module("@mui/material/GlobalStyles")
external make: React.component<props> = "default"
