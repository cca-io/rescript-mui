module Styles = %makeStyles((
  theme => {
    root: ReactDOM.Style.make(~width="100%", ~maxWidth="970px", ~margin="0 auto", ()),
    rounded: ReactDOM.Style.make(
      ~backgroundColor=theme.palette.background.paper,
      ~color=theme.palette.text.primary,
      ~padding="15px",
      (),
    ),
  },
  {name: "test"},
))

@react.component
let make = () => {
  let classes = Styles.useStyles()
  open Mui
  <Paper classes={Paper.Classes.make(~root=classes.root, ~rounded=classes.rounded, ())}>
    <Typography> {"Some Content"->React.string} </Typography>
  </Paper>
}
