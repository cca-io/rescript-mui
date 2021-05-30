module Styles: {
  type classes = {
    root: string,
    rounded: string,
  };
  let useStyles: unit => classes;
} = {
  type styles = {
    root: ReactDOM.Style.t,
    rounded: ReactDOM.Style.t,
  };
  type classes = {
    root: string,
    rounded: string,
  };
  type useStyles = unit => classes;
  [@module "@material-ui/core/styles"]
  external makeStyles: (. (MaterialUi.Theme.t => styles)) => useStyles =
    "makeStyles";
  let useStyles =
    makeStyles(. theme =>
      {
        root:
          ReactDOM.Style.make(
            ~width="100%",
            ~maxWidth="970px",
            ~margin="0 auto",
            (),
          ),
        rounded:
          ReactDOM.Style.make(
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
      }
    );
};

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
