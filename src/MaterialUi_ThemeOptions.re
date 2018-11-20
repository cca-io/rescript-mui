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

module Partial = {
  type t;
};

module MixinsOptions = {
  type t;
};

module PaletteOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "primary"]
    primary: fixUnionType,
    [@bs.optional] [@bs.as "secondary"]
    secondary: fixUnionType,
    [@bs.optional] [@bs.as "error"]
    error: fixUnionType,
    [@bs.optional] [@bs.as "type"]
    type_: string,
    [@bs.optional] [@bs.as "tonalOffset"]
    tonalOffset: float,
    [@bs.optional] [@bs.as "contrastThreshold"]
    contrastThreshold: float,
    [@bs.optional] [@bs.as "common"]
    common: Partial.t,
    [@bs.optional] [@bs.as "grey"]
    grey: Partial.t,
    [@bs.optional] [@bs.as "text"]
    text: Partial.t,
    [@bs.optional] [@bs.as "divider"]
    divider: string,
    [@bs.optional] [@bs.as "action"]
    action: Partial.t,
    [@bs.optional] [@bs.as "background"]
    background: Partial.t,
    [@bs.optional] [@bs.as "getContrastText"]
    getContrastText: string => string,
  };
};

module TransitionsOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "easing"]
    easing: Partial.t,
    [@bs.optional] [@bs.as "duration"]
    duration: Partial.t,
    [@bs.optional] [@bs.as "create"]
    create: (fixUnionType, Partial.t) => string,
    [@bs.optional] [@bs.as "getAutoHeightDuration"]
    getAutoHeightDuration: float => float,
  };
};

module ThemeOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "shape"]
    shape: Partial.t,
    [@bs.optional] [@bs.as "breakpoints"]
    breakpoints: Partial.t,
    [@bs.optional] [@bs.as "direction"]
    direction: string,
    [@bs.optional] [@bs.as "mixins"]
    mixins: MixinsOptions.t,
    [@bs.optional] [@bs.as "overrides"]
    overrides: Overrides.t,
    [@bs.optional] [@bs.as "palette"]
    palette: PaletteOptions.t,
    [@bs.optional] [@bs.as "props"]
    props: ComponentsProps.t,
    [@bs.optional] [@bs.as "shadows"]
    shadows: fixType,
    [@bs.optional] [@bs.as "spacing"]
    spacing: Partial.t,
    [@bs.optional] [@bs.as "transitions"]
    transitions: TransitionsOptions.t,
    [@bs.optional] [@bs.as "typography"]
    typography: fixUnionType,
    [@bs.optional] [@bs.as "zIndex"]
    zIndex: Partial.t,
  };
};

type t = ThemeOptions.t;
