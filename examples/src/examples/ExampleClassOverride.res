let useStyles = Mui.Styles.makeStyles({
  "fontSize": {ReactDOM.Style.fontSize: "30px"},
  "bgColor": {backgroundColor: Mui.Colors.red["300"]},
})

@react.component
let make = () => {
  let classes = useStyles()

  <Mui.Button
    color=#primary
    variant=#contained
    classes={root: classes["fontSize"], containedPrimary: classes["bgColor"]}>
    {React.string("Example Button")}
  </Mui.Button>
}
