type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root and bar2 element if `color="primary"`; bar2 if `variant="buffer"`. */
  colorPrimary?: string,
  /** Styles applied to the root and bar2 elements if `color="secondary"`; bar2 if `variant="buffer"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `variant="determinate"`. */
  determinate?: string,
  /** Styles applied to the root element if `variant="indeterminate"`. */
  indeterminate?: string,
  /** Styles applied to the root element if `variant="buffer"`. */
  buffer?: string,
  /** Styles applied to the root element if `variant="query"`. */
  query?: string,
  /** Styles applied to the additional bar element if `variant="buffer"`. */
  dashed?: string,
  /** Styles applied to the additional bar element if `variant="buffer"` and `color="primary"`. */
  dashedColorPrimary?: string,
  /** Styles applied to the additional bar element if `variant="buffer"` and `color="secondary"`. */
  dashedColorSecondary?: string,
  /** Styles applied to the layered bar1 and bar2 elements. */
  bar?: string,
  /** Styles applied to the bar elements if `color="primary"`; bar2 if `variant` not "buffer". */
  barColorPrimary?: string,
  /** Styles applied to the bar elements if `color="secondary"`; bar2 if `variant` not "buffer". */
  barColorSecondary?: string,
  /** Styles applied to the bar1 element if `variant="indeterminate or query"`. */
  bar1Indeterminate?: string,
  /** Styles applied to the bar1 element if `variant="determinate"`. */
  bar1Determinate?: string,
  /** Styles applied to the bar1 element if `variant="buffer"`. */
  bar1Buffer?: string,
  /** Styles applied to the bar2 element if `variant="indeterminate or query"`. */
  bar2Indeterminate?: string,
  /** Styles applied to the bar2 element if `variant="buffer"`. */
  bar2Buffer?: string,
}

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | @as("inherit") Inherit

type variant =
  | @as("determinate") Determinate
  | @as("indeterminate") Indeterminate
  | @as("buffer") Buffer
  | @as("query") Query

type props = {
  ...CommonProps.t,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The color of the component.
    * It supports both default and custom theme colors, which can be added as shown in the
    * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
    * @default 'primary'
    */
  color?: color,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The value of the progress indicator for the determinate and buffer variants.
    * Value between 0 and 100.
    */
  value?: int,
  /**
    * The value for the buffer variant.
    * Value between 0 and 100.
    */
  valueBuffer?: int,
  /**
    * The variant to use.
    * Use indeterminate or query when there is no progress value.
    * @default 'indeterminate'
    */
  variant?: variant,
}

@module("@mui/material/LinearProgress")
external make: React.component<props> = "default"
