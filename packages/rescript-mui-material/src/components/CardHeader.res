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

type slots = {
  /**
    * The component that renders the root slot.
    * @default 'div'
    */
  root?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the avatar slot.
    * @default 'div'
    */
  avatar?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the action slot.
    * @default 'div'
    */
  action?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the content slot.
    * @default 'div'
    */
  content?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the title slot.
    * @default Typography
    */
  title?: OverridableComponent.t<Typography.props>,
  /**
    * The component that renders the subheader slot.
    * @default Typography
    */
  subheader?: OverridableComponent.t<Typography.props>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    */
  root?: JsxDOM.domProps,
  /**
    * Props forwarded to the avatar slot.
    */
  avatar?: JsxDOM.domProps,
  /**
    * Props forwarded to the action slot.
    */
  action?: JsxDOM.domProps,
  /**
    * Props forwarded to the content slot.
    */
  content?: JsxDOM.domProps,
  /**
    * Props forwarded to the title slot.
    */
  title?: Typography.props,
  /**
    * Props forwarded to the subheader slot.
    */
  subheader?: Typography.props,
}

type props = {
  ...CommonProps.t_NoTitle,
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
    * @deprecated Use `slotProps.subheader` instead. This prop will be removed in v7.
    */
  subheaderTypographyProps?: Typography.props,
  /**
    * The components used for each slot inside.
    * @default {}
    */
  slots?: slots,
  /**
    * The extra props for the slot components.
    * You can override the existing props or add new ones.
    * @default {}
    */
  slotProps?: slotProps,
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
    * @deprecated Use `slotProps.title` instead. This prop will be removed in v7.
    */
  titleTypographyProps?: Typography.props,
}

@module("@mui/material/CardHeader")
external make: React.component<props> = "default"
