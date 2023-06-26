# @rescript-mui documentation

### Naming

`@rescript-mui/material` provides all components in individual files. The file
pattern is:

    Mui.[COMPONENT_NAME].res

If you wish to use the `Typography` component for example, it would look like
this:

```rescript
<Mui.Typography>
  {"Some example text"->React.string}
</Mui.Typography>
```

The component names map one to one to the ones found in the `Component API`
section of the MUI documentation.

### Global module

For convenience, the `Mui` module includes a few special modules, which will be
discussed later. To avoid name clashes, we suggest you stick to typing out
`Mui.[COMPONENT_NAME]` instead of using `open`.

```rescript
@react.component
let make = () =>
  <div>
    <Mui.Typography variant=#h4 gutterBottom=true>
      {"Headline"->React.string}
    </Mui.Typography>
    <Mui.Typography>
      {"Some example text"->React.string}
    </Mui.Typography>
  </div>
```

### Special modules

The `Mui` namespace contains the following special modules:

- [Colors](module-colors.md)
- [Core](module-core.md)
- [Box](module-box.md)
- [Theme](theming.md)
- [ThemeOptions](theming.md)
- [ThemeHelpers](theming.md)

## Styling

For styling `@rescript-mui` components, you need to pass CSS class names
to them. We have documented the following popular options:

- [CSS](css.md)
- [Tailwind CSS](tailwind.md)
- [a CSS-in-ReScript library like `bs-css`](bs-css.md)
