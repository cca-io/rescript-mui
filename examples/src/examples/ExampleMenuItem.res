open Mui

@react.component
let make = () => {
  let (anchorEl, setAnchorEl) = React.useState(_ => Js.Nullable.null)
  let open_ = !Js.Nullable.isNullable(anchorEl)
  
  let handleClick = (event) => {
    setAnchorEl(_ => ReactEvent.Mouse.currentTarget(event)->Js.Nullable.return)
  }
  
  let handleClose = () => {
    setAnchorEl(_ => Js.Nullable.null)
  }

  <div>
    <Typography variant=H6> {"MenuItem Examples:"->React.string} </Typography>
    <Box>
      <Button
        id="basic-button"
        onClick=handleClick>
        {"Dashboard Menu"->React.string}
      </Button>
      <Menu
        id="basic-menu"
        open_
        onClose={(_, _) => handleClose()}>
        <MenuItem id="menu-item-profile" onClick={_ => handleClose()}>
          {"Profile"->React.string}
        </MenuItem>
        <MenuItem id="menu-item-account" onClick={_ => handleClose()}>
          {"My account"->React.string}
        </MenuItem>
        <MenuItem id="menu-item-logout" onClick={_ => handleClose()}>
          {"Logout"->React.string}
        </MenuItem>
      </Menu>

      <Box >
        <Paper >
          <MenuList>
            <MenuItem id="menu-list-item-cut">
              <ListItemIcon>
                <span>{"✂️"->React.string}</span>
              </ListItemIcon>
              <ListItemText>{"Cut"->React.string}</ListItemText>
              <Typography variant=Body2 color={TextSecondary}>
                {"⌘X"->React.string}
              </Typography>
            </MenuItem>
            <MenuItem id="menu-list-item-copy">
              <ListItemIcon>
                <span>{"📋"->React.string}</span>
              </ListItemIcon>
              <ListItemText>{"Copy"->React.string}</ListItemText>
              <Typography variant=Body2 color={TextSecondary}>
                {"⌘C"->React.string}
              </Typography>
            </MenuItem>
            <MenuItem id="menu-list-item-paste">
              <ListItemIcon>
                <span>{"📌"->React.string}</span>
              </ListItemIcon>
              <ListItemText>{"Paste"->React.string}</ListItemText>
              <Typography variant=Body2 color={TextSecondary}>
                {"⌘V"->React.string}
              </Typography>
            </MenuItem>
            <Divider />
            <MenuItem id="menu-list-item-cloud">
              <ListItemIcon>
                <span>{"☁️"->React.string}</span>
              </ListItemIcon>
              <ListItemText>{"Web Clipboard"->React.string}</ListItemText>
            </MenuItem>
          </MenuList>
        </Paper>
      </Box>
    </Box>
  </div>
}
