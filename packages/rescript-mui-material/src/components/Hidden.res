type implementation =
  | @as("js") Js
  | @as("css") Css

type breakpoint =
  | @as("xs") Xs
  | @as("sm") Sm
  | @as("md") Md
  | @as("lg") Lg
  | @as("xl") Xl

type props = {
  ...CommonProps.t_NoRef,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Specify which implementation to use.  'js' is the default, 'css' works better for
    * server-side rendering.
    * @default 'js'
    */
  implementation?: implementation,
  /**
    * You can use this prop when choosing the `js` implementation with server-side rendering.
    *
    * As `window.innerWidth` is unavailable on the server,
    * we default to rendering an empty component during the first mount.
    * You might want to use a heuristic to approximate
    * the screen width of the client browser screen width.
    *
    * For instance, you could be using the user-agent or the client-hints.
    * https://caniuse.com/#search=client%20hint
    */
  initialWidth?: breakpoint,
  /**
    * If `true`, screens this size and down are hidden.
    * @default false
    */
  lgDown?: bool,
  /**
    * If `true`, screens this size and up are hidden.
    * @default false
    */
  lgUp?: bool,
  /**
    * If `true`, screens this size and down are hidden.
    * @default false
    */
  mdDown?: bool,
  /**
    * If `true`, screens this size and up are hidden.
    * @default false
    */
  mdUp?: bool,
  /**
    * Hide the given breakpoint(s).
    */
  only?: array<breakpoint>,
  /**
    * If `true`, screens this size and down are hidden.
    * @default false
    */
  smDown?: bool,
  /**
    * If `true`, screens this size and up are hidden.
    * @default false
    */
  smUp?: bool,
  /**
    * If `true`, screens this size and down are hidden.
    * @default false
    */
  xlDown?: bool,
  /**
    * If `true`, screens this size and up are hidden.
    * @default false
    */
  xlUp?: bool,
  /**
    * If `true`, screens this size and down are hidden.
    * @default false
    */
  xsDown?: bool,
  /**
    * If `true`, screens this size and up are hidden.
    * @default false
    */
  xsUp?: bool,
}

@module("@mui/material/Hidden")
external make: React.component<props> = "default"
