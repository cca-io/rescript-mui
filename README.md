# ReScript Bindings for MUI v5 (WIP!)

This library provides [ReScript](https://rescript-lang.org/) bindings for
[MUI](https://mui.com/). From now on, bindings are hand-written and manually maintained.

These bindings will only work with ReScript 11 and JSX mode version 4, as it enables us to utilize [untagged variants](https://rescript-lang.org/blog/improving-interop#untagged-variants), optional record fields, or record props spread. The latter is especially important, as we are finally able to inherit props from one component to another more easily.

# Progress

## MUI-Material

### Components

- [x] Accordion
- [ ] AccordionActions
- [ ] AccordionDetails
- [ ] AccordionSummary
- [ ] Alert
- [ ] AlertTitle
- [ ] AppBar
- [ ] Autocomplete
- [ ] Avatar
- [ ] AvatarGroup
- [ ] Backdrop
- [ ] Badge
- [ ] BottomNavigation
- [ ] BottomNavigationAction
- [ ] Box
- [ ] Breadcrumbs
- [ ] Button
- [ ] ButtonBase
- [ ] ButtonGroup
- [ ] Card
- [ ] CardActionArea
- [ ] CardActions
- [ ] CardContent
- [ ] CardHeader
- [ ] CardMedia
- [ ] Checkbox
- [ ] Chip
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
- [ ] Drawer
- [ ] Fab
- [ ] Fade
- [ ] FilledInput
- [ ] FormControl
- [ ] FormControlLabel
- [ ] FormGroup
- [ ] FormHelperText
- [ ] FormLabel
- [ ] GlobalStyles
- [ ] Grid
- [ ] Grow
- [ ] Hidden
- [ ] Icon
- [ ] IconButton
- [ ] ImageList
- [ ] ImageListItem
- [ ] ImageListItemBar
- [ ] Input
- [ ] InputAdornment
- [ ] InputBase
- [ ] InputLabel
- [ ] LinearProgress
- [ ] Link
- [ ] List
- [ ] ListItem
- [ ] ListItemAvatar
- [ ] ListItemButton
- [ ] ListItemIcon
- [ ] ListItemSecondaryAction
- [ ] ListItemText
- [ ] ListSubheader
- [ ] Menu
- [ ] MenuItem
- [ ] MenuList
- [ ] MobileStepper
- [ ] Modal
- [ ] NativeSelect
- [ ] OutlinedInput
- [ ] Pagination
- [ ] PaginationItem
- [x] Paper
- [ ] Popover
- [ ] Popper
- [ ] Radio
- [ ] RadioGroup
- [ ] Rating
- [ ] ScopedCssBaseline
- [ ] Select
- [ ] Skeleton
- [ ] Slide
- [ ] Slider
- [ ] Snackbar
- [ ] SnackbarContent
- [ ] SpeedDial
- [ ] SpeedDialAction
- [ ] SpeedDialIcon
- [ ] Stack
- [ ] Step
- [ ] StepButton
- [ ] StepConnector
- [ ] StepContent
- [ ] StepIcon
- [ ] StepLabel
- [ ] Stepper
- [ ] StylesProvider
- [ ] SvgIcon
- [ ] SwipeableDrawer
- [ ] Switch
- [ ] Tab
- [ ] Table
- [ ] TableBody
- [ ] TableCell
- [ ] TableContainer
- [ ] TableFooter
- [ ] TableHead
- [ ] TablePagination
- [ ] TableRow
- [ ] TableSortLabel
- [ ] Tabs
- [ ] TabScrollButton
- [ ] TextField
- [ ] ToggleButton
- [ ] ToggleButtonGroup
- [ ] Toolbar
- [ ] Tooltip
- [ ] Typography
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

# Documentation

Check out our documentation site at https://rescript-material-ui.cca.io/.

# Changelog

See https://rescript-material-ui.cca.io/docs/changelog.
