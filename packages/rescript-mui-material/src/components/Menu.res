type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the Paper component. */
  paper?: string,
  /** Styles applied to the List component via `MenuList`. */
  list?: string,
}

type props = {
  ...Popover.publicProps,
  /**
   * If `true` (Default) will focus the `[role="menu"]` if no focusable child is found. Disabled
   * children are not focusable. If you set this prop to `false` focus will be placed
   * on the parent modal container. This has severe accessibility implications
   * and should only be considered if you manage focus otherwise.
   * @default true
   */
  autoFocus?: bool,
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
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * The variant to use. Use `menu` to prevent selected items from impacting the initial focus.
   * @default 'selectedMenu'
   */
  variant?: MenuList.variant,
}

@module("@mui/material")
external make: React.component<props> = "Menu"
