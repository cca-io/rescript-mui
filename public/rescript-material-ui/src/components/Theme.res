type t_size = {
  lg: float,
  md: float,
  sm: float,
  xl: float,
  xs: float,
}

type t_breakpoints = {
  between: Any.t,
  down: Any.t,
  keys: array<string>,
  not: Any.t,
  only: Any.t,
  unit: string,
  up: Any.t,
  values: t_size,
}

type t_palette = {mode: string}

type t_shape = {borderRadius: float}

type t_duration = {
  complex: float,
  enteringScreen: float,
  leavingScreen: float,
  short: float,
  shorter: float,
  shortest: float,
  standard: float,
}

type t_easing = {
  easeIn: string,
  easeInOut: string,
  easeOut: string,
  sharp: string,
}

type t_transitions = {
  duration: t_duration,
  easing: t_easing,
}

type t_theme = {
  breakpoints: t_breakpoints,
  components: Any.t,
  direction: string,
  palette: t_palette,
  shape: t_shape,
  spacing: int => int,
  transitions: t_transitions,
  unstable_sx: Any.t,
  unstable_sxConfig: Any.t,
}

type t = t_theme

@module("@mui/material/styles") external create: ThemeOptions.t => t = "createTheme"
