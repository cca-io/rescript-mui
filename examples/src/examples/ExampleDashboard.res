/*
     This example shows how to create a fully styled dashboard component with css breakpoints and transitions
     converted from github.com/mui-org/material-ui/tree/master/docs/src/pages/getting-started/page-layout-examples/dashboard
 */

open Mui

let drawerWidth = 240

let px_of_float = x => x->int_of_float->string_of_int ++ "px"
let px_of_int = x => x->string_of_int ++ "px"

let useStyles = Styles.makeStylesWithTheme(theme =>
  {
    "wrapper": ReactDOM.Style.make(
      ~position="fixed",
      ~width="100vw",
      ~height="100vh",
      ~zIndex="999999",
      ~left="0",
      ~top="0",
      ~background="#FFFFFF",
      (),
    ),
    "root": ReactDOM.Style.make(~display="flex", ()),
    "toolbar": ReactDOM.Style.make(~paddingRight="24px", ()),
    // keep right padding when drawer closed
    "toolbarIcon": ReactDOM.Style.combine(
      ReactDOM.Style.make(
        ~display="flex",
        ~alignItems="center",
        ~justifyContent="flex-end",
        ~padding="0 8px",
        (),
      ),
      theme.mixins.toolbar,
    ),
    "appBar": ReactDOM.Style.make(
      ~zIndex=(theme.zIndex.drawer +. 1.0)->int_of_float->string_of_int,
      ~transition=ThemeHelpers.transitionCreate(
        ~theme,
        ~affectWidth=true,
        ~affectMargin=true,
        ~easing=theme.transitions.easing.sharp,
        ~duration=theme.transitions.duration.leavingScreen,
        (),
      ),
      (),
    ),
    "appBarShift": ReactDOM.Style.make(
      ~marginLeft=drawerWidth->string_of_int ++ "px",
      ~width=j`calc(100% - $(drawerWidth)px)`,
      ~transition=ThemeHelpers.transitionCreate(
        ~theme,
        ~affectWidth=true,
        ~affectMargin=true,
        ~easing=theme.transitions.easing.sharp,
        ~duration=theme.transitions.duration.enteringScreen,
        (),
      ),
      (),
    ),
    "menuButton": ReactDOM.Style.make(~marginLeft="12px", ~marginRight="36px", ()),
    "menuButtonHidden": ReactDOM.Style.make(~display="none", ()),
    "title": ReactDOM.Style.make(~flexGrow="1", ()),
    "drawerPaper": ReactDOM.Style.make(
      ~position="relative",
      ~whiteSpace="nowrap",
      ~width=j`$(drawerWidth)px`,
      ~transition=ThemeHelpers.transitionCreate(
        ~theme,
        ~affectWidth=true,
        ~easing=theme.transitions.easing.sharp,
        ~duration=theme.transitions.duration.enteringScreen,
        (),
      ),
      (),
    ),
    "drawerPaperClose": ReactDOM.Style.make(
      ~overflowX="hidden",
      ~transition=ThemeHelpers.transitionCreate(
        ~theme,
        ~affectWidth=true,
        ~affectMargin=true,
        ~easing=theme.transitions.easing.sharp,
        ~duration=theme.transitions.duration.leavingScreen,
        (),
      ),
      ~width=theme.spacing(7)->px_of_int,
      (),
    )->ThemeHelpers.addBreakpoint(
      ~theme,
      ~breakpoint=#SM,
      ~style=ReactDOM.Style.make(~width=theme.spacing(9)->px_of_int, ()),
    ),
    "appBarSpacer": theme.mixins.toolbar,
    "content": ReactDOM.Style.make(
      ~flexGrow="1",
      ~padding=theme.spacing(3)->px_of_int,
      ~height="100vh",
      ~overflow="auto",
      (),
    ),
    "h5": ReactDOM.Style.make(~marginBottom=theme.spacing(2)->px_of_int, ()),
  }
)

module MenuIcon = {
  @react.component @module("@material-ui/icons/Menu")
  external make: unit => React.element = "default"
}

module NotificationsIcon = {
  @react.component @module("@material-ui/icons/Notifications")
  external make: unit => React.element = "default"
}

module ChevronLeftIcon = {
  @react.component @module("@material-ui/icons/ChevronLeft")
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

  let classes = useStyles(.)

  <div>
    {show
      ? <div className={classes["wrapper"]}>
          <div className={classes["root"]}>
            <CssBaseline />
            <AppBar
              position=#absolute
              className={[
                classes["appBar"],
                state.isOpen ? classes["appBarShift"] : "",
              ] |> Js.Array.joinWith(" ")}>
              <Toolbar disableGutters={!state.isOpen} className={classes["toolbar"]}>
                <IconButton
                  color=#inherit
                  onClick={_event => setState(Open)}
                  className={[
                    classes["menuButton"],
                    state.isOpen ? classes["menuButtonHidden"] : "",
                  ] |> Js.Array.joinWith(" ")}>
                  <MenuIcon />
                </IconButton>
                <Typography
                  component={Typography.Component.string("h1")}
                  variant=#h6
                  color=#inherit
                  noWrap=true
                  className={classes["title"]}>
                  {"Dashboard"->React.string}
                </Typography>
                <Link
                  href="#"
                  onClick={e => {
                    e->ReactEvent.Mouse.preventDefault
                    setShow(false)
                  }}
                  color=#secondary>
                  {"Close Dashboard"->React.string}
                </Link>
                <IconButton color=#inherit>
                  <Badge badgeContent={"4"->React.string} color=#secondary>
                    <NotificationsIcon />
                  </Badge>
                </IconButton>
              </Toolbar>
            </AppBar>
            <Drawer
              variant=#permanent
              classes={Drawer.Classes.make(
                ~paper=[
                  classes["drawerPaper"],
                  state.isOpen ? "" : classes["drawerPaperClose"],
                ] |> Js.Array.joinWith(" "),
                (),
              )}
              \"open"=state.isOpen>
              <div className={classes["toolbarIcon"]}>
                <IconButton onClick={_event => setState(Close)}> <ChevronLeftIcon /> </IconButton>
              </div>
              <Divider />
              <div> sidebar </div>
            </Drawer>
            <main className={classes["content"]}>
              <div className={classes["appBarSpacer"]} /> <div> children </div>
            </main>
          </div>
        </div>
      : <Mui.Button variant=#outlined color=#primary onClick={_ => setShow(true)}>
          {"Open Dashboard"->React.string}
        </Mui.Button>}
  </div>
}
