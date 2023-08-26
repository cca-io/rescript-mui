type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the ol element. */
  ol?: string,
  /** Styles applied to the li element. */
  li?: string,
  /** Styles applied to the separator element. */
  separator?: string,
}

type slots = {@as("CollapsedIcon") collapsedIcon?: React.element}

type slotProps = {
  /**
    * Props applied to the CollapsedIcon slot.
    * @default {}
    */
  collapsedIcon?: SvgIcon.props,
}

type props = {
  ...CommonProps.t,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * Override the default label for the expand button.
    *
    * For localization purposes, you can use the provided [translations](/material-ui/guides/localization/).
    * @default 'Show path'
    */
  expandText?: string,
  /**
    * If max items is exceeded, the number of items to show after the ellipsis.
    * @default 1
    */
  itemsAfterCollapse?: int,
  /**
    * If max items is exceeded, the number of items to show before the ellipsis.
    * @default 1
    */
  itemsBeforeCollapse?: int,
  /**
    * Specifies the maximum number of breadcrumbs to display. When there are more
    * than the maximum number, only the first `itemsBeforeCollapse` and last `itemsAfterCollapse`
    * will be shown, with an ellipsis in between.
    * @default 8
    */
  maxItems?: int,
  /**
    * Custom separator node.
    * @default '/'
    */
  separator?: React.element,
  /**
    * The components used for each slot inside the Breadcumb.
    * Either a string to use a HTML element or a component.
    * @default {}
    */
  slots?: slots,
  /**
    * The props used for each slot inside the Breadcumb.
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/Breadcrumbs")
external make: React.component<props> = "default"
