type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the ButtonBase root element if the action area is keyboard focused. */
  focusVisible?: string,
  /** Styles applied to the overlay that covers the action area when it is keyboard focused. */
  focusHighlight?: string,
}

type slots = {
  /**
    * The component that renders the root slot.
    * @default ButtonBase
    */
  root?: OverridableComponent.t<ButtonBase.props>,
  /**
    * The component that renders the focusHighlight slot.
    * @default 'span'
    */
  focusHighlight?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    */
  root?: ButtonBase.props,
  /**
    * Props forwarded to the focusHighlight slot.
    */
  focusHighlight?: JsxDOM.domProps,
}

type props = {
  ...ButtonBase.publicPropsWithOnClick,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
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

@module("@mui/material/CardActionArea")
external make: React.component<props> = "default"
