type classes = {
  /** Styles applied to the root element. */
  root: string,
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
     * Enable `color-scheme` CSS property to use `theme.palette.mode`.
     * For more details, check out https://developer.mozilla.org/en-US/docs/Web/CSS/color-scheme
     * For browser support, check out https://caniuse.com/?search=color-scheme
     */
  enableColorScheme?: bool,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
}

@module("@mui/material")
external make: props => React.element = "ScopedCssBaseline"
