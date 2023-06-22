type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `position="right"`. */
  positionRight?: string,
  /** Styles applied to the root element if `position="left"`. */
  positionLeft?: string,
  /** Styles applied to the root element if `position="alternate"`. */
  positionAlternate?: string,
  /** Styles applied to the root element if `position="alternate-reverse"`. */
  positionAlternateReverse?: string,
}

type props = {
  ...Mui.Typography.publicProps,
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

@module("@mui/lab/TimelineOppositeContent")
external make: React.component<props> = "default"
