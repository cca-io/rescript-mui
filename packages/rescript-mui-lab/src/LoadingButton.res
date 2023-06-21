type classes = {
  ...Mui.Button.classes,
  /** Styles applied to the root element if `loading={true}`. */
  loading?: string,
  /** Styles applied to the loadingIndicator element. */
  loadingIndicator?: string,
  /** Styles applied to the loadingIndicator element if `loadingPosition="center"`. */
  loadingIndicatorCenter?: string,
  /** Styles applied to the loadingIndicator element if `loadingPosition="start"`. */
  loadingIndicatorStart?: string,
  /** Styles applied to the loadingIndicator element if `loadingPosition="end"`. */
  loadingIndicatorEnd?: string,
  /** Styles applied to the endIcon element if `loading={true}` and `loadingPosition="end"`. */
  endIconLoadingEnd?: string,
  /** Styles applied to the startIcon element if `loading={true}` and `loadingPosition="start"`. */
  startIconLoadingStart?: string,
}

type loadingPosition =
  | @a("start") Start
  | @a("end") End
  | @a("center") Center

type props = {
  ...Mui.Button.props,
  /**
    * If `true`, the loading indicator is shown.
    * @default false
    */
  loading?: bool,
  /**
    * Element placed before the children if the button is in loading state.
    * The node should contain an element with `role="progressbar"` with an accessible name.
    * By default we render a `CircularProgress` that is labelled by the button itself.
    * @default <CircularProgress color="inherit" size={16} />
    */
  loadingIndicator?: React.element,
  /**
    * The loading indicator can be positioned on the start, end, or the center of the button.
    * @default 'center'
    */
  loadingPosition?: loadingPosition,
}

@module("@mui/lab/LoadingButton")
external make: React.component<props> = "default"
