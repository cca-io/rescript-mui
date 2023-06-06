type useStyles<'a> = unit => 'a

@module("@mui/styles")
external makeStyles: {..} => useStyles<'a> = "makeStyles"

@module("@mui/styles")
external makeStylesWithTheme: (Theme.t => {..}) => useStyles<'a> = "makeStyles"
