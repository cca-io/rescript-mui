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
  | @as("start") Start
  | @as("end") End
  | @as("center") Center

type props = {
  ...Mui.Button.props,
}

@module("@mui/lab/LoadingButton")
external make: React.component<props> = "default"
