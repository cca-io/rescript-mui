type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `container={true}`. */
  container?: string,
  /** Styles applied to the root element if `item={true}`. */
  item?: string,
  /** Styles applied to the root element if `zeroMinWidth={true}`. */
  zeroMinWidth?: string,
}

type gridDirection =
  | @as("row") Row
  | @as("row-reverse") RowReverse
  | @as("column") Column
  | @as("column-reverse") ColumnReverse

type gridWrap =
  | @as("nowrap") Nowrap
  | @as("wrap") Wrap
  | @as("wrap-reverse") WrapReverse

@unboxed
type gridSize =
  | @as("auto") Auto
  | @as(true) True
  | @as(false) False
  | Number(float)

type regularBreakpoints = {
  /**
   * If a number, it sets the number of columns the grid item uses.
   * It can't be greater than the total number of columns of the container (12 by default).
   * If 'auto', the grid item's width matches its content.
   * If false, the prop is ignored.
   * If true, the grid item's width grows to use the space available in the grid container.
   * The value is applied for the `lg` breakpoint and wider screens if not overridden.
   * @default false
   */
  lg?: gridSize,
  /**
   * If a number, it sets the number of columns the grid item uses.
   * It can't be greater than the total number of columns of the container (12 by default).
   * If 'auto', the grid item's width matches its content.
   * If false, the prop is ignored.
   * If true, the grid item's width grows to use the space available in the grid container.
   * The value is applied for the `md` breakpoint and wider screens if not overridden.
   * @default false
   */
  md?: gridSize,
  /**
   * If a number, it sets the number of columns the grid item uses.
   * It can't be greater than the total number of columns of the container (12 by default).
   * If 'auto', the grid item's width matches its content.
   * If false, the prop is ignored.
   * If true, the grid item's width grows to use the space available in the grid container.
   * The value is applied for the `sm` breakpoint and wider screens if not overridden.
   * @default false
   */
  sm?: gridSize,
  /**
   * If a number, it sets the number of columns the grid item uses.
   * It can't be greater than the total number of columns of the container (12 by default).
   * If 'auto', the grid item's width matches its content.
   * If false, the prop is ignored.
   * If true, the grid item's width grows to use the space available in the grid container.
   * The value is applied for the `xl` breakpoint and wider screens if not overridden.
   * @default false
   */
  xl?: gridSize,
  /**
   * If a number, it sets the number of columns the grid item uses.
   * It can't be greater than the total number of columns of the container (12 by default).
   * If 'auto', the grid item's width matches its content.
   * If false, the prop is ignored.
   * If true, the grid item's width grows to use the space available in the grid container.
   * The value is applied for all the screen sizes with the lowest priority.
   * @default false
   */
  xs?: gridSize,
}

@unboxed
type columns =
  | Array(array<int>)
  | Int(int)
  | Object(Js.Dict.t<string>)

@unboxed
type rec gridSpacing =
  | Array(array<gridSpacing>)
  | Int(int)
  | String(string)
  | Object(Js.Dict.t<string>)

@unboxed
type autoNumberBool =
  | @as("auto") Auto
  | Number(int)
  | @as(true) True
  | @as(false) False

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
    * The number of columns.
    * @default 12
    */
  columns?: columns,
  /**
    * Defines the horizontal space between the type `item` components.
    * It overrides the value of the `spacing` prop.
    */
  columnSpacing?: gridSpacing,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
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
  direction?: gridDirection,
  /**
    * If `true`, the component will have the flex *item* behavior.
    * You should be wrapping *items* with a *container*.
    * @default false
    */
  item?: bool,
  /**
    * If a number, it sets the number of columns the grid item uses.
    * It can't be greater than the total number of columns of the container (12 by default).
    * If 'auto', the grid item's width matches its content. If false, the prop is ignored. 
    * If true, the grid item's width grows to use the space available in the grid container.
    * The value is applied for the `lg` breakpoint and wider screens if not overridden.
    */
  lg?: autoNumberBool,
  /**
    * If a number, it sets the number of columns the grid item uses.
    * It can't be greater than the total number of columns of the container (12 by default).
    * If 'auto', the grid item's width matches its content. If false, the prop is ignored. 
    * If true, the grid item's width grows to use the space available in the grid container.
    * The value is applied for the `md`` breakpoint and wider screens if not overridden.
    */
  md?: autoNumberBool,
  /**
    * Defines the vertical space between the type `item` components.
    * It overrides the value of the `spacing` prop.
    */
  rowSpacing?: gridSpacing,
  /**
    * If a number, it sets the number of columns the grid item uses.
    * It can't be greater than the total number of columns of the container (12 by default).
    * If 'auto', the grid item's width matches its content. If false, the prop is ignored. 
    * If true, the grid item's width grows to use the space available in the grid container.
    * The value is applied for the `sm` breakpoint and wider screens if not overridden.
    */
  sm?: autoNumberBool,
  /**
    * Defines the space between the type `item` components.
    * It can only be used on a type `container` component.
    * @default 0
    */
  spacing?: gridSpacing,
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
  /**
    * If a number, it sets the number of columns the grid item uses.
    * It can't be greater than the total number of columns of the container (12 by default).
    * If 'auto', the grid item's width matches its content. If false, the prop is ignored. 
    * If true, the grid item's width grows to use the space available in the grid container.
    * The value is applied for the `xl` breakpoint and wider screens if not overridden.
    */
  xl?: autoNumberBool,
  /**
    * If a number, it sets the number of columns the grid item uses.
    * It can't be greater than the total number of columns of the container (12 by default).
    * If 'auto', the grid item's width matches its content. If false, the prop is ignored. 
    * If true, the grid item's width grows to use the space available in the grid container.
    * The value is applied for all the screen sizes with the lowest priority.
    */
  xs?: autoNumberBool,
  /**
    * If `true`, it sets `min-width: 0` on the item.
    * Refer to the limitations section of the documentation to better understand the use case.
    * @default false
    */
  zeroMinWidth?: bool,
}

@module("@mui/material/Grid")
external make: React.component<props> = "default"
