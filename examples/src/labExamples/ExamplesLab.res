open Mui

@react.component
let make = () => <>
  <Grid container=true>
    <Grid item=true md=Grid.Md.\"12">
      <Typography variant=#h4> {"ReScript Material-UI Lab Examples"->React.string} </Typography>
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> {"Alert"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleAlert /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> {"Autocomplete"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleAutocomplete /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> {"Pagination"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExamplePagination /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> {"Rating"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleRating /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> {"Skeleton"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleSkeleton /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> {"ToggleButton"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleToggleButton /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> {"TreeView"->React.string} </Typography>
    </Grid>
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
</>
