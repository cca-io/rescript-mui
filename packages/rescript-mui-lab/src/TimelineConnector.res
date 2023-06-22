type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type props = {
  ...Mui.CommonProps.t,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Mui.Sx.props,
}

@module("@mui/lab/TimelineConnector")
external make: React.component<props> = "default"
