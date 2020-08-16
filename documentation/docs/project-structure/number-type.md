---
title: Number Type
---

The bindings will provide both `float` and `int` types as numbers. Generally the
the type of `MaterialUi_Types.Number.t` will be re-used whereever possible (The
`Number` module is also accessible via `MaterialUi.Number`).

An example of this would be:

```reason
@react.component
let make = () => {
  open MaterialUi;

  <AppBar elevation=Number.int(3) />
}
```

In some cases where you would expect this type, the bindings might require
another one that originates inside the component. This is the case when a number
is part of a broader union type.

An example of this would be:

```reason
@react.component
let make = () => {
  open MaterialUi;

  <Backdrop timeout=Backdrop.Timeout.int(3000) />
}
```
