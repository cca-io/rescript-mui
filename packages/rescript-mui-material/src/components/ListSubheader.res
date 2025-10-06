type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="inherit"`. */
  colorInherit?: string,
  /** Styles applied to the inner `component` element unless `disableGutters={true}`. */
  gutters?: string,
  /** Styles applied to the root element if `inset={true}`. */
  inset?: string,
  /** Styles applied to the root element unless `disableSticky={true}`. */
  sticky?: string,
}

@uboxed
type color =
  | @as("default") Default
  | @as("inherit") Inherit
  | @as("primary") Primary

type props = {
  ...CommonProps.t,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The color of the component. It supports those theme colors that make sense for this component.
    * @default 'default'
    */
  color?: color,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * If `true`, the List Subheader will not have gutters.
    * @default false
    */
  disableGutters?: bool,
  /**
    * If `true`, the List Subheader will not stick to the top during scroll.
    * @default false
    */
  disableSticky?: bool,
  /**
    * If `true`, the List Subheader is indented.
    * @default false
    */
  inset?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/ListSubheader")
external make: React.component<props> = "default"
