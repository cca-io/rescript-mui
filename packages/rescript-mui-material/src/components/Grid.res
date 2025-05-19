type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `container={true}`. */
  container?: string,
  /** Styles applied to the root element if `direction="column"`. */
  @as("direction-xs-column")
  directionXsColumn?: string,
  /** Styles applied to the root element if `direction="column-reverse"`. */
  @as("direction-xs-column-reverse")
  directionXsColumnReverse?: string,
  /** Styles applied to the root element if `direction="row"`. */
  @as("direction-xs-row")
  directionXsRow?: string,
  /** Styles applied to the root element if `direction="row-reverse"`. */
  @as("direction-xs-row-reverse")
  directionXsRowReverse?: string,
  /** Styles applied to the root element if `wrap="wrap"`. */
  @as("wrap-xs-wrap")
  wrapXsWrap?: string,
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
  // Grid xs classes
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
  // Grid sm classes
  @as("grid-sm-auto") gridSmAuto?: string,
  @as("grid-sm-true") gridSmTrue?: string,
  @as("grid-sm-1") gridSm_1?: string,
  @as("grid-sm-2") gridSm_2?: string,
  @as("grid-sm-3") gridSm_3?: string,
  @as("grid-sm-4") gridSm_4?: string,
  @as("grid-sm-5") gridSm_5?: string,
  @as("grid-sm-6") gridSm_6?: string,
  @as("grid-sm-7") gridSm_7?: string,
  @as("grid-sm-8") gridSm_8?: string,
  @as("grid-sm-9") gridSm_9?: string,
  @as("grid-sm-10") gridSm_10?: string,
  @as("grid-sm-11") gridSm_11?: string,
  @as("grid-sm-12") gridSm_12?: string,
  // Grid md classes
  @as("grid-md-auto") gridMdAuto?: string,
  @as("grid-md-true") gridMdTrue?: string,
  @as("grid-md-1") gridMd_1?: string,
  @as("grid-md-2") gridMd_2?: string,
  @as("grid-md-3") gridMd_3?: string,
  @as("grid-md-4") gridMd_4?: string,
  @as("grid-md-5") gridMd_5?: string,
  @as("grid-md-6") gridMd_6?: string,
  @as("grid-md-7") gridMd_7?: string,
  @as("grid-md-8") gridMd_8?: string,
  @as("grid-md-9") gridMd_9?: string,
  @as("grid-md-10") gridMd_10?: string,
  @as("grid-md-11") gridMd_11?: string,
  @as("grid-md-12") gridMd_12?: string,
  // Grid lg classes
  @as("grid-lg-auto") gridLgAuto?: string,
  @as("grid-lg-true") gridLgTrue?: string,
  @as("grid-lg-1") gridLg_1?: string,
  @as("grid-lg-2") gridLg_2?: string,
  @as("grid-lg-3") gridLg_3?: string,
  @as("grid-lg-4") gridLg_4?: string,
  @as("grid-lg-5") gridLg_5?: string,
  @as("grid-lg-6") gridLg_6?: string,
  @as("grid-lg-7") gridLg_7?: string,
  @as("grid-lg-8") gridLg_8?: string,
  @as("grid-lg-9") gridLg_9?: string,
  @as("grid-lg-10") gridLg_10?: string,
  @as("grid-lg-11") gridLg_11?: string,
  @as("grid-lg-12") gridLg_12?: string,
  // Grid xl classes
  @as("grid-xl-auto") gridXlAuto?: string,
  @as("grid-xl-true") gridXlTrue?: string,
  @as("grid-xl-1") gridXl_1?: string,
  @as("grid-xl-2") gridXl_2?: string,
  @as("grid-xl-3") gridXl_3?: string,
  @as("grid-xl-4") gridXl_4?: string,
  @as("grid-xl-5") gridXl_5?: string,
  @as("grid-xl-6") gridXl_6?: string,
  @as("grid-xl-7") gridXl_7?: string,
  @as("grid-xl-8") gridXl_8?: string,
  @as("grid-xl-9") gridXl_9?: string,
  @as("grid-xl-10") gridXl_10?: string,
  @as("grid-xl-11") gridXl_11?: string,
  @as("grid-xl-12") gridXl_12?: string,
}

@unboxed
type rec gridDirection =
  | @as("row") Row
  | @as("row-reverse") RowReverse
  | @as("column") Column
  | @as("column-reverse") ColumnReverse
  | Array(array<gridDirection>)
  | Dict(Js.Dict.t<gridDirection>)

type gridWrap =
  | @as("nowrap") Nowrap
  | @as("wrap") Wrap
  | @as("wrap-reverse") WrapReverse

@unboxed
type columns =
  | Array(array<int>)
  | Int(int)
  | Object(Js.Dict.t<int>)

@unboxed
type rec gridSpacing =
  | Int(int)
  | String(string)
  | Array(array<gridSpacing>)
  | Object(Js.Dict.t<gridSpacing>)

@unboxed
type rec gridOffset =
  | @as("auto") Auto
  | Int(int)
  | Array(array<gridOffset>)
  | Object(Js.Dict.t<gridOffset>)

@unboxed
type gridSize =
  | @as("auto") Auto
  | @as("grow") Grow
  | @as(false) False
  | Int(int)

type size = {
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
    * Defines the offset value for the type `item` components.
    */
  offset?: gridOffset,
  /**
    * Defines the vertical space between the type `item` components.
    * It overrides the value of the `spacing` prop.
    */
  rowSpacing?: gridSpacing,
  /**
    * Defines the size of the the type `item` components.
    */
  size?: size,
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
}

@module("@mui/material/Grid2")
external make: React.component<props> = "default"
