@unboxed
type styles =
  | SystemProps(System.props)
  | String(string)

type props = {
  ...CommonProps.t_NoRef,
  styles: styles,
}

@module("@mui/material/GlobalStyles")
external make: React.component<props> = "default"
