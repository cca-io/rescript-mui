type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element when the parent `ListItem` has `disableGutters={true}`. */
  disableGutters: string,
}

type props = {
  ...CommonProps.t,
  /**
   * The content of the component, normally an `IconButton` or selection control.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: unit => React.element = "ListItemSecondaryAction"
