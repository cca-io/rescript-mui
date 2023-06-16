type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="head"` or `context.table.head`. */
  head?: string,
  /** Styles applied to the root element if `variant="body"` or `context.table.body`. */
  body?: string,
  /** Styles applied to the root element if `variant="footer"` or `context.table.footer`. */
  footer?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="medium"`. */
  sizeMedium?: string,
  /** Styles applied to the root element if `padding="checkbox"`. */
  paddingCheckbox?: string,
  /** Styles applied to the root element if `padding="none"`. */
  paddingNone?: string,
  /** Styles applied to the root element if `align="left"`. */
  alignLeft?: string,
  /** Styles applied to the root element if `align="center"`. */
  alignCenter?: string,
  /** Styles applied to the root element if `align="right"`. */
  alignRight?: string,
  /** Styles applied to the root element if `align="justify"`. */
  alignJustify?: string,
  /** Styles applied to the root element if `context.table.stickyHeader={true}`. */
  stickyHeader?: string,
}

type align =
  | @as("inherit") Inherit
  | @as("left") Left
  | @as("center") Center
  | @as("right") Right
  | @as("justify") Justify

type padding =
  | @as("normal") Normal
  | @as("checkbox") Checkbox
  | @as("none") None

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium

@unboxed
type sortDirection =
  | @as("asc") Asc
  | @as("desc") Desc
  | @as(false) False

@unboxed
type variant =
  | @as("head") Head
  | @as("body") Body
  | @as("footer") Footer
  | String(string)

type publicProps = {
  ...CommonProps.t,
  /**
   * Set the text-align on the table cell content.
   *
   * Monetary or generally number fields **should be right aligned** as that allows
   * you to add them up quickly in your head without having to worry about decimals.
   * @default 'inherit'
   */
  align?: /**
   * Set the text-align on the table cell content.
   *
   * Monetary or generally number fields **should be right aligned** as that allows
   * you to add them up quickly in your head without having to worry about decimals.
   * @default 'inherit'
   */
  align,
  /**
   * Sets the padding applied to the cell.
   * The prop defaults to the value (`'default'`) inherited from the parent Table component.
   */
  padding?: padding,
  /**
   * Set scope attribute.
   */
  scope?: string,
  /**
   * Specify the size of the cell.
   * The prop defaults to the value (`'medium'`) inherited from the parent Table component.
   */
  size?: size,
  /**
   * Set aria-sort direction.
   */
  sortDirection?: sortDirection,
  /**
   * Specify the cell type.
   * The prop defaults to the value inherited from the parent TableHead, TableBody, or TableFooter components.
   */
  variant?: variant,
}

type props = {
  ...publicProps,
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The component used for the root node.
   * Either a string to use a HTML element or a component.
   */
  component?: OverridableComponent.t<unknown>,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material/TableCell")
external make: React.component<props> = "default"
