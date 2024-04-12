type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `fullWidth={true}`. */
  fullWidth?: string,
  /** State class applied to the root element if the listbox is displayed. */
  expanded?: string,
  /** State class applied to the root element if focused. */
  focused?: string,
  /** Styles applied to the option elements if they are keyboard focused. */
  focusVisible?: string,
  /** Styles applied to the tag elements, e.g. the chips. */
  tag?: string,
  /** Styles applied to the tag elements, e.g. the chips if `size="small"`. */
  tagSizeSmall?: string,
  /** Styles applied to the tag elements, e.g. the chips if `size="medium"`. */
  tagSizeMedium?: string,
  /** Styles applied when the popup icon is rendered. */
  hasPopupIcon?: string,
  /** Styles applied when the clear icon is rendered. */
  hasClearIcon?: string,
  /** Styles applied to the Input element. */
  inputRoot?: string,
  /** Styles applied to the input element. */
  input?: string,
  /** Styles applied to the input element if the input is focused. */
  inputFocused?: string,
  /** Styles applied to the endAdornment element. */
  endAdornment?: string,
  /** Styles applied to the clear indicator. */
  clearIndicator?: string,
  /** Styles applied to the popup indicator. */
  popupIndicator?: string,
  /** Styles applied to the popup indicator if the popup is open. */
  popupIndicatorOpen?: string,
  /** Styles applied to the popper element. */
  popper?: string,
  /** Styles applied to the popper element if `disablePortal={true}`. */
  popperDisablePortal?: string,
  /** Styles applied to the Paper component. */
  paper?: string,
  /** Styles applied to the listbox component. */
  listbox?: string,
  /** Styles applied to the loading wrapper. */
  loading?: string,
  /** Styles applied to the no option wrapper. */
  noOptions?: string,
  /** Styles applied to the option elements. */
  option?: string,
  /** Styles applied to the group's label elements. */
  groupLabel?: string,
  /** Styles applied to the group's ul elements. */
  groupUl?: string,
}

type blurOnSelect =
  | @as("touch") Touch
  | @as("mouse") Mouse
  | @as(true) True
  | @as(false) False

type changeReason =
  | @as("createOption") CreateOption
  | @as("selectOption") SelectOption
  | @as("removeOption") RemoveOption
  | @as("clear") Clear
  | @as("blur") Blur

type inputChangeReason =
  | @as("input") Input
  | @as("reset") Reset
  | @as("clear") Clear

type closeReason =
  | @as("createOption") CreateOption
  | @as("toggleInput") ToggleInput
  | @as("escape") Escape
  | @as("selectOption") SelectOption
  | @as("removeOption") RemoveOption
  | @as("blur") Blur

type filterOptionsState<'a> = {
  inputValue: string,
  getOptionLabel: 'a => string,
}

type componentsProps = {
  clearIndicator?: IconButton.props,
  paper?: Paper.props,
  popper?: Popper.props,
  popupIndicator?: IconButton.props,
}

type listboxProps = {
  sx?: Sx.props,
  ref?: React.ref<React.element>,
}

@unboxed
type forcePopupIcon =
  | @as(true) True
  | @as(false) False
  | @as("auto") Auto

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | String(string)

type ownerState = {
  disablePortal: bool,
  expanded: bool,
  focused: bool,
  fullWidth: bool,
  hasClearIcon: bool,
  hasPopupIcon: bool,
  inputFocused: bool,
  popupOpen: bool,
  size: size,
}

type renderGetTagProps = {
  key: int,
  className: string,
  disabled: bool,
  @as("data-tag-index") dataTagIndex: int,
  tabIndex: int,
  onDelete: ReactEvent.Synthetic.t => unit,
}

type highlightChangeReason =
  | @as("keyboard") Keyboard
  | @as("mouse") Mouse
  | @as("auto") Auto
  | @as("touch") Touch

type renderOptionState = {
  inputValue: string,
  index: int,
  selected: bool,
}

type renderGroupParams = {
  key: string,
  group: string,
  children?: React.element,
}

type renderInputParams<'value> = {
  id: string,
  disabled: bool,
  fullWidth: bool,
  size: size,
  @as("InputLabelProps") inputLabelProps: InputLabel.props,
  @as("InputProps") inputProps_: Input.props<'value>,
  inputProps: InputBase.inputBaseComponentProps,
}

