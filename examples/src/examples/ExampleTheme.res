// Define theme options with many properties populated
let themeOptions: Mui.ThemeOptions.t = {
  breakpoints: {
    keys: ["xs", "sm", "md", "lg", "xl"],
    values: {lg: 1200., md: 960., sm: 600., xl: 1920., xs: 0.},
    unit: "px",
  },
  direction: "ltr",
  mixins: {
    gutters: "16px",
    toolbar: {minHeight: "56px"},
  },
  components: {
    muiButton: {
      defaultProps: {variant: Contained},
      styleOverrides: {
        root: {
          borderRadius: "0",
          padding: "16px",
        },
      },
    },
  },
  palette: {
    mode: "light",
    action: {
      activatedOpacity: 0.12,
      active: "#000",
      disabled: "#ccc",
      disabledBackground: "#f5f5f5",
      disabledOpacity: 0.38,
      focus: "#ddd",
      focusOpacity: 0.12,
      hover: "#eee",
      hoverOpacity: 0.08,
      selected: "#bbb",
      selectedOpacity: 0.16,
    },
    background: {default: "#fafafa", paper: "#fff"},
    common: {black: "#000", white: "#fff"},
    contrastThreshold: 3.,
    divider: "rgba(0, 0, 0, 0.12)",
    error: {
      main: "#f44336",
      contrastText: "#fff",
      light: "#e57373",
      dark: "#d32f2f",
      \"50": "#ffebee",
      \"100": "#ffcdd2",
      \"200": "#ef9a9a",
      \"300": "#e57373",
      \"400": "#ef5350",
      \"500": "#f44336",
      \"600": "#e53935",
      \"700": "#d32f2f",
      \"800": "#c62828",
      \"900": "#b71c1c",
      \"A100": "#ff8a80",
      \"A200": "#ff5252",
      \"A400": "#ff1744",
      \"A700": "#d50000",
    },
    grey: {
      \"50": "#fafafa",
      \"100": "#f5f5f5",
      \"200": "#eeeeee",
      \"300": "#e0e0e0",
      \"400": "#bdbdbd",
      \"500": "#9e9e9e",
      \"600": "#757575",
      \"700": "#616161",
      \"800": "#424242",
      \"900": "#212121",
      \"A100": "#d5d5d5",
      \"A200": "#aaaaaa",
      \"A400": "#303030",
      \"A700": "#616161",
    },
    info: {
      main: "#2196f3",
      contrastText: "#fff",
      light: "#64b5f6",
      dark: "#1976d2",
    },
    primary: {
      main: "#1976d2",
      contrastText: "#fff",
      light: "#63a4ff",
      dark: "#004ba0",
    },
    secondary: {
      main: "#dc004e",
      contrastText: "#fff",
      light: "#ff5c8d",
      dark: "#9a0036",
    },
    success: {
      main: "#4caf50",
      contrastText: "#fff",
      light: "#81c784",
      dark: "#388e3c",
    },
    text: {
      primary: "rgba(0, 0, 0, 0.87)",
      secondary: "rgba(0, 0, 0, 0.54)",
      disabled: "rgba(0, 0, 0, 0.38)",
      hint: "rgba(0, 0, 0, 0.38)",
    },
    tonalOffset: {dark: 0.2, light: 0.2},
    warning: {
      main: "#ff9800",
      contrastText: "#fff",
      light: "#ffb74d",
      dark: "#f57c00",
    },
  },
  shadows: [
    "none",
    "0px 1px 3px rgba(0,0,0,0.2)",
    "0px 1px 5px rgba(0,0,0,0.2)",
    // ...additional shadow values as needed
  ],
  shape: {borderRadius: 4.},
  spacing: n => n * 8,
  transitions: {
    easing: {
      easeIn: "ease-in",
      easeInOut: "ease-in-out",
      easeOut: "ease-out",
      sharp: "cubic-bezier(0.4, 0, 0.6, 1)",
    },
    duration: {
      complex: 0.2,
      enteringScreen: 0.3,
      leavingScreen: 0.2,
      short: 150.,
      shorter: 100.,
      shortest: 50.,
      standard: 250.,
    },
  },
  typography: {
    fontFamily: "Roboto, sans-serif",
    fontSize: 14,
    fontWeightLight: "300",
    fontWeightRegular: "400",
    fontWeightMedium: "500",
    fontWeightBold: "700",
    htmlFontSize: 16,
    h1: {fontSize: "2rem"},
    h2: {fontSize: "1.75rem"},
    h3: {fontSize: "1.5rem"},
    h4: {fontSize: "1.25rem"},
    h5: {fontSize: "1rem"},
    h6: {fontSize: "0.875rem"},
    subtitle1: {fontSize: "1rem"},
    subtitle2: {fontSize: "0.875rem"},
    body1: {fontSize: "1rem"},
    body2: {fontSize: "0.875rem"},
    button: {fontSize: "0.875rem", textTransform: "uppercase"},
    caption: {fontSize: "0.75rem"},
    overline: {fontSize: "0.75rem", textTransform: "uppercase"},
  },
  unstable_strictMode: true,
  zIndex: {
    appBar: 1100,
    drawer: 1200,
    mobileStepper: 1000,
    modal: 1300,
    snackbar: 1400,
    speedDial: 1500,
    tooltip: 1600,
  },
}

