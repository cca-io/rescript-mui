type classes = {
  /** Class name applied to the root element. */
  root: string,
  /** Class name applied to the root element if the `Modal` has exited. */
  hidden: string,
  /** Class name applied to the backdrop element. */
  backdrop: string,
}

type reason =
  | @as("escapeKeyDown") EscapeKeyDown
  | @as("backdropClick") BackdropClick

type onClose = (ReactEvent.Synthetic.t, reason) => unit

type components = {
  @as("Root") root?: React.element,
  @as("Backdrop") backdrop?: React.element,
}

type componentsProps = {
  root?: unknown,
  backdrop?: unknown,
}

type publicProps = {
  ...CommonProps.t,
  /**
   * When set to true the Modal waits until a nested Transition is completed before closing.
   * @default false
   */
  closeAfterTransition?: bool,
  /**
     * The component used for the root node. Either a string to use a HTML element or a component.
     */
  component?: OverridableComponent.t<unknown>,
  /**
   * If `true`, the modal will not automatically shift focus to itself when it opens, and
   * replace it to the last focused element when it closes.
   * This also works correctly with any modal children that have the `disableAutoFocus` prop.
   *
   * Generally this should never be set to `true` as it makes the modal less
   * accessible to assistive technologies, like screen readers.
   * @default false
   */
  disableAutoFocus?: bool,
  /**
   * If `true`, the modal will not prevent focus from leaving the modal while open.
   *
   * Generally this should never be set to `true` as it makes the modal less
   * accessible to assistive technologies, like screen readers.
   * @default false
   */
  disableEnforceFocus?: bool,
  /**
   * If `true`, hitting escape will not fire the `onClose` callback.
   * @default false
   */
  disableEscapeKeyDown?: bool,
  /**
   * The `children` will be under the DOM hierarchy of the parent component.
   * @default false
   */
  disablePortal?: bool,
  /**
   * If `true`, the modal will not restore focus to previously focused element once
   * modal is hidden or unmounted.
   * @default false
   */
  disableRestoreFocus?: bool,
  /**
   * Disable the scroll lock behavior.
   * @default false
   */
  disableScrollLock?: bool,
  /**
   * If `true`, the backdrop is not rendered.
   * @default false
   */
  hideBackdrop?: bool,
  /**
   * Always keep the children in the DOM.
   * This prop can be useful in SEO situation or
   * when you want to maximize the responsiveness of the Modal.
   * @default false
   */
  keepMounted?: bool,
}

type props = {
  ...publicProps,
  /**
   * If `true`, the component is shown.
   */
  @as("open")
  open_: bool,
  /**
   * A single child content element.
   */
  children: React.element,
  /**
     * Override or extend the styles applied to the component.
     */
  classes?: classes,
  /**
   * An HTML element or function that returns one.
   * The `container` will have the portal children appended to it.
   *
   * By default, it uses the body of the top-level document object,
   * so it's simply `document.body` most of the time.
   */
  container?: React.element,
  /**
   * Callback fired when the component requests to be closed.
   * The `reason` parameter can optionally be used to control the response to `onClose`.
   *
   * @param {object} event The event source of the callback.
   * @param {string} reason Can be: `"escapeKeyDown"`, `"backdropClick"`.
   */
  onClose?: onClose,
  /**
   * The components used for each slot inside the Modal.
   * Either a string to use a HTML element or a component.
   * @default {}
   */
  slots?: components,
  /**
   * The props used for each slot inside the Modal.
   * @default {}
   */
  slotProps?: componentsProps,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
}

@module("@mui/material")
external make: props => React.element = "Modal"
