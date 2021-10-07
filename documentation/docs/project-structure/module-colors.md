---
title: Module - Colors
---

## Concept

All colors are available in the special module `MaterialUi.Colors`.

All colors are available as their corresponding name from the
[MUI Color Palette](https://material-ui.com/customization/color/#color-palette).
They are typed as [records](https://rescript-lang.org/docs/manual/latest/record)
and you can access the shades by the following rules:

- Numeric keys are prefixed with a `c`
- Keys that are prefixed by a char are lowercased

Let's take the color
[red](https://github.com/cca-io/rescript-material-ui/blob/4ceab30b4e63e6ca639c9cc5ad3a9a1adf52a970/public/rescript-material-ui/src/MaterialUi_Colors.re#L582-L612)
as an example. The following table shows the equivalent keys for accessing its
shades:

## Available Shades

| Javascript    | ReScript                     |
| ------------- | ---------------------------- |
| `red['50']`   | `MaterialUi.Colors.red.c50`  |
| `red['100']`  | `MaterialUi.Colors.red.c100` |
| `red['200']`  | `MaterialUi.Colors.red.c200` |
| `red['300']`  | `MaterialUi.Colors.red.c300` |
| `red['400']`  | `MaterialUi.Colors.red.c400` |
| `red['500']`  | `MaterialUi.Colors.red.c500` |
| `red['600']`  | `MaterialUi.Colors.red.c600` |
| `red['700']`  | `MaterialUi.Colors.red.c700` |
| `red['800']`  | `MaterialUi.Colors.red.c800` |
| `red['900']`  | `MaterialUi.Colors.red.c900` |
| `red['A100']` | `MaterialUi.Colors.red.a100` |
| `red['A200']` | `MaterialUi.Colors.red.a200` |
| `red['A400']` | `MaterialUi.Colors.red.a400` |
| `red['A700']` | `MaterialUi.Colors.red.a700` |

## Available colors

All colors from the
[MUI Color Palette](https://material-ui.com/customization/color/#color-palette)
are available:

- blueGrey
- grey
- brown
- deepOrange
- orange
- amber
- yellow
- lime
- lightGreen
- green
- teal
- cyan
- lightBlue
- blue
- indigo
- deepPurple
- purple
- pink
- red
- common
