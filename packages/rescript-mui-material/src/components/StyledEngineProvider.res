type props = {
  /**
    * Your component tree.
    */
  children: React.element,
  /**
    * By default, the styles are injected last in the <head> element of the page.
    * As a result, they gain more specificity than any other style sheet.
    * If you want to override MUI's styles, set this prop.
    */
  injectFirst: bool,
}

@module("@mui/material/styles")
external make: React.component<props> = "StyledEngineProvider"
