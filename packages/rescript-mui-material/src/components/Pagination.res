type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the ul element. */
  ul?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="text"`. */
  text?: string,
}

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("standard") Standard
  | String(string)

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
  | String(string)

@unboxed
type variant =
  | @as("text") Text
  | @as("outlined") Outlined
  | String(string)

type getItemAriaLabelType =
  | @as("page") Page
  | @as("first") First
  | @as("last") Last
  | @as("next") Next
  | @as("previous") Previous

type paginationItemType =
  | @as("page") Page
  | @as("first") First
  | @as("last") Last
  | @as("next") Next
  | @as("previous") Previous
  | @as("start-ellipsis") StartEllipsis
  | @as("end-ellipsis") EndEllipsis

@unboxed
type page =
  | Number(int)
  | @as(null) Null

type usePaginationItem = {
  onClick: ReactEvent.Mouse.t => unit,
  @as("type") type_: paginationItemType,
  page: page,
  selected: bool,
  disabled: bool,
}

type shape =
  | @as("circular") Circular
  | @as("rounded") Rounded

type paginationRenderItemParams = {
  ...usePaginationItem,
  color: color,
  shape: shape,
  size: size,
  variant: variant,
}

type props = {
  ...CommonProps.t,
  ...UsePagination.props,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The active color.
   * It supports both default and custom theme colors, which can be added as shown in the
   * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
   * @default 'standard'
   */
  color?: color,
  /**
   * Accepts a function which returns a string value that provides a user-friendly name for the current page.
   * This is important for screen reader users.
   *
   * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
   * @param {string} type The link or button type to format ('page' | 'first' | 'last' | 'next' | 'previous'). Defaults to 'page'.
   * @param {number} page The page number to format.
   * @param {bool} selected If true, the current page is selected.
   * @returns {string}
   */
  getItemAriaLabel?: (getItemAriaLabelType, int, bool) => string,
  /**
   * Render the item.
   * @param {PaginationRenderItemParams} params The props to spread on a PaginationItem.
   * @returns {ReactNode}
   * @default (item) => <PaginationItem {...item} />
   */
  renderItem?: paginationRenderItemParams => React.element,
  /**
   * The shape of the pagination items.
   * @default 'circular'
   */
  shape?: shape,
  /**
   * The size of the component.
   * @default 'medium'
   */
  size?: size,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * The variant to use.
   * @default 'text'
   */
  variant?: variant,
}

@module("@mui/material")
external make: React.component<props> = "Pagination"
