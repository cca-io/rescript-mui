type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `type="page"`. */
  page?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="large"`. */
  sizeLarge?: string,
  /** Styles applied to the root element if `variant="text"`. */
  text?: string,
  /** Styles applied to the root element if `variant="text"` and `color="primary"`. */
  textPrimary?: string,
  /** Styles applied to the root element if `variant="text"` and `color="secondary"`. */
  textSecondary?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="outlined"` and `color="primary"`. */
  outlinedPrimary?: string,
  /** Styles applied to the root element if `variant="outlined"` and `color="secondary"`. */
  outlinedSecondary?: string,
  /** Styles applied to the root element if `rounded="true"`. */
  rounded?: string,
  /** Styles applied to the root element if `type="start-ellipsis"` or `type="end-ellipsis"`. */
  ellipsis?: string,
  /** Styles applied to the root element if `type="first"` or type="last". */
  firstLast?: string,
  /** Styles applied to the root element if `type="previous"` or type="next". */
  previousNext?: string,
  /** State class applied to the root element if keyboard focused. */
  focusVisible?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** State class applied to the root element if `selected={true}`. */
  selected?: string,
  /** Styles applied to the icon to display. */
  icon?: string,
}

@unboxed
type color =
  | @as("standard") Standard
  | @as("primary") Primary
  | @as("secondary") Secondary
  | String(string)

type shape =
  | @as("circular") Circular
  | @as("rounded") Rounded

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
  | String(string)

type slots = {
  first?: React.element,
  last?: React.element,
  next?: React.element,
  previous?: React.element,
}

type type_ =
  | @as("page") Page
  | @as("first") First
  | @as("last") Last
  | @as("next") Next
  | @as("previous") Previous
  | @as("start-ellipsis") StartEllipsis
  | @as("end-ellipsis") EndEllipsis

@unboxed
type variant =
  | @as("text") Text
  | @as("outlined") Outlined
  | String(string)

type props = {
  ...CommonProps.t,
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
       * The component used for the root node. Either a string to use a HTML element or a component.
       */
  component?: OverridableComponent.t<unknown>,
  /**
     * If `true`, the component is disabled.
     * @default false
     */
  disabled?: bool,
  /**
     * The current page number.
     */
  page?: React.element,
  /**
     * If `true` the pagination item is selected.
     * @default false
     */
  selected?: bool,
  /**
     * The shape of the pagination item.
     * @default 'circular'
     */
  shape?: shape,
  /**
     * The size of the component.
     * @default 'medium'
     */
  size?: size,
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
  /**
     * The type of pagination item.
     * @default 'page'
     */
  @as("type")
  type_?: type_,
  /**
     * The variant to use.
     * @default 'text'
     */
  variant?: variant,
}

@module("@mui/material/PaginationItem")
external make: React.component<props> = "default"
