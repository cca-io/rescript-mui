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

type props = {
  ...ButtonBase.publicPropsWithOnClick,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The icon to display as the expand indicator.
    */
  expandIcon?: React.element,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/AccordionSummary")
external make: React.component<props> = "default"
