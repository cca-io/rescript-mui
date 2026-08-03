# @rescript-mui documentation

## Naming

`@rescript-mui/material` provides all components in individual files. The file
pattern is:

    Mui.[COMPONENT_NAME].res

If you wish to use the `Typography` component for example, it would look like
this:

```rescript
<Mui.Typography>
  {"Some example text"->React.string}
</Mui.Typography>
```

The component names map one to one to the ones found in the `Component API`
section of the MUI documentation.

## Namespace

The material package uses the `Mui` namespace. To avoid name clashes, prefer
qualified component names such as `Mui.Typography` over opening the whole
namespace.

```rescript
@react.component
let make = () =>
  <div>
    <Mui.Typography variant=H4 gutterBottom=true>
      {"Headline"->React.string}
    </Mui.Typography>
    <Mui.Typography>
      {"Some example text"->React.string}
    </Mui.Typography>
  </div>
```

## Supporting modules

The `Mui` namespace also contains bindings and types used across components:

- [Colors](module-colors.md)
- [System and `sx`](module-system.md)
- [Theming](theming.md)
- [Union values](union-values.md)

## Styling

MUI components accept `className`, `classes`, and `sx`, depending on the
component. The following pages show common styling approaches:

- [CSS](css.md)
- [Tailwind CSS](tailwind.md)
- [CSS-in-ReScript libraries such as `bs-css`](bs-css.md)
