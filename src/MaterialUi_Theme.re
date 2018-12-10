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
    muiAppBar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiAvatar"]
    muiAvatar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiBackdrop"]
    muiBackdrop: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiBadge"]
    muiBadge: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiBottomNavigation"]
    muiBottomNavigation: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiBottomNavigationAction"]
    muiBottomNavigationAction: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiButton"]
    muiButton: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiButtonBase"]
    muiButtonBase: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCard"]
    muiCard: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCardActionArea"]
    muiCardActionArea: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCardActions"]
    muiCardActions: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCardContent"]
    muiCardContent: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCardHeader"]
    muiCardHeader: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCardMedia"]
    muiCardMedia: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCheckbox"]
    muiCheckbox: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiChip"]
    muiChip: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCircularProgress"]
    muiCircularProgress: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCollapse"]
    muiCollapse: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiCssBaseline"]
    muiCssBaseline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiDialog"]
    muiDialog: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiDialogActions"]
    muiDialogActions: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiDialogContent"]
    muiDialogContent: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiDialogContentText"]
    muiDialogContentText: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiDialogTitle"]
    muiDialogTitle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiDivider"]
    muiDivider: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiDrawer"]
    muiDrawer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiExpansionPanel"]
    muiExpansionPanel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelActions"]
    muiExpansionPanelActions: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelDetails"]
    muiExpansionPanelDetails: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelSummary"]
    muiExpansionPanelSummary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiFab"]
    muiFab: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiFilledInput"]
    muiFilledInput: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiFormControl"]
    muiFormControl: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiFormControlLabel"]
    muiFormControlLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiFormGroup"]
    muiFormGroup: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiFormHelperText"]
    muiFormHelperText: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiFormLabel"]
    muiFormLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiGrid"]
    muiGrid: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiGridList"]
    muiGridList: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiGridListTile"]
    muiGridListTile: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiGridListTileBar"]
    muiGridListTileBar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiIcon"]
    muiIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiIconButton"]
    muiIconButton: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiInput"]
    muiInput: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiInputAdornment"]
    muiInputAdornment: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiInputBase"]
    muiInputBase: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiInputLabel"]
    muiInputLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiLinearProgress"]
    muiLinearProgress: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiList"]
    muiList: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiListItem"]
    muiListItem: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiListItemAvatar"]
    muiListItemAvatar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiListItemIcon"]
    muiListItemIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiListItemSecondaryAction"]
    muiListItemSecondaryAction: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiListItemText"]
    muiListItemText: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiListSubheader"]
    muiListSubheader: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiMenu"]
    muiMenu: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiMenuItem"]
    muiMenuItem: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiMobileStepper"]
    muiMobileStepper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiModal"]
    muiModal: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiNativeSelect"]
    muiNativeSelect: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiOutlinedInput"]
    muiOutlinedInput: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiPaper"]
    muiPaper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiPopover"]
    muiPopover: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiRadio"]
    muiRadio: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiSelect"]
    muiSelect: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiSnackbar"]
    muiSnackbar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiSnackbarContent"]
    muiSnackbarContent: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiStep"]
    muiStep: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiStepButton"]
    muiStepButton: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiStepConnector"]
    muiStepConnector: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiStepContent"]
    muiStepContent: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiStepIcon"]
    muiStepIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiStepLabel"]
    muiStepLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiStepper"]
    muiStepper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiSvgIcon"]
    muiSvgIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiSwitch"]
    muiSwitch: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiSwitchBase"]
    muiSwitchBase: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTab"]
    muiTab: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTable"]
    muiTable: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTableBody"]
    muiTableBody: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTableCell"]
    muiTableCell: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTableFooter"]
    muiTableFooter: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTableHead"]
    muiTableHead: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTablePagination"]
    muiTablePagination: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTableRow"]
    muiTableRow: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTableSortLabel"]
    muiTableSortLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTabs"]
    muiTabs: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiToolbar"]
    muiToolbar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTooltip"]
    muiTooltip: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTouchRipple"]
    muiTouchRipple: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "MuiTypography"]
    muiTypography: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TypeAction = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "active"]
    active: string,
    [@bs.as "disabled"]
    disabled: string,
    [@bs.as "disabledBackground"]
    disabledBackground: string,
    [@bs.as "hover"]
    hover: string,
    [@bs.as "hoverOpacity"]
    hoverOpacity: float,
    [@bs.as "selected"]
    selected: string,
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
    [@bs.as "primary"]
    primary: PaletteColor.t,
    [@bs.as "secondary"]
    secondary: PaletteColor.t,
    [@bs.as "text"]
    text: TypeText.t,
    [@bs.as "tonalOffset"]
    tonalOffset: float,
    [@bs.as "type"]
    type_: string,
  };

  let make = t;
};

