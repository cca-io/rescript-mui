# ReScript Bindings for MUI

This library provides [ReScript](https://rescript-lang.org/) bindings for [MUI](https://mui.com/).

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

These bindings will only work with ReScript 12+ (uncurried mode) and JSX version 4, as it enables us to utilize [untagged variants](https://rescript-lang.org/blog/improving-interop#untagged-variants), optional record fields, and record props spread. The latter is especially important, as we are finally able to inherit props from one component to another more easily.

## Examples

Have a look at the [examples folder](./examples/).

## Packages

| MUI package         | ReScript bindings package                                               | Namespace       |
| ------------------- | ----------------------------------------------------------------------- | --------------- |
| @mui/material       | [@rescript-mui/material](./packages/rescript-mui-material/)             | `Mui`           |
| @mui/lab            | [@rescript-mui/lab](./packages/rescript-mui-lab/)                       | `MuiLab`        |
| @mui/x-date-pickers | [@rescript-mui/x-date-pickers](./packages/rescript-mui-x-date-pickers/) | `MuiXDatePickers` |

## Documentation

See [documentation](./documentation/README.md).

## Changelog

See [CHANGELOG](./CHANGELOG.md).

## Contributing

See [CONTRIBUTING](./CONTRIBUTING.md).
