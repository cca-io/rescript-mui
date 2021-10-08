---
title: Module - Core
---

The `MaterialUi.Core` module contains a few manual bindings to potentially
useful functions.

### useTheme() => MaterialUi.Theme.t

A [react](https://rescript-lang.org/docs/react/latest/introduction) hook to get
the current theme. See
[this page](https://material-ui.com/styles/api/#usetheme-theme) for more
details.

### useMediaQuery(Breakpoint.t) => bool

A [react](https://rescript-lang.org/docs/react/latest/introduction) hook to
execute a programmatic media query. It returns a boolean for wether the query is
true or not.

The `useMediaQuery` uses a type of `MaterialUi.Core.Breakpoint.t`. (See
[this page](https://material-ui.com/components/use-media-query/#using-material-uis-breakpoint-helpers)
for more information).

You can construct a breakpoint like this:

```rescript
@react.component
let make = () => {
    open MaterialUi.Core
    let theme = useTheme()
    let matches = useMediaQuery(Breakpoint.get(theme, #up(#sm)))
    Js.log(matches)

    <div />
}
```

### useMediaQueryString(string) => bool

It serves the same purpose as the one mentioned above, but you can pass a string
with a custom query instead of a breakpoint. (See
[this page](https://material-ui.com/components/use-media-query/#simple-media-query)
for more information).
