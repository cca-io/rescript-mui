module BreakpointValues = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "lg"]
    lg: float,
    [@bs.as "md"]
    md: float,
    [@bs.as "sm"]
    sm: float,
    [@bs.as "xl"]
    xl: float,
    [@bs.as "xs"]
    xs: float,
  };

  let make = t;
};

module Breakpoints = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "between"]
    between: Js.Json.t,
    [@bs.as "down"]
    down: Js.Json.t,
    [@bs.as "keys"]
    keys: array(string),
    [@bs.as "only"]
    only: Js.Json.t,
    [@bs.as "up"]
    up: Js.Json.t,
    [@bs.as "values"]
    values: BreakpointValues.t,
    [@bs.as "width"]
    width: Js.Json.t,
  };

  let make = t;
};

module Mixins = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "gutters"]
    gutters: Js.Json.t,
    [@bs.as "toolbar"]
    toolbar: ReactDOMRe.Style.t,
  };

  let make = t;
};

module Overrides = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "MuiAppBar"]
    muiAppBar: Js.Json.t,
    [@bs.optional] [@bs.as "MuiAvatar"]
    muiAvatar: Js.Json.t,
    [@bs.optional] [@bs.as "MuiBackdrop"]
    muiBackdrop: Js.Json.t,
    [@bs.optional] [@bs.as "MuiBadge"]
    muiBadge: Js.Json.t,
    [@bs.optional] [@bs.as "MuiBottomNavigation"]
    muiBottomNavigation: Js.Json.t,
    [@bs.optional] [@bs.as "MuiBottomNavigationAction"]
    muiBottomNavigationAction: Js.Json.t,
    [@bs.optional] [@bs.as "MuiBreadcrumbs"]
    muiBreadcrumbs: Js.Json.t,
    [@bs.optional] [@bs.as "MuiButton"]
    muiButton: Js.Json.t,
    [@bs.optional] [@bs.as "MuiButtonBase"]
    muiButtonBase: Js.Json.t,
    [@bs.optional] [@bs.as "MuiButtonGroup"]
    muiButtonGroup: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCard"]
    muiCard: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCardActionArea"]
    muiCardActionArea: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCardActions"]
    muiCardActions: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCardContent"]
    muiCardContent: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCardHeader"]
    muiCardHeader: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCardMedia"]
    muiCardMedia: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCheckbox"]
    muiCheckbox: Js.Json.t,
    [@bs.optional] [@bs.as "MuiChip"]
    muiChip: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCircularProgress"]
    muiCircularProgress: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCollapse"]
    muiCollapse: Js.Json.t,
    [@bs.optional] [@bs.as "MuiContainer"]
    muiContainer: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCssBaseline"]
    muiCssBaseline: Js.Json.t,
    [@bs.optional] [@bs.as "MuiDialog"]
    muiDialog: Js.Json.t,
    [@bs.optional] [@bs.as "MuiDialogActions"]
    muiDialogActions: Js.Json.t,
    [@bs.optional] [@bs.as "MuiDialogContent"]
    muiDialogContent: Js.Json.t,
    [@bs.optional] [@bs.as "MuiDialogContentText"]
    muiDialogContentText: Js.Json.t,
    [@bs.optional] [@bs.as "MuiDialogTitle"]
    muiDialogTitle: Js.Json.t,
    [@bs.optional] [@bs.as "MuiDivider"]
    muiDivider: Js.Json.t,
    [@bs.optional] [@bs.as "MuiDrawer"]
    muiDrawer: Js.Json.t,
    [@bs.optional] [@bs.as "MuiExpansionPanel"]
    muiExpansionPanel: Js.Json.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelActions"]
    muiExpansionPanelActions: Js.Json.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelDetails"]
    muiExpansionPanelDetails: Js.Json.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelSummary"]
    muiExpansionPanelSummary: Js.Json.t,
    [@bs.optional] [@bs.as "MuiFab"]
    muiFab: Js.Json.t,
    [@bs.optional] [@bs.as "MuiFilledInput"]
    muiFilledInput: Js.Json.t,
    [@bs.optional] [@bs.as "MuiFormControl"]
    muiFormControl: Js.Json.t,
    [@bs.optional] [@bs.as "MuiFormControlLabel"]
    muiFormControlLabel: Js.Json.t,
    [@bs.optional] [@bs.as "MuiFormGroup"]
    muiFormGroup: Js.Json.t,
    [@bs.optional] [@bs.as "MuiFormHelperText"]
    muiFormHelperText: Js.Json.t,
    [@bs.optional] [@bs.as "MuiFormLabel"]
    muiFormLabel: Js.Json.t,
    [@bs.optional] [@bs.as "MuiGrid"]
    muiGrid: Js.Json.t,
    [@bs.optional] [@bs.as "MuiGridList"]
    muiGridList: Js.Json.t,
    [@bs.optional] [@bs.as "MuiGridListTile"]
    muiGridListTile: Js.Json.t,
    [@bs.optional] [@bs.as "MuiGridListTileBar"]
    muiGridListTileBar: Js.Json.t,
    [@bs.optional] [@bs.as "MuiIcon"]
    muiIcon: Js.Json.t,
    [@bs.optional] [@bs.as "MuiIconButton"]
    muiIconButton: Js.Json.t,
    [@bs.optional] [@bs.as "MuiInput"]
    muiInput: Js.Json.t,
    [@bs.optional] [@bs.as "MuiInputAdornment"]
    muiInputAdornment: Js.Json.t,
    [@bs.optional] [@bs.as "MuiInputBase"]
    muiInputBase: Js.Json.t,
    [@bs.optional] [@bs.as "MuiInputLabel"]
    muiInputLabel: Js.Json.t,
    [@bs.optional] [@bs.as "MuiLinearProgress"]
    muiLinearProgress: Js.Json.t,
    [@bs.optional] [@bs.as "MuiLink"]
    muiLink: Js.Json.t,
    [@bs.optional] [@bs.as "MuiList"]
    muiList: Js.Json.t,
    [@bs.optional] [@bs.as "MuiListItem"]
    muiListItem: Js.Json.t,
    [@bs.optional] [@bs.as "MuiListItemAvatar"]
    muiListItemAvatar: Js.Json.t,
    [@bs.optional] [@bs.as "MuiListItemIcon"]
    muiListItemIcon: Js.Json.t,
    [@bs.optional] [@bs.as "MuiListItemSecondaryAction"]
    muiListItemSecondaryAction: Js.Json.t,
    [@bs.optional] [@bs.as "MuiListItemText"]
    muiListItemText: Js.Json.t,
    [@bs.optional] [@bs.as "MuiListSubheader"]
    muiListSubheader: Js.Json.t,
    [@bs.optional] [@bs.as "MuiMenu"]
    muiMenu: Js.Json.t,
    [@bs.optional] [@bs.as "MuiMenuItem"]
    muiMenuItem: Js.Json.t,
    [@bs.optional] [@bs.as "MuiMobileStepper"]
    muiMobileStepper: Js.Json.t,
    [@bs.optional] [@bs.as "MuiNativeSelect"]
    muiNativeSelect: Js.Json.t,
    [@bs.optional] [@bs.as "MuiOutlinedInput"]
    muiOutlinedInput: Js.Json.t,
    [@bs.optional] [@bs.as "MuiPaper"]
    muiPaper: Js.Json.t,
    [@bs.optional] [@bs.as "MuiPopover"]
    muiPopover: Js.Json.t,
    [@bs.optional] [@bs.as "MuiRadio"]
    muiRadio: Js.Json.t,
    [@bs.optional] [@bs.as "MuiSelect"]
    muiSelect: Js.Json.t,
    [@bs.optional] [@bs.as "MuiSlider"]
    muiSlider: Js.Json.t,
    [@bs.optional] [@bs.as "MuiSnackbar"]
    muiSnackbar: Js.Json.t,
    [@bs.optional] [@bs.as "MuiSnackbarContent"]
    muiSnackbarContent: Js.Json.t,
    [@bs.optional] [@bs.as "MuiStep"]
    muiStep: Js.Json.t,
    [@bs.optional] [@bs.as "MuiStepButton"]
    muiStepButton: Js.Json.t,
    [@bs.optional] [@bs.as "MuiStepConnector"]
    muiStepConnector: Js.Json.t,
    [@bs.optional] [@bs.as "MuiStepContent"]
    muiStepContent: Js.Json.t,
    [@bs.optional] [@bs.as "MuiStepIcon"]
    muiStepIcon: Js.Json.t,
    [@bs.optional] [@bs.as "MuiStepLabel"]
    muiStepLabel: Js.Json.t,
    [@bs.optional] [@bs.as "MuiStepper"]
    muiStepper: Js.Json.t,
    [@bs.optional] [@bs.as "MuiSvgIcon"]
    muiSvgIcon: Js.Json.t,
    [@bs.optional] [@bs.as "MuiSwitch"]
    muiSwitch: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTab"]
    muiTab: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTable"]
    muiTable: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableBody"]
    muiTableBody: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableCell"]
    muiTableCell: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableContainer"]
    muiTableContainer: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableFooter"]
    muiTableFooter: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableHead"]
    muiTableHead: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTablePagination"]
    muiTablePagination: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableRow"]
    muiTableRow: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableSortLabel"]
    muiTableSortLabel: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTabs"]
    muiTabs: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTextField"]
    muiTextField: Js.Json.t,
    [@bs.optional] [@bs.as "MuiToolbar"]
    muiToolbar: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTooltip"]
    muiTooltip: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTouchRipple"]
    muiTouchRipple: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTypography"]
    muiTypography: Js.Json.t,
  };

  let make = t;
};

