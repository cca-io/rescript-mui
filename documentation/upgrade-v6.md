# Upgrading to v6.0.0

This guide helps you migrate from `@rescript-mui/material` v5.x to v6.0.0, which adds support for `@mui/material` v6.

> **Prerequisites**: This guide assumes familiarity with [MUI v6 breaking changes](https://v6.mui.com/material-ui/migration/upgrade-to-v6/). We focus on the ReScript binding changes.

## Grid → Grid2

The `Grid` component now uses MUI's new Grid2 implementation. This is the most significant breaking change.

### Removed props

- `item` - Grid items are now implicit (no longer needed)
- `zeroMinWidth` - Use `minWidth: 0` in sx prop instead

### Changed props

The breakpoint-specific size props (`xs`, `sm`, `md`, `lg`, `xl`) are replaced with a single `size` prop:

**Before (v5):**

```rescript
<Grid container=true spacing={Int(2)}>
  <Grid item=true xs={Number(12.)} md={Number(6.)}>
    <Item />
  </Grid>
</Grid>
```

**After (v6):**

```rescript
<Grid container=true spacing={Int(2)}>
  <Grid size=Object({xs: Int(12), md: Int(6)})>
    <Item />
  </Grid>
</Grid>
```

### Size values

The `GridSize.t` type supports multiple forms:

```rescript
// Single value for all breakpoints
size=Int(6)
size=Auto
size=Grow  // replaces `true`

// Responsive object
size=Object({xs: Int(12), sm: Int(6), md: Int(4)})

// Array form
size=Array([Int(12), Int(6), Int(4)])
```

### New offset prop

Grid2 adds support for offsets:

```rescript
<Grid size=Object({xs: Int(6)}) offset=Object({xs: Int(3)})>
  // Centered 6-column item
</Grid>
```

### Using GridLegacy

If you need time to migrate, use `GridLegacy` which preserves the v5 API:

```rescript
<GridLegacy container=true spacing={Int(2)}>
  <GridLegacy item=true xs={Number(12.)} md={Number(6.)}>
    <Item />
  </GridLegacy>
</GridLegacy>
```

## LoadingButton → Button

The `LoadingButton` component from `@rescript-mui/lab` has been removed. Use the standard `Button` with loading props instead.

**Before (v5):**

```rescript
<Lab.LoadingButton loading=true variant=Contained>
  {"Submit"->React.string}
</Lab.LoadingButton>
```

**After (v6):**

```rescript
<Button loading=True variant=Contained>
  {"Submit"->React.string}
</Button>
```

### Loading prop type

The `loading` prop uses a dedicated type for three-state behavior:

```rescript
type loading =
  | True      // Show loading indicator, disable button
  | False     // Normal state, loading wrapper rendered
  | Null      // Normal state, no loading wrapper (default)
```

### Loading position and indicator

```rescript
<Button
  loading=True
  loadingPosition=Start
  loadingIndicator={<CircularProgress size={Number(16.)} />}>
  {"Saving..."->React.string}
</Button>
```

## Typography

### Color prop

The `color` prop is now a dedicated enum instead of accepting system values:

**Before (v5):**

```rescript
<Typography color=Primary>...</Typography>  // worked
<Typography color=String("error")>...</Typography>  // also worked
```

**After (v6):**

```rescript
<Typography color=Primary>...</Typography>
<Typography color=Error>...</Typography>
<Typography color=TextSecondary>...</Typography>
```

Available values: `Primary`, `Secondary`, `Success`, `Error`, `Info`, `Warning`, `TextPrimary`, `TextSecondary`, `TextDisabled`

### Deprecated paragraph prop

The `paragraph` prop is deprecated. Use `component` instead:

**Before:**

```rescript
<Typography paragraph=true>...</Typography>
```

**After:**

```rescript
<Typography component="p" gutterBottom=true>...</Typography>
```

## Stack

### Direction prop

The `direction` prop now uses `StackDirection.t` for responsive support:

**Before (v5):**

```rescript
<Stack direction=[Row]>...</Stack>
```

**After (v6):**

```rescript
// Single direction
<Stack direction=Row>...</Stack>

// Responsive
<Stack direction=Object({xs: Column, md: Row})>...</Stack>
```

## Autocomplete

### Extended inputChangeReason

The `inputChangeReason` type has new variants:

```rescript
type inputChangeReason =
  | Blur         // new
  | Clear
  | Input
  | Reset
  | SelectOption // new
  | RemoveOption // new
```

Update any pattern matches on this type.

## Slots and SlotProps

Many components now have `slots` and `slotProps` for customization. This is the preferred way to customize internal elements in MUI v6.

```rescript
<TextField
  slots={
    input: customInputComponent
  }
  slotProps={
    input: {className: "custom-input"},
    inputLabel: {shrink: true}
  }
/>
```

Components with new slots/slotProps:

- Accordion, AccordionSummary
- Alert, Autocomplete
- Avatar, AvatarGroup
- Backdrop, Badge
- BottomNavigationAction, Breadcrumbs
- CardActionArea, CardHeader, Checkbox
- Drawer, FormControlLabel
- InputBase, ListItemText
- Menu, MobileStepper, Modal
- OutlinedInput, Popover, Radio, Rating
- Slider, Snackbar
- SpeedDial, SpeedDialAction
- StepContent, StepLabel
- SwipeableDrawer, Switch
- TablePagination, TableSortLabel
- TextField, Tooltip

## AvatarGroup

### New renderSurplus prop

Customize how the "+X" surplus indicator is rendered:

```rescript
<AvatarGroup
  max=3
  renderSurplus={surplus => <Avatar>{`+${surplus->Int.toString}`->React.string}</Avatar>}
>
  ...
</AvatarGroup>
```

## System props

### New flexbox props

`justifyItems` and `justifySelf` are now available:

```rescript
<Box justifyItems=Center justifySelf=FlexEnd>...</Box>
```

### New System.Value.t variants

Additional alignment and flex values:

```rescript
// Alignment
SpaceBetween, SpaceAround, SpaceEvenly, Left, Right

// Flex direction
Row, RowReverse, Column, ColumnReverse

// Flex wrap
Nowrap, Wrap, WrapReverse
```

## Quick migration checklist

- [ ] Update `@mui/material` to v6
- [ ] Replace `Grid` usage with new `size` prop API (or switch to `GridLegacy`)
- [ ] Remove `item` prop from Grid items
- [ ] Replace `LoadingButton` with `Button` + loading props
- [ ] Update `Typography.color` to use new enum values
- [ ] Update `Stack.direction` to new type
- [ ] Update any `Autocomplete.inputChangeReason` pattern matches
- [ ] Consider adopting `slots`/`slotProps` for component customization
