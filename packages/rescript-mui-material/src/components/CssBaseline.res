type props = {
  ...CommonProps.t_NoRef,
  /**
    * You can wrap a node.
    */
  children?: React.element,
  /**
    * Enable `color-scheme` CSS property to use `theme.palette.mode`.
    * For more details, check out https://developer.mozilla.org/en-US/docs/Web/CSS/color-scheme
    * For browser support, check out https://caniuse.com/?search=color-scheme
    * @default false
    */
  enableColorScheme?: bool,
}

@module("@mui/material/CssBaseline")
external make: React.component<props> = "default"
