open Mui

@react.component
let make = () => {
  let (selectedIndex, setSelectedIndex) = React.useState(_ => 1)

  let handleListItemClick = (_event, index) => {
    setSelectedIndex(_ => index)
  }

  <div>
    <Typography variant=H6> {"ListItemButton Examples:"->React.string} </Typography>
    <Box>
      <List component={OverridableComponent.string("string")}  ariaLabel="main mailbox folders">
        <ListItem disablePadding=true>
          <ListItemButton
            id="list-item-button-inbox"
            selected={selectedIndex === 0}
            onClick={event => handleListItemClick(event, 0)}>
            <ListItemIcon>
              <span>{"📥"->React.string}</span>
            </ListItemIcon>
            <ListItemText primary={"Inbox"->React.string} />
          </ListItemButton>
        </ListItem>
        <ListItem disablePadding=true>
          <ListItemButton
            id="list-item-button-drafts"
            selected={selectedIndex === 1}
            onClick={event => handleListItemClick(event, 1)}>
            <ListItemIcon>
              <span>{"📝"->React.string}</span>
            </ListItemIcon>
            <ListItemText primary={"Drafts"->React.string} />
          </ListItemButton>
        </ListItem>
      </List>
      <Divider />
      <List component={OverridableComponent.string("nav")} ariaLabel="secondary mailbox folders">
        <ListItem disablePadding=true>
          <ListItemButton id="list-item-button-trash">
            <ListItemText primary={"Trash"->React.string} />
          </ListItemButton>
        </ListItem>
        <ListItem disablePadding=true>
          <ListItemButton id="list-item-button-spam" href="#spam-link" component={OverridableComponent.string("a")}>
            <ListItemText primary={"Spam"->React.string} />
          </ListItemButton>
        </ListItem>
      </List>
    </Box>
  </div>
}
