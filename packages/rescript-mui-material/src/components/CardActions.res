type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element unless `disableSpacing={true}`. */
  spacing?: string,
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
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * If `true`, the actions do not have additional margin.
    * @default false
    */
  disableSpacing?: bool,
}

@module("@mui/material/CardActions")
external make: React.component<props> = "default"
