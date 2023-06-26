type classes = {
  /** Styles applied to the select component `select` class. */
  select?: string,
  /** Styles applied to the select component if `multiple={true}`. */
  multiple?: string,
  /** Styles applied to the select component if `variant="filled"`. */
  filled?: string,
  /** Styles applied to the select component if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the select component if `variant="standard"`. */
  standard?: string,
  /** State class applied to the select component `disabled` class. */
  disabled?: string,
  /** Styles applied to the icon component. */
  icon?: string,
  /** Styles applied to the icon component if the popup is open. */
  iconOpen?: string,
  /** Styles applied to the icon component if `variant="filled"`. */
  iconFilled?: string,
  /** Styles applied to the icon component if `variant="outlined"`. */
  iconOutlined?: string,
  /** Styles applied to the icon component if `variant="standard"`. */
  iconStandard?: string,
  /** Styles applied to the underlying native input component. */
  nativeInput?: string,
  /** State class applied to the root element if `error={true}`. */
  error?: string,
}

type variant =
  | @as("standard") Standard
  | @as("outlined") Outlined
  | @as("filled") Filled

type props<'value> = {
  ...OutlinedInput.publicProps,
  /**
    * If `true`, the width of the popover will automatically be set according to the items inside the
    * menu, otherwise it will be at least the width of the select input.
    * @default false
    */
  autoWidth?: bool,
  /**
    * The option elements to populate the select with.
    * Can be some `MenuItem` when `native` is false and `option` when `native` is true.
    *
    * ⚠️The `MenuItem` elements **must** be direct descendants when `native` is false.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    * @default {}
    */
  classes?: classes,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * If `true`, the component is initially open. Use when the component open state is not controlled (i.e. the `open` prop is not defined).
    * You can only use it when the `native` prop is `false` (default).
    * @default false
    */
  defaultOpen?: bool,
  /**
    * The default value. Use when the component is not controlled.
    */
  defaultValue?: 'value,
  /**
    * If `true`, a value is displayed even if no items are selected.
    *
    * In order to display a meaningful value, a function can be passed to the `renderValue` prop which
    * returns the value to be displayed when no items are selected.
    *
    * ⚠️ When using this prop, make sure the label doesn't overlap with the empty displayed value.
    * The label should either be hidden or forced to a shrunk state.
    * @default false
    */
  displayEmpty?: bool,
  /**
    * The icon that displays the arrow.
    * @default ArrowDropDownIcon
    */
  @as("IconComponent")
  iconComponent?: React.element,
  /**
    * An `Input` element, does not have to be a material-ui specific `Input`.
    */
  input?: React.element,
  /**
    * See [OutlinedInput#label](/material-ui/api/outlined-input/#props)
    */
  label?: React.element,
  /**
    * The ID of an element that acts as an additional label. The Select will
    * be labelled by the additional label and the selected value.
    */
  labelId?: string,
  /**
    * Props applied to the [`Menu`](/material-ui/api/menu/) element.
    */
  @as("MenuProps")
  menuProps?: Menu.props,
  /**
    * If `true`, `value` must be an array and the menu will support multiple selections.
    * @default false
    */
  multiple?: bool,
  /**
    * If `true`, the component uses a native `select` element.
    * @default false
    */
  native?: bool,
  /**
    * Callback fired when a menu item is selected.
    *
    * @param {SelectChangeEvent<T>} event The event source of the callback.
    * You can pull out the new value by accessing `event.target.value` (any).
    * **Warning**: This is a generic event, not a change event, unless the change event is caused by browser autofill.
    * @param {object} [child] The react element that was selected when `native` is `false` (default).
    */
  onChange?: (ReactEvent.Form.t, React.element) => unit,
  /**
    * Callback fired when the component requests to be closed.
    * Use it in either controlled (see the `open` prop), or uncontrolled mode (to detect when the Select collapses).
    *
    * @param {object} event The event source of the callback.
    */
  onClose?: ReactEvent.Synthetic.t => unit,
  /**
    * Callback fired when the component requests to be opened.
    * Use it in either controlled (see the `open` prop), or uncontrolled mode (to detect when the Select expands).
    *
    * @param {object} event The event source of the callback.
    */
  onOpen?: ReactEvent.Synthetic.t => unit,
  /**
    * If `true`, the component is shown.
    * You can only use it when the `native` prop is `false` (default).
    */
  @as("open")
  open_?: bool,
  /**
    * Render the selected value.
    * You can only use it when the `native` prop is `false` (default).
    *
    * @param {any} value The `value` provided to the component.
    * @returns {ReactNode}
    */
  renderValue?: 'value => React.element,
  /**
    * Props applied to the clickable div element.
    */
  @as("SelectDisplayProps")
  selectDisplayProps?: unknown,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The `input` value. Providing an empty string will select no options.
    * Set to an empty string `''` if you don't want any of the available options to be selected.
    *
    * If the value is an object it must have reference equality with the option in order to be selected.
    * If the value is not an object, the string representation must match with the string representation of the option in order to be selected.
    */
  value?: 'value,
  /**
    * The variant to use.
    * @default 'outlined'
    */
  variant?: variant,
}

@module("@mui/material/Select")
external make: React.component<props<'value>> = "default"
