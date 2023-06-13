---
title: Number Type
---

The bindings will provide both `float` and `int` types as numbers. Generally the
type of `Mui.Number.t` will be re-used whereever possible.

An example of this would be:

```rescript
@react.component
let make = () => {
  open Mui

  <AppBar elevation=Number.int(3) />
}
```

In some cases where you would expect this type, the bindings might require
another one that originates inside the component. This is the case when a number
is part of a broader union type.

An example of this would be:

```rescript
@react.component
let make = () => {
  <Mui.Backdrop
    _open=true
    timeout=Mui.Backdrop.Timeout.int(3000)
  />
}
```