module TypeAction = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "activatedOpacity"]
    activatedOpacity: float,
    [@bs.as "active"]
    active: string,
    [@bs.as "disabled"]
    disabled: string,
    [@bs.as "disabledBackground"]
    disabledBackground: string,
    [@bs.as "disabledOpacity"]
    disabledOpacity: float,
    [@bs.as "focus"]
    focus: string,
    [@bs.as "focusOpacity"]
    focusOpacity: float,
    [@bs.as "hover"]
    hover: string,
    [@bs.as "hoverOpacity"]
    hoverOpacity: float,
    [@bs.as "selected"]
    selected: string,
    [@bs.as "selectedOpacity"]
    selectedOpacity: float,
  };

  let make = t;
};

module TypeBackground = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "default"]
    default: string,
    [@bs.as "paper"]
    paper: string,
  };

  let make = t;
};

module CommonColors = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "black"]
    black: string,
    [@bs.as "white"]
    white: string,
  };

  let make = t;
};

module PaletteColor = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "contrastText"]
    contrastText: string,
    [@bs.as "dark"]
    dark: string,
    [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
  };

  let make = t;
};

module Color = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "50"]
    _50: string,
    [@bs.as "100"]
    _100: string,
    [@bs.as "200"]
    _200: string,
    [@bs.as "300"]
    _300: string,
    [@bs.as "400"]
    _400: string,
    [@bs.as "500"]
    _500: string,
    [@bs.as "600"]
    _600: string,
    [@bs.as "700"]
    _700: string,
    [@bs.as "800"]
    _800: string,
    [@bs.as "900"]
    _900: string,
    [@bs.as "A100"]
    a100: string,
    [@bs.as "A200"]
    a200: string,
    [@bs.as "A400"]
    a400: string,
    [@bs.as "A700"]
    a700: string,
  };

  let make = t;
};

