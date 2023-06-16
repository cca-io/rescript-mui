open Mui

@react.component
let make = () => {
  let subheader = <li />

  <Card>
    <Card>
      <CardHeader title={React.string("Example Title")} subheader={React.string("A Subtitle")} />
      <CardContent>
        <List subheader> {React.array(Array.map(sectionId =>
              <li key={"section-" ++ string_of_int(sectionId)}>
                <ul>
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
