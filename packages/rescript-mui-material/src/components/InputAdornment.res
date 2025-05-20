type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="filled"`. */
  filled?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="standard"`. */
  standard?: string,
  /** Styles applied to the root element if `position="start"`. */
  positionStart?: string,
  /** Styles applied to the root element if `position="end"`. */
  positionEnd?: string,
  /** Styles applied to the root element if `disablePointerEvents={true}`. */
  disablePointerEvents?: string,
  /** Styles applied if the adornment is used inside <FormControl hiddenLabel />. */
  hiddenLabel?: string,
  /** Styles applied if the adornment is used inside <FormControl size="small" />. */
  sizeSmall?: string,
}

type position =
  | @as("start") Start
  | @as("end") End

type variant =
  | @as("standard") Standard
  | @as("outlined") Outlined
  | @as("filled") Filled

type props = {
  ...CommonProps.t,
  /**
    * The position this adornment should appear relative to the `Input`.
    */
  position: position,
  /**
    * The content of the component, normally an `IconButton` or string.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * Disable pointer events on the root.
    * This allows for the content of the adornment to focus the `input` on click.
    * @default false
    */
  disablePointerEvents?: bool,
  /**
    * If children is a string then disable wrapping in a Typography component.
    * @default false
    */
  disableTypography?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The variant to use.
    * Note: If you are using the `TextField` component or the `FormControl` component
    * you do not have to set this manually.
    */
  variant?: variant,
  /**
    * Callback fired when the component is clicked.
    */
  onClick?: ReactEvent.Mouse.t => unit,
}

@module("@mui/material/InputAdornment")
external make: React.component<props> = "default"
