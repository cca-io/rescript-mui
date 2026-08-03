# ReScript Bindings for MUI

## Installation

1. Install all necessary packages according to the official MUI-Material installation guide: https://mui.com/material-ui/getting-started/installation/.
2. Install `@rescript-mui/material`

```sh
npm install @rescript-mui/material
```

3. Add it to `dependencies` in your `rescript.json`:

```json
{
  "dependencies": ["@rescript-mui/material"]
}
```

This library provides [ReScript](https://rescript-lang.org/) bindings for [MUI](https://mui.com/).

These bindings will only work with ReScript 12+ (uncurried mode) and JSX version 4, as it enables us to utilize [untagged variants](https://rescript-lang.org/blog/improving-interop#untagged-variants), optional record fields, and record props spread. The latter is especially important, as we are finally able to inherit props from one component to another more easily.

## Examples
Have a look at the [examples folder](./examples/).

## What's inside?

| MUI package         | ReScript bindings package                                               | Namespace        | Progress |
| ------------------- | ----------------------------------------------------------------------- | ---------------- | -------: |
| @mui/material       | [@rescript-mui/material](./packages/rescript-mui-material/)             | Mui              |    100 % |
| @mui/lab            | [@rescript-mui/lab](./packages/rescript-mui-lab/)                       | MuiLab           |    100 % |
| @mui/x-date-pickers | [@rescript-mui/x-date-pickers](./packages/rescript-mui-x-date-pickers/) | MuiXDatePickers  |    100 % |
| @mui/system         | [@rescript-mui/system](./packages/rescript-mui-system/)                 | MuiSystem        |      0 % |
| @mui/base           | Not implemented!                                                        | MuiBase (?)      |        - |
| @mui/joy            | Not implemented!                                                        | Joy (?)          |        - |
| @mui/x-data-grid    | Not implemented!                                                        | MuiXDataGrid (?) |        - |

NOTE: `@mui/styles` will never be implemented, as it is the legacy styling solution which is not compatible with `React.StrictMode` or React 18.

## Documentation

See [documentation](./documentation/README.md).

## Changelog

See [CHANGELOG](./CHANGELOG.md).

## Maintenance scripts

The [`scripts/`](./scripts/) folder contains two Node helpers used when bumping the bindings to a new MUI version. Both read the actual TypeScript definitions from the installed `@mui/material` package, so first run `yarn install` with the target MUI version, then run them **from the repository root**.

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

## Contributing

See [CONTRIBUTING](./CONTRIBUTING.md).
