type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element unless `square={true}`. */
  rounded?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="elevation"`. */
  elevation?: string,
  elevation0?: string,
  elevation1?: string,
  elevation2?: string,
  elevation3?: string,
  elevation4?: string,
  elevation5?: string,
  elevation6?: string,
  elevation7?: string,
  elevation8?: string,
  elevation9?: string,
  elevation10?: string,
  elevation11?: string,
  elevation12?: string,
  elevation13?: string,
  elevation14?: string,
  elevation15?: string,
  elevation16?: string,
  elevation17?: string,
  elevation18?: string,
  elevation19?: string,
  elevation20?: string,
  elevation21?: string,
  elevation22?: string,
  elevation23?: string,
  elevation24?: string,
}

@unboxed
type variant =
  | @as("elevation") Elevation
  | @as("outlined") Outlined
  | String(string)

type publicProps = {
  ...CommonProps.t,
  /**
    * Shadow depth, corresponds to `dp` in the spec.
    * It accepts values between 0 and 24 inclusive.
    * @default 1
  */
  elevation?: int,
  /**
    * If `true`, rounded corners are disabled.
    * @default false
  */
  square?: bool,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
  component?: OverridableComponent.t<unknown>,
}

type props = {
  ...publicProps,
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
    * The variant to use.
    * @default 'elevation'
  */
  variant?: variant,
}

@module("@mui/material/Paper")
external make: React.component<props> = "default"
