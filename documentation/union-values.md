---
title: Union Values (TODO)
---

## Union differences

While is is great to have a consistent usage for passing union values as props,
it can come at a conversion cost. This is why the current bindings make a
difference between 3 types of union values.

## String only unions

Whenever a prop on a component consists of a selection of string literals, the
bindings use an `@unboxed` variant. Each case is mapped to its original string
value with `@as`, and an escape hatch case `String(string)` is added so you can
still pass custom values (e.g. custom theme colors).

This is an example of the prop `variant`, taken from `Mui.Paper.res`:

```rescript
@unboxed
type variant =
  | @as("elevation") Elevation
  | @as("outlined") Outlined
  | String(string)
```

You can use it like so:

```rescript
<Mui.Paper variant=Outlined />
```

### Rules for string unions

- All variant cases are capitalized (ReScript requires it), while `@as` keeps the
  original string value (mostly lowercase).
- The `String(string)` case lets you pass any custom value, e.g.:
  `variant=String("custom")`.

### Additional types

In case you need to pass around the type of a string union prop, it is exposed as
a helper type in the module, e.g. `Mui.Paper.variant`.

## Numeric unions

Numeric unions use `@unboxed` variants with an `Int` case (they no longer use the
`@int` directive).

Example usage on `Mui.Grid`:

```rescript
<Mui.Grid spacing={Int(2)} />
```

## Mixed unions

Mixed unions make use of the ReScript's `unboxed` decorator:
[[unboxed]](https://rescript-lang.org/blog/union-types-in-bucklescript). The
nice thing about unboxed is, that there is no conversion cost, just as with the
above ones. Some of the helper functions will leave a function in the generated
js, that just returns the one argument it gets passed. These can be stripped
easily with an optimization build step (e.g. with webpack).

Whenever a prop value can be a literal of multiple types, this way of typing it
is used. A module inside of the component is created, that is simply named after
the prop (**uppercased**).

Let's use the `component` prop of the `Grid` component as an example. We can
pass either a string, callback or element as the `component` prop. This will
generate the following module inside the `Grid` component file:

```rescript
module Component: {
  type t
  let string: string => t
  let callback: (unit => React.element) => t
  let element: React.element => t
} = {
  @unboxed
  type rec t =
    | Any('a): t
  let string = (v: string) => Any(v)
  let callback = (v: unit => React.element) => Any(v)
  let element = (v: React.element) => Any(v)
}
```

You can use it in the following way:

```rescript
open Mui
<div>
  <Grid component=Grid.Component.string("div") />
  <Grid component=Grid.Component.element(<div />) />
</div>
```

### Rules for mixed unions

- Always creates a module leveraging `@unboxed` with the uppercased name of the
  prop
- Always fills that module with helper functions that are named after the type
  they represent
- Literal values don't have helper functions, but are represented as let
  bindings
- Numeric literals are always prefixed with `_` (e.g. `Grid.Md._2`)
- Boolean literals are always prefixed with `_` (e.g. `Grid.Md._false`)
- String literals are always their lowercased self (e.g. `Grid.Md.auto`)
