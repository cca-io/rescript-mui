# MUI 7.x Binding Updates

This document lists all updates made to the ReScript bindings in this package to support Material UI v7.x APIs and breaking changes.

## General

- All bindings reviewed and updated for compatibility with MUI v7.x, including new props, renamed values, and breaking changes.
- All relevant imports updated to use `@mui/material` instead of `@mui/lab` for components promoted to core.

## Button

- Added `loading`, `loadingIndicator`, and `loadingPosition` props.

## IconButton

- Added `loading`, `loadingIndicator`, and `loadingPosition` props.

## InputLabel

- Updated `size` type: removed `normal`, added `medium`.

## Badge

- Updated `overlap` type: replaced `circle`/`rectangle` with `circular`/`rectangular`.

## Skeleton

- Updated `variant` type: replaced `circle`/`rect` with `circular`/`rectangular`.

## Fab

- Updated `variant` type: replaced `round` with `circular`.

## Pagination & PaginationItem

- Updated `shape` type: replaced `round` with `circular`.

## Chip

- Updated `variant` type: replaced `default` with `filled`.

## Avatar

- Updated `variant` type: replaced `circle` with `circular`.

## AvatarGroup, ToggleButton, ToggleButtonGroup, Autocomplete

- Ensured all are imported from `@mui/material` (not `@mui/lab`).

## Other

- Reviewed all bindings for breaking changes and new props as per the [MUI v7 migration guide](https://mui.com/material-ui/migration/upgrade-to-v7/).

## MUI v6 Breaking Changes

- **Accordion**: Added `slotProps` prop to support heading customization (e.g., change heading level for accessibility). See Accordion binding for details.
- **slotProps/slots standardization**: Ensured all relevant bindings support `slotProps` and `slots` for customization, matching MUI v6+ API. (e.g., Badge, Autocomplete, AvatarGroup, etc.)
- **Grid2**: If you use the new `Grid2` API (formerly `Unstable_Grid2`), you must add a new binding. The classic `Grid` binding remains for legacy usage.
- **ListItem**: Deprecated `button` prop removed. Use `ListItemButton` for button behavior.
- **Autocomplete**: `onInputChange` now supports new `reason` values: `"blur"`, `"selectOption"`, `"removeOption"`.
- **Chip**: Chip no longer loses focus on `Escape` by default. See MUI docs for how to restore old behavior if needed.
- **Lab components promoted to core**: All promoted components now imported from `@mui/material`.
- **Minimum React/TypeScript version**: React 17+ and TypeScript 4.7+ required.
- **Removed UMD bundle and IE11 support**: No changes needed in bindings, but note for consumers.

**Bindings updated/reviewed:** Accordion, Badge, Autocomplete, AvatarGroup, ListItem, Chip, Grid. Others reviewed for slotProps/slots and import path correctness.

---

**Last updated:** $(date)
