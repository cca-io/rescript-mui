type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the Typography component if primary and secondary are set. */
  multiline?: string,
  /** Styles applied to the Typography component if dense. */
  dense?: string,
  /** Styles applied to the root element if `inset={true}`. */
  inset?: string,
  /** Styles applied to the primary `Typography` component. */
  primary?: string,
  /** Styles applied to the secondary `Typography` component. */
  secondary?: string,
}

type slots = {
  /**
    * The component that renders the root slot.
    * @default 'div'
    */
  root?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the primary slot.
    * @default Typography
    */
  primary?: OverridableComponent.t<Typography.props>,
  /**
    * The component that renders the secondary slot.
    * @default Typography
    */
  secondary?: OverridableComponent.t<Typography.props>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    */
  root?: JsxDOM.domProps,
  /**
    * Props forwarded to the primary slot.
    */
  primary?: Typography.props,
  /**
    * Props forwarded to the secondary slot.
    */
  secondary?: Typography.props,
}

type props = {
  ...CommonProps.t,
  /**
    * Alias for the `primary` prop.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, the children won't be wrapped by a Typography component.
    * This can be useful to render an alternative Typography variant by wrapping
    * the `children` (or `primary`) text, and optional `secondary` text
    * with the Typography component.
    * @default false
    */
  disableTypography?: bool,
  /**
    * If `true`, the children are indented.
    * This should be used if there is no left avatar or left icon.
    * @default false
    */
  inset?: bool,
  /**
    * The main content element.
    */
  primary?: React.element,
  /**
    * These props will be forwarded to the primary typography component
    * (as long as disableTypography is not `true`).
    * @deprecated Use `slotProps.primary` instead. This prop will be removed in v7.
    */
  primaryTypographyProps?: Typography.props,
  /**
    * The secondary content element.
    */
  secondary?: React.element,
  /**
    * These props will be forwarded to the secondary typography component
    * (as long as disableTypography is not `true`).
    * @deprecated Use `slotProps.secondary` instead. This prop will be removed in v7.
    */
  secondaryTypographyProps?: Typography.props,
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
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/ListItemText")
external make: React.component<props> = "default"
