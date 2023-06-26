type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="body2"`. */
  body2?: string,
  /** Styles applied to the root element if `variant="body1"`. */
  body1?: string,
  /** Styles applied to the root element if `variant="caption"`. */
  caption?: string,
  /** Styles applied to the root element if `variant="button"`. */
  button?: string,
  /** Styles applied to the root element if `variant="h1"`. */
  h1?: string,
  /** Styles applied to the root element if `variant="h2"`. */
  h2?: string,
  /** Styles applied to the root element if `variant="h3"`. */
  h3?: string,
  /** Styles applied to the root element if `variant="h4"`. */
  h4?: string,
  /** Styles applied to the root element if `variant="h5"`. */
  h5?: string,
  /** Styles applied to the root element if `variant="h6"`. */
  h6?: string,
  /** Styles applied to the root element if `variant="subtitle1"`. */
  subtitle1?: string,
  /** Styles applied to the root element if `variant="subtitle2"`. */
  subtitle2?: string,
  /** Styles applied to the root element if `variant="overline"`. */
  overline?: string,
  /** Styles applied to the root element if `variant="inherit"`. */
  inherit?: string,
  /** Styles applied to the root element if `align="left"`. */
  alignLeft?: string,
  /** Styles applied to the root element if `align="center"`. */
  alignCenter?: string,
  /** Styles applied to the root element if `align="right"`. */
  alignRight?: string,
  /** Styles applied to the root element if `align="justify"`. */
  alignJustify?: string,
  /** Styles applied to the root element if `nowrap={true}`. */
  noWrap?: string,
  /** Styles applied to the root element if `gutterBottom={true}`. */
  gutterBottom?: string,
  /** Styles applied to the root element if `paragraph={true}`. */
  paragraph?: string,
}

type align =
  | @as("inherit") Inherit
  | @as("left") Left
  | @as("center") Center
  | @as("right") Right
  | @as("justify") Justify

@unboxed
type variant =
  | @as("body1") Body1
  | @as("body2") Body2
  | @as("button") Button
  | @as("caption") Caption
  | @as("h1") H1
  | @as("h2") H2
  | @as("h3") H3
  | @as("h4") H4
  | @as("h5") H5
  | @as("h6") H6
  | @as("inherit") Inherit
  | @as("overline") Overline
  | @as("subtitle1") Subtitle1
  | @as("subtitle2") Subtitle2
  | String(string)

type variantMapping = {
  h1: variant,
  h2: variant,
  h3: variant,
  h4: variant,
  h5: variant,
  h6: variant,
  subtitle1: variant,
  subtitle2: variant,
  body1: variant,
  body2: variant,
  inherit: variant,
}

type publicProps = {
  ...System.props,
  /**
    * Set the text-align on the component.
    * @default 'inherit'
    */
  align?: align,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * If `true`, the text will have a bottom margin.
    * @default false
    */
  gutterBottom?: bool,
  /**
    * If `true`, the text will not wrap, but instead will truncate with a text overflow ellipsis.
    *
    * Note that text overflow can only happen with block or inline-block level elements
    * (the element needs to have a width in order to overflow).
    * @default false
    */
  noWrap?: bool,
  /**
    * If `true`, the element will be a paragraph element.
    * @default false
    */
  paragraph?: bool,
  /**
    * Applies the theme typography styles.
    * @default 'body1'
    */
  variant?: variant,
  /**
    * The component maps the variant prop to a range of different HTML element types.
    * For instance, subtitle1 to `<h6>`.
    * If you wish to change that mapping, you can provide your own.
    * Alternatively, you can use the `component` prop.
    * @default {
    *   h1: 'h1',
    *   h2: 'h2',
    *   h3: 'h3',
    *   h4: 'h4',
    *   h5: 'h5',
    *   h6: 'h6',
    *   subtitle1: 'h6',
    *   subtitle2: 'h6',
    *   body1: 'p',
    *   body2: 'p',
    *   inherit: 'p',
    * }
    */
  variantMapping?: variantMapping,
}

type props = {
  ...publicProps,
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
}

@module("@mui/material/Typography")
external make: React.component<props> = "default"
