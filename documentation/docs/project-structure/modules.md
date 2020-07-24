---
title: Modules
---

### Naming

`bs-material-ui` provides all components in individual files. The file pattern
is:

    MaterialUi_[COMPONENT_NAME].re

If you wish to use the `Typography` component for example, it would look like
this:

```reason
<MaterialUi_Typography>
  {"Some example text"->React.string}
<MaterialUi_Typography>
```

The component names map one to one to the ones found in the `Component API`
section of the MUI documentation.

### Global module

For convenience, `bs-material-ui` offers the `MaterialUi` module as well. It
includes all components and a few special ones, which will be discussed later.
This modules primary purpose is not having to type out the `MaterialUi_` part of
the component modules each time. Example:

```reason
[@react.component]
let make = () => {
  MaterialUi.(
    <div>
      <Typography variant=`H4 gutterBottom=true>
        {"Headline"->React.string}
      </Typography>
      <Typography>
        {"Some example text"->React.string}
      </Typography>
    </div>
  )
};
```

### Special modules

`MaterialUi.re` contains the following special modules:

- [Colors](colors.md)
- [Core](special-core.md)
- [Box](special-box.md)
- [Theme](theming.md)
- [ThemeOptions](theming.md)
- [ThemeHelpers](theming.md)
