type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `container={true}`. */
  container?: string,
}

type gridWrap =
  | @as("nowrap") Nowrap
  | @as("wrap") Wrap
  | @as("wrap-reverse") WrapReverse

type props = {
  ...System.props,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The component used for the root node.
    * Either a string to use an HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * The number of columns.
    * @default 12
    */
  columns?: GridColumns.t,
  /**
    * Defines the horizontal space between the type `item` components.
    * It overrides the value of the `spacing` prop.
    */
  columnSpacing?: GridSpacing.t,
  /**
    * If `true`, the component will have the flex *container* behavior.
    * You should be wrapping *items* with a *container*.
    * @default false
    */
  container?: bool,
  /**
    * Defines the `flex-direction` style property.
    * It is applied for all screen sizes.
    * @default 'row'
    */
  direction?: GridDirection.t,
  /**
    * Defines the offset value for the type `item` components.
    */
  offset?: GridOffset.t,
  /**
    * Defines the vertical space between the type `item` components.
    * It overrides the value of the `spacing` prop.
    */
  rowSpacing?: GridSpacing.t,
  /**
    * Defines the size of the the type `item` components.
    */
  size?: GridSize.t,
  /**
    * Defines the space between the type `item` components.
    * It can only be used on a type `container` component.
    * @default 0
    */
  spacing?: GridSpacing.t,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * Defines the `flex-wrap` style property.
    * It's applied for all screen sizes.
    * @default 'wrap'
    */
  wrap?: gridWrap,
}

@module("@mui/material/Grid")
external make: React.component<props> = "default"
