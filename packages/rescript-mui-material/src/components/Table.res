type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `stickyHeader={true}`. */
  stickyHeader?: string,
}

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | String(string)

type padding =
  | @as("normal") Normal
  | @as("checkbox") Checkbox
  | @as("none") None

type props = {
  ...CommonProps.t,
  /**
     * The content of the table, normally `TableHead` and `TableBody`.
     */
  children?: React.element,
  /**
     * Override or extend the styles applied to the component.
     */
  classes?: classes,
  /**
     * The component used for the root node. Either a string to use a HTML element or a component.
     */
  component?: OverridableComponent.t<unknown>,
  /**
     * Allows TableCells to inherit padding of the Table.
     * @default 'normal'
     */
  padding?: padding,
  /**
     * Allows TableCells to inherit size of the Table.
     * @default 'medium'
     */
  size?: size,
  /**
     * Set the header sticky.
     *
     * ⚠️ It doesn't work with IE11.
     * @default false
     */
  stickyHeader?: bool,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
}

@module("@mui/material/Table")
external make: React.component<props> = "default"
