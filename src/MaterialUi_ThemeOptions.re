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
  type t('between, 'down, 'only, 'up, 'width) = {
    [@bs.optional] [@bs.as "between"]
    between: Js.t('between),
    [@bs.optional] [@bs.as "down"]
    down: Js.t('down),
    [@bs.optional] [@bs.as "keys"]
    keys: array(string),
    [@bs.optional] [@bs.as "only"]
    only: Js.t('only),
    [@bs.optional] [@bs.as "step"]
    step: float,
    [@bs.optional] [@bs.as "unit"]
    unit: string,
    [@bs.optional] [@bs.as "up"]
    up: Js.t('up),
    [@bs.optional] [@bs.as "values"]
    values: BreakpointValues.t,
    [@bs.optional] [@bs.as "width"]
    width: Js.t('width),
  };

  let make = t;
};

module MixinsOptions = {
  [@bs.deriving abstract]
  type t('gutters) = {
    [@bs.optional] [@bs.as "gutters"]
    gutters: Js.t('gutters),
    [@bs.optional] [@bs.as "toolbar"]
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
    [@bs.optional] [@bs.as "active"]
    active: string,
    [@bs.optional] [@bs.as "disabled"]
    disabled: string,
    [@bs.optional] [@bs.as "disabledBackground"]
    disabledBackground: string,
    [@bs.optional] [@bs.as "hover"]
    hover: string,
    [@bs.optional] [@bs.as "hoverOpacity"]
    hoverOpacity: float,
    [@bs.optional] [@bs.as "selected"]
    selected: string,
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

module PaletteOptions = {
  [@bs.deriving abstract]
  type t('getContrastText) = {
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
    [@bs.optional] [@bs.as "getContrastText"]
    getContrastText: Js.t('getContrastText),
    [@bs.optional] [@bs.as "grey"]
    grey: Color.t,
    [@bs.optional] [@bs.as "text"]
    text: TypeText.t,
    [@bs.optional] [@bs.as "tonalOffset"]
    tonalOffset: float,
    [@bs.optional] [@bs.as "type"]
    type_: string,
  };

  let make = t;
};

module ComponentsProps = {
  [@bs.deriving abstract]
  type t(
    'muiAppBar,
    'muiAvatar,
    'muiBackdrop,
    'muiBadge,
    'muiBottomNavigation,
    'muiBottomNavigationAction,
    'muiButton,
    'muiButtonBase,
    'muiCard,
    'muiCardActions,
    'muiCardContent,
    'muiCardHeader,
    'muiCardMedia,
    'muiCheckbox,
    'muiChip,
    'muiCircularProgress,
    'muiCollapse,
    'muiCssBaseline,
    'muiDialog,
    'muiDialogActions,
    'muiDialogContent,
    'muiDialogContentText,
    'muiDialogTitle,
    'muiDivider,
    'muiDrawer,
    'muiExpansionPanel,
    'muiExpansionPanelActions,
    'muiExpansionPanelDetails,
    'muiExpansionPanelSummary,
    'muiFormControl,
    'muiFormControlLabel,
    'muiFormGroup,
    'muiFormHelperText,
    'muiFormLabel,
    'muiGrid,
    'muiGridList,
    'muiGridListTile,
    'muiGridListTileBar,
    'muiIcon,
    'muiIconButton,
    'muiInput,
    'muiInputAdornment,
    'muiInputLabel,
    'muiLinearProgress,
    'muiList,
    'muiListItem,
    'muiListItemAvatar,
    'muiListItemIcon,
    'muiListItemSecondaryAction,
    'muiListItemText,
    'muiListSubheader,
    'muiMenu,
    'muiMenuItem,
    'muiMobileStepper,
    'muiModal,
    'muiNativeSelect,
    'muiPaper,
    'muiPopover,
    'muiRadio,
    'muiSelect,
    'muiSnackbar,
    'muiSnackbarContent,
    'muiStep,
    'muiStepButton,
    'muiStepConnector,
    'muiStepContent,
    'muiStepIcon,
    'muiStepLabel,
    'muiStepper,
    'muiSvgIcon,
    'muiSwitch,
    'muiSwitchBase,
    'muiTab,
    'muiTable,
    'muiTableCell,
    'muiTablePagination,
    'muiTableRow,
    'muiTableSortLabel,
    'muiTabs,
    'muiToolbar,
    'muiTooltip,
    'muiTypography,
  ) = {
    [@bs.optional] [@bs.as "MuiAppBar"]
    muiAppBar: Js.t('muiAppBar),
    [@bs.optional] [@bs.as "MuiAvatar"]
    muiAvatar: Js.t('muiAvatar),
    [@bs.optional] [@bs.as "MuiBackdrop"]
    muiBackdrop: Js.t('muiBackdrop),
    [@bs.optional] [@bs.as "MuiBadge"]
    muiBadge: Js.t('muiBadge),
    [@bs.optional] [@bs.as "MuiBottomNavigation"]
    muiBottomNavigation: Js.t('muiBottomNavigation),
    [@bs.optional] [@bs.as "MuiBottomNavigationAction"]
    muiBottomNavigationAction: Js.t('muiBottomNavigationAction),
    [@bs.optional] [@bs.as "MuiButton"]
    muiButton: Js.t('muiButton),
    [@bs.optional] [@bs.as "MuiButtonBase"]
    muiButtonBase: Js.t('muiButtonBase),
    [@bs.optional] [@bs.as "MuiCard"]
    muiCard: Js.t('muiCard),
    [@bs.optional] [@bs.as "MuiCardActions"]
    muiCardActions: Js.t('muiCardActions),
    [@bs.optional] [@bs.as "MuiCardContent"]
    muiCardContent: Js.t('muiCardContent),
    [@bs.optional] [@bs.as "MuiCardHeader"]
    muiCardHeader: Js.t('muiCardHeader),
    [@bs.optional] [@bs.as "MuiCardMedia"]
    muiCardMedia: Js.t('muiCardMedia),
    [@bs.optional] [@bs.as "MuiCheckbox"]
    muiCheckbox: Js.t('muiCheckbox),
    [@bs.optional] [@bs.as "MuiChip"]
    muiChip: Js.t('muiChip),
    [@bs.optional] [@bs.as "MuiCircularProgress"]
    muiCircularProgress: Js.t('muiCircularProgress),
    [@bs.optional] [@bs.as "MuiCollapse"]
    muiCollapse: Js.t('muiCollapse),
    [@bs.optional] [@bs.as "MuiCssBaseline"]
    muiCssBaseline: Js.t('muiCssBaseline),
    [@bs.optional] [@bs.as "MuiDialog"]
    muiDialog: Js.t('muiDialog),
    [@bs.optional] [@bs.as "MuiDialogActions"]
    muiDialogActions: Js.t('muiDialogActions),
    [@bs.optional] [@bs.as "MuiDialogContent"]
    muiDialogContent: Js.t('muiDialogContent),
    [@bs.optional] [@bs.as "MuiDialogContentText"]
    muiDialogContentText: Js.t('muiDialogContentText),
    [@bs.optional] [@bs.as "MuiDialogTitle"]
    muiDialogTitle: Js.t('muiDialogTitle),
    [@bs.optional] [@bs.as "MuiDivider"]
    muiDivider: Js.t('muiDivider),
    [@bs.optional] [@bs.as "MuiDrawer"]
    muiDrawer: Js.t('muiDrawer),
    [@bs.optional] [@bs.as "MuiExpansionPanel"]
    muiExpansionPanel: Js.t('muiExpansionPanel),
    [@bs.optional] [@bs.as "MuiExpansionPanelActions"]
    muiExpansionPanelActions: Js.t('muiExpansionPanelActions),
    [@bs.optional] [@bs.as "MuiExpansionPanelDetails"]
    muiExpansionPanelDetails: Js.t('muiExpansionPanelDetails),
    [@bs.optional] [@bs.as "MuiExpansionPanelSummary"]
    muiExpansionPanelSummary: Js.t('muiExpansionPanelSummary),
    [@bs.optional] [@bs.as "MuiFormControl"]
    muiFormControl: Js.t('muiFormControl),
    [@bs.optional] [@bs.as "MuiFormControlLabel"]
    muiFormControlLabel: Js.t('muiFormControlLabel),
    [@bs.optional] [@bs.as "MuiFormGroup"]
    muiFormGroup: Js.t('muiFormGroup),
    [@bs.optional] [@bs.as "MuiFormHelperText"]
    muiFormHelperText: Js.t('muiFormHelperText),
    [@bs.optional] [@bs.as "MuiFormLabel"]
    muiFormLabel: Js.t('muiFormLabel),
    [@bs.optional] [@bs.as "MuiGrid"]
    muiGrid: Js.t('muiGrid),
    [@bs.optional] [@bs.as "MuiGridList"]
    muiGridList: Js.t('muiGridList),
    [@bs.optional] [@bs.as "MuiGridListTile"]
    muiGridListTile: Js.t('muiGridListTile),
    [@bs.optional] [@bs.as "MuiGridListTileBar"]
    muiGridListTileBar: Js.t('muiGridListTileBar),
    [@bs.optional] [@bs.as "MuiIcon"]
    muiIcon: Js.t('muiIcon),
    [@bs.optional] [@bs.as "MuiIconButton"]
    muiIconButton: Js.t('muiIconButton),
    [@bs.optional] [@bs.as "MuiInput"]
    muiInput: Js.t('muiInput),
    [@bs.optional] [@bs.as "MuiInputAdornment"]
    muiInputAdornment: Js.t('muiInputAdornment),
    [@bs.optional] [@bs.as "MuiInputLabel"]
    muiInputLabel: Js.t('muiInputLabel),
    [@bs.optional] [@bs.as "MuiLinearProgress"]
    muiLinearProgress: Js.t('muiLinearProgress),
    [@bs.optional] [@bs.as "MuiList"]
    muiList: Js.t('muiList),
    [@bs.optional] [@bs.as "MuiListItem"]
    muiListItem: Js.t('muiListItem),
    [@bs.optional] [@bs.as "MuiListItemAvatar"]
    muiListItemAvatar: Js.t('muiListItemAvatar),
    [@bs.optional] [@bs.as "MuiListItemIcon"]
    muiListItemIcon: Js.t('muiListItemIcon),
    [@bs.optional] [@bs.as "MuiListItemSecondaryAction"]
    muiListItemSecondaryAction: Js.t('muiListItemSecondaryAction),
    [@bs.optional] [@bs.as "MuiListItemText"]
    muiListItemText: Js.t('muiListItemText),
    [@bs.optional] [@bs.as "MuiListSubheader"]
    muiListSubheader: Js.t('muiListSubheader),
    [@bs.optional] [@bs.as "MuiMenu"]
    muiMenu: Js.t('muiMenu),
    [@bs.optional] [@bs.as "MuiMenuItem"]
    muiMenuItem: Js.t('muiMenuItem),
    [@bs.optional] [@bs.as "MuiMobileStepper"]
    muiMobileStepper: Js.t('muiMobileStepper),
    [@bs.optional] [@bs.as "MuiModal"]
    muiModal: Js.t('muiModal),
    [@bs.optional] [@bs.as "MuiNativeSelect"]
    muiNativeSelect: Js.t('muiNativeSelect),
    [@bs.optional] [@bs.as "MuiPaper"]
    muiPaper: Js.t('muiPaper),
    [@bs.optional] [@bs.as "MuiPopover"]
    muiPopover: Js.t('muiPopover),
    [@bs.optional] [@bs.as "MuiRadio"]
    muiRadio: Js.t('muiRadio),
    [@bs.optional] [@bs.as "MuiSelect"]
    muiSelect: Js.t('muiSelect),
    [@bs.optional] [@bs.as "MuiSnackbar"]
    muiSnackbar: Js.t('muiSnackbar),
    [@bs.optional] [@bs.as "MuiSnackbarContent"]
    muiSnackbarContent: Js.t('muiSnackbarContent),
    [@bs.optional] [@bs.as "MuiStep"]
    muiStep: Js.t('muiStep),
    [@bs.optional] [@bs.as "MuiStepButton"]
    muiStepButton: Js.t('muiStepButton),
    [@bs.optional] [@bs.as "MuiStepConnector"]
    muiStepConnector: Js.t('muiStepConnector),
    [@bs.optional] [@bs.as "MuiStepContent"]
    muiStepContent: Js.t('muiStepContent),
    [@bs.optional] [@bs.as "MuiStepIcon"]
    muiStepIcon: Js.t('muiStepIcon),
    [@bs.optional] [@bs.as "MuiStepLabel"]
    muiStepLabel: Js.t('muiStepLabel),
    [@bs.optional] [@bs.as "MuiStepper"]
    muiStepper: Js.t('muiStepper),
    [@bs.optional] [@bs.as "MuiSvgIcon"]
    muiSvgIcon: Js.t('muiSvgIcon),
    [@bs.optional] [@bs.as "MuiSwitch"]
    muiSwitch: Js.t('muiSwitch),
    [@bs.optional] [@bs.as "MuiSwitchBase"]
    muiSwitchBase: Js.t('muiSwitchBase),
    [@bs.optional] [@bs.as "MuiTab"]
    muiTab: Js.t('muiTab),
    [@bs.optional] [@bs.as "MuiTable"]
    muiTable: Js.t('muiTable),
    [@bs.optional] [@bs.as "MuiTableCell"]
    muiTableCell: Js.t('muiTableCell),
    [@bs.optional] [@bs.as "MuiTablePagination"]
    muiTablePagination: Js.t('muiTablePagination),
    [@bs.optional] [@bs.as "MuiTableRow"]
    muiTableRow: Js.t('muiTableRow),
    [@bs.optional] [@bs.as "MuiTableSortLabel"]
    muiTableSortLabel: Js.t('muiTableSortLabel),
    [@bs.optional] [@bs.as "MuiTabs"]
    muiTabs: Js.t('muiTabs),
    [@bs.optional] [@bs.as "MuiToolbar"]
    muiToolbar: Js.t('muiToolbar),
    [@bs.optional] [@bs.as "MuiTooltip"]
    muiTooltip: Js.t('muiTooltip),
    [@bs.optional] [@bs.as "MuiTypography"]
    muiTypography: Js.t('muiTypography),
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

module Spacing = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "unit"]
    unit: float,
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
  type t('create, 'getAutoHeightDuration) = {
    [@bs.optional] [@bs.as "create"]
    create: Js.t('create),
    [@bs.optional] [@bs.as "duration"]
    duration: Duration.t,
    [@bs.optional] [@bs.as "easing"]
    easing: Easing.t,
    [@bs.optional] [@bs.as "getAutoHeightDuration"]
    getAutoHeightDuration: Js.t('getAutoHeightDuration),
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
    [@bs.optional] [@bs.as "tooltip"]
    tooltip: float,
  };

  let make = t;
};

module ThemeOptions = {
  [@bs.deriving abstract]
  type t(
    'between,
    'down,
    'only,
    'up,
    'width,
    'gutters,
    'getContrastText,
    'muiAppBar,
    'muiAvatar,
    'muiBackdrop,
    'muiBadge,
    'muiBottomNavigation,
    'muiBottomNavigationAction,
    'muiButton,
    'muiButtonBase,
    'muiCard,
    'muiCardActions,
    'muiCardContent,
    'muiCardHeader,
    'muiCardMedia,
    'muiCheckbox,
    'muiChip,
    'muiCircularProgress,
    'muiCollapse,
    'muiCssBaseline,
    'muiDialog,
    'muiDialogActions,
    'muiDialogContent,
    'muiDialogContentText,
    'muiDialogTitle,
    'muiDivider,
    'muiDrawer,
    'muiExpansionPanel,
    'muiExpansionPanelActions,
    'muiExpansionPanelDetails,
    'muiExpansionPanelSummary,
    'muiFormControl,
    'muiFormControlLabel,
    'muiFormGroup,
    'muiFormHelperText,
    'muiFormLabel,
    'muiGrid,
    'muiGridList,
    'muiGridListTile,
    'muiGridListTileBar,
    'muiIcon,
    'muiIconButton,
    'muiInput,
    'muiInputAdornment,
    'muiInputLabel,
    'muiLinearProgress,
    'muiList,
    'muiListItem,
    'muiListItemAvatar,
    'muiListItemIcon,
    'muiListItemSecondaryAction,
    'muiListItemText,
    'muiListSubheader,
    'muiMenu,
    'muiMenuItem,
    'muiMobileStepper,
    'muiModal,
    'muiNativeSelect,
    'muiPaper,
    'muiPopover,
    'muiRadio,
    'muiSelect,
    'muiSnackbar,
    'muiSnackbarContent,
    'muiStep,
    'muiStepButton,
    'muiStepConnector,
    'muiStepContent,
    'muiStepIcon,
    'muiStepLabel,
    'muiStepper,
    'muiSvgIcon,
    'muiSwitch,
    'muiSwitchBase,
    'muiTab,
    'muiTable,
    'muiTableCell,
    'muiTablePagination,
    'muiTableRow,
    'muiTableSortLabel,
    'muiTabs,
    'muiToolbar,
    'muiTooltip,
    'muiTypography,
    'create,
    'getAutoHeightDuration,
  ) = {
    [@bs.optional] [@bs.as "breakpoints"]
    breakpoints: Breakpoints.t('between, 'down, 'only, 'up, 'width),
    [@bs.optional] [@bs.as "direction"]
    direction: string,
    [@bs.optional] [@bs.as "mixins"]
    mixins: MixinsOptions.t('gutters),
    [@bs.optional] [@bs.as "overrides"]
    overrides: Overrides.t,
    [@bs.optional] [@bs.as "palette"]
    palette: PaletteOptions.t('getContrastText),
    [@bs.optional] [@bs.as "props"]
    props:
      ComponentsProps.t(
        'muiAppBar,
        'muiAvatar,
        'muiBackdrop,
        'muiBadge,
        'muiBottomNavigation,
        'muiBottomNavigationAction,
        'muiButton,
        'muiButtonBase,
        'muiCard,
        'muiCardActions,
        'muiCardContent,
        'muiCardHeader,
        'muiCardMedia,
        'muiCheckbox,
        'muiChip,
        'muiCircularProgress,
        'muiCollapse,
        'muiCssBaseline,
        'muiDialog,
        'muiDialogActions,
        'muiDialogContent,
        'muiDialogContentText,
        'muiDialogTitle,
        'muiDivider,
        'muiDrawer,
        'muiExpansionPanel,
        'muiExpansionPanelActions,
        'muiExpansionPanelDetails,
        'muiExpansionPanelSummary,
        'muiFormControl,
        'muiFormControlLabel,
        'muiFormGroup,
        'muiFormHelperText,
        'muiFormLabel,
        'muiGrid,
        'muiGridList,
        'muiGridListTile,
        'muiGridListTileBar,
        'muiIcon,
        'muiIconButton,
        'muiInput,
        'muiInputAdornment,
        'muiInputLabel,
        'muiLinearProgress,
        'muiList,
        'muiListItem,
        'muiListItemAvatar,
        'muiListItemIcon,
        'muiListItemSecondaryAction,
        'muiListItemText,
        'muiListSubheader,
        'muiMenu,
        'muiMenuItem,
        'muiMobileStepper,
        'muiModal,
        'muiNativeSelect,
        'muiPaper,
        'muiPopover,
        'muiRadio,
        'muiSelect,
        'muiSnackbar,
        'muiSnackbarContent,
        'muiStep,
        'muiStepButton,
        'muiStepConnector,
        'muiStepContent,
        'muiStepIcon,
        'muiStepLabel,
        'muiStepper,
        'muiSvgIcon,
        'muiSwitch,
        'muiSwitchBase,
        'muiTab,
        'muiTable,
        'muiTableCell,
        'muiTablePagination,
        'muiTableRow,
        'muiTableSortLabel,
        'muiTabs,
        'muiToolbar,
        'muiTooltip,
        'muiTypography,
      ),
    [@bs.optional] [@bs.as "shadows"]
    shadows: array(string),
    [@bs.optional] [@bs.as "shape"]
    shape: Shape.t,
    [@bs.optional] [@bs.as "spacing"]
    spacing: Spacing.t,
    [@bs.optional] [@bs.as "transitions"]
    transitions: TransitionsOptions.t('create, 'getAutoHeightDuration),
    [@bs.optional] [@bs.as "zIndex"]
    zIndex: ZIndex.t,
  };

  let make = t;
};

type t('p) =
  ThemeOptions.t(
    'between,
    'down,
    'only,
    'up,
    'width,
    'gutters,
    'getContrastText,
    'muiAppBar,
    'muiAvatar,
    'muiBackdrop,
    'muiBadge,
    'muiBottomNavigation,
    'muiBottomNavigationAction,
    'muiButton,
    'muiButtonBase,
    'muiCard,
    'muiCardActions,
    'muiCardContent,
    'muiCardHeader,
    'muiCardMedia,
    'muiCheckbox,
    'muiChip,
    'muiCircularProgress,
    'muiCollapse,
    'muiCssBaseline,
    'muiDialog,
    'muiDialogActions,
    'muiDialogContent,
    'muiDialogContentText,
    'muiDialogTitle,
    'muiDivider,
    'muiDrawer,
    'muiExpansionPanel,
    'muiExpansionPanelActions,
    'muiExpansionPanelDetails,
    'muiExpansionPanelSummary,
    'muiFormControl,
    'muiFormControlLabel,
    'muiFormGroup,
    'muiFormHelperText,
    'muiFormLabel,
    'muiGrid,
    'muiGridList,
    'muiGridListTile,
    'muiGridListTileBar,
    'muiIcon,
    'muiIconButton,
    'muiInput,
    'muiInputAdornment,
    'muiInputLabel,
    'muiLinearProgress,
    'muiList,
    'muiListItem,
    'muiListItemAvatar,
    'muiListItemIcon,
    'muiListItemSecondaryAction,
    'muiListItemText,
    'muiListSubheader,
    'muiMenu,
    'muiMenuItem,
    'muiMobileStepper,
    'muiModal,
    'muiNativeSelect,
    'muiPaper,
    'muiPopover,
    'muiRadio,
    'muiSelect,
    'muiSnackbar,
    'muiSnackbarContent,
    'muiStep,
    'muiStepButton,
    'muiStepConnector,
    'muiStepContent,
    'muiStepIcon,
    'muiStepLabel,
    'muiStepper,
    'muiSvgIcon,
    'muiSwitch,
    'muiSwitchBase,
    'muiTab,
    'muiTable,
    'muiTableCell,
    'muiTablePagination,
    'muiTableRow,
    'muiTableSortLabel,
    'muiTabs,
    'muiToolbar,
    'muiTooltip,
    'muiTypography,
    'create,
    'getAutoHeightDuration,
  )
constraint 'p = (
  'between,
  'down,
  'only,
  'up,
  'width,
  'gutters,
  'getContrastText,
  'muiAppBar,
  'muiAvatar,
  'muiBackdrop,
  'muiBadge,
  'muiBottomNavigation,
  'muiBottomNavigationAction,
  'muiButton,
  'muiButtonBase,
  'muiCard,
  'muiCardActions,
  'muiCardContent,
  'muiCardHeader,
  'muiCardMedia,
  'muiCheckbox,
  'muiChip,
  'muiCircularProgress,
  'muiCollapse,
  'muiCssBaseline,
  'muiDialog,
  'muiDialogActions,
  'muiDialogContent,
  'muiDialogContentText,
  'muiDialogTitle,
  'muiDivider,
  'muiDrawer,
  'muiExpansionPanel,
  'muiExpansionPanelActions,
  'muiExpansionPanelDetails,
  'muiExpansionPanelSummary,
  'muiFormControl,
  'muiFormControlLabel,
  'muiFormGroup,
  'muiFormHelperText,
  'muiFormLabel,
  'muiGrid,
  'muiGridList,
  'muiGridListTile,
  'muiGridListTileBar,
  'muiIcon,
  'muiIconButton,
  'muiInput,
  'muiInputAdornment,
  'muiInputLabel,
  'muiLinearProgress,
  'muiList,
  'muiListItem,
  'muiListItemAvatar,
  'muiListItemIcon,
  'muiListItemSecondaryAction,
  'muiListItemText,
  'muiListSubheader,
  'muiMenu,
  'muiMenuItem,
  'muiMobileStepper,
  'muiModal,
  'muiNativeSelect,
  'muiPaper,
  'muiPopover,
  'muiRadio,
  'muiSelect,
  'muiSnackbar,
  'muiSnackbarContent,
  'muiStep,
  'muiStepButton,
  'muiStepConnector,
  'muiStepContent,
  'muiStepIcon,
  'muiStepLabel,
  'muiStepper,
  'muiSvgIcon,
  'muiSwitch,
  'muiSwitchBase,
  'muiTab,
  'muiTable,
  'muiTableCell,
  'muiTablePagination,
  'muiTableRow,
  'muiTableSortLabel,
  'muiTabs,
  'muiToolbar,
  'muiTooltip,
  'muiTypography,
  'create,
  'getAutoHeightDuration,
);
let make = ThemeOptions.make;
