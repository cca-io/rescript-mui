type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the message wrapper element. */
  message?: string,
  /** Styles applied to the action wrapper element if `action` is provided. */
  action?: string,
}

type action = React.element

type message = React.element

type props = {
  ...Paper.publicProps,
  /**
   * The action to display. It renders after the message, at the end of the snackbar.
   */
  action?: action,
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The message to display.
   */
  message?: message,
  /**
   * The ARIA role attribute of the element.
   * @default 'alert'
   */
  role?: string,
  /**
    * The variant to use.
    * @default 'elevation'
  */
  variant?: Paper.variant,
}

@module("@mui/material/SnackbarContent")
external make: React.component<props> = "default"
