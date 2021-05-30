open MaterialUi

@react.component
let make = () =>
  <ThemeProvider theme={Theme.create(ThemeOptions.make())}>
    <Box
      width={Box.Value.string("100%")}
      height={Box.Value.string("100%")}
      maxWidth={Box.Value.string("970px")}
      margin={Box.Value.string("30px auto")}>
      <CssBaseline />
      <Grid container=true>
        <Grid item=true md=Grid.Md.\"12">
          <Typography variant=#h4> "ReScript Material-UI Lab Examples" </Typography>
        </Grid>
      </Grid>
      <br />
      <br />
      <Divider />
      <br />
      <br />
      <Grid container=true alignItems=#center>
        <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Alert" </Typography> </Grid>
        <Grid item=true md=Grid.Md.\"6"> <ExampleAlert /> </Grid>
      </Grid>
      <br />
      <br />
      <Divider />
      <br />
      <br />
      <Grid container=true alignItems=#center>
        <Grid item=true md=Grid.Md.\"6">
          <Typography variant=#h5> "Autocomplete" </Typography>
        </Grid>
        <Grid item=true md=Grid.Md.\"6"> <ExampleAutocomplete /> </Grid>
      </Grid>
      <br />
      <br />
      <Divider />
      <br />
      <br />
      <Grid container=true alignItems=#center>
        <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Pagination" </Typography> </Grid>
        <Grid item=true md=Grid.Md.\"6"> <ExamplePagination /> </Grid>
      </Grid>
      <br />
      <br />
      <Divider />
      <br />
      <br />
      <Grid container=true alignItems=#center>
        <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Rating" </Typography> </Grid>
        <Grid item=true md=Grid.Md.\"6"> <ExampleRating /> </Grid>
      </Grid>
      <br />
      <br />
      <Divider />
      <br />
      <br />
      <Grid container=true alignItems=#center>
        <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Skeleton" </Typography> </Grid>
        <Grid item=true md=Grid.Md.\"6"> <ExampleSkeleton /> </Grid>
      </Grid>
      <br />
      <br />
      <Divider />
      <br />
      <br />
      <Grid container=true alignItems=#center>
        <Grid item=true md=Grid.Md.\"6">
          <Typography variant=#h5> "ToggleButton" </Typography>
        </Grid>
        <Grid item=true md=Grid.Md.\"6"> <ExampleToggleButton /> </Grid>
      </Grid>
      <br />
      <br />
      <Divider />
      <br />
      <br />
      <Grid container=true alignItems=#center>
        <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "TreeView" </Typography> </Grid>
        <Grid item=true md=Grid.Md.\"6"> <ExampleTreeView /> </Grid>
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
  </ThemeProvider>