let theme = Mui.Theme.create(themeOptions)

// Log various properties of the theme - Basic properties
Console.log("============ Theme Basic Properties ============")
Console.log("Theme direction: " ++ theme.direction)
Console.log2("Palette mode:", theme.palette.mode)
Console.log2("Breakpoints keys:", theme.breakpoints.keys)
Console.log2("Typography fontFamily:", theme.typography.fontFamily)

// Log color palette
Console.log("\n============ Theme Colors ============")
Console.log2("Primary main:", theme.palette.primary.main)
Console.log2("Primary light:", theme.palette.primary.light)
Console.log2("Primary dark:", theme.palette.primary.dark)
Console.log2("Secondary main:", theme.palette.secondary.main)
Console.log2("Error main:", theme.palette.error.main)
Console.log2("Warning main:", theme.palette.warning.main)
Console.log2("Info main:", theme.palette.info.main)
Console.log2("Success main:", theme.palette.success.main)
Console.log2("Background default:", theme.palette.background.default)
Console.log2("Background paper:", theme.palette.background.paper)
Console.log2("Common white:", theme.palette.common.white)
Console.log2("Common black:", theme.palette.common.black)
Console.log2("Text primary:", theme.palette.text.primary)
Console.log2("Text secondary:", theme.palette.text.secondary)
Console.log2("Text disabled:", theme.palette.text.disabled)
Console.log2("Divider:", theme.palette.divider)

// Log typography
Console.log("\n============ Typography ============")
Console.log2("Font family:", theme.typography.fontFamily)
Console.log2("Font size:", theme.typography.fontSize)
Console.log2("Font weight light:", theme.typography.fontWeightLight)
Console.log2("Font weight regular:", theme.typography.fontWeightRegular)
Console.log2("Font weight medium:", theme.typography.fontWeightMedium)
Console.log2("Font weight bold:", theme.typography.fontWeightBold)
Console.log2("HTML font size:", theme.typography.htmlFontSize)
Console.log2("h1:", theme.typography.h1)
Console.log2("h2:", theme.typography.h2)
Console.log2("body1:", theme.typography.body1)
Console.log2("button:", theme.typography.button)

// Log spacing
Console.log("\n============ Spacing ============")
Console.log2("spacing(1):", theme.spacing(1))
Console.log2("spacing(2):", theme.spacing(2))
Console.log2("spacing(3):", theme.spacing(3))
Console.log2("spacing(4):", theme.spacing(4))

// Log breakpoints
Console.log("\n============ Breakpoints ============")
Console.log2("xs value:", theme.breakpoints.values.xs)
Console.log2("sm value:", theme.breakpoints.values.sm)
Console.log2("md value:", theme.breakpoints.values.md)
Console.log2("lg value:", theme.breakpoints.values.lg)
Console.log2("xl value:", theme.breakpoints.values.xl)
Console.log2("unit:", theme.breakpoints.unit)

// Log shape
Console.log("\n============ Shape ============")
Console.log2("Border radius:", theme.shape.borderRadius)

// Log transitions
Console.log("\n============ Transitions ============")
Console.log2("Easing ease-in:", theme.transitions.easing.easeIn)
Console.log2("Easing ease-out:", theme.transitions.easing.easeOut)
Console.log2("Duration shortest:", theme.transitions.duration.shortest)
Console.log2("Duration standard:", theme.transitions.duration.standard)

// Log zIndex
Console.log("\n============ Z-Index ============")
Console.log2("App bar:", theme.zIndex.appBar)
Console.log2("Drawer:", theme.zIndex.drawer)
Console.log2("Modal:", theme.zIndex.modal)
Console.log2("Snackbar:", theme.zIndex.snackbar)
Console.log2("Tooltip:", theme.zIndex.tooltip)

// Log shadows (first few for brevity)
Console.log("\n============ Shadows ============")
Console.log2("Shadow 0:", theme.shadows[0])
Console.log2("Shadow 1:", theme.shadows[1])
Console.log2("Shadow 2:", theme.shadows[2])
