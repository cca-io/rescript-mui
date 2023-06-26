type classes = {
  /** Styles applied to the root element. */
  root?: string,
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
  /** State class applied to the select component `error` class. */
  error?: string,
}

type variant =
  | @as("filled") Filled
  | @as("outlined") Outlined
  | @as("standard") Standard

type props<'value> = {
  ...InputBase.publicProps,
  /**
    * The option elements to populate the select with.
    * Can be some `<option>` elements.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    * @default {}
    */
  classes?: classes,
  /**
    * The default value. Use when the component is not controlled.
    */
  defaultValue?: 'value,
  /**
    * If `true`, the `input` will not have an underline.
    */
  disableUnderline?: bool,
  /**
    * The icon that displays the arrow.
    * @default ArrowDropDownIcon
    */
  @as("IconComponent")
  iconComponent?: React.element,
  /**
    * An `Input` element, does not have to be a material-ui specific `Input`.
    * @default <Input />
    */
  input?: React.element,
  /**
    * Pass a ref to the `input` element.
    */
  inputRef?: React.ref<unknown>,
  /**
    * Callback fired when a menu item is selected.
    *
    * @param {React.ChangeEvent<HTMLSelectElement>} event The event source of the callback.
    * You can pull out the new value by accessing `event.target.value` (string).
    */
  onChange?: ReactEvent.Form.t => unit,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The `input` value. The DOM API casts this to a string.
    */
  value?: 'value,
  /**
    * The variant to use.
    */
  variant?: variant,
}

@module("@mui/material/NativeSelect")
external make: React.component<props<'value>> = "default"
