// This file is generated automatically by helpers/src/GenerateOverrides.res. Do not edit manually!

type component<'classKey, 'props> = {
  defaultProps?: 'props,
  styleOverrides?: 'classKey,
}

type loadingButtonClassKey = {
  loading?: ReactDOM.Style.t,
  loadingIndicator?: ReactDOM.Style.t,
  loadingIndicatorCenter?: ReactDOM.Style.t,
  loadingIndicatorStart?: ReactDOM.Style.t,
  loadingIndicatorEnd?: ReactDOM.Style.t,
  endIconLoadingEnd?: ReactDOM.Style.t,
  startIconLoadingStart?: ReactDOM.Style.t,
}

type masonryClassKey = {root?: ReactDOM.Style.t}

type tabListClassKey = {
  root?: ReactDOM.Style.t,
  vertical?: ReactDOM.Style.t,
  flexContainer?: ReactDOM.Style.t,
  flexContainerVertical?: ReactDOM.Style.t,
  centered?: ReactDOM.Style.t,
  scroller?: ReactDOM.Style.t,
  fixed?: ReactDOM.Style.t,
  scrollableX?: ReactDOM.Style.t,
  scrollableY?: ReactDOM.Style.t,
  hideScrollbar?: ReactDOM.Style.t,
  scrollButtons?: ReactDOM.Style.t,
  scrollButtonsHideMobile?: ReactDOM.Style.t,
  indicator?: ReactDOM.Style.t,
}

type tabPanelClassKey = {root?: ReactDOM.Style.t}

type timelineClassKey = {
  root?: ReactDOM.Style.t,
  positionLeft?: ReactDOM.Style.t,
  positionRight?: ReactDOM.Style.t,
  positionAlternate?: ReactDOM.Style.t,
  positionAlternateReverse?: ReactDOM.Style.t,
}

type timelineConnectorClassKey = {root?: ReactDOM.Style.t}

type timelineContentClassKey = {
  root?: ReactDOM.Style.t,
  positionRight?: ReactDOM.Style.t,
  positionLeft?: ReactDOM.Style.t,
  positionAlternate?: ReactDOM.Style.t,
  positionAlternateReverse?: ReactDOM.Style.t,
}

type timelineDotClassKey = {
  root?: ReactDOM.Style.t,
  filled?: ReactDOM.Style.t,
  outlined?: ReactDOM.Style.t,
  filledGrey?: ReactDOM.Style.t,
  outlinedGrey?: ReactDOM.Style.t,
  filledPrimary?: ReactDOM.Style.t,
  outlinedPrimary?: ReactDOM.Style.t,
  filledSecondary?: ReactDOM.Style.t,
  outlinedSecondary?: ReactDOM.Style.t,
}

type timelineItemClassKey = {
  root?: ReactDOM.Style.t,
  positionLeft?: ReactDOM.Style.t,
  positionRight?: ReactDOM.Style.t,
  positionAlternate?: ReactDOM.Style.t,
  positionAlternateReverse?: ReactDOM.Style.t,
  missingOppositeContent?: ReactDOM.Style.t,
}

type timelineOppositeContentClassKey = {
  root?: ReactDOM.Style.t,
  positionRight?: ReactDOM.Style.t,
  positionLeft?: ReactDOM.Style.t,
  positionAlternate?: ReactDOM.Style.t,
  positionAlternateReverse?: ReactDOM.Style.t,
}

type timelineSeparatorClassKey = {root?: ReactDOM.Style.t}

type treeItemClassKey = {
  root?: ReactDOM.Style.t,
  group?: ReactDOM.Style.t,
  content?: ReactDOM.Style.t,
  expanded?: ReactDOM.Style.t,
  selected?: ReactDOM.Style.t,
  focused?: ReactDOM.Style.t,
  disabled?: ReactDOM.Style.t,
  iconContainer?: ReactDOM.Style.t,
  label?: ReactDOM.Style.t,
}

type treeViewClassKey = {root?: ReactDOM.Style.t}

type t = {
  @as("MuiLoadingButton") muiLoadingButton?: component<loadingButtonClassKey, LoadingButton.props>,
  @as("MuiMasonry") muiMasonry?: component<masonryClassKey, Masonry.props>,
  @as("MuiTabList") muiTabList?: component<tabListClassKey, TabList.props<unknown>>,
  @as("MuiTabPanel") muiTabPanel?: component<tabPanelClassKey, TabPanel.props>,
  @as("MuiTimeline") muiTimeline?: component<timelineClassKey, Timeline.props>,
  @as("MuiTimelineConnector")
  muiTimelineConnector?: component<timelineConnectorClassKey, TimelineConnector.props>,
  @as("MuiTimelineContent")
  muiTimelineContent?: component<timelineContentClassKey, TimelineContent.props>,
  @as("MuiTimelineDot") muiTimelineDot?: component<timelineDotClassKey, TimelineDot.props>,
  @as("MuiTimelineItem") muiTimelineItem?: component<timelineItemClassKey, TimelineItem.props>,
  @as("MuiTimelineOppositeContent")
  muiTimelineOppositeContent?: component<
    timelineOppositeContentClassKey,
    TimelineOppositeContent.props,
  >,
  @as("MuiTimelineSeparator")
  muiTimelineSeparator?: component<timelineSeparatorClassKey, TimelineSeparator.props>,
  @as("MuiTreeItem") muiTreeItem?: component<treeItemClassKey, TreeItem.props>,
  @as("MuiTreeView") muiTreeView?: component<treeViewClassKey, TreeView.props>,
}
