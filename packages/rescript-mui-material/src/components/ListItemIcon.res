type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element when the parent `ListItem` uses `alignItems="flex-start"`. */
  alignItemsFlexStart?: string,
}

type props = {
  ...CommonProps.t,
  /**
    * The content of the component, normally `Icon`, `SvgIcon`,
    * or a `@mui/icons-material` SVG icon element.
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

@module("@mui/material/ListItemIcon")
external make: React.component<props> = "default"
