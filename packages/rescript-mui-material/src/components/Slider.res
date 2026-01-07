type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `marks` is provided with at least one label. */
  marked?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** State class applied to the root and thumb element if `disabled={true}`. */
  disabled?: string,
  /** State class applied to the root if a thumb is being dragged. */
  dragging?: string,
  /** Styles applied to the rail element. */
  rail?: string,
  /** Styles applied to the track element. */
  track?: string,
  /** Styles applied to the root element if `track={false}`. */
  trackFalse?: string,
  /** Styles applied to the root element if `track="inverted"`. */
  trackInverted?: string,
  /** Styles applied to the thumb element. */
  thumb?: string,
  /** State class applied to the thumb element if it's active. */
  active?: string,
  /** State class applied to the thumb element if keyboard focused. */
  focusVisible?: string,
  /** Styles applied to the mark element. */
  mark?: string,
  /** Styles applied to the mark element if active (depending on the value). */
  markActive?: string,
  /** Styles applied to the mark label element. */
  markLabel?: string,
  /** Styles applied to the mark label element if active (depending on the value). */
  markLabelActive?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the thumb element if `color="primary"`. */
  thumbColorPrimary?: string,
  /** Styles applied to the thumb element if `color="secondary"`. */
  thumbColorSecondary?: string,
  /** Styles applied to the thumb element if `size="small"`. */
  thumbSizeSmall?: string,
  /** Styles applied to the thumb label element. */
  valueLabel?: string,
  /** Styles applied to the thumb label element if it's open. */
  valueLabelOpen?: string,
  /** Styles applied to the thumb label's circle element. */
  valueLabelCircle?: string,
  /** Styles applied to the thumb label's label element. */
  valueLabelLabel?: string,
}

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | String(string)

type marksObj<'value> = {
  value: 'value,
  label?: string,
}

