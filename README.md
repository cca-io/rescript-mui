# ReScript Bindings for MUI (WIP!)

## Installation

```sh
COMING SOON!
```

This library provides [ReScript](https://rescript-lang.org/) bindings for
[MUI](https://mui.com/). From now on, bindings are hand-written and manually maintained.

These bindings will only work with ReScript 11 and JSX mode version 4, as it enables us to utilize [untagged variants](https://rescript-lang.org/blog/improving-interop#untagged-variants), optional record fields, or record props spread. The latter is especially important, as we are finally able to inherit props from one component to another more easily.

# What happened to the bindings for Material-UI 4?

They are still available, check out the old website: https://rescript-material-ui.cca.io/.

# Why no new website?

1. One of the goals of this rewrite is to make the usage of MUI in ReScript more accessible. In the best case you never need to leave your editor, since now we have doc comments for every property.
2. It just takes too much time to maintain.
3. In our opinion, it is much more useful (albeit not as pretty) to just have a look at the [examples folder](./examples/).

# What's inside?

| MUI package         | ReScript bindings package    | Progress |
| ------------------- | ---------------------------- | -------: |
| @mui/material       | @rescript-mui/material       |     50 % |
| @mui/lab            | @rescript-mui/lab            |      0 % |
| @mui/x-date-pickers | @rescript-mui/x-date-pickers |      0 % |
| @mui/base           | Not implemented!             |        - |
| @mui/joy            | Not implemented!             |        - |
| @mui/system         | Not implemented!             |        - |
| @mui/x-data-grid    | Not implemented!             |        - |

NOTE: "@mui/styles" will never be implemented, as it is the legacy styling solution which is not compatible with `React.StrictMode` or React 18.

# Progress

## MUI-Material

### Components

- [x] Accordion
- [x] AccordionActions
- [x] AccordionDetails
- [x] AccordionSummary
- [ ] Alert
- [ ] AlertTitle
- [ ] AppBar
- [x] Autocomplete
- [ ] Avatar
- [ ] AvatarGroup
- [x] Backdrop
- [x] Badge
- [ ] BottomNavigation
- [ ] BottomNavigationAction
- [x] Box
- [ ] Breadcrumbs
- [x] Button
- [x] ButtonBase
- [x] ButtonGroup
- [ ] Card
- [ ] CardActionArea
- [ ] CardActions
- [ ] CardContent
- [ ] CardHeader
- [ ] CardMedia
- [ ] Checkbox
- [x] Chip
- [ ] CircularProgress
- [ ] Collapse
- [ ] Container
- [ ] CssBaseline
- [x] Dialog
- [x] DialogActions
- [x] DialogContent
- [x] DialogContentText
- [x] DialogTitle
- [ ] Divider
- [x] Drawer
- [x] Fab
- [x] Fade
- [x] FilledInput
- [x] FormControl
- [x] FormControlLabel
- [ ] FormGroup
- [x] FormHelperText
- [ ] FormLabel
- [ ] GlobalStyles
- [x] Grid
- [ ] Grow
- [ ] Hidden
- [x] Icon
- [x] IconButton
- [ ] ImageList
- [ ] ImageListItem
- [ ] ImageListItemBar
- [x] Input
- [x] InputAdornment
- [x] InputBase
- [x] InputLabel
- [ ] LinearProgress
- [x] Link
- [x] List
- [ ] ListItem
- [ ] ListItemAvatar
- [ ] ListItemButton
- [x] ListItemIcon
- [ ] ListItemSecondaryAction
- [ ] ListItemText
- [ ] ListSubheader
- [x] Menu
- [x] MenuItem
- [x] MenuList
- [ ] MobileStepper
- [x] Modal
- [ ] NativeSelect
- [x] OutlinedInput
- [x] Pagination
- [ ] PaginationItem
- [x] Paper
- [ ] Popover
- [x] Popper
- [ ] Radio
- [ ] RadioGroup
- [x] Rating
- [ ] ScopedCssBaseline
- [x] Select
- [x] Skeleton
- [x] Slide
- [ ] Slider
- [ ] Snackbar
- [ ] SnackbarContent
- [ ] SpeedDial
- [x] SpeedDialAction
- [x] SpeedDialIcon
- [ ] Stack
- [x] Step
- [x] StepButton
- [x] StepConnector
- [x] StepContent
- [x] StepIcon
- [x] StepLabel
- [x] Stepper
- [x] StyledEngineProvider
- [x] SvgIcon
- [ ] Switch
- [x] Tab
- [ ] Table
- [ ] TableBody
- [ ] TableCell
- [ ] TableContainer
- [ ] TableFooter
- [ ] TableHead
- [ ] TablePagination
- [ ] TableRow
- [ ] TableSortLabel
- [x] Tabs
- [ ] TabScrollButton
- [x] TextField
- [ ] ToggleButton
- [ ] ToggleButtonGroup
- [ ] Toolbar
- [x] Tooltip
- [x] Typography
- [ ] Zoom

### Theming

- [x] Theme
- [x] ThemeHelpers
- [x] ThemeOptions
- [x] ThemeProvider

## MUI-LAB

- [ ] LoadingButton
- [ ] Masonry
- [ ] TabContext
- [ ] TabList
- [ ] TabPanel
- [ ] Timeline
- [ ] TimelineConnector
- [ ] TimelineContent
- [ ] TimelineDot
- [ ] TimelineItem
- [ ] TimelineOppositeContent
- [ ] TimelineSeparator
- [ ] TreeItem
- [ ] TreeView

## MUI-X Date Pickers

- [ ] AdapterDateFns
- [ ] AdapterDateFnsJalali
- [ ] AdapterDayjs
- [ ] AdapterLuxon
- [ ] AdapterMoment
- [ ] AdapterMomentHijri
- [ ] AdapterMomentJalaali
- [ ] DateCalendar
- [ ] DateField
- [ ] DatePicker
- [ ] DateTimeField
- [ ] DateTimePicker
- [ ] DayCalendarSkeleton
- [ ] DesktopDatePicker
- [ ] DesktopDateTimePicker
- [ ] DesktopTimePicker
- [ ] DigitalClock
- [ ] LocalizationProvider
- [ ] MobileDatePicker
- [ ] MobileDateTimePicker
- [ ] MobileTimePicker
- [ ] MonthCalendar
- [ ] MultiSectionDigitalClock
- [ ] PickersActionBar
- [ ] PickersDay
- [ ] PickersLayout
- [ ] PickersShortcuts
- [ ] StaticDatePicker
- [ ] StaticDateTimePicker
- [ ] StaticTimePicker
- [ ] TimeClock
- [ ] TimeField
- [ ] TimePicker
- [ ] YearCalendar

# Changelog

See [CHANGELOG](./CHANGELOG.md).

# Contributing

See [CONTRIBUTING](./CONTRIBUTING.md).
