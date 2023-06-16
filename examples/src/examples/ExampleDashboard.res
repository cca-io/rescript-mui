open Mui

let drawerWidth = 240

let px_of_int = x => x->string_of_int ++ "px"

module MenuIcon = {
  @react.component @module("@mui/icons-material/Menu")
  external make: unit => React.element = "default"
}

module NotificationsIcon = {
  @react.component @module("@mui/icons-material/Notifications")
  external make: unit => React.element = "default"
}

module ChevronLeftIcon = {
  @react.component @module("@mui/icons-material/ChevronLeft")
  external make: unit => React.element = "default"
}

type state = {isOpen: bool}

type action =
  | Open
  | Close

@react.component
let make = (~sidebar, ~children) => {
  let (state, setState) = React.useReducer((_, action) =>
    switch action {
    | Open => {isOpen: true}
    | Close => {isOpen: false}
    }
  , {isOpen: true})

  let (show, setShow) = React.useReducer((_, v) => v, false)

  <div>
    {show
      ? <div>
          <CssBaseline />
          <AppBar position=#absolute>
            <Toolbar disableGutters={!state.isOpen}>
              <IconButton color=Inherit onClick={_event => setState(Open)}>
                <MenuIcon />
              </IconButton>
              <Typography component={OverridableComponent.string("h1")} variant=H6 noWrap=true>
                {"Dashboard"->React.string}
              </Typography>
              <Link
                href="#"
                onClick={e => {
                  e->ReactEvent.Mouse.preventDefault
                  setShow(false)
                }}
                color=TextSecondary>
                {"Close Dashboard"->React.string}
              </Link>
              <IconButton color=Inherit>
                <Badge badgeContent={"4"->React.string} color=Secondary>
                  <NotificationsIcon />
                </Badge>
              </IconButton>
            </Toolbar>
          </AppBar>
          <Drawer variant=Permanent open_=state.isOpen>
            <IconButton onClick={_event => setState(Close)}>
              <ChevronLeftIcon />
            </IconButton>
            <Divider />
            <div> sidebar </div>
          </Drawer>
          <main>
            <div> children </div>
          </main>
        </div>
      : <Button variant=Outlined color=Primary onClick={_ => setShow(true)}>
          {"Open Dashboard"->React.string}
        </Button>}
  </div>
}
