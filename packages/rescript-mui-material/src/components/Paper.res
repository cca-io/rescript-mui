type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element unless `square={true}`. */
  rounded?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="elevation"`. */
  elevation?: string,
  /** Styles applied to the root element if `elevation={0}`. */
  elevation0?: string,
  /** Styles applied to the root element if `elevation={1}`. */
  elevation1?: string,
  /** Styles applied to the root element if `elevation={2}`. */
  elevation2?: string,
  /** Styles applied to the root element if `elevation={3}`. */
  elevation3?: string,
  /** Styles applied to the root element if `elevation={4}`. */
  elevation4?: string,
  /** Styles applied to the root element if `elevation={5}`. */
  elevation5?: string,
  /** Styles applied to the root element if `elevation={6}`. */
  elevation6?: string,
  /** Styles applied to the root element if `elevation={7}`. */
  elevation7?: string,
  /** Styles applied to the root element if `elevation={8}`. */
  elevation8?: string,
  /** Styles applied to the root element if `elevation={9}`. */
  elevation9?: string,
  /** Styles applied to the root element if `elevation={10}`. */
  elevation10?: string,
  /** Styles applied to the root element if `elevation={11}`. */
  elevation11?: string,
  /** Styles applied to the root element if `elevation={12}`. */
  elevation12?: string,
  /** Styles applied to the root element if `elevation={13}`. */
  elevation13?: string,
  /** Styles applied to the root element if `elevation={14}`. */
  elevation14?: string,
  /** Styles applied to the root element if `elevation={15}`. */
  elevation15?: string,
  /** Styles applied to the root element if `elevation={16}`. */
  elevation16?: string,
  /** Styles applied to the root element if `elevation={17}`. */
  elevation17?: string,
  /** Styles applied to the root element if `elevation={18}`. */
  elevation18?: string,
  /** Styles applied to the root element if `elevation={19}`. */
  elevation19?: string,
  /** Styles applied to the root element if `elevation={20}`. */
  elevation20?: string,
  /** Styles applied to the root element if `elevation={21}`. */
  elevation21?: string,
  /** Styles applied to the root element if `elevation={22}`. */
  elevation22?: string,
  /** Styles applied to the root element if `elevation={23}`. */
  elevation23?: string,
  /** Styles applied to the root element if `elevation={24}`. */
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
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
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
