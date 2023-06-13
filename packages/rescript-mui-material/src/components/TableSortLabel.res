type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** State class applied to the root element if `active={true}`. */
  active: string,
  /** Styles applied to the icon component. */
  icon: string,
  /** Styles applied to the icon component if `direction="desc"`. */
  iconDirectionDesc: string,
  /** Styles applied to the icon component if `direction="asc"`. */
  iconDirectionAsc: string,
}

type direction =
  | @as("asc") Asc
  | @as("desc") Desc

type props = {
  ...ButtonBase.publicProps,
  /**
     * If `true`, the label will have the active styling (should be true for the sorted column).
     * @default false
     */
  active?: bool,
  /**
     * Override or extend the styles applied to the component.
     */
  classes?: classes,
  /**
     * The current sort direction.
     * @default 'asc'
     */
  direction?: direction,
  /**
     * If `true`, the component is disabled.
     * @default false
     */
  disabled?: bool,
  /**
     * Hide sort icon when active is false.
     * @default false
     */
  hideSortIcon?: bool,
  /**
     * Sort icon to use.
     * @default ArrowDownwardIcon
     */
  @as("IconComponent")
  iconComponent?: React.component<CommonProps.classNameOnly>,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
}

@module("@mui/material")
external make: props => React.element = "TableSortLabel"
