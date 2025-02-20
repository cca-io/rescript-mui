type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type props = {
  ...Paper.publicProps,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, the card will use raised styling.
    * @default false
    */
  raised?: bool,
  /**
  * The variant to use.
  * @default 'elevation'
  */
  variant?: Paper.variant,
}

@module("@mui/material/Card")
external make: React.component<props> = "default"
