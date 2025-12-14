type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the Paper component. */
  paper?: string,
  /** Styles applied to the List component via `MenuList`. */
  list?: string,
}

type slots = {
  ...Popover.slots,
  /**
    * The component used for the list.
    * @default MenuList
    */
  list?: OverridableComponent.t<MenuList.props>,
}

type slotProps = {
  ...Popover.slotProps,
  /**
    * Props forwarded to the list slot.
    * By default, the avaible props are based on the [MenuList](https://mui.com/material-ui/api/menu-list/#props) component.
    */
  list?: MenuList.props,
}

type props = {
  ...Popover.publicProps,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * When opening the menu will not focus the active item but the `[role="menu"]`
    * unless `autoFocus` is also set to `false`. Not using the default means not
    * following WAI-ARIA authoring practices. Please be considerate about possible
    * accessibility implications.
    * @default false
    */
  disableAutoFocusItem?: bool,
  /**
    * Props applied to the [`MenuList`](/material-ui/api/menu-list/) element.
    * @deprecated use the `slotProps.list` prop instead. This prop will be removed in v7. See [Migrating from deprecated APIs](https://mui.com/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    * @default {}
    */
  @as("MenuListProps")
  menuListProps?: MenuList.props,
  /**
    * `classes` prop applied to the [`Popover`](/material-ui/api/popover/) element.
    */
  @as("PopoverClasses")
  popoverClasses?: Popover.classes,
  /**
    * The components used for each slot inside.
    * @default {}
    */
  slots?: slots,
  /**
    * The props used for each slot inside.
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The variant to use. Use `menu` to prevent selected items from impacting the initial focus.
    * @default 'selectedMenu'
    */
  variant?: MenuList.variant,
}

@module("@mui/material/Menu")
external make: React.component<props> = "default"
