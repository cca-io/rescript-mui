type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `dividers={true}`. */
  dividers?: string,
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
   * Display the top and bottom dividers.
   * @default false
   */
  dividers?: bool,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "DialogContent"
