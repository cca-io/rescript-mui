type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the avatar element. */
  avatar?: string,
  /** Styles applied to the action element. */
  action?: string,
  /** Styles applied to the content wrapper element. */
  content?: string,
  /** Styles applied to the title Typography element. */
  title?: string,
  /** Styles applied to the subheader Typography element. */
  subheader?: string,
}

type props = {
  ...CommonProps.t,
  /**
    * The action to display in the card header.
    */
  action?: React.element,
  /**
    * The Avatar element to display.
    */
  avatar?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * If `true`, `subheader` and `title` won't be wrapped by a Typography component.
    * This can be useful to render an alternative Typography variant by wrapping
    * the `title` text, and optional `subheader` text
    * with the Typography component.
    * @default false
    */
  disableTypography?: bool,
  /**
    * The content of the component.
    */
  subheader?: React.element,
  /**
    * These props will be forwarded to the subheader
    * (as long as disableTypography is not `true`).
    */
  subheaderTypographyProps?: Typography.props,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The content of the component.
    */
  title?: React.element,
  /**
    * These props will be forwarded to the title
    * (as long as disableTypography is not `true`).
    */
  titleTypographyProps?: Typography.props,
}

@module("@mui/material/CardHeader")
external make: React.component<props> = "default"
