---
title: Union Values
---

## Union differences

While is is great to have a consistent usage for passing union values as props,
it can come at a conversion cost. This is why the current bindings make a
difference between 3 types of union values.

## String only unions

Whenever a prop on a component consists of a selection of string only literals,
the generator will create polymorphic variants which just happen to compile to
JS strings anyway.

This is an example of the prop `variant`, taken from `MaterialUi.Accordion.re`:

```rescript
type variant = [#elevation | #outlined]
```

You can use it like so:

```rescript
<MaterialUi.Accordion variant=#outlined />
```

### Rules for string only unions

- All polymorphic variants have the same case as the original string value now
  (mostly lowercase)
- Some values include invalid characters (like `-`), which makes it necessary to
  use quotes, e.g.: `#"flex-end"`

### Additional types

In case that you need to pass around the type of a string union prop, the
generator creates a helper type for you in the module. To continue the example
from earlier, the following helper type will be added to
`MaterialUi.Accordion.re`:

```rescript
type variant = [#elevation | #outlined]
```

## Numeric unions

A union consisting of only numbers will utilize the
[[@int]](https://rescript-lang.org/docs/manual/latest/bind-to-js-function#constrain-arguments-better)
directive. Therefore, numerical unions will accept a form of polymorphic variant
as well.

These don't happen often - currently the only place where this applies is in the
`MaterialUi.Grid.re` component.

Example usage:

```rescript
<MaterialUi.Grid spacing=#2 />
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
open MaterialUi
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
