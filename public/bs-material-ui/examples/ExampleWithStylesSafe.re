[%mui.withStyles
  "StyledExample"({
    alignRight: ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ()),
  })
];

module Theme = MaterialUi_Theme;
[%mui.withStyles
  "StyledExampleTheme"(theme =>
    {
      background:
        ReactDOMRe.Style.make(
          ~color=MaterialUi.Colors.Common.white,
          ~backgroundColor=
            theme
            ->Theme.Theme.paletteGet
            ->Theme.Palette.primaryGet
            ->Theme.PaletteColor.mainGet,
          (),
        ),
    }
  )
];

[@react.component]
let make = () =>
  <div>
    <StyledExample>
      ...{classes =>
        <div className={classes.alignRight}>
          {ReasonReact.string("Example text - aligned to the right")}
        </div>
      }
    </StyledExample>
    <br />
    <br />
    <StyledExampleTheme>
      ...{classes =>
        <div className={classes.background}>
          {ReasonReact.string(
             "Example text on a background coming from the Mui Theme object",
           )}
        </div>
      }
    </StyledExampleTheme>
  </div>;