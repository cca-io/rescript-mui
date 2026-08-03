open Mui

@react.component
let make = () => {
  let subheader = <li />

  <Card>
    <Card>
      <CardHeader title={React.string("Example Title")} subheader={React.string("A Subtitle")} />
      <CardContent>
        <List subheader>
          {React.array(
            Array.map([0, 1, 2, 3, 4], sectionId =>
              <li key={"section-" ++ Int.toString(sectionId)}>
                <ul>
                  {React.array(
                    Array.concat(
                      [
                        <ListSubheader key="header">
                          {React.string("I'm sticky " ++ Int.toString(sectionId))}
                        </ListSubheader>,
                      ],
                      Array.map([0, 1, 2], item =>
                        <ListItem
                          key={"item-" ++ (Int.toString(sectionId) ++ ("-" ++ Int.toString(item)))}
                        >
                          <ListItemText>
                            {React.string("Item " ++ Int.toString(item))}
                          </ListItemText>
                        </ListItem>
                      ),
                    ),
                  )}
                </ul>
              </li>
            ),
          )}
        </List>
      </CardContent>
      <CardActions>
        <Button
          color=Primary
          variant=Contained
          href="#/example/route"
          rel="noreferrer noopener"
          target="_top"
        >
          {React.string("Go to example")}
        </Button>
      </CardActions>
    </Card>
  </Card>
}
