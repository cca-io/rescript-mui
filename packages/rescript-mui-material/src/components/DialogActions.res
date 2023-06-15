type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element unless `disableSpacing={true}`. */
  spacing?: string,
}

type props = {
  ...CommonProps.t,
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * If `true`, the actions do not have additional margin.
   * @default false
   */
  disableSpacing?: bool,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "DialogActions"
