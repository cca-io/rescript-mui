type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element if `orientation="horizontal"`. */
  horizontal: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical: string,
  /** Styles applied to the root element if `alternativeLabel={true}`. */
  alternativeLabel: string,
  /** State class applied to the root element if `active={true}`. */
  active: string,
  /** State class applied to the root element if `completed={true}`. */
  completed: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled: string,
  /** Styles applied to the line element. */
  line: string,
  /** Styles applied to the root element if `orientation="horizontal"`. */
  lineHorizontal: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  lineVertical: string,
}

type props = {
  ...CommonProps.t,
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
external make: props => React.element = "StepConnector"
