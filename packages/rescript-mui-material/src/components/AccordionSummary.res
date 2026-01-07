type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element, children wrapper element and `IconButton` component if `expanded={true}`. */
  expanded?: string,
  /** State class applied to the ButtonBase root element if the button is keyboard focused. */
  focusVisible?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element unless `disableGutters={true}`. */
  gutters?: string,
  /** Styles applied to the children wrapper element unless `disableGutters={true}`. */
  contentGutters?: string,
  /** Styles applied to the children wrapper element. */
  content?: string,
  /** Styles applied to the `expandIcon`'s wrapper element. */
  expandIconWrapper?: string,
}

type slots = {
  /**
    * The component that renders the root slot.
    * @default ButtonBase
    */
  root?: OverridableComponent.t<ButtonBase.props>,
  /**
    * The component that renders the content slot.
    * @default div
    */
  content?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the expand icon wrapper slot.
    * @default div
    */
  expandIconWrapper?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    * By default, the avaible props are based on the [ButtonBase](https://mui.com/material-ui/api/button-base/#props) component.
    */
  root?: ButtonBase.props,
  /**
    * Props forwarded to the content slot.
    * By default, the avaible props are based on a div element.
    */
  content?: JsxDOM.domProps,
  /**
    * Props forwarded to the expand icon wrapper slot.
    * By default, the avaible props are based on a div element.
    */
  expandIconWrapper?: JsxDOM.domProps,
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
    * The icon to display as the expand indicator.
    */
  expandIcon?: React.element,
  /**
    * The components used for each slot inside.
    * @default {}
    */
  slots?: slots,
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

@module("@mui/material/AccordionSummary")
external make: React.component<props> = "default"
