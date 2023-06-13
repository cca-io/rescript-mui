# How to add bindings to rescript-mui

## Use the d.ts as template

1. Take any component from MUI and look for its `d.ts` file, e.g. [Accordion.d.ts](https://github.com/mui/material-ui/blob/master/packages/mui-material/src/Accordion/Accordion.d.ts)
2. Copy it over, including the documentation comments.

## Props hierarchy

1. Every main props type needs to inherit from `CommonProps.t`, except if MUI documentation explicitly says that only the listed props are the valid ones.
2. If some component inherits from a MUI parent, the props to inherit from need to be called publicProps, e.g. `Paper.publicProps`. This is necessary, because prop names cannot be overwritten with different types. For instance the `classes` type is different between `Accordion` and `Paper` (of which the former inherits most props).

## Props naming conflicts:

- For uppercase names, always use @as and write the first letter lowercase
  - if there is a conflict, add a `_` behind the name
  - Examples: -`InputProps` conflicts with `inputProps` so it becomes `inputProps_` -`MuiSlider` becomes `muiSlider`
- For props that are ReScript keywords, add a `_` behind the name
  - Examples:
    - `type` becomes `type_`
    - `open` becomes `open_`
