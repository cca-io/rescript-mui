type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `labelPlacement="start"`. */
  labelPlacementStart?: string,
  /** Styles applied to the root element if `labelPlacement="top"`. */
  labelPlacementTop?: string,
  /** Styles applied to the root element if `labelPlacement="bottom"`. */
  labelPlacementBottom?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the label's Typography component. */
  label?: string,
  /** State class applied to the root element if `error={true}`. */
  error?: string,
  /** State class applied to the root element if `required={true}`. */
  required?: string,
  /** Styles applied to the asterisk element. */
  asterisk?: string,
}

type slotProps = {
  /**
    * Props applied to the Typography wrapper of the passed label.
    * This is unused if disableTypography is true.
    * @default {}
    */
  typography?: Typography.props,
}

type labelPlacement =
  | @as("end") End
  | @as("start") Start
  | @as("top") Top
  | @as("bottom") Bottom

type props<'value, 'inputRef> = {
  ...CommonProps.t,
  /**
    * A control element. For instance, it can be a `Radio`, a `Switch` or a `Checkbox`.
    */
  control: React.element,
  /**
    * If `true`, the component appears selected.
    */
  checked?: bool,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, the control is disabled.
    */
  disabled?: bool,
  /**
    * If `true`, the label is rendered as it is passed without an additional typography node.
    */
  disableTypography?: bool,
  /**
    * Pass a ref to the `input` element.
    */
  inputRef?: React.ref<'inputRef>,
  /**
    * A text or an element to be used in an enclosing label element.
    */
  label: React.element,
  /**
    * The position of the label.
    * @default 'end'
    */
  labelPlacement?: labelPlacement,
  /**
    * Callback fired when the state is changed.
    *
    * @param {React.SyntheticEvent} event The event source of the callback.
    * You can pull out the new checked state by accessing `event.target.checked` (boolean).
    */
  onChange?: (ReactEvent.Synthetic.t, bool) => unit,
  /**
    * If `true`, the label will indicate that the `input` is required.
    */
  required?: bool,
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
    * The value of the component.
    */
  value?: 'value,
}

@module("@mui/material/FormControlLabel")
external make: React.component<props<'value, 'inputRef>> = "default"
