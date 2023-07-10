type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the week element. */
  week?: string,
  /** Styles applied to the day element. */
  daySkeleton?: string,
}

type props = {
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Mui.Sx.props,
  ref?: ReactDOM.domRef,
}

@module("@mui/x-date-pickers")
external make: React.component<props> = "DayCalendarSkeleton"
