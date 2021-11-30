module Styles = %makeStyles((
  {
    root: ReactDOM.Style.make(~width="100%", ~maxWidth="970px", ~margin="0 auto", ()),
    rounded: ReactDOM.Style.make(~backgroundColor="grey", ~color="white", ~padding="15px", ()),
  },
  {
    classNamePrefix: "xxx",
    generateId: () => "blasdnsad" ++ Js.Math.random_int(0, 100)->string_of_int,
  },
))

@react.component
let make = () => {
  let classes = Styles.useStyles()
  open Mui
  <Paper classes={Paper.Classes.make(~root=classes.root, ~rounded=classes.rounded, ())}>
    <Typography> {"Some Content"->React.string} </Typography>
  </Paper>
}
