type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `position="bottom"`. */
  positionBottom?: string,
  /** Styles applied to the root element if `position="top"`. */
  positionTop?: string,
  /** Styles applied to the root element if `position="below"`. */
  positionBelow?: string,
  /** Styles applied to the title and subtitle container element. */
  titleWrap?: string,
  /** Styles applied to the title and subtitle container element if `position="below"`. */
  titleWrapBelow?: string,
  /** Styles applied to the container element if `actionPosition="left"`. */
  titleWrapActionPosLeft?: string,
  /** Styles applied to the container element if `actionPosition="right"`. */
  titleWrapActionPosRight?: string,
  /** Styles applied to the title container element. */
  title?: string,
  /** Styles applied to the subtitle container element. */
  subtitle?: string,
  /** Styles applied to the actionIcon if supplied. */
  actionIcon?: string,
  /** Styles applied to the actionIcon if `actionPosition="left"`. */
  actionIconActionPosLeft?: string,
}

type actionPosition =
  | @as("left") Left
  | @as("right") Right

type position =
  | @as("below") Below
  | @as("bottom") Bottom
  | @as("top") Top

type props = {
  /**
   * An IconButton element to be used as secondary action target
   * (primary action target is the item itself).
   */
  actionIcon?: React.element,
  /**
   * Position of secondary action IconButton.
   * @default 'right'
   */
  actionPosition?: actionPosition,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * Position of the title bar.
   * @default 'bottom'
   */
  position?: position,
  /**
   * String or element serving as subtitle (support text).
   */
  subtitle?: React.element,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * Title to be displayed.
   */
  title?: React.element,
}

@module("@mui/material/ImageListItemBar")
external make: React.component<props> = "default"
