module Styles: {
  type classes = {
    root: string,
    rounded: string,
  };
  let useStyles: unit => classes;
} = {
  type styles = {
    root: ReactDOMRe.Style.t,
    rounded: ReactDOMRe.Style.t,
  };
  type classes = {
    root: string,
    rounded: string,
  };
  type useStyles = unit => classes;
  [@bs.module "@material-ui/core/styles"]
  external makeStyles: (. styles) => useStyles = "makeStyles";
  let useStyles =
    makeStyles(. {
      root:
        ReactDOMRe.Style.make(
          ~width="100%",
          ~maxWidth="970px",
          ~margin="0 auto",
          (),
        ),
      rounded:
        ReactDOMRe.Style.make(
          ~backgroundColor="grey",
          ~color="white",
          ~padding="15px",
          (),
        ),
    });
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