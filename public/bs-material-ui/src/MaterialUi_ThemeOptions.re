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
    [@bs.optional] [@bs.as "between"]
    between: Js.Json.t,
    [@bs.optional] [@bs.as "down"]
    down: Js.Json.t,
    [@bs.optional] [@bs.as "keys"]
    keys: array(string),
    [@bs.optional] [@bs.as "only"]
    only: Js.Json.t,
    [@bs.optional] [@bs.as "step"]
    step: float,
    [@bs.optional] [@bs.as "unit"]
    unit: string,
    [@bs.optional] [@bs.as "up"]
    up: Js.Json.t,
    [@bs.optional] [@bs.as "values"]
    values: BreakpointValues.t,
    [@bs.optional] [@bs.as "width"]
    width: Js.Json.t,
  };

  let make = t;
};

module MixinsOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "gutters"]
    gutters: Js.Json.t,
    [@bs.optional] [@bs.as "toolbar"]
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
    [@bs.optional] [@bs.as "activatedOpacity"]
    activatedOpacity: float,
    [@bs.optional] [@bs.as "active"]
    active: string,
    [@bs.optional] [@bs.as "disabled"]
    disabled: string,
    [@bs.optional] [@bs.as "disabledBackground"]
    disabledBackground: string,
    [@bs.optional] [@bs.as "disabledOpacity"]
    disabledOpacity: float,
    [@bs.optional] [@bs.as "focus"]
    focus: string,
    [@bs.optional] [@bs.as "focusOpacity"]
    focusOpacity: float,
    [@bs.optional] [@bs.as "hover"]
    hover: string,
    [@bs.optional] [@bs.as "hoverOpacity"]
    hoverOpacity: float,
    [@bs.optional] [@bs.as "selected"]
    selected: string,
    [@bs.optional] [@bs.as "selectedOpacity"]
    selectedOpacity: float,
  };

  let make = t;
};

module TypeBackground = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "default"]
    default: string,
    [@bs.optional] [@bs.as "paper"]
    paper: string,
  };

  let make = t;
};

module CommonColors = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "black"]
    black: string,
    [@bs.optional] [@bs.as "white"]
    white: string,
  };

  let make = t;
};

module Error = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "50"]
    _50: string,
    [@bs.optional] [@bs.as "100"]
    _100: string,
    [@bs.optional] [@bs.as "200"]
    _200: string,
    [@bs.optional] [@bs.as "300"]
    _300: string,
    [@bs.optional] [@bs.as "400"]
    _400: string,
    [@bs.optional] [@bs.as "500"]
    _500: string,
    [@bs.optional] [@bs.as "600"]
    _600: string,
    [@bs.optional] [@bs.as "700"]
    _700: string,
    [@bs.optional] [@bs.as "800"]
    _800: string,
    [@bs.optional] [@bs.as "900"]
    _900: string,
    [@bs.optional] [@bs.as "A100"]
    a100: string,
    [@bs.optional] [@bs.as "A200"]
    a200: string,
    [@bs.optional] [@bs.as "A400"]
    a400: string,
    [@bs.optional] [@bs.as "A700"]
    a700: string,
    [@bs.optional] [@bs.as "contrastText"]
    contrastText: string,
    [@bs.optional] [@bs.as "dark"]
    dark: string,
    [@bs.optional] [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
  };

  let make = t;
};

module Color = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "50"]
    _50: string,
    [@bs.optional] [@bs.as "100"]
    _100: string,
    [@bs.optional] [@bs.as "200"]
    _200: string,
    [@bs.optional] [@bs.as "300"]
    _300: string,
    [@bs.optional] [@bs.as "400"]
    _400: string,
    [@bs.optional] [@bs.as "500"]
    _500: string,
    [@bs.optional] [@bs.as "600"]
    _600: string,
    [@bs.optional] [@bs.as "700"]
    _700: string,
    [@bs.optional] [@bs.as "800"]
    _800: string,
    [@bs.optional] [@bs.as "900"]
    _900: string,
    [@bs.optional] [@bs.as "A100"]
    a100: string,
    [@bs.optional] [@bs.as "A200"]
    a200: string,
    [@bs.optional] [@bs.as "A400"]
    a400: string,
    [@bs.optional] [@bs.as "A700"]
    a700: string,
  };

  let make = t;
};

