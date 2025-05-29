type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type direction =
  | @as("row") Row
  | @as("row-reverse") RowReverse
  | @as("column") Column
  | @as("column-reverse") ColumnReverse

@unboxed
type rec spacing =
  | Array(array<spacing>)
  | String(string)
  | Number(float)
  | Object(Js.Dict.t<spacing>)

type props = {
  ...System.props,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * Defines the `flex-direction` style property.
    * It is applied for all screen sizes.
    * @default 'column'
    */
  direction?: array<direction>,
  /**
    * Add an element between each child.
    */
  divider?: React.element,
  /**
    * Defines the space between immediate children.
    * @default 0
    */
  spacing?: spacing,
  /**
    * The system prop, which allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * If `true`, the CSS flexbox `gap` is used instead of applying `margin` to children.
    *
    * While CSS `gap` removes the [known limitations](https://mui.com/joy-ui/react-stack/#limitations),
    * it is not fully supported in some browsers. We recommend checking https://caniuse.com/?search=flex%20gap before using this flag.
    *
    * To enable this flag globally, follow the [theme's default props](https://mui.com/material-ui/customization/theme-components/#default-props) configuration.
    * @default false
    */
  useFlexGap?: bool,
  onClick?: ReactEvent.Mouse.t => unit,
}

@module("@mui/material/Stack")
external make: React.component<props> = "default"
