---
title: Changelog
---

**Tags:**

- :boom: - Breaking Change
- :rocket: - New Feature
- :bug: - Bug Fix
- :memo: - Documentation
- :house: - Internal
- :nail_care: - Polish

(_Tags are copied from
[babel](https://github.com/babel/babel/blob/master/CHANGELOG.md)_)

## 6.0.0 (Unreleased)

## 5.1.1

- :bug: restore the accidentally removed id prop of `ButtonBase`
- :memo: Add a bunch of examples

## 5.1.0

- :boom: Theme & ThemeOptions refactor
  - Makes the naming more consistent between the two (needs another check)
  - Re-order types to be defined in the same order in each module
  - Fixes the breakpoints function types on the theme
  - Removes the now unnecessary runtime overhead of ThemeHelpers.addBreakpoint
  - Add ThemeHelpers.addBreakpointDown function
  - Add ExampleTheme.res file to the repo
  
- :house: Add `Breakpoint` type
- :bug: Add a bunch of missing props to `InputBase`, `TextField`
- :bug: Add a bunch of event handler props to common props
- :house: Move `title` to common props
- :house: Move `tabIndex` to common props
- :bug: Add `Typography` props to `DialogTitle`
- :bug: Add `rel` and `target` to `ButtonBase` props
- :bug: Add missing `rowSpan` to `TableCell`
- :bug: Add `enterKeyHint` and `inputMode` to input props
- :bug: Add `variant` to `Card` props
- :bug: Add `data-testid` to common props

## 5.0.1

- :bug: Add missing colSpan to TableCell
- :bug: Fix disableUnderline not being available in Select & Co.
- :bug: Fix defaultProps override feature

## 5.0.0

- :rocket: Main release (no changes)

## 5.0.0-rc.2

- :rocket: Add ARIA props.

## 5.0.0-rc.1

- :boom: Split `Autocomplete` into `Autocomplete` and `Autocomplete.Multiple` and fix their types.
- :rocket: OverridableComponent: Add `componentWithUnknownProps` type coercion function.

## 5.0.0-rc.1

- :boom: Split `Autocomplete` into `Autocomplete` and `Autocomplete.Multiple` and fix their types.
- :rocket: OverridableComponent: Add `componentWithUnknownProps` type coercion function.

## 5.0.0-alpha.13

- :bug: Fab: Actually inherit onClick from ButtonBase

## 5.0.0-alpha.12

- :bug: Fix anchorEl binding in Popper and Popover
- :bug: Fab inherits its props from ButtonBase now

## 5.0.0-alpha.11

- :bug: Add missing onMouseEnter to CommonProps.clickableProps

## 5.0.0-alpha.10

- :bug: Fix Popper anchorEl signature once more.

## 5.0.0-alpha.9

- :bug: Fix Popper anchorEl signature

## 5.0.0-alpha.8

- :boom: Switch to rescript.json for all packages

### MUI Lab 5.0.0-alpha.3

- :boom: Switch to rescript.json

## 5.0.0-alpha.7

- :nail_care: Switch to rescript.json

- :bug: Fix Autocomplete's renderTags signature.
- :bug: Fix Autocomplete's renderOption signature.
- :bug: Fix typo '@as' annotations in Fab and LoadingButton.

## 5.0.0-alpha.6

- :bug: Fix Breadcrumbs signature.

## 5.0.0-alpha.5

- :rocket: Add scaffolding for MUI System package bindings.
- :bug: Fix missing clickable props for TableRow.

### MUI Lab 5.0.0-alpha.2

- :bug: Make MUI lab able to depend on current rescript-mui-material version.

## 5.0.0-alpha.4

- :bug: Fix CardActionArea having no typical button props like onClick.

## 5.0.0-alpha.3

- :boom: Finish complete bindings rewrite of the main MUI package.

### MUI Lab 5.0.0-alpha.1

- :boom: Complete rewrite to adapt to MUI v5 (in progress).

## 5.0.0-alpha.2

- :bug: Fix Input element type.

## 5.0.0-alpha.1

- :boom: Complete rewrite to adapt to MUI v5 (in progress).
- :boom: Release rescript-mui packages under a new npm organization (`@rescript-mui`).
- :memo: Rename the repository to rescript-mui.
- :memo: Deprecate website.
- :house: Restructure repo to a ReScript-Monorepo with pinned-packages.

## 3.0.2

- :bug: Fixed the binding generator's handling of `int` enums.

## 3.0.1

- :house: Fixed outdated peer dependencies.

## 3.0.0

- :boom: Converted the main entry point `MaterialUi` to the `Mui` namespace.
- :boom: Added `Any` module as a replacement for `MaterialUi.Types` and
  `MaterialUi.any`.
- :boom: Use stricter `React.element` type for children.
- :boom: Simplified ThemeProvider and removed MuiThemeProvider.
- :boom: `createTheme` replaces `createMuiTheme`.
- :boom: Removed `WithStyles` HOC and added a simple `useStyles` binding
  instead.
- :rocket: Added some custom props for `Button`, `ButtonBase`,
  `FormControlLabel`, `OutlinedInput`, `Radio`, `Switch`, `TableRow`,
  `TextField`.
- :rocket: Updated to material-ui 4.12.3 and material-ui-lab 4.0.0-alpha.60.
- :memo: Updated all Documentation to current changes.
- :memo: Added a migration guide for the transition to this version.
- :memo: Added a bunch of examples.
- :memo: ReScript syntax highlighting.
- :house: Made most bindings zero cost
- :house: Restructured the monorepo.
- :nail_care: Finished Reason -> ReScript transition.

## 2.1.2

- :boom: Republished 2.1.0 with the new package name `rescript-material-ui`.

## 2.1.0

This is the last version with the old package name `@jsiebern/bs-material-ui`.

- :rocket: Updated to MaterialUi v4.11.4
- :rocket: Added StylesProvider
- :boom: Switched to the new `@rescript/react` package (keep on `2.0.0` if you
  need legacy support)

## 2.0.0

- :boom: Deprecated the pre v2 bindings for the zero cost version (pre v2 is no
  longer supported)
- :rocket: Updated to MaterialUi v4.11.0
- :rocket: Added a documentation page

## 1.2.0

- :rocket: Updated to MaterialUi v4.8.1
- :rocket: Hooks are now on the master branch / main npm package

## 1.1.0

- :rocket: Updated to MaterialUi v3.9.2
- :house: Moved all related repos into this one
- :boom: Removed the icons from this repo, see the
  [README](https://github.com/cca-io/rescript-material-ui/blob/master/README.md)
  for more information

## 1.0.0

- :rocket: Bump to version 1.0.0 of the bindings (Because I think that the
  general way of the bindings won't change much from now on)
- :rocket: Updated to MaterialUi v3.8.1
- :rocket: Added bindings to `@material-ui/icons` (needs to be installed
  separately) **WARNING**: Currently broken (includes the whole icons package,
  fix coming down the road)
- :rocket: Added properly typed theme (see examples!)
- :rocket: Added `theme => ReactDOMRe.Style.t` functionality for the ppx
- :house: Moved the withStyles PPX into it's own repository
  ([https://github.com/jsiebern/reason-mui-withstyles-ppx](https://github.com/jsiebern/reason-mui-withstyles-ppx))
- :boom: Removed the `render` prop from the safe styles component (generated by
  the ppx), it has to be used as a HOC now (please see the updated examples)

## 0.4.3

- :rocket: Updated to MaterialUi v3.2.2
- :rocket: Added `xsAuto` ,`smAuto` ,`mdAuto` ,`lgAuto` ,`xlAuto` properties to
  the `Grid` component (will override their respective set properties if
  defined)
- :rocket: `mui.withStyles` generated components now accept a single child
  **OR** a render prop (no `...` array spread when using as a `HOC`)
- :house: Added an example page: Clone the project, `yarn install`, then
  `yarn examples` to start the dev server

## 0.4.2

- :rocket: Updated to MaterialUi v3.2.0

## 0.4.1

- :rocket: Updated to MaterialUi v3.1.1
- :bug: Brought back the `Popper` component
- :bug: Fixed `WithStyles` component crashing when themed argument is not passed
- :house: Switched binding style to support both `es6` and `commonjs`

## 0.4.0

- :rocket: Updated to MaterialUI v1.5.1
- :boom: Updated to ReasonReact v5 (using `ReactEvent` instead of
  `ReactEventRe`)

## 0.3.3

- :rocket: Updated to MaterialUI v1.4.1
- :bug: Grid component sizes were converted to strings

## 0.3.2

- :rocket: Added `ppx_withStyles` for `linux` and `mac`
- :rocket: Updated to MaterialUI v1.3.1
- :rocket: Added a postinstall hook for a platform dependant install of the
  ppx_withStyles
- :boom: Updated to Bucklescript v4.0.0 (abstract shapes field access switched
  from `key` to `keyGet`)

## 0.3.1

- :rocket: Updated to MaterialUI v1.2.2

## 0.3.0

- :rocket: Updated to MaterialUI v1.1.0
- :boom: Switched to `[bs.deriving abstract]` to work with object shapes (see
  component `Popover` as an example)
- :boom: Switched to trailing underscores for reserved names as per
  `reason-react v0.4.2` practice

## 0.2.0

- :bug: Fixed the `Grid` component so it requires numbers instead of strings

## 0.1.9

- :rocket: Most of the `onChange` handlers should be accurate now
- :house: The modules are now split into several files (reduces resulting bundle
  size)
- :memo: Added a changelog file
