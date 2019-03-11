[@bs.config {jsx: 3}];

[@react.component]
let make = () =>
  <div>
    <MaterialUi.WithStyles
      classes=[
        {
          name: "alignRight",
          styles:
            ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ()),
        },
      ]
      render={classes =>
        <div className=classes##alignRight>
          {ReasonReact.string("Example text - aligned to the right")}
        </div>
      }
    />
    <MaterialUi.WithStyles
      classesWithTheme={theme =>
        [
          {
            name: "mystyle",
            styles:
              ReactDOMRe.Style.make(
                ~minHeight="50px",
                ~backgroundColor=
                  MaterialUi_Theme.(
                    theme
                    ->Theme.paletteGet
                    ->Palette.secondaryGet
                    ->PaletteColor.mainGet
                  ),
                (),
              ),
          },
        ]
      }
      render={classes => <div className=classes##mystyle />}
    />
  </div>;