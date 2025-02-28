type t_sizeOptions = {
  lg?: float,
  md?: float,
  sm?: float,
  xl?: float,
  xs?: float,
}
@deprecated("Renamed to t_sizeOptions") type breakpointValues = t_sizeOptions

type t_breakpointOptions = {
  keys?: array<string>,
  values?: t_sizeOptions,
  up?: Breakpoint.t => string,
  down?: Breakpoint.t => string,
  between?: (Breakpoint.t, Breakpoint.t) => string,
  only?: Breakpoint.t => string,
  not?: Breakpoint.t => string,
  unit?: string,
}
@deprecated("Renamed to t_breakpointOptions") type breakpoints = t_breakpointOptions

type t_mixinsOptions = {
  gutters?: string,
  toolbar?: ReactDOM.Style.t,
}
@deprecated("Renamed to t_mixinsOptions") type mixinsOptions = t_mixinsOptions

type t_colorOptions = {
  \"50"?: string,
  \"100"?: string,
  \"200"?: string,
  \"300"?: string,
  \"400"?: string,
  \"500"?: string,
  \"600"?: string,
  \"700"?: string,
  \"800"?: string,
  \"900"?: string,
  \"A100"?: string,
  \"A200"?: string,
  \"A400"?: string,
  \"A700"?: string,
}
@deprecated("Renamed to t_colorOptions") type color = t_colorOptions

type t_colorWithVariantsOptions = {
  ...t_colorOptions,
  contrastText?: string,
  dark?: string,
  light?: string,
  main?: string,
}
@deprecated("Renamed to t_colorWithVariantsOptions") type colorWithVariants = t_colorWithVariantsOptions

type t_actionOptions = {
  activatedOpacity?: float,
  active?: string,
  disabled?: string,
  disabledBackground?: string,
  disabledOpacity?: float,
  focus?: string,
  focusOpacity?: float,
  hover?: string,
  hoverOpacity?: float,
  selected?: string,
  selectedOpacity?: float,
}
@deprecated("Renamed to t_actionOptions") type typeAction = t_actionOptions

type t_backgroundOptions = {default?: string, paper?: string}
@deprecated("Renamed to t_backgroundOptions") type typeBackground = t_backgroundOptions

type t_commonColorsOptions = {black?: string, white?: string}
@deprecated("Renamed to t_commonColorsOptions") type commonColors = t_commonColorsOptions

type t_textOptions = {
  disabled?: string,
  hint?: string,
  primary?: string,
  secondary?: string,
}
@deprecated("Renamed to t_textOptions") type typeText = t_textOptions

type t_tonalOffsetOptions = {dark?: float, light?: float}
@deprecated("Renamed to t_tonalOffsetOptions") type tonalOffset = t_tonalOffsetOptions

type t_paletteOptions = {
  action?: t_actionOptions,
  augmentColor?: unit => string,
  background?: t_backgroundOptions,
  common?: t_commonColorsOptions,
  contrastThreshold?: float,
  divider?: string,
  error?: t_colorWithVariantsOptions,
  getContrastText?: unit => string,
  grey?: t_colorOptions,
  info?: t_colorWithVariantsOptions,
  mode?: string,
  primary?: t_colorWithVariantsOptions,
  secondary?: t_colorWithVariantsOptions,
  success?: t_colorWithVariantsOptions,
  text?: t_textOptions,
  tonalOffset?: t_tonalOffsetOptions,
  @as("type") type_?: string,
  warning?: t_colorWithVariantsOptions,
}
@deprecated("Renamed to t_paletteOptions") type paletteOptions = t_paletteOptions


type t_shapeOptions = {borderRadius?: float}
@deprecated("Renamed to t_shapeOptions") type shape = t_shapeOptions

type t_durationOptions = {
  complex?: float,
  enteringScreen?: float,
  leavingScreen?: float,
  short?: float,
  shorter?: float,
  shortest?: float,
  standard?: float,
}
@deprecated("Renamed to t_durationOptions") type duration = t_durationOptions

type t_easingOptions = {
  easeIn?: string,
  easeInOut?: string,
  easeOut?: string,
  sharp?: string,
}
@deprecated("Renamed to t_easingOptions") type easing = t_easingOptions

type t_transitionCreateOptions = {
  duration?: string,
  easing?: string,
  delay?: string,
}

type t_transitionsOptions = {
  create?: (array<string>, t_transitionCreateOptions) => string,
  getAutoHeightDuration?: float => Transition.duration,
  easing?: t_easingOptions,
  duration?: t_durationOptions,
}
@deprecated("Renamed to t_transitionsOptions") type transitionsOptions = t_transitionsOptions

type t_zIndexOptions = {
  appBar?: int,
  drawer?: int,
  mobileStepper?: int,
  modal?: int,
  snackbar?: int,
  speedDial?: int,
  tooltip?: int,
}
@deprecated("Renamed to t_zIndexOptions") type zIndex = t_zIndexOptions

type t_fontStyleOptions = {
  allVariants?: ReactDOM.Style.t,
  fontFamily?: string,
  fontSize?: int,
  fontWeightLight?: string,
  fontWeightRegular?: string,
  fontWeightMedium?: string,
  fontWeightBold?: string,
  htmlFontSize?: int,
}

type t_typographyOptions = {
  ...t_fontStyleOptions,
  h1?: ReactDOM.Style.t,
  h2?: ReactDOM.Style.t,
  h3?: ReactDOM.Style.t,
  h4?: ReactDOM.Style.t,
  h5?: ReactDOM.Style.t,
  h6?: ReactDOM.Style.t,
  subtitle1?: ReactDOM.Style.t,
  subtitle2?: ReactDOM.Style.t,
  body1?: ReactDOM.Style.t,
  body2?: ReactDOM.Style.t,
  button?: ReactDOM.Style.t,
  caption?: ReactDOM.Style.t,
  overline?: ReactDOM.Style.t,
}

type t = {
  breakpoints?: t_breakpointOptions,
  direction?: string,
  mixins?: t_mixinsOptions,
  components?: Overrides.t,
  palette?: t_paletteOptions,
  shadows?: array<string>,
  shape?: t_shapeOptions,
  spacing?: int => int,
  transitions?: t_transitionsOptions,
  typography?: t_typographyOptions,
  unstable_strictMode?: bool,
  zIndex?: t_zIndexOptions,
}
