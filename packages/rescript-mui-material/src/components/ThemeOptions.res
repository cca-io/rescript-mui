type breakpointValues = {
  lg?: float,
  md?: float,
  sm?: float,
  xl?: float,
  xs?: float,
}

type breakpoints = {
  between?: Any.t,
  down?: Any.t,
  keys?: array<string>,
  only?: Any.t,
  step?: float,
  unit?: string,
  up?: Any.t,
  values?: breakpointValues,
  width?: Any.t,
}

type mixinsOptions = {gutters?: Any.t, toolbar?: ReactDOM.Style.t}

type typeAction = {
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

type typeBackground = {default?: string, paper?: string}

type commonColors = {black?: string, white?: string}

type typeText = {
  disabled?: string,
  hint?: string,
  primary?: string,
  secondary?: string,
}

type tonalOffset = {dark?: float, light?: float}

type color = {
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

type colorWithVariants = {
  ...color,
  contrastText?: string,
  dark?: string,
  light?: string,
  main?: string,
}

type paletteOptions = {
  action?: typeAction,
  background?: typeBackground,
  common?: commonColors,
  contrastThreshold?: float,
  divider?: string,
  error?: colorWithVariants,
  getContrastText?: Any.t,
  grey?: color,
  info?: colorWithVariants,
  primary?: colorWithVariants,
  secondary?: colorWithVariants,
  success?: colorWithVariants,
  text?: typeText,
  tonalOffset?: tonalOffset,
  \"type"?: string,
  warning?: colorWithVariants,
}

type shape = {borderRadius?: float}

type duration = {
  complex?: float,
  enteringScreen?: float,
  leavingScreen?: float,
  short?: float,
  shorter?: float,
  shortest?: float,
  standard?: float,
}

type easing = {
  easeIn?: string,
  easeInOut?: string,
  easeOut?: string,
  sharp?: string,
}

type transitionsOptions = {
  create?: Any.t,
  duration?: duration,
  easing?: easing,
  getAutoHeightDuration?: Any.t,
}

type typographyStyleOptions = {\"@font-face"?: Any.t}

type typography = {
  body1?: typographyStyleOptions,
  body2?: typographyStyleOptions,
  button?: typographyStyleOptions,
  caption?: typographyStyleOptions,
  fontFamily?: string,
  fontSize?: float,
  fontWeightBold?: string,
  fontWeightLight?: string,
  fontWeightMedium?: string,
  fontWeightRegular?: string,
  h1?: typographyStyleOptions,
  h2?: typographyStyleOptions,
  h3?: typographyStyleOptions,
  h4?: typographyStyleOptions,
  h5?: typographyStyleOptions,
  h6?: typographyStyleOptions,
  htmlFontSize?: float,
  overline?: typographyStyleOptions,
  subtitle1?: typographyStyleOptions,
  subtitle2?: typographyStyleOptions,
}

type zIndex = {
  appBar?: float,
  drawer?: float,
  mobileStepper?: float,
  modal?: float,
  snackbar?: float,
  speedDial?: float,
  tooltip?: float,
}

type t = {
  breakpoints?: breakpoints,
  direction?: string,
  mixins?: mixinsOptions,
  overrides?: Overrides.t,
  palette?: paletteOptions,
  props?: Any.t,
  shadows?: array<string>,
  shape?: shape,
  spacing?: Any.t,
  transitions?: transitionsOptions,
  typography?: typography,
  unstable_strictMode?: bool,
  zIndex?: zIndex,
}
