---
title: Any Type
---

If the type you need to pass cannot be determined you can usually insert the
`Any` type. It lives under `Mui.Types`.

:::info

In previous versions it also lived in the global `MaterialUi` module directly,
but this is no longer the case in version 3.0.0 and above

:::

Example for passing an `Any` value to a component:

```rescript
<TextField
  _InputProps={"readOnly": true}
  value={TextField.Value.string(value)}
  label={"Label"->React.string}
  fullWidth=true
  variant=#outlined
/>
```

Example for receiving an `Any` argument in a callback (The function
`Mui.Any.unsafeGetValue` will return an `Any` as `'a`):

```rescript
<Mui.ToggleButtonGroup
  value={Any(alignment)}
  exclusive=true
  onChange={(_event, value) => setAlignment(Mui.Any.unsafeGetValue(value))}
/>
```

More fleshed out example utilizing polymorphic variants:

```rescript
@react.component
let make = () => {
  let (state, setState) = React.useState(() => #Yes)

  open Mui
  <RadioGroup
    name="answer"
    value={Any.make(state)}
    onChange={e => {
      let value = (e->ReactEvent.Form.target)["value"]
      setState(_ => value->Any.unsafeGetValue)
    }}>
    <FormControlLabel value={Any.make(#Yes)} control={<Radio />} label={React.string("Yes")} />
    <FormControlLabel value={Any.make(#No)} control={<Radio />} label={React.string("No")} />
    <FormControlLabel value={Any.make(#Maybe)} control={<Radio />} label={React.string("Maybe")} />
  </RadioGroup>
}
```

As polymorphic variants compile to strings they are implicitly comparable by the
radio group component. This example would not work with common variants.
