@react.component
let make = () =>
  <div>
    <MaterialUi.WithStyles
      classes=list{
        {
          name: "alignRight",
          styles: ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ()),
        },
      }
      render={classes =>
        <div className={classes["alignRight"]}>
          {ReasonReact.string("Example text - aligned to the right")}
        </div>}
    />
    <MaterialUi.WithStyles
      classesWithTheme={theme => list{
        {
          name: "mystyle",
          styles: ReactDOMRe.Style.make(
            ~minHeight="50px",
            ~backgroundColor={
              open MaterialUi_Theme
              theme.palette.secondary.main
            },
            (),
          ),
        },
      }}
      render={classes => <div className={classes["mystyle"]} />}
    />
  </div>
