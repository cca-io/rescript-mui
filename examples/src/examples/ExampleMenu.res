open Mui

@react.component
let make = () => {
  <Menu id="menu" component={OverridableComponent.string("nav")} open_=true>
    <MenuItem id="simple-menu-item-1"> {React.string("Profile")} </MenuItem>
    <MenuItem id="simple-menu-item-2"> {React.string("My account")} </MenuItem>
    <MenuItem id="simple-menu-item-3"> {React.string("Logout")} </MenuItem>
  </Menu>
}