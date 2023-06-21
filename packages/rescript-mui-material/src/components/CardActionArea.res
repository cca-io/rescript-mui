type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the ButtonBase root element if the action area is keyboard focused. */
  focusVisible?: string,
  /** Styles applied to the overlay that covers the action area when it is keyboard focused. */
  focusHighlight?: string,
}

type props = {
  ...ButtonBase.publicProps,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/CardActionArea")
external make: React.component<props> = "default"
