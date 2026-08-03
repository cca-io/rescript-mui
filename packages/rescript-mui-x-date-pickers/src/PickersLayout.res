type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element in landscape orientation. */
  landscape?: string,
  /** Styles applied to the content wrapper element. */
  contentWrapper?: string,
  /** Styles applied to the toolbar. */
  toolbar?: string,
  /** Styles applied to the action bar. */
  actionBar?: string,
  /** Styles applied to the tabs. */
  tabs?: string,
  /** Styles applied to the shortcuts container. */
  shortcuts?: string,
}

type props = {
  ...Mui.CommonProps.t,
  /** Override or extend the styles applied to the component. */
  classes?: classes,
  /** The content of the component. */
  children?: React.element,
  /** Overridable component slots. @default {} */
  slots?: {.},
  /** The props used for each component slot. @default {} */
  slotProps?: {.},
  /** The system prop for defining system overrides and additional CSS styles. */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props> = "PickersLayout"
