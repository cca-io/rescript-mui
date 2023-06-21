type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type props = {
  ...Mui.CommonProps.t,
  /**
    * The content of the component.
    */
  children: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * Number of columns.
    * @default 4
    */
  columns?: Mui.System.Value.t,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: Mui.OverridableComponent.t<unknown>,
  /**
    * The default number of columns of the component. This is provided for server-side rendering.
    */
  defaultColumns?: int,
  /**
    * The default height of the component in px. This is provided for server-side rendering.
    */
  defaultHeight?: int,
  /**
    * The default spacing of the component. Like `spacing`, it is a factor of the theme's spacing. This is provided for server-side rendering.
    */
  defaultSpacing?: int,
  /**
    * Defines the space between children. It is a factor of the theme's spacing.
    * @default 1
    */
  spacing?: Mui.System.Value.t,
  /**
    * Allows defining system overrides as well as additional CSS styles.
    */
  sx?: Mui.Sx.props,
}

@module("@mui/lab/Masonry")
external make: React.component<props> = "default"
