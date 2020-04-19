[@react.component]
let make = () =>
  MaterialUi.(
    <MaterialUi_ThemeProvider
      theme={MaterialUi_Theme.create(MaterialUi_ThemeOptions.make())}>
      <Box width="100%" height="100%" maxWidth="970px" margin="30px auto">
        <CssBaseline />
        <Grid container=true>
          <Grid item=true md=`V12>
            <Typography variant=`H4>
              "@jsiebern/bs-material-ui-lab Examples"
            </Typography>
          </Grid>
        </Grid>
        <br />
        <br />
        <Divider />
        <br />
        <br />
        <Grid container=true alignItems=`Center>
          <Grid item=true md=`V6>
            <Typography variant=`H5> "Alert" </Typography>
          </Grid>
          <Grid item=true md=`V6> <ExampleAlert /> </Grid>
        </Grid>
        <br />
        <br />
        <Divider />
        <br />
        <br />
        <Grid container=true alignItems=`Center>
          <Grid item=true md=`V6>
            <Typography variant=`H5> "Autocomplete" </Typography>
          </Grid>
          <Grid item=true md=`V6> <ExampleAutocomplete /> </Grid>
        </Grid>
        <br />
        <br />
        <Divider />
        <br />
        <br />
        <Grid container=true alignItems=`Center>
          <Grid item=true md=`V6>
            <Typography variant=`H5> "Pagination" </Typography>
          </Grid>
          <Grid item=true md=`V6> <ExamplePagination /> </Grid>
        </Grid>
        <br />
        <br />
        <Divider />
        <br />
        <br />
        <Grid container=true alignItems=`Center>
          <Grid item=true md=`V6>
            <Typography variant=`H5> "Rating" </Typography>
          </Grid>
          <Grid item=true md=`V6> <ExampleRating /> </Grid>
        </Grid>
        <br />
        <br />
        <Divider />
        <br />
        <br />
        <Grid container=true alignItems=`Center>
          <Grid item=true md=`V6>
            <Typography variant=`H5> "Skeleton" </Typography>
          </Grid>
          <Grid item=true md=`V6> <ExampleSkeleton /> </Grid>
        </Grid>
        <br />
        <br />
        <Divider />
        <br />
        <br />
        <Grid container=true alignItems=`Center>
          <Grid item=true md=`V6>
            <Typography variant=`H5> "ToggleButton" </Typography>
          </Grid>
          <Grid item=true md=`V6> <ExampleToggleButton /> </Grid>
        </Grid>
        <br />
        <br />
        <Divider />
        <br />
        <br />
        <Grid container=true alignItems=`Center>
          <Grid item=true md=`V6>
            <Typography variant=`H5> "TreeView" </Typography>
          </Grid>
          <Grid item=true md=`V6> <ExampleTreeView /> </Grid>
        </Grid>
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
      </Box>
    </MaterialUi_ThemeProvider>
  );