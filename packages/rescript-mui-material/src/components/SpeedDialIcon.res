type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the icon component. */
  icon?: string,
  /** Styles applied to the icon component if `open={true}`. */
  iconOpen?: string,
  /** Styles applied to the icon when an `openIcon` is provided and if `open={true}`. */
  iconWithOpenIconOpen?: string,
  /** Styles applied to the `openIcon` if provided. */
  openIcon?: string,
  /** Styles applied to the `openIcon` if provided and if `open={true}`. */
  openIconOpen?: string,
}

type props = {
  ...CommonProps.t,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The icon to display.
   */
  icon?: React.element,
  /**
   * The icon to display in the SpeedDial Floating Action Button when the SpeedDial is open.
   */
  openIcon?: React.element,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material/SpeedDialIcon")
external make: React.component<props> = "default"
