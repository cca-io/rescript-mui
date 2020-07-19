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
  toolbar: ReactDOMRe.Style.t,
};

type t_accordionClassKey = {
  disabled: ReactDOMRe.Style.t,
  expanded: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  rounded: ReactDOMRe.Style.t,
};

type t_accordionActionsClassKey = {
  root: ReactDOMRe.Style.t,
  spacing: ReactDOMRe.Style.t,
};

type t_muiAccordionDetails = {root: ReactDOMRe.Style.t};

type t_accordionSummaryClassKey = {
  content: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  expandIcon: ReactDOMRe.Style.t,
  expanded: ReactDOMRe.Style.t,
  focused: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_appBarClassKey = {
  colorDefault: string,
  colorPrimary: string,
  colorSecondary: string,
  positionAbsolute: ReactDOMRe.Style.t,
  positionFixed: ReactDOMRe.Style.t,
  positionRelative: ReactDOMRe.Style.t,
  positionStatic: ReactDOMRe.Style.t,
  positionSticky: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_avatarClassKey = {
  circle: ReactDOMRe.Style.t,
  colorDefault: string,
  fallback: ReactDOMRe.Style.t,
  img: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  rounded: ReactDOMRe.Style.t,
  square: ReactDOMRe.Style.t,
};

type t_backdropClassKey = {
  invisible: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_badgeClassKey = {
  anchorOriginBottomLeftRectangle: ReactDOMRe.Style.t,
  anchorOriginBottomRightCircle: ReactDOMRe.Style.t,
  anchorOriginBottomRightRectangle: ReactDOMRe.Style.t,
  anchorOriginTopLeftCircle: ReactDOMRe.Style.t,
  anchorOriginTopLeftRectangle: ReactDOMRe.Style.t,
  anchorOriginTopRightCircle: ReactDOMRe.Style.t,
  anchorOriginTopRightRectangle: ReactDOMRe.Style.t,
  badge: ReactDOMRe.Style.t,
  colorError: string,
  colorPrimary: string,
  colorSecondary: string,
  dot: ReactDOMRe.Style.t,
  invisible: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_muiBottomNavigation = {root: ReactDOMRe.Style.t};

type t_bottomNavigationActionClassKey = {
  iconOnly: ReactDOMRe.Style.t,
  label: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  selected: ReactDOMRe.Style.t,
  wrapper: ReactDOMRe.Style.t,
};

type t_breadcrumbsClassKey = {
  li: ReactDOMRe.Style.t,
  ol: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  separator: ReactDOMRe.Style.t,
};

type t_buttonClassKey = {
  colorInherit: string,
  contained: ReactDOMRe.Style.t,
  containedPrimary: ReactDOMRe.Style.t,
  containedSecondary: ReactDOMRe.Style.t,
  containedSizeLarge: ReactDOMRe.Style.t,
  containedSizeSmall: ReactDOMRe.Style.t,
  disableElevation: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  endIcon: ReactDOMRe.Style.t,
  focusVisible: ReactDOMRe.Style.t,
  fullWidth: ReactDOMRe.Style.t,
  iconSizeLarge: ReactDOMRe.Style.t,
  iconSizeMedium: ReactDOMRe.Style.t,
  iconSizeSmall: ReactDOMRe.Style.t,
  label: ReactDOMRe.Style.t,
  outlined: ReactDOMRe.Style.t,
  outlinedPrimary: ReactDOMRe.Style.t,
  outlinedSecondary: ReactDOMRe.Style.t,
  outlinedSizeLarge: ReactDOMRe.Style.t,
  outlinedSizeSmall: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  sizeLarge: ReactDOMRe.Style.t,
  sizeSmall: ReactDOMRe.Style.t,
  startIcon: ReactDOMRe.Style.t,
  text: ReactDOMRe.Style.t,
  textPrimary: ReactDOMRe.Style.t,
  textSecondary: ReactDOMRe.Style.t,
  textSizeLarge: ReactDOMRe.Style.t,
  textSizeSmall: ReactDOMRe.Style.t,
};

type t_buttonBaseClassKey = {
  disabled: ReactDOMRe.Style.t,
  focusVisible: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_buttonGroupClassKey = {
  contained: ReactDOMRe.Style.t,
  disableElevation: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  fullWidth: ReactDOMRe.Style.t,
  grouped: ReactDOMRe.Style.t,
  groupedContained: ReactDOMRe.Style.t,
  groupedContainedHorizontal: ReactDOMRe.Style.t,
  groupedContainedPrimary: ReactDOMRe.Style.t,
  groupedContainedSecondary: ReactDOMRe.Style.t,
  groupedContainedVertical: ReactDOMRe.Style.t,
  groupedHorizontal: ReactDOMRe.Style.t,
  groupedOutlined: ReactDOMRe.Style.t,
  groupedOutlinedHorizontal: ReactDOMRe.Style.t,
  groupedOutlinedPrimary: ReactDOMRe.Style.t,
  groupedOutlinedSecondary: ReactDOMRe.Style.t,
  groupedOutlinedVertical: ReactDOMRe.Style.t,
  groupedText: ReactDOMRe.Style.t,
  groupedTextHorizontal: ReactDOMRe.Style.t,
  groupedTextPrimary: ReactDOMRe.Style.t,
  groupedTextSecondary: ReactDOMRe.Style.t,
  groupedTextVertical: ReactDOMRe.Style.t,
  groupedVertical: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  vertical: ReactDOMRe.Style.t,
};

type t_muiCard = {root: ReactDOMRe.Style.t};

type t_cardActionAreaClassKey = {
  focusHighlight: ReactDOMRe.Style.t,
  focusVisible: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_muiCardContent = {root: ReactDOMRe.Style.t};

type t_cardHeaderClassKey = {
  action: ReactDOMRe.Style.t,
  avatar: ReactDOMRe.Style.t,
  content: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  subheader: ReactDOMRe.Style.t,
  title: ReactDOMRe.Style.t,
};

type t_cardMediaClassKey = {
  media: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_checkboxClassKey = {
  checked: ReactDOMRe.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  indeterminate: ReactDOMRe.Style.t,
  input: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_chipClassKey = {
  avatar: ReactDOMRe.Style.t,
  avatarColorPrimary: ReactDOMRe.Style.t,
  avatarColorSecondary: ReactDOMRe.Style.t,
  avatarSmall: ReactDOMRe.Style.t,
  clickable: ReactDOMRe.Style.t,
  clickableColorPrimary: ReactDOMRe.Style.t,
  clickableColorSecondary: ReactDOMRe.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  deletable: ReactDOMRe.Style.t,
  deletableColorPrimary: ReactDOMRe.Style.t,
  deletableColorSecondary: ReactDOMRe.Style.t,
  deleteIcon: ReactDOMRe.Style.t,
  deleteIconColorPrimary: ReactDOMRe.Style.t,
  deleteIconColorSecondary: ReactDOMRe.Style.t,
  deleteIconOutlinedColorPrimary: ReactDOMRe.Style.t,
  deleteIconOutlinedColorSecondary: ReactDOMRe.Style.t,
  deleteIconSmall: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  icon: ReactDOMRe.Style.t,
  iconColorPrimary: ReactDOMRe.Style.t,
  iconColorSecondary: ReactDOMRe.Style.t,
  iconSmall: ReactDOMRe.Style.t,
  label: ReactDOMRe.Style.t,
  labelSmall: ReactDOMRe.Style.t,
  outlined: ReactDOMRe.Style.t,
  outlinedPrimary: ReactDOMRe.Style.t,
  outlinedSecondary: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  sizeSmall: ReactDOMRe.Style.t,
};

type t_circularProgressClassKey = {
  circle: ReactDOMRe.Style.t,
  circleDisableShrink: ReactDOMRe.Style.t,
  circleIndeterminate: ReactDOMRe.Style.t,
  circleStatic: ReactDOMRe.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  indeterminate: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  static: ReactDOMRe.Style.t,
  svg: ReactDOMRe.Style.t,
};

type t_collapseClassKey = {
  container: ReactDOMRe.Style.t,
  entered: ReactDOMRe.Style.t,
  hidden: ReactDOMRe.Style.t,
  wrapper: ReactDOMRe.Style.t,
  wrapperInner: ReactDOMRe.Style.t,
};

type t_containerClassKey = {
  disableGutters: ReactDOMRe.Style.t,
  fixed: ReactDOMRe.Style.t,
  maxWidthLg: ReactDOMRe.Style.t,
  maxWidthMd: ReactDOMRe.Style.t,
  maxWidthSm: ReactDOMRe.Style.t,
  maxWidthXl: ReactDOMRe.Style.t,
  maxWidthXs: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
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
  container: ReactDOMRe.Style.t,
  paper: ReactDOMRe.Style.t,
  paperFullScreen: ReactDOMRe.Style.t,
  paperFullWidth: ReactDOMRe.Style.t,
  paperScrollBody: ReactDOMRe.Style.t,
  paperScrollPaper: ReactDOMRe.Style.t,
  paperWidthFalse: ReactDOMRe.Style.t,
  paperWidthLg: ReactDOMRe.Style.t,
  paperWidthMd: ReactDOMRe.Style.t,
  paperWidthSm: ReactDOMRe.Style.t,
  paperWidthXl: ReactDOMRe.Style.t,
  paperWidthXs: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  scrollBody: ReactDOMRe.Style.t,
  scrollPaper: ReactDOMRe.Style.t,
};

type t_dialogContentClassKey = {
  dividers: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_muiDialogContentText = {root: ReactDOMRe.Style.t};

type t_muiDialogTitle = {root: ReactDOMRe.Style.t};

type t_dividerClassKey = {
  absolute: ReactDOMRe.Style.t,
  inset: ReactDOMRe.Style.t,
  light: ReactDOMRe.Style.t,
  middle: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  vertical: ReactDOMRe.Style.t,
};

type t_drawerClassKey = {
  docked: ReactDOMRe.Style.t,
  modal: ReactDOMRe.Style.t,
  paper: ReactDOMRe.Style.t,
  paperAnchorBottom: ReactDOMRe.Style.t,
  paperAnchorDockedBottom: ReactDOMRe.Style.t,
  paperAnchorDockedLeft: ReactDOMRe.Style.t,
  paperAnchorDockedRight: ReactDOMRe.Style.t,
  paperAnchorDockedTop: ReactDOMRe.Style.t,
  paperAnchorLeft: ReactDOMRe.Style.t,
  paperAnchorRight: ReactDOMRe.Style.t,
  paperAnchorTop: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_muiExpansionPanelDetails = {root: ReactDOMRe.Style.t};

type t_fabClassKey = {
  colorInherit: string,
  disabled: ReactDOMRe.Style.t,
  extended: ReactDOMRe.Style.t,
  focusVisible: ReactDOMRe.Style.t,
  label: ReactDOMRe.Style.t,
  primary: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  secondary: ReactDOMRe.Style.t,
  sizeMedium: ReactDOMRe.Style.t,
  sizeSmall: ReactDOMRe.Style.t,
};

type t_filledInputClassKey = {
  adornedEnd: ReactDOMRe.Style.t,
  adornedStart: ReactDOMRe.Style.t,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  focused: ReactDOMRe.Style.t,
  formControl: ReactDOMRe.Style.t,
  fullWidth: ReactDOMRe.Style.t,
  input: ReactDOMRe.Style.t,
  inputAdornedEnd: ReactDOMRe.Style.t,
  inputAdornedStart: ReactDOMRe.Style.t,
  inputHiddenLabel: ReactDOMRe.Style.t,
  inputMarginDense: ReactDOMRe.Style.t,
  inputMultiline: ReactDOMRe.Style.t,
  inputTypeSearch: ReactDOMRe.Style.t,
  marginDense: ReactDOMRe.Style.t,
  multiline: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  underline: ReactDOMRe.Style.t,
};

type t_formControlClassKey = {
  fullWidth: ReactDOMRe.Style.t,
  marginDense: ReactDOMRe.Style.t,
  marginNormal: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_formControlLabelClassKey = {
  disabled: ReactDOMRe.Style.t,
  label: ReactDOMRe.Style.t,
  labelPlacementBottom: ReactDOMRe.Style.t,
  labelPlacementStart: ReactDOMRe.Style.t,
  labelPlacementTop: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_formGroupClassKey = {
  root: ReactDOMRe.Style.t,
  row: ReactDOMRe.Style.t,
};

type t_formHelperTextClassKey = {
  contained: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  filled: ReactDOMRe.Style.t,
  focused: ReactDOMRe.Style.t,
  marginDense: ReactDOMRe.Style.t,
  required: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_formLabelClassKey = {
  asterisk: ReactDOMRe.Style.t,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  filled: ReactDOMRe.Style.t,
  focused: ReactDOMRe.Style.t,
  required: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_gridClassKey = {
  [@bs.as "align-content-xs-center"]
  alignContentXsCenter: ReactDOMRe.Style.t,
  [@bs.as "align-content-xs-flex-end"]
  alignContentXsFlexEnd: ReactDOMRe.Style.t,
  [@bs.as "align-content-xs-flex-start"]
  alignContentXsFlexStart: ReactDOMRe.Style.t,
  [@bs.as "align-content-xs-space-around"]
  alignContentXsSpaceAround: ReactDOMRe.Style.t,
  [@bs.as "align-content-xs-space-between"]
  alignContentXsSpaceBetween: ReactDOMRe.Style.t,
  [@bs.as "align-items-xs-baseline"]
  alignItemsXsBaseline: ReactDOMRe.Style.t,
  [@bs.as "align-items-xs-center"]
  alignItemsXsCenter: ReactDOMRe.Style.t,
  [@bs.as "align-items-xs-flex-end"]
  alignItemsXsFlexEnd: ReactDOMRe.Style.t,
  [@bs.as "align-items-xs-flex-start"]
  alignItemsXsFlexStart: ReactDOMRe.Style.t,
  container: ReactDOMRe.Style.t,
  [@bs.as "direction-xs-column"]
  directionXsColumn: ReactDOMRe.Style.t,
  [@bs.as "direction-xs-column-reverse"]
  directionXsColumnReverse: ReactDOMRe.Style.t,
  [@bs.as "direction-xs-row-reverse"]
  directionXsRowReverse: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-1"]
  gridXs1: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-10"]
  gridXs10: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-11"]
  gridXs11: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-12"]
  gridXs12: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-2"]
  gridXs2: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-3"]
  gridXs3: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-4"]
  gridXs4: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-5"]
  gridXs5: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-6"]
  gridXs6: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-7"]
  gridXs7: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-8"]
  gridXs8: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-9"]
  gridXs9: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-auto"]
  gridXsAuto: ReactDOMRe.Style.t,
  [@bs.as "grid-xs-true"]
  gridXsTrue: ReactDOMRe.Style.t,
  item: ReactDOMRe.Style.t,
  [@bs.as "justify-xs-center"]
  justifyXsCenter: ReactDOMRe.Style.t,
  [@bs.as "justify-xs-flex-end"]
  justifyXsFlexEnd: ReactDOMRe.Style.t,
  [@bs.as "justify-xs-space-around"]
  justifyXsSpaceAround: ReactDOMRe.Style.t,
  [@bs.as "justify-xs-space-between"]
  justifyXsSpaceBetween: ReactDOMRe.Style.t,
  [@bs.as "justify-xs-space-evenly"]
  justifyXsSpaceEvenly: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-1"]
  spacingXs1: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-10"]
  spacingXs10: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-2"]
  spacingXs2: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-3"]
  spacingXs3: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-4"]
  spacingXs4: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-5"]
  spacingXs5: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-6"]
  spacingXs6: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-7"]
  spacingXs7: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-8"]
  spacingXs8: ReactDOMRe.Style.t,
  [@bs.as "spacing-xs-9"]
  spacingXs9: ReactDOMRe.Style.t,
  [@bs.as "wrap-xs-nowrap"]
  wrapXsNowrap: ReactDOMRe.Style.t,
  [@bs.as "wrap-xs-wrap-reverse"]
  wrapXsWrapReverse: ReactDOMRe.Style.t,
  zeroMinWidth: ReactDOMRe.Style.t,
};

type t_muiGridList = {root: ReactDOMRe.Style.t};

type t_gridListTileClassKey = {
  imgFullHeight: ReactDOMRe.Style.t,
  imgFullWidth: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  tile: ReactDOMRe.Style.t,
};

type t_gridListTileBarClassKey = {
  actionIcon: ReactDOMRe.Style.t,
  actionIconActionPosLeft: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  rootSubtitle: ReactDOMRe.Style.t,
  subtitle: ReactDOMRe.Style.t,
  title: ReactDOMRe.Style.t,
  titlePositionBottom: ReactDOMRe.Style.t,
  titlePositionTop: ReactDOMRe.Style.t,
  titleWrap: ReactDOMRe.Style.t,
  titleWrapActionPosLeft: ReactDOMRe.Style.t,
  titleWrapActionPosRight: ReactDOMRe.Style.t,
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
  root: ReactDOMRe.Style.t,
};

type t_iconButtonClassKey = {
  colorInherit: string,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  edgeEnd: ReactDOMRe.Style.t,
  edgeStart: ReactDOMRe.Style.t,
  label: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  sizeSmall: ReactDOMRe.Style.t,
};

type t_inputClassKey = {
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  focused: ReactDOMRe.Style.t,
  formControl: ReactDOMRe.Style.t,
  fullWidth: ReactDOMRe.Style.t,
  input: ReactDOMRe.Style.t,
  inputMarginDense: ReactDOMRe.Style.t,
  inputMultiline: ReactDOMRe.Style.t,
  inputTypeSearch: ReactDOMRe.Style.t,
  marginDense: ReactDOMRe.Style.t,
  multiline: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  underline: ReactDOMRe.Style.t,
};

type t_inputAdornmentClassKey = {
  disablePointerEvents: ReactDOMRe.Style.t,
  filled: ReactDOMRe.Style.t,
  hiddenLabel: ReactDOMRe.Style.t,
  marginDense: ReactDOMRe.Style.t,
  positionEnd: ReactDOMRe.Style.t,
  positionStart: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_inputBaseClassKey = {
  adornedEnd: ReactDOMRe.Style.t,
  adornedStart: ReactDOMRe.Style.t,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  focused: ReactDOMRe.Style.t,
  formControl: ReactDOMRe.Style.t,
  fullWidth: ReactDOMRe.Style.t,
  input: ReactDOMRe.Style.t,
  inputAdornedEnd: ReactDOMRe.Style.t,
  inputAdornedStart: ReactDOMRe.Style.t,
  inputHiddenLabel: ReactDOMRe.Style.t,
  inputMarginDense: ReactDOMRe.Style.t,
  inputMultiline: ReactDOMRe.Style.t,
  inputTypeSearch: ReactDOMRe.Style.t,
  marginDense: ReactDOMRe.Style.t,
  multiline: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_inputLabelClassKey = {
  animated: ReactDOMRe.Style.t,
  asterisk: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  filled: ReactDOMRe.Style.t,
  focused: ReactDOMRe.Style.t,
  formControl: ReactDOMRe.Style.t,
  marginDense: ReactDOMRe.Style.t,
  outlined: ReactDOMRe.Style.t,
  required: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  shrink: ReactDOMRe.Style.t,
};

type t_linearProgressClassKey = {
  bar: ReactDOMRe.Style.t,
  bar1Buffer: ReactDOMRe.Style.t,
  bar1Determinate: ReactDOMRe.Style.t,
  bar1Indeterminate: ReactDOMRe.Style.t,
  bar2Buffer: ReactDOMRe.Style.t,
  bar2Indeterminate: ReactDOMRe.Style.t,
  barColorPrimary: ReactDOMRe.Style.t,
  barColorSecondary: ReactDOMRe.Style.t,
  buffer: ReactDOMRe.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  dashed: ReactDOMRe.Style.t,
  dashedColorPrimary: ReactDOMRe.Style.t,
  dashedColorSecondary: ReactDOMRe.Style.t,
  determinate: ReactDOMRe.Style.t,
  indeterminate: ReactDOMRe.Style.t,
  query: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_linkClassKey = {
  button: ReactDOMRe.Style.t,
  focusVisible: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  underlineAlways: ReactDOMRe.Style.t,
  underlineHover: ReactDOMRe.Style.t,
  underlineNone: ReactDOMRe.Style.t,
};

type t_listClassKey = {
  dense: ReactDOMRe.Style.t,
  padding: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  subheader: ReactDOMRe.Style.t,
};

type t_listItemClassKey = {
  button: ReactDOMRe.Style.t,
  container: ReactDOMRe.Style.t,
  default: ReactDOMRe.Style.t,
  dense: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  divider: ReactDOMRe.Style.t,
  focusVisible: ReactDOMRe.Style.t,
  gutters: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  secondaryAction: ReactDOMRe.Style.t,
  selected: ReactDOMRe.Style.t,
};

type t_listItemAvatarClassKey = {
  icon: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_listItemIconClassKey = {
  alignItemsFlexStart: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_muiListItemSecondaryAction = {root: ReactDOMRe.Style.t};

type t_listItemTextClassKey = {
  dense: ReactDOMRe.Style.t,
  inset: ReactDOMRe.Style.t,
  multiline: ReactDOMRe.Style.t,
  primary: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  secondary: ReactDOMRe.Style.t,
};

type t_listSubheaderClassKey = {
  colorInherit: string,
  colorPrimary: string,
  gutters: ReactDOMRe.Style.t,
  inset: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  sticky: ReactDOMRe.Style.t,
};

type t_menuClassKey = {
  list: ReactDOMRe.Style.t,
  paper: ReactDOMRe.Style.t,
};

type t_menuItemClassKey = {
  dense: ReactDOMRe.Style.t,
  gutters: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  selected: ReactDOMRe.Style.t,
};

type t_mobileStepperClassKey = {
  dot: ReactDOMRe.Style.t,
  dotActive: ReactDOMRe.Style.t,
  dots: ReactDOMRe.Style.t,
  positionBottom: ReactDOMRe.Style.t,
  positionStatic: ReactDOMRe.Style.t,
  positionTop: ReactDOMRe.Style.t,
  progress: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_nativeSelectClassKey = {
  disabled: ReactDOMRe.Style.t,
  filled: ReactDOMRe.Style.t,
  icon: ReactDOMRe.Style.t,
  iconFilled: ReactDOMRe.Style.t,
  iconOutlined: ReactDOMRe.Style.t,
  outlined: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  select: ReactDOMRe.Style.t,
  selectMenu: ReactDOMRe.Style.t,
};

type t_outlinedInputClassKey = {
  adornedEnd: ReactDOMRe.Style.t,
  adornedStart: ReactDOMRe.Style.t,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  focused: ReactDOMRe.Style.t,
  input: ReactDOMRe.Style.t,
  inputAdornedEnd: ReactDOMRe.Style.t,
  inputAdornedStart: ReactDOMRe.Style.t,
  inputMarginDense: ReactDOMRe.Style.t,
  inputMultiline: ReactDOMRe.Style.t,
  marginDense: ReactDOMRe.Style.t,
  multiline: ReactDOMRe.Style.t,
  notchedOutline: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_paperClassKey = {
  elevation0: ReactDOMRe.Style.t,
  elevation1: ReactDOMRe.Style.t,
  elevation10: ReactDOMRe.Style.t,
  elevation11: ReactDOMRe.Style.t,
  elevation12: ReactDOMRe.Style.t,
  elevation13: ReactDOMRe.Style.t,
  elevation14: ReactDOMRe.Style.t,
  elevation15: ReactDOMRe.Style.t,
  elevation16: ReactDOMRe.Style.t,
  elevation17: ReactDOMRe.Style.t,
  elevation18: ReactDOMRe.Style.t,
  elevation19: ReactDOMRe.Style.t,
  elevation2: ReactDOMRe.Style.t,
  elevation20: ReactDOMRe.Style.t,
  elevation21: ReactDOMRe.Style.t,
  elevation22: ReactDOMRe.Style.t,
  elevation23: ReactDOMRe.Style.t,
  elevation24: ReactDOMRe.Style.t,
  elevation3: ReactDOMRe.Style.t,
  elevation4: ReactDOMRe.Style.t,
  elevation5: ReactDOMRe.Style.t,
  elevation6: ReactDOMRe.Style.t,
  elevation7: ReactDOMRe.Style.t,
  elevation8: ReactDOMRe.Style.t,
  elevation9: ReactDOMRe.Style.t,
  outlined: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  rounded: ReactDOMRe.Style.t,
};

type t_popoverClassKey = {
  paper: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_radioClassKey = {
  checked: ReactDOMRe.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  input: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_muiScopedCssBaseline = {root: ReactDOMRe.Style.t};

type t_selectClassKey = {
  disabled: ReactDOMRe.Style.t,
  filled: ReactDOMRe.Style.t,
  icon: ReactDOMRe.Style.t,
  iconFilled: ReactDOMRe.Style.t,
  iconOpen: ReactDOMRe.Style.t,
  iconOutlined: ReactDOMRe.Style.t,
  outlined: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  select: ReactDOMRe.Style.t,
  selectMenu: ReactDOMRe.Style.t,
};

type t_sliderClassKey = {
  active: ReactDOMRe.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  focusVisible: ReactDOMRe.Style.t,
  mark: ReactDOMRe.Style.t,
  markActive: ReactDOMRe.Style.t,
  markLabel: ReactDOMRe.Style.t,
  markLabelActive: ReactDOMRe.Style.t,
  marked: ReactDOMRe.Style.t,
  rail: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  thumb: ReactDOMRe.Style.t,
  thumbColorPrimary: ReactDOMRe.Style.t,
  thumbColorSecondary: ReactDOMRe.Style.t,
  track: ReactDOMRe.Style.t,
  trackFalse: ReactDOMRe.Style.t,
  trackInverted: ReactDOMRe.Style.t,
  valueLabel: ReactDOMRe.Style.t,
  vertical: ReactDOMRe.Style.t,
};

type t_snackbarClassKey = {
  anchorOriginBottomCenter: ReactDOMRe.Style.t,
  anchorOriginBottomLeft: ReactDOMRe.Style.t,
  anchorOriginBottomRight: ReactDOMRe.Style.t,
  anchorOriginTopCenter: ReactDOMRe.Style.t,
  anchorOriginTopLeft: ReactDOMRe.Style.t,
  anchorOriginTopRight: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_snackbarContentClassKey = {
  action: ReactDOMRe.Style.t,
  message: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_stepClasskey = {
  alternativeLabel: ReactDOMRe.Style.t,
  completed: ReactDOMRe.Style.t,
  horizontal: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  vertical: ReactDOMRe.Style.t,
};

type t_stepButtonClasskey = {
  root: ReactDOMRe.Style.t,
  touchRipple: ReactDOMRe.Style.t,
  vertical: ReactDOMRe.Style.t,
};

type t_stepConnectorClasskey = {
  active: ReactDOMRe.Style.t,
  alternativeLabel: ReactDOMRe.Style.t,
  completed: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  horizontal: ReactDOMRe.Style.t,
  line: ReactDOMRe.Style.t,
  lineHorizontal: ReactDOMRe.Style.t,
  lineVertical: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  vertical: ReactDOMRe.Style.t,
};

type t_stepContentClasskey = {
  last: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  transition: ReactDOMRe.Style.t,
};

type t_stepIconClasskey = {
  active: ReactDOMRe.Style.t,
  completed: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  text: ReactDOMRe.Style.t,
};

type t_stepLabelClasskey = {
  active: ReactDOMRe.Style.t,
  alternativeLabel: ReactDOMRe.Style.t,
  completed: ReactDOMRe.Style.t,
  disabled: ReactDOMRe.Style.t,
  error: ReactDOMRe.Style.t,
  horizontal: ReactDOMRe.Style.t,
  iconContainer: ReactDOMRe.Style.t,
  label: ReactDOMRe.Style.t,
  labelContainer: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  vertical: ReactDOMRe.Style.t,
};

type t_stepperClasskey = {
  alternativeLabel: ReactDOMRe.Style.t,
  horizontal: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  vertical: ReactDOMRe.Style.t,
};

type t_switchClassKey = {
  checked: ReactDOMRe.Style.t,
  colorPrimary: string,
  colorSecondary: string,
  disabled: ReactDOMRe.Style.t,
  input: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  sizeSmall: ReactDOMRe.Style.t,
  switchBase: ReactDOMRe.Style.t,
  thumb: ReactDOMRe.Style.t,
  track: ReactDOMRe.Style.t,
};

type t_tabClassKey = {
  disabled: ReactDOMRe.Style.t,
  fullWidth: ReactDOMRe.Style.t,
  labelIcon: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  selected: ReactDOMRe.Style.t,
  textColorInherit: ReactDOMRe.Style.t,
  textColorPrimary: ReactDOMRe.Style.t,
  textColorSecondary: ReactDOMRe.Style.t,
  wrapped: ReactDOMRe.Style.t,
  wrapper: ReactDOMRe.Style.t,
};

type t_tableClassKey = {
  root: ReactDOMRe.Style.t,
  stickyHeader: ReactDOMRe.Style.t,
};

type t_muiTableBody = {root: ReactDOMRe.Style.t};

type t_tableCellClassKey = {
  alignCenter: ReactDOMRe.Style.t,
  alignJustify: ReactDOMRe.Style.t,
  alignLeft: ReactDOMRe.Style.t,
  alignRight: ReactDOMRe.Style.t,
  body: ReactDOMRe.Style.t,
  footer: ReactDOMRe.Style.t,
  head: ReactDOMRe.Style.t,
  paddingCheckbox: ReactDOMRe.Style.t,
  paddingNone: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  sizeSmall: ReactDOMRe.Style.t,
  stickyHeader: ReactDOMRe.Style.t,
};

type t_muiTableContainer = {root: ReactDOMRe.Style.t};

type t_muiTableFooter = {root: ReactDOMRe.Style.t};

type t_muiTableHead = {root: ReactDOMRe.Style.t};

type t_tablePaginationClassKey = {
  actions: ReactDOMRe.Style.t,
  caption: ReactDOMRe.Style.t,
  input: ReactDOMRe.Style.t,
  menuItem: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  select: ReactDOMRe.Style.t,
  selectIcon: ReactDOMRe.Style.t,
  selectRoot: ReactDOMRe.Style.t,
  spacer: ReactDOMRe.Style.t,
  toolbar: ReactDOMRe.Style.t,
};

type t_tableRowClassKey = {
  footer: ReactDOMRe.Style.t,
  head: ReactDOMRe.Style.t,
  hover: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  selected: ReactDOMRe.Style.t,
};

type t_tableSortLabelClassKey = {
  active: ReactDOMRe.Style.t,
  icon: ReactDOMRe.Style.t,
  iconDirectionAsc: ReactDOMRe.Style.t,
  iconDirectionDesc: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_tabsClassKey = {
  centered: ReactDOMRe.Style.t,
  fixed: ReactDOMRe.Style.t,
  flexContainer: ReactDOMRe.Style.t,
  indicator: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  scrollButtons: ReactDOMRe.Style.t,
  scrollButtonsDesktop: ReactDOMRe.Style.t,
  scrollable: ReactDOMRe.Style.t,
  scroller: ReactDOMRe.Style.t,
};

type t_muiTextField = {root: ReactDOMRe.Style.t};

type t_toolbarClassKey = {
  dense: ReactDOMRe.Style.t,
  gutters: ReactDOMRe.Style.t,
  regular: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_tooltipClassKey = {
  arrow: ReactDOMRe.Style.t,
  popper: ReactDOMRe.Style.t,
  popperArrow: ReactDOMRe.Style.t,
  popperInteractive: ReactDOMRe.Style.t,
  tooltip: ReactDOMRe.Style.t,
  tooltipArrow: ReactDOMRe.Style.t,
  tooltipPlacementBottom: ReactDOMRe.Style.t,
  tooltipPlacementLeft: ReactDOMRe.Style.t,
  tooltipPlacementRight: ReactDOMRe.Style.t,
  tooltipPlacementTop: ReactDOMRe.Style.t,
  touch: ReactDOMRe.Style.t,
};

type t_touchRippleClassKey = {
  child: ReactDOMRe.Style.t,
  childLeaving: ReactDOMRe.Style.t,
  childPulsate: ReactDOMRe.Style.t,
  ripple: ReactDOMRe.Style.t,
  ripplePulsate: ReactDOMRe.Style.t,
  rippleVisible: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
};

type t_typographyClassKey = {
  alignCenter: ReactDOMRe.Style.t,
  alignJustify: ReactDOMRe.Style.t,
  alignLeft: ReactDOMRe.Style.t,
  alignRight: ReactDOMRe.Style.t,
  body1: ReactDOMRe.Style.t,
  body2: ReactDOMRe.Style.t,
  button: ReactDOMRe.Style.t,
  caption: ReactDOMRe.Style.t,
  colorError: string,
  colorInherit: string,
  colorPrimary: string,
  colorSecondary: string,
  colorTextPrimary: string,
  colorTextSecondary: string,
  displayBlock: ReactDOMRe.Style.t,
  displayInline: ReactDOMRe.Style.t,
  gutterBottom: ReactDOMRe.Style.t,
  h1: ReactDOMRe.Style.t,
  h2: ReactDOMRe.Style.t,
  h3: ReactDOMRe.Style.t,
  h4: ReactDOMRe.Style.t,
  h5: ReactDOMRe.Style.t,
  h6: ReactDOMRe.Style.t,
  noWrap: ReactDOMRe.Style.t,
  overline: ReactDOMRe.Style.t,
  paragraph: ReactDOMRe.Style.t,
  root: ReactDOMRe.Style.t,
  srOnly: ReactDOMRe.Style.t,
  subtitle1: ReactDOMRe.Style.t,
  subtitle2: ReactDOMRe.Style.t,
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
  body1: ReactDOMRe.Style.t,
  body2: ReactDOMRe.Style.t,
  button: ReactDOMRe.Style.t,
  caption: ReactDOMRe.Style.t,
  fontFamily: string,
  fontSize: float,
  fontWeightBold: string,
  fontWeightLight: string,
  fontWeightMedium: string,
  fontWeightRegular: string,
  h1: ReactDOMRe.Style.t,
  h2: ReactDOMRe.Style.t,
  h3: ReactDOMRe.Style.t,
  h4: ReactDOMRe.Style.t,
  h5: ReactDOMRe.Style.t,
  h6: ReactDOMRe.Style.t,
  overline: ReactDOMRe.Style.t,
  pxToRem: MaterialUi_Types.any,
  subtitle1: ReactDOMRe.Style.t,
  subtitle2: ReactDOMRe.Style.t,
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
