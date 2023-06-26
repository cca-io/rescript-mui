type props = {
  ...CommonProps.t_NoRef,
  styles: System.props,
}

@module("@mui/material/GlobalStyles")
external make: React.component<props> = "default"
