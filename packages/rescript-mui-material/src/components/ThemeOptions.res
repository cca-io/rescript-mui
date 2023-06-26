type breakpointValues = {
  lg?: float,
  md?: float,
  sm?: float,
  xl?: float,
  xs?: float,
}

type breakpoints = {
  between?: float,
  down?: float,
  keys?: array<string>,
  not?: float,
  only?: float,
  unit?: string,
  up?: float,
  values?: breakpointValues,
}

type mixinsOptions = {gutters?: string, toolbar?: ReactDOM.Style.t}

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
  augmentColor?: unit => string,
  background?: typeBackground,
  common?: commonColors,
  contrastThreshold?: float,
  divider?: string,
  error?: colorWithVariants,
  getContrastText?: unit => string,
  grey?: color,
  info?: colorWithVariants,
  mode?: string,
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

type transitionCreateOptions = {
  duration?: string,
  easing?: string,
  delay?: string,
}

type transitionsOptions = {
  create?: (array<string>, transitionCreateOptions) => string,
  getAutoHeightDuration?: float => Transition.duration,
  easing?: easing,
  duration?: duration,
}

type typographyOptions = {
  fontFamily?: array<string>,
  fontWeight?: int,
  fontSize?: int,
  lineHeight?: float,
  letterSpacing?: string,
  textTransform: string,
}

type typographyStyleOptions = {
  htmlFontSize?: int,
  pxToRem?: string => string,
  fontFamily?: array<string>,
  fontSize?: int,
  fontWeightLight?: int,
  fontWeightRegular?: int,
  fontWeightMedium?: int,
  fontWeightBold?: int,
  h1?: typographyOptions,
  h2?: typographyOptions,
  h3?: typographyOptions,
  h4?: typographyOptions,
  h5?: typographyOptions,
  h6?: typographyOptions,
  subtitle1?: typographyOptions,
  subtitle2?: typographyOptions,
  body1?: typographyOptions,
  body2?: typographyOptions,
  button?: typographyOptions,
  caption?: typographyOptions,
  overline?: typographyOptions,
}

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
  components?: Overrides.t,
  palette?: paletteOptions,
  shadows?: array<string>,
  shape?: shape,
  spacing?: int => int,
  transitions?: transitionsOptions,
  typography?: typography,
  unstable_strictMode?: bool,
  zIndex?: zIndex,
}
