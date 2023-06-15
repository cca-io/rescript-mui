type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the Toolbar component. */
  toolbar?: string,
  /** Styles applied to the spacer element. */
  spacer?: string,
  /** Styles applied to the select label Typography element. */
  selectLabel?: string,
  /** Styles applied to the Select component `root` element. */
  selectRoot?: string,
  /** Styles applied to the Select component `select` class. */
  select?: string,
  /** Styles applied to the Select component `icon` class. */
  selectIcon?: string,
  /** Styles applied to the Select component `root` element. */
  input?: string,
  /** Styles applied to the MenuItem component. */
  menuItem?: string,
  /** Styles applied to the displayed rows Typography element. */
  displayedRows?: string,
  /** Styles applied to the internal `TablePaginationActions` component. */
  actions?: string,
}

type itemAriaLabelType =
  | @as("first") First
  | @as("last") Last
  | @as("next") Next
  | @as("previous") Previous

type actionsProps = {
  backIconButtonProps?: IconButton.props,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: unknown,
  count: int,
  /**
   * Accepts a function which returns a string value that provides a user-friendly name for the current page.
   * This is important for screen reader users.
   *
   * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
   * @param {string} type The link or button type to format ('first' | 'last' | 'next' | 'previous').
   * @returns {string}
   */
  getItemAriaLabel?: itemAriaLabelType => string,
  nextIconButtonProps?: IconButton.props,
  onPageChange: (ReactEvent.Mouse.t, int) => unit,
  page: int,
  rowsPerPage: int,
  showFirstButton: bool,
  showLastButton: bool,
}

type rowsPerPageOptionsObj = {value?: int, label?: string}

@unboxed
type rowsPerPageOptions =
  | Number(int)
  | Object(rowsPerPageOptionsObj)

type labelDisplayedRowsArgs = {
  from: int,
  to: int,
  count: int,
  page: int,
}

type props = {
  ...TableCell.publicProps,
  /**
       * The total number of rows.
       *
       * To enable server side pagination for an unknown number of items, provide -1.
       */
  count: int,
  /**
       * Callback fired when the page is changed.
       *
       * @param {React.MouseEvent<HTMLButtonElement> | null} event The event source of the callback.
       * @param {number} page The page selected.
       */
  onPageChange: (ReactEvent.Mouse.t, int) => unit,
  /**
       * The zero-based index of the current page.
       */
  page: int,
  /**
       * The number of rows per page.
       *
       * Set -1 to display all the rows.
       */
  rowsPerPage: int,
  /**
       * The component used for displaying the actions.
       * Either a string to use a HTML element or a component.
       * @default TablePaginationActions
       */
  @as("ActionsComponent")
  actionsComponent?: React.component<actionsProps>,
  /**
       * Props applied to the back arrow [`IconButton`](/material-ui/api/icon-button/) component.
       */
  backIconButtonProps?: IconButton.props,
  /**
       * Override or extend the styles applied to the component.
       */
  classes?: classes,
  /**
   * The component used for the root node.
   * Either a string to use a HTML element or a component.
   */
  component?: React.component<unknown>,
  /**
       * Accepts a function which returns a string value that provides a user-friendly name for the current page.
       * This is important for screen reader users.
       *
       * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
       * @param {string} type The link or button type to format ('first' | 'last' | 'next' | 'previous').
       * @returns {string}
       * @default function defaultGetAriaLabel(type) {
       *   return `Go to ${type} page`,
       * }
       */
  getItemAriaLabel?: itemAriaLabelType => string,
  /**
       * Customize the displayed rows label. Invoked with a `{ from, to, count, page }`
       * object.
       *
       * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
       * @default function defaultLabelDisplayedRows({ from, to, count }) {
       *   return `${from}–${to} of ${count !== -1 ? count : `more than ${to}`}`,
       * }
       */
  labelDisplayedRows?: labelDisplayedRowsArgs => React.element,
  /**
       * Customize the rows per page label.
       *
       * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
       * @default 'Rows per page:'
       */
  labelRowsPerPage?: React.element,
  /**
       * Props applied to the next arrow [`IconButton`](/material-ui/api/icon-button/) element.
       */
  nextIconButtonProps?: IconButton.props,
  /**
       * Callback fired when the number of rows per page is changed.
       *
       * @param {React.ChangeEvent<HTMLTextAreaElement | HTMLInputElement>} event The event source of the callback.
       */
  onRowsPerPageChange?: ReactEvent.Synthetic.t => unit,
  /**
       * Customizes the options of the rows per page select field. If less than two options are
       * available, no select field will be displayed.
       * Use -1 for the value with a custom label to show all the rows.
       * @default [10, 25, 50, 100]
       */
  rowsPerPageOptions?: array<rowsPerPageOptions>,
  /**
       * Props applied to the rows per page [`Select`](/material-ui/api/select/) element.
       * @default {}
       */
  @as("SelectProps")
  selectProps?: Select.props<int>,
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
       * The system prop that allows defining system overrides as well as additional CSS styles.
       */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "TablePagination"
