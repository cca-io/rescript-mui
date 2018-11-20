type fixType;
type fixUnionType;

module ComponentsProps = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "MuiAppBar"]
    muiAppBar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiAvatar"]
    muiAvatar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiBackdrop"]
    muiBackdrop: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiBadge"]
    muiBadge: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiBottomNavigation"]
    muiBottomNavigation: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiBottomNavigationAction"]
    muiBottomNavigationAction: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiButton"]
    muiButton: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiButtonBase"]
    muiButtonBase: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCard"]
    muiCard: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardActions"]
    muiCardActions: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardContent"]
    muiCardContent: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardHeader"]
    muiCardHeader: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardMedia"]
    muiCardMedia: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCheckbox"]
    muiCheckbox: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiChip"]
    muiChip: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCircularProgress"]
    muiCircularProgress: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCollapse"]
    muiCollapse: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCssBaseline"]
    muiCssBaseline: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialog"]
    muiDialog: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialogActions"]
    muiDialogActions: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialogContent"]
    muiDialogContent: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialogContentText"]
    muiDialogContentText: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialogTitle"]
    muiDialogTitle: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDivider"]
    muiDivider: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDrawer"]
    muiDrawer: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiExpansionPanel"]
    muiExpansionPanel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiExpansionPanelActions"]
    muiExpansionPanelActions: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiExpansionPanelDetails"]
    muiExpansionPanelDetails: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiExpansionPanelSummary"]
    muiExpansionPanelSummary: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormControl"]
    muiFormControl: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormControlLabel"]
    muiFormControlLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormGroup"]
    muiFormGroup: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormHelperText"]
    muiFormHelperText: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormLabel"]
    muiFormLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiGrid"]
    muiGrid: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiGridList"]
    muiGridList: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiGridListTile"]
    muiGridListTile: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiGridListTileBar"]
    muiGridListTileBar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiIcon"]
    muiIcon: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiIconButton"]
    muiIconButton: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiInput"]
    muiInput: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiInputAdornment"]
    muiInputAdornment: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiInputLabel"]
    muiInputLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiLinearProgress"]
    muiLinearProgress: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiList"]
    muiList: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItem"]
    muiListItem: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItemAvatar"]
    muiListItemAvatar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItemIcon"]
    muiListItemIcon: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItemSecondaryAction"]
    muiListItemSecondaryAction: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItemText"]
    muiListItemText: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListSubheader"]
    muiListSubheader: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiMenu"]
    muiMenu: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiMenuItem"]
    muiMenuItem: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiMobileStepper"]
    muiMobileStepper: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiModal"]
    muiModal: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiNativeSelect"]
    muiNativeSelect: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiPaper"]
    muiPaper: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiPopover"]
    muiPopover: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiRadio"]
    muiRadio: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSelect"]
    muiSelect: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSnackbar"]
    muiSnackbar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSnackbarContent"]
    muiSnackbarContent: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStep"]
    muiStep: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepButton"]
    muiStepButton: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepConnector"]
    muiStepConnector: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepContent"]
    muiStepContent: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepIcon"]
    muiStepIcon: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepLabel"]
    muiStepLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepper"]
    muiStepper: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSvgIcon"]
    muiSvgIcon: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSwitch"]
    muiSwitch: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSwitchBase"]
    muiSwitchBase: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTab"]
    muiTab: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTable"]
    muiTable: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableCell"]
    muiTableCell: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTablePagination"]
    muiTablePagination: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableRow"]
    muiTableRow: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableSortLabel"]
    muiTableSortLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTabs"]
    muiTabs: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiToolbar"]
    muiToolbar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTooltip"]
    muiTooltip: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTouchRipple"]
    muiTouchRipple: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTypography"]
    muiTypography: Js.Dict.t(string),
  };
};

