let component = ReasonReact.statelessComponent("Example");

[%mui.withStyles
  "ExampleStyles"({
    root:
      ReactDOMRe.Style.make(
        ~width="100%",
        ~maxWidth="360px",
        ~position="relative",
        ~overflow="auto",
        ~maxHeight="300px",
        ~backgroundColor="#FFFFFF",
        ()
      ),
    listSection: ReactDOMRe.Style.make(~backgroundColor="inherit", ()),
    ul: ReactDOMRe.Style.make(~backgroundColor="inherit", ~padding="0", ())
  })
];

let make = _children => {
  ...component,
  render: _self => {
    let subheader = <li />;
    MaterialUi.(
      <ExampleStyles
        render=(
          classes =>
            <Card>
              <CardHeader
                title=(ReasonReact.stringToElement("Example Title"))
                subheader=(ReasonReact.stringToElement("A Subtitle"))
              />
              <CardContent>
                <List className=classes.root subheader>
                  (
                    ReasonReact.arrayToElement(
                      [|0, 1, 2, 3, 4|]
                      |> Array.map(sectionId =>
                           <li
                             key=("section-" ++ string_of_int(sectionId))
                             className=classes.listSection>
                             <ul className=classes.ul>
                               (
                                 ReasonReact.arrayToElement(
                                   Array.append(
                                     [|
                                       <ListSubheader key="header">
                                         (
                                           ReasonReact.stringToElement(
                                             "I'm sticky "
                                             ++ string_of_int(sectionId)
                                           )
                                         )
                                       </ListSubheader>
                                     |],
                                     [|0, 1, 2|]
                                     |> Array.map(item =>
                                          <ListItem
                                            key=(
                                              "item-"
                                              ++ string_of_int(sectionId)
                                              ++ "-"
                                              ++ string_of_int(item)
                                            )>
                                            <ListItemText
                                              primary=(
                                                ReasonReact.stringToElement(
                                                  "Item "
                                                  ++ string_of_int(item)
                                                )
                                              )
                                            />
                                          </ListItem>
                                        )
                                   )
                                 )
                               )
                             </ul>
                           </li>
                         )
                    )
                  )
                </List>
              </CardContent>
              <CardActions>
                <Button color=`Primary variant=`Raised href="#/example/route">
                  (ReasonReact.stringToElement("Go to example"))
                </Button>
              </CardActions>
            </Card>
        )
      />
    );
  }
};