external renderInputParamsToTextFieldProps: renderInputParams<'a> => TextField.props<'value> =
  "%identity"

type slotProps = {
  clearIndicator?: IconButton.props,
  paper?: Paper.props,
  popper?: Popper.props,
  popupIndicator?: IconButton.props,
}

type autocompleteProps<'value> = {
  ...CommonProps.t_NoId,
  /**
    * Array of options.
    */
  options: array<'value>,
  /**
    * Render the input.
    *
    * @param {object} params
    * @returns {ReactNode}
    */
  renderInput: renderInputParams<'value> => React.element,
  /**
    * If `true`, the portion of the selected suggestion that has not been typed by the user,
    * known as the completion string, appears inline after the input cursor in the textbox.
    * The inline completion string is visually highlighted and has a selected state.
    * @default false
    */
  autoComplete?: bool,
  /**
    * If `true`, the first option is automatically highlighted.
    * @default false
    */
  autoHighlight?: bool,
  /**
    * If `true`, the selected option becomes the value of the input
    * when the Autocomplete loses focus unless the user chooses
    * a different option or changes the character string in the input.
    *
    * When using `freeSolo` mode, the typed value will be the input value
    * if the Autocomplete loses focus without highlighting an option.
    * @default false
    */
  autoSelect?: bool,
  /**
    * Control if the input should be blurred when an option is selected:
    *
    * - `false` the input is not blurred.
    * - `true` the input is always blurred.
    * - `touch` the input is blurred after a touch event.
    * - `mouse` the input is blurred after a mouse event.
    * @default false
    */
  blurOnSelect?: blurOnSelect,
  /**
    * Props applied to the [`Chip`](/material-ui/api/chip/) element.
    */
  @as("ChipProps")
  chipProps?: Chip.props,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The icon to display in place of the default clear icon.
    * @default <ClearIcon fontSize="small" />
    */
  clearIcon?: React.element,
  /**
    * If `true`, the input's text is cleared on blur if no value is selected.
    *
    * Set to `true` if you want to help the user enter a new value.
    * Set to `false` if you want to help the user resume their search.
    * @default !props.freeSolo
    */
  clearOnBlur?: bool,
  /**
    * If `true`, clear all values when the user presses escape and the popup is closed.
    * @default false
    */
  clearOnEscape?: bool,
  /**
    * Override the default text for the *clear* icon button.
    *
    * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
    * @default 'Clear'
    */
  clearText?: string,
  /**
    * Override the default text for the *close popup* icon button.
    *
    * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
    * @default 'Close'
    */
  closeText?: string,
  /**
    * The props used for each slot inside.
    * @default {}
    */
  componentsProps?: componentsProps,
  /**
    * If `true`, the input can't be cleared.
    * @default false
    */
  disableClearable?: bool,
  /**
    * If `true`, the popup won't close when a value is selected.
    * @default false
    */
  disableCloseOnSelect?: bool,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, will allow focus on disabled items.
    * @default false
    */
  disabledItemsFocusable?: bool,
  /**
    * If `true`, the list box in the popup will not wrap focus.
    * @default false
    */
  disableListWrap?: bool,
  /**
    * If `true`, the `Popper` content will be under the DOM hierarchy of the parent component.
    * @default false
    */
  disablePortal?: bool,
  /**
    * A function that determines the filtered options to be rendered on search.
    *
    * @default createFilterOptions()
    * @param {T[]} options The options to render.
    * @param {object} state The state of the component.
    * @returns {T[]}
    */
  filterOptions?: (array<'value>, filterOptionsState<'value>) => array<'value>,
  /**
    * If `true`, hide the selected options from the list box.
    * @default false
    */
  filterSelectedOptions?: bool,
  /**
    * Force the visibility display of the popup icon.
    * @default 'auto'
    */
  forcePopupIcon?: forcePopupIcon,
  /**
    * If `true`, the Autocomplete is free solo, meaning that the user input is not bound to provided options.
    * @default false
    */
  freeSolo?: bool,
  /**
    * If `true`, the input will take up the full width of its container.
    * @default false
    */
  fullWidth?: bool,
  /**
    * The label to display when the tags are truncated (`limitTags`).
    *
    * @param {number} more The number of truncated tags.
    * @returns {ReactNode}
    * @default (more) => `+${more}`
    */
  getLimitTagsText?: int => React.element,
  /**
    * Used to determine the disabled state for a given option.
    *
    * @param {T} option The option to test.
    * @returns {boolean}
    */
  getOptionDisabled?: 'value => bool,
  /**
    * Used to determine the string value for a given option.
    * It's used to fill the input (and the list box options if `renderOption` is not provided).
    *
    * If used in free solo mode, it must accept both the type of the options and a string.
    *
    * @param {T} option
    * @returns {string}
    * @default (option) => option.label ?? option
    */
  getOptionLabel?: 'value => string,
  /**
    * If provided, the options will be grouped under the returned string.
    * The groupBy value is also used as the text for group headings when `renderGroup` is not provided.
    *
    * @param {T} options The options to group.
    * @returns {string}
    */
  groupBy?: 'value => string,
  /**
    * If `true`, the component handles the "Home" and "End" keys when the popup is open.
    * It should move focus to the first option and last option, respectively.
    * @default !props.freeSolo
    */
  handleHomeEndKeys?: bool,
  /**
    * This prop is used to help implement the accessibility logic.
    * If you don't provide an id it will fall back to a randomly generated one.
    */
  id?: string,
  /**
    * If `true`, the highlight can move to the input.
    * @default false
    */
  includeInputInList?: bool,
  /**
    * The input value.
    */
  inputValue?: string,
  /**
    * The maximum number of tags that will be visible when not focused.
    * Set `-1` to disable the limit.
    * @default -1
    */
  limitTags?: int,
  /**
    * The component used to render the listbox.
    * @default 'ul'
    */
  @as("ListboxComponent")
  listboxComponent?: OverridableComponent.t<listboxProps>,
  /**
    * Props applied to the Listbox element.
    */
  @as("ListboxProps")
  listboxProps?: listboxProps,
  /**
    * If `true`, the component is in a loading state.
    * This shows the `loadingText` in place of suggestions (only if there are no suggestions to show, e.g. `options` are empty).
    * @default false
    */
  loading?: bool,
  /**
    * Text to display when in a loading state.
    *
    * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
    * @default 'Loading…'
    */
  loadingText?: React.element,
  /**
    * Text to display when there are no options.
    *
    * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
    * @default 'No options'
    */
  noOptionsText?: React.element,
  /**
    * Callback fired when the popup requests to be closed.
    * Use in controlled mode (see open).
    *
    * @param {React.SyntheticEvent} event The event source of the callback.
    * @param {string} reason Can be: `"toggleInput"`, `"escape"`, `"selectOption"`, `"removeOption"`, `"blur"`.
    */
  onClose?: (ReactEvent.Synthetic.t, closeReason) => unit,
  /**
    * Callback fired when the highlight option changes.
    *
    * @param {React.SyntheticEvent} event The event source of the callback.
    * @param {T} option The highlighted option.
    * @param {string} reason Can be: `"keyboard"`, `"auto"`, `"mouse"`, `"touch"`.
    */
  onHighlightChange?: (ReactEvent.Synthetic.t, 'value, highlightChangeReason) => unit,
  /**
    * Callback fired when the input value changes.
    *
    * @param {React.SyntheticEvent} event The event source of the callback.
    * @param {string} value The new value of the text input.
    * @param {string} reason Can be: `"input"` (user input), `"reset"` (programmatic change), `"clear"`.
    */
  onInputChange?: (ReactEvent.Synthetic.t, string, inputChangeReason) => unit,
  /**
    * Callback fired when the popup requests to be opened.
    * Use in controlled mode (see open).
    *
    * @param {React.SyntheticEvent} event The event source of the callback.
    */
  onOpen?: ReactEvent.Synthetic.t => unit,
  /**
    * If `true`, the component is shown.
    */
  @as("open")
  open_?: bool,
  /**
    * If `true`, the popup will open on input focus.
    * @default false
    */
  openOnFocus?: bool,
  /**
    * Override the default text for the *open popup* icon button.
    *
    * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
    * @default 'Open'
    */
  openText?: string,
  /**
    * The component used to render the body of the popup.
    * @default Paper
    */
  @as("PaperComponent")
  paperComponent?: OverridableComponent.t<unknown>,
  /**
    * The component used to position the popup.
    * @default Popper
    */
  @as("PopperComponent")
  popperComponent?: OverridableComponent.t<Popper.props>,
  /**
    * The icon to display in place of the default popup icon.
    * @default <ArrowDropDownIcon />
    */
  popupIcon?: React.element,
  /**
    * If `true`, the component becomes readonly. It is also supported for multiple tags where the tag cannot be deleted.
    * @default false
    */
  readOnly?: bool,
  /**
    * Render the group.
    *
    * @param {AutocompleteRenderGroupParams} params The group to render.
    * @returns {ReactNode}
    */
  renderGroup?: renderGroupParams => React.element,
  /**
    * Render the option, use `getOptionLabel` by default.
    *
    * @param {object} props The props to apply on the li element.
    * @param {T} option The option to render.
    * @param {object} state The state of each option.
    * @param {object} ownerState The state of the Autocomplete component.
    * @returns {ReactNode}
    */
  renderOption?: (JsxDOM.domProps, 'value, renderOptionState, ownerState) => React.element,
  /**
    * Render the selected value.
    *
    * @param {T[]} value The `value` provided to the component.
    * @param {function} getTagProps A tag props getter.
    * @param {object} ownerState The state of the Autocomplete component.
    * @returns {ReactNode}
    */
  renderTags?: (array<'value>, JsxDOM.domProps => renderGetTagProps, ownerState) => React.element,
  /**
    * If `true`, the input's text is selected on focus.
    * It helps the user clear the selected value.
    * @default !props.freeSolo
    */
  selectOnFocus?: bool,
  /**
    * The size of the component.
    * @default 'medium'
    */
  size?: size,
  /**
    * The props used for each slot inside.
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

module Multiple = {
  @unboxed
  type multiple = | @as(true) True

  type props<'value> = {
    ...autocompleteProps<'value>,
    /**
      * The default value. Use when the component is not controlled.
      * @default []
      */
    defaultValue?: array<'value>,
    /**
      * Must be set to `True` as the `value` must be an array and the menu will support multiple selections.
      */
    multiple: multiple,
    /**
      * Callback fired when the value changes.
      *
      * @param {ReactEvent.Synthetic.t} The event source of the callback.
      * @param {array<'value>} The new array value of the component.
      * @param {reason} One of CreateOption | SelectOption | RemoveOption | Clear | Blur
      * @param {string} [details]
      */
    onChange?: (ReactEvent.Synthetic.t, array<'value>, changeReason, string) => unit,
    /**
    * Used to determine if the option represents the given value.
    * Uses strict equality by default.
    * ⚠️ Both arguments need to be handled, an option can only match with one value.
    *
    * @param {T} option The option to test.
    * @param {T} value The value to test against.
    * @returns {boolean}
    */
    isOptionEqualToValue?: ('value, 'value) => bool,
    /**
      * The value of the autocomplete.
      *
      * The value must have reference equality with the option in order to be selected.
      * You can customize the equality behavior with the `isOptionEqualToValue` prop.
      */
    value?: array<'value>,
  }

  @module("@mui/material/Autocomplete")
  external make: React.component<props<'value>> = "default"
}

type props<'value> = {
  ...autocompleteProps<'value>,
  /**
    * The default value. Use when the component is not controlled.
    * @default null
    */
  defaultValue?: Js.null<'value>,
  /**
    * Callback fired when the value changes.
    *
    * @param {ReactEvent.Synthetic.t} The event source of the callback.
    * @param {'value} The new value of the component.
    * @param {reason} One of CreateOption | SelectOption | RemoveOption | Clear | Blur
    * @param {string} [details]
    */
  onChange?: (ReactEvent.Synthetic.t, Js.null<'value>, changeReason, string) => unit,
  /**
    * Used to determine if the option represents the given value.
    * Uses strict equality by default.
    * ⚠️ Both arguments need to be handled, an option can only match with one value.
    *
    * @param {T} option The option to test.
    * @param {T} value The value to test against.
    * @returns {boolean}
    */
  isOptionEqualToValue?: (Js.null<'value>, Js.null<'value>) => bool,
  /**
    * The value of the autocomplete.
    *
    * The value must have reference equality with the option in order to be selected.
    * You can customize the equality behavior with the `isOptionEqualToValue` prop.
    * It is both an option and nullable, because None compiles to undefined which means that the component is used in uncontrolled mode.
    * To use it in controlled mode, always set a value or Js.null.
    */
  value?: Js.null<'value>,
}

@module("@mui/material/Autocomplete")
external make: React.component<props<'value>> = "default"
