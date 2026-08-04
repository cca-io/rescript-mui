/** Frequently configured props for the picker field slot. */
type textFieldSlotProps = {
  className?: string,
  color?: Mui.FormControl.color,
  disabled?: bool,
  error?: bool,
  focused?: bool,
  fullWidth?: bool,
  helperText?: React.element,
  label?: React.element,
  margin?: Mui.FormControl.margin,
  name?: string,
  required?: bool,
  size?: Mui.FormControl.size,
  slots?: PickersTextField.slots,
  slotProps?: PickersTextField.slotProps,
  sx?: Mui.Sx.props,
  variant?: PickersTextField.variant,
}

type fieldSlotProps = {
  clearable?: bool,
  dateSeparator?: string,
  onClear?: ReactEvent.Mouse.t => unit,
  openPickerButtonPosition?: [#start | #end],
  shouldRespectLeadingZeros?: bool,
}

/** Named component slots shared by picker fields and views. */
type dateCalendarSlots = {
  calendarHeader?: Mui.OverridableComponent.t<unknown>,
  day?: Mui.OverridableComponent.t<unknown>,
  leftArrowIcon?: Mui.OverridableComponent.t<unknown>,
  monthButton?: Mui.OverridableComponent.t<unknown>,
  nextIconButton?: Mui.OverridableComponent.t<unknown>,
  previousIconButton?: Mui.OverridableComponent.t<unknown>,
  rightArrowIcon?: Mui.OverridableComponent.t<unknown>,
  switchViewButton?: Mui.OverridableComponent.t<unknown>,
  switchViewIcon?: Mui.OverridableComponent.t<unknown>,
  yearButton?: Mui.OverridableComponent.t<unknown>,
}

type datePickerSlots = {
  ...dateCalendarSlots,
  actionBar?: Mui.OverridableComponent.t<unknown>,
  clearButton?: Mui.OverridableComponent.t<unknown>,
  clearIcon?: Mui.OverridableComponent.t<unknown>,
  field?: Mui.OverridableComponent.t<unknown>,
  inputAdornment?: Mui.OverridableComponent.t<unknown>,
  layout?: Mui.OverridableComponent.t<unknown>,
  openPickerButton?: Mui.OverridableComponent.t<unknown>,
  openPickerIcon?: Mui.OverridableComponent.t<unknown>,
  shortcuts?: Mui.OverridableComponent.t<unknown>,
  textField?: Mui.OverridableComponent.t<unknown>,
  toolbar?: Mui.OverridableComponent.t<unknown>,
}

type timePickerSlots = {
  actionBar?: Mui.OverridableComponent.t<unknown>,
  arrowSwitcher?: Mui.OverridableComponent.t<unknown>,
  clearButton?: Mui.OverridableComponent.t<unknown>,
  clearIcon?: Mui.OverridableComponent.t<unknown>,
  field?: Mui.OverridableComponent.t<unknown>,
  inputAdornment?: Mui.OverridableComponent.t<unknown>,
  layout?: Mui.OverridableComponent.t<unknown>,
  leftArrowIcon?: Mui.OverridableComponent.t<unknown>,
  nextIconButton?: Mui.OverridableComponent.t<unknown>,
  openPickerButton?: Mui.OverridableComponent.t<unknown>,
  openPickerIcon?: Mui.OverridableComponent.t<unknown>,
  previousIconButton?: Mui.OverridableComponent.t<unknown>,
  rightArrowIcon?: Mui.OverridableComponent.t<unknown>,
  shortcuts?: Mui.OverridableComponent.t<unknown>,
  textField?: Mui.OverridableComponent.t<unknown>,
  toolbar?: Mui.OverridableComponent.t<unknown>,
}

type dateTimePickerSlots = {
  ...datePickerSlots,
  arrowSwitcher?: Mui.OverridableComponent.t<unknown>,
  tabs?: Mui.OverridableComponent.t<unknown>,
}

type fieldSlots = {
  clearButton?: Mui.OverridableComponent.t<unknown>,
  clearIcon?: Mui.OverridableComponent.t<unknown>,
  inputAdornment?: Mui.OverridableComponent.t<unknown>,
  textField?: Mui.OverridableComponent.t<unknown>,
}

type actionBarSlotProps = {
  actions?: array<PickersActionBar.action>,
  className?: string,
  sx?: Mui.Sx.props,
}

type calendarHeaderSlotProps = {
  className?: string,
  classes?: PickersCalendarHeader.classes,
  format?: string,
  sx?: Mui.Sx.props,
}

type toolbarSlotProps = {
  className?: string,
  hidden?: bool,
  toolbarFormat?: string,
  sx?: Mui.Sx.props,
}

type openPickerButtonSlotProps = {
  className?: string,
  color?: Mui.IconButton.color,
  disabled?: bool,
  edge?: Mui.IconButton.edge,
  size?: Mui.IconButton.size,
  sx?: Mui.Sx.props,
}

type inputAdornmentSlotProps = {
  className?: string,
  position?: Mui.InputAdornment.position,
  sx?: Mui.Sx.props,
}

type fieldComponentSlotProps = {
  clearButton?: openPickerButtonSlotProps,
  inputAdornment?: inputAdornmentSlotProps,
  textField?: textFieldSlotProps,
}

type daySlotProps = {
  className?: string,
  disableMargin?: bool,
  selected?: bool,
  sx?: Mui.Sx.props,
}

type shortcutsSlotProps<'date> = {
  items?: array<PickersShortcuts.shortcutItem<'date>>,
}

type dateCalendarSlotProps<'date> = {
  calendarHeader?: calendarHeaderSlotProps,
  day?: daySlotProps,
}

type datePickerSlotProps<'date> = {
  actionBar?: actionBarSlotProps,
  calendarHeader?: calendarHeaderSlotProps,
  day?: daySlotProps,
  field?: fieldSlotProps,
  inputAdornment?: inputAdornmentSlotProps,
  openPickerButton?: openPickerButtonSlotProps,
  shortcuts?: shortcutsSlotProps<'date>,
  textField?: textFieldSlotProps,
  toolbar?: toolbarSlotProps,
}

type timePickerSlotProps<'date> = {
  actionBar?: actionBarSlotProps,
  field?: fieldSlotProps,
  inputAdornment?: inputAdornmentSlotProps,
  openPickerButton?: openPickerButtonSlotProps,
  shortcuts?: shortcutsSlotProps<'date>,
  textField?: textFieldSlotProps,
  toolbar?: toolbarSlotProps,
}

type dateTimePickerSlotProps<'date> = {
  actionBar?: actionBarSlotProps,
  calendarHeader?: calendarHeaderSlotProps,
  day?: daySlotProps,
  field?: fieldSlotProps,
  inputAdornment?: inputAdornmentSlotProps,
  openPickerButton?: openPickerButtonSlotProps,
  shortcuts?: shortcutsSlotProps<'date>,
  textField?: textFieldSlotProps,
  toolbar?: toolbarSlotProps,
}
