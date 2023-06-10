let useStyles = Mui.Styles.makeStyles({
  "fontSize": {JsxDOMStyle.fontSize: "30px"},
  "bgColor": {JsxDOMStyle.backgroundColor: Mui.Colors.red["300"]},
})

@react.component
let make = () => {
  let classes = useStyles()

  <Mui.Button
    color=Primary
    variant=Contained
    classes={root: classes["fontSize"], containedPrimary: classes["bgColor"]}>
    {React.string("Example Button")}
  </Mui.Button>
}
