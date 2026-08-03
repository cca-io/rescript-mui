# Theming

## Creating and providing a theme

Create a theme from a `Mui.ThemeOptions.t` record and provide it through
`Mui.ThemeProvider`:

```rescript
let theme = Mui.Theme.create({
  palette: {
    primary: {main: "#8fe830"},
  },
})

@react.component
let make = () =>
  <Mui.ThemeProvider theme={Mui.ThemeProvider.Theme(theme)}>
    <Mui.Button color=Primary variant=Outlined>
      {"Themed button"->React.string}
    </Mui.Button>
  </Mui.ThemeProvider>
```

`Mui.ThemeProvider` also accepts `Func`, which derives a theme from the outer
theme:

```rescript
let updateTheme = outerTheme =>
  Mui.Theme.create({
    ...outerTheme,
    palette: {primary: {main: "#8fe830"}},
  })

<Mui.ThemeProvider theme={Mui.ThemeProvider.Func(updateTheme)}> ... </Mui.ThemeProvider>
```

## Component defaults and style overrides

The generated `components` record contains the available Material UI component
keys. Each entry supports typed default props and style overrides for its CSS
classes:

```rescript
let theme = Mui.Theme.create({
  components: {
    muiButton: {
      defaultProps: {
        variant: Mui.Button.Contained,
        disableElevation: true,
      },
      styleOverrides: {
        root: {
          borderRadius: "12px",
          textTransform: "none",
        },
      },
    },
  },
})
```

Lab overrides use `MuiLab.Overrides.t`. They can be merged into the Material UI
`components` record through interop when one theme contains overrides from both
packages. A complete, compile-checked example is available in
[`ExampleThemeOverrides.res`](../examples/src/examples/ExampleThemeOverrides.res).

## Per-component classes

Component `classes` props are typed records and can be written directly:

```rescript
<Mui.Button classes={root: "custom-button"}>
  {"Button"->React.string}
</Mui.Button>
```

For values that can be expressed through MUI System, prefer the typed `sx` prop.
See [System and `sx`](module-system.md).
