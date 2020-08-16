---
title: Union Values
---

## Union differences

While is is great to have a consistent usage for passing union values as props,
it can come at a conversion cost. This is why the current bindings make a
difference between 3 types of union values.

## String only unions

Whenever a prop on a component consists of a selection of string only literals,
the generator will use the
[[@bs.string]](https://reasonml.org/docs/reason-compiler/latest/function#constrain-arguments-better)
(will become obsolete with ReScript eventually) directive directly on the prop.
This will ensure a direct application of the string without conversion cost.

String only unions therefore need to get passed as a polymorphic variant. This
is an example of the prop `variant`, taken from `MaterialUi_Accordion.re`:

```reason
~variant: option<[
  | @bs.as("elevation") #Elevation
  | @bs.as("outlined") #Outlined
>=?,
```

You can use it like so:

```reason
<MaterialUi_Accordion variant=#Outlined />
```

### Rules for string only unions

- Always `[@bs.string]` in the external (you may ignore this if you're on
  `ReScript`)
- Always **uppercased** polymorphic variant of the original string value
- Invalid chars (like spaces) will be replaced by `_`

### Additional types

In case that you need to pass around the type of a string union prop, the
generator creates a helper type for you in the module. To continue the example
from earlier, the following helper type will be added to
`MaterialUi_Accordion.re`:

```reason
type variant = [ | #Elevation | #Outlined];
```

## Numeric unions

Similar to the string only unions, a union consisting of only numbers will
utilize the
[[bs.int]](https://reasonml.org/docs/reason-compiler/latest/function#constrain-arguments-better)
directive. Therefore, numerical unions will accept a form of polymorphic variant
as well.

These don't happen often - currently the only place where this applies is in the
`MaterialUi_Grid.re` component.

Example usage:

```reason
MaterialUi.(
  <Grid spacing=#V2 />
);
```

### Rules for numeric unions

- Always `@bs.string` in the external (you may ignore this if you're on
  `ReScript`)
- Always `` `V[NUM] `` format

## Mixed unions

Mixed unions make use of one of the newer features that bucklescript offers:
[[unboxed]](https://reasonml.org/blog/union-types-in-bucklescript). The nice
thing about unboxed is, that there is no conversion cost, just as with the above
ones. Some of the helper functions will leave a function in the generated js,
that just returns the one argument it gets passed. These can be stripped easily
with an optimization build step (e.g. with webpack).

Whenever a prop value can be a literal of multiple types, this way of typing it
is used. A module inside of the component is created, that is simply named after
the prop (**uppercased**).

Let's use the `component` prop of the `Grid` component as an example. We can
pass either a string, callback or element as the `component` prop. This will
generate the following module inside the `Grid` component file:

```reason
module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  @unboxed
  type rec t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};
```

You can use it in the following way:

```reason
open MaterialUi;
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
