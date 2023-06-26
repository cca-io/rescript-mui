type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="filled"`. */
  filled?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="standard"`. */
  standard?: string,
  /** Styles applied to the root element if `variant="standard"` and `color="success"`. */
  standardSuccess?: string,
  /** Styles applied to the root element if `variant="standard"` and `color="info"`. */
  standardInfo?: string,
  /** Styles applied to the root element if `variant="standard"` and `color="warning"`. */
  standardWarning?: string,
  /** Styles applied to the root element if `variant="standard"` and `color="error"`. */
  standardError?: string,
  /** Styles applied to the root element if `variant="outlined"` and `color="success"`. */
  outlinedSuccess?: string,
  /** Styles applied to the root element if `variant="outlined"` and `color="info"`. */
  outlinedInfo?: string,
  /** Styles applied to the root element if `variant="outlined"` and `color="warning"`. */
  outlinedWarning?: string,
  /** Styles applied to the root element if `variant="outlined"` and `color="error"`. */
  outlinedError?: string,
  /** Styles applied to the root element if `variant="filled"` and `color="success"`. */
  filledSuccess?: string,
  /** Styles applied to the root element if `variant="filled"` and `color="info"`. */
  filledInfo?: string,
  /** Styles applied to the root element if `variant="filled"` and `color="warning"`. */
  filledWarning?: string,
  /** Styles applied to the root element if `variant="filled"` and `color="error"`. */
  filledError?: string,
  /** Styles applied to the icon wrapper element. */
  icon?: string,
  /** Styles applied to the message wrapper element. */
  message?: string,
  /** Styles applied to the action wrapper element if `action` is provided. */
  action?: string,
}

type severity =
  | @as("success") Success
  | @as("info") Info
  | @as("warning") Warning
  | @as("error") Error

@unboxed
type color =
  | @as("success") Success
  | @as("info") Info
  | @as("warning") Warning
  | @as("error") Error
  | String(string)

type slots = {
  closeButton?: React.element,
  closeIcon?: React.element,
}

type slotProps = {
  closeButton?: IconButton.props,
  closeIcon?: SvgIcon.props,
}

@unboxed
type variant =
  | @as("standard") Standard
  | @as("filled") Filled
  | @as("outlined") Outlined
  | String(string)

type iconMapping = {
  error?: React.element,
  info?: React.element,
  success?: React.element,
  warning?: React.element,
}

type props = {
  ...Paper.publicProps,
  /**
    * The action to display. It renders after the message, at the end of the alert.
    */
  action?: React.element,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * Override the default label for the *close popup* icon button.
    *
    * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
    * @default 'Close'
    */
  closeText?: string,
  /**
    * The color of the component. Unless provided, the value is taken from the `severity` prop.
    * It supports both default and custom theme colors, which can be added as shown in the
    * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
    */
  color?: color,
  /**
    * Override the icon displayed before the children.
    * Unless provided, the icon is mapped to the value of the `severity` prop.
    * Set to `false` to remove the `icon`.
    */
  icon?: React.element,
  /**
    * The component maps the `severity` prop to a range of different icons,
    * for instance success to `<SuccessOutlined>`.
    * If you wish to change this mapping, you can provide your own.
    * Alternatively, you can use the `icon` prop to override the icon displayed.
    */
  iconMapping?: iconMapping,
  /**
    * Callback fired when the component requests to be closed.
    * When provided and no `action` prop is set, a close icon button is displayed that triggers the callback when clicked.
    * @param {React.SyntheticEvent} event The event source of the callback.
    */
  onClose?: ReactEvent.Synthetic.t => unit,
  /**
    * The ARIA role attribute of the element.
    * @default 'alert'
    */
  role?: string,
  /**
    * The severity of the alert. This defines the color and icon used.
    * @default 'success'
    */
  severity?: severity,
  /**
    * The extra props for the slot components.
    * You can override the existing props or add new ones.
    *
    * This prop is an alias for the `componentsProps` prop, which will be deprecated in the future.
    *
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The components used for each slot inside.
    *
    * This prop is an alias for the `components` prop, which will be deprecated in the future.
    *
    * @default {}
    */
  slots?: slots,
  /**
    * The variant to use.
    * @default 'standard'
    */
  variant?: variant,
}

@module("@mui/material/Alert")
external make: React.component<props> = "default"
