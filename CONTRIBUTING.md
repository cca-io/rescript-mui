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

## Maintenance scripts

The [`scripts/`](./scripts/) folder contains two Node helpers used when bumping the bindings to a new MUI version. Both read the actual TypeScript definitions from the installed `@mui/material` package, so first run `yarn install` with the target MUI version, then run them from the repository root.

### `scripts/gen-classes.mjs`

Regenerates the `type classes = {...}` block of material components from the real `@mui/material/<Component>/<component>Classes.d.ts` files (doc comments included). Useful whenever MUI adds, removes or renames CSS classes.

```sh
# dry-run: print the generated block for every component (nothing is written)
node scripts/gen-classes.mjs

# dry-run for specific components only
node scripts/gen-classes.mjs Button Chip

# write the changes into the .res files
node scripts/gen-classes.mjs --apply Button Chip

# ...or regenerate every component at once
node scripts/gen-classes.mjs --apply
```

After running with `--apply`, rebuild (`yarn build`) and regenerate the theme overrides (`yarn generateOverrides`) so the `*ClassKey` types stay in sync.

### `scripts/prop-diff2.mjs`

Reports props that exist in the current MUI `.d.ts` but are missing from a binding. It reads each material component's own props (resolving ReScript record spreads such as `...Paper.publicProps` transitively) and diffs them against the component's own-props interface in the `.d.ts`.

```sh
node scripts/prop-diff2.mjs
```

Every line lists a component and the props it is missing; no output means everything is in sync. It cannot inspect components whose props are a plain type alias without an `OwnProps`/`Props` interface (e.g. `Box`, `Select`) — those need a manual check.

## Releases

- Keep the base version (e.g. `6.1.0`) in each package `package.json`. Do not add prerelease suffixes there.
- Merges to `master` publish prereleases for changed packages as `6.1.0-dev.N` with npm dist-tag `next`.
- Stable releases are triggered by pushing a git tag like `v6.1.0` and publish with npm dist-tag `latest`.
