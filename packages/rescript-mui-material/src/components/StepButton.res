type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `orientation="horizontal"`. */
  horizontal?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** Styles applied to the `ButtonBase` touch-ripple. */
  touchRipple?: string,
}

type props = {
  ...ButtonBase.publicPropsWithOnClick,
  /**
	  * Override or extend the styles applied to the component.
	  */
  classes?: classes,
  /**
	  * The icon displayed by the step label.
	  */
  icon?: React.element,
  /**
	  * The optional node to display.
	  */
  optional?: React.element,
  /**
		* The system prop that allows defining system overrides as well as additional CSS styles.
	  */
  sx?: Sx.props,
}

@module("@mui/material/StepButton")
external make: React.component<props> = "default"
