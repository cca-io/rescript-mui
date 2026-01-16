module Breakpoint = {
  @unboxed
  type breakpoint =
    | String(string)
    | @as(true) True
    | @as(false) False
    | Number(float)

  type t = {
    xs?: breakpoint,
    sm?: breakpoint,
    md?: breakpoint,
    lg?: breakpoint,
    xl?: breakpoint,
  }

  external fromObj: {..} => t = "%identity"
  external toObj: t => {..} = "%identity"
}

module Value = {
  @unboxed
  type rec t =
    // colors
    | @as("common.black") CommonBlack
    | @as("common.white") CommonWhite
    | @as("primary.light") PrimaryLight
    | @as("primary.main") PrimaryMain
    | @as("primary.dark") PrimaryDark
    | @as("primary.contrastText") PrimaryContrastText
    | @as("secondary.light") SecondaryLight
    | @as("secondary.main") SecondaryMain
    | @as("secondary.dark") SecondaryDark
    | @as("secondary.contrastText") SecondaryContrastText
    | @as("error.light") ErrorLight
    | @as("error.main") ErrorMain
    | @as("error.dark") ErrorDark
    | @as("error.contrastText") ErrorContrastText
    | @as("warning.light") WarningLight
    | @as("warning.main") WarningMain
    | @as("warning.dark") WarningDark
    | @as("warning.contrastText") WarningContrastText
    | @as("info.light") InfoLight
    | @as("info.main") InfoMain
    | @as("info.dark") InfoDark
    | @as("info.contrastText") InfoContrastText
    | @as("success.light") SuccessLight
    | @as("success.main") SuccessMain
    | @as("success.dark") SuccessDark
    | @as("success.contrastText") SuccessContrastText
    | @as("text.primary") TextPrimary
    | @as("text.secondary") TextSecondary
    | @as("text.disabled") TextDisabled
    | @as("text.hint") TextHint
    | @as("divider") Divider
    | @as("action.active") ActionActive
    | @as("action.hover") ActionHover
    | @as("action.hoverOpacity") ActionHoverOpacity
    | @as("action.selected") ActionSelected
    | @as("action.selectedOpacity") ActionSelectedOpacity
    | @as("action.disabled") ActionDisabled
    | @as("action.disabledOpacity") ActionDisabledOpacity
    | @as("action.disabledBackground") ActionDisabledBackground
    | @as("action.focus") ActionFocus
    | @as("action.focusOpacity") ActionFocusOpacity
    | @as("action.activatedOpacity") ActionActivatedOpacity
    | @as("background.default") BackgroundDefault
    | @as("background.paper") BackgroundPaper

    /* Flexbox and Grid Alignment */
    | @as("normal") Normal
    | @as("stretch") Stretch
    | @as("center") Center
    | @as("start") Start
    | @as("end") End
    | @as("flex-start") FlexStart
    | @as("flex-end") FlexEnd
    | @as("self-start") SelfStart
    | @as("self-end") SelfEnd
    | @as("baseline") Baseline
    | @as("space-between") SpaceBetween
    | @as("space-around") SpaceAround
    | @as("space-evenly") SpaceEvenly
    | @as("left") Left
    | @as("right") Right

    /* Flexbox direction */
    | @as("row") Row
    | @as("row-reverse") RowReverse
    | @as("column") Column
    | @as("column-reverse") ColumnReverse

    /* Flexbox wrap */
    | @as("nowrap") Nowrap
    | @as("wrap") Wrap
    | @as("wrap-reverse") WrapReverse

    /* Overflow */
    | @as("auto") Auto
    | @as("clip") Clip
    | @as("hidden") Hidden
    | @as("scroll") Scroll
    | @as("visible") Visible

    /* Global values */
    | @as("inherit") Inherit
    | @as("initial") Initial
    | @as("revert") Revert
    | @as("revert-layer") RevertLayer
    | @as("unset") Unset

    | String(string)
    | @as(true) True
    | @as(false) False
    | Number(float)
    | Breakpoint(Breakpoint.t)
    | Array(array<t>)
}

