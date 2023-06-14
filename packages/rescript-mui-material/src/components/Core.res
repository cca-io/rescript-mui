@module("@mui/styles")
external useTheme: unit => Theme.t = "useTheme"

@module("@mui/material")
external useMediaQueryString: string => bool = "useMediaQuery"

@module("@mui/material")
external useMediaQuery: System.Breakpoint.t => bool = "useMediaQuery"
