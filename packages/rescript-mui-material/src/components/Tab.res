type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element if both `icon` and `label` are provided. */
  labelIcon: string,
  /** Styles applied to the root element if the parent [`Tabs`](/material-ui/api/tabs/) has `textColor="inherit"`. */
  textColorInherit: string,
  /** Styles applied to the root element if the parent [`Tabs`](/material-ui/api/tabs/) has `textColor="primary"`. */
  textColorPrimary: string,
  /** Styles applied to the root element if the parent [`Tabs`](/material-ui/api/tabs/) has `textColor="secondary"`. */
  textColorSecondary: string,
  /** State class applied to the root element if `selected={true}` (controlled by the Tabs component). */
  selected: string,
  /** State class applied to the root element if `disabled={true}` (controlled by the Tabs component). */
  disabled: string,
  /** Styles applied to the root element if `fullWidth={true}` (controlled by the Tabs component). */
  fullWidth: string,
  /** Styles applied to the root element if `wrapped={true}`. */
  wrapped: string,
  /** Styles applied to the wrapper element of `icon` if `icon` is provided. */
  iconWrapper: string,
}

type iconPosition =
  | @as("top") Top
  | @as("bottom") Bottom
  | @as("start") Start
  | @as("end") End

type props<'a> = {
  ...CommonProps.t,
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
     * If `true`, the  keyboard focus ripple is disabled.
     * @default false
     */
  disableFocusRipple?: bool,
  /**
     * The icon to display.
     */
  icon?: React.element,
  /**
     * The position of the icon relative to the label.
     * @default 'top'
     */
  iconPosition?: iconPosition,
  /**
     * The label element.
     */
  label?: React.element,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
  /**
     * You can provide your own value. Otherwise, we fallback to the child position index.
     */
  value?: 'a,
  /**
     * Tab labels appear in a single row.
     * They can use a second line if needed.
     * @default false
     */
  wrapped?: bool,
}

@module("@mui/material")
external make: props<'a> => React.element = "Tab"
