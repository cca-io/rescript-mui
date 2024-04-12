open Mui

@react.component
let make = () => <>
  <Grid container=true>
    <Grid item=true md=Number(12)>
      <Typography variant=H4> {"ReScript-MUI Lab Examples"->React.string} </Typography>
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Alert"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleAlert />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Autocomplete"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleAutocomplete />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Pagination"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExamplePagination />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Rating"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleRating />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Skeleton"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleSkeleton />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"ToggleButton"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleToggleButton />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  // TODO: TreeView moved to it's own package.
  // https://mui.com/x/migration/migration-tree-view-v6/
  //
  // <Grid container=true alignItems=String("center")>
  //   <Grid item=true md=Number(6)>
  //     <Typography variant=H5> {"TreeView"->React.string} </Typography>
  //   </Grid>
  //   <Grid item=true md=Number(6)>
  //     <ExampleTreeView />
  //   </Grid>
  // </Grid>
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
</>
