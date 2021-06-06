type useStyles<'a> = (. unit) => 'a

@module("@material-ui/styles")
external makeStyles: {..} => useStyles<'a> = "makeStyles"

@module("@material-ui/styles")
external makeStylesWithTheme: (MaterialUi_Theme.t => {..}) => useStyles<'a> = "makeStyles"
