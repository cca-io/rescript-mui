/**
The `System` module provides types for MUI's system properties, used primarily
with the `sx` prop and Box component.

## System.Value.t

All style values in `System.props` must be of type `System.Value.t`. This is an
unboxed variant type that accepts:

### Predefined Theme Colors
```rescript
PrimaryLight      // "primary.light"
PrimaryMain       // "primary.main"
SecondaryLight    // "secondary.light"
ErrorMain         // "error.main"
TextPrimary       // "text.primary"
TextSecondary     // "text.secondary"
BackgroundPaper   // "background.paper"
BackgroundDefault // "background.default"
// ... and more
```

### Predefined CSS Values
```rescript
Center      // "center"
FlexStart   // "flex-start"
FlexEnd     // "flex-end"
Baseline    // "baseline"
Stretch     // "stretch"
Hidden      // "hidden"
Visible     // "visible"
Auto        // "auto"
Inherit     // "inherit"
// ... and more
```

### Dynamic Values
```rescript
String("any-css-value")  // For arbitrary string values
Number(2.)               // For numeric values (often spacing multipliers)
True                     // For boolean true
False                    // For boolean false
Breakpoint({sm: Number(2.), md: Number(4.)})  // For responsive values
Array([Number(1.), Number(2.)])               // For array values
```

## Example Usage with Sx.obj

```rescript
<Box sx={Sx.obj({
  // Layout
  display: String("flex"),
  flexDirection: String("column"),
  alignItems: Center,
  justifyContent: FlexStart,
  gap: String("16px"),

  // Sizing
  width: String("100%"),
  maxWidth: String("400px"),
  height: Number(200.),

  // Spacing (numbers are theme.spacing multipliers)
  padding: Number(2.),     // theme.spacing(2)
  margin: Number(1.),      // theme.spacing(1)
  mt: Number(2.),          // marginTop shorthand
  px: String("16px"),      // paddingX with explicit px

  // Colors (use predefined variants for theme colors)
  bgcolor: BackgroundPaper,
  color: TextPrimary,
  borderColor: ErrorMain,

  // Or use String for custom colors
  bgcolor: String("#f5f5f5"),
  color: String("rgba(0, 0, 0, 0.87)"),

  // Responsive values
  padding: Breakpoint({xs: Number(1.), sm: Number(2.), md: Number(3.)}),
})} />
```
*/
module Breakpoint = {
  /**
  A breakpoint value that can be a string, boolean, or number.
  Used within responsive breakpoint objects.
  */
  @unboxed
  type breakpoint =
    | String(string)
    | @as(true) True
    | @as(false) False
    | Number(float)

  /**
  Responsive breakpoint object for defining different values at different screen sizes.

  ```rescript
  // Example: different padding at different breakpoints
  padding: Breakpoint({xs: Number(1.), sm: Number(2.), md: Number(3.)})
  ```
  */
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

/**
The universal value type for all System props. This unboxed variant allows
type-safe usage of MUI's system values.

## Predefined Variants

Use these instead of raw strings for better type safety and autocompletion:

**Theme Colors:**
- `PrimaryLight`, `PrimaryMain`, `PrimaryDark`, `PrimaryContrastText`
- `SecondaryLight`, `SecondaryMain`, `SecondaryDark`, `SecondaryContrastText`
- `ErrorLight`, `ErrorMain`, `ErrorDark`, `ErrorContrastText`
- `WarningLight`, `WarningMain`, `WarningDark`, `WarningContrastText`
- `InfoLight`, `InfoMain`, `InfoDark`, `InfoContrastText`
- `SuccessLight`, `SuccessMain`, `SuccessDark`, `SuccessContrastText`
- `TextPrimary`, `TextSecondary`, `TextDisabled`, `TextHint`
- `BackgroundDefault`, `BackgroundPaper`
- `Divider`, `ActionActive`, `ActionHover`, etc.

**Layout/Alignment:**
- `Center`, `Start`, `End`, `FlexStart`, `FlexEnd`
- `Baseline`, `Stretch`, `Normal`
- `SelfStart`, `SelfEnd`

**Overflow:**
- `Auto`, `Hidden`, `Visible`, `Scroll`, `Clip`

**Global CSS:**
- `Inherit`, `Initial`, `Revert`, `RevertLayer`, `Unset`

## Dynamic Values

- `String("value")` - Any CSS string value
- `Number(n)` - Numeric value (for spacing, this is a multiplier of theme.spacing)
- `True` / `False` - Boolean values
- `Breakpoint({...})` - Responsive values
- `Array([...])` - Array of values
*/
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

/**
System props without the `color` field. Used by components where `color`
has a different type (e.g., Button, Typography).
*/
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

/**
Full system props record used with `Sx.obj`. All values must be `System.Value.t`.

```rescript
<Box sx={Sx.obj({
  display: String("flex"),
  alignItems: Center,
  padding: Number(2.),
  bgcolor: BackgroundPaper,
  color: TextPrimary,
})} />
```
*/
type props = {
  ...propsWithoutColor,
  color?: Value.t,
}
