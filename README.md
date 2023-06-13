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

# Progress

## MUI-Material

### Components

- [x] Accordion
- [x] AccordionActions
- [ ] AccordionDetails
- [ ] AccordionSummary
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
- [ ] Dialog
- [ ] DialogActions
- [ ] DialogContent
- [ ] DialogContentText
- [ ] DialogTitle
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
- [ ] Step
- [ ] StepButton
- [ ] StepConnector
- [ ] StepContent
- [x] StepIcon
- [ ] StepLabel
- [ ] Stepper
- [ ] StylesProvider
- [x] SvgIcon
- [ ] SwipeableDrawer
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

- [ ] Theme
- [ ] ThemeHelpers
- [ ] ThemeOptions
- [ ] ThemeProvider

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
