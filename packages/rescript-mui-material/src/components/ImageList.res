type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="masonry"`. */
  masonry?: string,
  /** Styles applied to the root element if `variant="quilted"`. */
  quilted?: string,
  /** Styles applied to the root element if `variant="standard"`. */
  standard?: string,
  /** Styles applied to the root element if `variant="woven"`. */
  woven?: string,
}

@unboxed
type variant =
  | @as("masonry") Masonry
  | @as("quilted") Quilted
  | @as("standard") Standard
  | @as("woven") Woven
  | String(string)

@unboxed
type rowHeight =
  | Number(float)
  | @as("auto") Auto

type props = {
  ...CommonProps.t,
  /**
    * The content of the component, normally `ImageListItem`s.
    */
  children: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * Number of columns.
    * @default 2
    */
  cols?: int,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * The gap between items in px.
    * @default 4
    */
  gap?: float,
  /**
    * The height of one row in px.
    * @default 'auto'
    */
  rowHeight?: rowHeight,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The variant to use.
    * @default 'standard'
    */
  variant?: variant,
}

@module("@mui/material/ImageList")
external make: React.component<props> = "default"
