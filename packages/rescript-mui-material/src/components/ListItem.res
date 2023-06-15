type classes = {
  /** Styles applied to the (normally root) `component` element. May be wrapped by a `container`. */
  root?: string,
  /** Styles applied to the container element if `children` includes `ListItemSecondaryAction`. */
  container?: string,
  /** State class applied to the `component`'s `focusVisibleClassName` prop if `button={true}`. */
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
  /** Styles applied to the root element unless `disablePadding={true}`. */
  padding?: string,
  /** Styles applied to the inner `component` element if `button={true}`. */
  button?: string,
  /** Styles applied to the component element if `children` includes `ListItemSecondaryAction`. */
  secondaryAction?: string,
  /** State class applied to the root element if `selected={true}`. */
  selected?: string,
}

type alignItems =
  | @as("flex-start") FlexStart
  | @as("center") Center

type slotProps = {root?: unknown}

type slots = {root?: React.element}

type props = {
  ...CommonProps.t,
  /**
   * Defines the `align-items` style property.
   * @default 'center'
   */
  alignItems?: alignItems,
  /**
   * The content of the component if a `ListItemSecondaryAction` is used it must
   * be the last child.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The component used for the root node. Either a string to use a HTML element or a component.
   */
  component?: OverridableComponent.t<unknown>,
  /**
   * If `true`, compact vertical padding designed for keyboard and mouse input is used.
   * The prop defaults to the value inherited from the parent List component.
   * @default false
   */
  dense?: bool,
  /**
   * If `true`, the left and right padding is removed.
   * @default false
   */
  disableGutters?: bool,
  /**
   * If `true`, all padding is removed.
   * @default false
   */
  disablePadding?: bool,
  /**
   * If `true`, a 1px light border is added to the bottom of the list item.
   * @default false
   */
  divider?: bool,
  /**
   * The element to display at the end of ListItem.
   */
  secondaryAction?: React.element,
  /**
       * The extra props for the slot components.
       * You can override the existing props or add new ones.
       *
       * This prop is an alias for the `componentsProps` prop, which will be deprecated in the future.
       *
       * @default {}
       */
  slotProps?: slotProps,
  /**
       * The components used for each slot inside.
       *
       * This prop is an alias for the `components` prop, which will be deprecated in the future.
       *
       * @default {}
       */
  slots?: slots,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "ListItem"