module Overrides = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "MuiAppBar"]
    muiAppBar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiAvatar"]
    muiAvatar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiBackdrop"]
    muiBackdrop: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiBadge"]
    muiBadge: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiBottomNavigation"]
    muiBottomNavigation: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiBottomNavigationAction"]
    muiBottomNavigationAction: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiButton"]
    muiButton: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiButtonBase"]
    muiButtonBase: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCard"]
    muiCard: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardActionArea"]
    muiCardActionArea: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardActions"]
    muiCardActions: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardContent"]
    muiCardContent: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardHeader"]
    muiCardHeader: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCardMedia"]
    muiCardMedia: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCheckbox"]
    muiCheckbox: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiChip"]
    muiChip: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCircularProgress"]
    muiCircularProgress: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCollapse"]
    muiCollapse: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiCssBaseline"]
    muiCssBaseline: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialog"]
    muiDialog: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialogActions"]
    muiDialogActions: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialogContent"]
    muiDialogContent: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialogContentText"]
    muiDialogContentText: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDialogTitle"]
    muiDialogTitle: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDivider"]
    muiDivider: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiDrawer"]
    muiDrawer: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiExpansionPanel"]
    muiExpansionPanel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiExpansionPanelActions"]
    muiExpansionPanelActions: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiExpansionPanelDetails"]
    muiExpansionPanelDetails: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiExpansionPanelSummary"]
    muiExpansionPanelSummary: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFilledInput"]
    muiFilledInput: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormControl"]
    muiFormControl: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormControlLabel"]
    muiFormControlLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormGroup"]
    muiFormGroup: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormHelperText"]
    muiFormHelperText: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiFormLabel"]
    muiFormLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiGrid"]
    muiGrid: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiGridList"]
    muiGridList: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiGridListTile"]
    muiGridListTile: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiGridListTileBar"]
    muiGridListTileBar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiIcon"]
    muiIcon: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiIconButton"]
    muiIconButton: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiInput"]
    muiInput: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiInputAdornment"]
    muiInputAdornment: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiInputBase"]
    muiInputBase: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiInputLabel"]
    muiInputLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiLinearProgress"]
    muiLinearProgress: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiList"]
    muiList: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItem"]
    muiListItem: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItemAvatar"]
    muiListItemAvatar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItemIcon"]
    muiListItemIcon: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItemSecondaryAction"]
    muiListItemSecondaryAction: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListItemText"]
    muiListItemText: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiListSubheader"]
    muiListSubheader: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiMenu"]
    muiMenu: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiMenuItem"]
    muiMenuItem: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiMobileStepper"]
    muiMobileStepper: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiModal"]
    muiModal: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiNativeSelect"]
    muiNativeSelect: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiOutlinedInput"]
    muiOutlinedInput: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiPaper"]
    muiPaper: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiPopover"]
    muiPopover: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiRadio"]
    muiRadio: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSelect"]
    muiSelect: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSnackbar"]
    muiSnackbar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSnackbarContent"]
    muiSnackbarContent: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStep"]
    muiStep: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepButton"]
    muiStepButton: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepConnector"]
    muiStepConnector: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepContent"]
    muiStepContent: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepIcon"]
    muiStepIcon: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepLabel"]
    muiStepLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiStepper"]
    muiStepper: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSvgIcon"]
    muiSvgIcon: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSwitch"]
    muiSwitch: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiSwitchBase"]
    muiSwitchBase: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTab"]
    muiTab: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTable"]
    muiTable: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableBody"]
    muiTableBody: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableCell"]
    muiTableCell: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableFooter"]
    muiTableFooter: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableHead"]
    muiTableHead: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTablePagination"]
    muiTablePagination: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableRow"]
    muiTableRow: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTableSortLabel"]
    muiTableSortLabel: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTabs"]
    muiTabs: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiToolbar"]
    muiToolbar: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTooltip"]
    muiTooltip: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTouchRipple"]
    muiTouchRipple: Js.Dict.t(string),
    [@bs.optional] [@bs.as "MuiTypography"]
    muiTypography: Js.Dict.t(string),
  };
};

module BreakpointValues = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "xs"]
    xs: float,
    [@bs.optional] [@bs.as "sm"]
    sm: float,
    [@bs.optional] [@bs.as "md"]
    md: float,
    [@bs.optional] [@bs.as "lg"]
    lg: float,
    [@bs.optional] [@bs.as "xl"]
    xl: float,
  };
};

module Shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "borderRadius"]
    borderRadius: float,
  };
};

module Breakpoints = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "keys"]
    keys: array(string),
    [@bs.as "values"]
    values: BreakpointValues.t,
    [@bs.as "up"]
    up: fixUnionType => string,
    [@bs.as "down"]
    down: fixUnionType => string,
    [@bs.as "between"]
    between: (string, string) => string,
    [@bs.as "only"]
    only: string => string,
    [@bs.as "width"]
    width: string => float,
  };
};

