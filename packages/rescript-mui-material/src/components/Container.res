type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `disableGutters={true}`. */
  disableGutters?: string,
  /** Styles applied to the root element if `fixed={true}`. */
  fixed?: string,
  /** Styles applied to the root element if `maxWidth="xs"`. */
  maxWidthXs?: string,
  /** Styles applied to the root element if `maxWidth="sm"`. */
  maxWidthSm?: string,
  /** Styles applied to the root element if `maxWidth="md"`. */
  maxWidthMd?: string,
  /** Styles applied to the root element if `maxWidth="lg"`. */
  maxWidthLg?: string,
  /** Styles applied to the root element if `maxWidth="xl"`. */
  maxWidthXl?: string,
}

@unboxed
type maxWidth =
  | @as("xs") Xs
  | @as("sm") Sm
  | @as("md") Md
  | @as("lg") Lg
  | @as("xl") Xl
  | @as(false) False
  | String(string)

type props = {
  ...CommonProps.t,
  children?: React.element,
  /**
     * Override or extend the styles applied to the component.
     */
  classes?: classes,
  /**
     * If `true`, the left and right padding is removed.
     * @default false
     */
  disableGutters?: bool,
  /**
     * Set the max-width to match the min-width of the current breakpoint.
     * This is useful if you'd prefer to design for a fixed set of sizes
     * instead of trying to accommodate a fully fluid viewport.
     * It's fluid by default.
     * @default false
     */
  fixed?: bool,
  /**
     * Determine the max-width of the container.
     * The container width grows with the size of the screen.
     * Set to `false` to disable `maxWidth`.
     * @default 'lg'
     */
  maxWidth?: maxWidth,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
}

@module("@mui/material/Container")
external make: React.component<props> = "default"
