---
title: Usage
---

The extension is used by defining a module and passing `%makeStyles()` as the
module body. Think of `%makeStyles()` as a function, that accepts either

- a record with all fields of type `ReactDOMRe.Style.t`
- a function with a theme argument that returns above record

The resulting module contains a function called `useStyles()` which you can use
as a hook inside of your `ReasonReact` component. That hook will return all
record keys with class names as their values.

## Simple usage

```reason
module Styles = %makeStyles({
  root: ReactDOMRe.Style.make(~padding="20px", ()),
  inner: ReactDOMRe.Style.make(~lineHeight="1.3em", ()),
})

@react.component
let make = () => {
  let classes = Styles.useStyles();

  <div className=classes.root>
    <div className=classes.inner>
      {"Content"->React.string}
    </div>
  </div>
}
```

## Working with a theme

```reason
module Styles = %makeStyles(
  theme => {
    root: ReactDOMRe.Style.make(~padding=`${theme.spacing(3)->string_of_int}px`, ()),
    inner: ReactDOMRe.Style.make(~color=theme.palette.primary.main, ()),
  }
)

@react.component
let make = () => {
  let classes = Styles.useStyles();

  <div className=classes.root>
    <div className=classes.inner>
      {"Content"->React.string}
    </div>
  </div>
}
```
