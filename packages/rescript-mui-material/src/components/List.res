type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element unless `disablePadding={true}`. */
  padding?: string,
  /** Styles applied to the root element if dense. */
  dense?: string,
  /** Styles applied to the root element if a `subheader` is provided. */
  subheader?: string,
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
     * The component used for the root node. Either a string to use a HTML element or a component.
     */
  component?: OverridableComponent.t<unknown>,
  /**
     * If `true`, compact vertical padding designed for keyboard and mouse input is used for
     * the list and list items.
     * The prop is available to descendant components as the `dense` context.
     * @default false
     */
  dense?: bool,
  /**
     * If `true`, vertical padding is removed from the list.
     * @default false
     */
  disablePadding?: bool,
  /**
     * The content of the subheader, normally `ListSubheader`.
     */
  subheader?: React.element,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "List"
