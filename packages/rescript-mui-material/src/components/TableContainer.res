type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type props = {
  ...CommonProps.t,
  /**
    * The content of the component, normally `Table`.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/TableContainer")
external make: React.component<props> = "default"
