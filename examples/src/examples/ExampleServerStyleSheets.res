open Mui

let useStyles = Styles.makeStyles({
  "code": ReactDOM.Style.make(
    ~fontFamily="SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace",
    ~marginTop="15px",
    (),
  ),
})

@react.component
let make = () => {
  let classes = useStyles()
  let (html, css) = React.useMemo0(() => {
    let sheets = Mui.Core.ServerStyleSheets.make()
    let html = ReactDOMServer.renderToString(
      sheets->Mui.Core.ServerStyleSheets.collect(<ExampleBox />),
    )
    let css = sheets->Mui.Core.ServerStyleSheets.toString
    (html, css)
  })

  <div>
    <Typography variant=H5> {"ServerSide render of <ExampleBox />"->React.string} </Typography>
    <TextField
      className={classes["code"]}
      rows={TextField.Rows.int(5)}
      label={"HTML"->React.string}
      multiline=true
      fullWidth=true
      variant=#outlined
      defaultValue={TextField.DefaultValue.string(html)}
    />
    <TextField
      className={classes["code"]}
      rows={TextField.Rows.int(5)}
      label={"CSS"->React.string}
      multiline=true
      fullWidth=true
      variant=#outlined
      defaultValue={TextField.DefaultValue.string(css)}
    />
  </div>
}
