type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element unless `disableGutters={true}`. */
  gutters?: string,
  /** Styles applied to the root element if `variant="regular"`. */
  regular?: string,
  /** Styles applied to the root element if `variant="dense"`. */
  dense?: string,
}

@unboxed
type variant =
  | @as("regular") Regular
  | @as("dense") Dense
  | String(string)

type props = {
  ...CommonProps.t,
  /**
    * The Toolbar children, usually a mixture of `IconButton`, `Button` and `Typography`.
    * The Toolbar is a flex container, allowing flex item properties to be used to lay out the children.
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
    * If `true`, disables gutter padding.
    * @default false
    */
  disableGutters?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The variant to use.
    * @default 'regular'
    */
  variant?: variant,
}

@module("@mui/material/Toolbar")
external make: React.component<props> = "default"
