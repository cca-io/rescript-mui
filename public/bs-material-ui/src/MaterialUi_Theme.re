type t_breakpointValues = {
  lg: float,
  md: float,
  sm: float,
  xl: float,
  xs: float,
};

type t_breakpoints = {
  between: MaterialUi_Types.any,
  down: MaterialUi_Types.any,
  keys: array(string),
  only: MaterialUi_Types.any,
  up: MaterialUi_Types.any,
  values: t_breakpointValues,
  width: MaterialUi_Types.any,
};

type t_mixins = {
  gutters: MaterialUi_Types.any,
  toolbar: ReactDOM.Style.t,
};

type t_accordionClassKey = {
  disabled: ReactDOM.Style.t,
  expanded: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  rounded: ReactDOM.Style.t,
};

type t_accordionActionsClassKey = {
  root: ReactDOM.Style.t,
  spacing: ReactDOM.Style.t,
};

type t_muiAccordionDetails = {root: ReactDOM.Style.t};

type t_accordionSummaryClassKey = {
  content: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  expandIcon: ReactDOM.Style.t,
  expanded: ReactDOM.Style.t,
  focused: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_appBarClassKey = {
  colorDefault: string,
  colorPrimary: string,
  colorSecondary: string,
  positionAbsolute: ReactDOM.Style.t,
  positionFixed: ReactDOM.Style.t,
  positionRelative: ReactDOM.Style.t,
  positionStatic: ReactDOM.Style.t,
  positionSticky: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_avatarClassKey = {
  circle: ReactDOM.Style.t,
  circular: ReactDOM.Style.t,
  colorDefault: string,
  fallback: ReactDOM.Style.t,
  img: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  rounded: ReactDOM.Style.t,
  square: ReactDOM.Style.t,
};

type t_backdropClassKey = {
  invisible: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_badgeClassKey = {
  anchorOriginBottomLeftRectangle: ReactDOM.Style.t,
  anchorOriginBottomRightCircle: ReactDOM.Style.t,
  anchorOriginBottomRightRectangle: ReactDOM.Style.t,
  anchorOriginTopLeftCircle: ReactDOM.Style.t,
  anchorOriginTopLeftRectangle: ReactDOM.Style.t,
  anchorOriginTopRightCircle: ReactDOM.Style.t,
  anchorOriginTopRightRectangle: ReactDOM.Style.t,
  badge: ReactDOM.Style.t,
  colorError: string,
  colorPrimary: string,
  colorSecondary: string,
  dot: ReactDOM.Style.t,
  invisible: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_muiBottomNavigation = {root: ReactDOM.Style.t};

type t_bottomNavigationActionClassKey = {
  iconOnly: ReactDOM.Style.t,
  label: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  selected: ReactDOM.Style.t,
  wrapper: ReactDOM.Style.t,
};

type t_breadcrumbsClassKey = {
  li: ReactDOM.Style.t,
  ol: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  separator: ReactDOM.Style.t,
};

type t_buttonClassKey = {
  colorInherit: string,
  contained: ReactDOM.Style.t,
  containedPrimary: ReactDOM.Style.t,
  containedSecondary: ReactDOM.Style.t,
  containedSizeLarge: ReactDOM.Style.t,
  containedSizeSmall: ReactDOM.Style.t,
  disableElevation: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  endIcon: ReactDOM.Style.t,
  focusVisible: ReactDOM.Style.t,
  fullWidth: ReactDOM.Style.t,
  iconSizeLarge: ReactDOM.Style.t,
  iconSizeMedium: ReactDOM.Style.t,
  iconSizeSmall: ReactDOM.Style.t,
  label: ReactDOM.Style.t,
  outlined: ReactDOM.Style.t,
  outlinedPrimary: ReactDOM.Style.t,
  outlinedSecondary: ReactDOM.Style.t,
  outlinedSizeLarge: ReactDOM.Style.t,
  outlinedSizeSmall: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  sizeLarge: ReactDOM.Style.t,
  sizeSmall: ReactDOM.Style.t,
  startIcon: ReactDOM.Style.t,
  text: ReactDOM.Style.t,
  textPrimary: ReactDOM.Style.t,
  textSecondary: ReactDOM.Style.t,
  textSizeLarge: ReactDOM.Style.t,
  textSizeSmall: ReactDOM.Style.t,
};

type t_buttonBaseClassKey = {
  disabled: ReactDOM.Style.t,
  focusVisible: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_buttonGroupClassKey = {
  contained: ReactDOM.Style.t,
  disableElevation: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  fullWidth: ReactDOM.Style.t,
  grouped: ReactDOM.Style.t,
  groupedContained: ReactDOM.Style.t,
  groupedContainedHorizontal: ReactDOM.Style.t,
  groupedContainedPrimary: ReactDOM.Style.t,
  groupedContainedSecondary: ReactDOM.Style.t,
  groupedContainedVertical: ReactDOM.Style.t,
  groupedHorizontal: ReactDOM.Style.t,
  groupedOutlined: ReactDOM.Style.t,
  groupedOutlinedHorizontal: ReactDOM.Style.t,
  groupedOutlinedPrimary: ReactDOM.Style.t,
  groupedOutlinedSecondary: ReactDOM.Style.t,
  groupedOutlinedVertical: ReactDOM.Style.t,
  groupedText: ReactDOM.Style.t,
  groupedTextHorizontal: ReactDOM.Style.t,
  groupedTextPrimary: ReactDOM.Style.t,
  groupedTextSecondary: ReactDOM.Style.t,
  groupedTextVertical: ReactDOM.Style.t,
  groupedVertical: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  vertical: ReactDOM.Style.t,
};

type t_muiCard = {root: ReactDOM.Style.t};

type t_cardActionAreaClassKey = {
  focusHighlight: ReactDOM.Style.t,
  focusVisible: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_muiCardContent = {root: ReactDOM.Style.t};

type t_cardHeaderClassKey = {
  action: ReactDOM.Style.t,
  avatar: ReactDOM.Style.t,
  content: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  subheader: ReactDOM.Style.t,
  title: ReactDOM.Style.t,
};

type t_cardMediaClassKey = {
  media: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_checkboxClassKey = {
  checked: ReactDOM.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  indeterminate: ReactDOM.Style.t,
  input: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_chipClassKey = {
  avatar: ReactDOM.Style.t,
  avatarColorPrimary: ReactDOM.Style.t,
  avatarColorSecondary: ReactDOM.Style.t,
  avatarSmall: ReactDOM.Style.t,
  clickable: ReactDOM.Style.t,
  clickableColorPrimary: ReactDOM.Style.t,
  clickableColorSecondary: ReactDOM.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  deletable: ReactDOM.Style.t,
  deletableColorPrimary: ReactDOM.Style.t,
  deletableColorSecondary: ReactDOM.Style.t,
  deleteIcon: ReactDOM.Style.t,
  deleteIconColorPrimary: ReactDOM.Style.t,
  deleteIconColorSecondary: ReactDOM.Style.t,
  deleteIconOutlinedColorPrimary: ReactDOM.Style.t,
  deleteIconOutlinedColorSecondary: ReactDOM.Style.t,
  deleteIconSmall: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  icon: ReactDOM.Style.t,
  iconColorPrimary: ReactDOM.Style.t,
  iconColorSecondary: ReactDOM.Style.t,
  iconSmall: ReactDOM.Style.t,
  label: ReactDOM.Style.t,
  labelSmall: ReactDOM.Style.t,
  outlined: ReactDOM.Style.t,
  outlinedPrimary: ReactDOM.Style.t,
  outlinedSecondary: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  sizeSmall: ReactDOM.Style.t,
};

type t_circularProgressClassKey = {
  circle: ReactDOM.Style.t,
  circleDeterminate: ReactDOM.Style.t,
  circleDisableShrink: ReactDOM.Style.t,
  circleIndeterminate: ReactDOM.Style.t,
  circleStatic: ReactDOM.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  determinate: ReactDOM.Style.t,
  indeterminate: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  static: ReactDOM.Style.t,
  svg: ReactDOM.Style.t,
};

type t_collapseClassKey = {
  container: ReactDOM.Style.t,
  entered: ReactDOM.Style.t,
  hidden: ReactDOM.Style.t,
  wrapper: ReactDOM.Style.t,
  wrapperInner: ReactDOM.Style.t,
};

type t_containerClassKey = {
  disableGutters: ReactDOM.Style.t,
  fixed: ReactDOM.Style.t,
  maxWidthLg: ReactDOM.Style.t,
  maxWidthMd: ReactDOM.Style.t,
  maxWidthSm: ReactDOM.Style.t,
  maxWidthXl: ReactDOM.Style.t,
  maxWidthXs: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_global = {
  [@bs.as "@font-face"]
  fontFace: MaterialUi_Types.any,
};

type t_muiCssBaseline = {
  [@bs.as "@global"]
  global: t_global,
};

type t_dialogClassKey = {
  container: ReactDOM.Style.t,
  paper: ReactDOM.Style.t,
  paperFullScreen: ReactDOM.Style.t,
  paperFullWidth: ReactDOM.Style.t,
  paperScrollBody: ReactDOM.Style.t,
  paperScrollPaper: ReactDOM.Style.t,
  paperWidthFalse: ReactDOM.Style.t,
  paperWidthLg: ReactDOM.Style.t,
  paperWidthMd: ReactDOM.Style.t,
  paperWidthSm: ReactDOM.Style.t,
  paperWidthXl: ReactDOM.Style.t,
  paperWidthXs: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  scrollBody: ReactDOM.Style.t,
  scrollPaper: ReactDOM.Style.t,
};

type t_dialogContentClassKey = {
  dividers: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_muiDialogContentText = {root: ReactDOM.Style.t};

type t_muiDialogTitle = {root: ReactDOM.Style.t};

type t_dividerClassKey = {
  absolute: ReactDOM.Style.t,
  inset: ReactDOM.Style.t,
  light: ReactDOM.Style.t,
  middle: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  vertical: ReactDOM.Style.t,
};

type t_drawerClassKey = {
  docked: ReactDOM.Style.t,
  modal: ReactDOM.Style.t,
  paper: ReactDOM.Style.t,
  paperAnchorBottom: ReactDOM.Style.t,
  paperAnchorDockedBottom: ReactDOM.Style.t,
  paperAnchorDockedLeft: ReactDOM.Style.t,
  paperAnchorDockedRight: ReactDOM.Style.t,
  paperAnchorDockedTop: ReactDOM.Style.t,
  paperAnchorLeft: ReactDOM.Style.t,
  paperAnchorRight: ReactDOM.Style.t,
  paperAnchorTop: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_muiExpansionPanelDetails = {root: ReactDOM.Style.t};

type t_fabClassKey = {
  colorInherit: string,
  disabled: ReactDOM.Style.t,
  extended: ReactDOM.Style.t,
  focusVisible: ReactDOM.Style.t,
  label: ReactDOM.Style.t,
  primary: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  secondary: ReactDOM.Style.t,
  sizeMedium: ReactDOM.Style.t,
  sizeSmall: ReactDOM.Style.t,
};

type t_filledInputClassKey = {
  adornedEnd: ReactDOM.Style.t,
  adornedStart: ReactDOM.Style.t,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  focused: ReactDOM.Style.t,
  formControl: ReactDOM.Style.t,
  fullWidth: ReactDOM.Style.t,
  input: ReactDOM.Style.t,
  inputAdornedEnd: ReactDOM.Style.t,
  inputAdornedStart: ReactDOM.Style.t,
  inputHiddenLabel: ReactDOM.Style.t,
  inputMarginDense: ReactDOM.Style.t,
  inputMultiline: ReactDOM.Style.t,
  inputTypeSearch: ReactDOM.Style.t,
  marginDense: ReactDOM.Style.t,
  multiline: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  underline: ReactDOM.Style.t,
};

type t_formControlClassKey = {
  fullWidth: ReactDOM.Style.t,
  marginDense: ReactDOM.Style.t,
  marginNormal: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_formControlLabelClassKey = {
  disabled: ReactDOM.Style.t,
  label: ReactDOM.Style.t,
  labelPlacementBottom: ReactDOM.Style.t,
  labelPlacementStart: ReactDOM.Style.t,
  labelPlacementTop: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_formGroupClassKey = {
  root: ReactDOM.Style.t,
  row: ReactDOM.Style.t,
};

type t_formHelperTextClassKey = {
  contained: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  filled: ReactDOM.Style.t,
  focused: ReactDOM.Style.t,
  marginDense: ReactDOM.Style.t,
  required: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_formLabelClassKey = {
  asterisk: ReactDOM.Style.t,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  filled: ReactDOM.Style.t,
  focused: ReactDOM.Style.t,
  required: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_gridClassKey = {
  [@bs.as "align-content-xs-center"]
  alignContentXsCenter: ReactDOM.Style.t,
  [@bs.as "align-content-xs-flex-end"]
  alignContentXsFlexEnd: ReactDOM.Style.t,
  [@bs.as "align-content-xs-flex-start"]
  alignContentXsFlexStart: ReactDOM.Style.t,
  [@bs.as "align-content-xs-space-around"]
  alignContentXsSpaceAround: ReactDOM.Style.t,
  [@bs.as "align-content-xs-space-between"]
  alignContentXsSpaceBetween: ReactDOM.Style.t,
  [@bs.as "align-items-xs-baseline"]
  alignItemsXsBaseline: ReactDOM.Style.t,
  [@bs.as "align-items-xs-center"]
  alignItemsXsCenter: ReactDOM.Style.t,
  [@bs.as "align-items-xs-flex-end"]
  alignItemsXsFlexEnd: ReactDOM.Style.t,
  [@bs.as "align-items-xs-flex-start"]
  alignItemsXsFlexStart: ReactDOM.Style.t,
  container: ReactDOM.Style.t,
  [@bs.as "direction-xs-column"]
  directionXsColumn: ReactDOM.Style.t,
  [@bs.as "direction-xs-column-reverse"]
  directionXsColumnReverse: ReactDOM.Style.t,
  [@bs.as "direction-xs-row-reverse"]
  directionXsRowReverse: ReactDOM.Style.t,
  [@bs.as "grid-xs-1"]
  gridXs1: ReactDOM.Style.t,
  [@bs.as "grid-xs-10"]
  gridXs10: ReactDOM.Style.t,
  [@bs.as "grid-xs-11"]
  gridXs11: ReactDOM.Style.t,
  [@bs.as "grid-xs-12"]
  gridXs12: ReactDOM.Style.t,
  [@bs.as "grid-xs-2"]
  gridXs2: ReactDOM.Style.t,
  [@bs.as "grid-xs-3"]
  gridXs3: ReactDOM.Style.t,
  [@bs.as "grid-xs-4"]
  gridXs4: ReactDOM.Style.t,
  [@bs.as "grid-xs-5"]
  gridXs5: ReactDOM.Style.t,
  [@bs.as "grid-xs-6"]
  gridXs6: ReactDOM.Style.t,
  [@bs.as "grid-xs-7"]
  gridXs7: ReactDOM.Style.t,
  [@bs.as "grid-xs-8"]
  gridXs8: ReactDOM.Style.t,
  [@bs.as "grid-xs-9"]
  gridXs9: ReactDOM.Style.t,
  [@bs.as "grid-xs-auto"]
  gridXsAuto: ReactDOM.Style.t,
  [@bs.as "grid-xs-true"]
  gridXsTrue: ReactDOM.Style.t,
  item: ReactDOM.Style.t,
  [@bs.as "justify-xs-center"]
  justifyXsCenter: ReactDOM.Style.t,
  [@bs.as "justify-xs-flex-end"]
  justifyXsFlexEnd: ReactDOM.Style.t,
  [@bs.as "justify-xs-space-around"]
  justifyXsSpaceAround: ReactDOM.Style.t,
  [@bs.as "justify-xs-space-between"]
  justifyXsSpaceBetween: ReactDOM.Style.t,
  [@bs.as "justify-xs-space-evenly"]
  justifyXsSpaceEvenly: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  [@bs.as "spacing-xs-1"]
  spacingXs1: ReactDOM.Style.t,
  [@bs.as "spacing-xs-10"]
  spacingXs10: ReactDOM.Style.t,
  [@bs.as "spacing-xs-2"]
  spacingXs2: ReactDOM.Style.t,
  [@bs.as "spacing-xs-3"]
  spacingXs3: ReactDOM.Style.t,
  [@bs.as "spacing-xs-4"]
  spacingXs4: ReactDOM.Style.t,
  [@bs.as "spacing-xs-5"]
  spacingXs5: ReactDOM.Style.t,
  [@bs.as "spacing-xs-6"]
  spacingXs6: ReactDOM.Style.t,
  [@bs.as "spacing-xs-7"]
  spacingXs7: ReactDOM.Style.t,
  [@bs.as "spacing-xs-8"]
  spacingXs8: ReactDOM.Style.t,
  [@bs.as "spacing-xs-9"]
  spacingXs9: ReactDOM.Style.t,
  [@bs.as "wrap-xs-nowrap"]
  wrapXsNowrap: ReactDOM.Style.t,
  [@bs.as "wrap-xs-wrap-reverse"]
  wrapXsWrapReverse: ReactDOM.Style.t,
  zeroMinWidth: ReactDOM.Style.t,
};

type t_muiGridList = {root: ReactDOM.Style.t};

type t_gridListTileClassKey = {
  imgFullHeight: ReactDOM.Style.t,
  imgFullWidth: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  tile: ReactDOM.Style.t,
};

type t_gridListTileBarClassKey = {
  actionIcon: ReactDOM.Style.t,
  actionIconActionPosLeft: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  rootSubtitle: ReactDOM.Style.t,
  subtitle: ReactDOM.Style.t,
  title: ReactDOM.Style.t,
  titlePositionBottom: ReactDOM.Style.t,
  titlePositionTop: ReactDOM.Style.t,
  titleWrap: ReactDOM.Style.t,
  titleWrapActionPosLeft: ReactDOM.Style.t,
  titleWrapActionPosRight: ReactDOM.Style.t,
};

type t_svgIconClassKey = {
  colorAction: string,
  colorDisabled: string,
  colorError: string,
  colorPrimary: string,
  colorSecondary: string,
  fontSizeInherit: float,
  fontSizeLarge: float,
  fontSizeSmall: float,
  root: ReactDOM.Style.t,
};

type t_iconButtonClassKey = {
  colorInherit: string,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  edgeEnd: ReactDOM.Style.t,
  edgeStart: ReactDOM.Style.t,
  label: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  sizeSmall: ReactDOM.Style.t,
};

type t_inputClassKey = {
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  focused: ReactDOM.Style.t,
  formControl: ReactDOM.Style.t,
  fullWidth: ReactDOM.Style.t,
  input: ReactDOM.Style.t,
  inputMarginDense: ReactDOM.Style.t,
  inputMultiline: ReactDOM.Style.t,
  inputTypeSearch: ReactDOM.Style.t,
  marginDense: ReactDOM.Style.t,
  multiline: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  underline: ReactDOM.Style.t,
};

type t_inputAdornmentClassKey = {
  disablePointerEvents: ReactDOM.Style.t,
  filled: ReactDOM.Style.t,
  hiddenLabel: ReactDOM.Style.t,
  marginDense: ReactDOM.Style.t,
  positionEnd: ReactDOM.Style.t,
  positionStart: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_inputBaseClassKey = {
  adornedEnd: ReactDOM.Style.t,
  adornedStart: ReactDOM.Style.t,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  focused: ReactDOM.Style.t,
  formControl: ReactDOM.Style.t,
  fullWidth: ReactDOM.Style.t,
  input: ReactDOM.Style.t,
  inputAdornedEnd: ReactDOM.Style.t,
  inputAdornedStart: ReactDOM.Style.t,
  inputHiddenLabel: ReactDOM.Style.t,
  inputMarginDense: ReactDOM.Style.t,
  inputMultiline: ReactDOM.Style.t,
  inputTypeSearch: ReactDOM.Style.t,
  marginDense: ReactDOM.Style.t,
  multiline: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_inputLabelClassKey = {
  animated: ReactDOM.Style.t,
  asterisk: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  filled: ReactDOM.Style.t,
  focused: ReactDOM.Style.t,
  formControl: ReactDOM.Style.t,
  marginDense: ReactDOM.Style.t,
  outlined: ReactDOM.Style.t,
  required: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  shrink: ReactDOM.Style.t,
};

type t_linearProgressClassKey = {
  bar: ReactDOM.Style.t,
  bar1Buffer: ReactDOM.Style.t,
  bar1Determinate: ReactDOM.Style.t,
  bar1Indeterminate: ReactDOM.Style.t,
  bar2Buffer: ReactDOM.Style.t,
  bar2Indeterminate: ReactDOM.Style.t,
  barColorPrimary: ReactDOM.Style.t,
  barColorSecondary: ReactDOM.Style.t,
  buffer: ReactDOM.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  dashed: ReactDOM.Style.t,
  dashedColorPrimary: ReactDOM.Style.t,
  dashedColorSecondary: ReactDOM.Style.t,
  determinate: ReactDOM.Style.t,
  indeterminate: ReactDOM.Style.t,
  query: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_linkClassKey = {
  button: ReactDOM.Style.t,
  focusVisible: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  underlineAlways: ReactDOM.Style.t,
  underlineHover: ReactDOM.Style.t,
  underlineNone: ReactDOM.Style.t,
};

type t_listClassKey = {
  dense: ReactDOM.Style.t,
  padding: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  subheader: ReactDOM.Style.t,
};

type t_listItemClassKey = {
  button: ReactDOM.Style.t,
  container: ReactDOM.Style.t,
  default: ReactDOM.Style.t,
  dense: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  divider: ReactDOM.Style.t,
  focusVisible: ReactDOM.Style.t,
  gutters: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  secondaryAction: ReactDOM.Style.t,
  selected: ReactDOM.Style.t,
};

type t_listItemAvatarClassKey = {
  icon: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_listItemIconClassKey = {
  alignItemsFlexStart: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_muiListItemSecondaryAction = {root: ReactDOM.Style.t};

type t_listItemTextClassKey = {
  dense: ReactDOM.Style.t,
  inset: ReactDOM.Style.t,
  multiline: ReactDOM.Style.t,
  primary: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  secondary: ReactDOM.Style.t,
};

type t_listSubheaderClassKey = {
  colorInherit: string,
  colorPrimary: string,
  gutters: ReactDOM.Style.t,
  inset: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  sticky: ReactDOM.Style.t,
};

type t_menuClassKey = {
  list: ReactDOM.Style.t,
  paper: ReactDOM.Style.t,
};

type t_menuItemClassKey = {
  dense: ReactDOM.Style.t,
  gutters: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  selected: ReactDOM.Style.t,
};

type t_mobileStepperClassKey = {
  dot: ReactDOM.Style.t,
  dotActive: ReactDOM.Style.t,
  dots: ReactDOM.Style.t,
  positionBottom: ReactDOM.Style.t,
  positionStatic: ReactDOM.Style.t,
  positionTop: ReactDOM.Style.t,
  progress: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_nativeSelectClassKey = {
  disabled: ReactDOM.Style.t,
  filled: ReactDOM.Style.t,
  icon: ReactDOM.Style.t,
  iconFilled: ReactDOM.Style.t,
  iconOutlined: ReactDOM.Style.t,
  outlined: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  select: ReactDOM.Style.t,
  selectMenu: ReactDOM.Style.t,
};

type t_outlinedInputClassKey = {
  adornedEnd: ReactDOM.Style.t,
  adornedStart: ReactDOM.Style.t,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  focused: ReactDOM.Style.t,
  input: ReactDOM.Style.t,
  inputAdornedEnd: ReactDOM.Style.t,
  inputAdornedStart: ReactDOM.Style.t,
  inputMarginDense: ReactDOM.Style.t,
  inputMultiline: ReactDOM.Style.t,
  marginDense: ReactDOM.Style.t,
  multiline: ReactDOM.Style.t,
  notchedOutline: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_paperClassKey = {
  elevation0: ReactDOM.Style.t,
  elevation1: ReactDOM.Style.t,
  elevation10: ReactDOM.Style.t,
  elevation11: ReactDOM.Style.t,
  elevation12: ReactDOM.Style.t,
  elevation13: ReactDOM.Style.t,
  elevation14: ReactDOM.Style.t,
  elevation15: ReactDOM.Style.t,
  elevation16: ReactDOM.Style.t,
  elevation17: ReactDOM.Style.t,
  elevation18: ReactDOM.Style.t,
  elevation19: ReactDOM.Style.t,
  elevation2: ReactDOM.Style.t,
  elevation20: ReactDOM.Style.t,
  elevation21: ReactDOM.Style.t,
  elevation22: ReactDOM.Style.t,
  elevation23: ReactDOM.Style.t,
  elevation24: ReactDOM.Style.t,
  elevation3: ReactDOM.Style.t,
  elevation4: ReactDOM.Style.t,
  elevation5: ReactDOM.Style.t,
  elevation6: ReactDOM.Style.t,
  elevation7: ReactDOM.Style.t,
  elevation8: ReactDOM.Style.t,
  elevation9: ReactDOM.Style.t,
  outlined: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  rounded: ReactDOM.Style.t,
};

type t_popoverClassKey = {
  paper: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_radioClassKey = {
  checked: ReactDOM.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  input: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_muiScopedCssBaseline = {root: ReactDOM.Style.t};

type t_selectClassKey = {
  disabled: ReactDOM.Style.t,
  filled: ReactDOM.Style.t,
  icon: ReactDOM.Style.t,
  iconFilled: ReactDOM.Style.t,
  iconOpen: ReactDOM.Style.t,
  iconOutlined: ReactDOM.Style.t,
  outlined: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  select: ReactDOM.Style.t,
  selectMenu: ReactDOM.Style.t,
};

type t_sliderClassKey = {
  active: ReactDOM.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  focusVisible: ReactDOM.Style.t,
  mark: ReactDOM.Style.t,
  markActive: ReactDOM.Style.t,
  markLabel: ReactDOM.Style.t,
  markLabelActive: ReactDOM.Style.t,
  marked: ReactDOM.Style.t,
  rail: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  thumb: ReactDOM.Style.t,
  thumbColorPrimary: ReactDOM.Style.t,
  thumbColorSecondary: ReactDOM.Style.t,
  track: ReactDOM.Style.t,
  trackFalse: ReactDOM.Style.t,
  trackInverted: ReactDOM.Style.t,
  valueLabel: ReactDOM.Style.t,
  vertical: ReactDOM.Style.t,
};

type t_snackbarClassKey = {
  anchorOriginBottomCenter: ReactDOM.Style.t,
  anchorOriginBottomLeft: ReactDOM.Style.t,
  anchorOriginBottomRight: ReactDOM.Style.t,
  anchorOriginTopCenter: ReactDOM.Style.t,
  anchorOriginTopLeft: ReactDOM.Style.t,
  anchorOriginTopRight: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_snackbarContentClassKey = {
  action: ReactDOM.Style.t,
  message: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_stepClasskey = {
  alternativeLabel: ReactDOM.Style.t,
  completed: ReactDOM.Style.t,
  horizontal: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  vertical: ReactDOM.Style.t,
};

type t_stepButtonClasskey = {
  root: ReactDOM.Style.t,
  touchRipple: ReactDOM.Style.t,
  vertical: ReactDOM.Style.t,
};

type t_stepConnectorClasskey = {
  active: ReactDOM.Style.t,
  alternativeLabel: ReactDOM.Style.t,
  completed: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  horizontal: ReactDOM.Style.t,
  line: ReactDOM.Style.t,
  lineHorizontal: ReactDOM.Style.t,
  lineVertical: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  vertical: ReactDOM.Style.t,
};

type t_stepContentClasskey = {
  last: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  transition: ReactDOM.Style.t,
};

type t_stepIconClasskey = {
  active: ReactDOM.Style.t,
  completed: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  text: ReactDOM.Style.t,
};

type t_stepLabelClasskey = {
  active: ReactDOM.Style.t,
  alternativeLabel: ReactDOM.Style.t,
  completed: ReactDOM.Style.t,
  disabled: ReactDOM.Style.t,
  error: ReactDOM.Style.t,
  horizontal: ReactDOM.Style.t,
  iconContainer: ReactDOM.Style.t,
  label: ReactDOM.Style.t,
  labelContainer: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  vertical: ReactDOM.Style.t,
};

type t_stepperClasskey = {
  alternativeLabel: ReactDOM.Style.t,
  horizontal: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  vertical: ReactDOM.Style.t,
};

type t_switchClassKey = {
  checked: ReactDOM.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOM.Style.t,
  input: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  sizeSmall: ReactDOM.Style.t,
  switchBase: ReactDOM.Style.t,
  thumb: ReactDOM.Style.t,
  track: ReactDOM.Style.t,
};

type t_tabClassKey = {
  disabled: ReactDOM.Style.t,
  fullWidth: ReactDOM.Style.t,
  labelIcon: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  selected: ReactDOM.Style.t,
  textColorInherit: ReactDOM.Style.t,
  textColorPrimary: ReactDOM.Style.t,
  textColorSecondary: ReactDOM.Style.t,
  wrapped: ReactDOM.Style.t,
  wrapper: ReactDOM.Style.t,
};

type t_tableClassKey = {
  root: ReactDOM.Style.t,
  stickyHeader: ReactDOM.Style.t,
};

type t_muiTableBody = {root: ReactDOM.Style.t};

type t_tableCellClassKey = {
  alignCenter: ReactDOM.Style.t,
  alignJustify: ReactDOM.Style.t,
  alignLeft: ReactDOM.Style.t,
  alignRight: ReactDOM.Style.t,
  body: ReactDOM.Style.t,
  footer: ReactDOM.Style.t,
  head: ReactDOM.Style.t,
  paddingCheckbox: ReactDOM.Style.t,
  paddingNone: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  sizeSmall: ReactDOM.Style.t,
  stickyHeader: ReactDOM.Style.t,
};

type t_muiTableContainer = {root: ReactDOM.Style.t};

type t_muiTableFooter = {root: ReactDOM.Style.t};

type t_muiTableHead = {root: ReactDOM.Style.t};

type t_tablePaginationClassKey = {
  actions: ReactDOM.Style.t,
  caption: ReactDOM.Style.t,
  input: ReactDOM.Style.t,
  menuItem: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  select: ReactDOM.Style.t,
  selectIcon: ReactDOM.Style.t,
  selectRoot: ReactDOM.Style.t,
  spacer: ReactDOM.Style.t,
  toolbar: ReactDOM.Style.t,
};

type t_tableRowClassKey = {
  footer: ReactDOM.Style.t,
  head: ReactDOM.Style.t,
  hover: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  selected: ReactDOM.Style.t,
};

type t_tableSortLabelClassKey = {
  active: ReactDOM.Style.t,
  icon: ReactDOM.Style.t,
  iconDirectionAsc: ReactDOM.Style.t,
  iconDirectionDesc: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_tabsClassKey = {
  centered: ReactDOM.Style.t,
  fixed: ReactDOM.Style.t,
  flexContainer: ReactDOM.Style.t,
  indicator: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  scrollButtons: ReactDOM.Style.t,
  scrollButtonsDesktop: ReactDOM.Style.t,
  scrollable: ReactDOM.Style.t,
  scroller: ReactDOM.Style.t,
};

type t_muiTextField = {root: ReactDOM.Style.t};

type t_toolbarClassKey = {
  dense: ReactDOM.Style.t,
  gutters: ReactDOM.Style.t,
  regular: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_tooltipClassKey = {
  arrow: ReactDOM.Style.t,
  popper: ReactDOM.Style.t,
  popperArrow: ReactDOM.Style.t,
  popperInteractive: ReactDOM.Style.t,
  tooltip: ReactDOM.Style.t,
  tooltipArrow: ReactDOM.Style.t,
  tooltipPlacementBottom: ReactDOM.Style.t,
  tooltipPlacementLeft: ReactDOM.Style.t,
  tooltipPlacementRight: ReactDOM.Style.t,
  tooltipPlacementTop: ReactDOM.Style.t,
  touch: ReactDOM.Style.t,
};

type t_touchRippleClassKey = {
  child: ReactDOM.Style.t,
  childLeaving: ReactDOM.Style.t,
  childPulsate: ReactDOM.Style.t,
  ripple: ReactDOM.Style.t,
  ripplePulsate: ReactDOM.Style.t,
  rippleVisible: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
};

type t_typographyClassKey = {
  alignCenter: ReactDOM.Style.t,
  alignJustify: ReactDOM.Style.t,
  alignLeft: ReactDOM.Style.t,
  alignRight: ReactDOM.Style.t,
  body1: ReactDOM.Style.t,
  body2: ReactDOM.Style.t,
  button: ReactDOM.Style.t,
  caption: ReactDOM.Style.t,
  colorError: string,
  colorInherit: string,
  colorPrimary: string,
  colorSecondary: string,
  colorTextPrimary: string,
  colorTextSecondary: string,
  displayBlock: ReactDOM.Style.t,
  displayInline: ReactDOM.Style.t,
  gutterBottom: ReactDOM.Style.t,
  h1: ReactDOM.Style.t,
  h2: ReactDOM.Style.t,
  h3: ReactDOM.Style.t,
  h4: ReactDOM.Style.t,
  h5: ReactDOM.Style.t,
  h6: ReactDOM.Style.t,
  noWrap: ReactDOM.Style.t,
  overline: ReactDOM.Style.t,
  paragraph: ReactDOM.Style.t,
  root: ReactDOM.Style.t,
  srOnly: ReactDOM.Style.t,
  subtitle1: ReactDOM.Style.t,
  subtitle2: ReactDOM.Style.t,
};

type t_overrides = {
  [@bs.as "MuiAccordion"]
  muiAccordion: t_accordionClassKey,
  [@bs.as "MuiAccordionActions"]
  muiAccordionActions: t_accordionActionsClassKey,
  [@bs.as "MuiAccordionDetails"]
  muiAccordionDetails: t_muiAccordionDetails,
  [@bs.as "MuiAccordionSummary"]
  muiAccordionSummary: t_accordionSummaryClassKey,
  [@bs.as "MuiAppBar"]
  muiAppBar: t_appBarClassKey,
  [@bs.as "MuiAvatar"]
  muiAvatar: t_avatarClassKey,
  [@bs.as "MuiBackdrop"]
  muiBackdrop: t_backdropClassKey,
  [@bs.as "MuiBadge"]
  muiBadge: t_badgeClassKey,
  [@bs.as "MuiBottomNavigation"]
  muiBottomNavigation: t_muiBottomNavigation,
  [@bs.as "MuiBottomNavigationAction"]
  muiBottomNavigationAction: t_bottomNavigationActionClassKey,
  [@bs.as "MuiBreadcrumbs"]
  muiBreadcrumbs: t_breadcrumbsClassKey,
  [@bs.as "MuiButton"]
  muiButton: t_buttonClassKey,
  [@bs.as "MuiButtonBase"]
  muiButtonBase: t_buttonBaseClassKey,
  [@bs.as "MuiButtonGroup"]
  muiButtonGroup: t_buttonGroupClassKey,
  [@bs.as "MuiCard"]
  muiCard: t_muiCard,
  [@bs.as "MuiCardActionArea"]
  muiCardActionArea: t_cardActionAreaClassKey,
  [@bs.as "MuiCardActions"]
  muiCardActions: t_accordionActionsClassKey,
  [@bs.as "MuiCardContent"]
  muiCardContent: t_muiCardContent,
  [@bs.as "MuiCardHeader"]
  muiCardHeader: t_cardHeaderClassKey,
  [@bs.as "MuiCardMedia"]
  muiCardMedia: t_cardMediaClassKey,
  [@bs.as "MuiCheckbox"]
  muiCheckbox: t_checkboxClassKey,
  [@bs.as "MuiChip"]
  muiChip: t_chipClassKey,
  [@bs.as "MuiCircularProgress"]
  muiCircularProgress: t_circularProgressClassKey,
  [@bs.as "MuiCollapse"]
  muiCollapse: t_collapseClassKey,
  [@bs.as "MuiContainer"]
  muiContainer: t_containerClassKey,
  [@bs.as "MuiCssBaseline"]
  muiCssBaseline: t_muiCssBaseline,
  [@bs.as "MuiDialog"]
  muiDialog: t_dialogClassKey,
  [@bs.as "MuiDialogActions"]
  muiDialogActions: t_accordionActionsClassKey,
  [@bs.as "MuiDialogContent"]
  muiDialogContent: t_dialogContentClassKey,
  [@bs.as "MuiDialogContentText"]
  muiDialogContentText: t_muiDialogContentText,
  [@bs.as "MuiDialogTitle"]
  muiDialogTitle: t_muiDialogTitle,
  [@bs.as "MuiDivider"]
  muiDivider: t_dividerClassKey,
  [@bs.as "MuiDrawer"]
  muiDrawer: t_drawerClassKey,
  [@bs.as "MuiExpansionPanel"]
  muiExpansionPanel: t_accordionClassKey,
  [@bs.as "MuiExpansionPanelActions"]
  muiExpansionPanelActions: t_accordionActionsClassKey,
  [@bs.as "MuiExpansionPanelDetails"]
  muiExpansionPanelDetails: t_muiExpansionPanelDetails,
  [@bs.as "MuiExpansionPanelSummary"]
  muiExpansionPanelSummary: t_accordionSummaryClassKey,
  [@bs.as "MuiFab"]
  muiFab: t_fabClassKey,
  [@bs.as "MuiFilledInput"]
  muiFilledInput: t_filledInputClassKey,
  [@bs.as "MuiFormControl"]
  muiFormControl: t_formControlClassKey,
  [@bs.as "MuiFormControlLabel"]
  muiFormControlLabel: t_formControlLabelClassKey,
  [@bs.as "MuiFormGroup"]
  muiFormGroup: t_formGroupClassKey,
  [@bs.as "MuiFormHelperText"]
  muiFormHelperText: t_formHelperTextClassKey,
  [@bs.as "MuiFormLabel"]
  muiFormLabel: t_formLabelClassKey,
  [@bs.as "MuiGrid"]
  muiGrid: t_gridClassKey,
  [@bs.as "MuiGridList"]
  muiGridList: t_muiGridList,
  [@bs.as "MuiGridListTile"]
  muiGridListTile: t_gridListTileClassKey,
  [@bs.as "MuiGridListTileBar"]
  muiGridListTileBar: t_gridListTileBarClassKey,
  [@bs.as "MuiIcon"]
  muiIcon: t_svgIconClassKey,
  [@bs.as "MuiIconButton"]
  muiIconButton: t_iconButtonClassKey,
  [@bs.as "MuiInput"]
  muiInput: t_inputClassKey,
  [@bs.as "MuiInputAdornment"]
  muiInputAdornment: t_inputAdornmentClassKey,
  [@bs.as "MuiInputBase"]
  muiInputBase: t_inputBaseClassKey,
  [@bs.as "MuiInputLabel"]
  muiInputLabel: t_inputLabelClassKey,
  [@bs.as "MuiLinearProgress"]
  muiLinearProgress: t_linearProgressClassKey,
  [@bs.as "MuiLink"]
  muiLink: t_linkClassKey,
  [@bs.as "MuiList"]
  muiList: t_listClassKey,
  [@bs.as "MuiListItem"]
  muiListItem: t_listItemClassKey,
  [@bs.as "MuiListItemAvatar"]
  muiListItemAvatar: t_listItemAvatarClassKey,
  [@bs.as "MuiListItemIcon"]
  muiListItemIcon: t_listItemIconClassKey,
  [@bs.as "MuiListItemSecondaryAction"]
  muiListItemSecondaryAction: t_muiListItemSecondaryAction,
  [@bs.as "MuiListItemText"]
  muiListItemText: t_listItemTextClassKey,
  [@bs.as "MuiListSubheader"]
  muiListSubheader: t_listSubheaderClassKey,
  [@bs.as "MuiMenu"]
  muiMenu: t_menuClassKey,
  [@bs.as "MuiMenuItem"]
  muiMenuItem: t_menuItemClassKey,
  [@bs.as "MuiMobileStepper"]
  muiMobileStepper: t_mobileStepperClassKey,
  [@bs.as "MuiNativeSelect"]
  muiNativeSelect: t_nativeSelectClassKey,
  [@bs.as "MuiOutlinedInput"]
  muiOutlinedInput: t_outlinedInputClassKey,
  [@bs.as "MuiPaper"]
  muiPaper: t_paperClassKey,
  [@bs.as "MuiPopover"]
  muiPopover: t_popoverClassKey,
  [@bs.as "MuiRadio"]
  muiRadio: t_radioClassKey,
  [@bs.as "MuiScopedCssBaseline"]
  muiScopedCssBaseline: t_muiScopedCssBaseline,
  [@bs.as "MuiSelect"]
  muiSelect: t_selectClassKey,
  [@bs.as "MuiSlider"]
  muiSlider: t_sliderClassKey,
  [@bs.as "MuiSnackbar"]
  muiSnackbar: t_snackbarClassKey,
  [@bs.as "MuiSnackbarContent"]
  muiSnackbarContent: t_snackbarContentClassKey,
  [@bs.as "MuiStep"]
  muiStep: t_stepClasskey,
  [@bs.as "MuiStepButton"]
  muiStepButton: t_stepButtonClasskey,
  [@bs.as "MuiStepConnector"]
  muiStepConnector: t_stepConnectorClasskey,
  [@bs.as "MuiStepContent"]
  muiStepContent: t_stepContentClasskey,
  [@bs.as "MuiStepIcon"]
  muiStepIcon: t_stepIconClasskey,
  [@bs.as "MuiStepLabel"]
  muiStepLabel: t_stepLabelClasskey,
  [@bs.as "MuiStepper"]
  muiStepper: t_stepperClasskey,
  [@bs.as "MuiSvgIcon"]
  muiSvgIcon: t_svgIconClassKey,
  [@bs.as "MuiSwitch"]
  muiSwitch: t_switchClassKey,
  [@bs.as "MuiTab"]
  muiTab: t_tabClassKey,
  [@bs.as "MuiTable"]
  muiTable: t_tableClassKey,
  [@bs.as "MuiTableBody"]
  muiTableBody: t_muiTableBody,
  [@bs.as "MuiTableCell"]
  muiTableCell: t_tableCellClassKey,
  [@bs.as "MuiTableContainer"]
  muiTableContainer: t_muiTableContainer,
  [@bs.as "MuiTableFooter"]
  muiTableFooter: t_muiTableFooter,
  [@bs.as "MuiTableHead"]
  muiTableHead: t_muiTableHead,
  [@bs.as "MuiTablePagination"]
  muiTablePagination: t_tablePaginationClassKey,
  [@bs.as "MuiTableRow"]
  muiTableRow: t_tableRowClassKey,
  [@bs.as "MuiTableSortLabel"]
  muiTableSortLabel: t_tableSortLabelClassKey,
  [@bs.as "MuiTabs"]
  muiTabs: t_tabsClassKey,
  [@bs.as "MuiTextField"]
  muiTextField: t_muiTextField,
  [@bs.as "MuiToolbar"]
  muiToolbar: t_toolbarClassKey,
  [@bs.as "MuiTooltip"]
  muiTooltip: t_tooltipClassKey,
  [@bs.as "MuiTouchRipple"]
  muiTouchRipple: t_touchRippleClassKey,
  [@bs.as "MuiTypography"]
  muiTypography: t_typographyClassKey,
};

type t_typeAction = {
  activatedOpacity: float,
  active: string,
  disabled: string,
  disabledBackground: string,
  disabledOpacity: float,
  focus: string,
  focusOpacity: float,
  hover: string,
  hoverOpacity: float,
  selected: string,
  selectedOpacity: float,
};

type t_typeBackground = {
  default: string,
  paper: string,
};

type t_commonColors = {
  black: string,
  white: string,
};

type t_paletteColor = {
  contrastText: string,
  dark: string,
  light: string,
  main: string,
};

type t_color = {
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

type t_typeText = {
  disabled: string,
  hint: string,
  primary: string,
  secondary: string,
};

type t_tonalOffset = {
  dark: float,
  light: float,
};

type t_palette = {
  action: t_typeAction,
  augmentColor: MaterialUi_Types.any,
  background: t_typeBackground,
  common: t_commonColors,
  contrastThreshold: float,
  divider: string,
  error: t_paletteColor,
  getContrastText: MaterialUi_Types.any,
  grey: t_color,
  info: t_paletteColor,
  primary: t_paletteColor,
  secondary: t_paletteColor,
  success: t_paletteColor,
  text: t_typeText,
  tonalOffset: t_tonalOffset,
  [@bs.as "type"]
  _type: string,
  warning: t_paletteColor,
};

type t_shape = {borderRadius: float};

type t_duration = {
  complex: float,
  enteringScreen: float,
  leavingScreen: float,
  short: float,
  shorter: float,
  shortest: float,
  standard: float,
};

type t_easing = {
  easeIn: string,
  easeInOut: string,
  easeOut: string,
  sharp: string,
};

type t_transitions = {
  duration: t_duration,
  easing: t_easing,
};

type t_typography = {
  body1: ReactDOM.Style.t,
  body2: ReactDOM.Style.t,
  button: ReactDOM.Style.t,
  caption: ReactDOM.Style.t,
  fontFamily: string,
  fontSize: float,
  fontWeightBold: string,
  fontWeightLight: string,
  fontWeightMedium: string,
  fontWeightRegular: string,
  h1: ReactDOM.Style.t,
  h2: ReactDOM.Style.t,
  h3: ReactDOM.Style.t,
  h4: ReactDOM.Style.t,
  h5: ReactDOM.Style.t,
  h6: ReactDOM.Style.t,
  overline: ReactDOM.Style.t,
  pxToRem: MaterialUi_Types.any,
  subtitle1: ReactDOM.Style.t,
  subtitle2: ReactDOM.Style.t,
};

type t_zIndex = {
  appBar: float,
  drawer: float,
  mobileStepper: float,
  modal: float,
  snackbar: float,
  speedDial: float,
  tooltip: float,
};

type t_theme = {
  breakpoints: t_breakpoints,
  direction: string,
  mixins: t_mixins,
  overrides: t_overrides,
  palette: t_palette,
  props: MaterialUi_Types.any,
  shadows: array(string),
  shape: t_shape,
  spacing: int => int,
  transitions: t_transitions,
  typography: t_typography,
  unstable_strictMode: bool,
  zIndex: t_zIndex,
};
type t = t_theme;

[@bs.module "@material-ui/core/styles"]
external create: MaterialUi_ThemeOptions.t => t = "createMuiTheme";
