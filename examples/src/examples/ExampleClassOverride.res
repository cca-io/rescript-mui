open Mui

let useStyles = Styles.makeStyles({
  "fontSize": ReactDOM.Style.make(~fontSize="30px", ()),
  "bgColor": ReactDOM.Style.make(~backgroundColor=Mui.Colors.red["300"], ()),
})

@react.component
let make = () => {
  let classes = useStyles(.)

  <Button
    color=#primary
    variant=#contained
    classes={Button.Classes.make(
      ~root=classes["fontSize"],
      ~containedPrimary=classes["bgColor"],
      (),
    )}>
    {React.string("Example Button")}
  </Button>
}
