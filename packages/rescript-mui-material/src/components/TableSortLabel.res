type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `direction="desc"`. */
  directionDesc?: string,
  /** Styles applied to the root element if `direction="asc"`. */
  directionAsc?: string,
  /** State class applied to the root element if `active={true}`. */
  active?: string,
  /** Styles applied to the icon component. */
  icon?: string,
  /** Styles applied to the icon component if `direction="desc"`.
  * @deprecated Combine the [.MuiTableSortLabel-icon](/material-ui/api/table-sort-label/#TableSortLabel-css-MuiTableSortLabel-icon) and [.MuiTableSortLabel-directionDesc](/material-ui/api/table-sort-label/#table-sort-label-classes-MuiTableSortLabel-directionDesc) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  iconDirectionDesc?: string,
  /** Styles applied to the icon component if `direction="asc"`.
  * @deprecated Combine the [.MuiTableSortLabel-icon](/material-ui/api/table-sort-label/#TableSortLabel-css-MuiTableSortLabel-icon) and [.MuiTableSortLabel-directionAsc](/material-ui/api/table-sort-label/#table-sort-label-classes-MuiTableSortLabel-directionAsc) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  iconDirectionAsc?: string,
}

type direction =
  | @as("asc") Asc
  | @as("desc") Desc

type slots = {
  /**
    * The component that renders the root slot.
    * @default 'span'
    */
  root?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the icon slot.
    * @default ArrowDownwardIcon
    */
  icon?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    */
  root?: JsxDOM.domProps,
  /**
    * Props forwarded to the icon slot.
    */
  icon?: JsxDOM.domProps,
}

type props = {
  ...ButtonBase.publicPropsWithOnClick,
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

@module("@mui/material/TableSortLabel")
external make: React.component<props> = "default"
