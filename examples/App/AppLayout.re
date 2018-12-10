[%mui.withStyles
  "Styles"({
    container:
      ReactDOMRe.Style.make(
        ~width="100%",
        ~height="100%",
        ~maxWidth="970px",
        ~margin="30px auto",
        (),
      ),
  })
];

let component = ReasonReact.statelessComponent(__MODULE__);

let make = _children => {
  ...component,
  render: _self =>
    <Styles>
      ...MaterialUi.(
           classes =>
             <div className={classes.container}>
               <CssBaseline />
               <Grid container=true>
                 <Grid item=true md=V12>
                   <Typography variant=`H4>
                     "@jsiebern/bs-material-ui Examples"
                   </Typography>
                 </Grid>
               </Grid>
               <br />
               <br />
               <Divider />
               <br />
               <br />
               <Grid container=true alignItems=`Center>
                 <Grid item=true md=V6>
                   <Typography variant=`H5> "Class Override" </Typography>
                 </Grid>
                 <Grid item=true md=V6> <ExampleClassOverride /> </Grid>
               </Grid>
               <br />
               <br />
               <Divider />
               <br />
               <br />
               <Grid container=true alignItems=`Center>
                 <Grid item=true md=V6>
                   <Typography variant=`H5> "Icons" </Typography>
                 </Grid>
                 <Grid item=true md=V6> <ExampleIcons /> </Grid>
               </Grid>
               <br />
               <br />
               <Divider />
               <br />
               <br />
               <Grid container=true alignItems=`Center>
                 <Grid item=true md=V6>
                   <Typography variant=`H5> "Popover" </Typography>
                 </Grid>
                 <Grid item=true md=V6> <ExamplePopover /> </Grid>
               </Grid>
               <br />
               <br />
               <Divider />
               <br />
               <br />
               <Grid container=true alignItems=`Center>
                 <Grid item=true md=V6>
                   <Typography variant=`H5> "WithStylesSafe" </Typography>
                 </Grid>
                 <Grid item=true md=V6> <ExampleWithStylesSafe /> </Grid>
               </Grid>
               <br />
               <br />
               <Divider />
               <br />
               <br />
               <Grid container=true alignItems=`Center>
                 <Grid item=true md=V6>
                   <Typography variant=`H5> "WithStylesUnsafe" </Typography>
                 </Grid>
                 <Grid item=true md=V6> <ExampleWithStylesUnsafe /> </Grid>
               </Grid>
               <br />
               <br />
               <Divider />
               <br />
               <br />
               <Grid container=true alignItems=`Center>
                 <Grid item=true md=V6>
                   <Typography variant=`H5> "Theme Provider" </Typography>
                 </Grid>
                 <Grid item=true md=V6> <ExampleThemeProvider /> </Grid>
               </Grid>
               <br />
               <br />
               <Divider />
               <br />
               <br />
               <Grid container=true alignItems=`Center>
                 <Grid item=true md=V6>
                   <Typography variant=`H5> "List" </Typography>
                 </Grid>
                 <Grid item=true md=V6> <ExampleList /> </Grid>
               </Grid>
             </div>
         )
    </Styles>,
};