module Info = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "50"]
    _50: string,
    [@bs.optional] [@bs.as "100"]
    _100: string,
    [@bs.optional] [@bs.as "200"]
    _200: string,
    [@bs.optional] [@bs.as "300"]
    _300: string,
    [@bs.optional] [@bs.as "400"]
    _400: string,
    [@bs.optional] [@bs.as "500"]
    _500: string,
    [@bs.optional] [@bs.as "600"]
    _600: string,
    [@bs.optional] [@bs.as "700"]
    _700: string,
    [@bs.optional] [@bs.as "800"]
    _800: string,
    [@bs.optional] [@bs.as "900"]
    _900: string,
    [@bs.optional] [@bs.as "A100"]
    a100: string,
    [@bs.optional] [@bs.as "A200"]
    a200: string,
    [@bs.optional] [@bs.as "A400"]
    a400: string,
    [@bs.optional] [@bs.as "A700"]
    a700: string,
    [@bs.optional] [@bs.as "contrastText"]
    contrastText: string,
    [@bs.optional] [@bs.as "dark"]
    dark: string,
    [@bs.optional] [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
  };

  let make = t;
};

module Primary = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "50"]
    _50: string,
    [@bs.optional] [@bs.as "100"]
    _100: string,
    [@bs.optional] [@bs.as "200"]
    _200: string,
    [@bs.optional] [@bs.as "300"]
    _300: string,
    [@bs.optional] [@bs.as "400"]
    _400: string,
    [@bs.optional] [@bs.as "500"]
    _500: string,
    [@bs.optional] [@bs.as "600"]
    _600: string,
    [@bs.optional] [@bs.as "700"]
    _700: string,
    [@bs.optional] [@bs.as "800"]
    _800: string,
    [@bs.optional] [@bs.as "900"]
    _900: string,
    [@bs.optional] [@bs.as "A100"]
    a100: string,
    [@bs.optional] [@bs.as "A200"]
    a200: string,
    [@bs.optional] [@bs.as "A400"]
    a400: string,
    [@bs.optional] [@bs.as "A700"]
    a700: string,
    [@bs.optional] [@bs.as "contrastText"]
    contrastText: string,
    [@bs.optional] [@bs.as "dark"]
    dark: string,
    [@bs.optional] [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
  };

  let make = t;
};

module Secondary = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "50"]
    _50: string,
    [@bs.optional] [@bs.as "100"]
    _100: string,
    [@bs.optional] [@bs.as "200"]
    _200: string,
    [@bs.optional] [@bs.as "300"]
    _300: string,
    [@bs.optional] [@bs.as "400"]
    _400: string,
    [@bs.optional] [@bs.as "500"]
    _500: string,
    [@bs.optional] [@bs.as "600"]
    _600: string,
    [@bs.optional] [@bs.as "700"]
    _700: string,
    [@bs.optional] [@bs.as "800"]
    _800: string,
    [@bs.optional] [@bs.as "900"]
    _900: string,
    [@bs.optional] [@bs.as "A100"]
    a100: string,
    [@bs.optional] [@bs.as "A200"]
    a200: string,
    [@bs.optional] [@bs.as "A400"]
    a400: string,
    [@bs.optional] [@bs.as "A700"]
    a700: string,
    [@bs.optional] [@bs.as "contrastText"]
    contrastText: string,
    [@bs.optional] [@bs.as "dark"]
    dark: string,
    [@bs.optional] [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
  };

  let make = t;
};

module Success = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "50"]
    _50: string,
    [@bs.optional] [@bs.as "100"]
    _100: string,
    [@bs.optional] [@bs.as "200"]
    _200: string,
    [@bs.optional] [@bs.as "300"]
    _300: string,
    [@bs.optional] [@bs.as "400"]
    _400: string,
    [@bs.optional] [@bs.as "500"]
    _500: string,
    [@bs.optional] [@bs.as "600"]
    _600: string,
    [@bs.optional] [@bs.as "700"]
    _700: string,
    [@bs.optional] [@bs.as "800"]
    _800: string,
    [@bs.optional] [@bs.as "900"]
    _900: string,
    [@bs.optional] [@bs.as "A100"]
    a100: string,
    [@bs.optional] [@bs.as "A200"]
    a200: string,
    [@bs.optional] [@bs.as "A400"]
    a400: string,
    [@bs.optional] [@bs.as "A700"]
    a700: string,
    [@bs.optional] [@bs.as "contrastText"]
    contrastText: string,
    [@bs.optional] [@bs.as "dark"]
    dark: string,
    [@bs.optional] [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
  };

  let make = t;
};

