---
title: 2.x -> 3.0.0
---

# Migration Guide for v2.x -> v3.0.0

## MaterialUi is now Mui

We changed the namespace from `MaterialUi` to `Mui` in 3.0.0 for the following
reasons:

1. Nice and short 🙂
2. Material-UI [rebranded to MUI](https://mui.com/blog/material-ui-is-now-mui/)
3. Now that we are using the `namespace` feature, it is not possible anymore to
   "alias" the `MaterialUi` module to `Mui` using `include MaterialUi`. This
   gives a the following error:
   `Mui is compiled in script mode while its dependent is not`.
4. 3.0.0 already has other breaking changes anyway.

Furthermore, the lab bindings now have their own namespace under `MuiLab`.

## Bindings changes

These are mainly due to the stricter focus on zero-cost bindings.

### Mangled names utilize the `\""`-syntax now

e.g. `_InputProps` is now `\"InputProps"`, `_type="number"` is now
`\"type"="number"`.

### Polymorphic variants are now all lowercase

e.g. `color=#Primary` is now `color=#primary`.

### `any` and `anyUnpack` have been replaced

These type helpers now reside under `Mui.Any`. Refer to
[Any](../project-structure/any-type.md).

### Children types are more specific

Previously it was possible to put arbitrary types (such as strings) into
children. Now the children type is `React.element`, which streamlines this
library to the `rescript-react` bindings.

Therefore, you now need to wrap strings with the `React.string` function, or
pass arrays to `React.array`.

## FAQ

### Did we miss anything?

If there are any problems with this new release, feel free to
[open an issue](https://github.com/cca-io/rescript-material-ui/issues).

### Will you upgrade to v5 as well?

We are in no rush to do it, because we currently use v4 in most of our projects.
If we ever feel the need to upgrade, we will upgrade this repository
accordingly.
