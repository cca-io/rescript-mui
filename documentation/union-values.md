---
title: Union Values
---

## Union differences

The bindings use unboxed variants for values that may be represented by more
than one JavaScript literal. They compile directly to their underlying value,
without allocating a tagged JavaScript object.

## String unions

Whenever a prop consists of a selection of string literals, the bindings use an
`@unboxed` variant. Each case is mapped to its original string value with `@as`.
Where MUI permits custom values, a `String(string)` escape hatch is included.

This is the `variant` prop from `Mui.Paper`:

```rescript
@unboxed
type variant =
  | @as("elevation") Elevation
  | @as("outlined") Outlined
  | String(string)
```

Usage:

```rescript
<Mui.Paper variant=Outlined />
```

### Rules for string unions

- Cases are capitalized for ReScript and mapped to the original JavaScript
  string with `@as`.
- A `String(string)` case accepts custom values when MUI supports them.
- The component module exposes the type, for example `Mui.Paper.variant`.

## Numeric unions

Numeric unions also use unboxed variants. Numeric cases are represented by an
`Int(int)` or `Number(float)` payload, depending on the MUI API.

Example usage:

```rescript
<Mui.Grid spacing={Int(2)} />
```

## Mixed unions

Mixed unions combine literal cases and payload cases in one unboxed variant.
For example, `Mui.Grid.size` accepts the MUI string and boolean literals as well
as integer grid sizes:

```rescript
@unboxed
type value =
  | @as("auto") Auto
  | @as("grow") Grow
  | @as(false) False
  | Int(int)
```

Example usage:

```rescript
<Mui.Grid size={Int(6)} />
<Mui.Grid size=Grow />
```