module CSSProperties = {
  type t;
};

module Mixins = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "gutters"]
    gutters: CSSProperties.t => CSSProperties.t,
    [@bs.as "toolbar"]
    toolbar: CSSProperties.t,
  };
};

module CommonColors = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "black"]
    black: string,
    [@bs.as "white"]
    white: string,
  };
};

module PaletteColor = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
    [@bs.as "dark"]
    dark: string,
    [@bs.as "contrastText"]
    contrastText: string,
  };
};

module Color = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "50"]
    n50: string,
    [@bs.as "100"]
    n100: string,
    [@bs.as "200"]
    n200: string,
    [@bs.as "300"]
    n300: string,
    [@bs.as "400"]
    n400: string,
    [@bs.as "500"]
    n500: string,
    [@bs.as "600"]
    n600: string,
    [@bs.as "700"]
    n700: string,
    [@bs.as "800"]
    n800: string,
    [@bs.as "900"]
    n900: string,
    [@bs.as "A100"]
    a100: string,
    [@bs.as "A200"]
    a200: string,
    [@bs.as "A400"]
    a400: string,
    [@bs.as "A700"]
    a700: string,
  };
};

module TypeText = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "primary"]
    primary: string,
    [@bs.as "secondary"]
    secondary: string,
    [@bs.as "disabled"]
    disabled: string,
    [@bs.as "hint"]
    hint: string,
  };
};

module TypeAction = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "active"]
    active: string,
    [@bs.as "hover"]
    hover: string,
    [@bs.as "hoverOpacity"]
    hoverOpacity: float,
    [@bs.as "selected"]
    selected: string,
    [@bs.as "disabled"]
    disabled: string,
    [@bs.as "disabledBackground"]
    disabledBackground: string,
  };
};

module TypeBackground = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "default"]
    default: string,
    [@bs.as "paper"]
    paper: string,
  };
};

module Palette = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "common"]
    common: CommonColors.t,
    [@bs.as "type"]
    type_: string,
    [@bs.as "contrastThreshold"]
    contrastThreshold: float,
    [@bs.as "tonalOffset"]
    tonalOffset: float,
    [@bs.as "primary"]
    primary: PaletteColor.t,
    [@bs.as "secondary"]
    secondary: PaletteColor.t,
    [@bs.as "error"]
    error: PaletteColor.t,
    [@bs.as "grey"]
    grey: Color.t,
    [@bs.as "text"]
    text: TypeText.t,
    [@bs.as "divider"]
    divider: string,
    [@bs.as "action"]
    action: TypeAction.t,
    [@bs.as "background"]
    background: TypeBackground.t,
    [@bs.as "getContrastText"]
    getContrastText: string => string,
    [@bs.as "augmentColor"]
    augmentColor: fixType,
  };
};

module Spacing = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "unit"]
    unit: float,
  };
};

module Easing = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "easeInOut"]
    easeInOut: string,
    [@bs.as "easeOut"]
    easeOut: string,
    [@bs.as "easeIn"]
    easeIn: string,
    [@bs.as "sharp"]
    sharp: string,
  };
};

module Duration = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "shortest"]
    shortest: float,
    [@bs.as "shorter"]
    shorter: float,
    [@bs.as "short"]
    short: float,
    [@bs.as "standard"]
    standard: float,
    [@bs.as "complex"]
    complex: float,
    [@bs.as "enteringScreen"]
    enteringScreen: float,
    [@bs.as "leavingScreen"]
    leavingScreen: float,
  };
};

module Transitions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "easing"]
    easing: Easing.t,
    [@bs.as "duration"]
    duration: Duration.t,
  };
};

module Typography = {
  type t;
};

module ZIndex = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "mobileStepper"]
    mobileStepper: float,
    [@bs.as "appBar"]
    appBar: float,
    [@bs.as "drawer"]
    drawer: float,
    [@bs.as "modal"]
    modal: float,
    [@bs.as "snackbar"]
    snackbar: float,
    [@bs.as "tooltip"]
    tooltip: float,
  };
};

module Theme = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "shape"]
    shape: Shape.t,
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
    shadows: fixType,
    [@bs.as "spacing"]
    spacing: Spacing.t,
    [@bs.as "transitions"]
    transitions: Transitions.t,
    [@bs.as "typography"]
    typography: Typography.t,
    [@bs.as "zIndex"]
    zIndex: ZIndex.t,
  };
};

type t = Theme.t;
