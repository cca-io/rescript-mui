type props = {
  ...System.props,
  children?: React.element,
  /**
  * The component used for the root node.
  * Either a string to use a HTML element or a component.
  */
  component?: OverridableComponent.t<unknown>,
  /**
  * The system prop that allows defining system overrides as well as additional CSS styles.
  */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "Box"
