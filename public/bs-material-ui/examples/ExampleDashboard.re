/*  
    This example shows how to create a fully styled dashboard component with css breakpoints and transitions
    converted from github.com/mui-org/material-ui/tree/master/docs/src/pages/getting-started/page-layout-examples/dashboard
*/

open MaterialUi;

let drawerWidth = 240;

let px_of_float = x => x->int_of_float->string_of_int ++ "px";

let style = ReactDOMRe.Style.make;
[%mui.withStyles
  "EnterpriseDashboardStyles"(theme =>
    {
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
          theme->Theme.mixinsGet->Mixins.toolbarGet,
        ),
      appBar:
        style(
          ~zIndex=
            (theme->Theme.zIndexGet->ZIndex.drawerGet +. 1.0)
            ->int_of_float
            ->string_of_int,
          ~transition=
            Style.transitionCreate(
              ~theme,
              ~affectWidth=true,
              ~affectMargin=true,
              ~easing=
                theme
                ->Theme.transitionsGet
                ->Transitions.easingGet
                ->Easing.sharpGet,
              ~duration=
                theme
                ->Theme.transitionsGet
                ->Transitions.durationGet
                ->Duration.leavingScreenGet,
              (),
            ),
          (),
        ),
      appBarShift:
        style(
          ~marginLeft=drawerWidth->string_of_int ++ "px",
          ~width={j|calc(100% - $(drawerWidth)px)|j},
          ~transition=
            Style.transitionCreate(
              ~theme,
              ~affectWidth=true,
              ~affectMargin=true,
              ~easing=
                theme
                ->Theme.transitionsGet
                ->Transitions.easingGet
                ->Easing.sharpGet,
              ~duration=
                theme
                ->Theme.transitionsGet
                ->Transitions.durationGet
                ->Duration.enteringScreenGet,
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
            Style.transitionCreate(
              ~theme,
              ~affectWidth=true,
              ~easing=
                theme
                ->Theme.transitionsGet
                ->Transitions.easingGet
                ->Easing.sharpGet,
              ~duration=
                theme
                ->Theme.transitionsGet
                ->Transitions.durationGet
                ->Duration.enteringScreenGet,
              (),
            ),
          (),
        ),

      drawerPaperClose:
        style(
          ~overflowX="hidden",
          ~transition=
            Style.transitionCreate(
              ~theme,
              ~affectWidth=true,
              ~affectMargin=true,
              ~easing=
                theme
                ->Theme.transitionsGet
                ->Transitions.easingGet
                ->Easing.sharpGet,
              ~duration=
                theme
                ->Theme.transitionsGet
                ->Transitions.durationGet
                ->Duration.leavingScreenGet,
              (),
            ),
          ~width=
            (theme->Theme.spacingGet->Spacing.unitGet *. 7.0)->px_of_float,
          (),
        )
        ->Style.addBreakpoint(
            ~theme,
            ~breakpoint=`SM,
            ~style=
              style(
                ~width=
                  (theme->Theme.spacingGet->Spacing.unitGet *. 9.0)
                  ->px_of_float,
                (),
              ),
          ),
      appBarSpacer: theme->Theme.mixinsGet->Mixins.toolbarGet,
      content:
        style(
          ~flexGrow="1",
          ~padding=
            (theme->Theme.spacingGet->Spacing.unitGet *. 3.0)->px_of_float,
          ~height="100vh",
          ~overflow="auto",
          (),
        ),
      h5:
        style(
          ~marginBottom=
            (theme->Theme.spacingGet->Spacing.unitGet *. 2.0)->px_of_float,
          (),
        ),
    }
  )
];

type state = {isOpen: bool};

type action =
  | Open
  | Close;

[@react.component]
let make = (~sidebar, ~children) => {
  let (state, setState) = React.useState(() => {isOpen: true});

  let setState = action => {
    setState(state =>
      switch (action) {
      | Open => {isOpen: true}
      | Close => {isOpen: false}
      },
    );
  };

  <EnterpriseDashboardStyles>
    ...{classes =>
      <div className={classes.root}>
        <CssBaseline />
        <AppBar
          position=`Absolute
          className={Cn.make([
            classes.appBar,
            classes.appBarShift->Cn.ifTrue(state.isOpen),
          ])}>
          <Toolbar
            disableGutters={!state.isOpen} className={classes.toolbar}>
            <IconButton
              color=`Inherit
              onClick={_event => setState(Open)}
              className={Cn.make([
                classes.menuButton,
                classes.menuButtonHidden->Cn.ifTrue(state.isOpen),
              ])}>
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
            <IconButton color=`Inherit>
              <Badge badgeContent={"4"->ReasonReact.string} color=`Secondary>
                <MscharleyBsMaterialUiIcons.Notifications.Filled />
              </Badge>
            </IconButton>
          </Toolbar>
        </AppBar>
        <Drawer
          variant=`Permanent
          classes=[
            Paper(
              Cn.make([
                classes.drawerPaper,
                classes.drawerPaperClose->Cn.ifTrue(!state.isOpen),
              ]),
            ),
          ]
          open_={state.isOpen}>
          <div className={classes.toolbarIcon}>
            <IconButton onClick={_event => setState(Close)}>
              <MscharleyBsMaterialUiIcons.ChevronLeft.Filled />
            </IconButton>
          </div>
          <Divider />
          <div> {sidebar} </div>
        </Drawer>
        <main className={classes.content}>
          <div className={classes.appBarSpacer} />
          <div>{children}</div>
        </main>
      </div>
    }
  </EnterpriseDashboardStyles>;
};