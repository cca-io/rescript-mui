---
title: useStyles hook
---

The `useStyles` hook is new in version 3.0.0 of this bindings. It is the
recommended way to replace `withStyles` PPX calls. It utilizes MUI's
`makeStyles` function to generate MUI Styles objects.

### Example

```rescript
let useStyles = Mui.Styles.makeStyles({
  "fontSize": ReactDOM.Style.make(~fontSize="30px", ()),
  "bgColor": ReactDOM.Style.make(~backgroundColor=Mui.Colors.red["300"], ()),
})

@react.component
let make = () => {
  let classes = useStyles(.)

  <Mui.Button
    color=#primary
    variant=#contained
    classes={Mui.Button.Classes.make(
      ~root=classes["fontSize"],
      ~containedPrimary=classes["bgColor"],
      (),
    )}>
    {React.string("Example Button")}
  </Mui.Button>
}
```
