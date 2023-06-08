open Mui

let useStyles = Styles.makeStylesWithTheme(theme =>
  {
    "alignRight": {JsxDOMStyle.width: "100%", textAlign: "right"},
    "background": {
      JsxDOMStyle.color: theme.palette.common.white,
      backgroundColor: theme.palette.primary.main,
    },
  }
)

@react.component
let make = () => {
  let classes = useStyles()

  <div>
    <div className={classes["alignRight"]}>
      {"Example text - aligned to the right"->React.string}
    </div>
    <br />
    <br />
    <div className={classes["background"]}>
      {"Example text on a background coming from the Mui Theme object"->React.string}
    </div>
  </div>
}