module TypeText = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "disabled"]
    disabled: string,
    [@bs.optional] [@bs.as "hint"]
    hint: string,
    [@bs.optional] [@bs.as "primary"]
    primary: string,
    [@bs.optional] [@bs.as "secondary"]
    secondary: string,
  };

  let make = t;
};

module Warning = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "50"]
    _50: string,
    [@bs.optional] [@bs.as "100"]
    _100: string,
    [@bs.optional] [@bs.as "200"]
    _200: string,
    [@bs.optional] [@bs.as "300"]
    _300: string,
    [@bs.optional] [@bs.as "400"]
    _400: string,
    [@bs.optional] [@bs.as "500"]
    _500: string,
    [@bs.optional] [@bs.as "600"]
    _600: string,
    [@bs.optional] [@bs.as "700"]
    _700: string,
    [@bs.optional] [@bs.as "800"]
    _800: string,
    [@bs.optional] [@bs.as "900"]
    _900: string,
    [@bs.optional] [@bs.as "A100"]
    a100: string,
    [@bs.optional] [@bs.as "A200"]
    a200: string,
    [@bs.optional] [@bs.as "A400"]
    a400: string,
    [@bs.optional] [@bs.as "A700"]
    a700: string,
    [@bs.optional] [@bs.as "contrastText"]
    contrastText: string,
    [@bs.optional] [@bs.as "dark"]
    dark: string,
    [@bs.optional] [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
  };

  let make = t;
};

module PaletteOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "action"]
    action: TypeAction.t,
    [@bs.optional] [@bs.as "background"]
    background: TypeBackground.t,
    [@bs.optional] [@bs.as "common"]
    common: CommonColors.t,
    [@bs.optional] [@bs.as "contrastThreshold"]
    contrastThreshold: float,
    [@bs.optional] [@bs.as "divider"]
    divider: string,
    [@bs.optional] [@bs.as "error"]
    error: Error.t,
    [@bs.optional] [@bs.as "getContrastText"]
    getContrastText: Js.Json.t,
    [@bs.optional] [@bs.as "grey"]
    grey: Color.t,
    [@bs.optional] [@bs.as "info"]
    info: Info.t,
    [@bs.optional] [@bs.as "primary"]
    primary: Primary.t,
    [@bs.optional] [@bs.as "secondary"]
    secondary: Secondary.t,
    [@bs.optional] [@bs.as "success"]
    success: Success.t,
    [@bs.optional] [@bs.as "text"]
    text: TypeText.t,
    [@bs.optional] [@bs.as "tonalOffset"]
    tonalOffset: float,
    [@bs.optional] [@bs.as "type"]
    type_: string,
    [@bs.optional] [@bs.as "warning"]
    warning: Warning.t,
  };

  let make = t;
};

module Shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "borderRadius"]
    borderRadius: float,
  };

  let make = t;
};

module Duration = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "complex"]
    complex: float,
    [@bs.optional] [@bs.as "enteringScreen"]
    enteringScreen: float,
    [@bs.optional] [@bs.as "leavingScreen"]
    leavingScreen: float,
    [@bs.optional] [@bs.as "short"]
    short: float,
    [@bs.optional] [@bs.as "shorter"]
    shorter: float,
    [@bs.optional] [@bs.as "shortest"]
    shortest: float,
    [@bs.optional] [@bs.as "standard"]
    standard: float,
  };

  let make = t;
};

module Easing = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "easeIn"]
    easeIn: string,
    [@bs.optional] [@bs.as "easeInOut"]
    easeInOut: string,
    [@bs.optional] [@bs.as "easeOut"]
    easeOut: string,
    [@bs.optional] [@bs.as "sharp"]
    sharp: string,
  };

  let make = t;
};

module TransitionsOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "create"]
    create: Js.Json.t,
    [@bs.optional] [@bs.as "duration"]
    duration: Duration.t,
    [@bs.optional] [@bs.as "easing"]
    easing: Easing.t,
    [@bs.optional] [@bs.as "getAutoHeightDuration"]
    getAutoHeightDuration: Js.Json.t,
  };

  let make = t;
};

module Typography = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "body1"]
    body1: Js.Json.t,
    [@bs.optional] [@bs.as "body2"]
    body2: Js.Json.t,
    [@bs.optional] [@bs.as "button"]
    button: Js.Json.t,
    [@bs.optional] [@bs.as "caption"]
    caption: Js.Json.t,
    [@bs.optional] [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.optional] [@bs.as "fontSize"]
    fontSize: string,
    [@bs.optional] [@bs.as "fontWeightBold"]
    fontWeightBold: string,
    [@bs.optional] [@bs.as "fontWeightLight"]
    fontWeightLight: string,
    [@bs.optional] [@bs.as "fontWeightMedium"]
    fontWeightMedium: string,
    [@bs.optional] [@bs.as "fontWeightRegular"]
    fontWeightRegular: string,
    [@bs.optional] [@bs.as "h1"]
    h1: Js.Json.t,
    [@bs.optional] [@bs.as "h2"]
    h2: Js.Json.t,
    [@bs.optional] [@bs.as "h3"]
    h3: Js.Json.t,
    [@bs.optional] [@bs.as "h4"]
    h4: Js.Json.t,
    [@bs.optional] [@bs.as "h5"]
    h5: Js.Json.t,
    [@bs.optional] [@bs.as "h6"]
    h6: Js.Json.t,
    [@bs.optional] [@bs.as "htmlFontSize"]
    htmlFontSize: float,
    [@bs.optional] [@bs.as "overline"]
    overline: Js.Json.t,
    [@bs.optional] [@bs.as "subtitle1"]
    subtitle1: Js.Json.t,
    [@bs.optional] [@bs.as "subtitle2"]
    subtitle2: Js.Json.t,
  };

  let make = t;
};

module ZIndex = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "appBar"]
    appBar: float,
    [@bs.optional] [@bs.as "drawer"]
    drawer: float,
    [@bs.optional] [@bs.as "mobileStepper"]
    mobileStepper: float,
    [@bs.optional] [@bs.as "modal"]
    modal: float,
    [@bs.optional] [@bs.as "snackbar"]
    snackbar: float,
    [@bs.optional] [@bs.as "speedDial"]
    speedDial: float,
    [@bs.optional] [@bs.as "tooltip"]
    tooltip: float,
  };

  let make = t;
};

module ThemeOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "breakpoints"]
    breakpoints: Breakpoints.t,
    [@bs.optional] [@bs.as "direction"]
    direction: string,
    [@bs.optional] [@bs.as "mixins"]
    mixins: MixinsOptions.t,
    [@bs.optional] [@bs.as "overrides"]
    overrides: Overrides.t,
    [@bs.optional] [@bs.as "palette"]
    palette: PaletteOptions.t,
    [@bs.optional] [@bs.as "props"]
    props: Js.Json.t,
    [@bs.optional] [@bs.as "shadows"]
    shadows: array(string),
    [@bs.optional] [@bs.as "shape"]
    shape: Shape.t,
    [@bs.optional] [@bs.as "spacing"]
    spacing: string,
    [@bs.optional] [@bs.as "transitions"]
    transitions: TransitionsOptions.t,
    [@bs.optional] [@bs.as "typography"]
    typography: Typography.t,
    [@bs.optional] [@bs.as "zIndex"]
    zIndex: ZIndex.t,
  };

  let spacingGet = value => {
    let isNumeric: 'a => bool = [%raw
      {|
                function(obj) {
                    var realStringObj = obj && obj.toString();
                    return typeof obj !== 'object' && (realStringObj - parseFloat(realStringObj) + 1) >= 0;
                }
            |}
    ];
    let isBool: 'a => bool = [%raw
      {|
                function(obj) {
                    return typeof obj === 'boolean';
                }
            |}
    ];

    spacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v)
          ? `Float(Obj.magic(v))
          : isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};
type t = ThemeOptions.t;
let make = ThemeOptions.make;
