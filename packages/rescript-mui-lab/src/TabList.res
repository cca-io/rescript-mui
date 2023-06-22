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

type props<'value> = {
  ...Mui.Tabs.publicProps,
  /**
    * A list of `<Tab />` elements.
    */
  children: React.element,
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

@module("@mui/lab/TabList")
external make: React.component<props<'value>> = "default"
