---
title: Styles PPX (not recommended)
---

:::caution

The PPX is not recommended anymore for the following reasons:

1. We don't use it in our codebase and cannot thoroughly test it.
2. We will deprecate it as soon as it would take a significant amount of work
   hours to keep it alive.
3. The ReScript team recommends to use as few PPXes as possible in your
   codebase.

:::

## Installation

First, add it to your dependencies using `npm` or `yarn`:

```bash
yarn add rescript-material-ui-ppx
# or
npm install rescript-material-ui-ppx
```

Second, add it to `ppx-flags` in your `bsconfig.json`:

```json
{
  "ppx-flags": ["rescript-material-ui-ppx/ppx"]
}
```

In some cases, depending on your project structure and build process, you might
have to reference the path directly:

```json
{
  "ppx-flags": ["./node_modules/rescript-material-ui-ppx/ppx"]
}
```

## What is a PPX?

PPX stands for **Pre Processor eXtension**. There is a fairly detailed article
by [@dylanirlbeck](https://twitter.com/dylanirlbeck) that I'd recommed if you're
interested in the nuts and bolts of these extensions:
[Link to the article](https://dev.to/dylanirlbeck/intro-to-ppxs-for-reason-newcomers-2829).

## Why do we need one for rescript-material-ui?

When you create some
[styles in MaterialUi](https://material-ui.com/guides/typescript/#usage-of-withstyles),
you pass an object to the `withStyles` function that returns another object with
the same keys that contains the class names as values.

While this is easily representable in Typescript for example, there is no
straight forward way to do this in `ReScript`. This is where the PPX comes in.

You pass an object in and it automatically generates all needed types and
function applications for you. This keeps the tedious and quite verbose work
from you while staying completely type safe when accessing the generated class
names.

## Usage

The extension is used by defining a module and passing `%makeStyles()` as the
module body. Think of `%makeStyles()` as a function, that accepts either

- a record with all fields of type `ReactDOM.Style.t`
- a function with a theme argument that returns above record

The resulting module contains a function called `useStyles()` which you can use
as a hook inside of your `React` component. That hook will return all record
keys with class names as their values.

### Simple example

```rescript
module Styles = %makeStyles({
  root: ReactDOM.Style.make(~padding="20px", ()),
  inner: ReactDOM.Style.make(~lineHeight="1.3em", ()),
})

@react.component
let make = () => {
  let classes = Styles.useStyles()

  <div className=classes.root>
    <div className=classes.inner>
      {"Content"->React.string}
    </div>
  </div>
}
```

### Working with a theme

```rescript
module Styles = %makeStyles(
  theme => {
    root: ReactDOM.Style.make(~padding=`${theme.spacing(3)->string_of_int}px`, ()),
    inner: ReactDOM.Style.make(~color=theme.palette.primary.main, ()),
  }
)

@react.component
let make = () => {
  let classes = Styles.useStyles()

  <div className=classes.root>
    <div className=classes.inner>
      {"Content"->React.string}
    </div>
  </div>
}
```
