let useStyles = Mui.Styles.makeStyles({
  "fontSize": ReactDOM.Style.make(~fontSize="30px", ()),
  "bgColor": ReactDOM.Style.make(~backgroundColor=Mui.Colors.red.c300, ()),
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
