type t_size = {
  lg: float,
  md: float,
  sm: float,
  xl: float,
  xs: float,
}

@unboxed
type breakpoint =
  | Point(float)
  | Func(string => ThemeOptions.t)

type t_breakpoints = {
  between: float,
  down: float,
  keys: array<string>,
  not: float,
  only: float,
  unit: string,
  up: float,
  values: t_size,
}

type color = {
  \"50": string,
  \"100": string,
  \"200": string,
  \"300": string,
  \"400": string,
  \"500": string,
  \"600": string,
  \"700": string,
  \"800": string,
  \"900": string,
  \"A100": string,
  \"A200": string,
  \"A400": string,
  \"A700": string,
}

type colorWithVariants = {
  ...color,
  contrastText: string,
  dark: string,
  light: string,
  main: string,
}

type t_typeAction = {
  activatedOpacity: float,
  active: string,
  disabled: string,
  disabledBackground: string,
  disabledOpacity: float,
  focus: string,
  focusOpacity: float,
  hover: string,
  hoverOpacity: float,
  selected: string,
  selectedOpacity: float,
}

type t_typeBackground = {default: string, paper: string}

type t_commonColors = {black: string, white: string}

type t_typeText = {
  disabled: string,
  hint: string,
  primary: string,
  secondary: string,
}

type t_tonalOffset = {dark: float, light: float}

type t_palette = {
  mode: string,
  action: t_typeAction,
  background: t_typeBackground,
  common: t_commonColors,
  contrastThreshold: float,
  divider: string,
  error: colorWithVariants,
  grey: color,
  info: colorWithVariants,
  primary: colorWithVariants,
  secondary: colorWithVariants,
  success: colorWithVariants,
  text: t_typeText,
  tonalOffset: t_tonalOffset,
  \"type": string,
  warning: colorWithVariants,
}

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

type mixins = {
  toolbar: JsxDOMStyle.t,
  gutters: string,
}

type t_zIndex = {drawer: float}

type t_theme = {
  breakpoints: t_breakpoints,
  components: Overrides.t,
  direction: string,
  palette: t_palette,
  shape: t_shape,
  spacing: int => int,
  transitions: t_transitions,
  mixins: mixins,
  zIndex: t_zIndex,
}

type t = t_theme

external fromOptions: ThemeOptions.t => t = "%identity"

@module("@mui/material/styles") external create: ThemeOptions.t => t = "createTheme"
