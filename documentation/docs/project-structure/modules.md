---
title: Modules
---

### Naming

`rescript-material-ui` provides all components in individual files. The file
pattern is:

    MaterialUi.[COMPONENT_NAME].re

If you wish to use the `Typography` component for example, it would look like
this:

```rescript
<MaterialUi.Typography>
  {"Some example text"->React.string}
</MaterialUi.Typography>
```

The component names map one to one to the ones found in the `Component API`
section of the MUI documentation.

### Global module

For convenience, `rescript-material-ui` offers the `MaterialUi` module as well.
It includes all components and a few special ones, which will be discussed
later. This modules primary purpose is not having to type out the `MaterialUi_`
part of the component modules each time. Example:

```rescript
@react.component
let make = () => {
  open MaterialUi
  <div>
    <Typography variant=#h4 gutterBottom=true>
      {"Headline"->React.string}
    </Typography>
    <Typography>
      {"Some example text"->React.string}
    </Typography>
  </div>
}
```

### Special modules

`MaterialUi.re` contains the following special modules:

- [Colors](module-colors.md)
- [Core](module-core.md)
- [Box](module-box.md)
- [Theme](theming.md)
- [ThemeOptions](theming.md)
- [ThemeHelpers](theming.md)
