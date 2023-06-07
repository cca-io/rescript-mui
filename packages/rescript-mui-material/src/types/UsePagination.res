type props = {
  /**
   * Number of always visible pages at the beginning and end.
   * @default 1
   */
  boundaryCount?: int,
  /**
   * The name of the component where this hook is used.
   */
  componentName?: string,
  /**
   * The total number of pages.
   * @default 1
   */
  count?: int,
  /**
   * The page selected by default when the component is uncontrolled.
   * @default 1
   */
  defaultPage?: int,
  /**
   * If `true`, the component is disabled.
   * @default false
   */
  disabled?: bool,
  /**
   * If `true`, hide the next-page button.
   * @default false
   */
  hideNextButton?: bool,
  /**
   * If `true`, hide the previous-page button.
   * @default false
   */
  hidePrevButton?: bool,
  /**
   * Callback fired when the page is changed.
   *
   * @param {React.ChangeEvent<unknown>} event The event source of the callback.
   * @param {number} page The page selected.
   */
  onChange?: (ReactEvent.Synthetic.t, int) => unit,
  /**
   * The current page.
   */
  page?: int,
  /**
   * If `true`, show the first-page button.
   * @default false
   */
  showFirstButton?: bool,
  /**
   * If `true`, show the last-page button.
   * @default false
   */
  showLastButton?: bool,
  /**
   * Number of always visible pages before and after the current page.
   * @default 1
   */
  siblingCount?: int,
}
