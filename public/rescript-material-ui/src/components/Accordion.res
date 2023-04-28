type transitionProps

type props = {
  ...Paper.props,
  defaultExpanded?: bool,
  disabled?: bool,
  disableGutters?: bool,
  expanded?: bool,
  onChange?: (ReactEvent.Form.t, bool) => unit,
  @as("TransitionComponent") transitionComponent?: React.component<transitionProps>,
  @as("TransitionProps") transitionProps?: transitionProps,
}

@module("@mui/material")
external make: props => React.element = "Accordion"
