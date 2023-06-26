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
    */
  primaryTypographyProps?: Typography.props,
  /**
    * The secondary content element.
    */
  secondary?: React.element,
  /**
    * These props will be forwarded to the secondary typography component
    * (as long as disableTypography is not `true`).
    */
  secondaryTypographyProps?: Typography.props,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/ListItemText")
external make: React.component<props> = "default"
