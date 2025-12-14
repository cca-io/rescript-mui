/***
The `Sx` module provides type-safe bindings for MUI's `sx` prop, which allows
defining CSS styles using MUI's system properties.

The `sx` prop accepts `Sx.props`, which can be created using:
- `Sx.obj` - for a single style object
- `Sx.array` - for multiple style objects (useful for conditional styles)
- `Sx.func` - for theme-dependent styles
- `Sx.dict` - for dynamic style keys

## Basic Usage

```rescript
<Box sx={Sx.obj({
  display: String("flex"),
  flexDirection: String("column"),
  gap: String("16px"),
  padding: Number(2.),  // theme.spacing(2)
  bgcolor: PrimaryLight,  // theme.palette.primary.light
  alignItems: Center,
})}>
  {React.string("Content")}
</Box>
```

## Using Theme Colors

Use predefined variants for theme colors instead of raw strings:

```rescript
<Box sx={Sx.obj({
  bgcolor: BackgroundPaper,      // theme.palette.background.paper
  color: TextPrimary,            // theme.palette.text.primary
  borderColor: ErrorMain,        // theme.palette.error.main
})} />
```

## Using CSS Values

For standard CSS values, use the appropriate `System.Value.t` variant:

```rescript
<Box sx={Sx.obj({
  display: String("flex"),       // arbitrary string
  alignItems: Center,            // predefined "center"
  justifyContent: FlexStart,     // predefined "flex-start"
  width: String("100%"),         // percentage as string
  height: Number(200.),          // numeric value
  padding: String("16px"),       // px value as string
})} />
```
*/
module Array = {
  type t
  type cb<'theme> = 'theme => t

  /** Convert a bool to an array element (useful for conditional styles) */
  external bool: bool => t = "%identity"

  /** Create a theme-dependent style in an array context */
  external func: cb<'theme> => t = "%identity"

  /** Create a style object in an array context */
  external obj: System.props => t = "%identity"

  /** Create a style dict in an array context */
  external dict: Js.Dict.t<System.props> => t = "%identity"
}

/** The type for the `sx` prop on MUI components */
type props

/**
Create an `sx` prop from an array of styles. Useful for conditional styling.

```rescript
<Box sx={Sx.array([
  Sx.Array.obj({padding: Number(2.)}),
  Sx.Array.obj({bgcolor: if isActive PrimaryLight else BackgroundDefault}),
])} />
```
*/
external array: array<Array.t> => props = "%identity"

/**
Create an `sx` prop from a function that receives the theme. Useful for styling css properties that are not theme-aware.

```rescript
<Box sx={Sx.func(theme => {
  padding: Number(2.),
  color: PrimaryMain,
  boxShadow: String(theme.shadows[4]),
})} />
```
*/
external func: 'theme => props = "%identity"

/**
Create an `sx` prop from a System.props record. This is the most common usage.

All values in the record must be of type `System.Value.t`:
- Use `String("value")` for arbitrary CSS strings
- Use `Number(n)` for numeric values (often theme spacing multipliers)
- Use predefined variants like `Center`, `FlexStart`, `PrimaryLight`, etc.

```rescript
<Mui.Box sx={Mui.Sx.obj({
  display: String("flex"),
  flexDirection: String("column"),
  gap: String("16px"),
  maxWidth: String("300px"),
  padding: Number(2.),
  margin: Number(1.),
  bgcolor: PrimaryLight,
  alignItems: Center,
  justifyContent: FlexStart,
})} />
```
*/
external obj: System.props => props = "%identity"

/**
Create an `sx` prop from a dictionary. Useful for dynamic style keys.

```rescript
let styles = dict{"&:hover": System.props{bgcolor: PrimaryMain}}
<Box sx={Sx.dict(styles)} />
```
*/
external dict: Js.Dict.t<System.props> => props = "%identity"
