type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if selected. */
  selected?: string,
  /** State class applied to the root element if `showLabel={false}` and not selected. */
  iconOnly?: string,
  /** Styles applied to the label's span element. */
  label?: string,
}

type slots = {
  /**
    * The component that renders the root slot.
    * @default ButtonBase
    */
  root?: OverridableComponent.t<ButtonBase.props>,
  /**
    * The component that renders the label slot.
    * @default 'span'
    */
  label?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    */
  root?: ButtonBase.props,
  /**
    * Props forwarded to the label slot.
    */
  label?: JsxDOM.domProps,
}

type props<'value> = {
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
    * The icon to display.
    */
  icon?: React.element,
  /**
    * The label element.
    */
  label?: React.element,
  onChange?: ReactEvent.Form.t => unit,
  /**
    * If `true`, the `BottomNavigationAction` will show its label.
    * By default, only the selected `BottomNavigationAction`
    * inside `BottomNavigation` will show its label.
    *
    * The prop defaults to the value (`false`) inherited from the parent BottomNavigation component.
    */
  showLabel?: bool,
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
  /**
    * You can provide your own value. Otherwise, we fallback to the child position index.
    */
  value?: 'value,
}

@module("@mui/material/BottomNavigationAction")
external make: React.component<props<'value>> = "default"
