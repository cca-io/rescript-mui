type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `position="left"`. */
  positionLeft?: string,
  /** Styles applied to the root element if `position="right"`. */
  positionRight?: string,
  /** Styles applied to the root element if `position="alternate"`. */
  positionAlternate?: string,
  /** Styles applied to the root element if `position="alternate-reverse"`. */
  positionAlternateReverse?: string,
}

type position =
  | @as("left") Left
  | @as("right") Right
  | @as("alternate") Alternate
  | @as("alternate-reverse") AlternateReverse

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
    * The position where the TimelineContent should appear relative to the time axis.
    * @default 'right'
    */
  position?: position,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Mui.Sx.props,
}

@module("@mui/lab/Timeline")
external make: React.component<props> = "default"
