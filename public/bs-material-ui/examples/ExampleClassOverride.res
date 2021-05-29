module OverrideExample = %makeStyles({
  fontSize: ReactDOM.Style.make(~fontSize="30px", ()),
  bgColor: ReactDOM.Style.make(~backgroundColor=MaterialUi.Colors.red["300"], ()),
})

@react.component
let make = () => {
  let classes = OverrideExample.useStyles()

  open MaterialUi
  <Button
    color=#primary
    variant=#contained
    classes={Button.Classes.make(~root=classes.fontSize, ~containedPrimary=classes.bgColor, ())}>
    {React.string("Example Button")}
  </Button>
}
