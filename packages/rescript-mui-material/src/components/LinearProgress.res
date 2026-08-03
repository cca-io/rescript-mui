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
  /** Styles applied to the additional bar element if `variant="buffer"` and `color="primary"`.
  * @deprecated Combine the [.MuiLinearProgress-dashed](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-dashed) and [.MuiLinearProgress-colorPrimary](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-colorPrimary) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
  dashedColorPrimary?: string,
  /** Styles applied to the additional bar element if `variant="buffer"` and `color="secondary"`.
  * @deprecated Combine the [.MuiLinearProgress-dashed](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-dashed) and [.MuiLinearProgress-colorSecondary](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-colorSecondary) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
  dashedColorSecondary?: string,
  /** Styles applied to the layered bar1 and bar2 elements. */
  bar?: string,
  /** Styles applied to the bar1 element. */
  bar1?: string,
  /** Styles applied to the bar2 element. */
  bar2?: string,
  /** Styles applied to the bar elements if `color="primary"`; bar2 if `variant` not "buffer".
  * @deprecated Use the [.MuiLinearProgress-bar](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-bar) and [.MuiLinearProgress-colorPrimary](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-colorPrimary) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
  barColorPrimary?: string,
  /** Styles applied to the bar elements if `color="secondary"`; bar2 if `variant` not "buffer".
  * @deprecated Use the [.MuiLinearProgress-bar](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-bar) and [.MuiLinearProgress-colorSecondary](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-colorSecondary) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
  barColorSecondary?: string,
  /** Styles applied to the bar1 element if `variant="indeterminate or query"`.
  * @deprecated Use the [.MuiLinearProgress-bar1](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-bar1) and [.MuiLinearProgress-indeterminate](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-indeterminate) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
  bar1Indeterminate?: string,
  /** Styles applied to the bar1 element if `variant="determinate"`.
  * @deprecated Use the [.MuiLinearProgress-bar1](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-bar1) and [.MuiLinearProgress-determinate](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-determinate) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
  bar1Determinate?: string,
  /** Styles applied to the bar1 element if `variant="buffer"`.
  * @deprecated Use the [.MuiLinearProgress-bar1](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-bar1) and [.MuiLinearProgress-buffer](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-buffer) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
  bar1Buffer?: string,
  /** Styles applied to the bar2 element if `variant="indeterminate or query"`.
  * @deprecated Use the [.MuiLinearProgress-bar2](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-bar2) and [.MuiLinearProgress-indeterminate](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-indeterminate) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
  bar2Indeterminate?: string,
  /** Styles applied to the bar2 element if `variant="buffer"`.
  * @deprecated Use the [.MuiLinearProgress-bar2](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-bar2) and [.MuiLinearProgress-buffer](/material-ui/api/linear-progress/#linear-progress-classes-MuiLinearProgress-buffer) classes instead. [How to migrate](/material-ui/migration/migrating-from-deprecated-apis/)
  */
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
