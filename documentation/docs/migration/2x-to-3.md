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