@unboxed
type marks<'value> =
  | @as(false) False
  | @as(true) True
  | Array(array<marksObj<'value>>)

type orientation =
  | @as("horizontal") Horizontal
  | @as("vertical") Vertical

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | String(string)

type slotProps = {
  root?: JsxDOM.domProps,
  track?: JsxDOM.domProps,
  rail?: JsxDOM.domProps,
  thumb?: JsxDOM.domProps,
  mark?: JsxDOM.domProps,
  markLabel?: JsxDOM.domProps,
  valueLabel?: JsxDOM.domProps,
  input?: JsxDOM.domProps,
}

type slots = {
  root?: OverridableComponent.t<JsxDOM.domProps>,
  track?: OverridableComponent.t<JsxDOM.domProps>,
  rail?: OverridableComponent.t<JsxDOM.domProps>,
  thumb?: OverridableComponent.t<JsxDOM.domProps>,
  mark?: OverridableComponent.t<JsxDOM.domProps>,
  markLabel?: OverridableComponent.t<JsxDOM.domProps>,
  valueLabel?: OverridableComponent.t<JsxDOM.domProps>,
  input?: OverridableComponent.t<JsxDOM.domProps>,
}

@unboxed
type step =
  | Number(float)
  | @as(null) Null

@unboxed
type track =
  | @as("normal") Normal
  | @as("inverted") Inverted
  | @as(false) False

type valueLabelDisplay =
  | @as("on") On
  | @as("auto") Auto
  | @as("off") Off

@unboxed
type valueLabelFormat<'value> =
  | String(string)
  | Func(('value, int) => React.element)

type sliderProps<'value> = {
  ...CommonProps.t,
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
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * The default value. Use when the component is not controlled.
    */
  defaultValue?: 'value,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, the active thumb doesn't swap when moving pointer over a thumb while dragging another thumb.
    * @default false
    */
  disableSwap?: bool,
  /**
    * Accepts a function which returns a string value that provides a user-friendly name for the thumb labels of the slider.
    * This is important for screen reader users.
    * @param {number} index The thumb label's index to format.
    * @returns {string}
    */
  getAriaLabel?: int => string,
  /**
    * Accepts a function which returns a string value that provides a user-friendly name for the current value of the slider.
    * This is important for screen reader users.
    * @param {number} value The thumb label's value to format.
    * @param {number} index The thumb label's index to format.
    * @returns {string}
    */
  getAriaValueText?: ('value, int) => string,
  /**
    * Marks indicate predetermined values to which the user can move the slider.
    * If `true` the marks are spaced according the value of the `step` prop.
    * If an array, it should contain objects with `value` and an optional `label` keys.
    * @default false
    */
  marks?: marks<'value>,
  /**
    * The maximum allowed value of the slider.
    * Should not be equal to min.
    * @default 100
    */
  max?: float,
  /**
    * The minimum allowed value of the slider.
    * Should not be equal to max.
    * @default 0
    */
  min?: float,
  /**
    * Name attribute of the hidden `input` element.
    */
  name?: string,
  /**
    * Callback function that is fired when the slider's value changed.
    *
    * @param {Event} event The event source of the callback.
    * You can pull out the new value by accessing `event.target.value` (any).
    * **Warning**: This is a generic event not a change event.
    * @param {number | number[]} value The new value.
    * @param {number} activeThumb Index of the currently moved thumb.
    */
  onChange?: (ReactEvent.Synthetic.t, 'value, int) => unit,
  /**
    * Callback function that is fired when the `mouseup` is triggered.
    *
    * @param {React.SyntheticEvent | Event} event The event source of the callback. **Warning**: This is a generic event not a change event.
    * @param {number | number[]} value The new value.
    */
  onChangeCommitted?: (ReactEvent.Synthetic.t, 'value) => unit,
  /**
    * The component orientation.
    * @default 'horizontal'
    */
  orientation?: orientation,
  /**
    * A transformation function, to change the scale of the slider.
    * @param {any} x
    * @returns {any}
    * @default function Identity(x) {
    *   return x,
    * }
    */
  scale?: float => float,
  /**
    * The size of the slider.
    * @default 'medium'
    */
  size?: size,
  /**
    * The props used for each slot inside the Slider.
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The components used for each slot inside the Slider.
    * Either a string to use a HTML element or a component.
    * @default {}
    */
  slots?: slots,
  /**
    * The granularity with which the slider can step through values. (A "discrete" slider.)
    * The `min` prop serves as the origin for the valid values.
    * We recommend (max - min) to be evenly divisible by the step.
    *
    * When step is `null`, the thumb can only be slid onto marks provided with the `marks` prop.
    * @default 1
    */
  step?: step,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The track presentation:
    *
    * - `normal` the track will render a bar representing the slider value.
    * - `inverted` the track will render a bar representing the remaining slider value.
    * - `false` the track will render without a bar.
    * @default 'normal'
    */
  track?: track,
  /**
    * The value of the slider.
    * For ranged sliders, provide an array with two values.
    */
  value?: 'value,
  /**
    * Controls when the value label is displayed:
    *
    * - `auto` the value label will display when the thumb is hovered or focused.
    * - `on` will display persistently.
    * - `off` will never display.
    * @default 'off'
    */
  valueLabelDisplay?: valueLabelDisplay,
  /**
    * The format function the value label's value.
    *
    * When a function is provided, it should have the following signature:
    *
    * - {number} value The value label's value to format
    * - {number} index The value label's index to format
    * @param {any} x
    * @returns {any}
    * @default function Identity(x) {
    *   return x,
    * }
    */
  valueLabelFormat?: valueLabelFormat<'value>,
}

module Ranged = {
  type props = sliderProps<(float, float)>
  @module("@mui/material/Slider")
  external make: React.component<props> = "default"
}

type props = sliderProps<float>
@module("@mui/material/Slider")
external make: React.component<props> = "default"
