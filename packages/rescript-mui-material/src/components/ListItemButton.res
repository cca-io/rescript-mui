type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the `component`'s `focusVisibleClassName` prop. */
  focusVisible?: string,
  /** Styles applied to the component element if dense. */
  dense?: string,
  /** Styles applied to the component element if `alignItems="flex-start"`. */
  alignItemsFlexStart?: string,
  /** State class applied to the inner `component` element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the inner `component` element if `divider={true}`. */
  divider?: string,
  /** Styles applied to the inner `component` element unless `disableGutters={true}`. */
  gutters?: string,
  /** State class applied to the root element if `selected={true}`. */
  selected?: string,
}

type alignItems =
  | @as("flex-start") FlexStart
  | @as("center") Center

type props = {
  ...ButtonBase.publicPropsWithOnClick,
  /**
   * Defines the `align-items` style property.
   * @default 'center'
   */
  alignItems?: alignItems,
  /**
   * If `true`, the list item is focused during the first mount.
   * Focus will also be triggered if the value changes from false to true.
   * @default false
   */
  autoFocus?: bool,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * If `true`, compact vertical padding designed for keyboard and mouse input is used.
   * The prop defaults to the value inherited from the parent List component.
   * @default false
   */
  dense?: bool,
  /**
   * If `true`, the component is disabled.
   * @default false
   */
  disabled?: bool,
  /**
   * If `true`, the left and right padding is removed.
   * @default false
   */
  disableGutters?: bool,
  /**
   * If `true`, a 1px light border is added to the bottom of the list item.
   * @default false
   */
  divider?: bool,
  /**
   * Use to apply selected styling.
   * @default false
   */
  selected?: bool,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "ListItemButton"
