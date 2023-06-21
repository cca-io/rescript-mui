type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `component="video, audio, picture, iframe, or img"`. */
  media?: string,
  /** Styles applied to the root element if `component="picture or img"`. */
  img?: string,
}

type props = {
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * Image to be displayed as a background image.
    * Either `image` or `src` prop must be specified.
    * Note that caller must specify height otherwise the image will not be visible.
    */
  image?: string,
  /**
    * An alias for `image` property.
    * Available only with media components.
    * Media components: `video`, `audio`, `picture`, `iframe`, `img`.
    */
  src?: string,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/CardMedia")
external make: React.component<props> = "default"
