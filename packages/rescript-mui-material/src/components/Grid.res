type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `container={true}`. */
  container?: string,
  /** Styles applied to the root element if `item={true}`. */
  item?: string,
  /** Styles applied to the root element if `zeroMinWidth={true}`. */
  zeroMinWidth?: string,
  /** Styles applied to the root element if `direction="column"`. */
  @as("direction-xs-column")
  directionXsColumn?: string,
  /** Styles applied to the root element if `direction="column-reverse"`. */
  @as("direction-xs-column-reverse")
  directionXsColumnReverse?: string,
  /** Styles applied to the root element if `direction="row-reverse"`. */
  @as("direction-xs-row-reverse")
  directionXsRowReverse?: string,
  /** Styles applied to the root element if `wrap="nowrap"`. */
  @as("wrap-xs-nowrap")
  wrapXsNowrap?: string,
  /** Styles applied to the root element if `wrap="reverse"`. */
  @as("wrap-xs-wrap-reverse")
  wrapXsWrapReverse?: string,
  @as("spacing-xs-1") spacingXs_1?: string,
  @as("spacing-xs-2") spacingXs_2?: string,
  @as("spacing-xs-3") spacingXs_3?: string,
  @as("spacing-xs-4") spacingXs_4?: string,
  @as("spacing-xs-5") spacingXs_5?: string,
  @as("spacing-xs-6") spacingXs_6?: string,
  @as("spacing-xs-7") spacingXs_7?: string,
  @as("spacing-xs-8") spacingXs_8?: string,
  @as("spacing-xs-9") spacingXs_9?: string,
  @as("spacing-xs-10") spacingXs_10?: string,
  @as("grid-xs-auto") gridXsAuto?: string,
  @as("grid-xs-true") gridXsTrue?: string,
  @as("grid-xs-1") gridXs_1?: string,
  @as("grid-xs-2") gridXs_2?: string,
  @as("grid-xs-3") gridXs_3?: string,
  @as("grid-xs-4") gridXs_4?: string,
  @as("grid-xs-5") gridXs_5?: string,
  @as("grid-xs-6") gridXs_6?: string,
  @as("grid-xs-7") gridXs_7?: string,
  @as("grid-xs-8") gridXs_8?: string,
  @as("grid-xs-9") gridXs_9?: string,
  @as("grid-xs-10") gridXs_10?: string,
  @as("grid-xs-11") gridXs_11?: string,
  @as("grid-xs-12") gridXs_12?: string,
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
  | @as("grow") Grow
  | @as("number") Number(int)

type breakpointSizes = {
  xs?: gridSize,
  sm?: gridSize,
  md?: gridSize,
  lg?: gridSize,
  xl?: gridSize,
}

type size =
  | String(string)
  | Breakpoint(breakpointSizes)
  | Number(int)
  | Auto

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
    * Defines the vertical space between the type `item` components.
    * It overrides the value of the `spacing` prop.
    */
  rowSpacing?: gridSpacing,
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
    * Defines the size of the grid item.
    * It can be a single value for all breakpoints, or an object with breakpoint-specific values.
    * - If a number, it sets the number of columns the grid item uses.
    * - If 'auto', the grid item's width matches its content.
    * - If 'grow', the grid item's width grows to use the space available in the grid container.
    */
  size?: size,
}

@module("@mui/material/Grid")
external make: React.component<props> = "default"
