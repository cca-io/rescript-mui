open Mui

module Item = {
  @react.component
  let make = (~children) =>
    <Paper
      sx={Sx.array([
        Sx.Array.obj({
          p: Number(2.),
          textAlign: Center,
          color: TextSecondary,
        }),
      ])}>
      children
    </Paper>
}

@react.component
let make = () => {
  <Box sx={Sx.obj({flexGrow: Number(1.)})}>
    <Typography variant=H6 gutterBottom=true> {"Basic Grid"->React.string} </Typography>
    <Grid container=true spacing={Int(2)}>
      <Grid item=true xs={Number(8)}>
        <Item> {"xs=8"->React.string} </Item>
      </Grid>
      <Grid item=true xs={Number(4)}>
        <Item> {"xs=4"->React.string} </Item>
      </Grid>
      <Grid item=true xs={Number(4)}>
        <Item> {"xs=4"->React.string} </Item>
      </Grid>
      <Grid item=true xs={Number(8)}>
        <Item> {"xs=8"->React.string} </Item>
      </Grid>
    </Grid>
    <br />
    <Typography variant=H6 gutterBottom=true> {"Responsive Grid"->React.string} </Typography>
    <Grid container=true spacing={Int(2)}>
      <Grid item=true xs={Number(6)} md={Number(8)}>
        <Item> {"xs=6 md=8"->React.string} </Item>
      </Grid>
      <Grid item=true xs={Number(6)} md={Number(4)}>
        <Item> {"xs=6 md=4"->React.string} </Item>
      </Grid>
      <Grid item=true xs={Number(6)} md={Number(4)}>
        <Item> {"xs=6 md=4"->React.string} </Item>
      </Grid>
      <Grid item=true xs={Number(6)} md={Number(8)}>
        <Item> {"xs=6 md=8"->React.string} </Item>
      </Grid>
    </Grid>
    <br />
    <Typography variant=H6 gutterBottom=true> {"Grid Direction Column"->React.string} </Typography>
    <Grid container=true spacing={Int(2)} direction=Column>
      <Grid item=true>
        <Item> {"Column 1"->React.string} </Item>
      </Grid>
      <Grid item=true>
        <Item> {"Column 2"->React.string} </Item>
      </Grid>
    </Grid>
    <br />
    <Typography variant=H6 gutterBottom=true> {"Alignment - Center"->React.string} </Typography>
    <Grid
      container=true
      spacing={Int(2)}
      justifyContent=Center
      alignItems=Center
      sx={Sx.obj({minHeight: String("100px")})}>
      <Grid item=true>
        <Item> {"Centered"->React.string} </Item>
      </Grid>
    </Grid>
    <br />
    <Typography variant=H6 gutterBottom=true>
      {"Alignment - Space Between"->React.string}
    </Typography>
    <Grid
      container=true
      spacing={Int(2)}
      justifyContent=SpaceBetween
      sx={Sx.obj({minHeight: String("100px")})}>
      <Grid item=true xs={Number(5)}>
        <Item> {"Left"->React.string} </Item>
      </Grid>
      <Grid item=true xs={Number(5)}>
        <Item> {"Right"->React.string} </Item>
      </Grid>
    </Grid>
  </Box>
}