type propsWithoutColor = {
  ...CommonProps.t,
  border?: Value.t,
  borderBottom?: Value.t,
  borderColor?: Value.t,
  borderLeft?: Value.t,
  borderRadius?: Value.t,
  borderRight?: Value.t,
  borderTop?: Value.t,
  borderTopLeftRadius?: Value.t,
  borderTopWidth?: Value.t,
  borderTopStyle?: Value.t,
  borderTopColor?: Value.t,
  borderTopRightRadius?: Value.t,
  borderRightWidth?: Value.t,
  borderRightStyle?: Value.t,
  borderRightColor?: Value.t,
  borderBottomRightRadius?: Value.t,
  borderBottomWidth?: Value.t,
  borderBottomStyle?: Value.t,
  borderBottomColor?: Value.t,
  borderBottomLeftRadius?: Value.t,
  borderLeftWidth?: Value.t,
  borderLeftStyle?: Value.t,
  borderLeftColor?: Value.t,
  borderStyle?: Value.t,
  borderWidth?: Value.t,
  boxShadow?: Value.t,
  displayPrint?: Value.t,
  display?: Value.t,
  alignContent?: Value.t,
  alignItems?: Value.t,
  alignSelf?: Value.t,
  flex?: Value.t,
  flexDirection?: Value.t,
  flexGrow?: Value.t,
  flexShrink?: Value.t,
  flexWrap?: Value.t,
  justifyContent?: Value.t,
  justifyItems?: Value.t,
  justifySelf?: Value.t,
  order?: Value.t,
  gap?: Value.t,
  columnGap?: Value.t,
  rowGap?: Value.t,
  gridColumn?: Value.t,
  gridRow?: Value.t,
  gridAutoFlow?: Value.t,
  gridAutoColumns?: Value.t,
  gridAutoRows?: Value.t,
  gridTemplateColumns?: Value.t,
  gridTemplateRows?: Value.t,
  gridTemplateAreas?: Value.t,
  gridArea?: Value.t,
  bgcolor?: Value.t,
  bottom?: Value.t,
  left?: Value.t,
  position?: Value.t,
  right?: Value.t,
  top?: Value.t,
  zIndex?: Value.t,
  height?: Value.t,
  maxHeight?: Value.t,
  maxWidth?: Value.t,
  minHeight?: Value.t,
  minWidth?: Value.t,
  width?: Value.t,
  boxSizing?: Value.t,
  m?: Value.t,
  margin?: Value.t,
  mb?: Value.t,
  marginBottom?: Value.t,
  ml?: Value.t,
  marginLeft?: Value.t,
  mr?: Value.t,
  marginRight?: Value.t,
  mt?: Value.t,
  marginTop?: Value.t,
  mx?: Value.t,
  marginX?: Value.t,
  my?: Value.t,
  marginY?: Value.t,
  marginInline?: Value.t,
  marginInlineStart?: Value.t,
  marginInlineEnd?: Value.t,
  marginBlock?: Value.t,
  marginBlockStart?: Value.t,
  marginBlockEnd?: Value.t,
  p?: Value.t,
  padding?: Value.t,
  pb?: Value.t,
  paddingBottom?: Value.t,
  pl?: Value.t,
  paddingLeft?: Value.t,
  pr?: Value.t,
  paddingRight?: Value.t,
  pt?: Value.t,
  paddingTop?: Value.t,
  px?: Value.t,
  paddingX?: Value.t,
  py?: Value.t,
  paddingY?: Value.t,
  paddingInline?: Value.t,
  paddingInlineStart?: Value.t,
  paddingInlineEnd?: Value.t,
  paddingBlock?: Value.t,
  paddingBlockStart?: Value.t,
  paddingBlockEnd?: Value.t,
  typography?: Value.t,
  fontFamily?: Value.t,
  fontSize?: Value.t,
  fontStyle?: Value.t,
  fontWeight?: Value.t,
  letterSpacing?: Value.t,
  lineHeight?: Value.t,
  textAlign?: Value.t,
  textDecoration?: Value.t,
  textOverflow?: Value.t,
  textTransform?: Value.t,
  overflow?: Value.t,
  overflowX?: Value.t,
  overflowY?: Value.t,
  opacity?: Value.t,
  transform?: Value.t,
  whiteSpace?: Value.t,
  cursor?: Value.t,
  outline?: Value.t,
  userSelect?: Value.t,
  visibility?: Value.t,
  pointerEvents?: Value.t,
  wordBreak?: Value.t,
}

/** CSS system properties */
type props = {
  ...propsWithoutColor,
  color?: Value.t,
}
