open Mui

let useStyles = Styles.makeStyles({
  "code": {
    JsxDOMStyle.fontFamily: "SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace",
    marginTop: "15px",
  },
})

@react.component
let make = () => {
  let classes = useStyles()

  let (html, css) = React.useMemo0(() => {
    let sheets = Mui.Core.ServerStyleSheets.make()
    let css = sheets->Mui.Core.ServerStyleSheets.toString

    let html = ReactDOMServer.renderToString(
      sheets->Mui.Core.ServerStyleSheets.collect(<ExampleBox />),
    )

    (html, css)
  })

  <div>
    <Typography variant=H5> {"ServerSide render of <ExampleBox />"->React.string} </Typography>
    <TextField
      className={classes["code"]}
      rows=5
      label={"HTML"->React.string}
      multiline=true
      fullWidth=true
      variant=Outlined
      defaultValue={html}
    />
    <TextField
      className={classes["code"]}
      rows={5}
      label={"CSS"->React.string}
      multiline=true
      fullWidth=true
      variant=Outlined
      defaultValue={css}
    />
  </div>
}
