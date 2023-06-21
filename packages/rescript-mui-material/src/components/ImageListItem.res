type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to an `img` element to ensure it covers the item. */
  img?: string,
  /** Styles applied to the root element if `variant="standard"`. */
  standard?: string,
  /** Styles applied to the root element if `variant="woven"`. */
  woven?: string,
  /** Styles applied to the root element if `variant="masonry"`. */
  masonry?: string,
  /** Styles applied to the root element if `variant="quilted"`. */
  quilted?: string,
}

type props = {
  ...CommonProps.t,
  /**
    * The content of the component, normally an `<img>`.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * Width of the item in number of grid columns.
    * @default 1
    */
  cols?: int,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * Height of the item in number of grid rows.
    * @default 1
    */
  rows?: int,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/ImageListItem")
external make: React.component<props> = "default"
