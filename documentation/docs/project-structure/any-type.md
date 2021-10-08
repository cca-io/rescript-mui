---
title: Any Type
---

If the type you need to pass cannot be determined you can usually insert the
`Any` type. It lives under `MaterialUi.Types`, but the global `MaterialUi`
module also includes it directly.

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
`MaterialUi.anyUnpack` will return an `Any` as `'a`):

```rescript
<MaterialUi.ToggleButtonGroup
  value={Any(alignment)}
  exclusive=true
  onChange={(_event, value) => setAlignment(MaterialUi.anyUnpack(value))}
/>
```
