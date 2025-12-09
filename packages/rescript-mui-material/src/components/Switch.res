type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `edge="start"`. */
  edgeStart?: string,
  /** Styles applied to the root element if `edge="end"`. */
  edgeEnd?: string,
  /** Styles applied to the internal `SwitchBase` component's `root` class. */
  switchBase?: string,
  /** Styles applied to the internal SwitchBase component's root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the internal SwitchBase component's root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="medium"`. */
  sizeMedium?: string,
  /** State class applied to the internal `SwitchBase` component's `checked` class. */
  checked?: string,
  /** State class applied to the internal SwitchBase component's disabled class. */
  disabled?: string,
  /** Styles applied to the internal SwitchBase component's input element. */
  input?: string,
  /** Styles used to create the thumb passed to the internal `SwitchBase` component `icon` prop. */
  thumb?: string,
  /** Styles applied to the track element. */
  track?: string,
}

type slots = {
  /**
    * The component that renders the root slot.
    * @default 'span'
    */
  root?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the track slot.
    * @default 'span'
    */
  track?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the thumb slot.
    * @default 'span'
    */
  thumb?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the switchBase slot.
    * @default SwitchBase
    */
  switchBase?: OverridableComponent.t<JsxDOM.domProps>, // should be SwitchBase.props, but unbound
  /**
    * The component that renders the switchBase's input slot.
    * @default SwitchBaseInput
    */
  input?: OverridableComponent.t<JsxDOM.domProps>, // should be SwitchBaseInput.props, but unbound
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    * By default, the avaible props are based on the span element.
    */
  root?: JsxDOM.domProps,
  /**
    * Props forwarded to the track slot.
    * By default, the avaible props are based on the span element.
    */
  track?: JsxDOM.domProps,
  /**
    * Props forwarded to the thumb slot.
    * By default, the avaible props are based on the span element.
    */
  thumb?: JsxDOM.domProps,
  /**
    * Props forwarded to the switchBase slot.
    * By default, the avaible props are based on the internal SwitchBase component.
    */
  switchBase?: JsxDOM.domProps,
  /**
    * Props forwarded to the input slot.
    * By default, the avaible props are based on the input element.
    */
  input?: JsxDOM.domProps,
}

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | @as("default") Default
  | String(string)

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | String(string)

type edge =
  | @as("start") Start
  | @as("end") End
  | @as(false) False

type props<'value, 'inputRef> = {
  ...ButtonBase.publicPropsWithOnClick,
  /**
    * If `true`, the component is checked.
    */
  checked?: bool,
  /**
    * The icon to display when the component is checked.
    */
  checkedIcon?: React.element,
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
    * The default checked state. Use when the component is not controlled.
    */
  defaultChecked?: bool,
  /**
    * If `true`, the component is disabled.
    */
  disabled?: bool,
  /**
    * If `true`, the  keyboard focus ripple is disabled.
    * @default false
    */
  disableFocusRipple?: bool,
  /**
    * If given, uses a negative margin to counteract the padding on one
    * side (this is often helpful for aligning the left or right
    * side of the icon with content above or below, without ruining the border
    * size and shape).
    * @default false
    */
  edge?: edge,
  /**
    * The icon to display when the component is unchecked.
    */
  icon?: React.element,
  /**
    * [Attributes](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input#Attributes) applied to the `input` element.
    */
  inputProps?: InputBase.inputBaseComponentProps,
  /**
    * Pass a ref to the `input` element.
    */
  inputRef?: React.ref<'inputRef>,
  /**
    * Name attribute of the `input` element.
    */
  name?: string,
  /**
    * Callback fired when the state is changed.
    *
    * @param {React.ChangeEvent<HTMLInputElement>} event The event source of the callback.
    * You can pull out the new value by accessing `event.target.value` (string).
    * You can pull out the new checked state by accessing `event.target.checked` (bool).
    */
  onChange?: (ReactEvent.Form.t, bool) => unit,
  readOnly?: bool,
  /**
    * If `true`, the `input` element is required.
    * @default false
    */
  required?: bool,
  /**
    * The size of the component.
    * `small` is equivalent to the dense switch styling.
    * @default 'medium'
    */
  size?: size,
  /**
    * The components used for each slot inside.
    * @default {}
    */
  slots?: slots,
  /**
    * The props used for each slot inside.
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The value of the component. The DOM API casts this to a string.
    * The browser uses "on" as the default value.
    */
  value?: 'value,
}

@module("@mui/material/Switch")
external make: React.component<props<'value, 'inputRef>> = "default"