module TypeText = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "disabled"]
    disabled: string,
    [@bs.as "hint"]
    hint: string,
    [@bs.as "primary"]
    primary: string,
    [@bs.as "secondary"]
    secondary: string,
  };

  let make = t;
};

module Palette = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "action"]
    action: TypeAction.t,
    [@bs.as "augmentColor"]
    augmentColor: Js.Json.t,
    [@bs.as "background"]
    background: TypeBackground.t,
    [@bs.as "common"]
    common: CommonColors.t,
    [@bs.as "contrastThreshold"]
    contrastThreshold: float,
    [@bs.as "divider"]
    divider: string,
    [@bs.as "error"]
    error: PaletteColor.t,
    [@bs.as "getContrastText"]
    getContrastText: Js.Json.t,
    [@bs.as "grey"]
    grey: Color.t,
    [@bs.as "info"]
    info: PaletteColor.t,
    [@bs.as "primary"]
    primary: PaletteColor.t,
    [@bs.as "secondary"]
    secondary: PaletteColor.t,
    [@bs.as "success"]
    success: PaletteColor.t,
    [@bs.as "text"]
    text: TypeText.t,
    [@bs.as "tonalOffset"]
    tonalOffset: float,
    [@bs.as "type"]
    type_: string,
    [@bs.as "warning"]
    warning: PaletteColor.t,
  };

  let make = t;
};

module Shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "borderRadius"]
    borderRadius: float,
  };

  let make = t;
};

module Duration = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "complex"]
    complex: float,
    [@bs.as "enteringScreen"]
    enteringScreen: float,
    [@bs.as "leavingScreen"]
    leavingScreen: float,
    [@bs.as "short"]
    short: float,
    [@bs.as "shorter"]
    shorter: float,
    [@bs.as "shortest"]
    shortest: float,
    [@bs.as "standard"]
    standard: float,
  };

  let make = t;
};

module Easing = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "easeIn"]
    easeIn: string,
    [@bs.as "easeInOut"]
    easeInOut: string,
    [@bs.as "easeOut"]
    easeOut: string,
    [@bs.as "sharp"]
    sharp: string,
  };

  let make = t;
};

module Transitions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "duration"]
    duration: Duration.t,
    [@bs.as "easing"]
    easing: Easing.t,
  };

  let make = t;
};

module Typography = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "body1"]
    body1: ReactDOMRe.Style.t,
    [@bs.as "body2"]
    body2: ReactDOMRe.Style.t,
    [@bs.as "button"]
    button: ReactDOMRe.Style.t,
    [@bs.as "caption"]
    caption: ReactDOMRe.Style.t,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeightBold"]
    fontWeightBold: string,
    [@bs.as "fontWeightLight"]
    fontWeightLight: string,
    [@bs.as "fontWeightMedium"]
    fontWeightMedium: string,
    [@bs.as "fontWeightRegular"]
    fontWeightRegular: string,
    [@bs.as "h1"]
    h1: ReactDOMRe.Style.t,
    [@bs.as "h2"]
    h2: ReactDOMRe.Style.t,
    [@bs.as "h3"]
    h3: ReactDOMRe.Style.t,
    [@bs.as "h4"]
    h4: ReactDOMRe.Style.t,
    [@bs.as "h5"]
    h5: ReactDOMRe.Style.t,
    [@bs.as "h6"]
    h6: ReactDOMRe.Style.t,
    [@bs.as "overline"]
    overline: ReactDOMRe.Style.t,
    [@bs.as "pxToRem"]
    pxToRem: Js.Json.t,
    [@bs.as "subtitle1"]
    subtitle1: ReactDOMRe.Style.t,
    [@bs.as "subtitle2"]
    subtitle2: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ZIndex = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "appBar"]
    appBar: float,
    [@bs.as "drawer"]
    drawer: float,
    [@bs.as "mobileStepper"]
    mobileStepper: float,
    [@bs.as "modal"]
    modal: float,
    [@bs.as "snackbar"]
    snackbar: float,
    [@bs.as "speedDial"]
    speedDial: float,
    [@bs.as "tooltip"]
    tooltip: float,
  };

  let make = t;
};

module Theme = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "breakpoints"]
    breakpoints: Breakpoints.t,
    [@bs.as "direction"]
    direction: string,
    [@bs.as "mixins"]
    mixins: Mixins.t,
    [@bs.optional] [@bs.as "overrides"]
    overrides: Overrides.t,
    [@bs.as "palette"]
    palette: Palette.t,
    [@bs.optional] [@bs.as "props"]
    props: Js.Json.t,
    [@bs.as "shadows"]
    shadows: array(string),
    [@bs.as "shape"]
    shape: Shape.t,
    [@bs.as "spacing"]
    spacing: int => int,
    [@bs.as "transitions"]
    transitions: Transitions.t,
    [@bs.as "typography"]
    typography: Typography.t,
    [@bs.as "zIndex"]
    zIndex: ZIndex.t,
  };

  let make = t;
};
type t = Theme.t;
let make = Theme.make;

[@bs.module "@material-ui/core/styles"]
external create: MaterialUi_ThemeOptions.t => t = "createMuiTheme";
