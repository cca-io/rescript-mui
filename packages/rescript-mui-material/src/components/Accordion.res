type transitionProps

type props = {
  ...Paper.props,
  /**
   * If `true`, expands the accordion by default.
   * @default false
   */
  defaultExpanded?: bool,
  /**
   * If `true`, the component is disabled.
   * @default false
   */
  disabled?: bool,
  /**
   * If `true`, it removes the margin between two expanded accordion items and the increase of height.
   * @default false
   */
  disableGutters?: bool,
  /**
   * If `true`, expands the accordion, otherwise collapses it.
   * Setting this prop enables control over the accordion.
   */
  expanded?: bool,
  /**
   * Callback fired when the expand/collapse state is changed.
   *
   * @param {React.SyntheticEvent} event The event source of the callback. **Warning**: This is a generic event not a change event.
   * @param {boolean} expanded The `expanded` state of the accordion.
   */
  onChange?: (ReactEvent.Form.t, bool) => unit,
  @as("TransitionComponent") transitionComponent?: React.component<transitionProps>,
  @as("TransitionProps") transitionProps?: transitionProps,
}

@module("@mui/material")
external make: props => React.element = "Accordion"
