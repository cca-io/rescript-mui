type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if the color is secondary. */
  colorSecondary?: string,
  /** Styles applied to the root element if the component is focused. */
  focused?: string,
  /** Styles applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `startAdornment` is provided. */
  adornedStart?: string,
  /** Styles applied to the root element if `endAdornment` is provided. */
  adornedEnd?: string,
  /** State class applied to the root element if `error={true}`. */
  error?: string,
  /** Styles applied to the input element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `multiline={true}`. */
  multiline?: string,
  /** Styles applied to the NotchedOutline element. */
  notchedOutline?: string,
  /** Styles applied to the input element. */
  input?: string,
  /** Styles applied to the input element if `size="small"`. */
  inputSizeSmall?: string,
  /** Styles applied to the input element if `multiline={true}`. */
  inputMultiline?: string,
  /** Styles applied to the input element if `startAdornment` is provided. */
  inputAdornedStart?: string,
  /** Styles applied to the input element if `endAdornment` is provided. */
  inputAdornedEnd?: string,
  /** Styles applied to the input element if `type="search"`. */
  inputTypeSearch?: string,
}

type slots = {
  ...InputBase.slots,
  /**
    * The component that renders the notchedOutline slot.
    * @default NotchedOutline
    */
  notchedOutline?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  ...InputBase.slotProps,
  /**
    * Props forwarded to the notchedOutline slot.
    */
  notchedOutline?: JsxDOM.domProps,
}

type publicProps<'value, 'inputRef> = {
  ...InputBase.publicProps<'value, 'inputRef>,
  /**
    * If `true`, the outline is notched to accommodate the label.
    */
  notched?: bool,
}

type props<'value, 'inputRef> = {
  ...publicProps<'value, 'inputRef>,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * See [OutlinedInput#label](/material-ui/api/outlined-input/#props)
    */
  label?: React.element,
  /**
    * Callback fired when the value is changed.
    *
    * @param {React.ChangeEvent<HTMLTextAreaElement | HTMLInputElement>} event The event source of the callback.
    * You can pull out the new value by accessing `event.target.value` (string).
    */
  onChange?: ReactEvent.Synthetic.t => unit,
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
}

@module("@mui/material/OutlinedInput")
external make: React.component<props<'value, 'inputRef>> = "default"
