# How to add bindings to rescript-mui

**Note**: For file watching you need to have [watchexec](https://github.com/watchexec/watchexec#install) installed.

1. Checkout this repository
2. `yarn install`
3. `yarn watch`
4. Do your changes (see below)
5. Use `yarn generateOverrides` to add any new classes also to the Overrides module.
6. Commit and create a Pull Request

## Use the d.ts as template

1. Take any component from MUI and look for its `d.ts` file, e.g. [Accordion.d.ts](https://github.com/mui/material-ui/blob/master/packages/mui-material/src/Accordion/Accordion.d.ts)
2. Copy the content of the props type over, including the documentation comments.
3. Copy also the classes type over, e.g. [accordionClasses.ts]([https://github.com/mui/material-ui/blob/master/packages/mui-material/src/Accordion/Accordion.d.ts](https://github.com/mui/material-ui/blob/master/packages/mui-material/src/Accordion/accordionClasses.ts))
4. Replace all `;` with `,` and adapt the types accordingly.
5. Have a look at [`Accordion.res`](https://github.com/cca-io/rescript-mui/blob/master/packages/rescript-mui-material/src/components/Accordion.res) for inspiration.

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
