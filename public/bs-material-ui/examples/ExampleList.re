module ExampleStyles = [%makeStyles
  {
    root:
      ReactDOMRe.Style.make(
        ~width="100%",
        ~maxWidth="360px",
        ~position="relative",
        ~overflow="auto",
        ~maxHeight="300px",
        ~backgroundColor="#FFFFFF",
        (),
      ),
    listSection: ReactDOMRe.Style.make(~backgroundColor="inherit", ()),
    ul: ReactDOMRe.Style.make(~backgroundColor="inherit", ~padding="0", ()),
  }
];

[@react.component]
let make = () => {
  let classes = ExampleStyles.useStyles();
  let subheader = <li />;
  MaterialUi.(
    <Card>
      <Card>
        <CardHeader
          title={React.string("Example Title")}
          subheader={React.string("A Subtitle")}
        />
        <CardContent>
          <List className={classes.root} subheader>
            {React.array(
               [|0, 1, 2, 3, 4|]
               |> Array.map(sectionId =>
                    <li
                      key={"section-" ++ string_of_int(sectionId)}
                      className={classes.listSection}>
                      <ul className={classes.ul}>
                        {React.array(
                           Array.append(
                             [|
                               <ListSubheader key="header">
                                 {React.string(
                                    "I'm sticky " ++ string_of_int(sectionId),
                                  )}
                               </ListSubheader>,
                             |],
                             [|0, 1, 2|]
                             |> Array.map(item =>
                                  <ListItem
                                    key={
                                      "item-"
                                      ++ string_of_int(sectionId)
                                      ++ "-"
                                      ++ string_of_int(item)
                                    }>
                                    <ListItemText>
                                      {React.string(
                                         "Item " ++ string_of_int(item),
                                       )}
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
          <Button color=`Primary variant=`Contained href="#/example/route">
            {React.string("Go to example")}
          </Button>
        </CardActions>
      </Card>
    </Card>
  );
};
