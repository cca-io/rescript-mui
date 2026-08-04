type variant = [#standard | #outlined | #filled]

type slots = {
  root?: Mui.OverridableComponent.t<unknown>,
  input?: Mui.OverridableComponent.t<unknown>,
  inputLabel?: Mui.OverridableComponent.t<unknown>,
  htmlInput?: Mui.OverridableComponent.t<unknown>,
  formHelperText?: Mui.OverridableComponent.t<unknown>,
}

type slotProps = {
  root?: Mui.FormControl.props,
  input?: Mui.Input.props<unknown, unknown>,
  inputLabel?: Mui.InputLabel.props,
  htmlInput?: Mui.InputBase.inputBaseComponentProps,
  formHelperText?: Mui.FormHelperText.props,
}

type props<'inputRef> = {
  ...Mui.CommonProps.t_NoRef,
  ref?: ReactDOM.domRef,
  elements: array<UnstablePickersSectionList.sectionElement>,
  sectionListRef: React.ref<UnstablePickersSectionList.refData>,
  contentEditable: bool,
  tabIndex?: int,
  areAllSectionsEmpty: bool,
  onClick: ReactEvent.Mouse.t => unit,
  onMouseDown: ReactEvent.Mouse.t => unit,
  onKeyDown: ReactEvent.Keyboard.t => unit,
  onInput: ReactEvent.Form.t => unit,
  onPaste: ReactEvent.Synthetic.t => unit,
  endAdornment?: React.element,
  startAdornment?: React.element,
  value: string,
  onChange: ReactEvent.Form.t => unit,
  label?: React.element,
  fullWidth?: bool,
  readOnly?: bool,
  name?: string,
  inputRef?: React.ref<'inputRef>,
  onFocus: ReactEvent.Focus.t => unit,
  onBlur: ReactEvent.Focus.t => unit,
  disabled: bool,
  error: bool,
  helperText?: React.element,
  classes?: {.},
  color?: Mui.FormControl.color,
  focused?: bool,
  hiddenLabel?: bool,
  margin?: Mui.FormControl.margin,
  required?: bool,
  size?: Mui.FormControl.size,
  sx?: Mui.Sx.props,
  variant?: variant,
  slots?: slots,
  slotProps?: slotProps,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'inputRef>> = "PickersTextField"
