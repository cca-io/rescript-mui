type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="medium"`. */
  sizeMedium?: string,
  /** Styles applied to the root element if `size="large"`. */
  sizeLarge?: string,
  /** Styles applied to the root element if `readOnly={true}`. */
  readOnly?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** State class applied to the root element if keyboard focused. */
  focusVisible?: string,
  /** Visually hide an element. */
  visuallyHidden?: string,
  /** Styles applied to the label elements. */
  label?: string,
  /** Styles applied to the label of the "no value" input when it is active. */
  labelEmptyValueActive?: string,
  /** Styles applied to the icon wrapping elements. */
  icon?: string,
  /** Styles applied to the icon wrapping elements when empty. */
  iconEmpty?: string,
  /** Styles applied to the icon wrapping elements when filled. */
  iconFilled?: string,
  /** Styles applied to the icon wrapping elements when hover. */
  iconHover?: string,
  /** Styles applied to the icon wrapping elements when focus. */
  iconFocus?: string,
  /** Styles applied to the icon wrapping elements when active. */
  iconActive?: string,
  /** Styles applied to the icon wrapping elements when decimals are necessary. */
  decimal?: string,
}

@unboxed
type numberOrNull =
  | Number(float)
  | @as(null) Null

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
  | String(string)

type slots = {
  /**
    * The component used for the root slot.
    * @default 'span'
    */
  root?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component used for the label slot.
    * @default 'label'
    */
  label?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component used for the icon slot.
    * @default 'span'
    */
  icon?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component used for the decimal slot.
    * @default 'span'
    */
  decimal?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    */
  root?: JsxDOM.domProps,
  /**
    * Props forwarded to the label slot.
    */
  label?: JsxDOM.domProps,
  /**
    * Props forwarded to the icon slot.
    */
  icon?: JsxDOM.domProps,
  /**
    * Props forwarded to the decimal slot.
    */
  decimal?: JsxDOM.domProps,
}

type props = {
  ...CommonProps.t,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The default value. Use when the component is not controlled.
    * @default null
    */
  defaultValue?: float,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * The icon to display when empty.
    * @default <StarBorder fontSize="inherit" />
    */
  emptyIcon?: React.element,
  /**
    * The label read when the rating input is empty.
    * @default 'Empty'
    */
  emptyLabelText?: React.element,
  /**
    * Accepts a function which returns a string value that provides a user-friendly name for the current value of the rating.
    * This is important for screen reader users.
    *
    * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
    * @param {number} value The rating label's value to format.
    * @returns {string}
    * @default function defaultLabelText(value) {
    *   return `${value} Star${value !== 1 ? 's' : ''}`,
    * }
    */
  getLabelText?: float => string,
  /**
    * If `true`, only the selected icon will be highlighted.
    * @default false
    */
  highlightSelectedOnly?: bool,
  /**
    * The icon to display.
    * @default <Star fontSize="inherit" />
    */
  icon?: React.element,
  /**
    * The component containing the icon.
    * @deprecated Use `slotProps.icon.component` instead. This prop will be removed in v7.
    * @default function IconContainer(props) {
    *   const { value, ...other } = props,
    *   return <span {...other} />,
    * }
    */
  @as("IconContainerComponent")
  iconContainerComponent?: React.element,
  /**
    * Maximum rating.
    * @default 5
    */
  max?: float,
  /**
    * The name attribute of the radio `input` elements.
    * This input `name` should be unique within the page.
    * Being unique within a form is insufficient since the `name` is used to generated IDs.
    */
  name?: string,
  /**
    * Callback fired when the value changes.
    * @param {React.SyntheticEvent} event The event source of the callback.
    * @param {number|null} value The new value.
    */
  onChange?: (ReactEvent.Synthetic.t, numberOrNull) => unit,
  /**
    * Callback function that is fired when the hover state changes.
    * @param {React.SyntheticEvent} event The event source of the callback.
    * @param {number} value The new value.
    */
  onChangeActive?: (ReactEvent.Synthetic.t, float) => unit,
  /**
    * The minimum increment value change allowed.
    * @default 1
    */
  precision?: float,
  /**
    * Removes all hover effects and pointer events.
    * @default false
    */
  readOnly?: bool,
  /**
    * The size of the component.
    * @default 'medium'
    */
  size?: size,
  /**
    * The components used for each slot inside.
    * @default {}
    */
  slots?: slots,
  /**
    * The extra props for the slot components.
    * You can override the existing props or add new ones.
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The rating value.
    */
  value?: numberOrNull,
}

@module("@mui/material/Rating")
external make: React.component<props> = "default"
