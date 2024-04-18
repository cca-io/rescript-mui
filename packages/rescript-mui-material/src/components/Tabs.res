type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** Styles applied to the flex container element. */
  flexContainer?: string,
  /** Styles applied to the flex container element if `orientation="vertical"`. */
  flexContainerVertical?: string,
  /** Styles applied to the flex container element if `centered={true}` & `!variant="scrollable"`. */
  centered?: string,
  /** Styles applied to the tablist element. */
  scroller?: string,
  /** Styles applied to the tablist element if `!variant="scrollable"`. */
  fixed?: string,
  /** Styles applied to the tablist element if `variant="scrollable"` and `orientation="horizontal"`. */
  scrollableX?: string,
  /** Styles applied to the tablist element if `variant="scrollable"` and `orientation="vertical"`. */
  scrollableY?: string,
  /** Styles applied to the tablist element if `variant="scrollable"` and `visibleScrollbar={false}`. */
  hideScrollbar?: string,
  /** Styles applied to the ScrollButtonComponent component. */
  scrollButtons?: string,
  /** Styles applied to the ScrollButtonComponent component if `allowScrollButtonsMobile={true}`. */
  scrollButtonsHideMobile?: string,
  /** Styles applied to the TabIndicator component. */
  indicator?: string,
}

type tabsActions = {
  updateIndicator: unit => unit,
  updateScrollButtons: unit => unit,
}

type slots = {
  @as("StartScrollButtonIcon") startScrollButtonIcon?: React.element,
  @as("EndScrollButtonIcon") endScrollButtonIcon?: React.element,
}

type slotProps<'value> = {
  startScrollButtonIcon?: 'value,
  endScrollButtonIcon?: 'value,
}

@unboxed
type indicatorColor =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | String(string)

type orientation =
  | @as("vertical") Vertical
  | @as("horizontal") Horizontal

@unboxed
type scrollButtons =
  | @as("auto") Auto
  | @as(true) True
  | @as(false) False

type tabIndicatorProps<'value> = 'value

type tabScrollButtonProps<'value> = 'value

type textColor =
  | @as("secondary") Secondary
  | @as("primary") Primary
  | @as("inherit") Inherit

type variant =
  | @as("standard") Standard
  | @as("scrollable") Scrollable
  | @as("fullWidth") FullWidth

type publicProps = {
  ...CommonProps.t,
  /**
    * Callback fired when the component mounts.
    * This is useful when you want to trigger an action programmatically.
    * It supports two actions: `updateIndicator()` and `updateScrollButtons()`
    *
    * @param {object} actions This object contains all possible actions
    * that can be triggered programmatically.
    */
  action?: React.ref<tabsActions>,
  /**
    * If `true`, the scroll buttons aren't forced hidden on mobile.
    * By default the scroll buttons are hidden on mobile and takes precedence over `scrollButtons`.
    * @default false
    */
  allowScrollButtonsMobile?: bool,
  /**
    * If `true`, the tabs are centered.
    * This prop is intended for large views.
    * @default false
    */
  centered?: bool,
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
  slotProps?: slotProps<unknown>,
  /**
    * Determines the color of the indicator.
    * @default 'primary'
    */
  indicatorColor?: indicatorColor,
  /**
    * The component orientation (layout flow direction).
    * @default 'horizontal'
    */
  orientation?: orientation,
  /**
    * The component used to render the scroll buttons.
    * @default TabScrollButton
    */
  @as("ScrollButtonComponent")
  scrollButtonComponent?: React.element,
  /**
    * Determine behavior of scroll buttons when tabs are set to scroll:
    *
    * - `auto` will only present them when not all the items are visible.
    * - `true` will always present them.
    * - `false` will never present them.
    *
    * By default the scroll buttons are hidden on mobile.
    * This behavior can be disabled with `allowScrollButtonsMobile`.
    * @default 'auto'
    */
  scrollButtons?: scrollButtons,
  /**
    * If `true` the selected tab changes on focus. Otherwise it only
    * changes on activation.
    */
  selectionFollowsFocus?: bool,
  /**
    * Props applied to the tab indicator element.
    * @default  {}
    */
  @as("TabIndicatorProps")
  tabIndicatorProps?: tabIndicatorProps<unknown>,
  /**
    * Props applied to the [`TabScrollButton`](/material-ui/api/tab-scroll-button/) element.
    * @default {}
    */
  @as("TabScrollButtonProps")
  tabScrollButtonProps?: tabScrollButtonProps<unknown>,
  /**
    * Determines the color of the `Tab`.
    * @default 'primary'
    */
  textColor?: textColor,
  /**
    *  Determines additional display behavior of the tabs:
    *
    *  - `scrollable` will invoke scrolling properties and allow for horizontally
    *  scrolling (or swiping) of the tab bar.
    *  -`fullWidth` will make the tabs grow to use all the available space,
    *  which should be used for small views, like on mobile.
    *  - `standard` will render the default state.
    * @default 'standard'
    */
  variant?: variant,
  /**
    * If `true`, the scrollbar is visible. It can be useful when displaying
    * a long vertical list of tabs.
    * @default false
    */
  visibleScrollbar?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  component?: OverridableComponent.t<unknown>,
}

type props<'value> = {
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
    * Callback fired when the value changes.
    *
    * @param {React.SyntheticEvent} event The event source of the callback. **Warning**: This is a generic event not a change event.
    * @param {any} value We default to the index of the child (number)
    */
  onChange?: (ReactEvent.Synthetic.t, 'value) => unit,
  /**
    * The value of the currently selected `Tab`.
    * If you don't want any selected `Tab`, you can set this prop to `false`.
    */
  value?: 'value,
}

@module("@mui/material/Tabs")
external make: React.component<props<'value>> = "default"
