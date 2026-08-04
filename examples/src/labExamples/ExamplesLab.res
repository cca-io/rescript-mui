open Mui

@react.component
let make = () =>
  <Stack spacing={Number(4.)}>
    <Typography variant=H4> {"ReScript-MUI Lab Examples"->React.string} </Typography>
    <Divider />
    <Grid container=true spacing=Int(3) sx={Sx.obj({alignItems: String("center")})}>
      <Grid size=Object({xs: Int(12), md: Int(6)})>
        <Typography variant=H5> {"Timeline"->React.string} </Typography>
      </Grid>
      <Grid size=Object({xs: Int(12), md: Int(6)})>
        <ExampleTimeline />
      </Grid>
    </Grid>
    <Divider />
    <Grid container=true spacing=Int(3) sx={Sx.obj({alignItems: String("center")})}>
      <Grid size=Object({xs: Int(12), md: Int(6)})>
        <Typography variant=H5> {"Masonry"->React.string} </Typography>
      </Grid>
      <Grid size=Object({xs: Int(12), md: Int(6)})>
        <ExampleMasonry />
      </Grid>
    </Grid>
  </Stack>
