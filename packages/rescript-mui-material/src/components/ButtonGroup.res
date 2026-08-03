type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="contained"`. */
  contained?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="text"`. */
  text?: string,
  /** Styles applied to the root element if `disableElevation={true}`. */
  disableElevation?: string,
  /** State class applied to the child elements if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the first button in the button group. */
  firstButton?: string,
  /** Styles applied to the root element if `fullWidth={true}`. */
  fullWidth?: string,
  /** Styles applied to the root element if `orientation="horizontal"`. */
  horizontal?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** Styles applied to the children. */
  grouped?: string,
  /** Styles applied to the root element if `color="primary"` */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"` */
  colorSecondary?: string,
  /** Styles applied to the children if `orientation="horizontal"`.
  * @deprecated Combine the [.MuiButtonGroup-horizontal](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-horizontal) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedHorizontal?: string,
  /** Styles applied to the children if `orientation="vertical"`.
  * @deprecated Combine the [.MuiButtonGroup-vertical](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-vertical) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedVertical?: string,
  /** Styles applied to the children if `variant="text"`.
  * @deprecated Combine the [.MuiButtonGroup-text](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-text) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedText?: string,
  /** Styles applied to the children if `variant="text"` and `orientation="horizontal"`.
  * @deprecated Combine the [.MuiButtonGroup-text](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-text) , [.MuiButtonGroup-horizontal](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-horizontal) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedTextHorizontal?: string,
  /** Styles applied to the children if `variant="text"` and `orientation="vertical"`.
  * @deprecated Combine the [.MuiButtonGroup-text](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-text) , [.MuiButtonGroup-vertical](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-vertical) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedTextVertical?: string,
  /** Styles applied to the children if `variant="text"` and `color="primary"`.
  * @deprecated Combine the [.MuiButtonGroup-text](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-text) , [.MuiButtonGroup-colorPrimary](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-colorPrimary) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedTextPrimary?: string,
  /** Styles applied to the children if `variant="text"` and `color="secondary"`.
  * @deprecated Combine the [.MuiButtonGroup-text](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-text) , [.MuiButtonGroup-colorSecondary](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-colorSecondary) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedTextSecondary?: string,
  /** Styles applied to the children if `variant="outlined"`.
  * @deprecated Combine the [.MuiButtonGroup-outlined](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-outlined) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedOutlined?: string,
  /** Styles applied to the children if `variant="outlined"` and `orientation="horizontal"`.
  * @deprecated Combine the [.MuiButtonGroup-outlined](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-outlined) , [.MuiButtonGroup-horizontal](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-horizontal) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedOutlinedHorizontal?: string,
  /** Styles applied to the children if `variant="outlined"` and `orientation="vertical"`.
  * @deprecated Combine the [.MuiButtonGroup-outlined](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-outlined) , [.MuiButtonGroup-vertical](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-vertical) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedOutlinedVertical?: string,
  /** Styles applied to the children if `variant="outlined"` and `color="primary"`.
  * @deprecated Combine the [.MuiButtonGroup-outlined](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-outlined) , [.MuiButtonGroup-colorPrimary](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-colorPrimary) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedOutlinedPrimary?: string,
  /** Styles applied to the children if `variant="outlined"` and `color="secondary"`.
  * @deprecated Combine the [.MuiButtonGroup-outlined](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-outlined) , [.MuiButtonGroup-colorSecondary](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-colorSecondary) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedOutlinedSecondary?: string,
  /** Styles applied to the children if `variant="contained"`.
  * @deprecated Combine the [.MuiButtonGroup-contained](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-contained) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedContained?: string,
  /** Styles applied to the children if `variant="contained"` and `orientation="horizontal"`.
  * @deprecated Combine the [.MuiButtonGroup-contained](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-contained) , [.MuiButtonGroup-horizontal](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-horizontal) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedContainedHorizontal?: string,
  /** Styles applied to the children if `variant="contained"` and `orientation="vertical"`.
  * @deprecated Combine the [.MuiButtonGroup-contained](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-contained) , [.MuiButtonGroup-vertical](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-vertical) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedContainedVertical?: string,
  /** Styles applied to the children if `variant="contained"` and `color="primary"`.
  * @deprecated Combine the [.MuiButtonGroup-contained](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-contained) , [.MuiButtonGroup-colorPrimary](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-colorPrimary) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedContainedPrimary?: string,
  /** Styles applied to the children if `variant="contained"` and `color="secondary"`.
  * @deprecated Combine the [.MuiButtonGroup-contained](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-contained) , [.MuiButtonGroup-colorSecondary](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-colorSecondary) and [.MuiButtonGroup-grouped](/material-ui/api/button-group/#button-group-classes-MuiButtonGroup-grouped) classes instead. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
  */
  groupedContainedSecondary?: string,
  /** Styles applied to the last button in the button group. */
  lastButton?: string,
  /** Styles applied to buttons in the middle of the button group. */
  middleButton?: string,
}

@unboxed
type color =
  | @as("inherit") Inherit
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

type orientation =
  | @as("vertical") Vertical
  | @as("horizontal") Horizontal

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
  | String(string)

@unboxed
type variant =
  | @as("text") Text
  | @as("outlined") Outlined
  | @as("contained") Contained
  | String(string)

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
    * The color of the component.
    * It supports both default and custom theme colors, which can be added as shown in the
    * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
    * @default 'primary'
    */
  color?: color,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, no elevation is used.
    * @default false
    */
  disableElevation?: bool,
  /**
    * If `true`, the button keyboard focus ripple is disabled.
    * @default false
    */
  disableFocusRipple?: bool,
  /**
    * If `true`, the button ripple effect is disabled.
    * @default false
    */
  disableRipple?: bool,
  /**
    * If `true`, the buttons will take up the full width of its container.
    * @default false
    */
  fullWidth?: bool,
  /**
    * The component orientation (layout flow direction).
    * @default 'horizontal'
    */
  orientation?: orientation,
  /**
    * The size of the component.
    * `small` is equivalent to the dense button styling.
    * @default 'medium'
    */
  size?: size,
  /**
    * The variant to use.
    * @default 'outlined'
    */
  variant?: variant,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/ButtonGroup")
external make: React.component<props> = "default"
