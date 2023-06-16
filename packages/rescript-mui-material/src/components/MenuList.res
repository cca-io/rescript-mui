type variant =
  | @as("menu") Menu
  | @as("selectedMenu") SelectedMenu

type props = {
  ...List.props,
  /**
     * If `true`, will focus the `[role="menu"]` container and move into tab order.
     * @default false
     */
  autoFocus?: bool,
  /**
     * If `true`, will focus the first menuitem if `variant="menu"` or selected item
     * if `variant="selectedMenu"`.
     * @default false
     */
  autoFocusItem?: bool,
  /**
     * If `true`, will allow focus on disabled items.
     * @default false
     */
  disabledItemsFocusable?: bool,
  /**
     * If `true`, the menu items will not wrap focus.
     * @default false
     */
  disableListWrap?: bool,
  /**
     * The variant to use. Use `menu` to prevent selected items from impacting the initial focus
     * and the vertical alignment relative to the anchor element.
     * @default 'selectedMenu'
     */
  variant?: variant,
}

@module("@mui/material/MenuList")
external make: React.component<props> = "default"