module ComponentsProps = {
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
    [@bs.optional] [@bs.as "MuiButton"]
    muiButton: Js.Json.t,
    [@bs.optional] [@bs.as "MuiButtonBase"]
    muiButtonBase: Js.Json.t,
    [@bs.optional] [@bs.as "MuiCard"]
    muiCard: Js.Json.t,
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
    [@bs.optional] [@bs.as "MuiInputLabel"]
    muiInputLabel: Js.Json.t,
    [@bs.optional] [@bs.as "MuiLinearProgress"]
    muiLinearProgress: Js.Json.t,
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
    [@bs.optional] [@bs.as "MuiModal"]
    muiModal: Js.Json.t,
    [@bs.optional] [@bs.as "MuiNativeSelect"]
    muiNativeSelect: Js.Json.t,
    [@bs.optional] [@bs.as "MuiPaper"]
    muiPaper: Js.Json.t,
    [@bs.optional] [@bs.as "MuiPopover"]
    muiPopover: Js.Json.t,
    [@bs.optional] [@bs.as "MuiRadio"]
    muiRadio: Js.Json.t,
    [@bs.optional] [@bs.as "MuiSelect"]
    muiSelect: Js.Json.t,
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
    [@bs.optional] [@bs.as "MuiSwitchBase"]
    muiSwitchBase: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTab"]
    muiTab: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTable"]
    muiTable: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableCell"]
    muiTableCell: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTablePagination"]
    muiTablePagination: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableRow"]
    muiTableRow: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTableSortLabel"]
    muiTableSortLabel: Js.Json.t,
    [@bs.optional] [@bs.as "MuiTabs"]
    muiTabs: Js.Json.t,
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

module Shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "borderRadius"]
    borderRadius: float,
  };

  let make = t;
};

module Spacing = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "unit"]
    unit: float,
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

module Body1 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Body2 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Button = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Caption = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Display1 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Display2 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Display3 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Display4 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module H1 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module H2 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module H3 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module H4 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module H5 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module H6 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Headline = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Overline = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Subheading = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Subtitle1 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Subtitle2 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Title = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let fontSizeGet = value => {
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

    let v = fontSizeGet(value);
    isNumeric(v) ?
      `Float(Obj.magic(v)) :
      isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v));
  };

  [@bs.deriving jsConverter]
  type fontWeightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightGet = value =>
    fontWeightGet(value)->fontWeightConverterFromJs;

  let letterSpacingGet = value => {
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

    letterSpacingGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };
  let lineHeightGet = value => {
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

    lineHeightGet(value)
    ->Belt.Option.map(v =>
        isNumeric(v) ?
          `Float(Obj.magic(v)) :
          isBool(v) ? `Bool(Obj.magic(v)) : `String(Obj.magic(v))
      );
  };

  let make = t;
};

module Typography = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "body1"]
    body1: Body1.t,
    [@bs.as "body2"]
    body2: Body2.t,
    [@bs.as "button"]
    button: Button.t,
    [@bs.as "caption"]
    caption: Caption.t,
    [@bs.as "display1"]
    display1: Display1.t,
    [@bs.as "display2"]
    display2: Display2.t,
    [@bs.as "display3"]
    display3: Display3.t,
    [@bs.as "display4"]
    display4: Display4.t,
    [@bs.optional] [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: float,
    [@bs.optional] [@bs.as "fontWeightLight"]
    fontWeightLight: string,
    [@bs.optional] [@bs.as "fontWeightMedium"]
    fontWeightMedium: string,
    [@bs.optional] [@bs.as "fontWeightRegular"]
    fontWeightRegular: string,
    [@bs.as "h1"]
    h1: H1.t,
    [@bs.as "h2"]
    h2: H2.t,
    [@bs.as "h3"]
    h3: H3.t,
    [@bs.as "h4"]
    h4: H4.t,
    [@bs.as "h5"]
    h5: H5.t,
    [@bs.as "h6"]
    h6: H6.t,
    [@bs.as "headline"]
    headline: Headline.t,
    [@bs.as "overline"]
    overline: Overline.t,
    [@bs.as "pxToRem"]
    pxToRem: Js.Json.t,
    [@bs.as "subheading"]
    subheading: Subheading.t,
    [@bs.as "subtitle1"]
    subtitle1: Subtitle1.t,
    [@bs.as "subtitle2"]
    subtitle2: Subtitle2.t,
    [@bs.as "title"]
    title: Title.t,
  };

  [@bs.deriving jsConverter]
  type fontWeightLightConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightLightGet = value =>
    fontWeightLightGet(value)
    ->Belt.Option.map(v => fontWeightLightConverterFromJs(v));

  [@bs.deriving jsConverter]
  type fontWeightMediumConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightMediumGet = value =>
    fontWeightMediumGet(value)
    ->Belt.Option.map(v => fontWeightMediumConverterFromJs(v));

  [@bs.deriving jsConverter]
  type fontWeightRegularConverter = [
    | [@bs.as "-moz-initial"] `MozInitial
    | [@bs.as "100"] `V100
    | [@bs.as "200"] `V200
    | [@bs.as "300"] `V300
    | [@bs.as "400"] `V400
    | [@bs.as "500"] `V500
    | [@bs.as "600"] `V600
    | [@bs.as "700"] `V700
    | [@bs.as "800"] `V800
    | [@bs.as "900"] `V900
    | [@bs.as "bold"] `Bold
    | [@bs.as "bolder"] `Bolder
    | [@bs.as "inherit"] `Inherit
    | [@bs.as "initial"] `Initial
    | [@bs.as "lighter"] `Lighter
    | [@bs.as "normal"] `Normal
    | [@bs.as "revert"] `Revert
    | [@bs.as "unset"] `Unset
  ];
  let fontWeightRegularGet = value =>
    fontWeightRegularGet(value)
    ->Belt.Option.map(v => fontWeightRegularConverterFromJs(v));

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
    props: ComponentsProps.t,
    [@bs.as "shadows"]
    shadows: array(string),
    [@bs.as "shape"]
    shape: Shape.t,
    [@bs.as "spacing"]
    spacing: Spacing.t,
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
