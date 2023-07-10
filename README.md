# ReScript Bindings for MUI (WIP!)

## Installation

1. Install all necessary packages according to the official MUI-Material installation guide: https://mui.com/material-ui/getting-started/installation/.
2. Install `@rescript-mui/material`

```sh
npm install @rescript-mui/material
```

3. Add it to `dependencies` in your `bsconfig.json`:

```json
{
  "bs-dependencies": ["@rescript-mui/material"]
}
```

This library provides [ReScript](https://rescript-lang.org/) bindings for [MUI](https://mui.com/).

These bindings will only work with ReScript 11 (uncurried mode) and JSX version 4, as it enables us to utilize [untagged variants](https://rescript-lang.org/blog/improving-interop#untagged-variants), optional record fields, and record props spread. The latter is especially important, as we are finally able to inherit props from one component to another more easily.

## What happened to the bindings for Material-UI 4?

They are still available, check out the old website: https://rescript-material-ui.cca.io/.

## Why no new website?

1. One of the goals of this rewrite is to make the usage of MUI in ReScript more accessible. In the best case you never need to leave your editor, since now we have doc comments for (almost) every property.
2. It just takes too much time to maintain.
3. In our opinion, it is much more useful (albeit not as pretty) to just have a look at the [examples folder](./examples/).

## What's inside?

| MUI package         | ReScript bindings package                                               | Namespace        | Progress |
| ------------------- | ----------------------------------------------------------------------- | ---------------- | -------: |
| @mui/material       | [@rescript-mui/material](./packages/rescript-mui-material/)             | Mui              |     99 % |
| @mui/lab            | [@rescript-mui/lab](./packages/rescript-mui-lab/)                       | MuiLab           |    100 % |
| @mui/x-date-pickers | [@rescript-mui/x-date-pickers](./packages/rescript-mui-x-date-pickers/) | MuiXDatePickers  |     30 % |
| @mui/base           | Not implemented!                                                        | MuiBase (?)      |        - |
| @mui/joy            | Not implemented!                                                        | Joy (?)          |        - |
| @mui/system         | Not implemented!                                                        | MuiSystem (?)    |        - |
| @mui/x-data-grid    | Not implemented!                                                        | MuiXDataGrid (?) |        - |

NOTE: `@mui/styles` will never be implemented, as it is the legacy styling solution which is not compatible with `React.StrictMode` or React 18.

## Documentation

See [documentation](./documentation/README.md).

## Changelog

See [CHANGELOG](./CHANGELOG.md).

## Contributing

See [CONTRIBUTING](./CONTRIBUTING.md).
