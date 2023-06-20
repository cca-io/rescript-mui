type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type props<'value> = {
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
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * Callback fired when the value changes.
    *
    * @param {React.SyntheticEvent} event The event source of the callback. **Warning**: This is a generic event not a change event.
    * @param {any} value We default to the index of the child.
    */
  onChange?: (ReactEvent.Synthetic.t, 'value) => unit,
  /**
    * If `true`, all `BottomNavigationAction`s will show their labels.
    * By default, only the selected `BottomNavigationAction` will show its label.
    * @default false
    */
  showLabels?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The value of the currently selected `BottomNavigationAction`.
    */
  value?: 'value,
}

@module("@mui/material/BottomNavigation")
external make: React.component<props<'value>> = "default"
