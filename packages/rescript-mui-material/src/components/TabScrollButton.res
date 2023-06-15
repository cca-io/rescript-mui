type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
}

type slots = {
  @as("StartScrollButtonIcon") startScrollButtonIcon?: React.element,
  @as("EndScrollButtonIcon") endScrollButtonIcon?: React.element,
}

type slotProps = {
  startScrollButtonIcon?: SvgIcon.props,
  endScrollButtonIcon?: SvgIcon.props,
}

type direction =
  | @as("left") Left
  | @as("right") Right

type orientation =
  | @as("horizontal") Horizontal
  | @as("vertical") Vertical

type props = {
  ...CommonProps.clickablePropsWithOnClick,
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The components used for each slot inside.
   * @default {}
   */
  slots?: slots,
  /**
   * The extra props for the slot components.
   * You can override the existing props or add new ones.
   * @default {}
   */
  slotProps?: slotProps,
  /**
   * The direction the button should indicate.
   */
  direction: direction,
  /**
   * If `true`, the component is disabled.
   * @default false
   */
  disabled?: bool,
  /**
   * The component orientation (layout flow direction).
   */
  orientation: orientation,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "TabScrollButton"
