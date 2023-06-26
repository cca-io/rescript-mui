---
title: Theming (TODO)
---

## `classes` prop

Overriding styles locally is usually done via the `classes` prop that exists on
virtually every component. Likewise, each component of the bindings has this
prop and an according generator function for it. It is accessible via
`Mui.Component.Classes.make`.

Example:

```rescript
open Mui
let classes = Styles.useStyles()
<Paper
  classes={Paper.Classes.make(
    ~root=classes.root,
    ~rounded=classes.rounded,
    (),
  )}>
  <Typography> {"Some Content"->React.string} </Typography>
</Paper>
```

## On themes in general

The automated generation of the theme object differs a bit from the components.
The theme is extracted from it's typescript definitions, which are quite
complex. This means that the extraction process is a bit error prone
(unfortunately a lot more than I'd like). This means that it is possible for the
theme functions / object to change from release to release in a seemingly random
fashion, until I can resolve this situation in a reliable way (Not a trivial
problem to solve unfortunately).

Theming is split into two modules:

- `Mui.Theme` (reading)
- `Mui.ThemeOptions` (constructing)

Theme definitions are likely to undergo breaking changes in future versions.

## Constructing a theme

You can construct a theme object by calling `Mui.ThemeOptions.make`. You would
usually pass it to the `createTheme` function, which has a binding for
convenience at : `Mui.Theme.create`.

The following is an example of constructing a theme object:

```rescript
let theme =
  Mui.Theme.create({
    open Mui.ThemeOptions
    make(
    ~overrides=
        Overrides.make(
        ~muiButton=
            ButtonClassKey.make(
            ~outlined=
                ReactDOM.Style.make(
                ~fontSize="12px",
                ~fontWeight="300",
                ~color="gray",
                (),
                ),
            (),
            ),
        (),
        ),
    (),
    )
  })
```

You might have noticed that `ButtonClassKey` is not a straight forward and easy
to guess sub module name. This is due to how the type information is presented
by typescript. When in doubt, just open the `Mui.ThemeOptions.res` module and
follow the module names.

## Reading from a theme

Reading from a theme object has become a lot more straight forward in the latest
ReScript versions (as records are now equivalent to JavaScript objects).

All (sub-)types are in a flat hierarchy inside the `Mui.Theme` module. Accessing
them is very straight forward and corresponds to the original MaterialUi Shape.

Here are 2 examples of accessing fields in the theme object:

```rescript
@react.component
let make = () => {
  let theme = Mui.Core.useTheme()

  <div style={ReactDOM.Style.make(~color=theme.palette.primary.main, ())}>
    {"Some main colored text"->React.string}
  </div>
}
```

```rescript
module Styles = %makeStyles(
  theme => {
    toolbarIcon: ReactDOM.Style.combine(
      ReactDOM.Style.make(
        ~padding="0 8px",
        (),
      ),
      theme.mixins.toolbar,
    ),
    appBar: ReactDOM.Style.make(
      ~zIndex=(theme.zIndex.drawer +. 1.0)->int_of_float->string_of_int,
      ~transition=Mui.ThemeHelpers.transitionCreate(
        ~theme,
        ~affectWidth=true,
        ~affectMargin=true,
        ~easing=theme.transitions.easing.sharp,
        ~duration=theme.transitions.duration.leavingScreen,
        (),
      ),
      (),
    ),
  }
)
```

(The above example makes mention of the user contributed `Mui.ThemeHelpers`
module. Please refer to the source code for more information.)

## Theme Provider

For providing a theme at root level or further down the tree, you should use the
`Mui.ThemeProvider` component.

Example:

```rescript
let theme = Mui.Theme.create(Mui.ThemeOptions.make())

@react.component
let make = () => {
  <div className="app root">
    <Mui.ThemeProvider theme>
      <div />
    </Mui.ThemeProvider>
  </div>
}
```
