# How to add bindings to rescript-mui

1. Checkout this repository
2. Have [corepack](https://nodejs.org/api/corepack.html) enabled: `corepack enable`
3. `yarn install`
4. `yarn watch`
5. Do your changes (see below)
6. Use `yarn generateOverrides` to add any new classes also to the Overrides module.
7. Commit and create a Pull Request

## Use the d.ts as template

1. Take any component from MUI and look for its `d.ts` file, e.g. [Accordion.d.ts](https://github.com/mui/material-ui/blob/master/packages/mui-material/src/Accordion/Accordion.d.ts)
2. Copy the content of the props type over, including the documentation comments.
3. Copy also the classes type over, e.g. [accordionClasses.ts](https://github.com/mui/material-ui/blob/master/packages/mui-material/src/Accordion/accordionClasses.ts). This one always must be `type classes` as it gets picked up by the `generateOverrides` script.
4. Replace all `;` with `,` and adapt the types accordingly.
5. Cross-check with the corresponding MUI page, e.g. https://mui.com/material-ui/api/accordion/, if you ended up with all the listed props (execept for deprecated ones)
6. Have a look at [`Accordion.res`](https://github.com/cca-io/rescript-mui/blob/master/packages/rescript-mui-material/src/components/Accordion.res) for inspiration.

## Props hierarchy

- Every main props type needs to inherit from `CommonProps.t`, except if MUI documentation explicitly says that only the listed props are the valid ones.
- If some component inherits from a MUI parent, the props to inherit from need to be called publicProps, e.g. `Paper.publicProps`. This is necessary, because prop names cannot be overwritten with different types. For instance the `classes` type is different between `Accordion` and `Paper` (of which the former inherits most props).

## Props naming conflicts:

- For uppercase names, always use @as and write the first letter lowercase
  - if there is a conflict, add a `_` behind the name
  - Examples:
    - `InputProps` conflicts with `inputProps` so it becomes `inputProps_`
    - `MuiSlider` becomes `muiSlider`
- For props that are [ReScript keywords](https://rescript-lang.org/docs/manual/latest/reserved-keywords), add a `_` behind the name
  - Examples:
    - `type` becomes `type_`
    - `open` becomes `open_`
