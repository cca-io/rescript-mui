type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** State class applied to the root element if keyboard focused. */
  focusVisible?: string,
}

type buttonBaseActions = {focusVisible: unit => unit}

type startActionOptions = {
  pulsate?: bool,
  center?: bool,
}

type touchRippleActions = {
  start: (
    ~event: ReactEvent.Synthetic.t=?,
    ~options: startActionOptions=?,
    ~callback: unit => unit=?,
  ) => unit,
  pulsate: (~event: ReactEvent.Synthetic.t=?) => unit,
  stop: (~event: ReactEvent.Synthetic.t=?, ~callback: unit => unit=?) => unit,
}

type touchRippleClasses = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the internal `Ripple` components `ripple` class. */
  ripple: string,
  /** Styles applied to the internal `Ripple` components `rippleVisible` class. */
  rippleVisible: string,
  /** Styles applied to the internal `Ripple` components `ripplePulsate` class. */
  ripplePulsate: string,
  /** Styles applied to the internal `Ripple` components `child` class. */
  child: string,
  /** Styles applied to the internal `Ripple` components `childLeaving` class. */
  childLeaving: string,
  /** Styles applied to the internal `Ripple` components `childPulsate` class. */
  childPulsate: string,
}

type touchRippleProps = {
  center?: bool,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: touchRippleClasses,
}

@unboxed
type type_ =
  | @as("button") Button
  | @as("reset") Reset
  | @as("submit") Submit
  | String(string)

type publicProps = {
  ...CommonProps.clickableProps,
  /**
    * A ref for imperative actions.
    * It currently only supports `focusVisible()` action.
    */
  action?: React.ref<buttonBaseActions>,
  /**
    * If `true`, the ripples are centered.
    * They won't start at the cursor interaction position.
    * @default false
    */
  centerRipple?: bool,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * The component used for the root node. Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * If `true`, the ripple effect is disabled.
    *
    * ⚠️ Without a ripple there is no styling for :focus-visible by default. Be sure
    * to highlight the element by applying separate styles with the `.Mui-focusVisible` class.
    * @default false
    */
  disableRipple?: bool,
  /**
    * If `true`, the touch ripple effect is disabled.
    * @default false
    */
  disableTouchRipple?: bool,
  /**
    * If `true`, the base button will have a keyboard focus ripple.
    * @default false
    */
  focusRipple?: bool,
  /**
    * This prop can help identify which element has keyboard focus.
    * The class name will be applied when the element gains the focus through keyboard interaction.
    * It's a polyfill for the [CSS :focus-visible selector](https://drafts.csswg.org/selectors-4/#the-focus-visible-pseudo).
    * The rationale for using this feature [is explained here](https://github.com/WICG/focus-visible/blob/HEAD/explainer.md).
    * A [polyfill can be used](https://github.com/WICG/focus-visible) to apply a `focus-visible` class to other components
    * if needed.
    */
  focusVisibleClassName?: string,
  /**
    * The URL to link to when the button is clicked.
    * If defined, an `a` element will be used as the root node.
    */
  href?: string,
  /**
    * The component used to render a link when the `href` prop is provided.
    * @default 'a'
    */
  @as("LinkComponent")
  linkComponent?: React.element,
  /**
    * Callback fired when the component is focused with a keyboard.
    * We trigger a `onFocus` callback too.
    */
  onFocusVisible?: ReactEvent.Focus.t => unit,
  /**
    * The rel attribute for the link.
    */
  rel?: string,
  /**
    * @default 0
    */
  tabIndex?: int,
  /**
   * The target attribute of the link.
   */
  target?: string,
  /**
    * Props applied to the `TouchRipple` element.
    */
  @as("TouchRippleProps")
  touchRippleProps?: touchRippleProps,
  /**
    * A ref that points to the `TouchRipple` element.
    */
  touchRippleRef?: React.ref<touchRippleActions>,
  @as("type") type_?: type_,
}

type publicPropsWithOnClick = {
  ...publicProps,
  onClick?: ReactEvent.Mouse.t => unit,
}

type props = {
  ...publicPropsWithOnClick,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/ButtonBase")
external make: React.component<props> = "default"
