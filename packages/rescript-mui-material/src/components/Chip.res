type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="medium"`. */
  sizeMedium?: string,
  /** Styles applied to the root element if `color="default"`. */
  colorDefault?: string,
  /** Styles applied to the root element if `color="error"`. */
  colorError?: string,
  /** Styles applied to the root element if `color="info"`. */
  colorInfo?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `color="success"`. */
  colorSuccess?: string,
  /** Styles applied to the root element if `color="warning"`. */
  colorWarning?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `onClick` is defined or `clickable={true}`. */
  clickable?: string,
  /** Styles applied to the root element if `onDelete` is defined. */
  deletable?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="filled"`. */
  filled?: string,
  /** Styles applied to the avatar element. */
  avatar?: string,
  /** Styles applied to the icon element. */
  icon?: string,
  /** Styles applied to the label `span` element. */
  label?: string,
  /** Styles applied to the deleteIcon element. */
  deleteIcon?: string,
  /** State class applied to the root element if keyboard focused. */
  focusVisible?: string,
}

@unboxed
type color =
  | @as("default") Default
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | String(string)

@unboxed
type variant =
  | @as("filled") Filled
  | @as("outlined") Outlined
  | String(string)

type props = {
  ...CommonProps.t,
  /**
    * The Avatar element to display.
    */
  avatar?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, the chip will appear clickable, and will raise when pressed,
    * even if the onClick prop is not defined.
    * If `false`, the chip will not appear clickable, even if onClick prop is defined.
    * This can be used, for example,
    * along with the component prop to indicate an anchor Chip is clickable.
    * Note: this controls the UI and does not affect the onClick event.
    */
  clickable?: bool,
  /**
    * The color of the component.
    * It supports both default and custom theme colors, which can be added as shown in the
    * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
    * @default 'default'
    */
  color?: color,
  /**
    * Override the default delete icon element. Shown only if `onDelete` is set.
    */
  deleteIcon?: React.element,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * Icon element.
    */
  icon?: React.element,
  /**
    * The content of the component.
    */
  label?: React.element,
  /**
    * Callback fired when the chip is clicked.
    */
  onClick?: ReactEvent.Mouse.t => unit,
  /**
    * Callback fired when the delete icon is clicked.
    * If set, the delete icon will be shown.
    */
  onDelete?: ReactEvent.Synthetic.t => unit,
  /**
    * The size of the component.
    * @default 'medium'
    */
  size?: size,
  /**
    * If `true`, allows the disabled chip to escape focus.
    * If `false`, allows the disabled chip to receive focus.
    * @default false
    */
  skipFocusWhenDisabled?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The variant to use.
    * @default 'filled'
    */
  variant?: variant,
  component?: OverridableComponent.t<unknown>,
}

@module("@mui/material/Chip")
external make: React.component<props> = "default"
