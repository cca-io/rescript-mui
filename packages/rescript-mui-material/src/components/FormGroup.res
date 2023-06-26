type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `row={true}`. */
  row?: string,
  /** State class applied to the root element if `error={true}`. */
  error?: string,
}

type props = {
  ...CommonProps.t,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * Display group of elements in a compact row.
    * @default false
    */
  row?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/FormGroup")
external make: React.component<props> = "default"
