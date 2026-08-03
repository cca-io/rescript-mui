type classes = {
  root?: string,
  section?: string,
  sectionContent?: string,
}

type sectionElement = {
  container: {.},
  content: {.},
  before: {.},
  after: {.},
}

type refData

type props = {
  ...Mui.CommonProps.t_NoRef,
  ref?: ReactDOM.domRef,
  tabIndex?: int,
  elements: array<sectionElement>,
  sectionListRef: React.ref<refData>,
  contentEditable: bool,
  slots?: {.},
  slotProps?: {.},
  classes?: classes,
}

@module("@mui/x-date-pickers")
external make: React.component<props> = "Unstable_PickersSectionList"
