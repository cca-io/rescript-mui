module Styles = [%makeStyles
  (
    theme => {
      root:
        ReactDOMRe.Style.make(
          ~width="100%",
          ~maxWidth="970px",
          ~margin="0 auto",
          (),
        ),
      rounded:
        ReactDOMRe.Style.make(
          ~backgroundColor=
            MaterialUi.Theme.(
              theme
              ->Theme.paletteGet
              ->Palette.backgroundGet
              ->TypeBackground.paperGet
            ),
          ~color=
            MaterialUi.Theme.(
              theme->Theme.paletteGet->Palette.textGet->TypeText.primaryGet
            ),
          ~padding="15px",
          (),
        ),
    },
    {name: "test"},
  )
];

[@react.component]
let make = () => {
  let classes = Styles.useStyles();
  MaterialUi.(
    <Paper
      classes={Paper.Classes.make(
        ~root=classes.root,
        ~rounded=classes.rounded,
        (),
      )}>
      <Typography> "Some Content"->React.string </Typography>
    </Paper>
  );
};
