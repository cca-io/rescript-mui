type props = {
  injectFirst?: bool,
  children: React.element,
}

@module("@mui/material/styles")
external make: React.component<props> = "StyledEngineProvider"
