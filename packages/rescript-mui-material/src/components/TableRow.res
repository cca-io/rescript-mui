type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if `selected={true}`. */
  selected?: string,
  /** State class applied to the root element if `hover={true}`. */
  hover?: string,
  /** Styles applied to the root element if table variant="head". */
  head?: string,
  /** Styles applied to the root element if table variant="footer". */
  footer?: string,
}

type props = {
  ...CommonProps.t,
  /**
     * Should be valid <tr> children such as `TableCell`.
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
     * If `true`, the table row will shade on hover.
     * @default false
     */
  hover?: bool,
  /**
     * If `true`, the table row will have the selected shading.
     * @default false
     */
  selected?: bool,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "TableRow"
