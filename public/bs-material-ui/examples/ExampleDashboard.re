/*
     This example shows how to create a fully styled dashboard component with css breakpoints and transitions
     converted from github.com/mui-org/material-ui/tree/master/docs/src/pages/getting-started/page-layout-examples/dashboard
 */

open MaterialUi;

let drawerWidth = 240;

let px_of_float = x => x->int_of_float->string_of_int ++ "px";
let px_of_int = x => x->string_of_int ++ "px";

let style = ReactDOMRe.Style.make;
[%mui.withStyles
  "EnterpriseDashboardStyles"(theme =>
    {
      wrapper:
        style(
          ~position="fixed",
          ~width="100vw",
          ~height="100vh",
          ~zIndex="999999",
          ~left="0",
          ~top="0",
          ~background="#FFFFFF",
          (),
        ),
      root: style(~display="flex", ()),
      toolbar: style(~paddingRight="24px", ()), /* keep right padding when drawer closed */
      toolbarIcon:
        ReactDOMRe.Style.combine(
          style(
            ~display="flex",
            ~alignItems="center",
            ~justifyContent="flex-end",
            ~padding="0 8px",
            (),
          ),
          theme->Theme.Theme.mixinsGet->Theme.Mixins.toolbarGet,
        ),
      appBar:
        style(
          ~zIndex=
            (theme->Theme.Theme.zIndexGet->Theme.ZIndex.drawerGet +. 1.0)
            ->int_of_float
            ->string_of_int,
          ~transition=
            ThemeHelpers.transitionCreate(
              ~theme,
              ~affectWidth=true,
              ~affectMargin=true,
              ~easing=
                theme
                ->Theme.Theme.transitionsGet
                ->Theme.Transitions.easingGet
                ->Theme.Easing.sharpGet,
              ~duration=
                theme
                ->Theme.Theme.transitionsGet
                ->Theme.Transitions.durationGet
                ->Theme.Duration.leavingScreenGet,
              (),
            ),
          (),
        ),
      appBarShift:
        style(
          ~marginLeft=drawerWidth->string_of_int ++ "px",
          ~width={j|calc(100% - $(drawerWidth)px)|j},
          ~transition=
            ThemeHelpers.transitionCreate(
              ~theme,
              ~affectWidth=true,
              ~affectMargin=true,
              ~easing=
                theme
                ->Theme.Theme.transitionsGet
                ->Theme.Transitions.easingGet
                ->Theme.Easing.sharpGet,
              ~duration=
                theme
                ->Theme.Theme.transitionsGet
                ->Theme.Transitions.durationGet
                ->Theme.Duration.enteringScreenGet,
              (),
            ),
          (),
        ),
      menuButton: style(~marginLeft="12px", ~marginRight="36px", ()),
      menuButtonHidden: style(~display="none", ()),
      title: style(~flexGrow="1", ()),
      drawerPaper:
        style(
          ~position="relative",
          ~whiteSpace="nowrap",
          ~width={j|$(drawerWidth)px|j},
          ~transition=
            ThemeHelpers.transitionCreate(
              ~theme,
              ~affectWidth=true,
              ~easing=
                theme
                ->Theme.Theme.transitionsGet
                ->Theme.Transitions.easingGet
                ->Theme.Easing.sharpGet,
              ~duration=
                theme
                ->Theme.Theme.transitionsGet
                ->Theme.Transitions.durationGet
                ->Theme.Duration.enteringScreenGet,
              (),
            ),
          (),
        ),

      drawerPaperClose:
        style(
          ~overflowX="hidden",
          ~transition=
            ThemeHelpers.transitionCreate(
              ~theme,
              ~affectWidth=true,
              ~affectMargin=true,
              ~easing=
                theme
                ->Theme.Theme.transitionsGet
                ->Theme.Transitions.easingGet
                ->Theme.Easing.sharpGet,
              ~duration=
                theme
                ->Theme.Theme.transitionsGet
                ->Theme.Transitions.durationGet
                ->Theme.Duration.leavingScreenGet,
              (),
            ),
          ~width=theme->Theme.Theme.spacingGet(7)->px_of_int,
          (),
        )
        ->ThemeHelpers.addBreakpoint(
            ~theme,
            ~breakpoint=`SM,
            ~style=
              style(~width=theme->Theme.Theme.spacingGet(9)->px_of_int, ()),
          ),
      appBarSpacer: theme->Theme.Theme.mixinsGet->Theme.Mixins.toolbarGet,
      content:
        style(
          ~flexGrow="1",
          ~padding=theme->Theme.Theme.spacingGet(3)->px_of_int,
          ~height="100vh",
          ~overflow="auto",
          (),
        ),
      h5:
        style(~marginBottom=theme->Theme.Theme.spacingGet(2)->px_of_int, ()),
    }
  )
];

type state = {isOpen: bool};

type action =
  | Open
  | Close;

[@react.component]
let make = (~sidebar, ~children) => {
  let (state, setState) =
    React.useReducer(
      (_, action) =>
        switch (action) {
        | Open => {isOpen: true}
        | Close => {isOpen: false}
        },
      {isOpen: true},
    );
  let (show, setShow) = React.useReducer((_, v) => v, false);

  let classes = EnterpriseDashboardStyles.useStyles();

  <div>
    {show
       ? <div className={classes.wrapper}>
           <div className={classes.root}>
             <CssBaseline />
             <AppBar
               position=`Absolute
               className={
                 [|classes.appBar, state.isOpen ? classes.appBarShift : ""|]
                 |> Js.Array.joinWith(" ")
               }>
               <Toolbar
                 disableGutters={!state.isOpen} className={classes.toolbar}>
                 <IconButton
                   color=`Inherit
                   onClick={_event => setState(Open)}
                   className={
                     [|
                       classes.menuButton,
                       state.isOpen ? classes.menuButtonHidden : "",
                     |]
                     |> Js.Array.joinWith(" ")
                   }>
                   <MscharleyBsMaterialUiIcons.Menu.Filled />
                 </IconButton>
                 <MaterialUi_Typography
                   component={`String("h1")}
                   variant=`H6
                   color=`Inherit
                   noWrap=true
                   className={classes.title}>
                   "Dashboard"->ReasonReact.string
                 </MaterialUi_Typography>
                 <Link
                   href="#"
                   onClick={e => {
                     e->ReactEvent.Mouse.preventDefault;
                     setShow(false);
                   }}
                   color=`Secondary>
                   "Close Dashboard"
                 </Link>
                 <IconButton color=`Inherit>
                   <Badge
                     badgeContent={"4"->ReasonReact.string} color=`Secondary>
                     <MscharleyBsMaterialUiIcons.Notifications.Filled />
                   </Badge>
                 </IconButton>
               </Toolbar>
             </AppBar>
             <Drawer
               variant=`Permanent
               classes=[
                 Paper(
                   [|
                     classes.drawerPaper,
                     state.isOpen ? "" : classes.drawerPaperClose,
                   |]
                   |> Js.Array.joinWith(" "),
                 ),
               ]
               open_={state.isOpen}>
               <div className={classes.toolbarIcon}>
                 <IconButton onClick={_event => setState(Close)}>
                   <MscharleyBsMaterialUiIcons.ChevronLeft.Filled />
                 </IconButton>
               </div>
               <Divider />
               <div> sidebar </div>
             </Drawer>
             <main className={classes.content}>
               <div className={classes.appBarSpacer} />
               <div> children </div>
             </main>
           </div>
         </div>
       : <MaterialUi_Button
           variant=`Outlined color=`Primary onClick={_ => setShow(true)}>
           "Open Dashboard"
         </MaterialUi_Button>}
  </div>;
};