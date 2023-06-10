open Mui

let useStyles = Styles.makeStyles({
  "root": {
    JsxDOMStyle.width: "100%",
    maxWidth: "360px",
    position: "relative",
    overflow: "auto",
    maxHeight: "300px",
    backgroundColor: "#FFFFFF",
  },
  "listSection": {JsxDOMStyle.backgroundColor: "inherit"},
  "ul": {JsxDOMStyle.backgroundColor: "inherit", padding: "0"},
})

@react.component
let make = () => {
  let classes = useStyles()
  let subheader = <li />

  <Card>
    <Card>
      <CardHeader title={React.string("Example Title")} subheader={React.string("A Subtitle")} />
      <CardContent>
        <List className={classes["root"]} subheader> {React.array(Array.map(sectionId =>
              <li key={"section-" ++ string_of_int(sectionId)} className={classes["listSection"]}>
                <ul className={classes["ul"]}>
                  {React.array(
                    Array.append(
                      [
                        <ListSubheader key="header">
                          {React.string("I'm sticky " ++ string_of_int(sectionId))}
                        </ListSubheader>,
                      ],
                      Array.map(item =>
                        <ListItem
                          key={"item-" ++
                          (string_of_int(sectionId) ++
                          ("-" ++ string_of_int(item)))}>
                          <ListItemText>
                            {React.string("Item " ++ string_of_int(item))}
                          </ListItemText>
                        </ListItem>
                      , [0, 1, 2]),
                    ),
                  )}
                </ul>
              </li>
            , [0, 1, 2, 3, 4]))} </List>
      </CardContent>
      <CardActions>
        <Button color=Primary variant=Contained href="#/example/route">
          {React.string("Go to example")}
        </Button>
      </CardActions>
    </Card>
  </Card>
}
