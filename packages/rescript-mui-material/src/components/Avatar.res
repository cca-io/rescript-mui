type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if not `src` or `srcSet`. */
  colorDefault?: string,
  /** Styles applied to the root element if `variant="circular"`. */
  circular?: string,
  /** Styles applied to the root element if `variant="rounded"`. */
  rounded?: string,
  /** Styles applied to the root element if `variant="square"`. */
  square?: string,
  /** Styles applied to the img element if either `src` or `srcSet` is defined. */
  img?: string,
  /** Styles applied to the fallback icon */
  fallback?: string,
}

@unboxed
type variant =
  | @as("circular") Circular
  | @as("rounded") Rounded
  | @as("square") Square
  | String(string)

type imgProps = {
  ...System.props,
  // React.ImgHTMLAttributes<HTMLImageElement>
}

type props = {
  ...CommonProps.t,
  /**
     * Used in combination with `src` or `srcSet` to
     * provide an alt attribute for the rendered `img` element.
     */
  alt?: string,
  /**
     * Used to render icon or text elements inside the Avatar if `src` is not set.
     * This can be an element, or just a string.
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
     * [Attributes](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/img#attributes) applied to the `img` element if the component is used to display an image.
     * It can be used to listen for the loading error event.
     */
  imgProps?: imgProps,
  /**
     * The `sizes` attribute for the `img` element.
     */
  sizes?: string,
  /**
     * The `src` attribute for the `img` element.
     */
  src?: string,
  /**
     * The `srcSet` attribute for the `img` element.
     * Use this attribute for responsive image display.
     */
  srcSet?: string,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
  /**
     * The shape of the avatar.
     * @default 'circular'
     */
  variant?: variant,
}

@module("@mui/material/Avatar")
external make: React.component<props> = "default"
