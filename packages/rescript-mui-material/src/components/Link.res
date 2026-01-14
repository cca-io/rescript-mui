type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `underline="none"`. */
  underlineNone?: string,
  /** Styles applied to the root element if `underline="hover"`. */
  underlineHover?: string,
  /** Styles applied to the root element if `underline="always"`. */
  underlineAlways?: string,
  /** Styles applied to the root element if `component="button"`. */
  button?: string,
  /** State class applied to the root element if the link is keyboard focused. */
  focusVisible?: string,
}

type underline =
  | @as("none") None
  | @as("hover") Hover
  | @as("always") Always

type rel =
  | @as("alternate") Alternate
  | @as("author") Author
  | @as("bookmark") Bookmark
  | @as("external") External
  | @as("help") Help
  | @as("license") License
  | @as("next") Next
  | @as("nofollow") Nofollow
  | @as("noreferrer") Noreferrer
  | @as("noopener") Noopener
  | @as("prev") Prev
  | @as("search") Search
  | @as("tag") Tag

type props = {
  ...CommonProps.clickablePropsWithOnClick,
  ...Typography.publicProps,
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
    * `classes` prop applied to the [`Typography`](/material-ui/api/typography/) element.
    */
  @as("TypographyClasses")
  typographyClasses?: Typography.classes,
  /**
		* Controls when the link should have an underline.
		* @default 'always'
		*/
  underline?: underline,
  /**
    * Indicates that the link should be downloaded rather than navigated.
    */
  download?: string,
  // HTML anchor attributes
  href?: string,
  target?: string,
  rel?: rel,
}

@module("@mui/material/Link")
external make: React.component<props> = "default"
