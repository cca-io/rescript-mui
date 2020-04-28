module StyledExample = [%makeStyles
  {alignRight: ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ())}
];

module Theme = MaterialUi_Theme;
module StyledExampleTheme = [%makeStyles
  theme => {
    background:
      ReactDOMRe.Style.make(
        ~color=MaterialUi.Colors.common.white,
        ~backgroundColor=
          theme
          ->Theme.Theme.paletteGet
          ->Theme.Palette.primaryGet
          ->Theme.PaletteColor.mainGet,
        (),
      ),
  }
];

[@react.component]
let make = () => {
  let classesExample = StyledExample.useStyles();
  let classesExampleTheme = StyledExampleTheme.useStyles();

  <div>
    <div className={classesExample.alignRight}>
      "Example text - aligned to the right"->React.string
    </div>
    <br />
    <br />
    <div className={classesExampleTheme.background}>
      "Example text on a background coming from the Mui Theme object"
      ->React.string
    </div>
  </div>;
};
